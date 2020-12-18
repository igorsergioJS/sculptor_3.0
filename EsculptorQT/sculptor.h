#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <iostream>
#include "vector"
using namespace std;

/**
 * @brief O struct Voxel é responsável por definir as variáveis onde os valores dos canais RGB,
 * a transparência(alpha) de cada Voxel criado, além da utilização de um booleano para identificar se
 * determinado voxel será incluído ou não na visualização.
 *
 */
enum{XY,YZ,ZX};
/**
 * @brief O struct Voxel armazena os valores relacionados a cores e propriedades dos voxels;
 */
struct Voxel {
    /**
   * @brief r armazena o valor do canal r(vermelho) para voxel selecionado. Varia no intervalo [0,1];
   */
  float r;
  /**
   * @brief g armazena o valor do canal g(verde) para voxel selecionado. Varia no intervalo [0,1];
   */
  float g;
  /**
   * @brief b armazena o valor do canal b(azul) para voxel selecionado. Varia no intervalo [0,1];
   */
  float b; // Colors
  /**
   * @brief a armazena o valor da transparência para voxel selecionado. Varia no intervalo [0,1];
   */
  float a;
// Transparency
  /**
   * @brief isOn aramazena um valor lógico em relação ao voxel selecionado. Varia entre true e false;
   */
  bool isOn; // Included or not


};

/**
 * @brief A classe escultor apresenta variáveis privadas e funções públicas.
 * @details As variáveis privadas acessadas apenas por membros da mesma classe e as funções públicas
 * podem ser acessadas fora do objeto, onde este estiver definido.
 */
class Sculptor {
protected:
    /**
   * @brief v é um ponteiro para um ponteiro para um ponteiro auxilia na alocação dinâmica
   * de memória da matriz 3D, onde os voxels ficam "armazenados".
   */
  Voxel ***v;
  // 3D matrix
  /**
   * @brief nx armazena a dimensão em x da matriz 3D;
   */
  int nx;
  /**
   * @brief ny armazena a dimensão em y da matriz 3D;
   */
  int ny;
  /**
   * @brief nz armazena a dimensão em z da matriz 3D;
   */
  // Dimensions
  int nz;
  /**
   * @brief r armazena o valor de r para ser usado dentro da classe;
   */
  float r;
  /**
   * @brief g armazena o valor de g para ser usado dentro da classe;
   */
  float g;
  /**
   * @brief b armazena o valor de b para ser usado dentro da classe;
   */
  float b;
  // Current drawing color
  /**
   * @brief a armazena o valor da transparência para ser usado dentro da classe;
   */
  float a;
public:
  /**
   * @brief Sculptor é o construtor da classe responsável por receber as dimensões (x,y,z)
   * e pela alocação dinâmica de memória para a matriz 3D.
   *
   * @param _nx armazena a dimensão em x;
   * @param _ny armazena a dimensão em y;
   * @param _nz armazena a dimensão em z;
   */
  Sculptor(int _nx, int _ny, int _nz);
  //!
  /*!
    @brief ~Sculptor é o destrutor da classe responsável pela liberação da memória ao fim da execução do programa.
  */
  ~Sculptor();
  /**
   * @brief setColor é uma função que atribui valores aos parâmetros que representam os canais RGB e sua transparência.
   * @param _r recebe o valor decimal no intervalo [1,0] para o canal r;
   * @param _g recebe o valor decimal no intervalo [1,0] para o canal g;
   * @param _b recebe o valor decimal no intervalo [1,0] para o canal b;
   * @param alpha recebe o valor decimal no intervalo [1,0] para a transparência;
   */

  void setColor(float _r, float _g, float _b, float alpha);


  /**
   * @brief putVoxel atribui a um elemento da matriz 3D as variáveis presentes no struct Voxel
   * tornando o voxel selecionado visível e ativo.
   * @details
   * @param x recebe a coordenada x onde o voxel deve estar posicionado;
   * @param y recebe a coordenada y onde o voxel deve estar posicionado;
   * @param z recebe a coordenada z onde o voxel deve estar posicionado;
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief cutVoxel atribui a um elemento da matriz 3D a variável presente no struct Voxel isOn como false.
   *
   * @param x recebe a coordenada x onde o voxel deve estar desativado;
   * @param y recebe a coordenada y onde o voxel deve estar desativado;
   * @param z recebe a coordenada z onde o voxel deve estar desativado;
   */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief putBox realiza uma ou várias chamadas da função putVoxel para formar uma caixa com dimensões definidas pelos parâmetros da função putBox.
   * @param x0 armazena a coordenada inicial da caixa no eixo x;
   * @param x1 armazena a coordenada final da caixa no eixo x;
   * @param y0 armazena a coordenada inicial da caixa no eixo y;
   * @param y1 armazena a coordenada final da caixa no eixo y;
   * @param z0 armazena a coordenada inicial da caixa no eixo z;
   * @param z1 armazena a coordenada final da caixa no eixo z;
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief cutBox realiza uma ou várias chamadas da função cutVoxel para desativar o(s) voxel(s) presentes dentro de uma caixa com dimensões definidas pelos parâmetros da função cutBox.
   * @param x0 armazena a coordenada inicial da caixa no eixo x;
   * @param x1 armazena a coordenada final da caixa no eixo x;
   * @param y0 armazena a coordenada inicial da caixa no eixo y;
   * @param y1 armazena a coordenada final da caixa no eixo y;
   * @param z0 armazena a coordenada inicial da caixa no eixo z;
   * @param z1 armazena a coordenada final da caixa no eixo z;
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief putSphere realiza uma ou várias chamadas da função putVoxel para formar uma esfera com raio e coordenadas de centro definidas na chamada.
   * @param xcenter armazena a coordenada no eixo x onde a esfera deve estar centrada;
   * @param ycenter armazena a coordenada no eixo y onde a esfera deve estar centrada;
   * @param zcenter armazena a coordenada no eixo z onde a esfera deve estar centrada;
   * @param radius armazena comprimento(em voxels) do raio da esfera;
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief cutSphere realiza uma ou várias chamadas da função cutVoxel para desativar o(s) voxel(s) presentes dentro de uma esfera com raio e coordenadas de centro definidas na chamada.
   * @param xcenter armazena a coordenada no eixo x onde a esfera deve estar centrada;
   * @param ycenter armazena a coordenada no eixo y onde a esfera deve estar centrada;
   * @param zcenter armazena a coordenada no eixo z onde a esfera deve estar centrada;
   * @param radius armazena comprimento(em voxels) do raio da esfera;
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief putEllipsoid realiza uma ou várias chamadas da função putVoxel para formar uma elipsóide com raios e coordenadas de centro definidas na chamada.
   * @param xcenter armazena a coordenada no eixo x onde a elipsóide deve estar centrada;
   * @param ycenter armazena a coordenada no eixo y onde a elipsóide deve estar centrada;
   * @param zcenter armazena a coordenada no eixo z onde a elipsóide deve estar centrada;
   * @param rx armazena comprimento(em voxels) do raio da elipsóide em relação ao eixo x;
   * @param ry armazena comprimento(em voxels) do raio da elipsóide em relação ao eixo y;
   * @param rz armazena comprimento(em voxels) do raio da elipsóide em relação ao eixo z;
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief cutEllipsoid realiza uma ou várias chamadas da função cutVoxel para desativar o(s) voxel(s) presentes dentro de uma elipsóide com raios e coordenadas de centro definidas na chamada.
   * @param xcenter armazena a coordenada no eixo x onde a elipsóide deve estar centrada;
   * @param ycenter armazena a coordenada no eixo y onde a elipsóide deve estar centrada;
   * @param zcenter armazena a coordenada no eixo z onde a elipsóide deve estar centrada;
   * @param rx armazena comprimento(em voxels) do raio da elipsóide em relação ao eixo x;
   * @param ry armazena comprimento(em voxels) do raio da elipsóide em relação ao eixo y;
   * @param rz armazena comprimento(em voxels) do raio da elipsóide em relação ao eixo z;
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief writeOFF é responsável pela criação de um arquivo OFF da figura criada pelos métodos da classe
   *  possibilitando a visualização em um software gráfico.
   * @param filename armazena o nome escolhido para o arquivo a ser criado;
   * @details A criação do arquivo segue os padrões apresentados para um arquivo OFF padrão, contendo:
   * - "OFF" na primeira linha do arquivo de texto;
   * - Número de vértices e faces;
   * - Coordenadas dos vértices e faces;
   */
  void writeOFF(string filename);
  /**
   * @brief readMx é uma função que auxilia a interação e visão de diferentes planos 2D;
   * @param dim remete a que coordenada do plano que está sendo visualizado;
   * @param pl remete ao plano que será visualizado;
   */
  vector<vector<Voxel>> readMx(int dim=0, int pl = XY);
};

#endif // SCULPTOR_H
