#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <functiongenerator.h>
#include <visainstrument.h>
#include <QDoubleValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QDoubleValidator* validator;

    FunctionGenerator* funcgen;
    VisaInstrument* visaInst;
    VisaInstrument* idn;

public slots:
    void DeviceStatusButton();
    void SinButtonClicked();
    void FrequencyButtonClicked();
    void ConnectButtonClicked();
    void AmplitudeButtonClicked();
    void SquareButtonClicked();
    void VoltageButtonClicked();
    void SweepButtonClicked();
    void setVoltageButton();
    void RampButtonClicked();
    void PulseButtonClicked();
    void PhaseButtonClicked();
    void OffsetButtonClicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
