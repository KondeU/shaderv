#ifndef _N_VALUE_DATA_HPP_
#define _N_VALUE_DATA_HPP_

#include "../../UiBasic.hpp"

template <typename T, unsigned int C1, unsigned int C2>
class NValueData : public QtNodes::NodeData {
public:
    template <unsigned int G1, unsigned int G2>
    void Set(T t)
    {
        static_assert((G1 < C1) && (G2 < C2),
            "Template argument error");
        value[C2 * G2 + G1] = t;
    }

    template <unsigned int G1, unsigned int G2>
    T Get() const
    {
        static_assert((G1 < C1) && (G2 < C2),
            "Template argument error");
        return value[C2 * G2 + G1];
    }

    template <unsigned int G = 0>
    void Set(T t)
    {
        static_assert(G < C1 * C2,
            "Template argument error");
        value[G] = t;
    }

    template <unsigned int G = 0>
    T Get() const
    {
        static_assert(G < C1 * C2,
            "Template argument error");
        return value[G];
    }

protected:
    NValueData()
    {
        static_assert((C1 > 0) && (C2 > 0),
            "Template argument error");
        value.resize(C1 * C2);
    }

private:
    std::vector<T> value;
};

#define NVD_IMPL(nvdc, nvdt, cnt1, cnt2, idsz, name) \
class nvdc : public NValueData<nvdt, cnt1, cnt2> {   \
public:                                              \
    QtNodes::NodeDataType type() const override      \
    {                                                \
        return QtNodes::NodeDataType { idsz, name }; \
    }                                                \
};

NVD_IMPL(NDecimal, double, 1, 1, "decimal", "Decimal")
NVD_IMPL(NVector2, double, 2, 1, "vector2", "Vector2")
NVD_IMPL(NVector3, double, 3, 1, "vector3", "Vector3")
NVD_IMPL(NVector4, double, 4, 1, "vector4", "Vector4")
NVD_IMPL(NMatrix2, double, 2, 2, "matrix2", "Matrix2")
NVD_IMPL(NMatrix3, double, 3, 3, "matrix3", "Matrix3")
NVD_IMPL(NMatrix4, double, 4, 4, "matrix4", "Matrix4")
NVD_IMPL(NInteger, long,   1, 1, "integer", "Integer")
NVD_IMPL(NVecInt2, long,   2, 1, "vecint2", "VecInt2")
NVD_IMPL(NVecInt3, long,   3, 1, "vecint3", "VecInt3")
NVD_IMPL(NVecInt4, long,   4, 1, "vecint4", "VecInt4")
NVD_IMPL(NMatInt2, long,   2, 2, "matint2", "MatInt2")
NVD_IMPL(NMatInt3, long,   3, 3, "matint3", "MatInt3")
NVD_IMPL(NMatInt4, long,   4, 4, "matint4", "MatInt4")

#endif
