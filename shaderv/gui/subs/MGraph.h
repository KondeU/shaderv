#ifndef _M_GRAPH_H_
#define _M_GRAPH_H_

#include "../mvp/Model.hpp"

class MGraph : public Model {
public:
    bool Init() override;

protected:
    MGraph() = default;
    ~MGraph() override = default;

    virtual void RegisterUniqueDataModels(std::shared_ptr<
        QtNodes::DataModelRegistry> registry) const = 0;

private:
    std::shared_ptr<QtNodes::DataModelRegistry>
        RegisterDataModels() const;
    friend class VGraph; // scene
    QtNodes::FlowScene* scene;
};

class MGraphVert : public MGraph {
public:
    MGraphVert() = default;
    ~MGraphVert() override = default;

    void RegisterUniqueDataModels(std::shared_ptr<
        QtNodes::DataModelRegistry> registry) const override;
};

class MGraphFrag : public MGraph {
public:
    MGraphFrag() = default;
    ~MGraphFrag() override = default;

    void RegisterUniqueDataModels(std::shared_ptr<
        QtNodes::DataModelRegistry> registry) const override;
};

#endif
