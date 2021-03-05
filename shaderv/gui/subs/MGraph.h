#ifndef _M_GRAPH_H_
#define _M_GRAPH_H_

#include "../mvp/Model.hpp"

class MGraph : public Model {
public:
    MGraph();
    ~MGraph() override;

private:
    std::shared_ptr<QtNodes::DataModelRegistry>
        RegisterDataModels() const;
    friend class VGraph; // scene
    QtNodes::FlowScene* scene;
};

#endif
