#ifndef _QT_PROP_GEN_HPP_
#define _QT_PROP_GEN_HPP_

#define PROPERTY_GENERATOR_SETGET_1(n, n1, t1)                       \
public:                                                              \
    void SetProps##n(uintptr_t changer, const std::tuple<t1>& props) \
    {                                                                \
        prop##n1 = std::get<0>(props);                               \
        emit n##Changed(changer, prop##n1);                          \
    }                                                                \
    std::tuple<t1> GetProps##n() const                               \
    {                                                                \
        return { prop##n1 };                                         \
    }                                                                \
    void Set##n1(uintptr_t changer, t1 prop##n1)                     \
    {                                                                \
        this->prop##n1 = prop##n1;                                   \
        emit n##Changed(changer, prop##n1);                          \
    }                                                                \
    t1 Get##n1() const                                               \
    {                                                                \
        return prop##n1;                                             \
    }                                                                \
private:                                                             \
    t1 prop##n1;

#define PROPERTY_GENERATOR_SETGET_2(n, n1, n2, t1, t2)                   \
public:                                                                  \
    void SetProps##n(uintptr_t changer, const std::tuple<t1, t2>& props) \
    {                                                                    \
        prop##n1 = std::get<0>(props);                                   \
        prop##n2 = std::get<1>(props);                                   \
        emit n##Changed(changer, prop##n1, prop##n2);                    \
    }                                                                    \
    std::tuple<t1, t2> GetProps##n() const                               \
    {                                                                    \
        return { prop##n1, prop##n2 };                                   \
    }                                                                    \
    void Set##n1(uintptr_t changer, t1 prop##n1)                         \
    {                                                                    \
        this->prop##n1 = prop##n1;                                       \
        emit n##Changed(changer, prop##n1, prop##n2);                    \
    }                                                                    \
    t1 Get##n1() const                                                   \
    {                                                                    \
        return prop##n1;                                                 \
    }                                                                    \
    void Set##n2(uintptr_t changer, t2 prop##n2)                         \
    {                                                                    \
        this->prop##n2 = prop##n2;                                       \
        emit n##Changed(changer, prop##n1, prop##n2);                    \
    }                                                                    \
    t2 Get##n2() const                                                   \
    {                                                                    \
        return prop##n2;                                                 \
    }                                                                    \
private:                                                                 \
    t1 prop##n1;                                                         \
    t2 prop##n2;

#define PROPERTY_GENERATOR_SETGET_3(n, n1, n2, n3, t1, t2, t3)               \
public:                                                                      \
    void SetProps##n(uintptr_t changer, const std::tuple<t1, t2, t3>& props) \
    {                                                                        \
        prop##n1 = std::get<0>(props);                                       \
        prop##n2 = std::get<1>(props);                                       \
        prop##n3 = std::get<2>(props);                                       \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3);              \
    }                                                                        \
    std::tuple<t1, t2, t3> GetProps##n() const                               \
    {                                                                        \
        return { prop##n1, prop##n2, prop##n3 };                             \
    }                                                                        \
    void Set##n1(uintptr_t changer, t1 prop##n1)                             \
    {                                                                        \
        this->prop##n1 = prop##n1;                                           \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3);              \
    }                                                                        \
    t1 Get##n1() const                                                       \
    {                                                                        \
        return prop##n1;                                                     \
    }                                                                        \
    void Set##n2(uintptr_t changer, t2 prop##n2)                             \
    {                                                                        \
        this->prop##n2 = prop##n2;                                           \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3);              \
    }                                                                        \
    t2 Get##n2() const                                                       \
    {                                                                        \
        return prop##n2;                                                     \
    }                                                                        \
    void Set##n3(uintptr_t changer, t3 prop##n3)                             \
    {                                                                        \
        this->prop##n3 = prop##n3;                                           \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3);              \
    }                                                                        \
    t3 Get##n3() const                                                       \
    {                                                                        \
        return prop##n3;                                                     \
    }                                                                        \
private:                                                                     \
    t1 prop##n1;                                                             \
    t2 prop##n2;                                                             \
    t3 prop##n3;

#define PROPERTY_GENERATOR_SETGET_4(n, n1, n2, n3, n4, t1, t2, t3, t4)           \
public:                                                                          \
    void SetProps##n(uintptr_t changer, const std::tuple<t1, t2, t3, t4>& props) \
    {                                                                            \
        prop##n1 = std::get<0>(props);                                           \
        prop##n2 = std::get<1>(props);                                           \
        prop##n3 = std::get<2>(props);                                           \
        prop##n4 = std::get<3>(props);                                           \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3, prop##n4);        \
    }                                                                            \
    std::tuple<t1, t2, t3, t4> GetProps##n() const                               \
    {                                                                            \
        return { prop##n1, prop##n2, prop##n3, prop##n4 };                       \
    }                                                                            \
    void Set##n1(uintptr_t changer, t1 prop##n1)                                 \
    {                                                                            \
        this->prop##n1 = prop##n1;                                               \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3, prop##n4);        \
    }                                                                            \
    t1 Get##n1() const                                                           \
    {                                                                            \
        return prop##n1;                                                         \
    }                                                                            \
    void Set##n2(uintptr_t changer, t2 prop##n2)                                 \
    {                                                                            \
        this->prop##n2 = prop##n2;                                               \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3, prop##n4);        \
    }                                                                            \
    t2 Get##n2() const                                                           \
    {                                                                            \
        return prop##n2;                                                         \
    }                                                                            \
    void Set##n3(uintptr_t changer, t3 prop##n3)                                 \
    {                                                                            \
        this->prop##n3 = prop##n3;                                               \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3, prop##n4);        \
    }                                                                            \
    t3 Get##n3() const                                                           \
    {                                                                            \
        return prop##n3;                                                         \
    }                                                                            \
    void Set##n4(uintptr_t changer, t4 prop##n4)                                 \
    {                                                                            \
        this->prop##n4 = prop##n4;                                               \
        emit n##Changed(changer, prop##n1, prop##n2, prop##n3, prop##n4);        \
    }                                                                            \
    t4 Get##n4() const                                                           \
    {                                                                            \
        return prop##n4;                                                         \
    }                                                                            \
private:                                                                         \
    t1 prop##n1;                                                                 \
    t2 prop##n2;                                                                 \
    t3 prop##n3;                                                                 \
    t4 prop##n4;

#define PROPERTY_GENERATOR_SIGNAL_1(n, n1, t1) \
void n##Changed(uintptr_t changer, t1 prop##n1);

#define PROPERTY_GENERATOR_SIGNAL_2(n, n1, n2, t1, t2) \
void n##Changed(uintptr_t changer, t1 prop##n1, t2 prop##n2);

#define PROPERTY_GENERATOR_SIGNAL_3(n, n1, n2, n3, t1, t2, t3) \
void n##Changed(uintptr_t changer, t1 prop##n1, t2 prop##n2, t3 prop##n3);

#define PROPERTY_GENERATOR_SIGNAL_4(n, n1, n2, n3, n4, t1, t2, t3, t4) \
void n##Changed(uintptr_t changer, t1 prop##n1, t2 prop##n2, t3 prop##n3, t4 prop##n4);

#define PROPERTY_GENERATOR_MAKE_CHANGER(c) reinterpret_cast<uintptr_t>(c)

#ifndef PROPERTY_GENERATOR_FORCE_FULL_MACRO
#define PG_SETGET_1 PROPERTY_GENERATOR_SETGET_1
#define PG_SETGET_2 PROPERTY_GENERATOR_SETGET_2
#define PG_SETGET_3 PROPERTY_GENERATOR_SETGET_3
#define PG_SETGET_4 PROPERTY_GENERATOR_SETGET_4
#define PG_SIGNAL_1 PROPERTY_GENERATOR_SIGNAL_1
#define PG_SIGNAL_2 PROPERTY_GENERATOR_SIGNAL_2
#define PG_SIGNAL_3 PROPERTY_GENERATOR_SIGNAL_3
#define PG_SIGNAL_4 PROPERTY_GENERATOR_SIGNAL_4
#define PG_MAKE_CHANGER PROPERTY_GENERATOR_MAKE_CHANGER
#endif

#endif
