#pragma once

#include "types.h"
#include "00/Lib/GameSpy/login_connect.h"

// Values of the "info" argument of gpiSetInfos and gpiSetInfoi: which profile value to send. Each function takes its
// own subset and answers "Invalid info." to the rest; neither takes PROFILE_INFO_BIRTHDAY.
enum {
    PROFILE_INFO_NICK = 0x700,
    PROFILE_INFO_UNIQUENICK,
    PROFILE_INFO_EMAIL,
    PROFILE_INFO_PASSWORD,
    PROFILE_INFO_FIRSTNAME,
    PROFILE_INFO_LASTNAME,
    PROFILE_INFO_ICQUIN,
    PROFILE_INFO_HOMEPAGE,
    PROFILE_INFO_ZIPCODE,
    PROFILE_INFO_COUNTRYCODE,
    PROFILE_INFO_BIRTHDAY,
    PROFILE_INFO_SEX,
    PROFILE_INFO_CPUBRANDID,
    PROFILE_INFO_CPUSPEED,
    PROFILE_INFO_MEMORY,
    PROFILE_INFO_VIDEOCARD1STRING,
    PROFILE_INFO_VIDEOCARD1RAM,
    PROFILE_INFO_VIDEOCARD2STRING,
    PROFILE_INFO_VIDEOCARD2RAM,
    PROFILE_INFO_CONNECTIONID,
    PROFILE_INFO_CONNECTIONSPEED,
    PROFILE_INFO_HASNETWORK,
    PROFILE_INFO_OSSTRING,
    PROFILE_INFO_AIMNAME,
    PROFILE_INFO_PIC,
    PROFILE_INFO_OCCUPATIONID,
    PROFILE_INFO_INDUSTRYID,
    PROFILE_INFO_INCOMEID,
    PROFILE_INFO_MARRIEDID,
    PROFILE_INFO_CHILDCOUNT,
    PROFILE_INFO_INTERESTS1,
};

u32 gpiSetInfoCache(GPConnection *connection, GPIProfile *profile, GPIInfoCache *cache);
u32 gpiGetInfo(GPConnection *connection, u32 profile, s32 checkCache, u32 blocking, GPCallback callback, u32 param);
u32 gpiSendGetInfo(GPConnection *connection, u32 profileid, u32 operationid);
u32 gpiSetInfos(GPConnection *connection, s32 info, const s8 *value);
u32 gpiSetInfoi(GPConnection *connection, s32 info, s32 value);
u32 gpiSendUserInfo(GPConnection *connection, const char *info, const char *value);
u32 gpiSendLocalInfo(GPConnection *connection, const char *info, const char *value);
