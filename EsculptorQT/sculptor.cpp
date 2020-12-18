#include <iostream>
#include <iomanip>
#include "sculptor.h"
#include "mainwindow.h"
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;
    if(nx <= 0 || ny <= 0 || nz <= 0){
           nx = ny = nz = 0;
       }
       v = new Voxel**[nx];
       if(v == nullptr){
           exit(0);
       }
       v[0] = new Voxel*[nx*ny];
       if(v[0] == nullptr){
           exit(0);
       }
       v[0][0] = new Voxel[nx*ny*nz];
       if(v[0][0] == nullptr){
           exit(0);
       }

       for(int i=0; i< nx; i++)
       {
           if (i<(nx-1))
           {
               v[i+1] = v[i]+ny;
           }
           for(int j=1; j< ny; j++)
           {
               v[i][j] = v[i][j-1]+nz;
               if(j==ny-1 && i!=(nx-1))
               {
                   v[i+1][0] = v[i][j]+nz;
               }
           }
       }
       for(int i = 0; i < nx; i++){
           for(int j = 0; j < ny; j++){
               for(int k = 0; k < nz; k++){
                   v[i][j][k].isOn = false;
               }
           }
       }
}

vector<vector<Voxel>> Sculptor::readMx(int dim, int pl){
    vector<vector<Voxel>> m;
    vector<Voxel> l;
    if (pl == XY){
        l.resize(ny);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                l[j].isOn = v[i][j][dim].isOn;
                l[j].r = v[i][j][dim].r;
                l[j].g = v[i][j][dim].g;
                l[j].b = v[i][j][dim].b;
                l[j].a = v[i][j][dim].a;
            }
            m.push_back(l);
        }
    }
    if (pl == YZ){
        l.resize(nz);
        for(int i = 0; i<ny; i++){
            for(int j = 0; j<nz; j++){
                l[j].isOn = v[dim][i][j].isOn;
                l[j].r = v[dim][i][j].r;
                l[j].g = v[dim][i][j].g;
                l[j].b = v[dim][i][j].b;
                l[j].a = v[dim][i][j].a;
            }
            m.push_back(l);
        }
    }

    if (pl == ZX){
        l.resize(nx);
        for(int i = 0; i<nz; i++){
            for(int j = 0; j<nx; j++){
                l[j].isOn = v[j][dim][i].isOn;
                l[j].r = v[j][dim][i].r;
                l[j].g = v[j][dim][i].g;
                l[j].b = v[j][dim][i].b;
                l[j].a = v[j][dim][i].a;
            }
            m.push_back(l);
        }
    }
    l.clear();
    return m;
}

Sculptor::~Sculptor()
{
    // Liberação da memória alocada;
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha)
{
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    if(r>=0 && r<=255)
    v[x][y][z].r = r;
     if(g>=0 && g<=255)
    v[x][y][z].g = g;
      if(b>=0 && b<=255)
    v[x][y][z].b= b;
    v[x][y][z].a = a;

}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<x1;i++)
        {
            for(int j=y0;j<y1;j++)
            {
                for(int k=z0;k<z1;k++)
                {
                    putVoxel(i,j,k);
                }
            }
        }
}


void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<x1;i++)
        {
            for(int j=y0;j<y1;j++)
            {
                for(int k=z0;k<z1;k++)
                {
                    cutVoxel(i,j,k);
                }
            }
        }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter-radius; i<=xcenter+radius; i++)
        {
            for(int j = ycenter-radius; j<=ycenter+radius; j++)
            {
                for(int k = zcenter-radius; k<=zcenter+radius; k++)
                {
                    if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2))
                    {
                        putVoxel(i,j,k);
                    }
                }
            }
        }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter-radius; i<=xcenter+radius; i++)
        {
            for(int j = ycenter-radius; j<=ycenter+radius; j++)
            {
                for(int k = zcenter-radius; k<=zcenter+radius; k++)
                {
                    if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2))
                    {
                        cutVoxel(i,j,k);
                    }
                }
            }
        }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++)
        {
            for(int j = ycenter-ry; j<=ycenter+ry; j++)
            {
                for(int k = zcenter-rz; k<=zcenter+rz; k++)
                {
                        if(((pow((i-xcenter),2)/pow(rx,2))+(pow((j-ycenter),2)/pow(ry,2))+(pow((k-zcenter),2)/pow(rz,2)))<=1.0)
                        {
                            putVoxel(i,j,k);
                        }
                }
            }
        }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++)
        {
            for(int j = ycenter-ry; j<=ycenter+ry; j++)
            {
                for(int k = zcenter-rz; k<=zcenter+rz; k++)
                {
                        if(((pow((i-xcenter),2)/pow(rx,2))+(pow((j-ycenter),2)/pow(ry,2))+(pow((k-zcenter),2)/pow(rz,2)))<=1.0)
                        {
                            cutVoxel(i,j,k);
                        }
                }
            }
        }
}

void Sculptor::writeOFF(string filename)
{

    int aux = 0;
    int Nface = 0;
    int Nvert = 0;

    ofstream arq;
    arq.open(filename);


    for(int i=0;i<nx;i++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int k=0;k<nz;k++)
            {
                if(v[i][j][k].isOn && v[i][j][k].r>=0 && v[i][j][k].r<=255 && v[i][j][k].g>=0 && v[i][j][k].g<=255 && v[i][j][k].b>=0 && v[i][j][k].b<=255)
                {
                    Nvert = Nvert+8;
                    Nface = Nface+6;

                }
            }
        }
    }


    arq << "OFF" << endl; //Primeira linha do arquivo (obrigatória)
    arq << Nvert << " " << Nface << " " << 0 << endl;

    // Laço para atribuir os devidos valores dos vértices de cada voxel no arquivo
    for(int i=0;i<nx;i++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int k=0;k<nz;k++)
            {
                if(v[i][j][k].isOn && v[i][j][k].r>=0 && v[i][j][k].r<=255 && v[i][j][k].g>=0 && v[i][j][k].g<=255 && v[i][j][k].b>=0 && v[i][j][k].b<=255)
                {
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    arq<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                    arq<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    arq<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    arq<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }
    }

    // Laço para atribuir o devido ordenamento das faces de cada voxel no arquivo;
    for(int i=0;i<nx;i++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int k=0;k<nz;k++)
            {
                if(v[i][j][k].isOn && v[i][j][k].r>=0 && v[i][j][k].r<=255 && v[i][j][k].g>=0 && v[i][j][k].g<=255 && v[i][j][k].b>=0 && v[i][j][k].b<=255)
                {
                   arq << 4 << " " << aux+0 << " " << aux+3 << " " << aux+2 << " " << aux+1 << " " << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl;
                   arq << 4 << " " << aux+4 << " " << aux+5 << " " << aux+6 << " " << aux+7 << " " << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl;
                   arq << 4 << " " << aux+0 << " " << aux+1 << " " << aux+5 << " " << aux+4 << " " << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl;
                   arq << 4 << " " << aux+0 << " " << aux+4 << " " << aux+7 << " " << aux+3 << " " << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl;
                   arq << 4 << " " << aux+3 << " " << aux+7 << " " << aux+6 << " " << aux+2 << " " << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl;
                   arq << 4 << " " << aux+1 << " " << aux+2 << " " << aux+6 << " " << aux+5 << " " << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl;

                   aux = aux + 8;
                }
            }
        }
    }

    // Verifica se o arquivo é gerado. Quando não aparece mensagem alguma, provavelmente houve alguma falha na alocação;
    if(arq.is_open())
        {
            cout << "arquivo OFF salvo com sucesso ! "<<endl;
        }
    else
    {
        cout << "Erro ao salvar o arquivo" << endl;
    }

}


