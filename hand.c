#include <string.h>
#include <stdlib.h>
#include "hand.h"

#define SUIT_O "SHCD"
#define VALUE_O "AKJT98765432"

void HandSort( Hand* );
void sortBySuit( Hand* );
void sortByRank( Hand* );
int suitCompare( const void*, const void* );
int rankCompare( const void*, const void* );

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
        char* rank = &res->Cards[ i ][ 0 ];
        if( *rank <= '9' && *rank >= '2' ) {
            *rank -= '0';
        } else {
            switch( *rank ) {
            case 'T':
                *rank = 10;
                break;
            case 'J':
                *rank = 11;
                break;
            case 'Q':
                *rank = 12;
                break;
            case 'K':
                *rank = 13;
                break;
            case 'A':
                *rank = 14;
                break;
            default:
                *rank = '?';
                break;
            }
        }

        char* suit = &res->Cards[ i ][ 1 ];
        switch( *suit ) {
        case 'S':
            *suit = 1;
            break;
        case 'H':
            *suit = 2;
            break;
        case 'C':
            *suit = 3;
            break;
        case 'D':
            *suit = 4;
            break;
        default:
            *suit = '?';
            break;
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
