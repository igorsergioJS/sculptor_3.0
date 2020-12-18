#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include "sculptor.h"
#include "plotter.h"
#include "QMessageBox"
#include "QProcess"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        ui->horizontalSliderBoxX->setMaximum(ui->widget->sx-1);
        ui->horizontalSliderBoxY->setMaximum(ui->widget->sy-1);
        ui->horizontalSliderBoxZ->setMaximum(ui->widget->sz-1);
        ui->horizontalSliderRaioEsfera->setMaximum(ui->widget->sx/2 -1);
        ui->horizontalSliderElipRx->setMaximum(ui->widget->sx/2 -1);
        ui->horizontalSliderElipRy->setMaximum(ui->widget->sy/2 -1);
        ui->horizontalSliderElipRz->setMaximum(ui->widget->sz/2 -1);
        ui->horizontalSliderPlanoSpec->setMaximum(ui->widget->sz -1);
        ui->spinBoxAlpha->setValue(255);
        ui->horizontalSliderDimX->setValue(ui->widget->sx);
        ui->horizontalSliderDimY->setValue(ui->widget->sy);
        ui->horizontalSliderDimZ->setValue(ui->widget->sz);
        ui->pushButtonXY->setChecked(true);


        connect(ui->horizontalSliderPlanoSpec,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeSlice(int)));

            connect(ui->radioButtonPutVoxel,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(pVoxel()));

            connect(ui->radioButtonCutVoxel,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(cVoxel()));

            connect(ui->radioButtonPutBox,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(pBox()));

            connect(ui->radioButtonCutBox,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(cBox()));

            connect(ui->radioButtonPutSphere,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(pShpere()));

            connect(ui->radioButtonCutSphere,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(cShpere()));

            connect(ui->radioButtonPutEllipsoid,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(pEllip()));

            connect(ui->radioButtonCutEllipsoid,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(cEllip()));

            connect(ui->horizontalSliderRed,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeRed(int)));

            connect(ui->horizontalSliderBlue,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeBlue(int)));

            connect(ui->horizontalSliderGreen,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeGreen(int)));

            connect(ui->spinBoxAlpha,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeAlpha(int)));

            connect(ui->horizontalSliderBoxX,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeDimx(int)));

            connect(ui->horizontalSliderBoxY,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeDimy(int)));

            connect(ui->horizontalSliderBoxZ,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeDimz(int)));

            connect(ui->horizontalSliderRaioEsfera,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeRad(int)));

            connect(ui->horizontalSliderElipRx,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeRx(int)));

            connect(ui->horizontalSliderElipRy,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeRy(int)));

            connect(ui->horizontalSliderElipRz,
                    SIGNAL(valueChanged(int)),
                    ui->widget,
                    SLOT(changeRz(int)));

            connect(ui->pushButtonXY,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(changeXY()));

            connect(ui->pushButtonYZ,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(changeYZ()));

            connect(ui->pushButtonXZ,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(changeZX()));

            connect(ui->pushButtonCanvas,
                        SIGNAL(clicked(bool)),
                        this,
                        SLOT(selectPlane()));

            connect(ui->pushButtonGeomview,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(geomview()));

            connect(ui->pushButtonMeshlab,
                    SIGNAL(clicked(bool)),
                    this,
                    SLOT(meshlab()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sair()
{
    exit(0);
}


void MainWindow::selectPlane(){


      ui->widget->sx = ui->horizontalSliderDimX->value();
      ui->widget->sy = ui->horizontalSliderDimY->value();
      ui->widget->sz = ui->horizontalSliderDimZ->value();
      ui->widget->s->~Sculptor();
      ui->widget->s = new Sculptor(ui->widget->sx,ui->widget->sy,ui->widget->sz);
      ui->horizontalSliderBoxX->setMaximum(ui->widget->sx-1);
      ui->horizontalSliderBoxY->setMaximum(ui->widget->sy-1);
      ui->horizontalSliderBoxZ->setMaximum(ui->widget->sz-1);
      ui->horizontalSliderRaioEsfera->setMaximum(ui->widget->sx/2 -1);
      ui->horizontalSliderElipRx->setMaximum(ui->widget->sx/2 -1);
      ui->horizontalSliderElipRy->setMaximum(ui->widget->sy/2 -1);
      ui->horizontalSliderElipRz->setMaximum(ui->widget->sz/2 -1);
      ui->horizontalSliderPlanoSpec->setMaximum(ui->widget->sz -1);
      ui->widget->repaint();
}


void MainWindow::changeXY() //XY
{
    ui->widget->pl = XY;
    emit ui->widget->planeChosen(XY);
    ui->widget->dim = ui->widget->sz/2;
    ui->horizontalSliderPlanoSpec->setMaximum(ui->widget->sz -1);
    ui->widget->repaint();
}

void MainWindow::changeYZ() //YZ
{
    ui->widget->pl = YZ;
    emit ui->widget->planeChosen(YZ);
    ui->widget->dim = ui->widget->sx/2;
    ui->horizontalSliderPlanoSpec->setMaximum(ui->widget->sx -1);
    ui->widget->repaint();
}

void MainWindow::changeZX()
{
    ui->widget->pl = ZX;
    emit ui->widget->planeChosen(ZX);
    ui->widget->dim = ui->widget->sy/2;
    ui->horizontalSliderPlanoSpec->setMaximum(ui->widget->sy -1);
    ui->widget->repaint();
}

void MainWindow::pVoxel() //PV
{
    ui->widget->sh = 1;
}
void MainWindow::cVoxel() //CV
{
    ui->widget->sh = 2;
}
void MainWindow::pBox() //PB
{
    ui->widget->sh = 3;
}
void MainWindow::cBox() //CB
{
    ui->widget->sh= 4;
}
void MainWindow::pShpere() //PS
{
    ui->widget->sh = 5;
}
void MainWindow::cShpere() //CS
{
    ui->widget->sh = 6;
}
void MainWindow::pEllip() //PE
{
    ui->widget->sh = 7;
}
void MainWindow::cEllip() //PS
{
    ui->widget->sh= 8;
}

void MainWindow::geomview()
{
        QProcess process;
        process.start("geomview", QStringList() << ui->lineEditOFF->text() +".OFF");
        process.waitForFinished();
}

void MainWindow::meshlab()
{
        QProcess process;
        process.start("meshlab", QStringList() << ui->lineEditOFF->text() + ".OFF");
        process.waitForFinished();
}

void MainWindow::on_actionCriar_arquivo_OFF_triggered()
{
    ui->widget->Off(ui->lineEditOFF->text());
}



