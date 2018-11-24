#include <stdlib.h>
#include "methods.h"

int isFlush( Hand* hand ) {
    if( hand->cards[ 0 ].suit == hand->cards[ 4 ].suit ) {  // all cards have same suit
        return 1;
    }

    return 0;
}

