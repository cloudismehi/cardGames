#include "include/Cards.hpp"

Texture2D clubsTex, diamondsTex, heartsTex, spadesTex, highlight; 
Texture2D blackBackOfCard, redBackOfCard; 

bool Cards::loadTextures(){
    clubsTex = LoadTexture("../assets/cards/clubs.png"); 
    if (clubsTex.format == 0) {
        std::cerr << "couldn't load clubs texture"; 
        return false; 
    }
    
    spadesTex = LoadTexture("../assets/cards/spades.png"); 
    if (spadesTex.format == 0) {
        std::cerr << "couldn't load spades texture"; 
        return false; 
    }
    diamondsTex = LoadTexture("../assets/cards/diamonds.png"); 
    if (diamondsTex.format == 0) {
        std::cerr << "couldn't load diamonds texture"; 
        return false; 
    }
    heartsTex = LoadTexture("../assets/cards/hearts.png"); 
    if (heartsTex.format == 0) {
        std::cerr << "couldn't load hearts texture"; 
        return false; 
    }
    highlight = LoadTexture("../assets/cards/highlight.png"); 
    if (highlight.format == 0) {
        std::cerr << "couldn't load highlight texture"; 
        return false; 
    }
    blackBackOfCard = LoadTexture("../assets/cards/blackBackofCard.png"); 
    if (blackBackOfCard.format == 0) {
        std::cerr << "couldn't load black back of card texture"; 
        return false; 
    }
    redBackOfCard = LoadTexture("../assets/cards/redBackofCard.png"); 
    if (redBackOfCard.format == 0) {
        std::cerr << "couldn't load red back of card texture"; 
        return false; 
    }

    return true; 
}

void Cards::showCard(Vector2 pos, int* card, bool selected, int frameCount){
     
    Texture2D texToDraw; 
    switch (card[1]){
        case SPADES:
            texToDraw = spadesTex; 
            break; 
        case CLUBS:
            texToDraw = clubsTex; 
            break; 
        case DIAMONDS:
            texToDraw = diamondsTex; 
            break; 
        case HEARTS:
            texToDraw = heartsTex; 
            break; 
    }
    texRect.x = dim[0] * (card[0] - 2); 
    destRect.x = pos.x; 
    destRect.y = pos.y; 
    
    DrawTexturePro(texToDraw, texRect, destRect, (Vector2){50.f, 50.f}, 0.f, WHITE); 
    if (selected and (frameCount < 30)){
        DrawTexturePro(highlight, texRect, destRect, (Vector2){50.f, 50.f}, 0.f, WHITE); 
    }
}

void Cards::_showCard(Rectangle _destRect, int* card, bool selected, bool hidden){
     
    Texture2D texToDraw; 
    switch (card[1]){
        case SPADES:
            if (hidden) texToDraw = blackBackOfCard; 
            else texToDraw = spadesTex; 
            break; 
        case CLUBS:
            if (hidden) texToDraw = blackBackOfCard; 
            else texToDraw = clubsTex; 
            break; 
        case DIAMONDS:
            if (hidden) texToDraw = redBackOfCard; 
            else texToDraw = diamondsTex; 
            break; 
        case HEARTS:
            if (hidden) texToDraw = redBackOfCard; 
            else texToDraw = heartsTex; 
            break; 
    }
    Rectangle texture = {0.f, 0.f, 25.f, 25.f}; 
    texture.x = 25.f * (card[0] - 2); 
    
    DrawTexturePro(texToDraw, texture, _destRect, (Vector2){50.f, 50.f}, 0.f, WHITE); 
    if (selected){
        DrawTexturePro(highlight, texture, _destRect, (Vector2){50.f, 50.f}, 0.f, WHITE); 
    }
}
