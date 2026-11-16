#pragma once

#include "types.h"

void MBi_SetScanLockFunc(void (*setCallback)(const u8 *), void (*clearCallback)(void));
void MBi_SetBeaconRecvStatusBuffer(void *entryTable);
