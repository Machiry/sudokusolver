#include "sudoku.h"
#include <string.h>
#include <stdio.h>

int currBox[9][9];
char potentialValues[9][9][9];

static int isSinglePossibleValue(int row, int col);
static void updatePossibleValue(int row, int col, int val);
static int isSinglePossibleValue2(int row, int col);
static int isThisUnique(int row, int col, int val);

void initialize() {
    memset(currBox, 0, sizeof (currBox));
    //Set all values as possible values.
    memset(potentialValues, 1, sizeof (potentialValues));
}

static int isSinglePossibleValue(int row, int col) {
    int k = 0;
    int flag = 0;
    for (k = 0; k < 9; k++) {
        if (potentialValues[row][col][k]) {
            if (!flag) {
                flag = k + 1;
            } else {
                return 0;
            }
        }
    }
    potentialValues[row][col][flag - 1] = 0; //There is single possible value, remove the value from possible values and return.
    return flag;
}

static int isThisUnique(int row, int col, int val) {
    int i, j, e_i, e_j;
    int isUnique = 1;

    i = (row / 3) * 3;
    j = (col / 3) * 3;
    e_i = i + 3;
    e_j = j + 3;
    for (i = (row / 3) * 3; i < e_i; i++) {
        for (j = (col / 3) * 3; j < e_j; j++) {
            if (i != row || j != col) {
                if (!currBox[i][j] && potentialValues[i][j][val - 1]) {
                    isUnique = 0;
                }
            }
        }
    }

    if (isUnique) {
        return 1;
    }

    for (i = 0; i < 9; i++) {
        if (i != col) {
            if (!currBox[row][i] && potentialValues[row][i][val - 1]) {
                return 0;
            }
        }
        if (i != row) {
            if (!currBox[i][col] && potentialValues[i][col][val - 1]) {
                return 0;
            }
        }
    }


    return 1;
}

static int isSinglePossibleValue2(int row, int col) {
    int k = 0;
    for (k = 0; k < 9; k++) {
        if (potentialValues[row][col][k] && isThisUnique(row, col, k + 1)) {
            return k + 1;
        }
    }
    return 0;
}

static void updatePossibleValue(int row, int col, int val) {
    int i, j, e_i, e_j;
    //Remove possible values in row and coloum.
    for (i = 0; i < 9; i++) {
        potentialValues[row][i][val - 1] = 0;
        potentialValues[i][col][val - 1] = 0;
    }

    //Remove the possible value in corresponding grid
    i = (row / 3) * 3;
    j = (col / 3) * 3;
    e_i = i + 3;
    e_j = j + 3;
    for (i = (row / 3) * 3; i < e_i; i++) {
        for (j = (col / 3) * 3; j < e_j; j++) {
            potentialValues[i][j][val - 1] = 0;
        }
    }
}

void updateInitialValue(int row, int col, int val) {
    currBox[row][col] = val;
    updatePossibleValue(row, col, val);
}

int checkNonExisting(int row, int col, int val) {
    int i, j, e_i, e_j;
    for (i = 0; i < 9; i++) {
        if (i != row) {
            if (currBox[i][col] == val) {
                return 0;
            }
        }
        if (i != col) {
            if (currBox[row][i] == val) {
                return 0;
            }
        }
    }

    //Remove the possible value in corresponding grid
    i = (row / 3) * 3;
    j = (col / 3) * 3;
    e_i = i + 3;
    e_j = j + 3;
    for (i = (row / 3) * 3; i < e_i; i++) {
        for (j = (col / 3) * 3; j < e_j; j++) {
            if (i != row || j != col) {
                if (currBox[i][j] == val) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int verify() {
    int i = 0, j = 0;
    int i_s,j_s,i_e,j_e;
    char possibleValues[10];
    
    //All Values are filled
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (!currBox[i][j]) {
                return 0;
            }
        }
    }
    
    //No duplicate values
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(!checkNonExisting(i,j,currBox[i][j])){
                return 0;
            }
        }
    }
    
    for(i=0;i<9;i++){
        memset(possibleValues,0,sizeof(possibleValues));
        for(j=0;j<9;j++){
            if(possibleValues[currBox[i][j]]){
                return 0;
            }
            possibleValues[currBox[i][j]] = 1;
        }
    }
    
    for(i=0;i<9;i++){
        memset(possibleValues,0,sizeof(possibleValues));
        for(j=0;j<9;j++){
            if(possibleValues[currBox[j][i]]){
                return 0;
            }
            possibleValues[currBox[j][i]] = 1;
        }
    }
    
    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
            memset(possibleValues,0,sizeof(possibleValues));
            i_e = i  + 3;
            j_e = j + 3;            
            for(i_s=i;i_s<i_e;i_s++){
                for(j_s=j;j_s<j_e;j_s++){
                    if(possibleValues[currBox[i_s][j_s]]){
                        return 0;
                    }
                    possibleValues[currBox[i_s][j_s]] = 1;
                }
            }
        }
    }
    
    return 1;

}

int evaluvate() {
    int currRow = 0, currCol = 0, possibleVal;
    int noOfUpdates = 0;
    for (currRow = 0; currRow < 9; currRow++) {
        for (currCol = 0; currCol < 9; currCol++) {
            if (!currBox[currRow][currCol]) {
                possibleVal = isSinglePossibleValue(currRow, currCol);
                if (possibleVal) {
                    currBox[currRow][currCol] = possibleVal;
                    updatePossibleValue(currRow, currCol, possibleVal);
                    noOfUpdates++;
                }
            }
        }
    }
    for (currRow = 0; currRow < 9; currRow++) {
        for (currCol = 0; currCol < 9; currCol++) {
            if (!currBox[currRow][currCol]) {
                /*if(currRow == 8 && currCol == 1){
                    printf("xsdsds");
                }*/
                possibleVal = isSinglePossibleValue2(currRow, currCol);
                if (possibleVal) {
                    currBox[currRow][currCol] = possibleVal;
                    updatePossibleValue(currRow, currCol, possibleVal);
                    noOfUpdates++;
                }
            }
        }
    }
    return noOfUpdates;
}

void dumpResultMatrix() {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (!(i % 3)) {
            printf("\n");
        }
        for (j = 0; j < 9; j++) {
            if(!(j%3)){
                printf(" ");
            }
            printf("%d ", currBox[i][j]);
        }
        printf("\n");

    }
}
