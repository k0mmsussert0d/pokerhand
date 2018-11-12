#include <string.h>
#include <stdlib.h>
#include "hand.h"

#define SUIT_O "SHCD"
#define VALUE_O "AKJT98765432"

void sortBySuit( Hand* );
int suitCompare( const void*, const void* );

typedef struct Hand {
    char Cards[ 5 ][ 3 ];
} Hand;

Hand* PokerHand( const char* hands ) {
    Hand* res = malloc( sizeof (Hand) );
    for( int i = 0, j = 0, k = 0; hands[ i ] != '\0'; ++i ) {
        if( hands[ i ] == ' ' ) {
            res->Cards[ j ][ k ] = '\0';
            ++j; k = 0;
        } else {
            res->Cards[ j ][ k++ ] = hands[ i ];
        }
        res->Cards[ j ][ k ] = '\0';
    }
    for( int i = 0; i < 5; ++i ) {
        char* rank = &res->Cards[ i ][ 1 ];
        switch( *rank ) {
            case 'S':
                *rank = 1;
                break;
            case 'H':
                *rank = 2;
                break;
            case 'C':
                *rank = 3;
                break;
            case 'D':
                *rank = 4;
                break;
            default:
                *rank = '?';
        }
    }
    sortBySuit( res );
    return res;
}

Result compare( Hand* player, Hand* opponent ) {
    return Loss;
}

void sortBySuit( Hand* hand ) {
    qsort( hand->Cards, 5, 3, suitCompare );
}

int suitCompare( const void* s1, const void* s2 ) {
    const char* arg1 = (const char*)s1;
    const char* arg2 = (const char*)s2;

    return arg1[ 1 ] - arg2[ 1 ];
}
