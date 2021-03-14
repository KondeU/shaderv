#include "MGraph.h"
#include "graph/input/NDecimalInputModel.h"

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

    reg->registerModel<NDecimalInputModel>("Input");

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
