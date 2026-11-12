#include "code_02133da8.h"
#include "code_021423e4.h"
#pragma avoid_byte all

#include "code_02134008.h"
#include "code_02139e20.h"

WordPair FloatTrapDispatch(WordPair firstPair, WordPair secondPair, u32 statusFlags) {
    FloatTrapTable *floatTrapTable;
    FloatTrapHandlerFunc fn;

    floatTrapTable = GetFloatTrapTable();
    if ((statusFlags & 0xc00000) == 0) {
        statusFlags |= FloatStatusClearXor(0, 0) & 0xc00000;
    }
    switch (statusFlags & 0x7c000000) {
        case 0x40000000:
            fn = floatTrapTable->mHandlers[4];
            break;
        case 0x04000000:
            fn = floatTrapTable->mHandlers[0];
            break;
        case 0x10000000:
            fn = floatTrapTable->mHandlers[2];
            break;
        case 0x20000000:
            fn = floatTrapTable->mHandlers[3];
            break;
        case 0x08000000:
            fn = floatTrapTable->mHandlers[1];
            break;
        default:
            fn = 0;
            break;
    }
    if (fn == 0) {
        raise(2);
    }
    return fn(firstPair, secondPair, statusFlags);
}

u32 FloatTrapWordToWord(u32 word, u32 statusFlags) {
    WordPair operand;
    WordPair result;

    operand.mLow = word;
    result = FloatTrapDispatch(operand, operand, statusFlags);
    return result.mLow;
}

u32 FloatTrapPairToWord(u32 low, u32 high, u32 statusFlags) {
    WordPair operand;
    WordPair result;

    operand.mLow = low;
    operand.mHigh = high;
    result = FloatTrapDispatch(operand, operand, statusFlags);
    return result.mLow;
}

u64 FloatTrapWordToPair(u32 word, u32 statusFlags) {
    WordPair operand;
    WordPair result;

    operand.mLow = word;
    result = FloatTrapDispatch(operand, operand, statusFlags);
    return *(u64 *) &result;
}

u64 FloatTrapPairToPair(u32 low, u32 high, u32 statusFlags) {
    WordPair operand;
    WordPair result;

    operand.mLow = low;
    operand.mHigh = high;
    result = FloatTrapDispatch(operand, operand, statusFlags);
    return *(u64 *) &result;
}

u32 FloatTrapWordWordToWord(u32 firstWord, u32 secondWord, u32 statusFlags) {
    WordPair firstOperand;
    WordPair secondOperand;
    WordPair result;

    firstOperand.mLow = firstWord;
    secondOperand.mLow = secondWord;
    result = FloatTrapDispatch(firstOperand, secondOperand, statusFlags);
    return result.mLow;
}

u64 FloatTrapPairPairToPair(u32 firstLow, u32 firstHigh, u32 secondLow, u32 secondHigh, u32 statusFlags) {
    WordPair firstOperand;
    WordPair secondOperand;
    WordPair result;

    firstOperand.mLow = firstLow;
    firstOperand.mHigh = firstHigh;
    secondOperand.mLow = secondLow;
    secondOperand.mHigh = secondHigh;
    result = FloatTrapDispatch(firstOperand, secondOperand, statusFlags);
    return *(u64 *) &result;
}

u32 FloatTrapPairPairToWord(u32 firstLow, u32 firstHigh, u32 secondLow, u32 secondHigh, u32 statusFlags) {
    WordPair firstOperand;
    WordPair secondOperand;
    WordPair result;

    firstOperand.mLow = firstLow;
    firstOperand.mHigh = firstHigh;
    secondOperand.mLow = secondLow;
    secondOperand.mHigh = secondHigh;
    result = FloatTrapDispatch(firstOperand, secondOperand, statusFlags);
    return result.mLow;
}
