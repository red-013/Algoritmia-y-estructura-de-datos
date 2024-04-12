/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de marzo de 2024, 12:13 PM
 */

#include <iostream>
#include <climits>
#define MAXCOL 5
#define MAXFIL 4

using namespace std;

int mov[8][2];

void movimientos(){
    mov[0][0]=-1; mov[0][1]=0;
    mov[1][0]=-1; mov[1][1]=1;
    mov[2][0]=0;  mov[2][1]=1;
    mov[3][0]=1;  mov[3][1]=1 ;
    mov[4][0]=1;  mov[4][1]=0;
    mov[5][0]=1;  mov[5][1]=-1;
    mov[6][0]=0;  mov[6][1]=-1;
    mov[7][0]=-1; mov[7][1]=-1;
    
}
int busca(char tablero[][MAXCOL],char palabra[],int row,
        int col, int n){
    int nrow,ncol,j;
    if(tablero[row][col]!=palabra[0]) return 0;
    
    for(int i=0;i<8;i++){
        nrow = row+mov[i][0];
        ncol = col+mov[i][1];
        for(j=1;j<n;j++){
            if(ncol<0 || nrow<0 || ncol>=MAXCOL || nrow>=MAXFIL)
                break;
            if(tablero[nrow][ncol]!=palabra[j]) break;
            nrow = nrow + mov[i][0];
            ncol = ncol + mov[i][1];
        }
        if(j==n) return 1;
    }
    return 0;
}



void pupiletras(char palabra[],char tablero[][MAXCOL],int m){
    
    for(int i=0;i<MAXFIL;i++)
        for(int j=0;j<MAXCOL;j++)
            if(busca(tablero,palabra,i,j,m))
                cout <<"Encontre la palabra en: " << i <<" "<<j<<  endl;
    
}


int main(int argc, char** argv) {

    char tablero[][MAXCOL]={
        {'G','A','T','O','G'},
        {'O','G','O','A','O'},
        {'L','B','O','C','L'},
        {'R','A','T','L','N'}
    };
    int k=3;
    char palabra[]={'G','O','L'};
    movimientos();
    pupiletras(palabra,tablero,k);
    
    return 0;
}

