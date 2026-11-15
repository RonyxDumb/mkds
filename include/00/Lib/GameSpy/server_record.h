#pragma once

#include "types.h"

typedef struct SbServerList SbServerList;
typedef struct SbServer SbServer;

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

double SbServerGetDouble(SbServer *server, const char *key, double defaultValue);
s32 SbServerGetInt(SbServer *server, const char *key, s32 defaultValue);
char *SbServerGetValue(SbServer *server, const char *key, char *defaultValue);
void SbServerSetInt(SbServer *server, const char *key, u32 value);
void SbServerSetValue(SbServer *server, const char *key, const char *value);

BOOL SBIsNullServer(SbServer *server);
u8 SBServerGetState(SbServer *server);
void SBServerSetState(SbServer *server, u8 state);
void SBServerSetICMPIP(SbServer *server, u32 targetAddr);
void SBServerSetPrivateAddr(SbServer *server, u32 innerAddress, u16 innerPort);
void SBServerSetFlags(SbServer *server, s32 flags);
SbServer *SBAllocServer(SbServerList *serverList, u32 outerAddress, u16 outerPort);
u32 SBServerGetPing(SbServer *server);
s32 KeyValCompareKey(const char *const *first, const char *const *second);
u32 KeyValHashKey(HashtableNameEntry *entry, u32 modulus);
void KeyValFree(u32 *pair);
u32 ServerStringHash(const s8 *name, u32 modulus);
void SBServerParseQR2FullKeysSingle(SbServer *server, s8 *buf, s32 length);
void SBServerParseKeyVals(SbServer *server, s8 *buf);
s8 *mytok(s8 *text, s32 delimiter);
BOOL CheckValidKey(const char *key);
SbServer *SBServerGetNext(SbServer *server);
void SBServerSetNext(SbServer *server, SbServer *next);
u32 SBServerGetPrivateQueryPort(SbServer *server);
u32 SBServerGetPrivateInetAddress(SbServer *server);
BOOL SBServerHasPrivateAddress(SbServer *server);
u16 SBServerGetPublicQueryPortNBO(SbServer *server);
u32 SBServerGetPublicQueryPort(SbServer *server);
u32 SBServerGetPublicInetAddress(SbServer *server);
void SBServerFree(SbServer **serverPointer);
void SBRefStrHashCleanup(void *serverList);
struct Hashtable *SBRefStrHash(struct SbServerList *serverList);
void RefStringFree(u32 element);
s32 RefStringCompare(const char *const *first, const char *const *second);
u32 RefStringHash(HashtableNameEntry *entry, u32 modulus);

extern s8 *gMytokPosition;
extern struct Hashtable *gSBRefStrList;
extern struct SbServer *gSBNullServer;
