#include <stdlib.h>
#include "macro.h"
#include "methods.h"

int isFlush( Hand* hand ) {
    if( hand->cards[ 0 ].suit == hand->cards[ 4 ].suit ) {  // all cards have same suit
        return 1;
    }

    return 0;
}

int isStraight( Hand* hand ) {
    if( hand->cards[ 0 ].rank == 14 ) { // highest cards is A
        if( hand->cards[ 1 ].rank == 13 && // checking for A-high straight
            hand->cards[ 2 ].rank == 12 &&
            hand->cards[ 3 ].rank == 11 &&
            hand->cards[ 4 ].rank == 10 ) {
                return 1;
        }

        if( hand->cards[ 1 ].rank == 5 && // checking for 5-high straight
            hand->cards[ 2 ].rank == 4 &&
            hand->cards[ 3 ].rank == 3 &&
            hand->cards[ 4 ].rank == 2 ) {
                return 1;
        }

        return 0;
    }

    char prevRank = hand->cards[ 0 ].rank;
    for( size_t i = 1; i < 5; ++i ) { // other cases, general check
        if( hand->cards[ i ].rank != prevRank - 1 ) {
            return 0;
        }

        prevRank = hand->cards[ i ].rank;
    }

    return 1;
}

int isStraightFlush( Hand* hand ) {
    return isFlush( hand ) && isStraight( hand );
}

int isRoyalFlush( Hand* hand ) {
    return isStraightFlush( hand ) && highestCard( hand ) == A;
}


char highestCard( Hand* hand ) {
    return hand->cards[ 0 ].rank;
}
