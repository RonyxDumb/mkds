#pragma once

#include "types.h"

u32 MBi_SetScanLockFunc(UnkFunc *setCallback, UnkFunc *clearCallback);
void MBi_SetBeaconRecvStatusBuffer(void *entryTable);
