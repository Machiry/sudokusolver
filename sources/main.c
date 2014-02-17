/* 
 * File:   main.c
 * Author: machiry
 *
 * Created on February 16, 2014, 6:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> 
#include "sudoku.h"
#define MAX_ROUNDS 81

/*
 * 
 */
int main(int argc, char** argv) {
    int i=0,j=0,currVal,maxRounds = MAX_ROUNDS;
    double elapsedTime;
    struct timeval t1, t2;
    initialize();
    printf("Expected to read 81 numbers.\nEach corresponding to 81 cells of the SUDOKU grid. Entered in row majoring order.\nA missing value in a cell is indicated with 0.\n");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&currVal);
            /*if(i==2 && j == 1){
                printf("Git\n");
            }*/
            if(currVal){
                if(currVal > 9 || currVal < 0){
                    printf("\nInvalid number:%d, Valid numbers: 0-9\n",currVal);
                    return EXIT_FAILURE;
                }
                updateInitialValue(i,j,currVal);
            }
        }
    }
    gettimeofday(&t1, NULL);
    while(maxRounds){
        if(!evaluvate()){
            break;
        }
        /*printf("\nResult Matrix:\n");
        dumpResultMatrix();*/
        maxRounds--;
    }
    gettimeofday(&t2, NULL);
    if(verify()){
        printf("\nSolved Successfully\n");
    }
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("\n Result:\n");
    printf("Number of rounds:%d, Elapsed Time:%lf sec (%lf msec)\n",MAX_ROUNDS-maxRounds,elapsedTime,elapsedTime/1000);
    printf("\nResult Matrix:");
    dumpResultMatrix();
    return (EXIT_SUCCESS);
}

