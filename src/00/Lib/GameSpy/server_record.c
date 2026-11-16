#include "00/Lib/GameSpy/server_list.h"

#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/server_query_engine.h"
#include "00/Lib/GameSpy/server_key_info.h"
#include "03/Net/exchange_essid.h" // SocketAddress
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/hash_table.h"
#include "decimal_digit_arith_string_compare.h"
#include "00/Lib/wifi_library_globals.h"
#include "unsigned_int_divide.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/query_key_register.h"
#include "string.h"
#include "00/Lib/DWC/shop_access_point_key.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "00/Lib/GameSpy/stream_cipher.h"
#include "scan_text_random.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "quick_sort.h"
#include "00/Lib/GameSpy/availability_check.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"

struct SBServer *gSBNullServer;
s8 *gMytokPosition;
struct HashImplementation *gSBRefStrList = NULL;
InvalidKeyNames gInvalidKeys = {{"queryid", "final"}};

u32 RefStringHash(HashtableNameEntry *entry, u32 modulus) {
    return ServerStringHash(entry->mName, modulus);
}

s32 RefStringCompare(const char *const *first, const char *const *second) {
    return CompareStringsMapped(*first, *second);
}

void RefStringFree(u32 element) {
    u32 stringPointer = element;
    u32 unusedValue;
    stringPointer = *(const u32 *) ((stringPointer) + 0u);
    DWCi_GsFree((void *) stringPointer);
}

struct HashImplementation *SBRefStrHash(struct SBServerList *serverList) {
    if (gSBRefStrList == NULL) {
        gSBRefStrList = HashtableCreate(8, 100, 2, (s32(*)(void *, s32)) RefStringHash,
                                        (ArrayCompareFn *) RefStringCompare, (void (*)(void *)) RefStringFree);
    }
    return gSBRefStrList;
}

void SBRefStrHashCleanup(void *serverList) {
    int count;
    if ((gSBRefStrList != NULL) && (count = TableCount(gSBRefStrList), count == 0)) {
        TableFree(gSBRefStrList);
        gSBRefStrList = NULL;
    }
}

void SBServerFree(SBServer **serverPointer) {
    SBServer *serverRecord;
    serverRecord = *serverPointer;
    TableFree(serverRecord->mKeyValues);
    serverRecord->mKeyValues = NULL;
    DWCi_GsFree(serverRecord);
}

void SBServerAddKeyValue(SBServer *server, const char *key, const char *value) {
    char *pair[2];
    pair[0] = SBRefStr(NULL, key);
    pair[1] = SBRefStr(NULL, value);
    TableEnter(server->mKeyValues, pair);
}

void SBServerAddIntKeyValue(SBServer *server, const char *key, u32 value) {
    char valueText[20];
    sprintf(valueText, "%d", value);
    SBServerAddKeyValue(server, key, valueText);
}

char *SBServerGetStringValueA(SBServer *server, const char *key, char *defaultValue) {
    KeyLookup probe;
    u32 *entry;
    if (server == NULL) {
        AssertionFailed("server", "sb_server.c", NULL, 0x97);
    }
    if (server == NULL) {
        return NULL;
    }
    probe.mKey = key;
    entry = TableLookup(server->mKeyValues, &probe);
    if (entry != NULL) {
        defaultValue = (char *) entry[1];
    }
    return defaultValue;
}

s32 SBServerGetIntValueA(SBServer *server, const char *key, s32 defaultValue) {
    char *text;
    s32 firstChar;
    if (strcmp(key, "ping") == 0) {
        return SBServerGetPing(server);
    }
    text = SBServerGetStringValueA(server, key, NULL);
    if (text == NULL ||
        (firstChar = *text, !((firstChar < 0 || firstChar >= 0x80) ? 0 : (gCharClassFlags[firstChar] & 8)))) {
        return defaultValue;
    }
    return StrtolBase10(text);
}

double SBServerGetFloatValueA(SBServer *server, const char *key, double defaultValue) {
    char *text;
    text = SBServerGetStringValueA(server, key, NULL);
    if (text != NULL) {
        defaultValue = atof(text);
    }
    return defaultValue;
}

u32 SBServerGetPublicInetAddress(SBServer *server) {
    return server->mPublicIp;
}

u32 SBServerGetPublicQueryPort(SBServer *server) {
    u32 value;
    u32 port;
    u32 swappedPort;
    port = server->mPublicPort;
    swappedPort = ((s32) port >> 8);
    value = 255u;
    swappedPort = (swappedPort) & (value);
    port = (port << 8);
    value = 0xff00u;
    port = (port) & (value);
    swappedPort = (swappedPort) | (port);
    value = (swappedPort << 16);
    value = (value >> 16);
    return value;
}

u16 SBServerGetPublicQueryPortNBO(SBServer *server) {
    return server->mPublicPort;
}

BOOL SBServerHasPrivateAddress(SBServer *server) {
    if ((server->mFlags & PRIVATE_IP_FLAG) == PRIVATE_IP_FLAG) {
        return 1;
    }
    return 0;
}

u32 SBServerGetPrivateInetAddress(SBServer *server) {
    return server->mPrivateIp;
}

u32 SBServerGetPrivateQueryPort(SBServer *server) {
    u32 value;
    u32 port;
    u32 swappedPort;
    port = server->mPrivatePort;
    swappedPort = ((s32) port >> 8);
    value = 255u;
    swappedPort = (swappedPort) & (value);
    port = (port << 8);
    value = 0xff00u;
    port = (port) & (value);
    swappedPort = (swappedPort) | (port);
    value = (swappedPort << 16);
    value = (value >> 16);
    return value;
}

void SBServerSetNext(SBServer *server, SBServer *next) {
    server->mNext = next;
}

SBServer *SBServerGetNext(SBServer *server) {
    return server->mNext;
}

BOOL CheckValidKey(const char *key) {
    InvalidKeyNames invalidKeys;
    u32 index;
    const char **invalidName;
    invalidKeys = gInvalidKeys;
    invalidName = invalidKeys.mNames;
    for (index = 0; index < 2; index++) {
        if (strcmp(key, *invalidName) == 0) {
            return 0;
        }
        invalidName++;
    }
    return 1;
}

s8 *mytok(s8 *text, s32 delimiter) {
    s8 *tokenStart;
    s8 *cursor;
    s32 character;
    if (text != NULL) {
        gMytokPosition = text;
    }
    tokenStart = gMytokPosition;
    while ((character = *(cursor = gMytokPosition)) != 0 && character != delimiter) {
        gMytokPosition++;
    }
    if (cursor == tokenStart) {
        tokenStart = NULL;
    }
    if (character != 0) {
        gMytokPosition++;
        *cursor = 0;
    }
    return tokenStart;
}

void SBServerParseKeyVals(SBServer *server, s8 *keyValues) {
    s8 *key;
    s8 *value;
    key = mytok(keyValues + 1, 0x5c);
    while (key != NULL) {
        value = mytok(NULL, 0x5c);
        if (value == NULL) {
            value = (s8 *) "";
        }
        if (CheckValidKey((const char *) key) != 0) {
            SBServerAddKeyValue(server, (const char *) key, (const char *) value);
        }
        key = mytok(NULL, 0x5c);
    }
}

void SBServerParseQR2FullKeysSingle(SBServer *server, s8 *data, s32 length) {
    FullKeysScratch scratch;
    s8 *keyNames;
    s8 *key;
    s8 *value;
    s32 keyCount;
    s32 groupIndex;
    s32 unitIndex;
    s32 keyIndex;
    s32 valueLength;
    s32 stringLength;
    u16 unitCount;
    while (*data != 0) {
        stringLength = NTSLengthSB(data, length);
        if (stringLength < 0) {
            return;
        }
        key = data;
        data += stringLength;
        length -= stringLength;
        stringLength = NTSLengthSB(data, length);
        if (stringLength < 0) {
            return;
        }
        value = data;
        data += stringLength;
        length -= stringLength;
        SBServerAddKeyValue(server, (const char *) key, (const char *) value);
    }
    data++;
    length--;
    for (groupIndex = 0; groupIndex < 2; groupIndex++) {
        if (length < 2) {
            return;
        }
        __memcpy(&scratch.mUnitCount, data, 2);
        unitCount = scratch.mUnitCount;
        scratch.mUnitCount = ((unitCount >> 8) & 0xff) | ((unitCount << 8) & 0xff00);
        data += 2;
        length -= 2;
        keyNames = data;
        keyCount = 0;
        while (*data != 0) {
            stringLength = NTSLengthSB(data, length);
            if (stringLength < 0 || stringLength > 100) {
                return;
            }
            keyCount++;
            data += stringLength;
            length -= stringLength;
        }
        data++;
        length--;
        unitIndex = 0;
        while (unitIndex < scratch.mUnitCount) {
            key = keyNames;
            keyIndex = 0;
            while (keyIndex < keyCount) {
                valueLength = NTSLengthSB(data, length);
                if (valueLength < 0) {
                    return;
                }
                sprintf(scratch.mTempKey, "%s%d", key, unitIndex);
                SBServerAddKeyValue(server, scratch.mTempKey, (const char *) data);
                data += valueLength;
                length -= valueLength;
                key += strlen((const char *) key) + 1;
                keyIndex++;
            }
            unitIndex++;
        }
    }
}

u32 ServerStringHash(const s8 *text, u32 modulus) {
    s32 character;
    u32 hash;
    hash = 0;
    character = *text;
    while (character != 0) {
        if (character >= 0 && character < 0x80) {
            character = gLowerCaseMap[character];
        }
        hash *= 0x9ccf9319;
        hash += character;
        text++;
        character = *text;
    }
    return hash % modulus;
}

void KeyValFree(u32 *pair) {
    SBReleaseStr(0, *pair);
    SBReleaseStr(0, pair[1]);
}

u32 KeyValHashKey(HashtableNameEntry *entry, u32 modulus) {
    return ServerStringHash(entry->mName, modulus);
}

s32 KeyValCompareKey(const char *const *first, const char *const *second) {
    return CompareStringsMapped(*first, *second);
}

u32 SBServerGetPing(SBServer *server) {
    return server->mPing;
}

SBServer *SBAllocServer(SBServerList *serverList, u32 publicIp, u16 publicPort) {
    SBServer *newServer;
    newServer = DWCi_GsMalloc(0x24);
    if (newServer == NULL) {
        return NULL;
    }
    newServer->mKeyValues = HashtableCreate(8, 8, 4, (s32(*)(void *, s32)) KeyValHashKey,
                                            (ArrayCompareFn *) KeyValCompareKey, (void (*)(void *)) KeyValFree);
    if (newServer->mKeyValues == NULL) {
        DWCi_GsFree(newServer);
        return NULL;
    }
    newServer->mStateFlags = 0;
    newServer->mFlags = 0;
    newServer->mNext = NULL;
    newServer->mPing = 0;
    newServer->mIcmpIp = 0;
    newServer->mPublicIp = publicIp;
    newServer->mPublicPort = publicPort;
    newServer->mPrivateIp = 0;
    newServer->mPrivatePort = 0;
    return newServer;
}

void SBServerSetFlags(SBServer *server, s32 flags) {
    server->mFlags = flags;
}

void SBServerSetPrivateAddr(SBServer *server, u32 privateIp, u16 privatePort) {
    server->mPrivateIp = privateIp;
    server->mPrivatePort = privatePort;
}

void SBServerSetICMPIP(SBServer *server, u32 icmpIp) {
    server->mIcmpIp = icmpIp;
}

void SBServerSetState(SBServer *server, u8 state) {
    server->mStateFlags = state;
}

u8 SBServerGetState(SBServer *server) {
    return server->mStateFlags;
}

BOOL SBIsNullServer(SBServer *server) {
    if (server == gSBNullServer) {
        return 1;
    }
    return 0;
}
