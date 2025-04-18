#include "include/Player.hpp"

Player::Player(bool _active){
    activePlayer = _active;
    if (activePlayer){
        yPos = 750; 
        pileRec = (Rectangle){800.f, 900.f, 100.f, 100.f}; 
        discardRec = (Rectangle){100.f, 900.f, 150.f, 50.f}; 
    }
    else {
        yPos = 225; 
        pileRec = (Rectangle){800.f, 100.f, 100.f, 100.f}; 
        discardRec = (Rectangle){100.f, 75.f, 150.f, 50.f}; 
    }
    
    layoutRects(4, cardDims, 850, (Vector2){100.f, (float)yPos}, cardRecs); 
    for (int i = 0; i < 4; i++) cardSelected.push_back(false); 
}

bool Player::play(std::vector<std::array<int, 2>> &_cardsOnTable, std::vector<Rectangle> _cardsOnTableRec,
                    Rectangle _otherPileRec, std::vector<std::array<int, 2>> &_otherPile){
    bool turnOver = false; 
    Rectangle pilaCheck = {_otherPileRec.x - 50, _otherPileRec.y - 50, _otherPileRec.width, _otherPileRec.height}; 
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        
        Vector2 mousePos = {(float)GetMouseX(), (float)GetMouseY()}; 
        //draw highlight
        for (int i = 0; i < cards.size(); i++){
            Rectangle recCheck = {cardRecs[i].x - 50, cardRecs[i].y - 50, cardRecs[i].width, cardRecs[i].height};
            if (CheckCollisionPointRec(mousePos, recCheck) and (mousePos.y >= cardRecs[0].y - 50)){
                cardSelected[i] = true; 
            } else {
                cardSelected[i] = false;         
            }
        }
        //check for draw
        for (int i = 0; i < _cardsOnTable.size(); i++){
            Rectangle recCheck = {_cardsOnTableRec[i].x - 50, _cardsOnTableRec[i].y - 50, _cardsOnTableRec[i].width, _cardsOnTableRec[i].height};
            if (CheckCollisionPointRec(mousePos, recCheck)){
                if (_cardsOnTable[i][1] == cards[whichCardSelected][1]){
                    pile.push_back(cards[whichCardSelected]); 
                    pile.push_back(_cardsOnTable[i]); 
                    _cardsOnTable.erase(_cardsOnTable.begin() + i); 
                    cards.erase(cards.begin() + whichCardSelected); 
                    turnOver = true; 
                }
            } 
        }
         
        //check for roba pila
        if ((drawDiscard) and (CheckCollisionPointRec(mousePos, pilaCheck))){
            if (_otherPile.back()[1] == cards[whichCardSelected][1]){
                for (int i = 0; i < _otherPile.size(); i++){
                    pile.push_back(_otherPile[i]); 
                }
                pile.push_back(cards[whichCardSelected]); 
                _otherPile.clear(); 
                cards.erase(cards.begin() + whichCardSelected);
            }  
            turnOver = true; 
        }

        //discard
        if ((drawDiscard) and (CheckCollisionPointRec(mousePos, discardRec))){
            _cardsOnTable.push_back(cards[whichCardSelected]); 
            cards.erase(cards.begin() + whichCardSelected); 
            turnOver = true; 
        }

        //check what card is selected
        int _index = 0; 
        for (auto val : cardSelected){
            if (val) {
                whichCardSelected  = _index; 
                drawDiscard = true; 
                break; 
            }
            else {
                whichCardSelected = -1; 
                drawDiscard = false; 
            }
            _index++; 
        }
    } 
    if (activePlayer){
        DrawRectangle(400, 990, 200, 10, BLACK); 
    }
    else{
        DrawRectangle(400, 0, 200, 10, BLACK); 
    }
    
    return turnOver; 
}

void Player::showCards(const std::function<void(Rectangle, int*, bool, bool)> &func, bool myTurn){
    layoutRects(cards.size(), cardDims, 850, (Vector2){100.f, (float)yPos}, cardRecs); 
    
    int _index = 0; 
    //draw cards
    for (auto val : cards){
        int cardToDraw[] = {val[1], val[0]}; 
        func(cardRecs[_index], cardToDraw, cardSelected[_index], !myTurn); 
        _index++; 
    }
    //draw pile
    if (pile.size() != 0){
        int cardToDraw[] = {pile.back()[1], pile.back()[0]}; 
        func(pileRec, cardToDraw, false, false); 
        // std::string cardsInPile = std::to_string(pile.size()); 
        // DrawText(cardsInPile.c_str(), pileRec.x - 70, pileRec.y, 20, BLACK); 
    }
    //draw discard button
    if (drawDiscard){
        DrawRectangleLinesEx(discardRec, 3, BLACK); 
        DrawText("discard?", discardRec.x+10, discardRec.y+5, 30, BLACK); 
    }
}

void Player::layoutRects(int _numRectangles, Vector2 _rectDim, int _canvasWidth, Vector2 _initPos, std::vector<Rectangle>& _rectangles){
    _rectangles.clear(); 
    int offset = ((_canvasWidth - _rectDim.x)/(_numRectangles - 1)) - _rectDim.x;
    if (_numRectangles == 1) _rectangles.push_back((Rectangle){_canvasWidth / 2.f, _initPos.y, _rectDim.x, _rectDim.y}); 
    else{
        for (int i = 0; i < _numRectangles; i++){
            _rectangles.push_back((Rectangle){_initPos.x + (i * (_rectDim.x + offset) ), _initPos.y, _rectDim.x, _rectDim.y});
        }
    }
}