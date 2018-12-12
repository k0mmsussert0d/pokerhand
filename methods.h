#ifndef METHODS_H
#define METHODS_H

#include "hand.h"

int isFlush( Hand* );
int isStraight( Hand* );
int isStraightFulsh( Hand* );
int isRoyalFlush( Hand* );
int isFourOfAKind( Hand* );

char highestCard( Hand* );

#endif // METHODS_H
