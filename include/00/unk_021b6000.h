#pragma once

#include "types.h"

typedef struct HttpsEntry HttpsEntry;
typedef struct SOCLSocket SOCLSocket;

// Objects whose layout isn't known yet.
extern u8 FreeFunc_SOC[];
extern u8 gIpConflict;
extern u32 CPSNoIpReason;
extern u8 *(*CPSiAlloc)(u32 param_1);
extern void (*CPSiFree)(void *param_1);

extern void (*gScavengerCallback)(void);

extern SOCLSocket *SOCLiSocketList;
extern SOCLSocket *SOCLiSocketListTrash;
extern HttpsEntry gHttpsEntries[];
extern HttpsEntry gUncachedHttpsEntry;
