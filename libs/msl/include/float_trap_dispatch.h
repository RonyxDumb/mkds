#pragma once

#include "types.h"

// Two words passed and returned by value.
typedef union WordPair {
    struct {
        /* 00 */ u32 mLow;
        /* 04 */ u32 mHigh;
    };
    u64 mWhole;
} WordPair;

typedef WordPair (*FloatTrapHandlerFunc)(WordPair firstPair, WordPair secondPair, u32 statusFlags);

// The floating point trap handlers; FloatTrapDispatch calls one of the five mHandlers.
typedef struct FloatTrapTable {
    /* 00 */ u32 mUnk_00;
    /* 04 */ FloatTrapHandlerFunc mHandlers[5];
} FloatTrapTable;

u32 FloatTrapPairPairToWord(u32 firstLow, u32 firstHigh, u32 secondLow, u32 secondHigh, u32 statusFlags);
u64 FloatTrapPairPairToPair(u32 firstLow, u32 firstHigh, u32 secondLow, u32 secondHigh, u32 statusFlags);
u32 FloatTrapWordWordToWord(u32 firstWord, u32 secondWord, u32 statusFlags);
u64 FloatTrapPairToPair(u32 low, u32 high, u32 statusFlags);
u64 FloatTrapWordToPair(u32 word, u32 statusFlags);
u32 FloatTrapPairToWord(u32 low, u32 high, u32 statusFlags);
u32 FloatTrapWordToWord(u32 word, u32 statusFlags);
WordPair FloatTrapDispatch(WordPair firstPair, WordPair secondPair, u32 statusFlags);

// Used by three functions of this file, by PowBody (which stores 33 there) and by overlay 0.
extern int gLibErrorCode;
