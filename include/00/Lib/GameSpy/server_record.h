#pragma once

#include "types.h"

typedef struct SBServerList SBServerList;
typedef struct SBServer SBServer;

typedef struct HashtableNameEntry {
    /* 00 */ const s8 *mName;
} HashtableNameEntry;

typedef struct InvalidKeyNames {
    /* 0 */ const char *mNames[2];
} InvalidKeyNames;

typedef struct FullKeysScratch {
    /* 00 */ u16 mUnitCount;
    /* 02 */ char mTempKey[0x86];
} FullKeysScratch;

typedef struct KeyLookup {
    /* 0 */ const char *mKey;
} KeyLookup;

double SBServerGetFloatValueA(SBServer *server, const char *key, double defaultValue);
s32 SBServerGetIntValueA(SBServer *server, const char *key, s32 defaultValue);
char *SBServerGetStringValueA(SBServer *server, const char *key, char *defaultValue);
void SBServerAddIntKeyValue(SBServer *server, const char *key, u32 value);
void SBServerAddKeyValue(SBServer *server, const char *key, const char *value);

BOOL SBIsNullServer(SBServer *server);
u8 SBServerGetState(SBServer *server);
void SBServerSetState(SBServer *server, u8 state);
void SBServerSetICMPIP(SBServer *server, u32 targetAddr);
void SBServerSetPrivateAddr(SBServer *server, u32 innerAddress, u16 innerPort);
void SBServerSetFlags(SBServer *server, s32 flags);
SBServer *SBAllocServer(SBServerList *serverList, u32 outerAddress, u16 outerPort);
u32 SBServerGetPing(SBServer *server);
s32 KeyValCompareKey(const char *const *first, const char *const *second);
u32 KeyValHashKey(HashtableNameEntry *entry, u32 modulus);
void KeyValFree(u32 *pair);
u32 ServerStringHash(const s8 *name, u32 modulus);
void SBServerParseQR2FullKeysSingle(SBServer *server, s8 *buf, s32 length);
void SBServerParseKeyVals(SBServer *server, s8 *buf);
s8 *mytok(s8 *text, s32 delimiter);
BOOL CheckValidKey(const char *key);
SBServer *SBServerGetNext(SBServer *server);
void SBServerSetNext(SBServer *server, SBServer *next);
u32 SBServerGetPrivateQueryPort(SBServer *server);
u32 SBServerGetPrivateInetAddress(SBServer *server);
BOOL SBServerHasPrivateAddress(SBServer *server);
u16 SBServerGetPublicQueryPortNBO(SBServer *server);
u32 SBServerGetPublicQueryPort(SBServer *server);
u32 SBServerGetPublicInetAddress(SBServer *server);
void SBServerFree(SBServer **serverPointer);
void SBRefStrHashCleanup(void *serverList);
struct HashImplementation *SBRefStrHash(struct SBServerList *serverList);
void RefStringFree(u32 element);
s32 RefStringCompare(const char *const *first, const char *const *second);
u32 RefStringHash(HashtableNameEntry *entry, u32 modulus);

extern s8 *gMytokPosition;
extern struct HashImplementation *gSBRefStrList;
extern struct SBServer *gSBNullServer;
