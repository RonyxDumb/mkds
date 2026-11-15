#pragma avoid_byte all

#include "code_0213cae0.h"
#include "code_02134b18.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213c94c.h"
#include "code_0213ecf8.h"
#include "code_0213ee6c.h"

const u16 gCharFlags[128] = {
    4,     4,     4,     4,     4,     4,     4,     4,     4,     0x106, 0x104, 0x104, 0x104, 0x104, 4,     4,
    4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
    0x142, 0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,
    0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0x458, 0xd0,  0xd0,  0xd0,  0xd0,  0xd0,  0xd0,
    0xd0,  0x651, 0x651, 0x651, 0x651, 0x651, 0x651, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251,
    0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0x251, 0xd0,  0xd0,  0xd0,  0xd0,  0xd0,
    0xd0,  0x471, 0x471, 0x471, 0x471, 0x471, 0x471, 0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,
    0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0x71,  0xd0,  0xd0,  0xd0,  0xd0,  4};

const u16 *FormatWideParseSpec(const u16 *format, char **argList, FormatWideSpec *specOut) {
    FormatWideSpec parsed;
    const u16 *cursor;
    u16 ch;
    int matched;

    parsed.mPadKind = FORMAT_WIDE_PAD_SPACES;
    parsed.mSignKind = FORMAT_WIDE_SIGN_NONE;
    parsed.mHasDot = 0;
    parsed.mHash = 0;
    parsed.mArgKind = FORMAT_WIDE_ARG_DEFAULT;
    parsed.mMinLength = 0;
    parsed.mPrecision = 0;
    cursor = format + 1;
    ch = *cursor;
    if (ch == '%') {
        parsed.mSpecChar = ch;
        *specOut = parsed;
        return cursor + 1;
    }
    for (;;) {
        matched = 1;
        switch (ch) {
            case '-':
                parsed.mPadKind = FORMAT_WIDE_PAD_LEFT_ALIGN;
                break;
            case '+':
                parsed.mSignKind = FORMAT_WIDE_SIGN_PLUS;
                break;
            case ' ':
                if (parsed.mSignKind != FORMAT_WIDE_SIGN_PLUS) {
                    parsed.mSignKind = FORMAT_WIDE_SIGN_SPACE;
                }
                break;
            case '#':
                parsed.mHash = 1;
                break;
            case '0':
                if (parsed.mPadKind != FORMAT_WIDE_PAD_LEFT_ALIGN) {
                    parsed.mPadKind = FORMAT_WIDE_PAD_ZEROS;
                }
                break;
            default:
                matched = 0;
                break;
        }
        if (!matched) {
            break;
        }
        ch = *++cursor;
    }
    if (ch == '*') {
        *argList += 4;
        parsed.mMinLength = *(int *) (*argList - 4);
        if (parsed.mMinLength < 0) {
            parsed.mPadKind = FORMAT_WIDE_PAD_LEFT_ALIGN;
            parsed.mMinLength = -parsed.mMinLength;
        }
        ch = *++cursor;
    } else {
        while ((ch >= 0x80 ? 0 : gCharFlags[ch] & 8) != 0) {
            parsed.mMinLength = parsed.mMinLength * 10 + (ch - '0');
            ch = *++cursor;
        }
    }
    if (parsed.mMinLength > FORMAT_WIDE_MAX_LENGTH) {
        parsed.mSpecChar = FORMAT_WIDE_SPEC_INVALID;
        *specOut = parsed;
        return cursor + 1;
    }
    if (ch == '.') {
        parsed.mHasDot = 1;
        ch = *++cursor;
        if (ch == '*') {
            *argList += 4;
            parsed.mPrecision = *(int *) (*argList - 4);
            if (parsed.mPrecision < 0) {
                parsed.mHasDot = 0;
            }
            ch = *++cursor;
        } else {
            while ((ch >= 0x80 ? 0 : gCharFlags[ch] & 8) != 0) {
                parsed.mPrecision = parsed.mPrecision * 10 + (ch - '0');
                ch = *++cursor;
            }
        }
    }
    matched = 1;
    switch (ch) {
        case 'h':
            parsed.mArgKind = FORMAT_WIDE_ARG_SHORT;
            if (cursor[1] == 'h') {
                parsed.mArgKind = FORMAT_WIDE_ARG_CHAR;
                ch = *++cursor;
            }
            break;
        case 'l':
            parsed.mArgKind = FORMAT_WIDE_ARG_LONG;
            if (cursor[1] == 'l') {
                parsed.mArgKind = FORMAT_WIDE_ARG_LONG_LONG;
                ch = *++cursor;
            }
            break;
        case 'L':
            parsed.mArgKind = FORMAT_WIDE_ARG_LONG_DOUBLE;
            break;
        default:
            matched = 0;
            break;
    }
    if (matched) {
        ch = *++cursor;
    }
    parsed.mSpecChar = ch;
    switch (ch) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (parsed.mArgKind == FORMAT_WIDE_ARG_LONG_DOUBLE) {
                parsed.mArgKind = FORMAT_WIDE_ARG_LONG_LONG;
            }
            if (parsed.mHasDot == 0) {
                parsed.mPrecision = 1;
            } else if (parsed.mPadKind == FORMAT_WIDE_PAD_ZEROS) {
                parsed.mPadKind = FORMAT_WIDE_PAD_SPACES;
            }
            break;
        case 'f':
        case 'F':
            if (parsed.mArgKind == FORMAT_WIDE_ARG_SHORT || parsed.mArgKind == FORMAT_WIDE_ARG_LONG_LONG) {
                parsed.mSpecChar = FORMAT_WIDE_SPEC_INVALID;
            } else if (parsed.mHasDot == 0) {
                parsed.mPrecision = FORMAT_WIDE_FLOAT_DEFAULT_PRECISION;
            }
            break;
        case 'g':
        case 'G':
            if (parsed.mPrecision == 0) {
                parsed.mPrecision = 1;
            }
        case 'e':
        case 'E':
            if (parsed.mArgKind == FORMAT_WIDE_ARG_SHORT || parsed.mArgKind == FORMAT_WIDE_ARG_LONG_LONG ||
                parsed.mArgKind == FORMAT_WIDE_ARG_CHAR) {
                parsed.mSpecChar = FORMAT_WIDE_SPEC_INVALID;
            } else if (parsed.mHasDot == 0) {
                parsed.mPrecision = FORMAT_WIDE_FLOAT_DEFAULT_PRECISION;
            }
            break;
        case 'p':
            parsed.mArgKind = FORMAT_WIDE_ARG_LONG;
            parsed.mHash = 1;
            parsed.mSpecChar = 'x';
            parsed.mPrecision = FORMAT_WIDE_POINTER_DIGITS;
            break;
        case 'c':
            if (parsed.mArgKind == FORMAT_WIDE_ARG_LONG) {
                parsed.mArgKind = FORMAT_WIDE_ARG_WIDE;
            } else if (parsed.mHasDot != 0 || parsed.mArgKind != FORMAT_WIDE_ARG_DEFAULT) {
                parsed.mSpecChar = FORMAT_WIDE_SPEC_INVALID;
            }
            break;
        case 's':
            if (parsed.mArgKind == FORMAT_WIDE_ARG_LONG) {
                parsed.mArgKind = FORMAT_WIDE_ARG_WIDE;
            } else if (parsed.mArgKind != FORMAT_WIDE_ARG_DEFAULT) {
                parsed.mSpecChar = FORMAT_WIDE_SPEC_INVALID;
            }
            break;
        case 'n':
            if (parsed.mArgKind == FORMAT_WIDE_ARG_LONG_DOUBLE) {
                parsed.mArgKind = FORMAT_WIDE_ARG_LONG_LONG;
            }
            break;
        default:
            parsed.mSpecChar = FORMAT_WIDE_SPEC_INVALID;
            break;
    }
    *specOut = parsed;
    return cursor + 1;
}

// Writes the digits of value backwards from end and returns the address of the first one, or 0 when too long.
u16 *FormatWideInt32(unsigned long value, u16 *end, FormatWideSpec spec) {
    unsigned long base;
    u16 *cursor;
    int negative;
    int count;
    int precision;
    int width;
    u8 alt;
    int signKind;
    int digit;
    u16 conv;

    precision = spec.mPrecision;
    alt = spec.mHash;
    conv = spec.mSpecChar;
    width = spec.mMinLength;
    signKind = spec.mSignKind;
    count = 0;
    negative = 0;
    cursor = end;
    *--cursor = 0;
    if (value == 0 && precision == 0) {
        if (alt == 0 || conv != 'o') {
            return cursor;
        }
    }
    switch (conv) {
        case 'd':
        case 'i':
            base = 10;
            if ((int) value < 0) {
                value = -value;
                count = 1;
            }
            break;
        case 'o':
            base = 8;
            signKind = 0;
            break;
        case 'u':
            base = 10;
            signKind = 0;
            break;
        case 'x':
        case 'X':
            base = 16;
            signKind = 0;
            break;
    }
    do {
        digit = value % base;
        value = value / base;
        if (digit < 10) {
            digit += '0';
        } else if (conv == 'x') {
            digit += 0x57;
        } else {
            digit += 0x37;
        }
        *--cursor = digit;
        negative++;
    } while (value != 0);
    if (base == 8 && alt != 0) {
        if (*cursor != '0') {
            *--cursor = '0';
            negative++;
        }
    }
    if (spec.mPadKind == FORMAT_WIDE_PAD_ZEROS) {
        precision = width;
        if (count != 0 || signKind != 0) {
            precision--;
        }
        if (base == 16 && alt != 0) {
            precision -= 2;
        }
    }
    if (precision + (end - cursor) > FORMAT_WIDE_MAX_LENGTH) {
        return 0;
    }
    while (negative < precision) {
        negative++;
        *--cursor = '0';
    }
    if (base == 16 && alt != 0) {
        *--cursor = conv;
        *--cursor = '0';
    }
    if (count != 0) {
        *--cursor = '-';
    } else if (signKind == FORMAT_WIDE_SIGN_PLUS) {
        *--cursor = '+';
    } else if (signKind == FORMAT_WIDE_SIGN_SPACE) {
        *--cursor = ' ';
    }
    return cursor;
}

// Same as FormatWideInt32 with a 64-bit value (one word per half; the digit and the quotient come from 64-bit unsigned
// division and remainder).
// Same as FormatWideInt32 with a 64-bit value.
u16 *FormatWideInt64(u64 value, u16 *end, FormatWideSpec spec) {
    int count;
    int precision;
    int width;
    u8 alt;
    int digit;
    u64 base;
    u16 *cursor;
    s32 negative;
    u16 conv;
    u8 signKind;
    int digitChar;

    precision = spec.mPrecision;
    alt = spec.mHash;
    signKind = spec.mSignKind;
    width = spec.mMinLength;
    count = 0;
    negative = 0;
    conv = spec.mSpecChar;
    cursor = end;
    *--cursor = 0;
    if (value == 0 && precision == 0) {
        if (alt == 0 || conv != 'o') {
            return cursor;
        }
    }
    switch (conv) {
        case 'd':
        case 'i':
            base = 10;
            if ((s64) value < 0) {
                value = -value;
                count = 1;
            }
            break;
        case 'o':
            base = 8;
            signKind = 0;
            break;
        case 'u':
            base = 10;
            signKind = 0;
            break;
        case 'x':
        case 'X':
            base = 16;
            signKind = 0;
            break;
    }
    do {
        digit = value % base;
        value = value / base;
        if (digit < 10) {
            digitChar = digit + '0';
        } else if (conv == 'x') {
            digitChar = digit + 0x57;
        } else {
            digitChar = digit + 0x37;
        }
        *--cursor = digitChar;
        negative++;
    } while (value != 0);
    if (base == 8 && alt != 0) {
        if (*cursor != '0') {
            *--cursor = '0';
            negative++;
        }
    }
    if (spec.mPadKind == FORMAT_WIDE_PAD_ZEROS) {
        precision = width;
        if (count != 0 || signKind != 0) {
            precision--;
        }
        if (base == 16 && alt != 0) {
            precision -= 2;
        }
    }
    if (precision + (end - cursor) > FORMAT_WIDE_MAX_LENGTH) {
        return 0;
    }
    while (negative < precision) {
        negative++;
        *--cursor = '0';
    }
    if (base == 16 && alt != 0) {
        *--cursor = conv;
        *--cursor = '0';
    }
    if (count != 0) {
        *--cursor = '-';
    } else if (signKind == FORMAT_WIDE_SIGN_PLUS) {
        *--cursor = '+';
    } else if (signKind == FORMAT_WIDE_SIGN_SPACE) {
        *--cursor = ' ';
    }
    return cursor;
}

void FormatWideRoundDigitChars(DigitRecord *record, int keepCount) {
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

u16 *FormatWideDouble(double value, u16 *end, FormatWideSpec spec) {
    DigitOptions digitOptions;
    DigitRecord record;
    char buf[0x200];
    int precision;
    u16 conv;
    u8 alt;
    u8 signKind;
    char *cursor;
    char *tail;
    u16 *wideCursor;
    int exponent;
    int intDigits;
    int fracDigits;
    int exponentDigits;
    int index;
    u8 exponentSign;

    precision = spec.mPrecision;
    conv = spec.mSpecChar;
    alt = spec.mHash;
    signKind = spec.mSignKind;
    if (precision > 509) {
        return 0;
    }
    digitOptions.mUnk_00 = 0;
    digitOptions.mDigitCount = DIGIT_RECORD_MAX_DIGITS;
    DoubleToDigitChars(&digitOptions, value, &record);
    cursor = record.mDigits + record.mDigitCount;
    while (record.mDigitCount > 1 && *--cursor == '0') {
        record.mDigitCount--;
        record.mExponent++;
    }
    switch (record.mDigits[0]) {
        case '0':
            record.mExponent = 0;
            break;
        case 'I':
            if (value < 0.0) {
                wideCursor = end - 5;
                if ((conv >= 0x80 ? 0 : gCharFlags[conv] & 0x200) != 0) {
                    wcscpy(wideCursor, L"-INF");
                } else {
                    wcscpy(wideCursor, L"-inf");
                }
            } else {
                wideCursor = end - 4;
                if ((conv >= 0x80 ? 0 : gCharFlags[conv] & 0x200) != 0) {
                    wcscpy(wideCursor, L"INF");
                } else {
                    wcscpy(wideCursor, L"inf");
                }
            }
            return wideCursor;
        case 'N':
            wideCursor = end - 4;
            wcscpy(wideCursor, L"NaN");
            return wideCursor;
    }
    record.mExponent += record.mDigitCount - 1;
    cursor = buf + sizeof(buf);
    *--cursor = 0;
    switch (conv) {
        case 'g':
        case 'G':
            if (record.mDigitCount > precision) {
                FormatWideRoundDigitChars(&record, precision);
            }
            if (record.mExponent < -4 || record.mExponent >= precision) {
                if (alt != 0) {
                    precision--;
                } else {
                    precision = record.mDigitCount - 1;
                }
                if (conv == 'g') {
                    conv = 'e';
                } else {
                    conv = 'E';
                }
                goto exp;
            }
            if (alt != 0) {
                precision -= record.mExponent + 1;
            } else {
                if ((precision = record.mDigitCount - (record.mExponent + 1)) < 0) {
                    precision = 0;
                }
            }
            goto fix;
        case 'e':
        case 'E':
        exp:
            if (record.mDigitCount > precision + 1) {
                FormatWideRoundDigitChars(&record, precision + 1);
            }
            exponent = record.mExponent;
            exponentSign = '+';
            if (exponent < 0) {
                exponent = -exponent;
                exponentSign = '-';
            }
            for (exponentDigits = 0; exponent != 0 || exponentDigits < 2; exponentDigits++) {
                *--cursor = exponent % 10 + '0';
                exponent /= 10;
            }
            *--cursor = exponentSign;
            *--cursor = conv;
            if (buf - cursor + precision > 509) {
                return 0;
            }
            if (record.mDigitCount < precision + 1) {
                for (index = precision + 2 - record.mDigitCount; --index != 0;) {
                    *--cursor = '0';
                }
            }
            tail = record.mDigits + record.mDigitCount;
            for (index = record.mDigitCount; --index != 0;) {
                *--cursor = *--tail;
            }
            if (precision != 0 || alt != 0) {
                *--cursor = '.';
            }
            *--cursor = record.mDigits[0];
            if (record.mNegative != 0) {
                *--cursor = '-';
            } else if (signKind == FORMAT_WIDE_SIGN_PLUS) {
                *--cursor = '+';
            } else if (signKind == FORMAT_WIDE_SIGN_SPACE) {
                *--cursor = ' ';
            }
            break;
        case 'f':
        case 'F':
        fix:
            if ((fracDigits = record.mDigitCount - record.mExponent - 1) < 0) {
                fracDigits = 0;
            }
            if (fracDigits > precision) {
                FormatWideRoundDigitChars(&record, record.mDigitCount - (fracDigits - precision));
                if ((fracDigits = record.mDigitCount - record.mExponent - 1) < 0) {
                    fracDigits = 0;
                }
            }
            if ((intDigits = record.mExponent + 1) < 0) {
                intDigits = 0;
            }
            if (intDigits + fracDigits > 509) {
                return 0;
            }
            tail = record.mDigits + record.mDigitCount;
            for (index = 0; index < precision - fracDigits; index++) {
                *--cursor = '0';
            }
            for (index = 0; index < fracDigits && index < record.mDigitCount; index++) {
                *--cursor = *--tail;
            }
            for (; index < fracDigits; index++) {
                *--cursor = '0';
            }
            if (precision != 0 || alt != 0) {
                *--cursor = '.';
            }
            if (intDigits != 0) {
                for (index = 0; index < intDigits - record.mDigitCount; index++) {
                    *--cursor = '0';
                }
                for (; index < intDigits; index++) {
                    *--cursor = *--tail;
                }
            } else {
                *--cursor = '0';
            }
            if (record.mNegative != 0) {
                *--cursor = '-';
            } else if (signKind == FORMAT_WIDE_SIGN_PLUS) {
                *--cursor = '+';
            } else if (signKind == FORMAT_WIDE_SIGN_SPACE) {
                *--cursor = ' ';
            }
            break;
    }
    wideCursor = end - strlen(cursor) - 1;
    mbstowcs(wideCursor, cursor, strlen(cursor));
    return wideCursor;
}

int FormatWideWithPutFunc(void *(*putFunc)(void *, const u16 *, u32), void *putArg, const u16 *format, char *argList) {
    u16 padChar = ' ';
    u16 spaceChar;
    char charArg;
    FormatWideSpec spec;
    u16 buf[512];
    int totalLength;
    long intArg;
    u64 int64Arg;
    const u16 *percentPos;
    int printedLength;
    u16 *text;
    int textLength;
    double doubleValue;
    const char *narrowText;
    int narrowLength;
    const u16 *nulPos;
    const char *narrowNulPos;
    int padCharValue;

    totalLength = 0;
    while (*format != 0) {
        percentPos = wcschr(format, '%');
        if (percentPos == 0) {
            textLength = wcslen(format);
            totalLength += textLength;
            if (textLength != 0 && putFunc(putArg, format, textLength) == 0) {
                return -1;
            }
            break;
        }
        textLength = percentPos - format;
        totalLength += textLength;
        if (textLength != 0 && putFunc(putArg, format, textLength) == 0) {
            return -1;
        }
        format = FormatWideParseSpec(percentPos, &argList, &spec);
        switch (spec.mSpecChar) {
            case 'd':
            case 'i':
                if (spec.mArgKind == FORMAT_WIDE_ARG_LONG) {
                    argList += 4;
                    intArg = *(long *) (argList - 4);
                } else if (spec.mArgKind == FORMAT_WIDE_ARG_LONG_LONG) {
                    argList += 8;
                    int64Arg = *(u64 *) (argList - 8);
                } else {
                    argList += 4;
                    intArg = *(int *) (argList - 4);
                }
                if (spec.mArgKind == FORMAT_WIDE_ARG_SHORT) {
                    intArg = (short) intArg;
                }
                if (spec.mArgKind == FORMAT_WIDE_ARG_LONG_LONG) {
                    text = FormatWideInt64(int64Arg, buf + 512, spec);
                    if (text == 0) {
                        goto bad;
                    }
                } else {
                    text = FormatWideInt32(intArg, buf + 512, spec);
                    if (text == 0) {
                        goto bad;
                    }
                }
                textLength = buf + 511 - text;
                break;
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                if (spec.mArgKind == FORMAT_WIDE_ARG_LONG) {
                    argList += 4;
                    intArg = *(long *) (argList - 4);
                } else if (spec.mArgKind == FORMAT_WIDE_ARG_LONG_LONG) {
                    argList += 8;
                    int64Arg = *(u64 *) (argList - 8);
                } else {
                    argList += 4;
                    intArg = *(int *) (argList - 4);
                }
                if (spec.mArgKind == FORMAT_WIDE_ARG_SHORT) {
                    intArg = (u16) intArg;
                }
                if (spec.mArgKind == FORMAT_WIDE_ARG_LONG_LONG) {
                    text = FormatWideInt64(int64Arg, buf + 512, spec);
                    if (text == 0) {
                        goto bad;
                    }
                } else {
                    text = FormatWideInt32(intArg, buf + 512, spec);
                    if (text == 0) {
                        goto bad;
                    }
                }
                textLength = buf + 511 - text;
                break;
            case 'e':
            case 'f':
            case 'g':
            case 'E':
            case 'F':
            case 'G':
                if (spec.mArgKind == FORMAT_WIDE_ARG_LONG_DOUBLE) {
                    argList += 8;
                    doubleValue = *(long double *) (argList - 8);
                } else {
                    argList += 8;
                    doubleValue = *(double *) (argList - 8);
                }
                text = FormatWideDouble(doubleValue, buf + 512, spec);
                if (text == 0) {
                    goto bad;
                }
                textLength = buf + 511 - text;
                break;
            case 's':
                if (spec.mArgKind == FORMAT_WIDE_ARG_WIDE) {
                    argList += 4;
                    text = *(u16 **) (argList - 4);
                    if (text == 0) {
                        text = L"";
                    }
                    if (spec.mHash != 0) {
                        textLength = (u8) *text++;
                        if (spec.mHasDot != 0 && textLength > spec.mPrecision) {
                            textLength = spec.mPrecision;
                        }
                    } else if (spec.mHasDot != 0) {
                        textLength = spec.mPrecision;
                        nulPos = wmemchr(text, 0, textLength);
                        if (nulPos != 0) {
                            textLength = nulPos - text;
                        }
                    } else {
                        textLength = wcslen(text);
                    }
                } else {
                    argList += 4;
                    narrowText = *(const char **) (argList - 4);
                    if (narrowText == 0) {
                        narrowText = "";
                    }
                    if (spec.mHash != 0) {
                    // reads p (the u16 pointer of the other branch), not bp
                        narrowLength = (u8) *text;
                        if (spec.mHasDot != 0 && narrowLength > spec.mPrecision) {
                            narrowLength = spec.mPrecision;
                        }
                    } else if (spec.mHasDot != 0) {
                        narrowLength = spec.mPrecision;
                        narrowNulPos = memchr(narrowText, 0, narrowLength);
                        if (narrowNulPos != 0) {
                            narrowLength = narrowNulPos - narrowText;
                        }
                    } else {
                        narrowLength = strlen(narrowText);
                    }
                    textLength = mbstowcs(buf, narrowText, narrowLength);
                    if (textLength < 0) {
                        goto bad;
                    }
                    text = buf;
                }
                break;
            case 'n':
                argList += 4;
                text = *(u16 **) (argList - 4);
                switch (spec.mArgKind) {
                    case FORMAT_WIDE_ARG_DEFAULT:
                        *(int *) text = totalLength;
                        break;
                    case FORMAT_WIDE_ARG_SHORT:
                        *(short *) text = totalLength;
                        break;
                    case FORMAT_WIDE_ARG_LONG:
                        *(long *) text = totalLength;
                        break;
                    case FORMAT_WIDE_ARG_LONG_LONG:
                        *(long long *) text = totalLength;
                        break;
                }
                continue;
            case 'c':
                text = buf;
                if (spec.mArgKind == FORMAT_WIDE_ARG_WIDE) {
                    argList += 4;
                    textLength = 1;
                    *text = *(int *) (argList - 4);
                } else {
                    argList += 4;
                    charArg = *(int *) (argList - 4);
                    textLength = mbtowc(text, &charArg, 1);
                }
                break;
            case '%':
                buf[0] = '%';
                text = buf;
                textLength = 1;
                break;
            case FORMAT_WIDE_SPEC_INVALID:
            default:
            bad:
                textLength = wcslen(percentPos);
                totalLength += textLength;
                if (textLength != 0 && putFunc(putArg, percentPos, textLength) == 0) {
                    return -1;
                }
                return totalLength;
        }
        printedLength = textLength;
        if (spec.mPadKind != FORMAT_WIDE_PAD_LEFT_ALIGN) {
            padCharValue = spec.mPadKind == FORMAT_WIDE_PAD_ZEROS ? '0' : ' ';
            padChar = padCharValue;
            if ((*text == '+' || *text == '-' || *text == ' ') && padCharValue == '0') {
                if (putFunc(putArg, text, 1) == 0) {
                    return -1;
                }
                text++;
                textLength--;
            }
            while (printedLength < spec.mMinLength) {
                if (putFunc(putArg, &padChar, 1) == 0) {
                    return -1;
                }
                printedLength++;
            }
        }
        if (textLength != 0 && putFunc(putArg, text, textLength) == 0) {
            return -1;
        }
        if (spec.mPadKind == FORMAT_WIDE_PAD_LEFT_ALIGN) {
            while (printedLength < spec.mMinLength) {
                spaceChar = ' ';
                if (putFunc(putArg, &spaceChar, 1) == 0) {
                    return -1;
                }
                printedLength++;
            }
        }
        totalLength += printedLength;
    }
    return totalLength;
}
