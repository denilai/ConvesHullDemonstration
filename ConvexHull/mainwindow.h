#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QFile;
class QCustomPlot;
class QHBoxLayout;
class QVBoxLayout;
class QDoubleSpinBox;
class QString;
class QCPCurve;
class QLabel;
class QPushButton;


//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void on_addPushButton_clicked();
    void slotMousePress(QMouseEvent*);
    void on_cleanPushButton_clicked();
    void on_addDotPushButton_clicked();

private:

    QDoubleSpinBox * xSpinBox = nullptr;
    QDoubleSpinBox * ySpinBox = nullptr;
    QLabel * xLabel = nullptr;
    QLabel * yLabel = nullptr;

    QVBoxLayout * mainLayout = nullptr;
    QHBoxLayout * controlLayout = nullptr;

    QHBoxLayout * xLayout = nullptr;
    QHBoxLayout * yLayout = nullptr;

    QPushButton * createHullButt = nullptr;
    QPushButton * clearButt = nullptr;
    QPushButton * addDotButt = nullptr;

    QCustomPlot * plot = nullptr;

    void setupPlot();
    void setupWorkArea();

    QString inputPath = "dots.txt";
    QString outputPath = "hull.txt";
    QFile * inputFile = nullptr;
    QFile * outputFile = nullptr;

    void writeToFile(QFile*, QString);
    void saveToFile(QFile*);
    void readFromFile(QFile*);
    void addPoint (double x, double y);
    void plotF();
    void clearData();
    QVector <double> inp_x, inp_y, out_x, out_y;
    QCPCurve * newCurve;

    //Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
