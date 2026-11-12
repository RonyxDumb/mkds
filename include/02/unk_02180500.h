#pragma once

#include "types.h"

extern u8 gOverlayFrmHeapBuffer[];
extern u8 gOverlayExpHeapBuffer[];

// End of the 0x800-byte stack of the TCP/IP thread, inside the expanded heap buffer.
#define TCPIP_STACK_TOP (gOverlayExpHeapBuffer + 0xdf80)
