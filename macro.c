#include <ctype.h>
#include <string.h>
#include "macro.h"

int isCorrectSuit( char* suit ) {
    const char allSuits[] = "DCHS";

    if( !isupper( *suit ) ) {
        return 0;
    }

    for( int i = 0; allSuits[ i ] != '\0'; ++i ) {
        if( *suit == allSuits[ i ] ) {
            *suit = (char)(i + 1);
            return 1;
        }
    }

    return 0;
}

int isCorrectRank( char* rank ) {
    const char allRanks[] = "TJQKA";

    if( *rank >= '2' && *rank <= '9' ) {
        *rank -= '0';
        return 1;
    }

    for( int i = 0; allRanks[ i ] != '\0'; ++i ) {
        if( *rank == allRanks[ i ] ) {
            *rank = (char)(i + 10);
            return 1;
        }
    }

    return 0;
}
