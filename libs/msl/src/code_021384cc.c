#include "code_021384cc.h"

#include "code_02134398.h"
#include "output_effect.h"

#pragma avoid_byte all

#include "code_02134b18.h"
#include "code_0213a460.h"

u32 gRandValue = 1;

const char *ScanParseSpec(const char *format, ScanSpec *outSpec) {
    ScanSpec localSpec = {0, 0, 0, 0, 0x7fffffff};
    const char *formatPointer = format + 1;
    int currentChar = *formatPointer;
    int hasModifier;
    int negated;
    int rangeEnd;
    int count;
    unsigned char *setPointer;
    unsigned char argKind;

    if (currentChar == '%') {
        localSpec.mSpecChar = currentChar;
        *outSpec = localSpec;
        return formatPointer + 1;
    }
    if (currentChar == '*') {
        localSpec.mStar = 1;
        currentChar = *++formatPointer;
    }
    if ((currentChar < 0 || currentChar >= 0x80) ? 0 : (gCharClassFlags[currentChar] & 8)) {
        localSpec.mMaxLength = 0;
        do {
            localSpec.mMaxLength = localSpec.mMaxLength * 10 + (currentChar - '0');
            currentChar = *++formatPointer;
        } while ((currentChar < 0 || currentChar >= 0x80) ? 0 : (gCharClassFlags[currentChar] & 8));
        if (localSpec.mMaxLength == 0) {
            localSpec.mSpecChar = 0xff;
            *outSpec = localSpec;
            return formatPointer + 1;
        }
        localSpec.mHasMaxLength = 1;
    }
    hasModifier = 1;
    switch (currentChar) {
        case 'h':
            localSpec.mArgKind = 2;
            if (formatPointer[1] == 'h') {
                localSpec.mArgKind = 1;
                currentChar = *++formatPointer;
            }
            break;
        case 'l':
            localSpec.mArgKind = 3;
            if (formatPointer[1] == 'l') {
                localSpec.mArgKind = 7;
                currentChar = *++formatPointer;
            }
            break;
        case 'L':
            localSpec.mArgKind = 9;
            break;
        case 'j':
            localSpec.mArgKind = 4;
            break;
        case 'z':
            localSpec.mArgKind = 5;
            break;
        case 't':
            localSpec.mArgKind = 6;
            break;
        default:
            hasModifier = 0;
            break;
    }
    if (hasModifier) {
        currentChar = *++formatPointer;
    }
    localSpec.mSpecChar = currentChar;
    switch (currentChar) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (localSpec.mArgKind == 9) {
                localSpec.mSpecChar = 0xff;
            }
            break;
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'f':
        case 'F':
        case 'g':
        case 'G':
            argKind = localSpec.mArgKind;
            if (argKind == 1 || argKind == 2 || (unsigned char) (argKind + 0xfc) <= 3) {
                localSpec.mSpecChar = 0xff;
            } else if (argKind == 3) {
                localSpec.mArgKind = 8;
            }
            break;
        case 'p':
            localSpec.mArgKind = 3;
            localSpec.mSpecChar = 'x';
            break;
        case 'c':
            if (localSpec.mArgKind == 3) {
                localSpec.mArgKind = 10;
            } else if (localSpec.mArgKind != 0) {
                localSpec.mSpecChar = 0xff;
            }
            break;
        case 's':
            if (localSpec.mArgKind == 3) {
                localSpec.mArgKind = 10;
            } else if (localSpec.mArgKind != 0) {
                localSpec.mSpecChar = 0xff;
            }
            for (count = 32, setPointer = localSpec.mCharSet; count > 0; count--) {
                *setPointer++ = 0xff;
            }
            localSpec.mCharSet[1] = 0xc1;
            localSpec.mCharSet[4] = 0xfe;
            break;
        case '[':
            if (localSpec.mArgKind == 3) {
                localSpec.mArgKind = 10;
            } else if (localSpec.mArgKind != 0) {
                localSpec.mSpecChar = 0xff;
            }
            currentChar = *++formatPointer;
            negated = 0;
            if (currentChar == '^') {
                currentChar = *++formatPointer;
                negated = 1;
            }
            if (currentChar == ']') {
                localSpec.mCharSet[']' >> 3] |= 1 << (']' & 7);
                currentChar = *++formatPointer;
            }
            while (currentChar != 0 && currentChar != ']') {
                localSpec.mCharSet[(unsigned char) currentChar >> 3] |= 1 << (currentChar & 7);
                if (formatPointer[1] == '-' && (rangeEnd = formatPointer[2]) != 0 && rangeEnd != ']') {
                    for (currentChar++; currentChar <= rangeEnd; currentChar++) {
                        localSpec.mCharSet[(unsigned char) currentChar >> 3] |= 1 << (currentChar & 7);
                    }
                    currentChar = *(formatPointer += 3);
                } else {
                    currentChar = *++formatPointer;
                }
            }
            if (currentChar == 0) {
                localSpec.mSpecChar = 0xff;
            } else if (negated) {
                for (count = 32, setPointer = localSpec.mCharSet; count > 0; count--, setPointer++) {
                    *setPointer = ~*setPointer;
                }
            }
            break;
        case 'n':
            break;
        default:
            localSpec.mSpecChar = 0xff;
            break;
    }
    *outSpec = localSpec;
    return formatPointer + 1;
}

static inline int IsScanSkippedChar(int character) {
    return (character < 0 || character >= 0x80) ? 0 : (gCharClassFlags[character] & 0x100);
}

int ScanWithSourceFunc(ScanReadCharFunc fn, ScanStringSource *source, const char *format, char *argList) {
    int consumedCount;
    int s32;
    long long s64;
    int assignedCount;
    int conversionCount;
    unsigned int u32;
    unsigned long long u64;
    int ch;
    unsigned char formatChar;
    char *destination;
    int base;
    char chb;
    int usedCount;
    int negative;
    int overflow;
    double doubleValue;
    ScanSpec spec;

    consumedCount = 0;
    assignedCount = 0;
    conversionCount = 0;
    while ((formatChar = *format) != 0) {
        if (IsScanSkippedChar(formatChar)) {
            do {
                format++;
                formatChar = *format;
            } while (IsScanSkippedChar(formatChar));
            while (chb = fn(source, 0, 0), IsScanSkippedChar(chb)) {
                consumedCount++;
            }
            fn(source, chb, 1);
            continue;
        }
        if (formatChar != '%') {
            chb = fn(source, 0, 0);
            if (formatChar != chb) {
                fn(source, chb, 1);
                goto exit;
            }
            format++;
            consumedCount++;
            continue;
        }
        format = ScanParseSpec(format, &spec);
        if (spec.mStar == 0 && spec.mSpecChar != '%') {
            argList += 4;
            destination = ((char **) argList)[-1];
        } else {
            destination = 0;
        }
        if (spec.mSpecChar != 'n') {
            if (fn(source, 0, 2) != 0) {
                goto exit;
            }
        }
        switch (spec.mSpecChar) {
            case 'd':
                base = 10;
                goto signed_int;
            case 'i':
                base = 0;
            signed_int:
                if (spec.mArgKind == 7) {
                    u64 = ScanInt64(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                } else {
                    u32 = ScanInt32(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                }
                if (usedCount == 0) {
                    goto exit;
                }
                consumedCount += usedCount;
                if (spec.mArgKind == 7) {
                    if (negative == 0) {
                        s64 = u64;
                    } else {
                        s64 = -u64;
                    }
                } else {
                    if (negative != 0) {
                        s32 = -u32;
                    } else {
                        s32 = u32;
                    }
                }
                if (destination != 0) {
                    switch (spec.mArgKind) {
                        case 0:
                            *(int *) destination = s32;
                            break;
                        case 1:
                            *destination = s32;
                            break;
                        case 2:
                            *(short *) destination = s32;
                            break;
                        case 3:
                            *(int *) destination = s32;
                            break;
                        case 4:
                            *(long long *) destination = s32;
                            break;
                        case 5:
                            *(int *) destination = s32;
                            break;
                        case 6:
                            *(int *) destination = s32;
                            break;
                        case 7:
                            *(long long *) destination = s64;
                            break;
                    }
                    assignedCount++;
                }
                conversionCount++;
                break;
            case 'o':
                base = 8;
                goto unsigned_int;
            case 'u':
                base = 10;
                goto unsigned_int;
            case 'X':
            case 'x':
                base = 16;
            unsigned_int:
                if (spec.mArgKind == 7) {
                    u64 = ScanInt64(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                } else {
                    u32 = ScanInt32(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                }
                if (usedCount == 0) {
                    goto exit;
                }
                consumedCount += usedCount;
                if (negative != 0) {
                    if (spec.mArgKind == 7) {
                        u64 = -u64;
                    } else {
                        u32 = -u32;
                    }
                }
                if (destination != 0) {
                    switch (spec.mArgKind) {
                        case 0:
                            *(unsigned int *) destination = u32;
                            break;
                        case 1:
                            *(unsigned char *) destination = u32;
                            break;
                        case 2:
                            *(unsigned short *) destination = u32;
                            break;
                        case 3:
                            *(unsigned int *) destination = u32;
                            break;
                        case 4:
                            *(unsigned long long *) destination = u32;
                            break;
                        case 5:
                            *(unsigned int *) destination = u32;
                            break;
                        case 6:
                            *(unsigned int *) destination = u32;
                            break;
                        case 7:
                            *(unsigned long long *) destination = u64;
                            break;
                    }
                    assignedCount++;
                }
                conversionCount++;
                break;
            case 'A':
            case 'E':
            case 'F':
            case 'G':
            case 'a':
            case 'e':
            case 'f':
            case 'g':
                doubleValue = ScanDouble(spec.mMaxLength, fn, source, &usedCount, &overflow);
                if (usedCount == 0) {
                    goto exit;
                }
                consumedCount += usedCount;
                if (destination != 0) {
                    switch (spec.mArgKind) {
                        case 0:
                            *(float *) destination = doubleValue;
                            break;
                        case 8:
                            *(double *) destination = doubleValue;
                            break;
                        case 9:
                            *(double *) destination = doubleValue;
                            break;
                    }
                    assignedCount++;
                }
                conversionCount++;
                break;
            case 'c':
                if (spec.mHasMaxLength == 0) {
                    spec.mMaxLength = 1;
                }
                if (destination != 0) {
                    usedCount = 0;
                    while (spec.mMaxLength-- != 0 && (ch = fn(source, 0, 0)) != -1) {
                        chb = ch;
                        if (spec.mArgKind == 10) {
                            mbtowc((u16 *) destination, &chb, 1);
                            destination += 1;
                        } else {
                            *destination++ = chb;
                        }
                        usedCount++;
                    }
                    chb = ch;
                    if (usedCount == 0) {
                        goto exit;
                    }
                    consumedCount += usedCount;
                    assignedCount++;
                } else {
                    usedCount = 0;
                    while (spec.mMaxLength-- != 0 && (ch = fn(source, 0, 0)) != -1) {
                        chb = ch;
                        usedCount++;
                    }
                    chb = ch;
                    if (usedCount == 0) {
                        goto exit;
                    }
                }
                conversionCount++;
                break;
            case '%':
                while (chb = fn(source, 0, 0), IsScanSkippedChar(chb)) {
                    consumedCount++;
                }
                if (chb != '%') {
                    fn(source, chb, 1);
                    goto exit;
                }
                consumedCount++;
                break;
            case 's':
                chb = fn(source, 0, 0);
                while (IsScanSkippedChar(chb)) {
                    consumedCount++;
                    chb = fn(source, 0, 0);
                }
                fn(source, chb, 1);
            case '[':
                if (destination != 0) {
                    usedCount = 0;
                    while (spec.mMaxLength-- != 0 && (ch = fn(source, 0, 0)) != -1) {
                        chb = ch;
                        if (!(spec.mCharSet[chb >> 3] & (1 << (chb & 7)))) {
                            break;
                        }
                        if (spec.mArgKind == 10) {
                            mbtowc((u16 *) destination, &chb, 1);
                            destination += 2;
                        } else {
                            *destination++ = chb;
                        }
                        usedCount++;
                    }
                    chb = ch;
                    if (usedCount == 0) {
                        fn(source, chb, 1);
                        goto exit;
                    }
                    consumedCount += usedCount;
                    if (spec.mArgKind == 10) {
                        *(short *) destination = 0;
                    } else {
                        *destination = 0;
                    }
                    assignedCount++;
                } else {
                    usedCount = 0;
                    while (spec.mMaxLength-- != 0 && (ch = fn(source, 0, 0)) != -1) {
                        chb = ch;
                        if (!(spec.mCharSet[chb >> 3] & (1 << (chb & 7)))) {
                            break;
                        }
                        usedCount++;
                    }
                    chb = ch;
                    if (usedCount == 0) {
                        fn(source, chb, 1);
                        break;
                    }
                    consumedCount += usedCount;
                }
                if (spec.mMaxLength >= 0) {
                    fn(source, chb, 1);
                }
                conversionCount++;
                break;
            case 'n':
                if (destination != 0) {
                    switch (spec.mArgKind) {
                        case 0:
                            *(int *) destination = consumedCount;
                            break;
                        case 2:
                            *(short *) destination = consumedCount;
                            break;
                        case 3:
                            *(int *) destination = consumedCount;
                            break;
                        case 1:
                            *destination = consumedCount;
                            break;
                        case 7:
                            *(long long *) destination = consumedCount;
                            break;
                    }
                }
                break;
            case 0xff:
            default:
                goto exit;
        }
    }
exit:
    if (fn(source, 0, 2) != 0 && conversionCount == 0) {
        return -1;
    }
    return assignedCount;
}

int ScanStringSourceOp(void *context, int character, int operation) {
    ScanStringSource *source;
    const char *text;
    u32 ch;

    source = context;
    switch (operation) {
        case 0:
            text = source->mNextChar;
            ch = *text;
            if (ch == 0) {
                source->mAtEnd = 1;
                return -1;
            }
            source->mNextChar = text + 1;
            return ch;
        case 1:
            if (source->mAtEnd == 0) {
                source->mNextChar--;
            } else {
                source->mAtEnd = 0;
            }
            return character;
        case 2:
            return source->mAtEnd;
        default:
            return 0;
    }
}

int vsscanf(const char *text, const char *format, char *args) {
    ScanStringSource loc;

    loc.mNextChar = text;
    if (text == 0 || *text == 0) {
        return -1;
    }
    loc.mAtEnd = 0;
    return ScanWithSourceFunc(ScanStringSourceOp, &loc, format, args);
}

int sscanf(const char *text, const char *format, ...) {
    char *ap;

    ap = (char *) (((u32) &format & ~3) + 4);
    return vsscanf(text, format, ap);
}

u32 rand(void) {
    gRandValue = gRandValue * 0x41c64e6d + 0x3039;
    return (gRandValue >> 16) & 0x7fff;
}

void srand(u32 seed) {
    gRandValue = seed;
}
