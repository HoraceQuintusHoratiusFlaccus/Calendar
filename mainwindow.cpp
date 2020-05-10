#include "mainwindow.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QCalendarWidget>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>

Window::Window(QWidget * Parent)
    : QWidget(Parent)
{
    CreatePreviewGroupBox();
    CreateGeneralOptionsGroupBox();
    CreateDatesGroupBox();
    CreateTextFormatsGroupBox();

    QGridLayout * Layout = new QGridLayout;
    Layout -> addWidget(PreviewGroupBox, 0, 0);
    Layout -> addWidget(GeneralOptionsGroupBox, 0, 1);
    Layout -> addWidget(DatesGroupBox, 1, 0);
    Layout -> addWidget(TextFormatsGroupBox, 1, 1);
    Layout -> setSizeConstraint(QLayout::SetFixedSize);
    setLayout(Layout);

    PreviewLayout -> setRowMinimumHeight(0, Calendar -> sizeHint().height());
    PreviewLayout -> setColumnMinimumWidth(0, Calendar -> sizeHint().width());

    setWindowTitle(tr("Calendar"));
}

void Window::CreatePreviewGroupBox()
{
    PreviewGroupBox = new QGroupBox(tr("Preview"));

    Calendar = new QCalendarWidget;
    Calendar -> setMinimumDate(QDate(1900, 1, 1));
    Calendar -> setMaximumDate(QDate(3000, 1, 1));
    Calendar -> setGridVisible(true);

    connect(Calendar, &QCalendarWidget::currentPageChanged,
            this, &Window::ReformatCalendarPage);

    PreviewLayout = new QGridLayout;
    PreviewLayout -> addWidget(Calendar, 0, 0, Qt::AlignCenter);
    PreviewGroupBox -> setLayout(PreviewLayout);
}

void Window::CreateGeneralOptionsGroupBox()
{
    GeneralOptionsGroupBox = new QGroupBox(tr("General Options"));

    LocaleCombo = new QComboBox;
    int CurLocaleIndex = -1;
    int Index = 0;
    for (int lang = QLocale::C; lang <= QLocale::LastLanguage; ++lang)
    {
        QLocale::Language Lang = static_cast<QLocale::Language>(lang);
        QList<QLocale::Country> Countries = QLocale::countriesForLanguage(Lang);
        for (int i = 0; i < Countries.count(); ++i)
        {
            QLocale::Country Country = Countries.at(i);
            QString Label = QLocale::languageToString(Lang);
            Label += QLatin1Char('/');
            Label += QLocale::countryToString(Country);
            QLocale Locale(Lang, Country);
            if (this -> locale().language() == Lang && this -> locale().country() == Country)
                CurLocaleIndex = Index;
            LocaleCombo -> addItem(Label, Locale);
            ++Index;
        }
    }
    if (CurLocaleIndex != -1)
        LocaleCombo -> setCurrentIndex(CurLocaleIndex);
    LocaleLabel = new QLabel(tr("&Locale"));
    LocaleLabel -> setBuddy(LocaleCombo);

    FirstDayCombo = new QComboBox;
    FirstDayCombo -> addItem(tr("Sunday"), Qt::Sunday);
    FirstDayCombo -> addItem(tr("Monday"), Qt::Monday);
    FirstDayCombo -> addItem(tr("Tuesday"), Qt::Tuesday);
    FirstDayCombo -> addItem(tr("Wednesday"), Qt::Wednesday);
    FirstDayCombo -> addItem(tr("Thursday"), Qt::Thursday);
    FirstDayCombo -> addItem(tr("Friday"), Qt::Friday);
    FirstDayCombo -> addItem(tr("Saturday"), Qt::Saturday);

    FirstDayLabel = new QLabel(tr("Wee&k starts on:"));
    FirstDayLabel -> setBuddy(FirstDayCombo);

    SelectionModeCombo = new QComboBox;
    SelectionModeCombo -> addItem(tr("Single selection"), QCalendarWidget::SingleSelection);
    SelectionModeCombo -> addItem(tr("None"), QCalendarWidget::NoSelection);

    SelectionModeLabel = new QLabel(tr("&Selection mode:"));
    SelectionModeLabel -> setBuddy(SelectionModeCombo);

    GridCheckBox = new QCheckBox(tr("&Grid"));
    GridCheckBox -> setChecked(Calendar -> isGridVisible());

    NavigationCheckBox = new QCheckBox(tr("&Navigation bar"));
    NavigationCheckBox -> setChecked(true);

    HorizontalHeaderCombo = new QComboBox;
    HorizontalHeaderCombo -> addItem(tr("Single letter day names"),
                                     QCalendarWidget::SingleLetterDayNames);
    HorizontalHeaderCombo -> addItem(tr("Short day names"), QCalendarWidget::ShortDayNames);
    HorizontalHeaderCombo -> addItem(tr("None"), QCalendarWidget::NoHorizontalHeader);
    HorizontalHeaderCombo -> setCurrentIndex(1);

    HorizontalHeaderLabel = new QLabel(tr("&Horizontal header:"));
    HorizontalHeaderLabel -> setBuddy(HorizontalHeaderCombo);

    VerticalHeaderCombo = new QComboBox;
    VerticalHeaderCombo -> addItem(tr("ISO week numbers"), QCalendarWidget::ISOWeekNumbers);
    VerticalHeaderCombo -> addItem(tr("None"), QCalendarWidget::NoVerticalHeader);

    VerticalHeaderLabel = new QLabel(tr("&Vertical header:"));
    VerticalHeaderLabel -> setBuddy(VerticalHeaderCombo);

    connect(LocaleCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::LocaleChanged);
    connect(FirstDayCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::FirstDayChanged);
    connect(SelectionModeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::SelectionModeChanged);
    connect(GridCheckBox, &QCheckBox::toggled, Calendar, &QCalendarWidget::setGridVisible);
    connect(NavigationCheckBox, &QCheckBox::toggled,
            Calendar, &QCalendarWidget::setNavigationBarVisible);
    connect(HorizontalHeaderCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::VerticalHeaderChanged);
    connect(VerticalHeaderCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::VerticalHeaderChanged);

    QHBoxLayout * CheckBoxLayout = new QHBoxLayout;
    CheckBoxLayout -> addWidget(GridCheckBox);
    CheckBoxLayout -> addStretch();
    CheckBoxLayout -> addWidget(NavigationCheckBox);

    QGridLayout * OuterLayout = new QGridLayout;
    OuterLayout->addWidget(LocaleLabel, 0, 0);
    OuterLayout->addWidget(LocaleCombo, 0, 1);
    OuterLayout->addWidget(FirstDayLabel, 1, 0);
    OuterLayout->addWidget(FirstDayCombo, 1, 1);
    OuterLayout->addWidget(SelectionModeLabel, 2, 0);
    OuterLayout->addWidget(SelectionModeCombo, 2, 1);
    OuterLayout->addLayout(CheckBoxLayout, 3, 0, 1, 2);
    OuterLayout->addWidget(HorizontalHeaderLabel, 4, 0);
    OuterLayout->addWidget(HorizontalHeaderCombo, 4, 1);
    OuterLayout->addWidget(VerticalHeaderLabel, 5, 0);
    OuterLayout->addWidget(VerticalHeaderCombo, 5, 1);
    GeneralOptionsGroupBox->setLayout(OuterLayout);

    FirstDayChanged(FirstDayCombo -> currentIndex());
    SelectionModeChanged(SelectionModeCombo -> currentIndex());
    HorizontalHeaderChanged(HorizontalHeaderCombo -> currentIndex());
    VerticalHeaderChanged(VerticalHeaderCombo -> currentIndex());
}
