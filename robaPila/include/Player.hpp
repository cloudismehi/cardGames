#include <raylib.h>
#include <iostream>
#include <array>
#include <vector>
#include <functional>

class Player{
    public:
    std::vector<std::array<int, 2>> cards; 
    std::vector<std::array<int, 2>> pile; 
    
    std::vector<bool> cardSelected; 
    std::vector<Rectangle> cardRecs; 
    Rectangle pileRec = {800.f, 900.f, 100.f, 100.f}; 
    Rectangle discardRec; 
    Vector2 cardDims = {100.f, 100.f}; 
    int whichCardSelected = -1; 
    bool isBot = false; 
    
    bool activePlayer = true; 

    Player(); 
    Player(bool _active); 
    void showCards(const std::function<void(Rectangle, int*, bool, bool)> &func, bool myTurn);
    void layoutRects(int _numRectangles, Vector2 _rectDim, int _canvasWidth, Vector2 _initPos, std::vector<Rectangle>& _rectangles); 
    
    bool play(std::vector<std::array<int, 2>> &_cardsOnTable, std::vector<Rectangle> _cardsOnTableRec,
                Rectangle _otherPileRec, std::vector<std::array<int,2>> &_otherPile); 
    bool playBot(std::vector<std::array<int, 2>> &_cardsOnTable, std::vector<Rectangle> _cardsOnTableRec,
        Rectangle _otherPileRec, std::vector<std::array<int,2>> &_otherPile); 

    private: 
    int yPos; 
    bool drawDiscard = false; 
}; 
