#include "include/Dealer.hpp"

void Dealer::genAllCards(){
    for (int i = 0; i < 4; i++){
        for (int q = 0; q < 13; q++){
            std::array<int, 2> card = {i, q+2}; 
            allCards.push_back(card); 
        }
    }
}

Dealer::Dealer(){
    genAllCards(); 
    layoutRects(4, cardDims, 850, (Vector2){100.f, yPos}, cardsOnTableRec); 
    for (int i = 0; i < 4; i++){
        cardSelected.push_back(false); 
    }
}

bool Dealer::dealCards( std::vector< std::array<int, 2> > &player1, 
                        std::vector< std::array<int, 2> > &player2, bool gameStart  )
{
    if (allCards.size() == 0) return false; 
    srand(time(0)); 

    for (int i = 0; i < 4; i++){
        int _index; 
        if (allCards.size() == 0) {
            printf("out of cards"); 
            return false; 
        }
        if (gameStart){
            _index = rand() % allCards.size(); 
            
            cardsOnTable.push_back(allCards[_index]); 
            allCards.erase(allCards.begin() + _index); 
        }
        
        _index = rand() % allCards.size(); 
        
        player1.push_back(allCards[_index]); 
        allCards.erase(allCards.begin() + _index); 
        
        _index = rand() % allCards.size(); 
        
        player2.push_back(allCards[_index]); 
        allCards.erase(allCards.begin() + _index); 
    }
    return true; 
}

void Dealer::showCards(const std::function<void (Rectangle, int*, bool, bool)> &func){
    layoutRects(cardsOnTable.size(), cardDims, 850, (Vector2){100.f, yPos}, cardsOnTableRec); 

    int _index = 0;
    for (auto val : cardsOnTable){
        int cardToDraw[] = {val[1], val[0]}; 
        func(cardsOnTableRec[_index], cardToDraw, cardSelected[_index], false); 
        _index++; 
    }
}

void Dealer::layoutRects(int _numRectangles, Vector2 _rectDim, int _canvasWidth, Vector2 _initPos, std::vector<Rectangle>& _rectangles){
    _rectangles.clear(); 
    int offset = ((_canvasWidth - _rectDim.x)/(_numRectangles - 1)) - _rectDim.x;
    if (_numRectangles == 1) _rectangles.push_back((Rectangle){_canvasWidth / 2.f, _initPos.y, _rectDim.x, _rectDim.y}); 
    else{
        for (int i = 0; i < _numRectangles; i++){
            _rectangles.push_back((Rectangle){_initPos.x + (i * (_rectDim.x + offset) ), _initPos.y, _rectDim.x, _rectDim.y});
        }
    }
}