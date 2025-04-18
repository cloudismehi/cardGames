#include <iostream>
#include <raylib.h>
#include <vector> 

#include "include/Cards.hpp"
#include "include/Dealer.hpp"
#include "include/Player.hpp"

void show(Rectangle rec){
    DrawRectangleRec(rec, WHITE); 
}

int main(){
    InitWindow(1000, 1000, "we'll light ourselves on fire"); 
    SetTargetFPS(60); 

    Dealer dealer; 
    std::vector<std::array<int, 2>> player1, player2;  
    Cards cards; 
    
    Player cloud(true); 
    Player ro(false); 
    bool gameOver = false; 
    bool playerTurn = true;
    bool playerTurnBufferBool = playerTurn;  

    if (!cards.loadTextures()){
        CloseWindow(); 
        exit(EXIT_FAILURE); 
    }; 

    dealer.dealCards(cloud.cards, ro.cards, true); 
    
    
    while(!WindowShouldClose()){
        BeginDrawing(); 
        ClearBackground(RAYWHITE); 

        if (gameOver){
            DrawRectangle(100, 100, 800, 800, GRAY); 
            DrawText("GAME OVER!", 180, 450, 100, BLACK); 
            if (cloud.cards.size() > ro.cards.size()){
                DrawText("Player 1 won!", 200, 600, 50, RED); 
            } else {
                DrawText("Player 2 won!", 200, 600, 50, RED); 
            }
        } else{
            int _index = 0; 
            
            int playerTurnBufferInt = 0; 

            cloud.showCards(cards._showCard, playerTurn); 
            ro.showCards(cards._showCard, !playerTurn); 
            dealer.showCards(cards._showCard); 
            
            if ((playerTurnBufferBool != playerTurn) and (playerTurnBufferInt++ < 120)){
                continue; 
            } else{
                if (playerTurn) {
                    playerTurn = !cloud.play(dealer.cardsOnTable, dealer.cardsOnTableRec, ro.pileRec, ro.pile); 
                }
                else {
                    playerTurn = ro.play(dealer.cardsOnTable, dealer.cardsOnTableRec, cloud.pileRec, cloud.pile); 
                }
                if ((ro.cards.size() == 0) and (cloud.cards.size() == 0)){
                    if (!dealer.dealCards(cloud.cards, ro.cards, false)) gameOver = true; 
                }
                playerTurnBufferBool = playerTurn; 
                playerTurnBufferInt = 0; 
            }
        }
        
        EndDrawing(); 
    }
    CloseWindow(); 

    return 0; 
}

