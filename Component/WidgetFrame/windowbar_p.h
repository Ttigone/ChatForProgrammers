#ifndef WINDOWBARPRIVATE_H
#define WINDOWBARPRIVATE_H

#include "windowbar.h"

#include <QHBoxLayout>

namespace Ttigone {

class WindowBarPrivate {
    Q_DECLARE_PUBLIC(WindowBar)

public:
    WindowBarPrivate();
    virtual ~WindowBarPrivate();

    WindowBar *q_ptr;

    QWidget *w;
    bool autoTitle;
    bool autoIcon;

    enum WindowBarItem {
        IconButton,
        MenuWidget,
        TitleLabel,
        MinimumButton,
        MaxinumButton,
        CloseButton,
    };

    QHBoxLayout *m_layout;

    void init();

    inline QWidget *widgetAt(int index) const {
        return m_layout->itemAt(index)->widget();
    }

    void setWidgetAt(int index, QWidget *widget);

    QWidget *takeWidgetAt(int index);

    inline void insertDefaultSpace(int index) {
        m_layout->insertSpacerItem(index, new QSpacerItem(0, 0));
    }

private:
    Q_DISABLE_COPY(WindowBarPrivate)
};

}


#endif
