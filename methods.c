#include <stdlib.h>
#include "macro.h"
#include "methods.h"

int isPair( Hand* hand, size_t firstPos, size_t secondPos ) {
    return hand->cards[ firstPos ].rank == hand->cards[ secondPos ].rank;
}

int isFlush( Hand* hand ) {
    if( hand->cards[ 0 ].suit == hand->cards[ 4 ].suit ) {  // all cards have same suit
        return 1;
    }

    return 0;
}

int isStraight( Hand* hand ) {
    if( highestCard( hand ) == A ) {
        if( hand->cards[ 1 ].rank == K && // checking for A-high straight
            hand->cards[ 2 ].rank == Q &&
            hand->cards[ 3 ].rank == J &&
            hand->cards[ 4 ].rank == T ) {
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

int isFourOfAKind( Hand* hand ) {
    int z = isPair( hand, 1, 2 ) && isPair( hand, 2, 3 );

    int a = isPair( hand, 0, 1 );
    int b = isPair( hand, 3, 4 );

    return ( a || b ) && z;
}

int isFullHouse( Hand* hand ) {
    int a = hand->cards[ 0 ].rank == hand->cards[ 1 ].rank &&
            hand->cards[ 2 ].rank == hand->cards[ 3 ].rank &&
            hand->cards[ 3 ].rank == hand->cards[ 4 ].rank;
    int b = hand->cards[ 0 ].rank == hand->cards[ 1 ].rank &&
            hand->cards[ 1 ].rank == hand->cards[ 2 ].rank &&
            hand->cards[ 3 ].rank == hand->cards[ 4 ].rank;

    return a || b;
}

int isThreeOfAKind( Hand* hand ) {
    int z = hand->cards[ 1 ].rank == hand->cards[ 3 ].rank;

    int a = hand->cards[ 0 ].rank == hand->cards[ 1 ].rank;
    int b = hand->cards[ 4 ].rank == hand->cards[ 3 ].rank;

    return ( a || b ) && z;
}


char highestCard( Hand* hand ) {
    return hand->cards[ 0 ].rank;
}
