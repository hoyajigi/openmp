//
//  main.c
//  HelloC
//
//  Created by Cho Hyunseok on 2014. 8. 30..
//  Copyright (c) 2014년 hoyajigi. All rights reserved.
//
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

static long num_steps=100000000; double step;

int main(int argc, const char * argv[])
{
    int i;
    double x,pi,sum=0.0;
   
    printf("OpenMP Spec %d\n",_OPENMP);

    step=1.0/(double)num_steps;
    for(i=0;i<=num_steps;i++){ 
         x=(i+0.5)*step;
         sum=sum+4.0/(1.0+x*x); 
    }
    pi=step*sum;
    return 0;
}

