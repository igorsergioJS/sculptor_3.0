# sculptor_3.0
Terceira versão do projeto escultor que utiliza voxels para criar figuras tridimencionais, agora utilizando uma interface com base em programação em Qt.

# Integrantes:

Igor Sérgio de França Correia;

Thiago Theiry de Oliveira;


# Interface:

![interface](https://user-images.githubusercontent.com/64499865/102566575-97392280-40be-11eb-8047-31fd062f9ec1.png)

A interface vem com algumas predefinições :
Dimensões 10x10x10;
Plano de visualização em XY;
Método de desenho setado em PutVoxel;
Raios e dimensões zerados;
Canais RGB zerados (Black) e transparência máxima;

# Dimensões:

Para alterar as dimensões e modificar o campo de desenho, altere o valor das dimensões pelo sliders ou pelo spin box e depois, clicar em "Definir dimensões";

![image](https://user-images.githubusercontent.com/64499865/102569184-bdad8c80-40c3-11eb-803e-810efc6b6936.png)

# Raios e dimensões:

Para alterar os valores dos raios (da esfera e elipsoide) e as dimensões da caixa, basta utilizar os sliders ou os spin boxes;

![image](https://user-images.githubusercontent.com/64499865/102569788-e2563400-40c4-11eb-8dab-fe8c60e1ff63.png)


# Visualização dos planos e escolha da forma de desenho:

A visualização dos planos pode ser alterada clicando nos radio buttons correspondentes a cada plano;
Os métodos de desenho "cut" e "put" podem ser alterados clicando nos respectivos botões de cada função;

![image](https://user-images.githubusercontent.com/64499865/102570233-ad96ac80-40c5-11eb-9dbf-ec4bbfeffcbb.png)


# Cor e transparência:

Os valores dos canais RGBA podem ser alterados utilizando os sliders e spin boxes e uma amostra da cor escolhida é apresentada em um widged abaixo dos sliders;

![image](https://user-images.githubusercontent.com/64499865/102570510-43323c00-40c6-11eb-98b0-468235a183f7.png)


# Campo de desenho e mudança de planos:

Para desenhar no campo, basta escolher uma forma de desenho, escolher uma cor e clicar nos quadrados que deseja preencher. Pode ser clicando quadrado por quadrado ou segurando o botão e arrastando o mouse;

![image](https://user-images.githubusercontent.com/64499865/102571002-51348c80-40c7-11eb-8adf-8f362c2ba401.png)


# Nomeando, salvando e visualizando:

Após terminar a escultura, você deve escolher um nome para o arquivo no campo adequado "Nome do arquivo:";
Para salvar, basta clicar em "arquivo", no canto superior esquerdo, em seguida, "Criar arquivo .OFF" e aguardar a mensagem de confirmação que seu arquivo foi criado com sucesso. <b>Não há necessidade de colocar a terminação ".OFF"</b>;
Para visualizar a figura salva, basta clicar no botão "Geomview"/"Meshlab" (Apenas para distribuições Linux);

![image](https://user-images.githubusercontent.com/64499865/102571465-4e866700-40c8-11eb-9199-393081b45833.png)
![image](https://user-images.githubusercontent.com/64499865/102571503-66f68180-40c8-11eb-9469-7165920ac6b9.png)
![image](https://user-images.githubusercontent.com/64499865/102571597-9efdc480-40c8-11eb-860c-275de181641b.png)
![image](https://user-images.githubusercontent.com/64499865/102571550-842b5000-40c8-11eb-9fbd-9a2637f8fed7.png)


