#pragma once

#include "types.h"
#include "00/code_0219887c.h" // Unk0219887c
#include "00/code_0219b1d4.h" // NatTraversalEntry
#include "00/code_0218f960.h" // BuddyMessageData

typedef struct GpConnection GpConnection;

NatTraversalEntry *FindNegotiatorForCookie(u32 cookie);
void DWCi_GT2SocketErrorCallback(u32 *socket);
void DWCi_GT2PingCallback(Unk0219887c *connection, u32 latency);
void DWCi_GT2ClosedCallback(Unk0219887c *connection, u32 reason);
void DWCi_GT2ReceivedCallback(Unk0219887c *connection, void *message, s32 length, u32 reliable);
void DWCi_GPRecvBuddyMessageCallback(GpConnection *connection, BuddyMessageData *arg, u32 param);
