#include <stdio.h>
//#include <conio.h>
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

const int N = 10000, M = 10000; //размерность схемы
float L = 1.0, T = 1.0;
float h, tau, lambda, Uxk[N],Uxk1[N],a[N],b[N], t[M], u[N][M],F[N],U0[N];

float f(float x, float t);
float fi(int x);
float mu_1(float t);
float mu_2(float t);

int main(){
    a[0]=1;
    b[0]=1;
    b[N-1]=3;

    for (int j = 0; j < N ; j++)
        F[j] = j;

    for (int j = 0; j < N ; j++) //Начальные усл
        U0[j] = j*5;

    tau = T / N;
    h = L / N;
    lambda = 0.00001*tau / (h * h);  //коэф Куранта

    for (int j = 1; j < N ; j++)
        a[j] = (-lambda/2)/(lambda*a[j-1]/2-1-lambda);

   // for (int j = N-1; j > 0 ; j--)
        b[j] = (-lambda/2)/(lambda*a[j-1]/2-1-lambda);

    for (int i = 0; i <= N; i++) {x[i] = i * L / N;}
    for (int j = 0; j <= M; j++) {t[j] = j * T / M;}

    for (int i = 0; i < N ; i++){
        for (int j = 0; j < M ; j++){
            u[i][j] = 0.0;
        }
    }

    for (int j = 0; j < M; j++){
        u[0][j] = mu_1(t[j]);
    }

    for (int j = 0; j < M; j++){
        u[N-1][j] = mu_2(t[j]);
    }

    for (int i = 1; i < N-1; i++){
        u[i][0] = 5/*fi(i+1)*/;
    }

    for (int j = 0; j < M-1 ; j++){
        for (int i = 1; i < N-1; i++){
            u[i][j+1] = lambda /2 * u[i+1][j] + lambda/2 * u[i-1][j] + (1.0 - lambda) * u[i][j];
            u[i][j+1] = lambda /2 * u[i+1][j] + lambda/2 * u[i-1][j] + (1.0 - lambda) * u[i][j]; //+ tau * f(x[i], t[j]);
        }
    }

    /*  for (int j = M; j > 0; j--){
          for (int i = 0; i < N; i++){
              printf("%5.3f ", u[i][j]);
          }
          printf("\n");
      }*/

    ofstream f;
    f.open("test150519.txt");
    /*   for(int i=0; i<4; i++)    // или так
           f << m[i] << endl;*/

    /*   for (int j = 0; j < M; j++){
           for (int i = 0; i < N; i++)
               f<< u[i][j]<< endl;
               f<<endl;
       }*/
    int j=100;
    for (int i = 0; i < N; i++)
        f<< u[i][j]<< endl;
    f<<endl;

    j=2500;
    for (int i = 0; i < N; i++)
        f<< u[i][j]<< endl;
    f<<endl;

    j=5000;
    for (int i = 0; i < N; i++)
        f<< u[i][j]<< endl;
    f<<endl;

    j=7500;
    for (int i = 0; i < N; i++)
        f<< u[i][j]<< endl;
    f<<endl;

    j=9999;
    for (int i = 0; i < N; i++)
        f<< u[i][j]<< endl;
    f<<endl;


    /* for(int i=0; i<4; i++)    // или так
         f << m[i] << " ";*/

    f.close();
    return 0;

/*
    PrimitiveObject::PrimitiveObject(double *c);

    double c[]={5,4.0,1};
    PrimitiveObject o(1,2,3), o2(c);
    double *sph = o.get_spherical();
    print_array(sph,3);
    delete[]sph;
    return 0;*/

    //system("pause");
    //  friend std::ostream &operator<<(std  ::ostream &out-*

}

float f(float x, float t){
    return 20*x*t;
}

float fi(int x){
    return x;
}

float mu_1(float t){
    return 1;
}

float mu_2(float t){
    return 10;
}
