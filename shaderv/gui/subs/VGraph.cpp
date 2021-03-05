#include "VGraph.h"
#include "MGraph.h"

VGraph::VGraph(const MGraph& model)
    : ViewCenter("Graph")
{
    //QtNodes::FlowViewStyle::setStyle(
    //R"(
    //{
    //  "FlowViewStyle": {
    //    "BackgroundColor" : [127, 127, 120],
    //    "CoarseGridColor" : [105, 105, 100],
    //    "FineGridColor"   : [115, 115, 110]
    //  }
    //}
    //)");

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
        "ConstructionColor"     : "lightgray",
        "NormalColor"           : "black",
        "SelectedColor"         : "lightgray",
        "SelectedHaloColor"     : "deepskyblue",
        "HoveredColor"          : "deepskyblue",
        "LineWidth"             : 3.0,
        "ConstructionLineWidth" : 2.0,
        "PointDiameter"         : 10.0,
        "UseDataDefinedColors"  : true
      }
    }
    )");

    view = QT_NEW QtNodes::FlowView(model.scene);
    SetStuff(view);
}

VGraph::~VGraph()
{
}
