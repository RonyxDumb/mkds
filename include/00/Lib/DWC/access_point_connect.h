#pragma once

#include "types.h"

typedef struct ACWORK ACWORK;

u8 GetConnectType(ACWORK *object);
u32 ConnectAP(ACWORK *object);
u32 ConnectStart(ACWORK *object);
u32 DWCi_AC_ConnectAP(void);
BOOL CloseAutoConnectSocket(void);
s32 DisConnectAP(void);
