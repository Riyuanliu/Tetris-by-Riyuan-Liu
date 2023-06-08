//
//  TetrisGrid.hpp
//  Tetris
//
//  Created by Riyuan Liu on 6/6/23.
//

#ifndef TetrisGrid_hpp
#define TetrisGrid_hpp

#include <stdio.h>
#include "Tetrominoes.hpp"
#include <iostream>
class TetrisGrid{
public:
    TetrisGrid(){
        for(unsigned int i = 0; i < M; i++) {
          for(unsigned int j = 0; j < N; j++) {
            field[i][j]=0;
          }
        }
    }
    void resetgrid(){
        for(unsigned int i = 0; i < M; i++) {
          for(unsigned int j = 0; j < N; j++) {
            field[i][j]=0;
          }
        }
    }
    int getnumberat(int x, int y){
        return field[x][y];
    }
    void setnumberat(int x,int y,int n){
        field[x][y]=n;
    }
    bool placeTetrominoes_on_grid(int n,Tetrominoes& b){
        if(check(b)){
            for(int i=0;i<4;i++){
                setnumberat(b.getycord(i), b.getxcord(i), n);
            }
            return true;
        }
        return false;
    }
    bool check(Tetrominoes& a){
        for (int i=0;i<4;i++){
            if(a.getxcord(i)<0  ||  a.getxcord(i)>=N  ||  a.getycord(i)>=M  ){return 0;}
            else if(field[a.getycord(i)][a.getxcord(i)]){return 0;}
        }
        return 1;
    }
    void move(bool movex,int dx,Tetrominoes& a,Tetrominoes& b){
        if(movex){
            b=a;
            a.movexcord(dx);
            if(!check(a)){
                a=b;
            }
        }
    }
    void Roate(bool  roate,Tetrominoes& a,Tetrominoes& b){
        if(roate){
            a.rotate();
            if(!check(a)){
                a=b;
            }
        }
    }

    void Speedown(bool speeddown,Tetrominoes& a,Tetrominoes& b){
        if(speeddown){
            while(check(a)){
                b=a;
                a.moveycord(1);
            }
        }
        if(!check(a)){
            a=b;
        }
    }
    void getdown(bool godown,int dy,Tetrominoes& a,Tetrominoes& b){
        if(godown){
            b=a;
            a.moveycord(1);
        }
        if(!check(a)){
            a=b;
        }
    }
    void keyboardevent(bool movex,int dx,bool rotate,bool speeddown,bool godown,int dy,Tetrominoes& a,Tetrominoes& b){
        move(movex, dx, a, b);
        Roate(rotate, a, b);
        Speedown(speeddown, a, b);
        getdown(godown, dy, a, b);
    }
    void checkclear(int& score){
        int k=M-1;
        for(int i=M-1;i>0;i--){
            int count=0;
            for(int j=0;j<N;j++){
                if(getnumberat(i, j)){
                    count ++;
                }
                setnumberat(k, j, getnumberat(i, j));
            }
            if(count<N)k--;
            else {score++;}
        }
    }
    void resetgame(int& score,int& Highest_score){
        resetgrid();
        Highest_score=fmax(Highest_score,score);
        score=0;
    }
private:
    int M=20;
    int N=10;
    int field[20][10];
    
};
#endif /* TetrisGrid_hpp */
