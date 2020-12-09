#include "mainwindow.h"
//#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QFile>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDoubleSpinBox>

#include "qcustomplot.h"
#include <process.h>
#include <conio.h>
#include <wchar.h>
#include <errors.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    inputFile = new QFile(inputPath);
    if (inputFile->exists())
        inputFile->resize(0);
    outputFile = new QFile(outputPath);
    if (outputFile->exists())
        outputFile->resize(0);

    setupPlot();
    setupWorkArea();

    connect(plot, &QCustomPlot::mousePress, this, &MainWindow::slotMousePress);
    connect(createHullButt, &QPushButton::clicked, this, &MainWindow::on_addPushButton_clicked);
    connect(clearButt, &QPushButton::clicked, this, &MainWindow::on_cleanPushButton_clicked);
    connect(addDotButt, &QPushButton::clicked, this, &MainWindow::on_addDotPushButton_clicked);
}


void MainWindow::on_addPushButton_clicked()
{
    // запуск программы на Haskell
    // результат - файл hull.txt
    //

    wchar_t lpszCommandLine[] =L"Main.exe dots.txt hull.txt";
    STARTUPINFO si;
    PROCESS_INFORMATION piCom;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    if(!CreateProcess(NULL,lpszCommandLine,NULL, NULL, FALSE,CREATE_NO_WINDOW,NULL, NULL, &si, &piCom))
        qDebug()<<(GetLastError(),"CreateProcess failed");
    WaitForSingleObject(piCom.hProcess, INFINITE);
    CloseHandle(piCom.hThread);
    CloseHandle(piCom.hProcess);

    //system("Main.exe dots.txt hull.txt");
    readFromFile(outputFile);
}

void MainWindow::on_cleanPushButton_clicked()
{
    clearData();
}

void MainWindow::on_addDotPushButton_clicked(){
    addPoint(xSpinBox->value(),ySpinBox->value());
}


void MainWindow::setupPlot()
{
    plot = new QCustomPlot();
    plot->addGraph();
    plot->graph(0) ->setScatterStyle(QCPScatterStyle::ssCircle);
    plot->graph(0) ->setLineStyle(QCPGraph::lsNone);
    newCurve = new QCPCurve(plot->xAxis, plot->yAxis);
}

void MainWindow::setupWorkArea()
{
    QMdiArea *mdiArea = new QMdiArea(this);
    mainLayout = new QVBoxLayout(mdiArea);
    mainLayout->addWidget(plot);

    xLabel = new QLabel();
    yLabel = new QLabel();
    xLabel -> setText(tr("X:"));
    yLabel -> setText(tr("Y:"));
    xSpinBox = new QDoubleSpinBox();
    ySpinBox = new QDoubleSpinBox();
    xSpinBox ->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ySpinBox ->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);


    xLayout = new QHBoxLayout();
    xLayout -> addWidget(xLabel);
    xLayout -> addWidget(xSpinBox);

    yLayout = new QHBoxLayout();
    yLayout -> addWidget(yLabel);
    yLayout -> addWidget(ySpinBox);

    createHullButt = new QPushButton(tr("Создать оболочку"));
    clearButt = new QPushButton(tr("Очистить"));
    addDotButt = new QPushButton(tr("Добавить точку"));

    controlLayout = new QHBoxLayout();
    controlLayout -> addLayout(xLayout);
    controlLayout -> addLayout(yLayout);
    controlLayout -> addStretch(1);
    controlLayout -> addWidget(addDotButt);
    controlLayout -> addWidget(createHullButt);
    controlLayout -> addWidget(clearButt);

    mainLayout -> addLayout(controlLayout);

    this->setCentralWidget(mdiArea);
}

void MainWindow::writeToFile(QFile* file, QString message){
    if(!file -> open(QIODevice::Append)){
        qDebug()<<"MainWindow::printFile: File "+file->fileName()+ " not open for writing";
        return;
    }
    QTextStream *stream = new QTextStream(file);
    *stream<<message;
    delete stream;
    file->close();
}

void MainWindow::saveToFile(QFile* file)
{
    if (inputFile->exists())
        inputFile->resize(0);
    if(!file -> open(QIODevice::WriteOnly)){
        qDebug()<<"MainWindow::printFile: File "+file->fileName()+ " not open for writing";
        return;
    }
    QTextStream *stream = new QTextStream(file);
    for(auto x_it = inp_x.begin(), y_it = inp_y.begin(); x_it!=inp_x.end() && y_it!= inp_y.end();x_it++, y_it++){
        *stream<<*x_it<<" "<<*y_it<<Qt::endl;
    }
    delete stream;
    file->close();
}

void MainWindow::readFromFile(QFile * file)
{
    if(!file->open(QIODevice::ReadOnly| QIODevice::Text)){
        qDebug()<<"MainWindow::printFile: File "+file->fileName()+ " not open for reading";
        return;
    }
    //file->readLine();
    while(!file->atEnd()){
        QString line = QString::fromUtf8(file->readLine());
        line = line.simplified();
        QStringList words = line.split(" ",Qt::SkipEmptyParts);
        out_x.append(words.at(0).toDouble());
        out_y.append(words.at(1).toDouble());
        //newCurve = new QCPCurve(plot->xAxis, plot->yAxis);
        newCurve->setData(out_x, out_y);

        plotF();

    }
    file->close();
}



void MainWindow::addPoint(double x, double y)
{
    double eps = 0.0001;
    for(auto x_it = inp_x.begin(), y_it = inp_y.begin(); x_it!=inp_x.end() && y_it!= inp_y.end();x_it++, y_it++){
        if(abs(x-*x_it)<eps && abs(y-*y_it)<eps)
            return;
    }

    inp_x.append(x);
    inp_y.append(y);
    plotF();
    QString a = QString::number(x) + " "+ QString::number(y)+"\n";
    writeToFile(inputFile,a);
}



void MainWindow::slotMousePress(QMouseEvent *event)
{
    // Определяем координату X на графике, где был произведён клик мышью
    double coordX = plot->xAxis->pixelToCoord(event->pos().x());
    double coordY = plot->yAxis->pixelToCoord(event->pos().y());

    xSpinBox->setValue(coordX);
    ySpinBox->setValue(coordY);

    addPoint(coordX,coordY);
}

void MainWindow::plotF()
{
    plot->graph(0)->setData(inp_x, inp_y);
    newCurve->setData(out_x, out_y);
    plot->replot();
    plot->update();
}

void MainWindow::clearData()
{
    if (inputFile->exists())
        inputFile->resize(0);
    if (outputFile->exists())
        outputFile->resize(0);
    out_x.clear();
    out_y.clear();
    inp_x.clear();
    inp_y.clear();
    plotF();
}
