#pragma once

#include "types.h"
#include "03/Net/essid_wcm.h"

void EssidFreeExpHeapBlockWrapper(void *block);

extern const u8 gNintendoDsItemBytes[11];
extern u8 gValueRecordsRequestSucceeded[1];
extern struct ValueRecordsRequest *gValueRecordsRequest;
