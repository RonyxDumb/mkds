#pragma once

#include "types.h"

typedef struct HttpsEntry HttpsEntry;
typedef struct SOCLSocket SOCLSocket;

extern u8 gIpConflict;
extern u32 CPSNoIpReason;
extern u8 *(*CPSiAlloc)(u32 size);
extern void (*CPSiFree)(void *block);

extern void (*gScavengerCallback)(void);

