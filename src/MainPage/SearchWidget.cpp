#include "SearchWidget.h"

#include <QVBoxLayout>

SearchWidget::SearchWidget(QWidget *parent)
    : QWidget{parent},
      m_searchEditor(new QtMaterialAutoComplete)
{
    init();
}

void SearchWidget::init() {
    m_layout = new QHBoxLayout(this);
    m_layout->setContentsMargins(QMargins());
    m_layout->setSpacing(0);

    m_addMsgBtn = new QPushButton;

    m_baseWidget = new QWidget;
    m_baseWidget->setObjectName(QStringLiteral("MainPage-search-Widget"));
    m_baselayout = new QHBoxLayout(m_baseWidget);
    m_baselayout->setContentsMargins(QMargins(10, 10, 10, 10));
    // m_baselayout->setContentsMargins(QMargins());
    m_baselayout->setSpacing(10);

    m_baselayout->addWidget(m_searchEditor);
    m_baselayout->addWidget(m_addMsgBtn);

    m_layout->addWidget(m_baseWidget);
}



// AutoCompleteSettingsEditor::AutoCompleteSettingsEditor(QWidget *parent)
//     : QWidget(parent),
//       m_autocomplete(new QtMaterialAutoComplete)
// {
//     // 垂直布局
//     QVBoxLayout *layout = new QVBoxLayout;

//     setLayout(layout);

//     QWidget *widget = new QWidget;

//     layout->addWidget(widget);

//     // 画板
//     QWidget *canvas = new QWidget;
//     // 设置 样式表
//     canvas->setStyleSheet("QWidget { background: white; }");

//     // 整个画板
//     layout->addWidget(canvas);

//     // 最小高度
//     canvas->setMinimumHeight(900); //


//     // 设置边距
//     layout->setContentsMargins(20, 20, 20, 20);


//     layout = new QVBoxLayout;

//     // 新的垂直布局 设置给 画板
//     canvas->setLayout(layout);

//     // 状态机的 状态
//     QStringList states =
//       { "Alabama"
//       , "Alaska"
//       , "American Samoa"
//       , "Arizona"
//       , "Arkansas"
//       , "California"
//       , "Colorado"
//       , "Connecticut"
//       , "Delaware"
//       , "District of Columbia"
//       , "Florida"
//       , "Georgia"
//       , "Guam"
//       , "Hawaii"
//       , "Idaho"
//       , "Illinois"
//       , "Indiana"
//       , "Iowa"
//       , "Kansas"
//       , "Kentucky"
//       , "Louisiana"
//       , "Maine"
//       , "Maryland"
//       , "Massachusetts"
//       , "Michigan"
//       , "Minnesota"
//       , "Mississippi"
//       , "Missouri"
//       , "Montana"
//       , "Nebraska"
//       , "Nevada"
//       , "New Hampshire"
//       , "New Jersey"
//       , "New Mexico"
//       , "New York"
//       , "North Carolina"
//       , "North Dakota"
//       , "Northern Marianas Islands"
//       , "Ohio"
//       , "Oklahoma"
//       , "Oregon"
//       , "Pennsylvania"
//       , "Puerto Rico"
//       , "Rhode Island"
//       , "South Carolina"
//       , "South Dakota"
//       , "Tennessee"
//       , "Texas"
//       , "Utah"
//       , "Vermont"
//       , "Virginia"
//       , "Virgin Islands"
//       , "Washington"
//       , "West Virginia"
//       , "Wisconsin"
//       , "Wyoming"
//     };

//     // 设置数据源
//     m_autocomplete->setDataSource(states);

//     // 画板的布局 添加 widget
//     layout->addWidget(m_autocomplete);

//     // 间隙
//     layout->addSpacing(600);

//     // 方向
//     layout->setAlignment(m_autocomplete, Qt::AlignCenter);


//     setupForm();
// }

// AutoCompleteSettingsEditor::~AutoCompleteSettingsEditor()
// {
//     //delete ui;
// }

// void AutoCompleteSettingsEditor::setupForm()
// {
// }

// void AutoCompleteSettingsEditor::updateWidget()
// {
// }

// void AutoCompleteSettingsEditor::selectColor()
// {
// }
