#include "MGraph.h"
#include "graph/input/NDecimalInputModel.h"
#include "graph/input/NIntegerInputModel.h"
#include "graph/value/NMergeVectorModel.h"

bool MGraph::Init()
{
    scene = QT_NEW QtNodes::FlowScene(
        RegisterDataModels(), this);
    return true;
}

std::shared_ptr<QtNodes::DataModelRegistry>
MGraph::RegisterDataModels() const
{
    std::shared_ptr<QtNodes::DataModelRegistry> reg =
        std::make_shared<QtNodes::DataModelRegistry>();

    reg->registerModel<NDecimalInputModel>("Value");
    reg->registerModel<NIntegerInputModel>("Value");

    reg->registerModel<NMergeVector2Model>("Vector");
    reg->registerModel<NMergeVector3Model>("Vector");
    reg->registerModel<NMergeVector4Model>("Vector");

    reg->registerModel<NMergeVecInt2Model>("VecInt");
    reg->registerModel<NMergeVecInt3Model>("VecInt");
    reg->registerModel<NMergeVecInt4Model>("VecInt");

    RegisterUniqueDataModels(reg);
    return reg;
}

void MGraphVert::RegisterUniqueDataModels(std::shared_ptr<
    QtNodes::DataModelRegistry> registry) const
{
}

void MGraphFrag::RegisterUniqueDataModels(std::shared_ptr<
    QtNodes::DataModelRegistry> registry) const
{
}
