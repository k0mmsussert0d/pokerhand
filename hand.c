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
void sortHandBy( Hand*, int(*)( const void*, const void* ), size_t, size_t );
int suitCompare( const void*, const void* );
int rankCompare( const void*, const void* );

Hand* PokerHand( const char* hands ) {
    Hand* res = malloc( sizeof (Hand) );
    for( int i = 0, j = 0; hands[ i ] != '\0' && j < 5; i += 2, ++j ) {
        if( hands[ i ] == ' ' ) {
            ++i;
        }

        char curr_rank = (char)toupper( hands[ i ] );
        char curr_suit = (char)toupper( hands[ i + 1 ] );
        if( !isCorrectRank( &curr_rank ) || !isCorrectSuit( &curr_suit ) ) {
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
    sortHandBy( hand, suitCompare, 0, 4 );
    for( size_t i = 0, end = 0, start = 0; i < 5; ++i ) {
        if( hand->cards[ i ].suit != hand->cards[ i + 1 ].suit || i == 4 ) {
            if( start != end ) {
                sortHandBy( hand, rankCompare, start, end );
            }

            start = end + 1;
        }
        ++end;
    }
}

void sortHandBy( Hand* hand, int (*comp)( const void*, const void* ), size_t startAt, size_t endAt ) {
    size_t oneCardSize = sizeof(hand->cards[ 0 ]);
    size_t countOf = endAt - startAt + 1;
    qsort( &hand->cards[ startAt ], countOf, oneCardSize, *comp );
}

int suitCompare( const void* s1, const void* s2 ) {
    const Card* card1 = (const Card*)s1;
    const Card* card2 = (const Card*)s2;

    return card2->suit - card1->suit;
}

int rankCompare( const void* s1, const void* s2 ) {
    const Card* card1 = (const Card*)s1;
    const Card* card2 = (const Card*)s2;

    return card2->rank - card1->rank;
}
