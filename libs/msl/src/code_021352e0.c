#pragma avoid_byte all

#include "code_021352e0.h"
#include "code_02134b18.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0213ee6c.h"

#pragma explicit_zero_data on
char gLocaleEmptyString[] = "";
#pragma explicit_zero_data off
char gLocaleTimeFormatHMS[] = "%T";
char gLocaleAmPmNames[] = "AM|PM";
CharConversionFunctions gCharConversionFunctions = {MbtowcSingleByte, WctombSingleByte};
char gLocaleDateFormat[] = "%m/%d/%y";
CharConversion gCharConversion = {gLocaleTimeStrings, gLocaleCharInfo, &gCharConversionFunctions};
char gLocaleDateTimeFormat[] = "%a %b %e %T %Y";
char gLocaleDayNames[] = "Sun|Sunday|Mon|Monday|Tue|Tuesday|Wed|Wednesday|Thu|Thursday|Fri|Friday|Sat|Saturday";
char gLocaleMonthNames[] = "Jan|January|Feb|February|Mar|March|Apr|April|May|May|Jun|June|Jul|July|Aug|August|Sep|"
                           "September|Oct|October|Nov|November|Dec|December";
u16 gLocaleNameOffsets[58] = {2,  4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
                              42, 44, 46, 48, 50, 52, 0,  0,  0,  0,  0,  0,  1,  3,  5,  7,  9,  11, 13, 15,
                              17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51};
void *gLocaleCharInfo[4] = {(void *) 0x41, (void *) 0x3a, NULL, gLocaleNameOffsets};
const char *gLocaleTimeStrings[8] = {gLocaleAmPmNames,  gLocaleDateTimeFormat, gLocaleTime12Format,
                                     gLocaleDateFormat, gLocaleTimeFormatHMS,  gLocaleDayNames,
                                     gLocaleMonthNames, gLocaleEmptyString};
char gLocaleTime12Format[] = "%I:%M:%S %p";

const char *FormatParseSpec(const char *format, char **argList, FormatSpec *buf) {
    const char *cursor;
    FormatSpec parsed;
    int currentChar;
    int matched;
    int widthArg;

    parsed.mPadKind = FORMAT_PAD_SPACES;
    parsed.mSignKind = FORMAT_SIGN_NONE;
    parsed.mHasDot = 0;
    parsed.mHash = 0;
    parsed.mArgKind = FORMAT_ARG_DEFAULT;
    parsed.mMinLength = 0;
    parsed.mPrecision = 0;
    cursor = format + 1;
    currentChar = *cursor;
    if (currentChar == '%') {
        parsed.mSpecChar = currentChar;
        *buf = parsed;
        return cursor + 1;
    }
    for (;;) {
        matched = 1;
        switch (currentChar) {
            case '-':
                parsed.mPadKind = FORMAT_PAD_LEFT_ALIGN;
                break;
            case '+':
                parsed.mSignKind = FORMAT_SIGN_PLUS;
                break;
            case ' ':
                if (parsed.mSignKind != FORMAT_SIGN_PLUS) {
                    parsed.mSignKind = FORMAT_SIGN_SPACE;
                }
                break;
            case '#':
                parsed.mHash = 1;
                break;
            case '0':
                if (parsed.mPadKind != FORMAT_PAD_LEFT_ALIGN) {
                    parsed.mPadKind = FORMAT_PAD_ZEROS;
                }
                break;
            default:
                matched = 0;
                break;
        }
        if (!matched) {
            break;
        }
        currentChar = *++cursor;
    }
    if (currentChar == '*') {
        *argList += 4;
        widthArg = ((int *) *argList)[-1];
        parsed.mMinLength = widthArg;
        if (widthArg < 0) {
            parsed.mPadKind = FORMAT_PAD_LEFT_ALIGN;
            parsed.mMinLength = -widthArg;
        }
        currentChar = *++cursor;
    } else {
        while ((currentChar < 0 || currentChar >= 0x80) ? 0 : (gCharClassFlags[currentChar] & 8)) {
            parsed.mMinLength = parsed.mMinLength * 10 + (currentChar - '0');
            currentChar = *++cursor;
        }
    }
    if (parsed.mMinLength > FORMAT_MAX_LENGTH) {
        parsed.mSpecChar = FORMAT_SPEC_INVALID;
        *buf = parsed;
        return cursor + 1;
    }
    if (currentChar == '.') {
        parsed.mHasDot = 1;
        currentChar = *++cursor;
        if (currentChar == '*') {
            *argList += 4;
            parsed.mPrecision = ((int *) *argList)[-1];
            if (parsed.mPrecision < 0) {
                parsed.mHasDot = 0;
            }
            currentChar = *++cursor;
        } else {
            while ((currentChar < 0 || currentChar >= 0x80) ? 0 : (gCharClassFlags[currentChar] & 8)) {
                parsed.mPrecision = parsed.mPrecision * 10 + (currentChar - '0');
                currentChar = *++cursor;
            }
        }
    }
    matched = 1;
    switch (currentChar) {
        case 'h':
            parsed.mArgKind = FORMAT_ARG_SHORT;
            if (cursor[1] == 'h') {
                parsed.mArgKind = FORMAT_ARG_CHAR;
                currentChar = *++cursor;
            }
            break;
        case 'l':
            parsed.mArgKind = FORMAT_ARG_LONG;
            if (cursor[1] == 'l') {
                parsed.mArgKind = FORMAT_ARG_LONG_LONG;
                currentChar = *++cursor;
            }
            break;
        case 'L':
            parsed.mArgKind = FORMAT_ARG_LONG_DOUBLE;
            break;
        case 'j':
            parsed.mArgKind = FORMAT_ARG_INTMAX;
            break;
        case 'z':
            parsed.mArgKind = FORMAT_ARG_SIZE;
            break;
        case 't':
            parsed.mArgKind = FORMAT_ARG_PTRDIFF;
            break;
        default:
            matched = 0;
            break;
    }
    if (matched) {
        currentChar = *++cursor;
    }
    parsed.mSpecChar = currentChar;
    switch (currentChar) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (parsed.mArgKind == FORMAT_ARG_LONG_DOUBLE) {
                parsed.mSpecChar = FORMAT_SPEC_INVALID;
            } else if (parsed.mHasDot == 0) {
                parsed.mPrecision = 1;
            } else if (parsed.mPadKind == FORMAT_PAD_ZEROS) {
                parsed.mPadKind = FORMAT_PAD_SPACES;
            }
            break;
        case 'f':
        case 'F':
            if (parsed.mArgKind == FORMAT_ARG_SHORT || parsed.mArgKind == FORMAT_ARG_INTMAX ||
                parsed.mArgKind == FORMAT_ARG_SIZE || parsed.mArgKind == FORMAT_ARG_PTRDIFF ||
                parsed.mArgKind == FORMAT_ARG_LONG_LONG) {
                parsed.mSpecChar = FORMAT_SPEC_INVALID;
            } else if (parsed.mHasDot == 0) {
                parsed.mPrecision = FORMAT_FLOAT_DEFAULT_PRECISION;
            }
            break;
        case 'a':
        case 'A':
            if (parsed.mHasDot == 0) {
                parsed.mPrecision = FORMAT_HEX_FLOAT_DEFAULT_PRECISION;
            }
            if (parsed.mArgKind == FORMAT_ARG_SHORT || parsed.mArgKind == FORMAT_ARG_INTMAX ||
                parsed.mArgKind == FORMAT_ARG_SIZE || parsed.mArgKind == FORMAT_ARG_PTRDIFF ||
                parsed.mArgKind == FORMAT_ARG_LONG_LONG || parsed.mArgKind == FORMAT_ARG_CHAR) {
                parsed.mSpecChar = FORMAT_SPEC_INVALID;
            }
            break;
        case 'g':
        case 'G':
            if (parsed.mPrecision == 0) {
                parsed.mPrecision = 1;
            }
        case 'e':
        case 'E':
            if (parsed.mArgKind == FORMAT_ARG_SHORT || parsed.mArgKind == FORMAT_ARG_INTMAX ||
                parsed.mArgKind == FORMAT_ARG_SIZE || parsed.mArgKind == FORMAT_ARG_PTRDIFF ||
                parsed.mArgKind == FORMAT_ARG_LONG_LONG || parsed.mArgKind == FORMAT_ARG_CHAR) {
                parsed.mSpecChar = FORMAT_SPEC_INVALID;
            } else if (parsed.mHasDot == 0) {
                parsed.mPrecision = FORMAT_FLOAT_DEFAULT_PRECISION;
            }
            break;
        case 'p':
            parsed.mSpecChar = 'x';
            parsed.mHash = 1;
            parsed.mArgKind = FORMAT_ARG_LONG;
            parsed.mPrecision = FORMAT_POINTER_DIGITS;
            break;
        case 'c':
            if (parsed.mArgKind == FORMAT_ARG_LONG) {
                parsed.mArgKind = FORMAT_ARG_WIDE;
            } else if (parsed.mHasDot != 0 || parsed.mArgKind != FORMAT_ARG_DEFAULT) {
                parsed.mSpecChar = FORMAT_SPEC_INVALID;
            }
            break;
        case 's':
            if (parsed.mArgKind == FORMAT_ARG_LONG) {
                parsed.mArgKind = FORMAT_ARG_WIDE;
            } else if (parsed.mArgKind != FORMAT_ARG_DEFAULT) {
                parsed.mSpecChar = FORMAT_SPEC_INVALID;
            }
            break;
        case 'n':
            if (parsed.mArgKind == FORMAT_ARG_LONG_DOUBLE) {
                parsed.mSpecChar = FORMAT_SPEC_INVALID;
            }
            break;
        default:
            parsed.mSpecChar = FORMAT_SPEC_INVALID;
            break;
    }
    *buf = parsed;
    return cursor + 1;
}

char *FormatInt32(unsigned long value, char *end, FormatSpec spec) {
    int neg;
    int width;
    u8 alt;
    u8 sign;
    int digit;
    int base;
    char *cursor;
    int cnt;
    int prec;
    u8 conv;

    prec = spec.mPrecision;
    alt = spec.mHash;
    conv = spec.mSpecChar;
    width = spec.mMinLength;
    sign = spec.mSignKind;
    cursor = end;
    neg = 0;
    *--cursor = 0;
    cnt = neg;
    if (value == 0 && prec == 0 && !(alt != 0 && conv == 'o')) {
        return cursor;
    }
    switch (conv) {
        case 'i':
        case 'd':
            base = 10;
            if ((long) value < 0) {
                neg = 1;
                value = -value;
            }
            break;
        case 'u':
            base = 10;
            sign = 0;
            break;
        case 'x':
        case 'X':
            base = 16;
            sign = 0;
            break;
        case 'o':
            base = 8;
            sign = 0;
            break;
    }
    do {
        digit = value % base;
        value = value / base;
        if (digit < 10) {
            digit += '0';
        } else if (conv == 'x') {
            digit += 'a' - 10;
        } else {
            digit += 'A' - 10;
        }
        *--cursor = digit;
        cnt++;
    } while (value != 0);
    if (base == 8 && alt != 0 && *cursor != '0') {
        *--cursor = '0';
        cnt++;
    }
    if (spec.mPadKind == FORMAT_PAD_ZEROS) {
        prec = width;
        if (neg != 0 || sign != 0) {
            prec--;
        }
        if (base == 16 && alt != 0) {
            prec -= 2;
        }
    }
    if (prec + (end - cursor) > FORMAT_MAX_LENGTH) {
        return 0;
    }
    while (cnt < prec) {
        *--cursor = '0';
        cnt++;
    }
    if (base == 16 && alt != 0) {
        *--cursor = conv;
        *--cursor = '0';
    }
    if (neg != 0) {
        *--cursor = '-';
    } else if (sign == FORMAT_SIGN_PLUS) {
        *--cursor = '+';
    } else if (sign == FORMAT_SIGN_SPACE) {
        *--cursor = ' ';
    }
    return cursor;
}

char *FormatInt64(u64 value, char *end, FormatSpec spec) {
    int neg;
    int precision;
    int flag;
    u32 wid;
    int alt;
    u64 base;
    char *cursor;
    int count;
    int ch;
    int digit;

    precision = spec.mPrecision;
    alt = spec.mHash;
    ch = spec.mSpecChar;
    wid = spec.mMinLength;
    flag = spec.mSignKind;
    cursor = end;
    neg = 0;
    *--cursor = 0;
    count = neg;
    if (value == 0 && precision == 0 && (alt == 0 || ch != 'o')) {
        return cursor;
    }
    switch (ch) {
        case 'd':
        case 'i':
            base = 10;
            if ((s64) value < 0) {
                value = -value;
                neg = 1;
            }
            break;
        case 'o':
            base = 8;
            flag = 0;
            break;
        case 'u':
            base = 10;
            flag = 0;
            break;
        case 'x':
        case 'X':
            base = 16;
            flag = 0;
            break;
    }
    do {
        digit = value % base;
        value = value / base;
        if (digit < 10) {
            digit += '0';
        } else if (ch == 'x') {
            digit += 'a' - 10;
        } else {
            digit += 'A' - 10;
        }
        *--cursor = digit;
        count++;
    } while (value != 0);
    if (base == 8 && alt != 0 && *cursor != '0') {
        *--cursor = '0';
        count++;
    }
    if (spec.mPadKind == FORMAT_PAD_ZEROS) {
        precision = wid;
        if (neg != 0 || flag != 0) {
            precision--;
        }
        if (base == 16 && alt != 0) {
            precision -= 2;
        }
    }
    if (precision + (end - cursor) > FORMAT_MAX_LENGTH) {
        return 0;
    }
    while (count < precision) {
        *--cursor = '0';
        count++;
    }
    if (base == 16 && alt != 0) {
        *--cursor = ch;
        *--cursor = '0';
    }
    if (neg != 0) {
        *--cursor = '-';
    } else if (flag == FORMAT_SIGN_PLUS) {
        *--cursor = '+';
    } else if (flag == FORMAT_SIGN_SPACE) {
        *--cursor = ' ';
    }
    return cursor;
}

char *FormatDoubleHex(double value, char *buf, FormatSpec spec) {
    int precision;
    u8 conv;
    u8 alt;
    u8 signKind;
    DigitOptions digitOptions;
    FormatSpec exponentSpec;
    DigitRecord digits;
    char *cursor;
    int byteIndex;
    u8 swapTemp;
    u8 *mantissaBytes;
    u8 *swapBytes;
    u8 nibble;
    int counter;
    int bitOffset;

    precision = spec.mPrecision;
    conv = spec.mSpecChar;
    alt = spec.mHash;
    signKind = spec.mSignKind;
    if (precision > FORMAT_MAX_LENGTH) {
        return 0;
    }
    digitOptions.mUnk_00 = 0;
    digitOptions.mDigitCount = DIGIT_RECORD_MAX_DIGITS;
    DoubleToDigitChars(&digitOptions, value, &digits);
    if (0.0 == fabs(value)) {
        cursor = buf - 6;
        strcpy(cursor, gFormatHexZero);
        return cursor;
    }
    if (digits.mDigits[0] == 'I') {
        if (digits.mNegative != 0) {
            cursor = buf - 5;
            if (conv == 'A') {
                strcpy(cursor, gFormatMinusInfUpper);
            } else {
                strcpy(cursor, gFormatMinusInfLower);
            }
        } else {
            cursor = buf - 4;
            if (conv == 'A') {
                strcpy(cursor, gFormatInfUpper);
            } else {
                strcpy(cursor, gFormatInfLower);
            }
        }
        return cursor;
    }
    if (digits.mDigits[0] == 'N') {
        if (digits.mNegative != 0) {
            cursor = buf - 5;
            if (conv == 'A') {
                strcpy(cursor, gFormatMinusNanUpper);
            } else {
                strcpy(cursor, gFormatMinusNanLower);
            }
        } else {
            cursor = buf - 4;
            if (conv == 'A') {
                strcpy(cursor, gFormatNanUpper);
            } else {
                strcpy(cursor, gFormatNanLower);
            }
        }
        return cursor;
    }
    exponentSpec.mPadKind = FORMAT_PAD_SPACES;
    exponentSpec.mSignKind = FORMAT_SIGN_PLUS;
    exponentSpec.mHasDot = 0;
    exponentSpec.mHash = 0;
    exponentSpec.mArgKind = FORMAT_ARG_DEFAULT;
    exponentSpec.mPrecision = 1;
    exponentSpec.mMinLength = 0;
    exponentSpec.mSpecChar = 'd';
    swapBytes = (u8 *) &value;
    for (byteIndex = 0; byteIndex < 4; byteIndex++) {
        swapTemp = swapBytes[byteIndex];
        swapBytes[byteIndex] = swapBytes[7 - byteIndex];
        swapBytes[7 - byteIndex] = swapTemp;
    }
    bitOffset = ((u8 *) &value)[0] << 25;
    bitOffset |= ((u8 *) &value)[1] << 17;
    bitOffset = ((u32) bitOffset >> 21) & 0x7ff;
    counter = bitOffset - 1023;
    cursor = FormatInt32(counter, buf, exponentSpec);
    if (conv == 'a') {
        *--cursor = 'p';
    } else {
        *--cursor = 'P';
    }
    bitOffset = precision * 4 + 11;
    mantissaBytes = (u8 *) &value;
    for (counter = precision; counter >= 1; counter--) {
        if (bitOffset < 64) {
            nibble = mantissaBytes[bitOffset >> 3] >> (7 - (bitOffset & 7));
            if ((bitOffset & ~7) != ((bitOffset - 4) & ~7)) {
                nibble = nibble | ((mantissaBytes[(bitOffset >> 3) - 1] << 8) >> (7 - (bitOffset & 7)));
            }
            nibble &= 15;
            if (nibble < 10) {
                nibble += '0';
            } else if (conv == 'a') {
                nibble += 'a' - 10;
            } else {
                nibble += 'A' - 10;
            }
        } else {
            nibble = '0';
        }
        *--cursor = nibble;
        bitOffset -= 4;
    }
    if (precision != 0 || alt != 0) {
        *--cursor = '.';
    }
    *--cursor = '1';
    if (conv == 'a') {
        *--cursor = 'x';
    } else {
        *--cursor = 'X';
    }
    *--cursor = '0';
    if (digits.mNegative != 0) {
        *--cursor = '-';
    } else if (signKind == FORMAT_SIGN_PLUS) {
        *--cursor = '+';
    } else if (signKind == FORMAT_SIGN_SPACE) {
        *--cursor = ' ';
    }
    return cursor;
}

void FormatRoundDigitChars(DigitRecord *record, int keepCount) {
    char *digitStart;
    char *cursor;
    char *tail;
    int digitCount;
    u8 digit;
    int roundUp;

    if (keepCount < 0) {
    zero:
        record->mExponent = 0;
        record->mDigitCount = 1;
        record->mDigits[0] = '0';
        return;
    }
    digitCount = record->mDigitCount;
    if (keepCount >= digitCount) {
        return;
    }
    digitStart = record->mDigits;
    cursor = digitStart + keepCount + 1;
    digit = *--cursor - '0';
    if (digit == 5) {
        tail = digitStart + digitCount;
        while (--tail > cursor && *tail == '0') {
        }
        if (tail == cursor) {
            roundUp = cursor[-1] & 1;
        } else {
            roundUp = 1;
        }
    } else {
        roundUp = digit > 5;
    }
    while (keepCount != 0) {
        digit = *--cursor - '0' + roundUp;
        roundUp = digit > 9;
        if (roundUp != 0 || digit == 0) {
            keepCount--;
        } else {
            *cursor = digit + '0';
            break;
        }
    }
    if (roundUp != 0) {
        record->mExponent++;
        record->mDigitCount = 1;
        record->mDigits[0] = '1';
        return;
    }
    if (keepCount == 0) {
        goto zero;
    }
    record->mDigitCount = keepCount;
}

char *FormatDouble(double value, char *buf, FormatSpec spec) {
    DigitOptions digitOptions;
    DigitRecord record;
    u8 conv;
    int precision;
    int signKind;
    int alt;
    char *source;
    char *cursor;
    char *tail;
    int exponent;
    int exponentSign;
    int exponentDigits;
    int index;
    int intDigits;
    int fracDigits;
    int counter;

    conv = spec.mSpecChar;
    precision = spec.mPrecision;
    alt = spec.mHash;
    signKind = spec.mSignKind;
    digitOptions.mUnk_00 = 0;
    digitOptions.mDigitCount = DIGIT_RECORD_MAX_DIGITS;
    DoubleToDigitChars(&digitOptions, value, &record);
    tail = record.mDigits + record.mDigitCount;
    while (record.mDigitCount > 1 && *--tail == '0') {
        record.mDigitCount--;
        record.mExponent++;
    }
    switch (record.mDigits[0]) {
        case '0':
            record.mExponent = 0;
            break;
        case 'I':
            counter = conv;
            if (value < 0.0) {
                cursor = buf - 5;
                if ((counter < 0 || counter >= 0x80) ? 0 : (gCharClassFlags[counter] & 0x200)) {
                    strcpy(cursor, gFormatMinusInfUpper);
                } else {
                    strcpy(cursor, gFormatMinusInfLower);
                }
            } else {
                cursor = buf - 4;
                if ((counter < 0 || counter >= 0x80) ? 0 : (gCharClassFlags[counter] & 0x200)) {
                    strcpy(cursor, gFormatInfUpper);
                } else {
                    strcpy(cursor, gFormatInfLower);
                }
            }
            return cursor;
        case 'N':
            counter = conv;
            if (record.mNegative) {
                cursor = buf - 5;
                if ((counter < 0 || counter >= 0x80) ? 0 : (gCharClassFlags[counter] & 0x200)) {
                    strcpy(cursor, gFormatMinusNanUpper);
                } else {
                    strcpy(cursor, gFormatMinusNanLower);
                }
            } else {
                cursor = buf - 4;
                if ((counter < 0 || counter >= 0x80) ? 0 : (gCharClassFlags[counter] & 0x200)) {
                    strcpy(cursor, gFormatNanUpper);
                } else {
                    strcpy(cursor, gFormatNanLower);
                }
            }
            return cursor;
    }
    record.mExponent += record.mDigitCount - 1;
    cursor = buf - 1;
    *cursor = 0;
    switch (conv) {
        case 'g':
        case 'G':
            if (record.mDigitCount > precision) {
                FormatRoundDigitChars(&record, precision);
            }
            if (record.mExponent < -4 || record.mExponent >= precision) {
                if (alt) {
                    precision--;
                } else {
                    precision = record.mDigitCount - 1;
                }
                if (conv == 'g') {
                    conv = 'e';
                } else {
                    conv = 'E';
                }
            } else {
                if (alt) {
                    precision -= record.mExponent + 1;
                } else {
                    precision = record.mDigitCount - (record.mExponent + 1);
                    if (precision < 0) {
                        precision = 0;
                    }
                }
                goto case_f;
            }
        case 'e':
        case 'E':
            if (record.mDigitCount > precision + 1) {
                FormatRoundDigitChars(&record, precision + 1);
            }
            exponent = record.mExponent;
            exponentSign = '+';
            if (exponent < 0) {
                exponent = -exponent;
                exponentSign = '-';
            }
            for (exponentDigits = 0; exponent != 0 || exponentDigits < 2;) {
                *--cursor = exponent % 10 + '0';
                exponent /= 10;
                exponentDigits++;
            }
            cursor[-1] = exponentSign;
            cursor -= 2;
            *cursor = conv;
            if (precision + (buf - cursor) > FORMAT_MAX_LENGTH) {
                return 0;
            }
            if (record.mDigitCount < precision + 1) {
                index = precision + 2 - record.mDigitCount;
                while (--index) {
                    *--cursor = '0';
                }
            }
            source = record.mDigits + record.mDigitCount;
            for (index = record.mDigitCount - 1; index != 0; index--) {
                *--cursor = *--source;
            }
            if (precision != 0 || alt) {
                *--cursor = '.';
            }
            *--cursor = record.mDigits[0];
            if (record.mNegative) {
                *--cursor = '-';
            } else if (signKind == FORMAT_SIGN_PLUS) {
                *--cursor = '+';
            } else if (signKind == FORMAT_SIGN_SPACE) {
                *--cursor = ' ';
            }
            break;
        case 'f':
        case 'F':
        case_f:
            exponent = record.mExponent;
            fracDigits = record.mDigitCount - exponent - 1;
            if (fracDigits < 0) {
                fracDigits = 0;
            }
            if (fracDigits > precision) {
                FormatRoundDigitChars(&record, record.mDigitCount - (fracDigits - precision));
                exponent = record.mExponent;
                fracDigits = record.mDigitCount - exponent - 1;
                if (fracDigits < 0) {
                    fracDigits = 0;
                }
            }
            intDigits = exponent + 1;
            if (intDigits < 0) {
                intDigits = 0;
            }
            if (intDigits + fracDigits > FORMAT_MAX_LENGTH) {
                return 0;
            }
            source = record.mDigits + record.mDigitCount;
            for (counter = 0; counter < precision - fracDigits; counter++) {
                *--cursor = '0';
            }
            for (counter = 0; counter < fracDigits && counter < record.mDigitCount; counter++) {
                *--cursor = *--source;
            }
            for (; counter < fracDigits; counter++) {
                *--cursor = '0';
            }
            if (precision != 0 || alt) {
                *--cursor = '.';
            }
            if (intDigits != 0) {
                for (counter = 0; counter < intDigits - record.mDigitCount; counter++) {
                    *--cursor = '0';
                }
                for (; counter < intDigits; counter++) {
                    *--cursor = *--source;
                }
            } else {
                *--cursor = '0';
            }
            if (record.mNegative) {
                *--cursor = '-';
            } else if (signKind == FORMAT_SIGN_PLUS) {
                *--cursor = '+';
            } else if (signKind == FORMAT_SIGN_SPACE) {
                *--cursor = ' ';
            }
            break;
    }
    return cursor;
}

int FormatWithPutFunc(void *(*putFunc)(void *, const char *, u32), void *putArg, const char *format, char *argList) {
    FormatSpec spec;
    char buf[0x200];
    char padChar;
    char spaceChar;
    int totalLength;
    unsigned long long longLongValue;
    const char *percentPos;
    int textLength;
    int chunkLength;
    int printedLength;
    char *text;
    unsigned long wordValue;
    double doubleValue;
    const u16 *wideText;
    char *nulPos;
    void *countPtr;

    padChar = ' ';
    totalLength = 0;
    while (*format != 0) {
        percentPos = strchr(format, '%');
        if (percentPos == 0) {
            chunkLength = strlen(format);
            totalLength += chunkLength;
            if (chunkLength != 0 && putFunc(putArg, format, chunkLength) == 0) {
                return -1;
            }
            break;
        }
        chunkLength = percentPos - format;
        totalLength += chunkLength;
        if (chunkLength != 0 && putFunc(putArg, format, chunkLength) == 0) {
            return -1;
        }
        format = FormatParseSpec(percentPos, &argList, &spec);
        switch (spec.mSpecChar) {
            case 'd':
            case 'i':
                if (spec.mArgKind == FORMAT_ARG_LONG) {
                    wordValue = *(long *) ((argList += 4) - 4);
                } else if (spec.mArgKind == FORMAT_ARG_LONG_LONG) {
                    longLongValue = *(long long *) ((argList += 8) - 8);
                } else if (spec.mArgKind == FORMAT_ARG_INTMAX) {
                    wordValue = *(long long *) ((argList += 8) - 8);
                } else if (spec.mArgKind == FORMAT_ARG_SIZE) {
                    wordValue = *(u32 *) ((argList += 4) - 4);
                } else if (spec.mArgKind == FORMAT_ARG_PTRDIFF) {
                    wordValue = *(long *) ((argList += 4) - 4);
                } else {
                    wordValue = *(int *) ((argList += 4) - 4);
                }
                if (spec.mArgKind == FORMAT_ARG_SHORT) {
                    wordValue = (short) wordValue;
                }
                if (spec.mArgKind == FORMAT_ARG_CHAR) {
                    wordValue = (s8) wordValue;
                }
                if (spec.mArgKind == FORMAT_ARG_LONG_LONG) {
                    text = FormatInt64(longLongValue, buf + sizeof(buf), spec);
                    if (text == 0) {
                        goto bad;
                    }
                } else {
                    text = FormatInt32(wordValue, buf + sizeof(buf), spec);
                    if (text == 0) {
                        goto bad;
                    }
                }
                textLength = buf + sizeof(buf) - 1 - text;
                break;
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                if (spec.mArgKind == FORMAT_ARG_LONG) {
                    wordValue = *(unsigned long *) ((argList += 4) - 4);
                } else if (spec.mArgKind == FORMAT_ARG_LONG_LONG) {
                    longLongValue = *(unsigned long long *) ((argList += 8) - 8);
                } else if (spec.mArgKind == FORMAT_ARG_INTMAX) {
                    wordValue = *(unsigned long long *) ((argList += 8) - 8);
                } else if (spec.mArgKind == FORMAT_ARG_SIZE) {
                    wordValue = *(u32 *) ((argList += 4) - 4);
                } else if (spec.mArgKind == FORMAT_ARG_PTRDIFF) {
                    wordValue = *(unsigned long *) ((argList += 4) - 4);
                } else {
                    wordValue = *(u32 *) ((argList += 4) - 4);
                }
                if (spec.mArgKind == FORMAT_ARG_SHORT) {
                    wordValue = (u16) wordValue;
                }
                if (spec.mArgKind == FORMAT_ARG_CHAR) {
                    wordValue = (u8) wordValue;
                }
                if (spec.mArgKind == FORMAT_ARG_LONG_LONG) {
                    text = FormatInt64(longLongValue, buf + sizeof(buf), spec);
                    if (text == 0) {
                        goto bad;
                    }
                } else {
                    text = FormatInt32(wordValue, buf + sizeof(buf), spec);
                    if (text == 0) {
                        goto bad;
                    }
                }
                textLength = buf + sizeof(buf) - 1 - text;
                break;
            case 'e':
            case 'E':
            case 'f':
            case 'F':
            case 'g':
            case 'G':
                if (spec.mArgKind == FORMAT_ARG_LONG_DOUBLE) {
                    doubleValue = *(long double *) ((argList += 8) - 8);
                } else {
                    doubleValue = *(double *) ((argList += 8) - 8);
                }
                text = FormatDouble(doubleValue, buf + sizeof(buf), spec);
                if (text == 0) {
                    goto bad;
                }
                textLength = buf + sizeof(buf) - 1 - text;
                break;
            case 'a':
            case 'A':
                if (spec.mArgKind == FORMAT_ARG_LONG_DOUBLE) {
                    doubleValue = *(long double *) ((argList += 8) - 8);
                } else {
                    doubleValue = *(double *) ((argList += 8) - 8);
                }
                text = FormatDoubleHex(doubleValue, buf + sizeof(buf), spec);
                if (text == 0) {
                    goto bad;
                }
                textLength = buf + sizeof(buf) - 1 - text;
                break;
            case 's':
                if (spec.mArgKind == FORMAT_ARG_WIDE) {
                    wideText = *(const u16 **) ((argList += 4) - 4);
                    if (wideText == 0) {
                        wideText = L"";
                    }
                    if (wcstombs(buf, wideText, sizeof(buf)) < 0) {
                        goto bad;
                    }
                    text = buf;
                } else {
                    text = *(char **) ((argList += 4) - 4);
                }
                if (text == 0) {
                    text = "";
                }
                if (spec.mHash != 0) {
                    textLength = *text++;
                    if (spec.mHasDot != 0 && textLength > spec.mPrecision) {
                        textLength = spec.mPrecision;
                    }
                } else if (spec.mHasDot != 0) {
                    textLength = spec.mPrecision;
                    nulPos = memchr(text, 0, textLength);
                    if (nulPos != 0) {
                        textLength = nulPos - text;
                    }
                } else {
                    textLength = strlen(text);
                }
                break;
            case 'n':
                countPtr = *(void **) ((argList += 4) - 4);
                switch (spec.mArgKind) {
                    case FORMAT_ARG_DEFAULT:
                        *(int *) countPtr = totalLength;
                        break;
                    case FORMAT_ARG_SHORT:
                        *(short *) countPtr = totalLength;
                        break;
                    case FORMAT_ARG_LONG:
                        *(long *) countPtr = totalLength;
                        break;
                    case FORMAT_ARG_LONG_LONG:
                        *(long long *) countPtr = totalLength;
                        break;
                }
                continue;
            case 'c':
                text = buf;
                *text = *(int *) ((argList += 4) - 4);
                textLength = 1;
                break;
            case '%':
                text = buf;
                *text = '%';
                textLength = 1;
                break;
            case FORMAT_SPEC_INVALID:
            default:
            bad:
                chunkLength = strlen(percentPos);
                totalLength += chunkLength;
                if (chunkLength != 0 && putFunc(putArg, percentPos, chunkLength) == 0) {
                    return -1;
                }
                return totalLength;
        }
        printedLength = textLength;
        if (spec.mPadKind != FORMAT_PAD_LEFT_ALIGN) {
            padChar = spec.mPadKind == FORMAT_PAD_ZEROS ? '0' : ' ';
            if ((*text == '+' || *text == '-' || *text == ' ') && padChar == '0') {
                if (putFunc(putArg, text, 1) == 0) {
                    return -1;
                }
                text++;
                textLength--;
            }
            for (; printedLength < spec.mMinLength; printedLength++) {
                if (putFunc(putArg, &padChar, 1) == 0) {
                    return -1;
                }
            }
        }
        if (textLength != 0 && putFunc(putArg, text, textLength) == 0) {
            return -1;
        }
        if (spec.mPadKind == FORMAT_PAD_LEFT_ALIGN) {
            for (; printedLength < spec.mMinLength; printedLength++) {
                spaceChar = ' ';
                if (putFunc(putArg, &spaceChar, 1) == 0) {
                    return -1;
                }
            }
        }
        totalLength += printedLength;
    }
    return totalLength;
}
