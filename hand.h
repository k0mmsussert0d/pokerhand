#ifndef HAND_H
#define HAND_H

typedef struct Hand Hand;
typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand( const char* );
Result compare( Hand*, Hand* );

#endif // HAND_H
