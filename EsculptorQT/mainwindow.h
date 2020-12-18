#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector"
#include "sculptor.h"
#include "plotter.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 * @brief A classe MainWindow é responsável por realizar várias funções relativas a mudanças de variáveis pelo usuário por meio da interface;
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    ///Realiza várias ações ao redimensionar o sculptor;
    void selectPlane();
    ///Finaliza o programa;
    void sair();
    ///Ativa o plano XY como plano visível;
    void changeXY();
    ///Ativa o plano XZ como plano visível;
    void changeYZ();
    ///Ativa o plano ZX como plano visível;
    void changeZX();
    ///Ativa a função PutVoxel. Chamado quando o botão é pressionado;
    void pVoxel();
    ///Ativa a função CutVoxel. Chamado quando o botão é pressionado;
    void cVoxel();
    ///Ativa a função PutBox. Chamado quando o botão é pressionado;
    void pBox();
    ///Ativa a função CutBox. Chamado quando o botão é pressionado;
    void cBox();
    ///Ativa a função PutSphere. Chamado quando o botão é pressionado;
    void pShpere();
    ///Ativa a função CutSphere. Chamado quando o botão é pressionado;
    void cShpere();
    ///Ativa a função PutEllipsoid. Chamado quando o botão é pressionado;
    void pEllip();
    ///Ativa a função CutEllipsoid. Chamado quando o botão é pressionado;
    void cEllip();
    ///Abre o arquivo gravado com o geomview quando o botão é pressionado;
    void geomview();
    ///Abre o arquivo gravado com o geomview quando o botão é pressionado;
    void meshlab();
    /// Cria o arquivo OFF quando o botão é engatilhado;
    void on_actionCriar_arquivo_OFF_triggered();
private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};
#endif // MAINWINDOW_H
