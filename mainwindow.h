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
    void CreatePreviewGroupBox();
    void CreateGeneralOptionsGroupBox();
    void CreateDatesGroupBox();
    void CreateTextFormatsGroupBox();
    QComboBox * CreateColorComboBox();

    QGroupBox * PreviewGroupBox;
    QGridLayout * PreviewLayout;
    QCalendarWidget * Calendar;

    QGroupBox * GeneralOptionsGroupBox;
    QLabel * LocaleLabel;
    QLabel * FirstDayLabel;
    QLabel * SelectionModeLabel;
    QLabel * HorizontalHeaderLabel;
    QLabel * VerticalHeaderLabel;
    QComboBox * LocaleCombo;
    QComboBox * FirstDayCombo;
    QComboBox * SelectionModeCombo;
    QCheckBox * GridCheckBox;
    QCheckBox * NavigationCheckBox;
    QComboBox * HorizontalHeaderCombo;
    QComboBox * VerticalHeaderCombo;

    QGroupBox * DatesGroupBox;
    QLabel * CurrentDateLabel;
    QLabel * MinDateLabel;
    QLabel * MaxDateLabel;
    QDateEdit * CurrentDateEdit;
    QDateEdit * MinDateEdit;
    QDateEdit * MaxDateEdit;

    QGroupBox * TextFormatsGroupBox;
    QLabel * WeekdayColorLabel;
    QLabel * WeekendColorLabel;
    QLabel * HeaderTextFormatLabel;
    QComboBox * WeekdayColorCombo;
    QComboBox * HeaderTextFormatCombo;

    QCheckBox * FirstFirdayCheckBox;
    QCheckBox * MayFirstCheckBox;
};

#endif // MAINWINDOW_H
