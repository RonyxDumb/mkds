#pragma once

#include "types.h"
#include "00/code_0219887c.h" // Unk0219887c
#include "00/code_0219b1d4.h" // NatTraversalEntry

typedef struct GpConnection GpConnection;

// Message block: word at 0 and string pointer at 8.
typedef struct Unk0219b4b4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 pad_04[4];
    /* 08 */ char *mUnk_08;
} Unk0219b4b4;

NatTraversalEntry *FindNegotiatorForCookie(u32 cookie);
void DWCi_GT2SocketErrorCallback(u32 *socket);
void WiFiGt2ElapsedTimeCallback(Unk0219887c *connection, u32 latency);
void DWCi_GT2ClosedCallback(Unk0219887c *connection, u32 reason);
void WiFiGt2DataCallback(Unk0219887c *connection, void *message, s32 length, u32 reliable);
void WiFiGpMessageCallback(GpConnection *connection, Unk0219b4b4 *arg, u32 param);
