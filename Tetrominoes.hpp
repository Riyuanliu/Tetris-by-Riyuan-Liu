//
//  Tetrominoes.hpp
//  Tetris
//
//  Created by Riyuan Liu on 6/6/23.
//

#ifndef Tetrominoes_hpp
#define Tetrominoes_hpp

#include <stdio.h>
#include "Point.hpp"
#include <random>
int figures[7][4]=
{
    1,3,5,7,  //I
    2,4,5,7,  //z
    3,5,4,6,  //S
    3,5,4,7,  //T
    2,3,5,7,  //L
    3,5,7,6,  //J
    2,3,4,5,  //O
};
class Tetrominoes:public Point
{
public:
    Tetrominoes(){
        for(int i=0;i<4;i++){
            a[i].x=0;
            a[i].y=0;
        }
    }
    Tetrominoes(int n){
        for(int i=0;i<4;i++){
            a[i].x=figures[n][i]%2;
            a[i].y=figures[n][i]/2;
        }
    }
    //change every x cord of every block of this tetrominoes
    void setxcord(int n){
        for(int i=0;i<4;i++){
            a[i].x=n;
        }
    }
    //change every y cord of every block of this tetrominoes
    void setycord(int n){
        for(int i=0;i<4;i++){
            a[i].y=n;
        }
    }
    void movexcord(int dx){
        for(int i=0;i<4;i++){
            a[i].x+=dx;
        }
    }
    void moveycord(int dx){
        for(int i=0;i<dx;i++){
            for(int i=0;i<4;i++){
                a[i].y+=1;
            }
        }
    }
    void rotate(){
        Point p=a[1];
        for(int i=0;i<4;i++){
            int x=a[i].y-p.y;
            int y=a[i].x-p.x;
            a[i].x=p.x-x;
            a[i].y=p.y+y;
        }
    }
    //get every x cord of i block of this tetrominoes
    int getxcord(int i){
        return a[i].x;
    }
    //get every x cord of i block of this tetrominoes
    int getycord(int i){
        return a[i].y;
    }
    //change the tetrominoes into something else
    void changeTetrominoes(int n){
        for(int i=0;i<4;i++){
            a[i].x=figures[n][i]%2;
            a[i].y=figures[n][i]/2;
        }
    }
    void changeTetrominoestorandom(){
        int n = rand() % 6 + 1;
        for(int i=0;i<4;i++){
            a[i].x=figures[n][i]%2;
            a[i].y=figures[n][i]/2;
        }
    }
    //change this tetrominoes into the new tetrominoes
    void operator=(Tetrominoes &rhs){
        for(int i=0;i<4;i++){
            a[i].x=rhs.getxcord(i);
            a[i].y=rhs.getycord(i);
        }
    }
    
private:
    Point a[4];
};
#endif /* Tetrominoes_hpp */
