// 행렬합 예제

#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include "iomanip"
#include "omp.h"
using namespace std;

const int x=10000,y=10000,num_of_threads=10;

void arr_print(double**);

int main(){
  // initialization
  int i,j;
  double **pot;

  pot=new double*[x];
  for(i=0; i<x; i++){
    pot[i]=new double[y];	}
#pragma omp parallel for private(j)
  for(i=0; i<x; i++){
    for(j=0; j<y; j++){
      pot[i][j]=sin(cos(i))+cos(sin(j));	}}


  // main loop
  double summed=0;
 omp_set_num_threads(8);
  for(i=0; i<x; i++){
    for(j=0; j<y; j++){
     if((i+j)%2==1) summed+=pot[i][j];	}}
  
//  arr_print(pot);
  cout << "The sum of all elements of {pot} is " << setprecision(15) << summed << endl; 

  // freeing memories
  for(i=0; i<x; i++){
    delete(pot[i]);	}
  delete(pot);
  
  return 0;
  }

void arr_print(double **a){
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      cout << a[i][j] << " ";  }
    cout << endl;      }
}
