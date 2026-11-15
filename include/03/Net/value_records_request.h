#pragma once

#include "types.h"
#include "03/Net/essid_packet_steps.h"

void EssidFreeExpHeapBlockWrapper(void *block);

extern const u8 gNintendoDsItemBytes[12];
extern u8 gValueRecordsRequestSucceeded;
extern struct ValueRecordsRequest *gValueRecordsRequest;
