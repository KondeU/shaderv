#ifndef _V_GRAPH_H_
#define _V_GRAPH_H_

#include "../mvp/ViewCenter.hpp"

class MGraph;
class VGraph : public ViewCenter {
public:
    VGraph(const MGraph& model, const QString& shaderType);
    ~VGraph() override;

private:
    QtNodes::FlowView* view;
    static bool styled;
};

#endif
