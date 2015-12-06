// 10*10 퍼텐셜

#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include "iomanip"
#include "omp.h"
using namespace std;

const int x=1000,y=1000;

double sum(double**);			// summing all elements of array
void arr_print(double**);		// print the array


int main(){

  // initialization
  int iter=0,i,j;
  double **pot,comp_a,comp_b;

  pot=new double*[x];
  for(i=0; i<x; i++){
    pot[i]=new double[y];	}
  
  for(i=0; i<x; i++){
    for(j=0; j<y; j++){
      pot[i][j]=0;	}}

  for(j=0; j<y;j++){
    pot[0][j]=100;	}

  comp_a=0;
  comp_b=1;
  // main loop
  while(abs(comp_a-comp_b)>0.001){
#pragma omp parallel for private(j)
    for(i=1; i<x-1; i++){
      for(j=1;j<y-1; j++){
	pot[i][j]=(pot[i-1][j]+pot[i+1][j]+pot[i][j-1]+pot[i][j+1])/4.;	}}

    comp_a=pot[1][1];
    comp_b=pot[1][y-2];
    iter+=1;
  }
  
//  arr_print(pot);
  cout << "The number of iteration is " << iter << endl;
  cout << "The sum of all elements of pot is " << setprecision(15) << sum(pot) << endl; 
  
  // freeing memories
  for(i=0; i<x; i++){
    delete(pot[i]);	}
  delete(pot);
  
  return 0;
}

  
double sum(double **a){
  double summed=0;
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      summed+=a[i][j];	}}
  
  return summed;
}

void arr_print(double **a){
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      cout << a[i][j] << " ";	}
    cout << endl;	}
}
