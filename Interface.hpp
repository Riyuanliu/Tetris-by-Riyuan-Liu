//
//  Interface.hpp
//  Tetris
//
//  Created by Riyuan Liu on 6/7/23.
//

#ifndef Interface_hpp
#define Interface_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
using namespace sf;
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
void drawingshapeongrid(RenderWindow& window, Tetrominoes a,int x, int y,int colorNum,Sprite& s){
    for(int i=0;i<4;i++){
        s.setTextureRect(IntRect(colorNum*18,0,18,18));
        s.setPosition(a.getxcord(i)*18,a.getycord(i)*18);
        s.move(x,y); //offset
        window.draw(s);
    }
}

#endif /* Interface_hpp */
