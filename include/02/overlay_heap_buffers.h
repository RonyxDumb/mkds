#pragma once

#include "types.h"

extern u8 gOverlayFrmHeapBuffer[];
extern u8 g_Overlay3Region[];

// End of the 0x800-byte stack of the TCP/IP thread, inside the expanded heap buffer.
#ifdef version_EUR
#define TCPIP_STACK_TOP (g_Overlay3Region + 0xdfa0)
#else
#define TCPIP_STACK_TOP (g_Overlay3Region + 0xdf80)
#endif
