#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    validator = new QDoubleValidator(-1e9,1e9,3,NULL);
    ui->inputStartFreq->setValidator(validator);
    ui->inputEndFreq->setValidator(validator);
    ui->inputVoltage->setValidator(validator);

    funcgen = new FunctionGenerator();
    visaInst = new VisaInstrument();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete validator;
}
void MainWindow::PhaseButtonClicked()
{
    QMessageBox msg;
    msg.setText("Phase Button Pressed!");
    msg.exec();
    QString phase = ui->phaseInput->text();
    float Phase = phase.toFloat();
    funcgen->applyPhase(Phase);
}
void MainWindow::OffsetButtonClicked()
{
    QMessageBox msg;
    msg.setText("Offset Button Pressed!");
    msg.exec();
    QString offset = ui->offsetInput->text();
    float Offset = offset.toFloat();
    funcgen->applyOffset(Offset);
}
void MainWindow::SinButtonClicked()
{
    QMessageBox msg;
    msg.setText("Sin Button Pressed!");
    msg.exec();
    QString sin = ui->inputSinFreq->text();
    float Sin = sin.toFloat();
    funcgen->applySinWave(Sin);

}
void MainWindow::SweepButtonClicked()
{
    QMessageBox msg;
    msg.setText("Sweep Button Pressed!");
    msg.exec();






    QString startFreq = ui->inputStartFreq->text();
    QString endFreq = ui->inputEndFreq->text();
    float start = startFreq.toFloat();
    float end = endFreq.toFloat();

    funcgen->sweep(start,end);


}

void MainWindow::setVoltageButton()
{
    QMessageBox msg;
    msg.setText("Set Voltage Button Pressed!");
    msg.exec();

    QString volts = ui->inputVoltage->text();
    float voltage = volts.toFloat();
    funcgen->setVoltage(voltage);
   //msg.setText("Set Voltage to %f",voltage);


}

void MainWindow::DeviceStatusButton()
{
    QMessageBox msg;
    msg.setText("Device Status Button Pressed!");
    msg.exec();

     //visaInst->idn();

}
void MainWindow::FrequencyButtonClicked()
{
    QMessageBox msg;
    msg.setText("Frequency Button Pressed!");
    msg.exec();
    QString inputFreq = ui->inputFreq->text();

    float startfreq = inputFreq.toFloat();

    funcgen->setFrequency(startfreq);
}
void MainWindow::ConnectButtonClicked()
{
    QMessageBox msg;
    msg.setText("Connect Button Pressed!");
    msg.exec();

    funcgen->initialization();


}
void MainWindow::AmplitudeButtonClicked()
{
    QMessageBox msg;
    msg.setText("Amplitude Button Pressed!");
    msg.exec();


}
void MainWindow::SquareButtonClicked()
{
    QMessageBox msg;
    msg.setText("Square Button Pressed!");
    msg.exec();
    QString square = ui->inputSquareFreq->text();

    float squarefreq = square.toFloat();

    funcgen->applySquareWave(squarefreq);
}

void MainWindow::PulseButtonClicked()
{
    QMessageBox msg;
    msg.setText("Pulse Button Pressed!");
    msg.exec();
    QString pulse = ui->inputPulseFreq->text();

    float pulsefreq = pulse.toFloat();

    funcgen->applyPulse(pulsefreq);
}
void MainWindow::RampButtonClicked()
{
    QMessageBox msg;
    msg.setText("Ramp Button Pressed!");
    msg.exec();
    QString ramp = ui->inputRampFreq->text();
    //QString ramp1 = ui->inputRampAmplitude->text();
    float rampfreq = ramp.toFloat();
    //float rampAmpl = ramp1.toFloat();
    funcgen->applyRamp(rampfreq);
}
void MainWindow::VoltageButtonClicked()
{
    QMessageBox msg;
    msg.setText("Voltage Button Pressed!");
    msg.exec();

  //  QString thetext = ui->inputLineEdit->text();
   // double x = thetext.toDouble();
    //double y = sin(x);
    //QString answer("Answer = %1");

    //ui->answerLabel->setText(answer.arg(y));
}

