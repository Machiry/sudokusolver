/* 
 * File:   sudoku.h
 * Author: machiry
 *
 * Created on February 16, 2014, 11:07 PM
 */

#ifndef SUDOKU_H
#define	SUDOKU_H

#ifdef	__cplusplus
extern "C" {
#endif

    int evaluvate();
    void updateInitialValue(int row,int col,int val);
    void dumpResultMatrix();
    int verify();
    void initialize();

#ifdef	__cplusplus
}
#endif
#endif	/* SUDOKU_H */

