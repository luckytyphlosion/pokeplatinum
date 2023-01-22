#ifndef POKEPLATINUM_UNK_020790B0_H
#define POKEPLATINUM_UNK_020790B0_H

#include "struct_defs/struct_020790C4.h"

typedef enum MoveAttribute {
    MOVEATTRIBUTE_EFFECT = 0,
    MOVEATTRIBUTE_CLASS,
    MOVEATTRIBUTE_POWER,
    MOVEATTRIBUTE_TYPE,
    MOVEATTRIBUTE_ACCURACY,
    MOVEATTRIBUTE_PP,
    MOVEATTRIBUTE_EFFECT_CHANCE,
    MOVEATTRIBUTE_UNK7,
    MOVEATTRIBUTE_PRIORTY,
    MOVEATTRIBUTE_UNK9,
    MOVEATTRIBUTE_UNK10,
    MOVEATTRIBUTE_CONTEST_TYPE,
} MoveAttribute;

void LoadMoveTable(void * dest);
u32 GetMoveAttributeibute(int moveID, int attrno);
u8 GetMoveMaxPP(u16 moveID, u8 ppUps);
u32 GetMoveTableAttribute(MoveTable * moveTable, int attribute);

#endif // POKEPLATINUM_UNK_020790B0_H
