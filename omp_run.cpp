#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include "iomanip"
#include "omp.h"
using namespace std;

const int x=500000001;

int main(){
	omp_set_num_threads(8);
  // initialization
  double *arr;
  
  arr=new double[x];


  // main loop
#pragma omp parallel for
  for(int i=0; i<x; i++)
    arr[i]=pow(i,1./3.);	


  cout << "The last element of the array is " << arr[x-1] << endl << endl;
  
  // freeing memories
  delete(arr);
  
  return 0;
}

