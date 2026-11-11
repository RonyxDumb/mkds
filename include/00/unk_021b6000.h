#pragma once

#include "types.h"

typedef struct HttpsEntry HttpsEntry;
typedef struct SOCLSocket SOCLSocket;

// Objects whose layout isn't known yet.
extern u8 FreeFunc_SOC[];
extern u8 data_ov000_021b6368;
extern u32 data_ov000_021b637c;
extern u8 *(*data_ov000_021b63a4)(u32 param_1);
extern void (*data_ov000_021b63ac)(void *param_1);

extern void (*data_ov000_021b63a8)(void);

extern SOCLSocket *SOCLiSocketList;
extern SOCLSocket *SOCLiSocketListTrash;
extern HttpsEntry data_ov000_021b61f4[];
extern HttpsEntry data_ov000_021b6198;
