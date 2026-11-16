#pragma avoid_byte all

#include "narrow_string_functions.h"
#include "text_to_number.h"

double atof(const char *string) {
    return strtod(string, 0);
}

u32 strlen(const char *string) {
    u32 length = -1;
    u32 currentChar;

    do {
        currentChar = *string++;
        length++;
    } while (currentChar != 0);
    return length;
}

char *strcpy(char *dst, const char *src) {
    char *cursor;
    u32 srcAlign;
    u32 dstAlign;
    u32 word;
    u32 zeroTestAdd;
    u32 zeroTestMask;
    u32 sum;
    u32 headCount;

    cursor = dst;
    srcAlign = (u32) src & 3;
    dstAlign = (u32) dst & 3;
    if (dstAlign == srcAlign) {
        if (srcAlign != 0) {
            *dst = *src;
            if (*dst == 0) {
                return dst;
            }
            headCount = 3 - srcAlign;
            if (headCount != 0) {
                do {
                    *++cursor = *++src;
                    if (*cursor == 0) {
                        return dst;
                    }
                } while (--headCount != 0);
            }
            cursor++;
            src++;
        }
        word = *(u32 *) src;
        zeroTestAdd = 0xfefefeff;
        zeroTestMask = 0x80808080;
        sum = word + zeroTestAdd;
        if ((sum & zeroTestMask) == 0) {
            cursor -= 4;
            do {
                cursor += 4;
                *(u32 *) cursor = word;
                src += 4;
                word = *(u32 *) src;
                sum = word + zeroTestAdd;
            } while ((sum & zeroTestMask) == 0);
            cursor += 4;
        }
    }
    *cursor = *src;
    if (*cursor == 0) {
        return dst;
    }
    do {
        *++cursor = *++src;
    } while (*cursor != 0);
    return dst;
}

char *SomeStrncpy_0(char *dst, const char *src, u32 count) {
    char *cursor;

    cursor = dst;
    for (; count != 0; count--) {
        if ((*cursor++ = *src++) == 0) {
            while (--count != 0) {
                *cursor++ = 0;
            }
            break;
        }
    }
    return dst;
}

char *strcat(char *dst, const char *src) {
    char *cursor;
    char *last;

    cursor = dst;
    while (*cursor++ != 0) {
    }
    cursor--;
    do {
        last = cursor;
        *cursor++ = *src++;
    } while (*last != 0);
    return dst;
}

int strcmp(const char *left, const char *right) {
    u32 leftValue;
    u32 diff;
    u32 leftByte;
    u32 byteDiff;
    u32 rightValue;
    u32 zeroTestAdd;
    u32 zeroTestMask;
    u32 leftAlign;
    u32 rightAlign;

    leftValue = *left;
    diff = leftValue - *right;
    if (diff != 0) {
        return diff;
    }
    leftAlign = (u32) left & 3;
    rightAlign = (u32) right & 3;
    if (rightAlign == leftAlign) {
        if (leftAlign != 0) {
            if (leftValue == 0) {
                return 0;
            }
            leftAlign = 3 - leftAlign;
            if (leftAlign != 0) {
                do {
                    leftByte = *++left;
                    byteDiff = leftByte - *++right;
                    if (byteDiff != 0) {
                        return byteDiff;
                    }
                    if (leftByte == 0) {
                        return 0;
                    }
                } while (--leftAlign != 0);
            }
            left++;
            right++;
        }
        leftValue = *(u32 *) left;
        zeroTestAdd = 0xfefefeff;
        zeroTestMask = 0x80808080;
        rightValue = *(u32 *) right;
        if (((leftValue + zeroTestAdd) & zeroTestMask) == 0) {
            if (leftValue == rightValue) {
                do {
                    leftValue = *(u32 *) (left += 4);
                    rightValue = *(u32 *) (right += 4);
                    if (((leftValue + zeroTestAdd) & zeroTestMask) != 0) {
                        goto tail;
                    }
                } while (leftValue == rightValue);
            }
            left--;
            right--;
            goto slow;
        }
    tail:
        leftValue = *left;
        diff = leftValue - *right;
        if (diff != 0) {
            return diff;
        }
    }
slow:
    if (leftValue == 0) {
        return 0;
    }
    do {
        leftByte = *++left;
        byteDiff = leftByte - *++right;
        if (byteDiff != 0) {
            return byteDiff;
        }
    } while (leftByte != 0);
    return 0;
}

int strncmp(const char *left, const char *right, u32 count) {
    u32 leftChar;
    u32 rightChar;

    if (count != 0) {
        do {
            rightChar = *right++;
            leftChar = *left++;
            if (leftChar != rightChar) {
                return leftChar - rightChar;
            }
            if (leftChar == 0) {
                break;
            }
        } while (--count != 0);
    }
    return 0;
}

char *strchr(const char *string, int chr) {
    u32 current;
    const char *cursor;

    chr = (u8) chr;
    cursor = string + 1;
    current = *string;
    if (current != 0) {
        do {
            if (current == chr) {
                return (char *) (cursor - 1);
            }
            current = *cursor++;
        } while (current != 0);
    }
    if (chr != 0) {
        return 0;
    }
    return (char *) (cursor - 1);
}

char *strstr(const char *haystack, const char *needle) {
    u32 haystackChar;
    const char *cursor;
    u32 needleFirst;
    u32 needleChar;
    const char *haystackScan;
    const char *needleScan;
    u32 scanChar;

    if (needle == 0) {
        return (char *) haystack;
    }
    needleFirst = *needle;
    if (needleFirst == 0) {
        return (char *) haystack;
    }
    cursor = haystack + 1;
    haystackChar = *haystack;
    for (; haystackChar != 0; haystackChar = *cursor++) {
        if (haystackChar == needleFirst) {
            haystackScan = cursor;
            needleScan = needle + 1;
            do {
                needleChar = *needleScan++;
                scanChar = *haystackScan++;
            } while (scanChar == needleChar && scanChar != 0);
            if (needleChar == 0) {
                return (char *) (cursor - 1);
            }
        }
    }
    return 0;
}
