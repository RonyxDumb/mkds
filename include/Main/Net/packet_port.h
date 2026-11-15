#pragma once

#include "types.h"
#include "Main/MapObjects/data_02165000.h"

typedef struct WirelessMessage WirelessMessage;

void PacketPortCallback(void *portMessage);
void QueuePacketToPort(void);
void PacketPortSendCallback(void);
void SetBlockEntryBuffer(u32 entryIndex, void *buffer);

extern u16 gPacketSendTimerFrames;
extern QueueMPDataToPortParams gPacketPortParams;
