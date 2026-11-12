#pragma once

#include "types.h"

BOOL gt2StringToAddress(const char *string, u32 *ipOut, u16 *portOut);
u32 gt2AddressToString(u32 ipAddress, u32 port, char *buffer);
