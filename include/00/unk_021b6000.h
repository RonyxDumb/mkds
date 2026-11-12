#pragma once

#include "types.h"

typedef struct HttpsEntry HttpsEntry;
typedef struct SOCLSocket SOCLSocket;

extern u8 gIpConflict;
extern u32 CPSNoIpReason;
extern u8 *(*CPSiAlloc)(u32 param_1);
extern void (*CPSiFree)(void *param_1);

extern void (*gScavengerCallback)(void);

