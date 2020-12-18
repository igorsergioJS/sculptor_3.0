#ifndef COLORDRAW_H
#define COLORDRAW_H

#include <QWidget>
/**
 * @brief A classe ColorDraw é responsável pela amostra de cores no canto inferior esquerdo da janela;
 */
class ColorDraw : public QWidget
{
    Q_OBJECT
private:
    /**
     * @brief r armazena o valor de r para amostagem;
     */
    int r;
    /**
     * @brief g armazena o valor de g para amostagem;
     */
    int g;
    /**
     * @brief b armazena o valor de b para amostagem;
     */
    int b;
public:
    explicit ColorDraw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    /// Altera o valor de r para o valor escolhido pelo usuário;
    void set_r(int _r);
    /// Altera o valor de g para o valor escolhido pelo usuário;
    void set_g(int _g);
    /// Altera o valor de b para o valor escolhido pelo usuário;
    void set_b(int _b);
};

#endif // COLORDRAW_H
