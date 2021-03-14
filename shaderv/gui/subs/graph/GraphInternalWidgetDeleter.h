#ifndef _GRAPH_INTERNAL_WIDGET_DELETER_H_
#define _GRAPH_INTERNAL_WIDGET_DELETER_H_

#include "../../UiBasic.hpp"

class GraphInternalWidgetDeleter {
public:
    static GraphInternalWidgetDeleter& GetDeleter();

private:
    static GraphInternalWidgetDeleter deleter;

public:
    void RegisterWidget(QString name, QWidget* widget);

protected:
    virtual ~GraphInternalWidgetDeleter();

private:
    // Max same key: vert + frag
    static constexpr int MAX_SAME_KEY = 2;
    QMap<QString, QVector<QWidget*>> widgets;
};

#define REGISTER_INTERNAL_WIDGET(n, w) \
GraphInternalWidgetDeleter::GetDeleter().RegisterWidget(n, w)

#endif
