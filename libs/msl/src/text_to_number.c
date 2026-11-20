#pragma avoid_byte all

#include "text_to_number.h"
#include "print_memory_multibyte_write.h"
#include "scan_text_random.h"
#include "wide_number_format.h"
#include "double_digits_math_functions.h"
#include "float_trap_dispatch.h"

const u8 gUpperCaseMap[128] = {
    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0xa,  0xb,  0xc,  0xd,  0xe,  0xf,  0x10, 0x11, 0x12,
    0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
    0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
    0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b,
    0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e,
    0x5f, 0x60, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51,
    0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f};
const u8 gLowerCaseMap[128] = {
    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0xa,  0xb,  0xc,  0xd,  0xe,  0xf,  0x10, 0x11, 0x12,
    0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
    0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
    0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
    0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x5b, 0x5c, 0x5d, 0x5e,
    0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71,
    0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f};
const u16 gCharClassFlags[128] = {
    4,     4,     4,     4,     4,     4,     4,     4,     4,     0x106, 0x104, 0x104, 0x104, 0x104, 4,     4,
    4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
    0x142, 0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,
    0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,
    0xd0,  0x651, 0x651, 0x651, 0x651, 0x651, 0x651, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251,
    0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0xd0,  0xd0,  0xd0,  0xd0,  0xd0,
    0xd0,  0x471, 0x471, 0x471, 0x471, 0x471, 0x471, 0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,
    0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0xd0,  0xd0,  0xd0,  0xd0,  4};

// Reads digits through readChar in the given base, at most maxChars of them.
u32 ScanInt32(int base, int maxChars, ScanReadCharFunc readChar, ScanStringSource *source, int *usedCount,
              int *negative, int *overflow) {
    int st;
    int consumed;
    int leadingSpaces;
    int currentChar;
    u32 acc;
    u32 lim;

    leadingSpaces = 0;
    *negative = *overflow = 0;
    st = SCAN_INT_STATE_READ_SIGN;
    consumed = leadingSpaces;
    acc = leadingSpaces;
    lim = leadingSpaces;
    if (base < 0 || base == 1 || base > 36 || maxChars < 1) {
        st = SCAN_INT_STATE_FAILED;
    } else {
        consumed++;
        currentChar = readChar(source, 0, SCAN_OP_READ);
    }
    if (base != 0) {
        lim = 0xffffffffU / base;
    }
    while (consumed <= maxChars && currentChar != -1 && !(st & SCAN_INT_STATES_STOPPED)) {
        switch (st) {
            case SCAN_INT_STATE_READ_SIGN:
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x100) {
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                    leadingSpaces++;
                } else {
                    if (currentChar == '+') {
                        consumed++;
                        currentChar = readChar(source, 0, SCAN_OP_READ);
                    } else if (currentChar == '-') {
                        consumed++;
                        currentChar = readChar(source, 0, SCAN_OP_READ);
                        *negative = 1;
                    }
                    st = SCAN_INT_STATE_AFTER_SIGN;
                }
                break;
            case SCAN_INT_STATE_AFTER_SIGN:
                if ((base == 0 || base == 16) && currentChar == '0') {
                    st = SCAN_INT_STATE_CHECK_RADIX_MARK;
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    st = SCAN_INT_STATE_FIRST_DIGIT;
                }
                break;
            case SCAN_INT_STATE_CHECK_RADIX_MARK:
                if (currentChar == 'X' || currentChar == 'x') {
                    base = 16;
                    st = SCAN_INT_STATE_FIRST_DIGIT;
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    if (base == 0) {
                        base = 8;
                    }
                    st = SCAN_INT_STATE_DIGITS;
                }
                break;
            case SCAN_INT_STATE_FIRST_DIGIT:
            case SCAN_INT_STATE_DIGITS:
                if (base == 0) {
                    base = 10;
                }
                if (lim == 0) {
                    lim = 0xffffffffU / base;
                }
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8) {
                    currentChar -= '0';
                    if (currentChar >= base) {
                        st = st == SCAN_INT_STATE_DIGITS ? SCAN_INT_STATE_ENDED : SCAN_INT_STATE_FAILED;
                        currentChar += '0';
                        break;
                    }
                } else {
                    if (!(((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x1) &&
                          ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) - 0x37 <
                              base)) {
                        st = st == SCAN_INT_STATE_DIGITS ? SCAN_INT_STATE_ENDED : SCAN_INT_STATE_FAILED;
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
                st = SCAN_INT_STATE_DIGITS;
                consumed++;
                currentChar = readChar(source, 0, SCAN_OP_READ);
                break;
        }
    }
    if (!(st & SCAN_INT_STATES_VALID)) {
        *usedCount = acc = 0;
    } else {
        *usedCount = consumed - 1 + leadingSpaces;
    }
    readChar(source, currentChar, SCAN_OP_UNREAD);
    return acc;
}

// Same as ScanInt32 with a 64-bit result.
u64 ScanInt64(int base, int maxChars, ScanReadCharFunc readChar, void *source, int *usedCount, int *negative,
              int *overflow) {
    int st;
    int consumed;
    int leadingSpaces;
    int currentChar;
    u64 acc;
    u64 lim;

    leadingSpaces = 0;
    *negative = *overflow = 0;
    st = SCAN_INT_STATE_READ_SIGN;
    consumed = leadingSpaces;
    acc = leadingSpaces;
    lim = leadingSpaces;
    if (base < 0 || base == 1 || base > 36 || maxChars < 1) {
        st = SCAN_INT_STATE_FAILED;
    } else {
        consumed++;
        currentChar = readChar(source, 0, SCAN_OP_READ);
    }
    if (base != 0) {
        lim = 0xffffffffffffffffULL / base;
    }
    while (consumed <= maxChars && currentChar != -1 && !(st & SCAN_INT_STATES_STOPPED)) {
        switch (st) {
            case SCAN_INT_STATE_READ_SIGN:
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x100) {
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                    leadingSpaces++;
                } else {
                    if (currentChar == '+') {
                        consumed++;
                        currentChar = readChar(source, 0, SCAN_OP_READ);
                    } else if (currentChar == '-') {
                        consumed++;
                        currentChar = readChar(source, 0, SCAN_OP_READ);
                        *negative = 1;
                    }
                    st = SCAN_INT_STATE_AFTER_SIGN;
                }
                break;
            case SCAN_INT_STATE_AFTER_SIGN:
                if ((base == 0 || base == 16) && currentChar == '0') {
                    st = SCAN_INT_STATE_CHECK_RADIX_MARK;
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    st = SCAN_INT_STATE_FIRST_DIGIT;
                }
                break;
            case SCAN_INT_STATE_CHECK_RADIX_MARK:
                if (currentChar == 'X' || currentChar == 'x') {
                    base = 16;
                    st = SCAN_INT_STATE_FIRST_DIGIT;
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    if (base == 0) {
                        base = 8;
                    }
                    st = SCAN_INT_STATE_DIGITS;
                }
                break;
            case SCAN_INT_STATE_FIRST_DIGIT:
            case SCAN_INT_STATE_DIGITS:
                if (base == 0) {
                    base = 10;
                }
                if (lim == 0) {
                    lim = 0xffffffffffffffffULL / base;
                }
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8) {
                    currentChar -= '0';
                    if (currentChar >= base) {
                        st = st == SCAN_INT_STATE_DIGITS ? SCAN_INT_STATE_ENDED : SCAN_INT_STATE_FAILED;
                        currentChar += '0';
                        break;
                    }
                } else {
                    if (!(((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x1) &&
                          ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) - 0x37 <
                              base)) {
                        st = st == SCAN_INT_STATE_DIGITS ? SCAN_INT_STATE_ENDED : SCAN_INT_STATE_FAILED;
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
                st = SCAN_INT_STATE_DIGITS;
                consumed++;
                currentChar = readChar(source, 0, SCAN_OP_READ);
                break;
        }
    }
    if (!(st & SCAN_INT_STATES_VALID)) {
        *usedCount = acc = 0;
    } else {
        *usedCount = consumed - 1 + leadingSpaces;
    }
    readChar(source, currentChar, SCAN_OP_UNREAD);
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

/* readChar is called as readChar(source, 0, SCAN_OP_READ) for each next value and as
 * readChar(source, currentChar, SCAN_OP_UNREAD) with a value already read. */
double ScanDouble(int maxChars, ScanReadCharFunc readChar, void *source, int *usedCount, int *overflow) {
    int state = SCAN_DOUBLE_STATE_READ_SIGN;
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
    currentChar = readChar(source, 0, SCAN_OP_READ);

    while (consumed <= maxChars && currentChar != -1 && !(state & SCAN_DOUBLE_STATES_STOPPED)) {
        switch (state) {
            case SCAN_DOUBLE_STATE_READ_SIGN:
                if ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x100) {
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                    leadingSpaces++;
                } else {
                    switch ((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) {
                        case '-':
                            negative = 1;
                            /* fall through */
                        case '+':
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                            sg = 1;
                            break;
                        case 'I':
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                            state = SCAN_DOUBLE_STATE_INFINITY;
                            break;
                        case 'N':
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                            state = SCAN_DOUBLE_STATE_NAN;
                            break;
                        default:
                            state = SCAN_DOUBLE_STATE_START_NUMBER;
                            break;
                    }
                }
                break;
            case SCAN_DOUBLE_STATE_INFINITY: {
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
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                }
                if (matchCount == 3 || matchCount == 8) {
                    if (negative) {
                        result = -gFloatInfinity;
                    } else {
                        result = gFloatInfinity;
                    }
                    *usedCount = leadingSpaces + matchCount + sg;
                    return result;
                }
                state = SCAN_DOUBLE_STATE_FAILED;
                break;
            }
            case SCAN_DOUBLE_STATE_NAN: {
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
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                }
                if (matchCount == 3 || matchCount == 4) {
                    if (matchCount == 4) {
                        while (nameLength < 32 &&
                               (((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8) ||
                                ((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x1) ||
                                currentChar == '.')) {
                            buf[nameLength++] = currentChar;
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        }
                        if (currentChar != ')') {
                            state = SCAN_DOUBLE_STATE_FAILED;
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
                state = SCAN_DOUBLE_STATE_FAILED;
                break;
            }
            case SCAN_DOUBLE_STATE_START_NUMBER:
                if (currentChar == '.') {
                    state = SCAN_DOUBLE_STATE_POINT_FIRST;
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = SCAN_DOUBLE_STATE_FAILED;
                } else if (currentChar == '0') {
                    int charValue;

                    consumed++;
                    currentChar = charValue = readChar(source, 0, SCAN_OP_READ);
                    if (((charValue < 0 || charValue >= 0x80) ? charValue : gUpperCaseMap[charValue]) == 'X') {
                        state = SCAN_DOUBLE_STATE_HEX;
                        hexState = SCAN_HEX_STATE_START;
                    } else {
                        state = SCAN_DOUBLE_STATE_LEADING_ZEROS;
                    }
                } else {
                    state = SCAN_DOUBLE_STATE_INT_DIGITS;
                }
                break;
            case SCAN_DOUBLE_STATE_LEADING_ZEROS:
                if (currentChar == '0') {
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    state = SCAN_DOUBLE_STATE_INT_DIGITS;
                }
                break;
            case SCAN_DOUBLE_STATE_INT_DIGITS:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    if (currentChar == '.') {
                        state = SCAN_DOUBLE_STATE_FRACTION_DIGITS;
                        consumed++;
                        currentChar = readChar(source, 0, SCAN_OP_READ);
                    } else {
                        state = SCAN_DOUBLE_STATE_EXPONENT_MARK;
                    }
                } else {
                    if (rec.mDigitCount < SCAN_DOUBLE_MAX_DIGITS) {
                        rec.mDigits[rec.mDigitCount++] = currentChar;
                    } else {
                        ea++;
                    }
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                }
                break;
            case SCAN_DOUBLE_STATE_POINT_FIRST:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = SCAN_DOUBLE_STATE_FAILED;
                } else {
                    state = SCAN_DOUBLE_STATE_FRACTION_DIGITS;
                }
                break;
            case SCAN_DOUBLE_STATE_FRACTION_DIGITS:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = SCAN_DOUBLE_STATE_EXPONENT_MARK;
                } else {
                    if (rec.mDigitCount < SCAN_DOUBLE_MAX_DIGITS) {
                        if (currentChar != '0' || rec.mDigitCount != 0) {
                            rec.mDigits[rec.mDigitCount++] = currentChar;
                        }
                        ea--;
                    }
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                }
                break;
            case SCAN_DOUBLE_STATE_EXPONENT_MARK:
                if (((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) == 'E') {
                    state = SCAN_DOUBLE_STATE_EXPONENT_SIGN;
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    state = SCAN_DOUBLE_STATE_DONE;
                }
                break;
            case SCAN_DOUBLE_STATE_EXPONENT_SIGN:
                if (currentChar == '+') {
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else if (currentChar == '-') {
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                    em = 1;
                }
                state = SCAN_DOUBLE_STATE_EXPONENT_FIRST;
                break;
            case SCAN_DOUBLE_STATE_EXPONENT_FIRST:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = SCAN_DOUBLE_STATE_FAILED;
                } else if (currentChar == '0') {
                    state = SCAN_DOUBLE_STATE_EXPONENT_ZEROS;
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    state = SCAN_DOUBLE_STATE_EXPONENT_DIGITS;
                }
                break;
            case SCAN_DOUBLE_STATE_EXPONENT_ZEROS:
                if (currentChar == '0') {
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                } else {
                    state = SCAN_DOUBLE_STATE_EXPONENT_DIGITS;
                }
                break;
            case SCAN_DOUBLE_STATE_EXPONENT_DIGITS:
                if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                    state = SCAN_DOUBLE_STATE_DONE;
                } else {
                    exponent = exponent * 10 + (currentChar - '0');
                    if (exponent > 0x7fff) {
                        *overflow = 1;
                    }
                    consumed++;
                    currentChar = readChar(source, 0, SCAN_OP_READ);
                }
                break;
            case SCAN_DOUBLE_STATE_HEX:
                switch (hexState) {
                    case SCAN_HEX_STATE_START:
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
                        hexState = SCAN_HEX_STATE_LEADING_ZEROS;
                        consumed++;
                        currentChar = readChar(source, 0, SCAN_OP_READ);
                        break;
                    case SCAN_HEX_STATE_LEADING_ZEROS:
                        if (currentChar == '0') {
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        } else {
                            hexState = SCAN_HEX_STATE_INT_DIGITS;
                        }
                        break;
                    case SCAN_HEX_STATE_INT_DIGITS:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x400)) {
                            if (currentChar == '.') {
                                hexState = SCAN_HEX_STATE_FRACTION_DIGITS;
                                consumed++;
                                currentChar = readChar(source, 0, SCAN_OP_READ);
                            } else {
                                hexState = SCAN_HEX_STATE_EXPONENT_MARK;
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
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        } else {
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        }
                        break;
                    case SCAN_HEX_STATE_FRACTION_DIGITS:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x400)) {
                            hexState = SCAN_HEX_STATE_EXPONENT_MARK;
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
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        } else {
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        }
                        break;
                    case SCAN_HEX_STATE_EXPONENT_MARK:
                        if (((currentChar < 0 || currentChar >= 0x80) ? currentChar : gUpperCaseMap[currentChar]) ==
                            'P') {
                            hexState = SCAN_HEX_STATE_EXPONENT_SIGN;
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        } else {
                            state = SCAN_DOUBLE_STATE_DONE;
                        }
                        break;
                    case SCAN_HEX_STATE_EXPONENT_SIGN:
                        if (currentChar == '-') {
                            hm = 1;
                        } else if (currentChar != '+') {
                            readChar(source, currentChar, SCAN_OP_UNREAD);
                            consumed--;
                        }
                        hexState = SCAN_HEX_STATE_EXPONENT_FIRST;
                        consumed++;
                        currentChar = readChar(source, 0, SCAN_OP_READ);
                        break;
                    case SCAN_HEX_STATE_EXPONENT_FIRST:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                            state = SCAN_DOUBLE_STATE_FAILED;
                        } else if (currentChar == '0') {
                            hexState = SCAN_HEX_STATE_EXPONENT_ZEROS;
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        } else {
                            hexState = SCAN_HEX_STATE_EXPONENT_DIGITS;
                        }
                        break;
                    case SCAN_HEX_STATE_EXPONENT_ZEROS:
                        if (currentChar == '0') {
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        } else {
                            hexState = SCAN_HEX_STATE_EXPONENT_DIGITS;
                        }
                        break;
                    case SCAN_HEX_STATE_EXPONENT_DIGITS:
                        if (!((currentChar < 0 || currentChar >= 0x80) ? 0 : gCharClassFlags[currentChar] & 0x8)) {
                            state = SCAN_DOUBLE_STATE_DONE;
                        } else {
                            he = he * 10 + (currentChar - '0');
                            if (exponent > 0x7fff) {
                                *overflow = 1;
                            }
                            consumed++;
                            currentChar = readChar(source, 0, SCAN_OP_READ);
                        }
                        break;
                }
                break;
        }
    }

    if (state != SCAN_DOUBLE_STATE_HEX ? !(state & SCAN_DOUBLE_STATES_VALID_END)
                                       : (consumed - 1 <= 2 || !(hexState & SCAN_HEX_STATES_VALID_END))) {
        *usedCount = 0;
    } else {
        *usedCount = consumed - 1 + leadingSpaces;
    }
    readChar(source, currentChar, SCAN_OP_UNREAD);

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
                return gDoubleInfinity;
            }
            return -gDoubleInfinity;
        }
        rec.mExponent = exponent;
        result = DigitCharsToDouble(&rec);
        if (result != 0.0 && result < 2.2250738585072014e-308) {
            *overflow = 1;
        } else if (result > 1.7976931348623157e+308) {
            *overflow = 1;
            result = gDoubleInfinity;
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
