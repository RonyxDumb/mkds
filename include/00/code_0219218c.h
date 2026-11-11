#pragma once

#include "types.h"
#include "00/code_021919ac.h"

u32 gpiSetInfoCache(GpConnection *connection, Unk021919ac_node *profile, Unk021919ac_f0 *cache);
u32 gpiGetInfo(GpConnection *connection, u32 profile, s32 checkCache, u32 blocking, u32 callback, u32 param);
u32 gpiSendGetInfo(GpConnection *connection, u32 profileid, u32 operationid);
u32 gpiSetInfos(GpConnection *connection, s32 info, const s8 *value);
u32 gpiSetInfoi(GpConnection *connection, s32 info, s32 value);
u32 gpiSendUserInfo(GpConnection *connection, const char *info, const char *value);
u32 gpiSendLocalInfo(GpConnection *connection, const char *info, const char *value);
