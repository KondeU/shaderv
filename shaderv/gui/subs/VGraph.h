#ifndef _V_GRAPH_H_
#define _V_GRAPH_H_

#include "../mvp/ViewCenter.hpp"

class MGraph;
class VGraph : public ViewCenter {
public:
    explicit VGraph(const MGraph& model);
    ~VGraph() override;

private:
    QtNodes::FlowView* view;
};

#endif
