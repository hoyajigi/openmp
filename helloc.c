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

int main(int argc, const char * argv[])
{
    omp_set_num_threads(8);
    int iter;
    int NCOUNT = 100000000;
    #pragma omp parallel for
    for(iter = 0; iter < NCOUNT; iter++)
    {
        printf("OMP: Hello World, %d times\n", iter);
    }
    return 0;
}

