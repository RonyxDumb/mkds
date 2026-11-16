#include "scan_text_random.h"

#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"

#pragma avoid_byte all

#include "char_conversion.h"
#include "text_to_number.h"

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
            localSpec.mSpecChar = SCAN_SPEC_INVALID;
            *outSpec = localSpec;
            return formatPointer + 1;
        }
        localSpec.mHasMaxLength = 1;
    }
    hasModifier = 1;
    switch (currentChar) {
        case 'h':
            localSpec.mArgKind = SCAN_ARG_SHORT;
            if (formatPointer[1] == 'h') {
                localSpec.mArgKind = SCAN_ARG_CHAR;
                currentChar = *++formatPointer;
            }
            break;
        case 'l':
            localSpec.mArgKind = SCAN_ARG_LONG;
            if (formatPointer[1] == 'l') {
                localSpec.mArgKind = SCAN_ARG_LONG_LONG;
                currentChar = *++formatPointer;
            }
            break;
        case 'L':
            localSpec.mArgKind = SCAN_ARG_LONG_DOUBLE;
            break;
        case 'j':
            localSpec.mArgKind = SCAN_ARG_INTMAX;
            break;
        case 'z':
            localSpec.mArgKind = SCAN_ARG_SIZE;
            break;
        case 't':
            localSpec.mArgKind = SCAN_ARG_PTRDIFF;
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
            if (localSpec.mArgKind == SCAN_ARG_LONG_DOUBLE) {
                localSpec.mSpecChar = SCAN_SPEC_INVALID;
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
            if (argKind == SCAN_ARG_CHAR || argKind == SCAN_ARG_SHORT || (unsigned char) (argKind + 0xfc) <= 3) {
                localSpec.mSpecChar = SCAN_SPEC_INVALID;
            } else if (argKind == SCAN_ARG_LONG) {
                localSpec.mArgKind = SCAN_ARG_DOUBLE;
            }
            break;
        case 'p':
            localSpec.mArgKind = SCAN_ARG_LONG;
            localSpec.mSpecChar = 'x';
            break;
        case 'c':
            if (localSpec.mArgKind == SCAN_ARG_LONG) {
                localSpec.mArgKind = SCAN_ARG_WIDE;
            } else if (localSpec.mArgKind != SCAN_ARG_DEFAULT) {
                localSpec.mSpecChar = SCAN_SPEC_INVALID;
            }
            break;
        case 's':
            if (localSpec.mArgKind == SCAN_ARG_LONG) {
                localSpec.mArgKind = SCAN_ARG_WIDE;
            } else if (localSpec.mArgKind != SCAN_ARG_DEFAULT) {
                localSpec.mSpecChar = SCAN_SPEC_INVALID;
            }
            for (count = 32, setPointer = localSpec.mCharSet; count > 0; count--) {
                *setPointer++ = 0xff;
            }
            localSpec.mCharSet[1] = 0xc1;
            localSpec.mCharSet[4] = 0xfe;
            break;
        case '[':
            if (localSpec.mArgKind == SCAN_ARG_LONG) {
                localSpec.mArgKind = SCAN_ARG_WIDE;
            } else if (localSpec.mArgKind != SCAN_ARG_DEFAULT) {
                localSpec.mSpecChar = SCAN_SPEC_INVALID;
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
                localSpec.mSpecChar = SCAN_SPEC_INVALID;
            } else if (negated) {
                for (count = 32, setPointer = localSpec.mCharSet; count > 0; count--, setPointer++) {
                    *setPointer = ~*setPointer;
                }
            }
            break;
        case 'n':
            break;
        default:
            localSpec.mSpecChar = SCAN_SPEC_INVALID;
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
                goto CheckZetaInvokeBeta;
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
                goto CheckZetaInvokeBeta;
            }
        }
        switch (spec.mSpecChar) {
            case 'd':
                base = 10;
                goto signed_int;
            case 'i':
                base = 0;
            signed_int:
                if (spec.mArgKind == SCAN_ARG_LONG_LONG) {
                    u64 = ScanInt64(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                } else {
                    u32 = ScanInt32(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                }
                if (usedCount == 0) {
                    goto CheckZetaInvokeBeta;
                }
                consumedCount += usedCount;
                if (spec.mArgKind == SCAN_ARG_LONG_LONG) {
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
                        case SCAN_ARG_DEFAULT:
                            *(int *) destination = s32;
                            break;
                        case SCAN_ARG_CHAR:
                            *destination = s32;
                            break;
                        case SCAN_ARG_SHORT:
                            *(short *) destination = s32;
                            break;
                        case SCAN_ARG_LONG:
                            *(int *) destination = s32;
                            break;
                        case SCAN_ARG_INTMAX:
                            *(long long *) destination = s32;
                            break;
                        case SCAN_ARG_SIZE:
                            *(int *) destination = s32;
                            break;
                        case SCAN_ARG_PTRDIFF:
                            *(int *) destination = s32;
                            break;
                        case SCAN_ARG_LONG_LONG:
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
                if (spec.mArgKind == SCAN_ARG_LONG_LONG) {
                    u64 = ScanInt64(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                } else {
                    u32 = ScanInt32(base, spec.mMaxLength, fn, source, &usedCount, &negative, &overflow);
                }
                if (usedCount == 0) {
                    goto CheckZetaInvokeBeta;
                }
                consumedCount += usedCount;
                if (negative != 0) {
                    if (spec.mArgKind == SCAN_ARG_LONG_LONG) {
                        u64 = -u64;
                    } else {
                        u32 = -u32;
                    }
                }
                if (destination != 0) {
                    switch (spec.mArgKind) {
                        case SCAN_ARG_DEFAULT:
                            *(unsigned int *) destination = u32;
                            break;
                        case SCAN_ARG_CHAR:
                            *(unsigned char *) destination = u32;
                            break;
                        case SCAN_ARG_SHORT:
                            *(unsigned short *) destination = u32;
                            break;
                        case SCAN_ARG_LONG:
                            *(unsigned int *) destination = u32;
                            break;
                        case SCAN_ARG_INTMAX:
                            *(unsigned long long *) destination = u32;
                            break;
                        case SCAN_ARG_SIZE:
                            *(unsigned int *) destination = u32;
                            break;
                        case SCAN_ARG_PTRDIFF:
                            *(unsigned int *) destination = u32;
                            break;
                        case SCAN_ARG_LONG_LONG:
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
                    goto CheckZetaInvokeBeta;
                }
                consumedCount += usedCount;
                if (destination != 0) {
                    switch (spec.mArgKind) {
                        case SCAN_ARG_DEFAULT:
                            *(float *) destination = doubleValue;
                            break;
                        case SCAN_ARG_DOUBLE:
                            *(double *) destination = doubleValue;
                            break;
                        case SCAN_ARG_LONG_DOUBLE:
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
                        if (spec.mArgKind == SCAN_ARG_WIDE) {
                            mbtowc((u16 *) destination, &chb, 1);
                            destination += 1;
                        } else {
                            *destination++ = chb;
                        }
                        usedCount++;
                    }
                    chb = ch;
                    if (usedCount == 0) {
                        goto CheckZetaInvokeBeta;
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
                        goto CheckZetaInvokeBeta;
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
                    goto CheckZetaInvokeBeta;
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
                        if (spec.mArgKind == SCAN_ARG_WIDE) {
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
                        goto CheckZetaInvokeBeta;
                    }
                    consumedCount += usedCount;
                    if (spec.mArgKind == SCAN_ARG_WIDE) {
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
                        case SCAN_ARG_DEFAULT:
                            *(int *) destination = consumedCount;
                            break;
                        case SCAN_ARG_SHORT:
                            *(short *) destination = consumedCount;
                            break;
                        case SCAN_ARG_LONG:
                            *(int *) destination = consumedCount;
                            break;
                        case SCAN_ARG_CHAR:
                            *destination = consumedCount;
                            break;
                        case SCAN_ARG_LONG_LONG:
                            *(long long *) destination = consumedCount;
                            break;
                    }
                }
                break;
            case SCAN_SPEC_INVALID:
            default:
                goto CheckZetaInvokeBeta;
        }
    }
CheckZetaInvokeBeta:
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
        case SCAN_OP_READ:
            text = source->mNextChar;
            ch = *text;
            if (ch == 0) {
                source->mAtEnd = 1;
                return -1;
            }
            source->mNextChar = text + 1;
            return ch;
        case SCAN_OP_UNREAD:
            if (source->mAtEnd == 0) {
                source->mNextChar--;
            } else {
                source->mAtEnd = 0;
            }
            return character;
        case SCAN_OP_AT_END:
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
