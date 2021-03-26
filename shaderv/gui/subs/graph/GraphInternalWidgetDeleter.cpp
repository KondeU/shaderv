#include "GraphInternalWidgetDeleter.h"

GraphInternalWidgetDeleter GraphInternalWidgetDeleter::deleter;

GraphInternalWidgetDeleter& GraphInternalWidgetDeleter::GetDeleter()
{
    return deleter;
}

void GraphInternalWidgetDeleter::RegisterWidget(QString name, QWidget* widget)
{
    if (widgets.find(name) == widgets.end()) {
        widgets[name].push_back(widget);
    } else {
        if (widgets[name].size() < MAX_SAME_KEY) {
            widgets[name].push_back(widget);
        }
    }
}

GraphInternalWidgetDeleter::~GraphInternalWidgetDeleter()
{
    for (QVector<QWidget*>& sameTypeWidgets : widgets) {
        for (QWidget* widget : sameTypeWidgets) {
            QT_DEL widget;
        }
    }
}
