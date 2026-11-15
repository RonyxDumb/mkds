#pragma once

#include "types.h"
#include "Main/MapObjects/data_02165000.h"

typedef struct WirelessMessage WirelessMessage;

// Bytes of one packet the wireless block transfer sends on its port: from the parent, from a child.
#define PACKET_PORT_PARENT_PACKET_SIZE 0x192
#define PACKET_PORT_CHILD_PACKET_SIZE 0xe

void PacketPortCallback(void *portMessage);
void QueuePacketToPort(void);
void PacketPortSendCallback(void);
void SetBlockEntryBuffer(u32 entryIndex, void *buffer);

extern u16 gPacketSendTimerFrames;
extern QueueMPDataToPortParams gPacketPortParams;
