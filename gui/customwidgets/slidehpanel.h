#ifndef SLIDEHPANEL_H
#define SLIDEHPANEL_H

#include "slidepanel.h"

class SlideHPanel : public SlidePanel
{
    Q_OBJECT
public:
    explicit SlideHPanel(QWidget *parent);
    ~SlideHPanel();
    void setPosition(PanelHPosition);
    QRect triggerRect();
    void setPanelHeight(int);

protected:
    PanelHPosition position;
    int invisibleMargin;
    int panelHeight;
    void recalculateGeometry();
    virtual void updateTriggerRect();
};

#endif // SLIDEHPANEL_H
