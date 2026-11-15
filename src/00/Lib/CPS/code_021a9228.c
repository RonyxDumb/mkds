#include "00/Lib/CPS/code_021a9228.h"

#include "00/Lib/CPS/code_021ab6d4.h"
#include "00/Lib/CPS/code_021abd2c.h"
#include "00/Lib/CPS/network.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b6000.h"
#include "code_0214d018.h"
#include "00/Lib/CPS/code_021abca0.h"
#include "os_thread.h"
#include "00/Lib/CPS/code_021abc24.h"
#include "code_0200fc8c.h"
#include "00/Lib/CPS/code_021ac3e4.h"
#include "00/code_021ab000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b4000.h"
#include "code_02139f70.h"
#include "00/Lib/CPS/code_021acbf8.h"
#include "00/Lib/CPS/code_021acc8c.h"
#include "code_0214d93c.h"
#include "Main/Net/data_0216f000.h"
#include "mb_data.h"
#include "os_tick.h"
#include "convert.h"

u8 gRandomByteStateMixed;
u32 gNewEntryIdCount;
u8 gRandomByteState[0x14];
HttpsEntry gUncachedHttpsEntry;
HttpsEntry gHttpsEntries[4];

static char sPrefixNone[] = "\xff\xff\xff";
static char sPrefixCommonName[] = "\x55\x04\x03";
u32 gSslLowThreadPriority = 0xffffffff;
static char sPrefixRsaEncryption[] = "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x01";
static char sPrefixRsaAlgorithm[] = "\x55\x08\x01\x01";
static char sPrefixMd5WithRsa[] = "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x04";
static char sPrefixSha1WithRsa[] = "\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05";
u16 gOfferedValues[2] = {4, 5};
const char *gTaggedItemPrefixes[6] = {sPrefixNone,       sPrefixRsaEncryption, sPrefixRsaAlgorithm,
                                      sPrefixMd5WithRsa, sPrefixSha1WithRsa,   sPrefixCommonName};

HttpsEntry *FindEntryByBytesAndSetLastUseTime(const u8 *wantedBytes) {
    s32 entryIndex;
    HttpsEntry *entry;
    entryIndex = 0;
    entry = gHttpsEntries;
    for (; entryIndex < 4; entryIndex++) {
        if (entry->mInUse != 0 && memcmp(entry->mSessionId, wantedBytes, 0x20) == 0) {
            entry->mLastUseTime = OS_GetTick() >> 16;
            return entry;
        }
        entry++;
    }
    return NULL;
}

HttpsEntry *FindEntryByValuePairAndSetLastUseTime(u32 firstValue, u32 secondValue) {
    HttpsEntry *entry;
    s32 entryIndex;
    entryIndex = 0;
    entry = gHttpsEntries;
    for (; entryIndex < 4; entryIndex++) {
        if (entry->mInUse != 0 && entry->mRemoteIp == firstValue && entry->mRemotePort == secondValue) {
            entry->mLastUseTime = OS_GetTick() >> 16;
            return entry;
        }
        entry++;
    }
    return NULL;
}

// Takes the first free entry, else the one stamped longest ago; copies the 0x20 bytes in, stamps it and marks it in
// use.
HttpsEntry *AddEntryOrReplaceLongestUnused(const u8 *bytes) {
    HttpsEntry *chosen;
    u32 now;
    s32 entryIndex;
    u32 idleTime;
    u32 longestIdleTime;
    HttpsEntry *entry;
    now = OS_GetTick() >> 16;
    longestIdleTime = 0;
    chosen = gHttpsEntries;
    entryIndex = 0;
    entry = chosen;
    for (; entryIndex < 4; entryIndex++) {
        if (entry->mInUse == 0) {
            chosen = entry;
            break;
        }
        idleTime = now - entry->mLastUseTime;
        if (idleTime > longestIdleTime) {
            longestIdleTime = idleTime;
            chosen = entry;
        }
        entry++;
    }
    MI_CpuCopy8(bytes, chosen, 0x20);
    chosen->mLastUseTime = now;
    chosen->mInUse = 1;
    return chosen;
}

// The clock's date and time as seconds, plus 0x386d4380.
u32 GetRtcSecondsPlusFixedOffset(void) {
    RTCDate date;
    RTCTime time;
    RTC_GetDate(&date);
    RTC_GetTime(&time);
    return (u32) RTC_ConvertDateTimeToSecond(&date, &time) + 0x386d4380;
}

void SetAuthorityTable(u32 table, u32 count) {
    CPSSoc *connection;
    HttpsState *httpsState;
    connection = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if ((connection != NULL) && (httpsState = connection->mHttpsState, httpsState != NULL)) {
        httpsState->mAuthorities = table;
        httpsState->mAuthorityCount = count;
    }
}

u32 FindAuthorityByName(HttpsState *httpsState, const s8 *name) {
    int authorityCount;
    int index;
    u32 *tableCursor;
    u32 *table;
    int compareResult;
    index = 0;
    authorityCount = httpsState->mAuthorityCount;
    if (0 < authorityCount) {
        table = (u32 *) httpsState->mAuthorities;
        tableCursor = table;
        do {
            compareResult = strcmp((const char *) (*(u32 *) *tableCursor), (const char *) name);
            if (compareResult == 0) {
                return table[index];
            }
            tableCursor = tableCursor + 1;
            index = index + 1;
        } while (index < authorityCount);
    }
    return 0;
}

// Reads a length (one byte below 0x80, else 0x80 + n followed by n big-endian bytes) and moves *a past it; -1 when the
// value would not fit in 32 bits.
s32 ReadLengthAndAdvance(u8 **position) {
    u8 *cursor;
    s32 length;
    u32 lengthByteCount;
    cursor = *position;
    length = *cursor++;
    if ((length & 0x80) != 0) {
        lengthByteCount = length & 0x7f;
        length = 0;
        while (lengthByteCount-- != 0) {
            if ((length & 0xff000000) != 0) {
                return -1;
            }
            length = (length << 8) + *cursor++;
        }
    }
    *position = cursor;
    return length;
}

void AppendCommaSeparatedText(s8 *dest, const s8 *source, s32 count) {
    s8 *start;
    start = dest;
    if (*dest != 0) {
        do {
            dest++;
        } while (*dest != 0);
        if (dest - start >= 0xff) {
            return;
        }
        *dest++ = ',';
        *dest++ = ' ';
    }
    while (count-- != 0 && dest - start < 0xff) {
        *dest++ = *source++;
    }
    *dest = 0;
}

// Returns year << 16 | month << 8 | day from digit text; a tag of 0x17 means a two-digit year, else four digits.
u32 ParseDateText(const u8 *digits, u32 tag) {
    u32 leadingNumber;
    u32 year;
    leadingNumber = digits[1] + digits[0] * 10 - 0x210;
    digits += 2;
    if (tag == 0x17) {
        if (leadingNumber < 0x32) {
            year = leadingNumber + 0x7d0;
        } else {
            year = leadingNumber + 0x76c;
        }
    } else {
        year = leadingNumber * 100 + (digits[1] + digits[0] * 10 - 0x210);
        digits += 2;
    }
    return (year << 16) + ((digits[1] + digits[0] * 10 - 0x210) << 8) + (digits[3] + digits[2] * 10 - 0x210);
}

// Parses one tag-length-value item and the items inside the container tags; returns TRUE on a bad length or a failed
// inner item.
BOOL ParseTaggedItem(HttpsState *httpsState, u8 **position, s32 depth, s32 index, s32 mode) {
    u8 *cursor;
    u32 tag;
    u32 tagKind;
    s32 length;
    u8 *itemEnd;
    s32 failed;
    u8 *itemStart;
    const char *prefix;
    const char **prefixCursor;
    u32 date;
    cursor = *position;
    tag = *cursor++;
    length = ReadLengthAndAdvance(&cursor);
    if (length < 0 || length > 0x7d0) {
        return TRUE;
    }
    tagKind = tag & 0x1f;
    switch (tagKind) {
        case 2:
            if (httpsState->mCaptureValues != 0) {
                if (index == 0) {
                    while (*cursor == 0) {
                        cursor++;
                        length--;
                    }
                    switch (mode) {
                        case 0:
                            if (length <= 0x100) {
                                MI_CpuCopy8(cursor, httpsState->mFirstValue, length);
                                httpsState->mFirstValueLength = length;
                            }
                            break;
                        case 2:
                            httpsState->mItemRecord.mFirstLength = length;
                            httpsState->mItemRecord.mFirstBytes = cursor;
                            break;
                    }
                } else if (index == 1) {
                    while (*cursor == 0) {
                        cursor++;
                        length--;
                    }
                    switch (mode) {
                        case 0:
                            if (length <= 8) {
                                MI_CpuCopy8(cursor, httpsState->mSecondValue, length);
                                httpsState->mSecondValueLength = length;
                            }
                            break;
                        case 2:
                            httpsState->mItemRecord.mSecondLength = length;
                            httpsState->mItemRecord.mSecondBytes = cursor;
                            break;
                    }
                }
            }
            cursor += length;
            break;
        case 3:
            if (depth == 1 && mode != 2) {
                httpsState->mCheckedBytes = cursor + 1;
                httpsState->mCheckedBytesLength = length - 1;
            }
            if (httpsState->mCaptureValues != 0) {
                cursor++;
                if (ParseTaggedItem(httpsState, &cursor, depth, 0, mode) != FALSE) {
                    return TRUE;
                }
                httpsState->mCaptureValues = 0;
            } else {
                cursor += length;
            }
            break;
        case 6:
            failed = 0;
            prefixCursor = gTaggedItemPrefixes;
            itemStart = cursor;
            do {
                prefix = *prefixCursor;
                if (memcmp(itemStart, prefix, strlen(prefix)) == 0) {
                    switch (failed) {
                        case 1:
                        case 2:
                            if (mode == 0) {
                                httpsState->mTaggedItemPrefixIndex = failed;
                            }
                            httpsState->mCaptureValues = failed;
                            break;
                        case 3:
                        case 4:
                            if (mode != 2) {
                                httpsState->mDigestKind = failed;
                            }
                            break;
                        case 5:
                            if (mode != 2) {
                                httpsState->mCopyNextText = failed;
                            }
                            break;
                    }
                    break;
                }
                prefixCursor++;
                failed++;
            } while (failed < 6);
            cursor += length;
            break;
        case 0xc:
        case 0x13:
        case 0x14:
        case 0x16:
            if (mode != 2) {
                if (httpsState->mDatesSeen != 0) {
                    AppendCommaSeparatedText(httpsState->mUnk_684, (const s8 *) cursor, length);
                    if (httpsState->mCopyNextText == 5 && length <= 0x4f) {
                        MI_CpuCopy8(cursor, httpsState->mHostPattern, length);
                        httpsState->mHostPattern[length] = 0;
                    }
                } else {
                    AppendCommaSeparatedText(httpsState->mAuthorityName, (const s8 *) cursor, length);
                }
            }
            httpsState->mCopyNextText = 0;
            cursor += length;
            break;
        case 0x17:
        case 0x18:
            if (mode != 2) {
                date = ParseDateText(cursor, tagKind);
                if (index == 0) {
                    if (httpsState->mCurrentDate >= date) {
                        httpsState->mDateInRange = 1;
                    }
                } else {
                    if (httpsState->mCurrentDate > date) {
                        httpsState->mDateInRange = 0;
                    }
                }
            }
            cursor += length;
            httpsState->mDatesSeen = 1;
            break;
        case 0x10:
            if (depth == 0 && index == 0 && mode != 2) {
                httpsState->mDigestStart = cursor;
            }
            itemEnd = cursor + length;
            length = 0;
            if (cursor < itemEnd) {
                do {
                    failed = ParseTaggedItem(httpsState, &cursor, depth + 1, length, mode);
                    length++;
                    if (failed != 0) {
                        return TRUE;
                    }
                } while (cursor < itemEnd);
            }
            if (depth == 1 && index == 0 && mode != 2) {
                httpsState->mDigestEnd = cursor;
            }
            break;
        case 0x11:
            itemEnd = cursor + length;
            if (cursor < itemEnd) {
                do {
                    if (ParseTaggedItem(httpsState, &cursor, depth + 1, 0, mode) != FALSE) {
                        return TRUE;
                    }
                } while (cursor < itemEnd);
            }
            break;
        default:
            if (tag == 0xa0) {
                itemEnd = cursor + length;
                if (cursor < itemEnd) {
                    do {
                        if (ParseTaggedItem(httpsState, &cursor, depth + 1, 0, mode) != FALSE) {
                            return TRUE;
                        }
                    } while (cursor < itemEnd);
                }
            } else {
                cursor += length;
            }
            break;
    }
    *position = cursor;
    return FALSE;
}

// Returns 0 when the bytes, run through the two values of the authority record, start 00 01, a run of 0xff, 00, 30 and
// end with mRangeDigest, else 2.
u32 CheckTransformedBytesHoldPaddedDigest(HttpsState *httpsState, AuthorityRecord *authority) {
    s32 digitCount;
    u16 *result;
    u16 *checkedDigits;
    u16 *exponent;
    u16 *modulus;
    u32 savedPriority;
    OSThread *thread;
    u32 status;
    enum { K0 } padIndex;
    if (httpsState->mCheckedBytes == NULL || httpsState->mCheckedBytesLength == 0 || authority->mSecondBytes == NULL ||
        authority->mSecondLength == 0 || authority->mFirstBytes == NULL || authority->mFirstLength == 0) {
        return 2;
    }
    digitCount = authority->mFirstLength * 2;
    digitCount = digitCount / 2;
    result = (u16 *) CPSiAlloc(digitCount * 8);
    if (result == NULL) {
        return 2;
    }
    checkedDigits = result + digitCount;
    exponent = checkedDigits + digitCount;
    modulus = exponent + digitCount;
    CPSi_big_from_char(checkedDigits, httpsState->mCheckedBytes, httpsState->mCheckedBytesLength, digitCount);
    CPSi_big_from_char(exponent, authority->mSecondBytes, authority->mSecondLength, digitCount);
    CPSi_big_from_char(modulus, authority->mFirstBytes, authority->mFirstLength, digitCount);
    if (gSslLowThreadPriority < 0x20) {
        thread = OSi_ThreadInfo.mCurrentThread;
        savedPriority = OS_GetThreadPriority(thread);
        OS_SetThreadPriority(thread, gSslLowThreadPriority);
        CPSi_big_power(result, checkedDigits, exponent, digitCount, modulus);
        OS_SetThreadPriority(thread, savedPriority);
    } else {
        CPSi_big_power(result, checkedDigits, exponent, digitCount, modulus);
    }
    CPSi_char_from_big((u8 *) checkedDigits, result, authority->mFirstLength, digitCount);
    status = 0;
    if (((u8 *) checkedDigits)[0] != 0 || ((u8 *) checkedDigits)[1] != 1) {
        status = 2;
    } else {
        padIndex = 2;
        if (authority->mFirstLength > 2) {
            do {
                if (((u8 *) checkedDigits)[padIndex] != 0xff) {
                    break;
                }
                padIndex++;
            } while (padIndex < authority->mFirstLength);
        }
        if (padIndex + 1 >= authority->mFirstLength || ((u8 *) checkedDigits)[padIndex] != 0 ||
            ((u8 *) checkedDigits)[padIndex + 1] != 0x30 ||
            memcmp(httpsState->mRangeDigest,
                   (u8 *) checkedDigits + authority->mFirstLength - httpsState->mRangeDigestLength,
                   httpsState->mRangeDigestLength) != 0) {
            status = 2;
        }
    }
    CPSiFree(result);
    return status;
}

// Flags: 0x8000 when mDateInRange is clear; low byte 1 no authority found, 2 check failed, 3 unknown digest kind, 4
// mTaggedItemPrefixIndex is -1.
u32 ComputeParsedItemCheckFlags(HttpsState *httpsState) {
    u32 flags;
    CPSMd5Ctx *scratchHash16;
    Hash20Context *scratchHash20;
    u32 authority;
    if (httpsState->mDateInRange != 0) {
        flags = 0;
    } else {
        flags = 0x8000;
    }
    if (httpsState->mTaggedItemPrefixIndex == -1) {
        flags |= 4;
        return flags;
    }
    switch (httpsState->mDigestKind) {
        case 3:
            scratchHash16 = &httpsState->mScratchHash16;
            CPSi_md5_init(scratchHash16);
            CPSi_md5_calc(scratchHash16, httpsState->mDigestStart, httpsState->mDigestEnd - httpsState->mDigestStart);
            CPSi_md5_result(scratchHash16, httpsState->mRangeDigest);
            httpsState->mRangeDigestLength = 0x10;
            break;
        case 4:
            scratchHash20 = &httpsState->mScratchHash20;
            CPSi_sha1_init(scratchHash20);
            CPSi_sha1_calc(scratchHash20, httpsState->mDigestStart, httpsState->mDigestEnd - httpsState->mDigestStart);
            CPSi_sha1_result(scratchHash20, httpsState->mRangeDigest);
            httpsState->mRangeDigestLength = 0x14;
            break;
        default:
            flags |= 3;
            return flags;
    }
    authority = FindAuthorityByName(httpsState, httpsState->mAuthorityName);
    if (authority == 0) {
        flags |= 1;
        return flags;
    }
    flags |= CheckTransformedBytesHoldPaddedDigest(httpsState, (AuthorityRecord *) authority);
    return flags;
}

s32 GetTextLengthUpToDot(const s8 *text) {
    const s8 *start = text;
    while (*text != '.' && *text != 0) {
        text++;
    }
    return text - start;
}

// Returns FALSE when the texts match; a '*' in the second matches the first characters of one dot-separated part of the
// first.
BOOL CompareTextWithWildcard(const s8 *text, const s8 *pattern) {
    s32 textPartLength;
    s32 patternPartLength;
    s8 patternChar;
    s8 textChar;
    for (;;) {
        while ((textChar = *text++) == (patternChar = *pattern++)) {
            if (textChar == 0) {
                return FALSE;
            }
        }
        if (patternChar != '*') {
            return TRUE;
        }
        text--;
        textPartLength = GetTextLengthUpToDot(text);
        patternPartLength = GetTextLengthUpToDot(pattern);
        if (patternPartLength > textPartLength) {
            return TRUE;
        }
        text += textPartLength - patternPartLength;
    }
}

// Parses and checks each item of the list message in turn, passing the flags to mCheckFlagsCallback; mSetupState
// becomes HTTPS_SETUP_ITEM_LIST_CHECKED when the last result is 0, else HTTPS_SETUP_FAILED.
void ParseAndCheckItemListMessage(HttpsState *httpsState, u8 *cursor) {
    s32 itemIndex;
    s32 remainingLength;
    u32 flags;
    u32 resultCode;
    BOOL parseMode;
    s32 itemLength;
    u8 *nextItem;
    RTCDate date;
    remainingLength = (((cursor[0] << 8) + cursor[1]) << 8) + cursor[2];
    cursor += 3;
    httpsState->mTaggedItemPrefixIndex = -1;
    RTC_GetDate(&date);
    httpsState->mCurrentDate = date.mDay + (((date.mYear + 0x7d0) << 16) + (date.mMonth << 8));
    httpsState->mUnk_684[0] = 0;
    httpsState->mFirstValueLength = httpsState->mSecondValueLength = 0;
    parseMode = FALSE;
    itemIndex = parseMode;
    for (;;) {
        itemLength = (((cursor[0] << 8) + cursor[1]) << 8) + cursor[2];
        cursor += 3;
        remainingLength -= itemLength + 3;
        httpsState->mDigestKind = -1;
        httpsState->mCaptureValues = 0;
        httpsState->mDatesSeen = 0;
        httpsState->mDateInRange = 0;
        httpsState->mUnk_684[0] = 0;
        httpsState->mAuthorityName[0] = 0;
        httpsState->mHostPattern[0] = 0;
        httpsState->mItemBytes = cursor;
        httpsState->mItemLength = itemLength;
        if (ParseTaggedItem(httpsState, &cursor, 0, 0, parseMode) != 0 || httpsState->mFirstValueLength < 0x33 ||
            httpsState->mSecondValueLength == 0) {
            httpsState->mSetupState = HTTPS_SETUP_FAILED;
            return;
        }
        flags = ComputeParsedItemCheckFlags(httpsState);
        if (itemIndex == 0 && httpsState->mHost != NULL &&
            CompareTextWithWildcard(httpsState->mHost, httpsState->mHostPattern) != 0) {
            flags |= 0x4000;
        }
        resultCode = flags & 0xff;
        if (resultCode == 1 && remainingLength != 0) {
            nextItem = cursor + 3;
            httpsState->mCaptureValues = 0;
            if (ParseTaggedItem(httpsState, &nextItem, 0, 0, 2) != 0) {
                httpsState->mSetupState = HTTPS_SETUP_FAILED;
                return;
            }
            flags = (flags & ~0xff) | CheckTransformedBytesHoldPaddedDigest(httpsState, &httpsState->mItemRecord);
        }
        if (httpsState->mCheckFlagsCallback != NULL) {
            flags = httpsState->mCheckFlagsCallback(flags, httpsState, itemIndex);
        }
        itemIndex++;
        if (resultCode != 0 && flags == 0 && remainingLength != 0) {
            parseMode = TRUE;
            continue;
        }
        break;
    }
    if (flags == 0) {
        httpsState->mSetupState = HTTPS_SETUP_ITEM_LIST_CHECKED;
    } else {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
    }
}

void ParseKind2Message(HttpsState *httpsState, u8 *message) {
    u8 idLength;
    u8 *afterId;
    u8 *idLengthByte;
    HttpsEntry *entry;
    MI_CpuCopy8(message + 2, httpsState->mKind2Block, 0x20);
    idLengthByte = message + 0x22;
    message = (u8 *) message + 0x23;
    idLength = *idLengthByte;
    entry = httpsState->mEntry;
    if (entry != NULL && idLength == 0x20 && memcmp(entry->mSessionId, message, 0x20) == 0) {
        httpsState->mReusedEntry = 1;
    } else {
        if (entry != NULL) {
            entry->mInUse = 0;
        }
        if (idLength == 0) {
            httpsState->mEntry = &gUncachedHttpsEntry;
        } else {
            httpsState->mEntry = AddEntryOrReplaceLongestUnused(message);
        }
        httpsState->mReusedEntry = 0;
    }
    afterId = message + idLength;
    httpsState->mCommonValue = (afterId[0] << 8) + afterId[1];
    httpsState->mSetupState = HTTPS_SETUP_ANSWER_RECEIVED;
}

BOOL IsBigEndianValueInList(const u8 *list, s32 count, s32 width, u32 value) {
    s32 listIndex;
    u32 entryValue;
    for (listIndex = 0; listIndex < count; listIndex++) {
        entryValue = (list[0] << 8) + list[1];
        if (width == 3) {
            entryValue = (entryValue << 8) + list[2];
        }
        if (entryValue == value) {
            return TRUE;
        }
        list += width;
    }
    return FALSE;
}

u32 FindOfferedValueInList(const u8 *list, s32 count, s32 width) {
    u32 offerIndex;
    const u16 *offeredCursor;
    for (offerIndex = 0, offeredCursor = gOfferedValues; offerIndex < 2; offeredCursor++, offerIndex++) {
        if (IsBigEndianValueInList(list, count, width, *offeredCursor) != 0) {
            return gOfferedValues[offerIndex];
        }
    }
    return 0;
}

u32 IsFirstArgumentThree(int value, int unusedArgument) {
    if (value == 3) {
        return 1;
    }
    return 0;
}

void ParseKind1MessageWithThreeByteValues(HttpsState *httpsState, u8 *message) {
    s32 valueListLength;
    u16 offeredValue;
    s32 idLength;
    s32 blockLength;
    if (IsFirstArgumentThree(message[0], message[1]) != 0) {
        valueListLength = (message[2] << 8) + message[3];
        offeredValue = FindOfferedValueInList(message + 8, valueListLength / 3, 3);
        if (offeredValue != 0) {
            httpsState->mCommonValue = offeredValue;
            idLength = (message[4] << 8) + message[5];
            blockLength = (message[6] << 8) + message[7];
            httpsState->mEntry = NULL;
            message += valueListLength + 8 + idLength;
            if (blockLength >= 0x20) {
                MI_CpuCopy8(message, httpsState->mKind1Block, 0x20);
            } else {
                MI_CpuFill8(httpsState->mKind1Block, 0, 0x20 - blockLength);
                MI_CpuCopy8(message, httpsState->mKind2Block - blockLength, blockLength);
            }
            httpsState->mSetupState = HTTPS_SETUP_OFFER_RECEIVED;
        }
    }
}

void ParseKind1Message(HttpsState *httpsState, const u8 *message) {
    u8 idLength;
    u16 offeredValue;
    const u8 *cursor;
    if (IsFirstArgumentThree(message[0], message[1]) != 0) {
        MI_CpuCopy8(message + 2, httpsState->mKind1Block, 0x20);
        idLength = message[0x22];
        cursor = message + 0x23;
        if (idLength != 0x20) {
            httpsState->mEntry = NULL;
        } else {
            httpsState->mEntry = FindEntryByBytesAndSetLastUseTime(cursor);
        }
        cursor += idLength;
        offeredValue = FindOfferedValueInList(cursor + 2, ((cursor[0] << 8) + cursor[1]) / 2, 2);
        httpsState->mCommonValue = offeredValue;
        if (offeredValue != 0) {
            httpsState->mSetupState = HTTPS_SETUP_OFFER_RECEIVED;
        }
    }
}

// Transforms the bytes in b with the six length and pointer pairs of c and writes 0x30 bytes to a.
void decrypt_premaster_secret(u8 *secret, const u8 *encrypted, CPSPrivateKey *privateKey) {
    u16 *workBlock;
    u16 *keyBlock;
    u16 *productBlock;
    u16 *firstPowerBlock;
    u16 *secondPowerBlock;
    u16 *primeBlock;
    u16 *outputBlock;
    u16 *divisionWork;
    s32 digitCount;
    if (privateKey == NULL || privateKey->mModulusLength == 0) {
        return;
    }
    digitCount = privateKey->mModulusLength * 2;
    digitCount = digitCount / 2 + 1;
    workBlock = (u16 *) CPSiAlloc(digitCount * 0x14);
    if (workBlock == NULL) {
        return;
    }
    keyBlock = workBlock + digitCount;
    productBlock = keyBlock + digitCount;
    firstPowerBlock = productBlock + digitCount;
    secondPowerBlock = firstPowerBlock + digitCount;
    primeBlock = secondPowerBlock + digitCount;
    outputBlock = primeBlock + digitCount;
    divisionWork = outputBlock + digitCount;
    CPSi_big_from_char(workBlock, encrypted, privateKey->mModulusLength, digitCount);
    CPSi_big_from_char(keyBlock, privateKey->mExponent1, privateKey->mExponent1Length, digitCount);
    CPSi_big_from_char(primeBlock, privateKey->mPrime1, privateKey->mPrime1Length, digitCount);
    CPSi_big_montpower(firstPowerBlock, workBlock, keyBlock, digitCount, primeBlock);
    CPSi_big_from_char(keyBlock, privateKey->mExponent2, privateKey->mExponent2Length, digitCount);
    CPSi_big_from_char(primeBlock, privateKey->mPrime2, privateKey->mPrime2Length, digitCount);
    CPSi_big_montpower(secondPowerBlock, workBlock, keyBlock, digitCount, primeBlock);
    CPSi_big_sub(workBlock, firstPowerBlock, secondPowerBlock, digitCount);
    CPSi_big_from_char(keyBlock, privateKey->mCoefficient, privateKey->mCoefficientLength, digitCount);
    CPSi_big_mult(productBlock, workBlock, keyBlock, digitCount);
    CPSi_big_from_char(keyBlock, privateKey->mPrime2, privateKey->mPrime2Length, digitCount);
    CPSi_big_mult(workBlock, productBlock, keyBlock, digitCount);
    CPSi_big_add(productBlock, workBlock, secondPowerBlock, digitCount);
    CPSi_big_from_char(keyBlock, privateKey->mModulus, privateKey->mModulusLength, digitCount);
    if (CPSi_big_sign(productBlock, digitCount) < 0) {
        CPSi_big_negate(productBlock, digitCount);
        CPSi_big_div(NULL, productBlock, keyBlock, outputBlock, digitCount, divisionWork);
        CPSi_big_sub(outputBlock, keyBlock, outputBlock, digitCount);
    } else {
        CPSi_big_div(NULL, productBlock, keyBlock, outputBlock, digitCount, divisionWork);
    }
    CPSi_char_from_big(secret, outputBlock, 0x30, digitCount);
    CPSiFree(workBlock);
}

void ComputeLabeledDigest16(u8 *digest, const u8 *label, HttpsState *httpsState) {
    u8 innerDigest[0x14];
    Hash20Context *hash20;
    CPSMd5Ctx *hash16;
    hash20 = &httpsState->mScratchHash20;
    CPSi_sha1_init(hash20);
    CPSi_sha1_calc(hash20, label, strlen((const char *) label));
    CPSi_sha1_calc(hash20, httpsState->mEntry->mMasterSecret, 0x30);
    CPSi_sha1_calc(hash20, httpsState->mKind1Block, 0x20);
    CPSi_sha1_calc(hash20, httpsState->mKind2Block, 0x20);
    CPSi_sha1_result(hash20, innerDigest);
    hash16 = &httpsState->mScratchHash16;
    CPSi_md5_init(hash16);
    CPSi_md5_calc(hash16, httpsState->mEntry->mMasterSecret, 0x30);
    CPSi_md5_calc(hash16, innerDigest, 0x14);
    CPSi_md5_result(hash16, digest);
}

void ReplaceEntryBytesWithLabeledDigests(HttpsState *httpsState) {
    u8 firstDigest[16];
    u8 secondDigest[16];
    u8 thirdDigest[16];
    ComputeLabeledDigest16(firstDigest, (const u8 *) "A", httpsState);
    ComputeLabeledDigest16(secondDigest, (const u8 *) "BB", httpsState);
    ComputeLabeledDigest16(thirdDigest, (const u8 *) "CCC", httpsState);
    MI_CpuCopy8(firstDigest, httpsState->mEntry->mMasterSecret, 0x30);
}

// Fills mDerivedBytes from digests, splits it between the send and receive members and seeds the two key stream states.
void DeriveBytesAndInitKeyStreamStates(HttpsState *httpsState) {
    s32 digestLength;
    s32 keyStreamLength;
    s32 extraLength;
    s32 totalLength;
    s32 outputOffset;
    s32 blockIndex;
    s32 repeatIndex;
    u8 labelAndDigest[0x15];
    void *hashContext;
    switch (httpsState->mCommonValue) {
        case HTTPS_COMMON_VALUE_MD5:
            digestLength = 0x10;
            keyStreamLength = 0x10;
            extraLength = 0;
            break;
        case HTTPS_COMMON_VALUE_HASH20:
            digestLength = 0x14;
            keyStreamLength = 0x10;
            extraLength = 0;
            break;
    }
    totalLength = (digestLength + keyStreamLength + extraLength) * 2;
    blockIndex = 0;
    if (totalLength > 0) {
        outputOffset = 0;
        do {
            hashContext = &httpsState->mScratchHash20;
            CPSi_sha1_init(hashContext);
            labelAndDigest[0] = blockIndex + 0x41;
            for (repeatIndex = 0; repeatIndex < blockIndex + 1; repeatIndex++) {
                CPSi_sha1_calc(hashContext, labelAndDigest, 1);
            }
            CPSi_sha1_calc(hashContext, httpsState->mEntry->mMasterSecret, 0x30);
            CPSi_sha1_calc(hashContext, httpsState->mKind2Block, 0x20);
            CPSi_sha1_calc(hashContext, httpsState->mKind1Block, 0x20);
            CPSi_sha1_result(hashContext, labelAndDigest + 1);
            hashContext = &httpsState->mScratchHash16;
            CPSi_md5_init(hashContext);
            CPSi_md5_calc(hashContext, httpsState->mEntry->mMasterSecret, 0x30);
            CPSi_md5_calc(hashContext, labelAndDigest + 1, 0x14);
            CPSi_md5_result(hashContext, httpsState->mDerivedBytes + outputOffset);
            outputOffset += 0x10;
            blockIndex++;
        } while (outputOffset < totalLength);
    }
    if (httpsState->mReceivesKind1Record != 0) {
        httpsState->mReceiveDigestBytes = httpsState->mDerivedBytes;
        httpsState->mReceiveKeyStreamBytes = httpsState->mReceiveDigestBytes + digestLength * 2;
        httpsState->mUnk_1b0 = httpsState->mReceiveKeyStreamBytes + keyStreamLength * 2;
        httpsState->mSendDigestBytes = httpsState->mDerivedBytes + digestLength;
        httpsState->mSendKeyStreamBytes = httpsState->mSendDigestBytes + digestLength + keyStreamLength;
        httpsState->mUnk_098 = httpsState->mSendKeyStreamBytes + keyStreamLength + extraLength;
    } else {
        httpsState->mSendDigestBytes = httpsState->mDerivedBytes;
        httpsState->mSendKeyStreamBytes = httpsState->mSendDigestBytes + digestLength * 2;
        httpsState->mUnk_098 = httpsState->mSendKeyStreamBytes + keyStreamLength * 2;
        httpsState->mReceiveDigestBytes = httpsState->mDerivedBytes + digestLength;
        httpsState->mReceiveKeyStreamBytes = httpsState->mReceiveDigestBytes + digestLength + keyStreamLength;
        httpsState->mUnk_1b0 = httpsState->mReceiveKeyStreamBytes + keyStreamLength + extraLength;
    }
    CPSi_rc4_init(httpsState->mReceiveKeyStreamState, httpsState->mReceiveKeyStreamBytes, 0x10);
    CPSi_rc4_init(httpsState->mSendKeyStreamState, httpsState->mSendKeyStreamBytes, 0x10);
}

// Recovers the entry's 0x30 bytes from the encrypted secret, derives the key bytes and sets mSetupState to
// HTTPS_SETUP_KEYS_DERIVED.
void rcv_client_key_exchange(HttpsState *httpsState, const u8 *encryptedSecret) {
    decrypt_premaster_secret(httpsState->mEntry->mMasterSecret, encryptedSecret, httpsState->mPrivateKey);
    ReplaceEntryBytesWithLabeledDigests(httpsState);
    DeriveBytesAndInitKeyStreamStates(httpsState);
    httpsState->mSetupState = HTTPS_SETUP_KEYS_DERIVED;
}

void ComputeLabeledMessageDigest16(HttpsState *httpsState, u8 *digest, u32 fromOtherSide) {
    u8 padBytes[0x30];
    CPSMd5Ctx *messageHash;
    messageHash = &httpsState->mMessageHash16;
    if ((httpsState->mReceivesKind1Record ^ fromOtherSide) != 0) {
        CPSi_md5_calc(messageHash, (const u8 *) "SRVR", 4);
    } else {
        CPSi_md5_calc(messageHash, (const u8 *) "CLNT", 4);
    }
    CPSi_md5_calc(messageHash, httpsState->mEntry->mMasterSecret, 0x30);
    MI_CpuFill8(padBytes, 0x36, 0x30);
    CPSi_md5_calc(messageHash, padBytes, 0x30);
    CPSi_md5_result(messageHash, digest);
    CPSi_md5_init(messageHash);
    CPSi_md5_calc(messageHash, httpsState->mEntry->mMasterSecret, 0x30);
    MI_CpuFill8(padBytes, 0x5c, 0x30);
    CPSi_md5_calc(messageHash, padBytes, 0x30);
    CPSi_md5_calc(messageHash, digest, 0x10);
    CPSi_md5_result(messageHash, digest);
}

void ComputeLabeledMessageDigest20(HttpsState *httpsState, u8 *digest, u32 fromOtherSide) {
    u8 padBytes[0x28];
    Hash20Context *messageHash;
    messageHash = &httpsState->mMessageHash20;
    if ((httpsState->mReceivesKind1Record ^ fromOtherSide) != 0) {
        CPSi_sha1_calc(messageHash, (const u8 *) "SRVR", 4);
    } else {
        CPSi_sha1_calc(messageHash, (const u8 *) "CLNT", 4);
    }
    CPSi_sha1_calc(messageHash, httpsState->mEntry->mMasterSecret, 0x30);
    MI_CpuFill8(padBytes, 0x36, 0x28);
    CPSi_sha1_calc(messageHash, padBytes, 0x28);
    CPSi_sha1_result(messageHash, digest);
    CPSi_sha1_init(messageHash);
    CPSi_sha1_calc(messageHash, httpsState->mEntry->mMasterSecret, 0x30);
    MI_CpuFill8(padBytes, 0x5c, 0x28);
    CPSi_sha1_calc(messageHash, padBytes, 0x28);
    CPSi_sha1_calc(messageHash, digest, 0x14);
    CPSi_sha1_result(messageHash, digest);
}

void CheckMessageDigestsAndSetState(HttpsState *httpsState, u8 *receivedDigests) {
    int compareResult;
    u8 ownDigest[20];
    MI_CpuCopy8(&httpsState->mMessageHash16, &httpsState->mScratchHash16, 0x58);
    ComputeLabeledMessageDigest16(httpsState, ownDigest, 1);
    MI_CpuCopy8(&httpsState->mScratchHash16, &httpsState->mMessageHash16, 0x58);
    compareResult = memcmp(receivedDigests, ownDigest, 0x10);
    if (compareResult != 0) {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return;
    }
    MI_CpuCopy8(&httpsState->mMessageHash20, &httpsState->mScratchHash20, 0x5c);
    ComputeLabeledMessageDigest20(httpsState, ownDigest, 1);
    MI_CpuCopy8(&httpsState->mScratchHash20, &httpsState->mMessageHash20, 0x5c);
    compareResult = memcmp(receivedDigests + 0x10, ownDigest, 0x14);
    if (compareResult != 0) {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return;
    }
    httpsState->mSetupState = HTTPS_SETUP_DIGESTS_MATCHED;
}

void IncrementBigEndianBytes(u8 *bytes, s32 count) {
    s32 byteIndex;
    bytes += count;
    for (byteIndex = 0; byteIndex < count; byteIndex++) {
        bytes--;
        (*bytes)++;
        if (*bytes != 0) {
            break;
        }
    }
}

u32 XorReceivedBytesWithKeyStream(u32 httpsState, u8 *bytes, u32 count) {
    u32 byteCount = ((count) + (0x0u));
    u32 keyStreamOffset = 0x1b4u;
    u32 keyStreamState = ((httpsState) + (keyStreamOffset));
    u32 resultCount;
    CPSi_rc4_crypt((u8 *) keyStreamState, bytes, count);
    resultCount = ((byteCount) + (0x0u));
    return resultCount;
}

s32 XorReceivedRecordWithKeyStreamAndCheckDigest(HttpsState *httpsState, u8 *record) {
    u8 computedDigest[0x14];
    u8 padBytes[0x30];
    s32 payloadLength;
    u32 digestLength;
    CPSMd5Ctx *scratchHash16;
    Hash20Context *scratchHash20;
    payloadLength = XorReceivedBytesWithKeyStream((u32) httpsState, (record + 5), (record[3] << 8) + record[4]);
    switch (httpsState->mCommonValue) {
        case HTTPS_COMMON_VALUE_MD5:
            payloadLength -= 0x10;
            record[3] = payloadLength >> 8;
            record[4] = payloadLength;
            scratchHash16 = &httpsState->mScratchHash16;
            CPSi_md5_init(scratchHash16);
            CPSi_md5_calc(scratchHash16, httpsState->mReceiveDigestBytes, 0x10);
            MI_CpuFill8(padBytes, 0x36, 0x30);
            CPSi_md5_calc(scratchHash16, padBytes, 0x30);
            CPSi_md5_calc(scratchHash16, httpsState->mReceiveRecordCount, 8);
            CPSi_md5_calc(scratchHash16, record, 1);
            CPSi_md5_calc(scratchHash16, record + 3, 2);
            CPSi_md5_calc(scratchHash16, record + 5, payloadLength);
            CPSi_md5_result(scratchHash16, computedDigest);
            CPSi_md5_init(scratchHash16);
            CPSi_md5_calc(scratchHash16, httpsState->mReceiveDigestBytes, 0x10);
            MI_CpuFill8(padBytes, 0x5c, 0x30);
            CPSi_md5_calc(scratchHash16, padBytes, 0x30);
            CPSi_md5_calc(scratchHash16, computedDigest, 0x10);
            CPSi_md5_result(scratchHash16, computedDigest);
            digestLength = 0x10;
            break;
        case HTTPS_COMMON_VALUE_HASH20:
            payloadLength -= 0x14;
            record[3] = payloadLength >> 8;
            record[4] = payloadLength;
            scratchHash20 = &httpsState->mScratchHash20;
            CPSi_sha1_init(scratchHash20);
            CPSi_sha1_calc(scratchHash20, httpsState->mReceiveDigestBytes, 0x14);
            MI_CpuFill8(padBytes, 0x36, 0x28);
            CPSi_sha1_calc(scratchHash20, padBytes, 0x28);
            CPSi_sha1_calc(scratchHash20, httpsState->mReceiveRecordCount, 8);
            CPSi_sha1_calc(scratchHash20, record, 1);
            CPSi_sha1_calc(scratchHash20, record + 3, 2);
            CPSi_sha1_calc(scratchHash20, record + 5, payloadLength);
            CPSi_sha1_result(scratchHash20, computedDigest);
            CPSi_sha1_init(scratchHash20);
            CPSi_sha1_calc(scratchHash20, httpsState->mReceiveDigestBytes, 0x14);
            MI_CpuFill8(padBytes, 0x5c, 0x28);
            CPSi_sha1_calc(scratchHash20, padBytes, 0x28);
            CPSi_sha1_calc(scratchHash20, computedDigest, 0x14);
            CPSi_sha1_result(scratchHash20, computedDigest);
            digestLength = 0x14;
            break;
    }
    if (memcmp(record + 5 + payloadLength, computedDigest, digestLength) != 0) {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
    }
    IncrementBigEndianBytes(httpsState->mReceiveRecordCount, 8);
    return payloadLength + 5;
}

s32 AppendDigestAndXorSentRecordWithKeyStream(void *rawHttpsState, u8 *recordArg) {
    HttpsState *httpsState = rawHttpsState;
    u8 *record = recordArg;
    s32 payloadLength = (record[3] << 8) + record[4];
    u8 *digestPosition = record + 5 + payloadLength;
    u8 padBytes[0x30];
    CPSMd5Ctx *scratchHash16;
    Hash20Context *scratchHash20;
    switch (httpsState->mCommonValue) {
        case HTTPS_COMMON_VALUE_MD5:
            scratchHash16 = &httpsState->mScratchHash16;
            CPSi_md5_init(scratchHash16);
            CPSi_md5_calc(scratchHash16, httpsState->mSendDigestBytes, 0x10);
            MI_CpuFill8(padBytes, 0x36, 0x30);
            CPSi_md5_calc(scratchHash16, padBytes, 0x30);
            CPSi_md5_calc(scratchHash16, httpsState->mSendRecordCount, 8);
            CPSi_md5_calc(scratchHash16, record, 1);
            CPSi_md5_calc(scratchHash16, record + 3, 2);
            CPSi_md5_calc(scratchHash16, record + 5, payloadLength);
            CPSi_md5_result(scratchHash16, digestPosition);
            CPSi_md5_init(scratchHash16);
            CPSi_md5_calc(scratchHash16, httpsState->mSendDigestBytes, 0x10);
            MI_CpuFill8(padBytes, 0x5c, 0x30);
            CPSi_md5_calc(scratchHash16, padBytes, 0x30);
            CPSi_md5_calc(scratchHash16, digestPosition, 0x10);
            CPSi_md5_result(scratchHash16, digestPosition);
            payloadLength += 0x10;
            break;
        case HTTPS_COMMON_VALUE_HASH20:
            scratchHash20 = &httpsState->mScratchHash20;
            CPSi_sha1_init(scratchHash20);
            CPSi_sha1_calc(scratchHash20, httpsState->mSendDigestBytes, 0x14);
            MI_CpuFill8(padBytes, 0x36, 0x28);
            CPSi_sha1_calc(scratchHash20, padBytes, 0x28);
            CPSi_sha1_calc(scratchHash20, httpsState->mSendRecordCount, 8);
            CPSi_sha1_calc(scratchHash20, record, 1);
            CPSi_sha1_calc(scratchHash20, record + 3, 2);
            CPSi_sha1_calc(scratchHash20, record + 5, payloadLength);
            CPSi_sha1_result(scratchHash20, digestPosition);
            CPSi_sha1_init(scratchHash20);
            CPSi_sha1_calc(scratchHash20, httpsState->mSendDigestBytes, 0x14);
            MI_CpuFill8(padBytes, 0x5c, 0x28);
            CPSi_sha1_calc(scratchHash20, padBytes, 0x28);
            CPSi_sha1_calc(scratchHash20, digestPosition, 0x14);
            CPSi_sha1_result(scratchHash20, digestPosition);
            payloadLength += 0x14;
            break;
    }
    record[3] = payloadLength >> 8;
    record[4] = payloadLength;
    CPSi_rc4_crypt(httpsState->mSendKeyStreamState, (record + 5), payloadLength);
    IncrementBigEndianBytes(httpsState->mSendRecordCount, 8);
    return payloadLength + 5;
}

u32 ReadExactReceivedBytes(u8 *dest, s32 count, CPSSoc *connection) {
    u8 *chunk;
    u32 chunkLength;
    do {
        chunk = CPSi_TcpReadRaw(&chunkLength, connection);
        if (chunkLength == 0) {
            return 0xffffffff;
        }
        if (chunkLength > count) {
            chunkLength = count;
        }
        MI_CpuCopy8(chunk, dest, chunkLength);
        CPSi_SocConsumeRaw(chunkLength, connection);
        dest = dest + chunkLength;
        count = count - chunkLength;
    } while (0 < count);
    return 0;
}

// Reads one record, checks and xors it when mSetupState is HTTPS_SETUP_CIPHER_RECORD_RECEIVED or
// HTTPS_SETUP_COMPLETE, runs the handler of its kind and returns mSetupState.
u8 ReadHttpsRecordAndSetState(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    u32 length;
    u8 *header;
    u8 *record;
    u8 *body;
    u8 recordType;
    u8 messageType;
    s32 messageLength;
    do {
        header = CPSi_TcpReadRaw(&length, connection);
        if (length == 0) {
            httpsState->mSetupState = HTTPS_SETUP_FAILED;
            return httpsState->mSetupState;
        }
    } while (length < 5);
    recordType = header[0];
    if (recordType == 0x80) {
        if (httpsState->mReceivesKind1Record != 0 && httpsState->mSetupState == HTTPS_SETUP_START) {
            length = header[1];
            CPSi_SocConsumeRaw(2, connection);
            record = CPSiAlloc(length);
            if (record == NULL) {
                httpsState->mSetupState = HTTPS_SETUP_FAILED;
                return httpsState->mSetupState;
            }
            if (ReadExactReceivedBytes(record, length, connection) == 0 && record[0] == 1) {
                ParseKind1MessageWithThreeByteValues(httpsState, record + 1);
            } else {
                httpsState->mSetupState = HTTPS_SETUP_FAILED;
            }
            CPSi_sha1_calc(&httpsState->mMessageHash20, record, length);
            CPSi_md5_calc(&httpsState->mMessageHash16, record, length);
            CPSiFree(record);
        } else {
            httpsState->mSetupState = HTTPS_SETUP_FAILED;
        }
    } else {
        length = ((header[3] << 8) + header[4]) + 5;
        record = CPSiAlloc(length);
        if (record == NULL) {
            httpsState->mSetupState = HTTPS_SETUP_FAILED;
            return httpsState->mSetupState;
        }
        if (ReadExactReceivedBytes(record, length, connection) != 0) {
            CPSiFree(record);
            httpsState->mSetupState = HTTPS_SETUP_FAILED;
            return httpsState->mSetupState;
        }
        if (((u8) (httpsState->mSetupState + (0x100 - HTTPS_SETUP_CIPHER_RECORD_RECEIVED)) <= 1 &&
             recordType != 0x15) ||
            (recordType == 0x15 && length > 7)) {
            length = XorReceivedRecordWithKeyStreamAndCheckDigest(httpsState, record);
        }
        body = record + 5;
        length -= 5;
        switch (recordType) {
            case 0x14:
                MI_CpuFill8(httpsState->mReceiveRecordCount, 0, 8);
                httpsState->mSetupState = HTTPS_SETUP_CIPHER_RECORD_RECEIVED;
                break;
            case 0x15:
                if (body[0] == 2) {
                    httpsState->mSetupState = HTTPS_SETUP_FAILED;
                }
                break;
            case 0x16:
                do {
                    messageType = body[0];
                    messageLength = body[3] + ((body[1] << 16) + (body[2] << 8));
                    body += 4;
                    switch (messageType) {
                        case 1:
                            if (httpsState->mReceivesKind1Record != 0 && httpsState->mSetupState == HTTPS_SETUP_START) {
                                ParseKind1Message(httpsState, body);
                            }
                            break;
                        case 0x10:
                            rcv_client_key_exchange(httpsState, body);
                            break;
                        case 2:
                            ParseKind2Message(httpsState, body);
                            break;
                        case 0xb:
                            ParseAndCheckItemListMessage(httpsState, body);
                            break;
                        case 0xe:
                            httpsState->mSetupState = HTTPS_SETUP_REPLY_END_RECEIVED;
                            break;
                        case 0x14:
                            CheckMessageDigestsAndSetState(httpsState, body);
                            break;
                        default:
                            httpsState->mSetupState = HTTPS_SETUP_FAILED;
                            break;
                    }
                    CPSi_sha1_calc(&httpsState->mMessageHash20, body - 4, messageLength + 4);
                    CPSi_md5_calc(&httpsState->mMessageHash16, body - 4, messageLength + 4);
                    body += messageLength;
                    length -= (messageLength + 4);
                    if (length == 0) {
                        break;
                    }
                } while (httpsState->mSetupState != HTTPS_SETUP_FAILED);
                break;
            case 0x17:
                httpsState->mReceivedBlock = record;
                httpsState->mReceivedBlockOffset = 5;
                httpsState->mReceivedBlockEnd = length + 5;
                return httpsState->mSetupState;
        }
        CPSiFree(record);
    }
    return httpsState->mSetupState;
}

// Writes n bytes taken from digests of gRandomByteState, skipping zero bytes.
void FillNonzeroRandomBytes(u8 *out, s32 count) {
    u8 digest[0x14];
    u8 hashState[0x5c];
    u32 randomWord;
    s32 digestIndex;
    s32 outputCount;
    s32 byteIndex;
    u32 carry;
    u8 *digestCursor;
    u8 *stateCursor;
    u32 savedInterrupts;
    u32 sum;
    u64 *generator;
    u64 nextValue;
    if (gRandomByteStateMixed == 0) {
        generator = CPSiRand32ctx;
        nextValue = generator[1] * generator[0] + generator[2];
        generator[0] = nextValue;
        randomWord = nextValue >> 32;
        MixBytesIntoRandomState(&randomWord, 4);
    }
    digestIndex = 0x14;
    outputCount = 0;
    while (outputCount < count) {
        if (digestIndex == 0x14) {
            CPSi_sha1_init((Hash20Context *) hashState);
            savedInterrupts = OS_DisableInterrupts();
            CPSi_sha1_calc(hashState, gRandomByteState, 0x14);
            CPSi_sha1_result_prng((Hash20Context *) hashState, digest);
            carry = 1;
            byteIndex = 0x13;
            digestCursor = digest + 0x13;
            stateCursor = &gRandomByteState[0x13];
            for (; byteIndex >= 0; byteIndex--) {
                sum = *stateCursor + *digestCursor + carry;
                *stateCursor = sum;
                carry = sum >> 8;
                digestCursor--;
                stateCursor--;
            }
            randomWord = sum;
            OS_RestoreInterrupts(savedInterrupts);
            digestIndex = 0;
        }
        if (digest[digestIndex] != 0) {
            out[outputCount] = digest[digestIndex];
            outputCount++;
        }
        digestIndex++;
    }
}

void MixBytesIntoRandomState(void *bytes, u32 byteCount) {
    u8 hashState[0x60];
    u32 savedInterrupts;
    CPSi_sha1_init((Hash20Context *) hashState);
    savedInterrupts = OS_DisableInterrupts();
    CPSi_sha1_calc(hashState, gRandomByteState, 0x14);
    CPSi_sha1_calc(hashState, bytes, byteCount);
    CPSi_sha1_result((Hash20Context *) hashState, gRandomByteState);
    OS_RestoreInterrupts(savedInterrupts);
    gRandomByteStateMixed = 1;
}

u8 SendKind2Record(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    ItemList *itemList = httpsState->mItemList;
    s32 itemListLength;
    u32 seconds;
    u8 *message;
    u8 *cursor;
    s32 length;
    if (itemList != NULL) {
        itemListLength = itemList->mLength;
    } else {
        itemListLength = 0;
    }
    seconds = GetRtcSecondsPlusFixedOffset();
    httpsState->mKind2Block[0] = seconds >> 24;
    httpsState->mKind2Block[1] = seconds >> 16;
    httpsState->mKind2Block[2] = seconds >> 8;
    httpsState->mKind2Block[3] = seconds;
    FillNonzeroRandomBytes(&httpsState->mKind2Block[4], 0x1c);
    message = CPSiAlloc(itemListLength + 0x9d);
    if (message == NULL) {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return 1;
    }
    cursor = message + 5;
    message[5] = 2;
    cursor[1] = 0;
    cursor[2] = 0;
    cursor[3] = 0x46;
    cursor[4] = 3;
    cursor[5] = 0;
    MI_CpuCopy8(httpsState->mKind2Block, cursor + 6, 0x20);
    cursor[0x26] = 0x20;
    if (httpsState->mEntry != NULL) {
        MI_CpuCopy8(httpsState->mEntry, cursor + 0x27, 0x20);
        cursor += 0x47;
        httpsState->mReusedEntry = 1;
    } else {
        FillNonzeroRandomBytes(cursor + 0x27, 0x1c);
        seconds = gNewEntryIdCount;
        cursor[0x43] = seconds >> 24;
        cursor[0x44] = seconds >> 16;
        cursor[0x45] = seconds >> 8;
        cursor += 0x46;
        *cursor++ = seconds;
        httpsState->mEntry = AddEntryOrReplaceLongestUnused(cursor - 0x20);
        gNewEntryIdCount = gNewEntryIdCount + 1;
        httpsState->mReusedEntry = 0;
    }
    cursor[0] = httpsState->mCommonValue >> 8;
    cursor[1] = httpsState->mCommonValue;
    cursor += 2;
    *cursor++ = 0;
    if (httpsState->mReusedEntry == 0) {
        if (itemListLength != 0) {
            cursor[0] = 0xb;
            length = itemListLength + 6;
            cursor[1] = length >> 16;
            cursor[2] = length >> 8;
            cursor[3] = length;
            length = itemListLength + 3;
            cursor[4] = length >> 16;
            cursor[5] = length >> 8;
            cursor[6] = length;
            cursor[7] = itemListLength >> 16;
            cursor[8] = itemListLength >> 8;
            cursor += 9;
            *cursor++ = itemListLength;
            MI_CpuCopy8(itemList->mBytes, cursor, itemListLength);
            cursor += itemListLength;
        }
        cursor[0] = 0xe;
        cursor[1] = 0;
        cursor[2] = 0;
        cursor += 3;
        *cursor++ = 0;
    }
    length = cursor - message - 5;
    message[0] = 0x16;
    message[1] = 3;
    message[2] = 0;
    message[3] = length >> 8;
    message[4] = length;
    CPSi_sha1_calc(&httpsState->mMessageHash20, message + 5, length);
    CPSi_md5_calc(&httpsState->mMessageHash16, message + 5, length);
    CPSi_TcpWrite2Raw(message, length + 5, NULL, 0, connection);
    CPSiFree(message);
    return httpsState->mReusedEntry;
}

void SendOneByteRecordAndMessageDigests(CPSSoc *connection) {
    u8 *msg;
    HttpsState *httpsState;
    httpsState = connection->mHttpsState;
    msg = CPSiAlloc(0x83);
    if (msg == NULL) {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return;
    }
    msg[0] = 0x14;
    msg[1] = 3;
    msg[2] = 0;
    msg[3] = 0;
    msg[4] = 1;
    msg[5] = 1;
    MI_CpuFill8(httpsState->mSendRecordCount, 0, 8);
    msg[6] = 0x16;
    msg[7] = 3;
    msg[8] = 0;
    msg[9] = 0;
    msg[10] = 0x28;
    msg[11] = 0x14;
    msg[12] = 0;
    msg[13] = 0;
    msg[14] = 0x24;
    MI_CpuCopy8(&httpsState->mMessageHash16, &httpsState->mScratchHash16, 0x58);
    ComputeLabeledMessageDigest16(httpsState, msg + 0xf, 0);
    MI_CpuCopy8(&httpsState->mScratchHash16, &httpsState->mMessageHash16, 0x58);
    MI_CpuCopy8(&httpsState->mMessageHash20, &httpsState->mScratchHash20, 0x5c);
    ComputeLabeledMessageDigest20(httpsState, msg + 0x1f, 0);
    MI_CpuCopy8(&httpsState->mScratchHash20, &httpsState->mMessageHash20, 0x5c);
    CPSi_sha1_calc(&httpsState->mMessageHash20, msg + 0xb, 0x28);
    CPSi_md5_calc(&httpsState->mMessageHash16, msg + 0xb, 0x28);
    CPSi_TcpWrite2Raw(msg, AppendDigestAndXorSentRecordWithKeyStream(httpsState, msg + 6) + 6, NULL, 0, connection);
    CPSiFree(msg);
}

void SendKind1Record(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    u8 *message;
    u8 *cursor;
    u8 *lastByte;
    u32 seconds;
    s32 payloadLength;
    u32 offeredIndex;
    u16 *offeredCursor;
    message = CPSiAlloc(0x98);
    if (message == NULL) {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return;
    }
    cursor = message + 9;
    message[9] = 3;
    cursor[1] = 0;
    seconds = GetRtcSecondsPlusFixedOffset();
    httpsState->mKind1Block[0] = seconds >> 24;
    httpsState->mKind1Block[1] = seconds >> 16;
    httpsState->mKind1Block[2] = seconds >> 8;
    httpsState->mKind1Block[3] = seconds;
    FillNonzeroRandomBytes(&httpsState->mKind1Block[4], 0x1c);
    MI_CpuCopy8(httpsState->mKind1Block, cursor + 2, 0x20);
    httpsState->mEntry = FindEntryByValuePairAndSetLastUseTime(connection->mRemoteIp, connection->mRemotePort);
    if (httpsState->mEntry != NULL) {
        cursor[0x22] = 0x20;
        MI_CpuCopy8(httpsState->mEntry, cursor + 0x23, 0x20);
        cursor += 0x43;
    } else {
        lastByte = cursor + 0x22;
        cursor += 0x23;
        *lastByte = 0;
    }
    offeredIndex = 0;
    *cursor = 0;
    lastByte = cursor + 1;
    cursor += 2;
    *lastByte = 4;
    offeredCursor = gOfferedValues;
    for (; offeredIndex < 2; offeredIndex++) {
        *cursor = *offeredCursor >> 8;
        lastByte = cursor + 1;
        cursor += 2;
        *lastByte = *offeredCursor;
        offeredCursor++;
    }
    *cursor = 1;
    cursor[1] = 0;
    lastByte = cursor + 2;
    payloadLength = lastByte - message - 5;
    message[0] = 0x16;
    message[1] = 3;
    message[2] = 0;
    message[3] = payloadLength >> 8;
    message[4] = payloadLength;
    message[5] = 1;
    message[6] = (payloadLength - 4) >> 16;
    message[7] = (payloadLength - 4) >> 8;
    message[8] = payloadLength - 4;
    CPSi_TcpWrite2Raw(message, payloadLength + 5, NULL, 0, connection);
    CPSi_md5_calc(&httpsState->mMessageHash16, message + 5, payloadLength);
    CPSi_sha1_calc(&httpsState->mMessageHash20, message + 5, payloadLength);
    CPSiFree(message);
}

// Fills mEntry's 0x30 bytes (3, 0, then random bytes), pads them with random bytes, transforms them with mFirstValue
// and mSecondValue and sends the result.
void send_client_key_exchange(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    s32 modulusLength;
    s32 digitCount;
    u16 *result;
    u16 *base;
    u16 *exponent;
    u16 *modulus;
    u8 *paddedSecret;
    u8 *record;
    s32 digitIndex;
    u8 *writePtr;
    u8 *lowBytePtr;
    httpsState->mEntry->mMasterSecret[0] = 3;
    httpsState->mEntry->mMasterSecret[1] = 0;
    FillNonzeroRandomBytes(&httpsState->mEntry->mMasterSecret[2], 0x2e);
    modulusLength = httpsState->mFirstValueLength;
    digitCount = (modulusLength * 2) / 2;
    paddedSecret = CPSiAlloc(modulusLength);
    if (paddedSecret == NULL) {
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return;
    }
    paddedSecret[0] = 0;
    paddedSecret[1] = 2;
    FillNonzeroRandomBytes(paddedSecret + 2, modulusLength - 0x33);
    paddedSecret[modulusLength - 0x31] = 0;
    MI_CpuCopy8(httpsState->mEntry->mMasterSecret, paddedSecret + modulusLength - 0x30, 0x30);
    result = (u16 *) CPSiAlloc(digitCount * 8);
    if (result == NULL) {
        CPSiFree(paddedSecret);
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return;
    }
    base = result + digitCount;
    exponent = base + digitCount;
    modulus = exponent + digitCount;
    CPSi_big_from_char(base, paddedSecret, modulusLength, digitCount);
    CPSi_big_from_char(exponent, httpsState->mSecondValue, httpsState->mSecondValueLength, digitCount);
    CPSi_big_from_char(modulus, httpsState->mFirstValue, modulusLength, digitCount);
    if (gSslLowThreadPriority < 0x20) {
        OSThread *thread = OSi_ThreadInfo.mCurrentThread;
        u32 savedPriority = OS_GetThreadPriority(thread);
        OS_SetThreadPriority(thread, gSslLowThreadPriority);
        CPSi_big_power(result, base, exponent, digitCount, modulus);
        OS_SetThreadPriority(thread, savedPriority);
    } else {
        CPSi_big_power(result, base, exponent, digitCount, modulus);
    }
    record = CPSiAlloc(modulusLength + 0x49);
    if (record == NULL) {
        CPSiFree(paddedSecret);
        CPSiFree(result);
        httpsState->mSetupState = HTTPS_SETUP_FAILED;
        return;
    }
    record[0] = 0x16;
    record[1] = 3;
    record[2] = 0;
    record[3] = (modulusLength + 4) >> 8;
    record[4] = modulusLength + 4;
    record[5] = 0x10;
    record[6] = modulusLength >> 16;
    record[7] = modulusLength >> 8;
    writePtr = record + 9;
    record[8] = modulusLength;
    if (modulusLength & 1) {
        *writePtr = result[modulusLength / 2];
        writePtr += 1;
    }
    for (digitIndex = modulusLength / 2 - 1; digitIndex >= 0; digitIndex--) {
        *writePtr = result[digitIndex] >> 8;
        lowBytePtr = writePtr + 1;
        writePtr += 2;
        *lowBytePtr = result[digitIndex];
    }
    CPSi_TcpWrite2Raw(record, modulusLength + 9, NULL, 0, connection);
    CPSi_md5_calc(&httpsState->mMessageHash16, record + 5, (u32) modulusLength + 4);
    CPSi_sha1_calc(&httpsState->mMessageHash20, record + 5, modulusLength + 4);
    CPSiFree(record);
    CPSiFree(result);
    CPSiFree(paddedSecret);
}

u32 ReadRecordsExpectingStates7And6(CPSSoc *connection) {
    int state;
    state = ReadHttpsRecordAndSetState(connection);
    if (state != HTTPS_SETUP_CIPHER_RECORD_RECEIVED) {
        return 1;
    }
    state = ReadHttpsRecordAndSetState(connection);
    if (state != HTTPS_SETUP_DIGESTS_MATCHED) {
        return 1;
    }
    return 0;
}

BOOL RunSetupAfterReadingKind1Record(CPSSoc *connection) {
    if (ReadHttpsRecordAndSetState(connection) != HTTPS_SETUP_OFFER_RECEIVED) {
        return TRUE;
    }
    if (SendKind2Record(connection) != 0) {
        DeriveBytesAndInitKeyStreamStates(connection->mHttpsState);
        SendOneByteRecordAndMessageDigests(connection);
        if (ReadRecordsExpectingStates7And6(connection) != 0) {
            return TRUE;
        }
    } else {
        if (ReadHttpsRecordAndSetState(connection) != HTTPS_SETUP_KEYS_DERIVED) {
            return TRUE;
        }
        if (ReadRecordsExpectingStates7And6(connection) != 0) {
            return TRUE;
        }
        SendOneByteRecordAndMessageDigests(connection);
    }
    return FALSE;
}

void RunSetupAfterReadingKind1RecordUntilDone(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    while (1) {
        CPSi_TcpListenRaw(connection);
        httpsState->mSetupState = HTTPS_SETUP_START;
        httpsState->mReceivesKind1Record = 1;
        CPSi_sha1_init(&httpsState->mMessageHash20);
        CPSi_md5_init(&httpsState->mMessageHash16);
        if (RunSetupAfterReadingKind1Record(connection) == 0) {
            httpsState->mSetupState = HTTPS_SETUP_COMPLETE;
            return;
        }
        CPSi_TcpShutdownRaw(connection);
        connection->mRemotePort = connection->mRemotePortBound;
        connection->mRemoteIp = connection->mRemoteIpBound;
    }
}

BOOL RunSetupAfterSendingKind1Record(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    u8 state;
    SendKind1Record(connection);
    while (1) {
        state = ReadHttpsRecordAndSetState(connection);
        if (state == HTTPS_SETUP_FAILED) {
            return TRUE;
        }
        if (state == HTTPS_SETUP_REPLY_END_RECEIVED || httpsState->mReusedEntry != 0) {
            break;
        }
    }
    if (httpsState->mReusedEntry != 0) {
        DeriveBytesAndInitKeyStreamStates(httpsState);
        if (ReadRecordsExpectingStates7And6(connection) != 0) {
            return TRUE;
        }
        SendOneByteRecordAndMessageDigests(connection);
    } else {
        httpsState->mEntry->mRemoteIp = connection->mRemoteIp;
        httpsState->mEntry->mRemotePort = connection->mRemotePort;
        send_client_key_exchange(connection);
        ReplaceEntryBytesWithLabeledDigests(httpsState);
        DeriveBytesAndInitKeyStreamStates(httpsState);
        SendOneByteRecordAndMessageDigests(connection);
        if (ReadRecordsExpectingStates7And6(connection) != 0) {
            return TRUE;
        }
    }
    httpsState->mSetupState = HTTPS_SETUP_COMPLETE;
    return FALSE;
}

BOOL CPSi_SslConnect(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    if (connection->mState != SOCKET_STATE_ESTABLISHED && CPSi_TcpConnectRaw(connection) != 0) {
        return TRUE;
    }
    httpsState->mSetupState = HTTPS_SETUP_START;
    httpsState->mReceivesKind1Record = 0;
    CPSi_sha1_init(&httpsState->mMessageHash20);
    CPSi_md5_init(&httpsState->mMessageHash16);
    return RunSetupAfterSendingKind1Record(connection);
}

u8 *ReadHttpsRecordsUntilBytesReceived(s32 *unreadCount, CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    while (httpsState->mReceivedBlock == NULL) {
        if (ReadHttpsRecordAndSetState(connection) == HTTPS_SETUP_FAILED) {
            *unreadCount = 0;
            return NULL;
        }
    }
    *unreadCount = httpsState->mReceivedBlockEnd - httpsState->mReceivedBlockOffset;
    return httpsState->mReceivedBlock + httpsState->mReceivedBlockOffset;
}

void SkipHttpsReceivedBytes(u32 count, CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    if (count >= httpsState->mReceivedBlockEnd - httpsState->mReceivedBlockOffset) {
        CPSiFree(httpsState->mReceivedBlock);
        httpsState->mReceivedBlock = NULL;
        httpsState->mReceivedBlockOffset = httpsState->mReceivedBlockEnd;
    } else {
        httpsState->mReceivedBlockOffset += count;
    }
}

s32 ReadHttpsRecordIfBufferedAndGetUnreadByteCount(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    if (httpsState->mReceivedBlock == NULL) {
        if (connection->mReceiveBufferLength == 0) {
            return 0;
        }
        ReadHttpsRecordAndSetState(connection);
    }
    return httpsState->mReceivedBlockEnd - httpsState->mReceivedBlockOffset;
}

s32 SendHttpsBytesInChunks(u8 *firstBytes, u32 firstLength, u8 *secondBytes, u32 secondLength, CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    s32 remaining = firstLength + secondLength;
    u8 *record;
    s32 chunkLength;
    u32 firstChunkLength;
    u32 secondChunkLength;
    s32 sentCount = 0;
    u8 recordByte2 = 0;
    s32 emptyLength = 0;
    BOOL noneSent = FALSE;
    while (1) {
        if (remaining > 0xb4f) {
            chunkLength = 0xb4f;
        } else {
            chunkLength = remaining;
        }
        record = CPSiAlloc(chunkLength + 0x19);
        if (record == NULL) {
            break;
        }
        if (firstLength >= chunkLength) {
            firstChunkLength = chunkLength;
        } else {
            firstChunkLength = firstLength;
        }
        secondChunkLength = chunkLength - firstChunkLength;
        MI_CpuCopy8(firstBytes, record + 5, firstChunkLength);
        firstBytes += firstChunkLength;
        firstLength -= firstChunkLength;
        MI_CpuCopy8(secondBytes, record + 5 + firstChunkLength, secondChunkLength);
        secondBytes += secondChunkLength;
        record[0] = 0x17;
        record[1] = 3;
        record[2] = recordByte2;
        record[3] = chunkLength >> 8;
        record[4] = chunkLength;
        firstChunkLength = AppendDigestAndXorSentRecordWithKeyStream(httpsState, record);
        if (CPSi_TcpWrite2Raw(record, firstChunkLength, (const u8 *) emptyLength, emptyLength, connection) <
            firstChunkLength) {
            chunkLength = noneSent;
        }
        CPSiFree(record);
        remaining -= chunkLength;
        sentCount += chunkLength;
        if (remaining == 0) {
            break;
        }
        if (chunkLength == 0) {
            break;
        }
    }
    return sentCount;
}

// When mSetupState is HTTPS_SETUP_COMPLETE sends the 7-byte record that ends with 1, 0, then runs
// CPSi_TcpShutdownRaw and clears mSetupState.
void CPSi_SslShutdown(CPSSoc *connection) {
    HttpsState *httpsState = connection->mHttpsState;
    u8 alertRecord[0x20];
    if (httpsState->mSetupState == HTTPS_SETUP_COMPLETE) {
        alertRecord[0] = 0x15;
        alertRecord[1] = 3;
        alertRecord[2] = 0;
        alertRecord[3] = 0;
        alertRecord[4] = 2;
        alertRecord[5] = 1;
        alertRecord[6] = 0;
        CPSi_TcpWrite2Raw(alertRecord, AppendDigestAndXorSentRecordWithKeyStream(httpsState, alertRecord), NULL, 0,
                          connection);
    }
    CPSi_TcpShutdownRaw(connection);
    httpsState->mSetupState = HTTPS_SETUP_START;
}
