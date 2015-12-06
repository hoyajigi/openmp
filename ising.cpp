// 100*100 몬테카를로

#include<cstdio>
#define _USE_MATH_DEFINES
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<cstdlib> 

const int nx=100, ny=100, num_stages=10, iter=10000000;
using namespace std;
#include"fns.h"

int main(){

  // initialization
  int i, j;
  double KT = 16;	
  int Mij[nx][ny];
  double local_e[nx][ny]={0};
  double KTset[num_stages + 1]={0};
  bc bcs;
  bcs.x=0;bcs.y=0;bcs.l=0;bcs.r=0;bcs.d=0;bcs.u=0;
  
  srand(time(NULL));
  
  int m;
  for(i = 0;  i < nx; i++){
    for(j = 0; j < ny; j++){
      m = 2 * (int)(rand()%2) - 1;         
      Mij[i][j] = m;    }}	// 초기값 행렬 원소를 난수로 입력.

  cout<< endl << "Entering the Monte Carlo simulation." << endl;

  // MC_MonteCarlo initialization
  local_energy(bcs, Mij, local_e);
  double total_E=sum(local_e), delta_E=0;
  int ran_i,ran_j;
  double MC_KT=KT;
  cout<<"Random total E = " << total_E << endl << endl;

  // MonteCarlo loop
  srand(time(NULL));
  int stage = 0;

  for(int g=0; g!=num_stages+1; g++){
    cout << "stage " << stage + 1 <<" : Monte Carlo simulation at KT = " << MC_KT << endl;

    KTset[stage]=MC_KT;
    // main loop
    for(int h=0; h<iter; h++){	
      ran_i=(int)(rand()%nx);
      ran_j=(int)(rand()%ny);

      Mij[ran_i][ran_j]=-Mij[ran_i][ran_j];
      delta_E+=flip(ran_i, ran_j, bcs, MC_KT, Mij);
    }

    MC_KT=MC_KT - (KT/num_stages) + 0.0000000001;
    stage=stage + 1;
    cout << " End of the stage "<< stage << ". Total energy is " << total_E+delta_E << endl << endl;
  }
  
  return 0;

}
