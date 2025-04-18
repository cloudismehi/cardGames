#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <raylib.h>
#include <vector>
#include <array>
#include <functional>

class Dealer{
    void genAllCards(); 
    public: 
    
    Dealer(); 
    std::vector<std::array<int, 2> > allCards; 
    std::vector<std::array<int, 2> > cardsOnTable; 
    std::vector<bool> cardSelected; 
    Vector2 cardDims = {100.f, 100.f}; 
    
    std::vector< Rectangle > cardsOnTableRec; 
    
    bool dealCards( std::vector< std::array<int, 2> > &player1, 
                    std::vector< std::array<int, 2> > &player2, bool gameStart  ); 
    void showCards(const std::function<void (Rectangle, int*, bool, bool)> &func);
    void layoutRects(int _numRectangles, Vector2 _rectDim, int _canvasWidth, Vector2 _initPos, std::vector<Rectangle>& _rectangles); 
    private: 
    float yPos = 500.f;
}; 

#endif