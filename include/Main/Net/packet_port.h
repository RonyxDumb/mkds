#pragma once

#include "types.h"
#include "Main/Kart/kart_effect_param_tables.h"

typedef struct WirelessMessage WirelessMessage;

// Bytes of one packet QueuePacketToPort builds for the wireless block transfer: from the parent (also the largest
// length PacketPortCallback accepts), from a child.
#define PACKET_PORT_PARENT_PACKET_SIZE 0x192
#define PACKET_PORT_CHILD_PACKET_SIZE 0xe

void PacketPortCallback(void *portMessage);
void QueuePacketToPort(void);
void PacketPortSendCallback(void);
void SetBlockEntryBuffer(u32 entryIndex, void *buffer);

extern u16 gPacketSendTimerFrames;
extern QueueMPDataToPortParams gPacketPortParams;
