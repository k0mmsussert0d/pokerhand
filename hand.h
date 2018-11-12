#ifndef HAND_H
#define HAND_H

typedef struct Hand {
    char Cards[ 5 ][ 3 ];
} Hand;
typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand( const char* );
Result compare( Hand*, Hand* );

#endif // HAND_H
