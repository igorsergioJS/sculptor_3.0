#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QString>
#include "sculptor.h"
#include "vector"
#include <iostream>
#include<cstring>

/**
 * @brief A classe Plotter está relacionada a criação e constante alteração do compo de desenho;
 */
class Plotter : public QWidget
{
    Q_OBJECT
private:


public:

    explicit Plotter(QWidget *parent = nullptr);
    /**
     * @brief paintEvent é um evento que desenha uma matriz de cubos e os liga por barras;
     */

        void paintEvent(QPaintEvent *event);
        /**
         * @brief mousePressEvent é um evento que ativa a propriedade isOn de um voxel a partir de um clique do mouse;
         */
        void mousePressEvent(QMouseEvent *event);
        /**
         * @brief mouseReleaseEvent é um evento que realiza ações necessárias (deixa de atribuir a propriedade isOn para os voxels) após o botão esquerdo do mouse ser solto;
         */
        void mouseReleaseEvent(QMouseEvent *event);
        /**
         * @brief mouseMoveEvent é um evento que realiza ações quando o mouse se movimenta e está com o botão esquerdo pressionado;
         */
        void mouseMoveEvent(QMouseEvent *event);
        /**
         * @brief shape determina qual forma geométrica será utilizada, seja ela de propriedade "cut" ou "put". Existem 8 formas ao total;
         * @param sh armazena a forma geométrica escolhida pelo usuário;
         */
        void shape(int sh);
        /**
         * @brief s é o Sculptor chamado pela primeira vez quando o programa é aberto;
         */
        Sculptor *s;
        /**
         * @brief sh é a forma de desenho escolhida pelo usuário. PutVoxel está definida como padrão;
         */
        int sh = 1;
        /**
         * @brief dim é a dimensão delecionada pelo usuário;
         */
        int dim;
        /**
         * @brief pl é o plano selecionado pelo usuário;
         */
        int pl;
        /**
         * @brief Tamanho em x do escultor;
         */
        int sx;
        /**
         * @brief Tamanho em y do escultor;
         */
        int sy;
        /**
         * @brief Tamanho em z do escultor;
         */
        int sz;
        /**
         * @brief r armazena o valor do canal r(red);
         */
        int r;
        /**
         * @brief g armazena o valor do canal g(green);
         */
        int g;
        /**
         * @brief b armazena o valor do canal b(blue);
         */
        int b;
        /**
         * @brief a aramazena o valor da transparência;
         */
        int a;
        /**
         * @brief rad armazena o raio da esfera
         */
        int rad;
        /**
         * @brief rx armazena o raio em x da elipsoide;
         */
        int rx;
        /**
         * @brief ry armazena o raio em y da elipsoide;
         */
        int ry;
        /**
         * @brief rz armazena o raio em y da elipsoide;
         */
        int rz;
        /**
         * @brief x armazena as dimensões em x da caixa;
         */
        int x;
        /**
         * @brief y armazena as dimensões em y da caixa;
         */
        int y;
        /**
         * @brief z armazena as dimensões em z da caixa;
         */
        int z;
        /**
         * @brief h armazena a altura dos quadrados em branco;
         */
        int h;
        /**
         * @brief w armazena a largura dos quadrados em branco;
         */
        int w;
    private:
        vector<vector<Voxel>> p;
        QColor lineColor;
        int cor;
        QAction *actionMudaCor;
        int cube;
        int square;
        ///Position of the click.
        int px, py, pz;
        ///Mouse is clicked = true.
        bool press;
        ///Mouse coordinates.
        int mx, my;
    signals:
        /**
         * @brief Armazena as posições do mouse em X;
         */
        void moveX(int);
        /**
         * @brief Armazena as posições do mouse em Y;
         */
        void moveY(int);
        /**
         * @brief Armazena as posições em X que houve click;
         */
        void clickX(int);
        /**
         * @brief Armazena as posições em Y que houve click;
         */
        void clickY(int);
        /**
         * @brief planeChosen Armazena o plano escolhido;
         */
        void planeChosen(int);
    public slots:
        /**
         * @brief changeDimx modifica a dimensão em x;
         * @param size armazena o valor da dimensão x escolhida pelo usuário;
         */
        void changeDimx(int size);
        /**
         * @brief changeDimy modifica a dimensão em y;
         * @param size armazena o valor da dimensão y escolhida pelo usuário;
         */
        void changeDimy(int size);
        /**
         * @brief changeDimz modifica a dimensão em z;
         * @param size armazena o valor da dimensão z escolhida pelo usuário;
         */
        void changeDimz(int size);
        /**
         * @brief changeRad modifica o raio da esfera;
         * @param rd armazena o valor do raio da esfera escolhido pelo usuário;
         */
        void changeRad(int rd);
        /**
         * @brief changeRx modifica o raio em x da elipsoide;
         * @param radx armazena o raio em x da elipsoide escolhido pelo usuário;
         */
        void changeRx(int radx);
        /**
         * @brief changeRy modifica o raio em y da elipsoide;
         * @param rady armazena o raio em y da elipsoide escolhido pelo usuário;
         */
        void changeRy(int rady);
        /**
         * @brief changeRz modifica o raio em z da elipsoide;
         * @param radz armazena o raio em z da elipsoide escolhido pelo usuário;
         */
        void changeRz(int radz);
        /**
         * @brief changeRed modifica o canal r(red) do voxel;
         * @param red armazena o valor do canal r escolhido pelo usuário;
         */
        void changeRed(int red);
        /**
         * @brief changeGreen modifica o canal g(green) do voxel;
         * @param green armazena o valor do canal g escolhido pelo usuário;
         */

        void changeGreen(int green);
        /**
         * @brief changeBlue modifica o canal b(blue) do voxel;
         * @param blue armazena o valor do canal b escolhido pelo usuário;
         */
        void changeBlue(int blue);
        /**
         * @brief changeAlpha modifica o valor da transparência do voxel;
         * @param alpha aramzena o valor da transparência escolhido pelo usuário;
         */
        void changeAlpha(int alpha);
        /**
         * @brief changeSlice modifica qual camada do plano está sendo visualizada;
         * @param pln armazena o valor do plano escolhido pelo usuário;
         */
        void changeSlice(int pln);
        /**
         * @brief Off é responsável por fazer a chamada da funcão writeOFF presente no Sculptor e atribuir um nome ao arquivo OFF;
         * @param s é a string que armazena o nome escolhido para o arquivo pelo usuário;
         */
        void Off(QString s);


public slots:

signals:

};

#endif // PLOTTER_H
