#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"
#include "macro.h"

#define SUIT_O "SHCD"
#define VALUE_O "AKJT98765432"

void HandSort( Hand* );
void sortBySuit( Hand* );
void sortByRank( Hand* );
void sortHandBy( Hand*, int(*)( const void*, const void* ) );
int suitCompare( const void*, const void* );
int rankCompare( const void*, const void* );

Hand* PokerHand( const char* hands ) {
    Hand* res = malloc( sizeof (Hand) );
    for( int i = 0, j = 0; hands[ i ] != '\0' && j < 5; i += 2, ++j ) {
        if( hands[ i ] == ' ' ) {
            ++i;
        }

        const char curr_suit = (char)toupper( hands[ i ] );
        const char curr_rank = (char)toupper( hands[ i + 1 ] );
        if( !isCorrectRank( curr_rank ) || !isCorrectSuit( curr_suit ) ) {
            fprintf( stderr, "Error! %c%c is not correct card.", curr_rank, curr_suit );
            exit( EXIT_FAILURE );
        } else {
            res->cards[ j ].rank = curr_rank;
            res->cards[ j ].suit = curr_suit;
        }
    }

    HandSort( res );
    return res;
}

Result compare( Hand* player, Hand* opponent ) {
    return Loss;
}

void HandSort( Hand* hand ) {
    sortHandBy( hand, suitCompare );
}

void sortHandBy( Hand* hand, int (*comp)( const void*, const void* ) ) {
    qsort( hand->cards, sizeof(hand->cards), sizeof(hand->cards[ 0 ]), *comp );
}

int suitCompare( const void* s1, const void* s2 ) {
    const Card* card1 = (const Card*)s1;
    const Card* card2 = (const Card*)s2;

    return card1->suit - card2->suit;
}

int rankCompare( const void* s1, const void* s2 ) {
    const Card* card1 = (const Card*)s1;
    const Card* card2 = (const Card*)s2;

    return card1->rank - card2->rank;
}
