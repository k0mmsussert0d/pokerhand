#ifndef METHODS_H
#define METHODS_H

#include "hand.h"

int isFlush( const Hand* );
int isStraight( const Hand* );
int isStraightFulsh( const Hand* );
int isRoyalFlush( const Hand* );
int isFourOfAKind( const Hand* );

char highestCard( const Hand* );

#endif // METHODS_H
