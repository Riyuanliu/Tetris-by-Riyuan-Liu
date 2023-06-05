#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;
using namespace std;

const int M=20;
const int N=10;
const int CELLSIZE=18;
int field[M][N]={0};

struct Point
{int x,y;}a[4],b[4],c[4];

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

bool check(){
    for (int i=0;i<4;i++){
        if(a[i].x<0  ||  a[i].x>=N  ||  a[i].y>=M  )return 0;
        else if(field[a[i].y][a[i].x])return 0;
    }
    return 1;
}
void draw_box(RenderWindow& window,int x,int y,int wide,int high){
    RectangleShape rectangle(sf::Vector2f(wide, high));
    rectangle.setFillColor(sf::Color(0,0,0));
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color(256,256,256));
    rectangle.setPosition(x, y);
    window.draw(rectangle);
}
void draw_text(unsigned short i_x, unsigned short i_y, const std::string& i_text, sf::RenderWindow& i_window)
{
    //We're gonna align the text ot the left top
    short character_x = i_x;
    short character_y = i_y;

    unsigned char character_width;

    sf::Sprite character_sprite;

    sf::Texture font_texture;
    font_texture.loadFromFile("Images/font.png");

    //We're gonna calculate the width of the character based on the font image size
    //96 because there are 96 character in the image
    character_width = font_texture.getSize().x / 96;

    character_sprite.setTexture(font_texture);

    for (const char a : i_text)
    {
        if ('\n' == a)
        {
            //After every newline we put increase the y-coordinate and reset the x-coordinate
            character_x = i_x;
            character_y += font_texture.getSize().y;

            continue;
        }

        //Change the position of the next character
        character_sprite.setPosition(character_x, character_y);
        //Pick the character from the font image
        character_sprite.setTextureRect(sf::IntRect(character_width * (a - 32), 0, character_width, font_texture.getSize().y));

        //Increase the x-coordinate
        character_x += character_width;

        //Draw the character
        i_window.draw(character_sprite);
    }
}
void move(int dx){
    for(int i=0;i<4;i++) {
        b[i]=a[i];
        a[i].x+=dx;
    }
    if(!check()){
        for(int i=0;i<4;i++)a[i]=b[i];
    }
}
void Roate(bool  roate){
    if(roate){
        Point p=a[1];
        for(int i=0;i<4;i++){
            int x=a[i].y-p.y;
            int y=a[i].x-p.x;
            a[i].x=p.x-x;
            a[i].y=p.y+y;
        }
        if(!check()){
            for(int i=0;i<4;i++)a[i]=b[i];
        }
    }
}

void Speedown(bool speeddown){
    if(speeddown){
        while(check()){
            for(int i=0;i<4;i++){
                b[i]=a[i];
                a[i].y+=1;
            }
        }
    }
    if(!check()){
        for(int i=0;i<4;i++)a[i]=b[i];
    }
}
bool checkfail(){
    for(int i=0;i<N;i++){
        int v=0;
        for(int j=0;j<M;j++){
            if(field[j][i])v++;
        }
        if(v>=M-3){
            return true;
        }
    }
    return false;
}
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
    bool rotate=0,speedown=0,godown=0;
    float timer=0,delay=0.3;
    int score=0,Highest_score=0;
    int bcolnum=1;
    
    
    
    Clock clock;
    
    //first random shape
    int n=random()%7;
    cout<<n<<endl;
    for(int i=0;i<4;i++){
        a[i].x=figures[n][i]%2;
        a[i].y=figures[n][i]/2;
        c[i]=a[i];
    }
    
    
    int x=rand()%7;
    for(int i=0;i<4;i++){
        c[i].x=figures[x][i]%2;
        c[i].y=figures[x][i]/2;
    }
    
    
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
                if(e.key.code==Keyboard::Left) dx=-1;
                if(e.key.code==Keyboard::Right) dx=1;
                if(e.key.code==Keyboard::Return)speedown=true;
                if(e.key.code==Keyboard::Down)godown=true;
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){delay+=0.05;}
        ///<--move-->///
        move(dx);
        //Rotate//
        Roate(rotate);
        //speedown//
        Speedown(speedown);
        //godown//
        if(godown){
            for(int i=0;i<4;i++){
                b[i]=a[i];
                a[i].y+=1;
            }
        }
        if(!check()){
            for(int i=0;i<4;i++)a[i]=b[i];
        }
        ////Tick///
        if(timer>delay){
            for(int i=0;i<4;i++){
                b[i]=a[i];
                a[i].y+=1;
            }
            if(!check()){
                for(int i=0;i<4;i++){
                    field[b[i].y][b[i].x]=bcolnum;
                }
                if(checkfail()){
                    for(unsigned int i = 0; i < M; i++) {
                      for(unsigned int j = 0; j < N; j++) {
                        field[i][j]=0;
                      }
                    }
                    Highest_score=max(Highest_score,score);
                    score=0;
                }
                bcolnum=colorNum;
                colorNum=1+rand()%7;
                for(int i=0;i<4;i++){
                    a[i]=c[i];
                }
                int n =rand()%7;
                for(int i=0;i<4;i++){
                    c[i].x=figures[n][i]%2;
                    c[i].y=figures[n][i]/2;
                }
                //move the block to middle
                for(int i=0;i<4;i++){
                    a[i].x+=4;
                    a[i].y-=1;
                }
            }
            timer=0;
        }
        //check clear//
        int k=M-1;
        for(int i=M-1;i>0;i--){
            int count=0;
            for(int j=0;j<N;j++){
                if(field[i][j]){
                    count ++;
                }
                field[k][j]=field[i][j];
                
            }
            if(count<N)k--;
            else score++;
        }
        dx=0; rotate=0; delay=0.3;speedown=0;godown=0;

        
        window.clear(Color::White);
        window.draw(background);
        //draw on the grid after place//
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(field[i][j]==0)continue;
                s.setTextureRect(IntRect(field[i][j]*18,0,18,18));
                s.setPosition(j*18,i*18);
                s.move(28,31); //offset
                window.draw(s);
            }
        }

        //drawing the shape//
        for(int i=0;i<4;i++){
            s.setTextureRect(IntRect(bcolnum*18,0,18,18));
            s.setPosition(a[i].x*18,a[i].y*18);
            s.move(28,31); //offset
            window.draw(s);
        }
        //drawing the preview//
        draw_box(window,240,45,150,100);
        for(int i=0;i<4;i++){
            s1.setTextureRect(IntRect(colorNum*18,0,18,18));
            s1.setPosition(c[i].x*18,c[i].y*18);
            s1.move(240,50); //offset
            window.draw(s1);
        }
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
