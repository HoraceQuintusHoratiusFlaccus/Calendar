#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QCheckBox;
class QComboBox;
class QDate;
class QDateEdit;
class QGridLayout;
class QGroupBox;
class QLabel;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget * Parent = nullptr);

private slots:
    void LocaleChanged(int);
    void FirstDayChanged(int);
    void SelectionModeChanged(int);
    void HorizontalHeaderChanged(int);
    void VerticalHeaderChanged(int);
    void SelectedDateChanged();
    void MinDateChanged(QDate);
    void MaxDateChanged(QDate);
    void WeekdayFormatChanged();
    void WeekendFormatChanged();
    void ReformatHeaders();
    void ReformatCalendarPage();

private:
    void CreatePreviewGroup();
    void CreateGeneralOptionsGroup();
    void CreateDatesGroup();
    void CreateTextFormatsGroup();
    QComboBox * CreateColorCombo();

    QGroupBox * PreviewGroup;
    QGridLayout * PreviewLayout;
    QCalendarWidget * Calendar;

    QGroupBox * GeneralOptionsGroup;
    QLabel * LocaleLabel;
    QLabel * FirstDayLabel;
    QLabel * SelectionModeLabel;
    QLabel * HorizontalHeaderLabel;
    QLabel * VerticalHeaderLabel;
    QComboBox * LocaleCombo;
    QComboBox * FirstDayCombo;
    QComboBox * SelectionModeCombo;
    QCheckBox * GridCheck;
    QCheckBox * NavigationCheck;
    QComboBox * HorizontalHeaderCombo;
    QComboBox * VerticalHeaderCombo;

    QGroupBox * DatesGroup;
    QLabel * CurDateLabel;
    QLabel * MinDateLabel;
    QLabel * MaxDateLabel;
    QDateEdit * CurDateEdit;
    QDateEdit * MinDateEdit;
    QDateEdit * MaxDateEdit;

    QGroupBox * TextFormatsGroup;
    QLabel * WeekdayColorLabel;
    QLabel * WeekendColorLabel;
    QLabel * HeaderTextFormatLabel;
    QComboBox * WeekdayColorCombo;
    QComboBox * WeekendColorCombo;
    QComboBox * HeaderTextFormatCombo;

    QCheckBox * FirstFridayCheck;
    QCheckBox * MayFirstCheck;
};

#endif // MAINWINDOW_H
