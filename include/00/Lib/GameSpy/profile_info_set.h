#pragma once

#include "types.h"
#include "00/Lib/GameSpy/login_connect.h"

// Which profile field gpiSetInfos and gpiSetInfoi set (the argument "info").
enum {
    GP_NICK = 0x700,
    GP_UNIQUENICK,
    GP_EMAIL,
    GP_PASSWORD,
    GP_FIRSTNAME,
    GP_LASTNAME,
    GP_ICQUIN,
    GP_HOMEPAGE,
    GP_ZIPCODE,
    GP_COUNTRYCODE,
    GP_BIRTHDAY,
    GP_SEX,
    GP_CPUBRANDID,
    GP_CPUSPEED,
    GP_MEMORY,
    GP_VIDEOCARD1STRING,
    GP_VIDEOCARD1RAM,
    GP_VIDEOCARD2STRING,
    GP_VIDEOCARD2RAM,
    GP_CONNECTIONID,
    GP_CONNECTIONSPEED,
    GP_HASNETWORK,
    GP_OSSTRING,
    GP_AIMNAME,
    GP_PIC,
    GP_OCCUPATIONID,
    GP_INDUSTRYID,
    GP_INCOMEID,
    GP_MARRIEDID,
    GP_CHILDCOUNT,
    GP_INTERESTS1,
};

u32 gpiSetInfoCache(GpConnection *connection, GpiProfile *profile, GPIInfoCache *cache);
u32 gpiGetInfo(GpConnection *connection, u32 profile, s32 checkCache, u32 blocking, GpiCallbackFn callback, u32 param);
u32 gpiSendGetInfo(GpConnection *connection, u32 profileid, u32 operationid);
u32 gpiSetInfos(GpConnection *connection, s32 info, const s8 *value);
u32 gpiSetInfoi(GpConnection *connection, s32 info, s32 value);
u32 gpiSendUserInfo(GpConnection *connection, const char *info, const char *value);
u32 gpiSendLocalInfo(GpConnection *connection, const char *info, const char *value);
