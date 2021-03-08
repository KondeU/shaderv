#include "VGraph.h"
#include "MGraph.h"

bool VGraph::styled = false;

VGraph::VGraph(const MGraph& model, const QString& shaderType)
    : ViewCenter(shaderType)
{
    if (!styled) {
        QtNodes::FlowViewStyle::setStyle(
        R"(
        {
          "FlowViewStyle": {
            "BackgroundColor" : [200, 200, 192],
            "CoarseGridColor" : [180, 180, 175],
            "FineGridColor"   : [190, 190, 185]
          }
        }
        )");

        QtNodes::ConnectionStyle::setConnectionStyle(
        R"(
        {
          "ConnectionStyle": {
            "ConstructionColor"     : "darkgray",
            "NormalColor"           : "black",
            "SelectedColor"         : "darkgray",
            "SelectedHaloColor"     : "deepskyblue",
            "HoveredColor"          : "deepskyblue",
            "LineWidth"             : 3.0,
            "ConstructionLineWidth" : 2.0,
            "PointDiameter"         : 10.0,
            "UseDataDefinedColors"  : true
          }
        }
        )");

        styled = true;
    }

    view = QT_NEW QtNodes::FlowView(model.scene);
    SetStuff(view);
}

VGraph::~VGraph()
{
}
