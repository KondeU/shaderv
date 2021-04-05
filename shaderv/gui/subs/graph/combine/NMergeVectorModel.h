#ifndef _N_MERGE_VECTOR_MODEL_H_
#define _N_MERGE_VECTOR_MODEL_H_

#include "../NBaseModel.hpp"
#include "../NValueData.hpp"

template <typename TI, typename TO, unsigned int X>
class NMergeVectorModel : public NBaseModel {
public:
    NMergeVectorModel();

    void CbInData(int index, std::shared_ptr<PortData> in) override;
    std::shared_ptr<PortData> CbOutData(int index) override;

private:
    std::vector<std::weak_ptr<TI>> nodeInput;
    std::shared_ptr<TO> nodeOutput;
};

using NMergeVector2Model = NMergeVectorModel<NDecimal, NVector2, 2>;
using NMergeVector3Model = NMergeVectorModel<NDecimal, NVector3, 3>;
using NMergeVector4Model = NMergeVectorModel<NDecimal, NVector4, 4>;
using NMergeVecInt2Model = NMergeVectorModel<NInteger, NVecInt2, 2>;
using NMergeVecInt3Model = NMergeVectorModel<NInteger, NVecInt3, 3>;
using NMergeVecInt4Model = NMergeVectorModel<NInteger, NVecInt4, 4>;

#include "NMergeVectorModel.inl"

#endif
