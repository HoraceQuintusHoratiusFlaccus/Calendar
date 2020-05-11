#include "mainwindow.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QCalendarWidget>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>
#include <QDateEdit>

Window::Window(QWidget * Parent)
    : QWidget(Parent)
{
    CreatePreviewGroup();
    CreateGeneralOptionsGroup();
    CreateDatesGroup();
    CreateTextFormatsGroup();

    QGridLayout * Layout = new QGridLayout;
    Layout -> addWidget(PreviewGroup, 0, 0);
    Layout -> addWidget(GeneralOptionsGroup, 0, 1);
    Layout -> addWidget(DatesGroup, 1, 0);
    Layout -> addWidget(TextFormatsGroup, 1, 1);
    Layout -> setSizeConstraint(QLayout::SetFixedSize);
    setLayout(Layout);

    PreviewLayout -> setRowMinimumHeight(0, Calendar -> sizeHint().height());
    PreviewLayout -> setColumnMinimumWidth(0, Calendar -> sizeHint().width());

    setWindowTitle(tr("Calendar"));
}

void Window::CreatePreviewGroup()
{
    PreviewGroup = new QGroupBox(tr("Preview"));

    Calendar = new QCalendarWidget;
    Calendar -> setMinimumDate(QDate(1900, 1, 1));
    Calendar -> setMaximumDate(QDate(3000, 1, 1));
    Calendar -> setGridVisible(true);

    connect(Calendar, &QCalendarWidget::currentPageChanged,
            this, &Window::ReformatCalendarPage);

    PreviewLayout = new QGridLayout;
    PreviewLayout -> addWidget(Calendar, 0, 0, Qt::AlignCenter);
    PreviewGroup -> setLayout(PreviewLayout);
}

void Window::CreateGeneralOptionsGroup()
{
    GeneralOptionsGroup = new QGroupBox(tr("General Options"));

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

    GridCheck = new QCheckBox(tr("&Grid"));
    GridCheck -> setChecked(Calendar -> isGridVisible());

    NavigationCheck = new QCheckBox(tr("&Navigation bar"));
    NavigationCheck -> setChecked(true);

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
    connect(GridCheck, &QCheckBox::toggled, Calendar, &QCalendarWidget::setGridVisible);
    connect(NavigationCheck, &QCheckBox::toggled,
            Calendar, &QCalendarWidget::setNavigationBarVisible);
    connect(HorizontalHeaderCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::VerticalHeaderChanged);
    connect(VerticalHeaderCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::VerticalHeaderChanged);

    QHBoxLayout * CheckBoxLayout = new QHBoxLayout;
    CheckBoxLayout -> addWidget(GridCheck);
    CheckBoxLayout -> addStretch();
    CheckBoxLayout -> addWidget(NavigationCheck);

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
    GeneralOptionsGroup->setLayout(OuterLayout);

    FirstDayChanged(FirstDayCombo -> currentIndex());
    SelectionModeChanged(SelectionModeCombo -> currentIndex());
    HorizontalHeaderChanged(HorizontalHeaderCombo -> currentIndex());
    VerticalHeaderChanged(VerticalHeaderCombo -> currentIndex());
}

void Window::CreateDatesGroup()
{
    DatesGroup = new QGroupBox(tr("Dates"));

    MinDateEdit = new QDateEdit;
    MinDateEdit -> setDisplayFormat("MMM d yyyy");
    MinDateEdit -> setDateRange(Calendar -> minimumDate(), Calendar -> maximumDate());
    MinDateEdit -> setDate(Calendar -> minimumDate());

    MinDateLabel = new QLabel(tr("&Minimum Date:"));
    MinDateLabel -> setBuddy(MinDateEdit);

    CurDateEdit = new QDateEdit;
    CurDateEdit -> setDisplayFormat("MMM d yyyy");
    CurDateEdit -> setDate(Calendar -> selectedDate());
    CurDateEdit -> setDateRange(Calendar -> minimumDate(), Calendar -> maximumDate());

    CurDateLabel = new QLabel(tr("&Current Date:"));
    CurDateLabel -> setBuddy(CurDateEdit);

    MaxDateEdit = new QDateEdit;
    MaxDateEdit -> setDisplayFormat("MMM d yyyy");
    MaxDateEdit -> setDateRange(Calendar -> minimumDate(), Calendar -> maximumDate());
    MaxDateEdit -> setDate(Calendar -> maximumDate());

    MaxDateLabel = new QLabel(tr("Ma&ximum Date:"));
    MaxDateLabel -> setBuddy(MaxDateEdit);

    connect(CurDateEdit, &QDateEdit::dateChanged, Calendar, &QCalendarWidget::setSelectedDate);
    connect(Calendar, &QCalendarWidget::selectionChanged, this, &Window::SelectedDateChanged);
    connect(MinDateEdit, &QDateEdit::dateChanged, this, &Window::MinDateChanged);
    connect(MaxDateEdit, &QDateEdit::dateChanged, this, &Window::MaxDateChanged);

    QGridLayout * DateBoxLayout = new QGridLayout;
    DateBoxLayout -> addWidget(CurDateLabel, 1, 0);
    DateBoxLayout -> addWidget(CurDateEdit, 1, 1);
    DateBoxLayout -> addWidget(MinDateLabel, 0, 0);
    DateBoxLayout -> addWidget(MinDateEdit, 0, 1);
    DateBoxLayout -> addWidget(MaxDateLabel, 2, 0);
    DateBoxLayout -> addWidget(MaxDateEdit, 2, 1);
    DateBoxLayout -> setRowStretch(3, 1);

    DatesGroup -> setLayout(DateBoxLayout);
}

void Window::CreateTextFormatsGroup()
{
    TextFormatsGroup = new QGroupBox(tr("Text Formats"));

    WeekdayColorCombo = CreateColorCombo();
    WeekdayColorCombo -> setCurrentIndex(WeekdayColorCombo -> findText(tr("Black")));

    WeekdayColorLabel = new QLabel(tr("&Weekday color:"));
    WeekdayColorLabel -> setBuddy(WeekdayColorCombo);

    WeekendColorCombo = CreateColorCombo();
    WeekendColorCombo -> setCurrentIndex(WeekendColorCombo -> findText(tr("Red")));

    WeekendColorLabel = new QLabel(tr("Week&end color:"));
    WeekendColorLabel -> setBuddy(WeekendColorCombo);

    HeaderTextFormatCombo = new QComboBox;
    HeaderTextFormatCombo -> addItem(tr("Bold"));
    HeaderTextFormatCombo -> addItem(tr("Italic"));
    HeaderTextFormatCombo -> addItem(tr("Plain"));

    HeaderTextFormatLabel = new QLabel(tr("&Header text:"));
    HeaderTextFormatLabel -> setBuddy(HeaderTextFormatCombo);

    FirstFridayCheck = new QCheckBox(tr("&FirstFriday in blue"));

    MayFirstCheck = new QCheckBox(tr("May &1 in red"));

    connect(WeekdayColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::WeekdayFormatChanged);
    connect(WeekdayColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::ReformatCalendarPage);
    connect(WeekendColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::WeekendFormatChanged);
    connect(WeekendColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::ReformatCalendarPage);
    connect(HeaderTextFormatCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::ReformatHeaders);
    connect(FirstFridayCheck, &QCheckBox::toggled, this, &Window::ReformatCalendarPage);
    connect(MayFirstCheck, &QCheckBox::toggled, this, &Window::ReformatCalendarPage);

    QHBoxLayout * CheckBoxLayout = new QHBoxLayout;
    CheckBoxLayout -> addWidget(FirstFridayCheck);
    CheckBoxLayout -> addStretch();
    CheckBoxLayout -> addWidget(MayFirstCheck);

    QGridLayout * OuterLayout = new QGridLayout;
    OuterLayout -> addWidget(WeekdayColorLabel, 0, 0);
    OuterLayout -> addWidget(WeekdayColorCombo, 0, 1);
    OuterLayout -> addWidget(WeekendColorLabel, 1, 0);
    OuterLayout -> addWidget(WeekendColorCombo, 1, 1);
    OuterLayout -> addWidget(HeaderTextFormatLabel, 2, 0);
    OuterLayout -> addWidget(HeaderTextFormatCombo, 2, 1);
    OuterLayout -> addLayout(CheckBoxLayout, 3, 0, 1, 2);
    TextFormatsGroup -> setLayout(OuterLayout);

    WeekdayFormatChanged();
    WeekendFormatChanged();

    ReformatHeaders();
    ReformatCalendarPage();
}
