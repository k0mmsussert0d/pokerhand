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
int suitCompare( const void*, const void* );
int rankCompare( const void*, const void* );

Hand* PokerHand( const char* hands ) {
    Hand* res = malloc( sizeof (Hand) );
    for( int i = 0, j = 0; hands[ i ] != '\0' && j < 5; i += 2, ++j ) {
        if( hands[ i ] == ' ' ) {
            ++i;
        } else if( hands[ i ] == '\0' ) {
            break;
        }

        const char curr_rank = (char)toupper( hands[ i ] );
        const char curr_suit = (char)toupper( hands[ i + 1 ] );
        if( !isCorrectRank( curr_rank ) || !isCorrectSuit( curr_suit ) ) {
            fprintf( stderr, "Error! %c%c is not correct card.", curr_rank, curr_suit );
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
    sortBySuit( hand );
    sortByRank( hand );
}

void sortBySuit( Hand* hand ) {
    qsort( hand->Cards, 5, 3, suitCompare );
}

void sortByRank( Hand* hand ) {
    char* pos = hand->Cards[ 0 ];
    size_t count = 0;
    for( int i = 1; i < 5; ++i ) {
        char* current = hand->Cards[ i ];
        char* previous = hand->Cards[ i - 1 ];
        if( current[ 1 ] != previous[ 1 ] ) {
            if( count ) {
                qsort( pos, count + 1, 3, rankCompare );
            }
            count = 0;
            pos = hand->Cards[ i + 1 ];
        } else {
            ++count;
        }
    }
}

int suitCompare( const void* s1, const void* s2 ) {
    const char* arg1 = (const char*)s1;
    const char* arg2 = (const char*)s2;

    return arg1[ 1 ] - arg2[ 1 ];
}

int rankCompare( const void* s1, const void* s2 ) {
    const char* arg1 = (const char*)s1;
    const char* arg2 = (const char*)s2;

    return -( arg1[ 0 ] - arg2[ 0 ] );
}
