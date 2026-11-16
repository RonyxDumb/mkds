#include "formatted_text_to_buffer.h"

// Stores c at dst_string.mCur while dst_string.mLen is nonzero, and always advances dst_string.mCur.
void Util_PrintContext_ApppendChar(dst_string *str, char character) {
    if (str->mLen != 0) {
        str->mCur[0] = character;
        str->mLen = str->mLen - 1;
    }
    str->mCur = str->mCur + 1;
}

// Stores len copies of c at dst_string.mCur as far as dst_string.mLen allows, and advances dst_string.mCur by len.
void Util_PrintContext_FillWith(dst_string *str, char character, int len) {
    size_t index;
    size_t count;

    if (len <= 0) {
        return;
    }
    count = str->mLen;
    if (count > len) {
        count = len;
    }
    for (index = 0; index < count; index++) {
        str->mCur[index] = character;
    }
    str->mLen = str->mLen - count;
    str->mCur = str->mCur + len;
}

// Copies len bytes of src to dst_string.mCur as far as dst_string.mLen allows, and advances dst_string.mCur by len.
void Util_PrintContext_AppendString(dst_string *str, const char *src, int len) {
    size_t index;
    size_t count;

    if (len <= 0) {
        return;
    }
    count = str->mLen;
    if (count > len) {
        count = len;
    }
    for (index = 0; index < count; index++) {
        str->mCur[index] = src[index];
    }
    str->mLen = str->mLen - count;
    str->mCur = str->mCur + len;
}

// Formats into dst without a length limit and returns the length the text has.
int MaybeUtil_SPrintF(char *dst, const char *fmt, ...) {
    char *args;

    args = (char *) (((u32) &fmt & ~3) + 4);
    return Util_VSPrintF(dst, fmt, args);
}

// MaybeUtil_SPrintF with the arguments already collected.
int Util_VSPrintF(char *dst, const char *fmt, char *args) {
    return Util_VSNPrintF(dst, 0x7fffffff, fmt, args);
}

// Formats into dst with room for len bytes (including the terminator) and returns the length the full text has.
int Util_SNPrintF(char *dst, size_t len, const char *fmt, ...) {
    char *args;

    args = (char *) (((u32) &fmt & ~3) + 4);
    return Util_VSNPrintF(dst, len, fmt, args);
}

// Util_SNPrintF with the arguments already collected. Handles %d %i %u %o %x %X %p %c %s %n and %%, with the flags
// space + - 0, a width and precision (also from the arguments), and the h, hh, l and ll sizes.
int Util_VSNPrintF(char *dst, size_t len, const char *fmt, char *args) {
    int width;
    int nBuf;
    int nPrefix;
    int flag;
    int precision;
    int nZero;
    char ch;
    int radix;
    int hexChar;
    const char *specStart;
    char flagCh;
    int strLen;
    int written;
    u64 value;
    int charArg;
    const char *string;
    char prefix[2];
    char digits[24];
    dst_string str;

    str.mLen = len;
    str.mBase = dst;
    str.mCur = dst;
    while (*fmt != 0) {
        ch = *(const s8 *) fmt;
        if ((u32) (((u8) ch ^ 0x20) - 0xa1) < 0x3c) {
            Util_PrintContext_ApppendChar(&str, ch);
            ch = *++fmt;
            if (ch != 0) {
                fmt++;
                Util_PrintContext_ApppendChar(&str, ch);
            }
            continue;
        }
        if (ch != '%') {
            fmt++;
            Util_PrintContext_ApppendChar(&str, ch);
            continue;
        }
        flag = 0;
        precision = -1;
        width = 0;
        radix = PRINTF_RADIX_DECIMAL;
        hexChar = 0x57;
        specStart = fmt;
        for (;;) {
            flagCh = *++fmt;
            switch (flagCh) {
                case '+':
                    if (fmt[-1] == ' ') {
                        flag |= 2;
                        continue;
                    }
                    break;
                case ' ':
                    flag |= 1;
                    continue;
                case '-':
                    flag |= 8;
                    continue;
                case '0':
                    flag |= 0x10;
                    continue;
            }
            break;
        }
        if (flagCh == '*') {
            args += 4;
            width = *(int *) (args - 4);
            fmt++;
            if (width < 0) {
                width = -width;
                flag |= 8;
            }
        } else {
            while (*fmt >= '0' && *fmt <= '9') {
                width = width * 10 + *fmt++ - '0';
            }
        }
        if (*fmt == '.') {
            precision = 0;
            if (*++fmt == '*') {
                args += 4;
                precision = *(int *) (args - 4);
                fmt++;
                if (precision < 0) {
                    precision = -1;
                }
            } else {
                while (*fmt >= '0' && *fmt <= '9') {
                    precision = precision * 10 + *fmt++ - '0';
                }
            }
        }
        switch (*fmt) {
            case 'h':
                if (*++fmt != 'h') {
                    flag |= 0x40;
                } else {
                    fmt++;
                    flag |= 0x100;
                }
                break;
            case 'l':
                if (*++fmt != 'l') {
                    flag |= 0x20;
                } else {
                    fmt++;
                    flag |= 0x80;
                }
                break;
        }
        switch (*fmt) {
            case 'd':
            case 'i':
                goto label_int;
            case 'o':
                radix = PRINTF_RADIX_OCTAL;
                flag |= 0x1000;
                goto label_int;
            case 'u':
                flag |= 0x1000;
                goto label_int;
            case 'X':
                hexChar = 0x37;
                goto labelHex;
            case 'p':
                flag |= 4;
                precision = 8;
                goto labelHex;
            case 'x':
                goto labelHex;
            case 'c':
                if (precision >= 0) {
                    goto label_copy;
                }
                args += 4;
                charArg = *(int *) (args - 4);
                if (flag & 8) {
                    Util_PrintContext_ApppendChar(&str, charArg);
                    Util_PrintContext_FillWith(&str, ' ', width - 1);
                } else {
                    Util_PrintContext_FillWith(&str, (flag & 0x10) ? '0' : ' ', width - 1);
                    Util_PrintContext_ApppendChar(&str, charArg);
                }
                fmt++;
                continue;
            case 's':
                args += 4;
                strLen = 0;
                string = *(const char **) (args - 4);
                if (precision < 0) {
                    while (string[strLen] != 0) {
                        strLen++;
                    }
                } else {
                    while (strLen < precision && string[strLen] != 0) {
                        strLen++;
                    }
                }
                width -= strLen;
                if (flag & 8) {
                    Util_PrintContext_AppendString(&str, string, strLen);
                    Util_PrintContext_FillWith(&str, ' ', width);
                } else {
                    Util_PrintContext_FillWith(&str, (flag & 0x10) ? '0' : ' ', width);
                    Util_PrintContext_AppendString(&str, string, strLen);
                }
                fmt++;
                continue;
            case 'n':
                written = str.mCur - str.mBase;
                if (!(flag & 0x100)) {
                    if (flag & 0x40) {
                        args += 4;
                        **(s16 **) (args - 4) = written;
                    } else if (flag & 0x80) {
                        args += 4;
                        **(s64 **) (args - 4) = written;
                    } else {
                        args += 4;
                        **(int **) (args - 4) = written;
                    }
                }
                fmt++;
                continue;
            case '%':
                if (specStart + 1 == fmt) {
                    Util_PrintContext_ApppendChar(&str, *fmt++);
                    continue;
                }
            default:
            label_copy:
                Util_PrintContext_AppendString(&str, specStart, fmt - specStart);
                continue;
        }
    labelHex:
        radix = PRINTF_RADIX_HEX;
        flag |= 0x1000;
    label_int:
        nPrefix = 0;
        if (flag & 8) {
            flag &= ~0x10;
        }
        if (precision >= 0) {
            flag &= ~0x10;
        } else {
            precision = 1;
        }
        if (flag & 0x1000) {
            if (flag & 0x100) {
                args += 4;
                value = *(u8 *) (args - 4);
            } else if (flag & 0x40) {
                args += 4;
                value = *(u16 *) (args - 4);
            } else if (flag & 0x80) {
                args += 8;
                value = *(u64 *) (args - 8);
            } else {
                args += 4;
                value = *(u32 *) (args - 4);
            }
            flag &= ~3;
            if (flag & 4) {
                if (radix == PRINTF_RADIX_HEX) {
                    if (value != 0) {
                        prefix[1] = '0';
                        prefix[0] = hexChar + 0x21;
                        nPrefix = 2;
                    }
                } else if (radix == PRINTF_RADIX_OCTAL) {
                    prefix[0] = '0';
                    nPrefix = 1;
                }
            }
        } else {
            if (flag & 0x100) {
                args += 4;
                value = *(s8 *) (args - 4);
            } else if (flag & 0x40) {
                args += 4;
                value = *(s16 *) (args - 4);
            } else if (flag & 0x80) {
                args += 8;
                value = *(s64 *) (args - 8);
            } else {
                args += 4;
                value = *(int *) (args - 4);
            }
            if ((value >> 32) & 0x80000000) {
                prefix[0] = '-';
                value = ~value + 1;
                nPrefix = 1;
            } else if (value != 0 || precision != 0) {
                if (flag & 2) {
                    prefix[0] = '+';
                    nPrefix = 1;
                } else if (flag & 1) {
                    prefix[0] = ' ';
                    nPrefix = 1;
                }
            }
        }
        nBuf = 0;
        switch (radix) {
            case PRINTF_RADIX_OCTAL:
                while (value != 0) {
                    int digit = value & 7;
                    value >>= 3;
                    digits[nBuf++] = digit + '0';
                }
                break;
            case PRINTF_RADIX_DECIMAL:
                if ((value >> 32) == 0) {
                    u32 low = value;
                    while (low != 0) {
                        u32 quot = low / 10;
                        int digit = low - quot * 10;
                        low = quot;
                        digits[nBuf++] = digit + '0';
                    }
                } else {
                    while (value != 0) {
                        u64 quot = value / 10;
                        digits[nBuf++] = (int) (value - quot * 10) + '0';
                        value = quot;
                    }
                }
                break;
            case PRINTF_RADIX_HEX:
                while (value != 0) {
                    int digit = value & 0xf;
                    value >>= 4;
                    if (digit < 10) {
                        digit += '0';
                    } else {
                        digit += hexChar;
                    }
                    digits[nBuf++] = digit;
                }
                break;
        }
        if (nPrefix > 0 && prefix[0] == '0') {
            digits[nBuf++] = '0';
            nPrefix = 0;
        }
        nZero = precision - nBuf;
        if (flag & 0x10) {
            if (nZero < width - nBuf - nPrefix) {
                nZero = width - nBuf - nPrefix;
            }
        }
        if (nZero > 0) {
            width -= nZero;
        }
        width -= nPrefix + nBuf;
        if (!(flag & 8)) {
            Util_PrintContext_FillWith(&str, ' ', width);
        }
        while (nPrefix > 0) {
            Util_PrintContext_ApppendChar(&str, prefix[--nPrefix]);
        }
        Util_PrintContext_FillWith(&str, '0', nZero);
        while (nBuf > 0) {
            Util_PrintContext_ApppendChar(&str, digits[--nBuf]);
        }
        if (flag & 8) {
            Util_PrintContext_FillWith(&str, ' ', width);
        }
        fmt++;
    }
    if (str.mLen != 0) {
        *str.mCur = 0;
    } else if (len != 0) {
        *(str.mBase + len - 1) = 0;
    }
    return str.mCur - str.mBase;
}
