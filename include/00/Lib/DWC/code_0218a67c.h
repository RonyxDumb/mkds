#pragma once

#include "types.h"

void DWCi_AC_GetPostalCode(const u8 *ssid, char *postalCode);
void DWCi_AC_GetNintendoShopWepKey(const u8 *ssid, u8 *wepKey);
BOOL DWCi_AC_CheckNintendoShopAP(const u8 *ssid);
void GOADecrypt(u8 *state, u8 *data, int length);

extern u8 gShopSsidPrefix[9];
