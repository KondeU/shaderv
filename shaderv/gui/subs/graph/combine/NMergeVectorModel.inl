namespace NMergeVectorModelPrivate {
template <typename T>
class NMergeVectorModelConfig {};

#define NMVMC_IMPL(out, title)           \
template<>                               \
class NMergeVectorModelConfig<out> {     \
public:                                  \
    static inline constexpr auto Title() \
    {                                    \
        return title;                    \
    }                                    \
};

NMVMC_IMPL(NVector2, "Merge Vector2")
NMVMC_IMPL(NVector3, "Merge Vector3")
NMVMC_IMPL(NVector4, "Merge Vector4")
NMVMC_IMPL(NVecInt2, "Merge VecInt2")
NMVMC_IMPL(NVecInt3, "Merge VecInt3")
NMVMC_IMPL(NVecInt4, "Merge VecInt4")
}

template <typename TI, typename TO, unsigned int X>
inline NMergeVectorModel<TI, TO, X>::NMergeVectorModel()
    : NBaseModel(X, 1, NMergeVectorModelPrivate::NMergeVectorModelConfig<TO>::Title())
{
    nodeInput.resize(X);

    SetTitle(NMergeVectorModelPrivate::NMergeVectorModelConfig<TO>::Title());

    SetOutputPortDataType(0, TO().type());
    for (unsigned int n = 0; n < X; n++) {
        SetInputPortDataType(n, TI().type());
    }
}

template <typename TI, typename TO, unsigned int X>
inline void NMergeVectorModel<TI, TO, X>::CbInData(int index, std::shared_ptr<PortData> in)
{
    auto inData = std::dynamic_pointer_cast<TI>(in);
    nodeInput[index] = inData;

    bool valid = true;
    std::vector<std::shared_ptr<TI>> nodeInputLocked(X);
    for (unsigned int n = 0; n < X; n++) {
        nodeInputLocked[n] = nodeInput[n].lock();
        if (!nodeInputLocked[n]) {
            valid = false;
        }
    }

    if (valid) {
        std::vector<TI::RawType> nodeInputData(X);
        for (unsigned int n = 0; n < X; n++) {
            nodeInputData[n] = nodeInputLocked[0]->Get();
        }
        nodeOutput = std::make_shared<TO>();
        (*nodeOutput)(nodeInputData);
        SetNodeState(NodeState::NORMAL);
        SetNodeMessage("");
    } else {
        nodeOutput.reset();
        SetNodeState(NodeState::WARNING);
        SetNodeMessage("Missing inputs!");
    }

    Update(0);
}

template <typename TI, typename TO, unsigned int X>
inline std::shared_ptr<NBaseModel::PortData> NMergeVectorModel<TI, TO, X>::CbOutData(int index)
{
    if (index == 0) {
        return nodeOutput;
    }
    return std::shared_ptr<PortData>();
}
