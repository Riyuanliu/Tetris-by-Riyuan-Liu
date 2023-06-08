#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Point.hpp"
#include "Tetrominoes.hpp"
#include "TetrisGrid.hpp"
#include "Interface.hpp"
using namespace sf;
using namespace std;

const int M=20;
const int N=10;
const int CELLSIZE=18;
TetrisGrid game;

Tetrominoes a,b,c;
int main(){
    srand(time(0));
    
    RenderWindow window(VideoMode(420,480),"Tetris!");
    //load image from the folder
    Texture t1,t2,t3;
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");
    Sprite s(t1), background(t2), frame(t3), s1(t1);

    int dx=0, colorNum=1;
    bool rotate=0,speedown=0,godown=0,movex=0;
    float timer=0,delay=0.3;
    int score=0,Highest_score=0;
    int bcolnum=1;
    
    
    
    Clock clock;
    
    //first random shape
    a.changeTetrominoestorandom();
    a.movexcord(4);
    //first preview
    c.changeTetrominoestorandom();
    
    while(window.isOpen()){
        float time=clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        Event e;
        while(window.pollEvent(e)){
            if(e.type==Event::Closed)
                window.close();
            if(e.type==Event::KeyPressed){
                if(e.key.code==Keyboard::Up) rotate=true;
                if(e.key.code==Keyboard::Left) {movex=1;dx=-1;}
                if(e.key.code==Keyboard::Right){movex=1;dx=1;}
                if(e.key.code==Keyboard::Return)speedown=true;
                if(e.key.code==Keyboard::Down)godown=true;
            }
        }
        //how fast the game go
        if(delay-0.05>0){
            for(int i=0;i<(score/10);i++){
                delay-=0.05;
            }
        }
        //keyboard event
        game.keyboardevent(movex, dx, rotate, speedown, godown, 1, a, b);
        ////Tick///
        if(timer>delay){
            b=a;
            a.moveycord(1);
            if(!game.check(a)){
                if(!game.placeTetrominoes_on_grid(bcolnum, b)){
                    game.resetgame(score, Highest_score);
                }
                //check if player ran out of place
                //spawning new shape
                bcolnum=colorNum;
                colorNum=1+rand()%7;
                //pull shape from the preview
                a=c;
                //spawn new shape for the preview
                c.changeTetrominoestorandom();
                //move the block to middle
                a.movexcord(4);
            }
            timer=0;
        }
        //check clear//
        game.checkclear(score);
        dx=0; rotate=0; delay=0.3;speedown=0;godown=0;movex=0;

        
        window.clear(Color::White);
        window.draw(background);
        //draw on the grid after place//
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(game.getnumberat(i, j)==0)continue;
                s.setTextureRect(IntRect(game.getnumberat(i, j)*18,0,18,18));
                s.setPosition(j*18,i*18);
                s.move(28,31); //offset
                window.draw(s);
            }
        }
        //drawing the shape//
        drawingshapeongrid(window, a, 28, 31, bcolnum, s);
        //drawing the preview//
        draw_box(window,240,25,150,100);
        draw_text(static_cast<unsigned short>(CELLSIZE * (0.5f + 13)), static_cast<unsigned short>(0.5f * CELLSIZE * 3), "Preview:", window);
        drawingshapeongrid(window, c, 240, 50, colorNum, s1);
        //drawing the highscore and curr score
        window.draw(frame);
        draw_box(window,240,277,150,50);
        draw_text(static_cast<unsigned short>(CELLSIZE * (0.5f + 13)), static_cast<unsigned short>(0.5f * CELLSIZE * 31), "Score     :", window);
        draw_text(static_cast<unsigned short>(CELLSIZE * (0.5f + 20)), static_cast<unsigned short>(0.5f * CELLSIZE * 31), to_string(score), window);
        
        draw_text(static_cast<unsigned short>(CELLSIZE * (0.5f + 13)), static_cast<unsigned short>(0.5f * CELLSIZE * 33), "High score:", window);
        draw_text(static_cast<unsigned short>(CELLSIZE * (0.5f + 20)), static_cast<unsigned short>(0.5f * CELLSIZE * 33), to_string(Highest_score), window);
        window.display();
    }
}
