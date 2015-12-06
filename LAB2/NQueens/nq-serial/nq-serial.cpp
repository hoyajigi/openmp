/*
 * Copyright (C) 2009 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all
 * documents related to the source code ("Material") are owned by
 * Intel Corporation or its suppliers or licensors. Title to the
 * Material remains with Intel Corporation or its suppliers and
 * licensors. The Material is protected by worldwide copyright
 * laws and treaty provisions.  No part of the Material may be
 * used, copied, reproduced, modified, published, uploaded,
 * posted, transmitted, distributed,  or disclosed in any way
 * except as expressly provided in the license provided with the
 * Materials.  No license under any patent, copyright, trade
 * secret or other intellectual property right is granted to or
 * conferred upon you by disclosure or delivery of the Materials,
 * either expressly, by implication, inducement, estoppel or
 * otherwise, except as expressly provided in the license
 * provided with the Materials 
*/
// [DESCRIPTION]
// 
// Solve the nqueens problem -base version
//
// [COMPILE]  
// Compile on IA-32 and Intel(R) 64 architectures only. 
// Use the following compiler options to compile: 
//
// CommandLine: icl nq-serial.cpp winmm.lib
//
// [RUN]
//
// From the command line:
//
//      nq-serial.exe boardSize
//
// where boardSize is the size of the board, in the range 4-20
//
// To set the board size in Visual Studio, right click on the project,
// select Properies > Configuration Properties > General > Debugging.  Set
// Command Arguments to the desired value.  8 has been provided as a default.
// 
// [EXPECTED OUTPUT]
//
// Board Size   Number of Solutions
//     4                2
//     5               10
//     6                4
//     7               40
//     8               92
//     9              352
//    10              724
//    11             2680
//    12            14200
//    13            73712
//    14           365596
//    15          2279184

#include <iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int nrOfSolutions=0;
int size=0;

void print(int queens[]) {
  cerr << "Solution " << nrOfSolutions << endl; 
  for(int row=0; row<size; row++) {
    for(int col=0; col<size; col++) {
      if(queens[row]==col) {
        cout << "Q";
      }
      else {
        cout << "-";
      }
    }
    cout << endl;
  }
}

void setQueen(int queens[], int row, int col) {
  for(int i=0; i<row; i++) {
    // vertical attacks
    if (queens[i]==col) {
      return;
    }
    // diagonal attacks
    if (abs(queens[i]-col) == (row-i) ) {
      return;
    }
  }

  // column is ok, set the queen
  queens[row]=col;

  if(row==size-1) {
    nrOfSolutions++;

  }
  else {
    // try to fill next row
    for(int i=0; i<size; i++) {
      setQueen(queens, row+1, i);
    }
  }
}


void solve(int queens[]) {
  for(int i=0; i<size; i++) {
    // try all positions in first row
    // create separate array for each recursion

    setQueen(queens, 0, i);
  }
}


int main(int argc, char*argv[]) {
  if(argc !=2) {
    cerr << "Usage: nq-serial boardSize [default is 12].\n";
    size = 14;
  } else {
    size = atoi(argv[1]);
  }

  cout << "Starting serial recursive solver for size " << size << "...\n";
  DWORD startTime=timeGetTime();
  solve(new int[size]);
  DWORD endTime=timeGetTime();
  cout << "Number of solutions: " << nrOfSolutions << endl;
  cout << "Calculations took " << endTime-startTime << "ms.\n";

  return 0;
}