#include "MGraph.h"

MGraph::MGraph()
{
    scene = QT_NEW QtNodes::FlowScene(
        RegisterDataModels(), this);
}

MGraph::~MGraph()
{
}

std::shared_ptr<QtNodes::DataModelRegistry>
MGraph::RegisterDataModels() const
{
    std::shared_ptr<QtNodes::DataModelRegistry> ret =
        std::make_shared<QtNodes::DataModelRegistry>();
    return ret;
}
