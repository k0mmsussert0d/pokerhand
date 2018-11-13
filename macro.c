#include <ctype.h>
#include <string.h>
#include "macro.h"

int isCorrectRank( const char rank ) {
    const char allRanks[] = "SHCD";

    if( !isupper( rank ) ) {
        return 0;
    } else if( strchr( allRanks, rank ) == NULL ) {
        return 0;
    }

    return 1;
}

int isCorrectSuit( const char suit ) {
    const char allCharSuits[] = "TJQKA";

    if( suit >= '2' && suit <= '9' ) {
        return 1;
    } else if( strchr( allCharSuits, suit ) != NULL ) {
        return 1;
    }

    return 0;
}
