#ifndef CARDS_H
#define CARDS_H

#define CLUBS       0
#define SPADES      1
#define DIAMONDS    2
#define HEARTS      3

#include <raylib.h>
#include <iostream>

extern Texture2D clubsTex, diamondsTex, heartsTex, spadesTex, highlight;
extern Texture2D blackBackOfCard, redBackOfCard; 

class Cards{
    int scalingFactor = 4; 
    public:
    int dim[2] = {25, 25}; //width, height
    Rectangle texRect = {0.f, 0.f, (float)dim[0], (float)dim[1]}; 
    Rectangle destRect = {0.f, 0.f, (float)dim[0] * scalingFactor, (float) dim[1] * scalingFactor}; 

    bool loadTextures();
    void showCard(Vector2 pos, int* card, bool selected, int frameCount); 
    static void _showCard(Rectangle _destRect, int* card, bool selected, bool hidden); 
};

#endif