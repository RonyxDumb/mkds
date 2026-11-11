#pragma avoid_byte all

#include "code_0213a460.h"
#include "code_02134398.h"
#include "code_021384cc.h"
#include "code_0213cae0.h"
#include "code_0213ee6c.h"

// Reads values through readChar(source, 0, 0), at most maxChars of them, in the given base. st is the state: 1, 2, 4, 8
// and 0x10 while reading, 0x20 or 0x40 once it stops. *usedCount gets the count used, *negative 1 after a minus,
// *overflow 1 when the value does not fit.
u32 ScanInt32(int base, int maxChars, Unk02138618Func readChar, ScanStringSource *source, int *usedCount, int *negative,
              int *overflow) {
    int st;
    int consumed;
    int leadingSpaces;
    int currentChar;
    u32 acc;
    u32 lim;

    leadingSpaces = 0;
    *negative = *overflow = 0;
    st = 1;
    consumed = leadingSpaces;
    acc = leadingSpaces;
    lim = leadingSpaces;
    if (base < 0 || base == 1 || base > 36 || maxChars < 1) {
        st = 0x40;
    } else {
        consumed++;
        currentChar = readChar(source, 0, 0);
    }
    if (base != 0) {
        lim = 0xffffffffU / base;
    }
    while (consumed <= maxChars && currentChar != -1 && !(st & 0x60)) {
        switch (st) {
            case 1:
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x100) {
                    currentChar = readChar(source, 0, 0);
                    leadingSpaces++;
                } else {
                    if (currentChar == '+') {
                        consumed++;
                        currentChar = readChar(source, 0, 0);
                    } else if (currentChar == '-') {
                        consumed++;
                        currentChar = readChar(source, 0, 0);
                        *negative = 1;
                    }
                    st = 2;
                }
                break;
            case 2:
                if ((base == 0 || base == 16) && currentChar == '0') {
                    st = 4;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    st = 8;
                }
                break;
            case 4:
                if (currentChar == 'X' || currentChar == 'x') {
                    base = 16;
                    st = 8;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    if (base == 0) {
                        base = 8;
                    }
                    st = 0x10;
                }
                break;
            case 8:
            case 0x10:
                if (base == 0) {
                    base = 10;
                }
                if (lim == 0) {
                    lim = 0xffffffffU / base;
                }
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8) {
                    currentChar -= '0';
                    if (currentChar >= base) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        currentChar += '0';
                        break;
                    }
                } else {
                    if (!(((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x1) &&
                          ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) - 0x37 <
                              base)) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        break;
                    }
                    currentChar = (currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar];
                    currentChar -= 0x37;
                }
                if (acc > lim) {
                    *overflow = 1;
                }
                acc *= base;
                if (currentChar > 0xffffffffU - acc) {
                    *overflow = 1;
                }
                acc += currentChar;
                st = 0x10;
                consumed++;
                currentChar = readChar(source, 0, 0);
                break;
        }
    }
    if (!(st & 0x34)) {
        *usedCount = acc = 0;
    } else {
        *usedCount = consumed - 1 + leadingSpaces;
    }
    readChar(source, currentChar, 1);
    return acc;
}

// Same as ScanInt32 with a 64-bit result.
u64 ScanInt64(int base, int maxChars, Unk02138618Func readChar, void *source, int *usedCount, int *negative,
              int *overflow) {
    int st;
    int consumed;
    int leadingSpaces;
    int currentChar;
    u64 acc;
    u64 lim;

    leadingSpaces = 0;
    *negative = *overflow = 0;
    st = 1;
    consumed = leadingSpaces;
    acc = leadingSpaces;
    lim = leadingSpaces;
    if (base < 0 || base == 1 || base > 36 || maxChars < 1) {
        st = 0x40;
    } else {
        consumed++;
        currentChar = readChar(source, 0, 0);
    }
    if (base != 0) {
        lim = 0xffffffffffffffffULL / base;
    }
    while (consumed <= maxChars && currentChar != -1 && !(st & 0x60)) {
        switch (st) {
            case 1:
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x100) {
                    currentChar = readChar(source, 0, 0);
                    leadingSpaces++;
                } else {
                    if (currentChar == '+') {
                        consumed++;
                        currentChar = readChar(source, 0, 0);
                    } else if (currentChar == '-') {
                        consumed++;
                        currentChar = readChar(source, 0, 0);
                        *negative = 1;
                    }
                    st = 2;
                }
                break;
            case 2:
                if ((base == 0 || base == 16) && currentChar == '0') {
                    st = 4;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    st = 8;
                }
                break;
            case 4:
                if (currentChar == 'X' || currentChar == 'x') {
                    base = 16;
                    st = 8;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    if (base == 0) {
                        base = 8;
                    }
                    st = 0x10;
                }
                break;
            case 8:
            case 0x10:
                if (base == 0) {
                    base = 10;
                }
                if (lim == 0) {
                    lim = 0xffffffffffffffffULL / base;
                }
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8) {
                    currentChar -= '0';
                    if (currentChar >= base) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        currentChar += '0';
                        break;
                    }
                } else {
                    if (!(((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x1) &&
                          ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) - 0x37 <
                              base)) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        break;
                    }
                    currentChar = (currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar];
                    currentChar -= 0x37;
                }
                if (acc > lim) {
                    *overflow = 1;
                }
                acc *= base;
                if (currentChar > 0xffffffffffffffffULL - acc) {
                    *overflow = 1;
                }
                acc += currentChar;
                st = 0x10;
                consumed++;
                currentChar = readChar(source, 0, 0);
                break;
        }
    }
    if (!(st & 0x34)) {
        *usedCount = acc = 0;
    } else {
        *usedCount = consumed - 1 + leadingSpaces;
    }
    readChar(source, currentChar, 1);
    return acc;
}

u32 strtoul(const char *string, const char **end, int base) {
    int usedCount;
    int neg;
    int ovf;
    ScanStringSource st;
    u32 value;

    st.mNextChar = string;
    st.mAtEnd = 0;
    value = ScanInt32(base, 0x7fffffff, ScanStringSourceOp, &st, &usedCount, &neg, &ovf);
    if (end != 0) {
        *end = string + usedCount;
    }
    if (ovf != 0) {
        gLibErrorCode = 0x22;
        return -1;
    }
    if (neg != 0) {
        value = -value;
    }
    return value;
}

long strtol(const char *string, const char **end, int base) {
    int usedCount;
    int neg;
    int ovf;
    ScanStringSource st;
    u32 value;

    st.mNextChar = string;
    st.mAtEnd = 0;
    value = ScanInt32(base, 0x7fffffff, ScanStringSourceOp, &st, &usedCount, &neg, &ovf);
    if (end != 0) {
        *end = string + usedCount;
    }
    if (ovf != 0 || (neg == 0 && value > 0x7fffffff) || (neg != 0 && value > 0x80000000)) {
        value = neg != 0 ? 0x80000000 : 0x7fffffff;
        gLibErrorCode = 0x22;
        return value;
    }
    if (neg != 0) {
        value = -value;
    }
    return value;
}

long StrtolBase10(const char *string) {
    return strtol(string, 0, 10);
}

/* readChar is called as readChar(source, 0, 0) for each next value and as readChar(source, currentChar, 1) with a value
 * already read. */
double ScanDouble(int maxChars, Unk02138618Func readChar, void *source, int *usedCount, int *overflow) {
    int state = 1;
    int hexState = 0;
    int consumed = 0;
    int currentChar;
    int leadingSpaces = 0;
    int negative;
    int em;
    int exponent;
    int ea;
    int sg;
    char *hp;
    char *hz;
    u32 lim;
    int he;
    int hk;
    int hm;
    u32 hd;
    double result;
    DigitRecord rec = {0};
    char hb[8];

    negative = 0;
    *overflow = 0;
    em = 0;
    exponent = 0;
    ea = 0;
    sg = 0;
    he = 0;
    hm = 0;
    hd = 0;
    hz = hb;
    consumed++;
    currentChar = readChar(source, 0, 0);

    while (consumed <= maxChars && currentChar != -1 && !(state & 0x1800)) {
        switch (state) {
            case 1:
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x100) {
                    currentChar = readChar(source, 0, 0);
                    leadingSpaces++;
                } else {
                    switch ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) {
                        case '-':
                            negative = 1;
                            /* fall through */
                        case '+':
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                            sg = 1;
                            break;
                        case 'I':
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                            state = 0x4000;
                            break;
                        case 'N':
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                            state = 0x2000;
                            break;
                        default:
                            state = 2;
                            break;
                    }
                }
                break;
            case 0x4000: {
                int matchCount = 1;
                char pattern[9] = "INFINITY";
                char *patternCursor;

                patternCursor = pattern + 1;
                while (matchCount < 8 &&
                       *patternCursor ==
                           ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar])) {
                    patternCursor++;
                    matchCount++;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                }
                if (matchCount == 3 || matchCount == 8) {
                    if (negative) {
                        result = -data_0216ec98;
                    } else {
                        result = data_0216ec98;
                    }
                    *usedCount = leadingSpaces + matchCount + sg;
                    return result;
                }
                state = 0x1000;
                break;
            }
            case 0x2000: {
                int matchCount = 1;
                int nameLength = 0;
                char pattern[5] = "NAN(";
                char buf[32] = {0};
                char *patternCursor;

                patternCursor = pattern + 1;
                while (matchCount < 4 &&
                       *patternCursor ==
                           ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar])) {
                    patternCursor++;
                    matchCount++;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                }
                if (matchCount == 3 || matchCount == 4) {
                    if (matchCount == 4) {
                        while (nameLength < 32 &&
                               (((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8) ||
                                ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x1) ||
                                currentChar == '.')) {
                            buf[nameLength++] = currentChar;
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        }
                        if (currentChar != ')') {
                            state = 0x1000;
                            break;
                        }
                        nameLength++;
                    }
                    buf[nameLength] = 0;
                    if (negative) {
                        result = -nan(buf);
                    } else {
                        result = nan(buf);
                    }
                    *usedCount = leadingSpaces + matchCount + nameLength + sg;
                    return result;
                }
                state = 0x1000;
                break;
            }
            case 2:
                if (currentChar == '.') {
                    state = 0x10;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = 0x1000;
                } else if (currentChar == '0') {
                    int charValue;

                    consumed++;
                    currentChar = charValue = readChar(source, 0, 0);
                    if (((charValue < 0 || charValue >= 0x80) ? charValue : gUpperCaseMap[charValue]) == 'X') {
                        state = 0x8000;
                        hexState = 1;
                    } else {
                        state = 4;
                    }
                } else {
                    state = 8;
                }
                break;
            case 4:
                if (currentChar == '0') {
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    state = 8;
                }
                break;
            case 8:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    if (currentChar == '.') {
                        state = 0x20;
                        consumed++;
                        currentChar = readChar(source, 0, 0);
                    } else {
                        state = 0x40;
                    }
                } else {
                    if (rec.mDigitCount < 20) {
                        rec.mDigits[rec.mDigitCount++] = currentChar;
                    } else {
                        ea++;
                    }
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                }
                break;
            case 0x10:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = 0x1000;
                } else {
                    state = 0x20;
                }
                break;
            case 0x20:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = 0x40;
                } else {
                    if (rec.mDigitCount < 20) {
                        if (currentChar != '0' || rec.mDigitCount != 0) {
                            rec.mDigits[rec.mDigitCount++] = currentChar;
                        }
                        ea--;
                    }
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                }
                break;
            case 0x40:
                if (((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) == 'E') {
                    state = 0x80;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    state = 0x800;
                }
                break;
            case 0x80:
                if (currentChar == '+') {
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else if (currentChar == '-') {
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                    em = 1;
                }
                state = 0x100;
                break;
            case 0x100:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = 0x1000;
                } else if (currentChar == '0') {
                    state = 0x200;
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    state = 0x400;
                }
                break;
            case 0x200:
                if (currentChar == '0') {
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                } else {
                    state = 0x400;
                }
                break;
            case 0x400:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = 0x800;
                } else {
                    exponent = exponent * 10 + (currentChar - '0');
                    if (exponent > 0x7fff) {
                        *overflow = 1;
                    }
                    consumed++;
                    currentChar = readChar(source, 0, 0);
                }
                break;
            case 0x8000:
                switch (hexState) {
                    case 1:
                        hz[0] = 0;
                        hz[1] = 0;
                        hz[2] = 0;
                        hz[3] = 0;
                        hz[4] = 0;
                        hz[5] = 0;
                        hz[6] = 0;
                        hz[7] = 0;
                        hp = hz;
                        lim = 14;
                        hd = 0;
                        hk = 0;
                        hexState = 2;
                        consumed++;
                        currentChar = readChar(source, 0, 0);
                        break;
                    case 2:
                        if (currentChar == '0') {
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        } else {
                            hexState = 4;
                        }
                        break;
                    case 4:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x400)) {
                            if (currentChar == '.') {
                                hexState = 8;
                                consumed++;
                                currentChar = readChar(source, 0, 0);
                            } else {
                                hexState = 0x10;
                            }
                        } else if (hd < lim) {
                            u8 hexByte;
                            u8 nibble;
                            int upperChar;

                            hd++;
                            hexByte = hp[hk / 2];
                            upperChar =
                                (currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar];
                            nibble = upperChar >= 'A' ? upperChar - 0x37 : upperChar - '0';
                            if (hk % 2) {
                                hexByte |= nibble;
                            } else {
                                hexByte |= (u8) (nibble << 4);
                            }
                            hp[hk++ / 2] = hexByte;
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        } else {
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        }
                        break;
                    case 8:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x400)) {
                            hexState = 0x10;
                        } else if (hd < lim) {
                            u8 hexByte;
                            u8 nibble;
                            int upperChar;

                            hexByte = hp[hk / 2];
                            upperChar =
                                (currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar];
                            nibble = upperChar >= 'A' ? upperChar - 0x37 : upperChar - '0';
                            if (hk % 2) {
                                hexByte |= nibble;
                            } else {
                                hexByte |= (u8) (nibble << 4);
                            }
                            hp[hk++ / 2] = hexByte;
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        } else {
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        }
                        break;
                    case 0x10:
                        if (((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) ==
                            'P') {
                            hexState = 0x20;
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        } else {
                            state = 0x800;
                        }
                        break;
                    case 0x20:
                        if (currentChar == '-') {
                            hm = 1;
                        } else if (currentChar != '+') {
                            readChar(source, currentChar, 1);
                            consumed--;
                        }
                        hexState = 0x40;
                        consumed++;
                        currentChar = readChar(source, 0, 0);
                        break;
                    case 0x40:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                            state = 0x1000;
                        } else if (currentChar == '0') {
                            hexState = 0x80;
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        } else {
                            hexState = 0x100;
                        }
                        break;
                    case 0x80:
                        if (currentChar == '0') {
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        } else {
                            hexState = 0x100;
                        }
                        break;
                    case 0x100:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                            state = 0x800;
                        } else {
                            he = he * 10 + (currentChar - '0');
                            if (exponent > 0x7fff) {
                                *overflow = 1;
                            }
                            consumed++;
                            currentChar = readChar(source, 0, 0);
                        }
                        break;
                }
                break;
        }
    }

    if (state != 0x8000 ? !(state & 0xe2c) : (consumed - 1 <= 2 || !(hexState & 0x18e))) {
        *usedCount = 0;
    } else {
        *usedCount = consumed - 1 + leadingSpaces;
    }
    readChar(source, currentChar, 1);

    if (hexState == 0) {
        int digitIndex;
        char *digitCursor;

        if (em) {
            exponent = -exponent;
        }
        digitIndex = rec.mDigitCount;
        digitCursor = &rec.mDigits[digitIndex];
        while (digitIndex-- != 0 && *--digitCursor == '0') {
            ea++;
        }
        rec.mDigitCount = digitIndex + 1;
        if (rec.mDigitCount == 0) {
            rec.mDigits[rec.mDigitCount++] = '0';
        }
        exponent += ea;
        if (exponent < -0x8000 || exponent > 0x7fff) {
            *overflow = 1;
        }
        if (*overflow) {
            if (em) {
                return 0.0;
            }
            if (!negative) {
                return data_0216eca0;
            }
            return -data_0216eca0;
        }
        rec.mExponent = exponent;
        result = DigitCharsToDouble(&rec);
        if (result != 0.0 && result < 2.2250738585072014e-308) {
            *overflow = 1;
        } else if (result > 1.7976931348623157e+308) {
            *overflow = 1;
            result = data_0216eca0;
        }
        if (negative && (state & 0xe2c)) {
            result = -result;
        }
        return result;
    } else {
        u32 leadingZeros;
        u32 bitIndex;
        u32 bitPos;
        u8 *outBytes;
        u8 byteValue;
        int byteIndex;
        u8 carry;
        u32 shift;
        u32 biasedExponent;
        double hexValue;

        outBytes = (u8 *) &hexValue;
        if (hm) {
            he = -he;
        }
        he += hd * 4;
        for (leadingZeros = 0; leadingZeros < 4 && !(hb[0] & (0x80 >> leadingZeros)); leadingZeros++) {
            he--;
        }
        leadingZeros++;
        if (leadingZeros != 0) {
            carry = 0;
            for (hp = hb + 7; hp >= hb; hp--) {
                byteValue = *hp;
                *hp = carry | (byteValue << leadingZeros);
                carry = byteValue >> (8 - leadingZeros);
            }
        }
        outBytes[0] = 0;
        outBytes[1] = 0;
        outBytes[2] = 0;
        outBytes[3] = 0;
        outBytes[4] = 0;
        outBytes[5] = 0;
        outBytes[6] = 0;
        outBytes[7] = 0;
        for (bitIndex = 0, bitPos = 12; bitIndex < 52; bitIndex += 8) {
            byteValue = hb[bitIndex / 8];
            if (bitIndex + 8 > 52) {
                byteValue &= 0xff << (52 - bitIndex);
            }
            shift = bitPos % 8;
            outBytes[bitPos / 8] |= (u8) (byteValue >> shift);
            bitPos += 8;
            outBytes[bitPos / 8] |= (u8) (byteValue << (8 - shift));
        }
        biasedExponent = he + 0x3fe;
        if (biasedExponent & -0x800) {
            *overflow = 1;
            return 0.0;
        }
        outBytes[0] |= (biasedExponent << 21) >> 25;
        outBytes[1] |= (biasedExponent << 21) >> 17;
        if (negative) {
            outBytes[0] |= 0x80;
        }
        for (byteIndex = 0; byteIndex < 4; byteIndex++) {
            byteValue = outBytes[byteIndex];
            outBytes[byteIndex] = outBytes[7 - byteIndex];
            outBytes[7 - byteIndex] = byteValue;
        }
        return *(double *) outBytes;
    }
}

double strtod(const char *string, const char **end) {
    int usedCount;
    int ovf;
    ScanStringSource st;
    double value;
    double absValue;

    st.mNextChar = string;
    st.mAtEnd = 0;
    value = ScanDouble(0x7fffffff, ScanStringSourceOp, &st, &usedCount, &ovf);
    if (end != 0) {
        *end = string + usedCount;
    }
    absValue = fabs(value);
    if (ovf != 0 || (value != 0.0 && (absValue < 2.2250738585072014e-308 || absValue > 1.7976931348623157e308))) {
        gLibErrorCode = 0x22;
    }
    return value;
}
