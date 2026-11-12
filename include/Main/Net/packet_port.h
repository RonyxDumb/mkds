#pragma once

#include "types.h"
#include "Main/MapObjects/data_02165000.h"

typedef struct Unk021425e8 Unk021425e8;

void PacketPortCallback(Unk021425e8 *result);
void QueuePacketToPort(void);
void PacketPortSendCallback(void);
void SetBlockEntryBuffer(u32 entryIndex, void *buffer);

extern u16 gPacketSendTimerFrames;
extern QueueMPDataToPortParams gPacketPortParams;
