#ifndef HAND_H
#define HAND_H

typedef struct Card {
    char suit;
    char rank;
} Card;

typedef struct Hand {
    Card cards[ 5 ];
} Hand;

typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand( const char* );
Result compare( Hand*, Hand* );

#endif // HAND_H
