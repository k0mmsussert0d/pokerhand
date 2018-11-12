#include <string.h>
#include <stdlib.h>

typedef struct Hand {
    char Cards[ 5 ][ 3 ];
} Hand;

typedef enum { Win, Loss, Tie } Result;

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
    return res;
}

Result compare( Hand* player, Hand* opponent ) {
    return Loss;
}
