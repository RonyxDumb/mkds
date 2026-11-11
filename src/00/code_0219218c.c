#include "00/code_0219218c.h"

#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_0219210c.h"
#include "00/code_02193000.h"
#include "00/code_02196590.h"
#include "00/code_02196594.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213a460.h"
#include "code_02133048.h"
#include "00/code_0218e2dc.h"
#include "00/code_02192d64.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "00/code_021947e4.h"
#include "00/code_021965a0.h"
#include "00/code_021919ac.h"
#include "00/code_02193634.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190cd4.h"
#include "00/code_02196000.h"
#include "00/code_021a3668.h"
#include "00/code_02193b88.h"

u32 GpiUnpackDate(u32 *connection, s32 date, u32 *day, u32 *month, u32 *year) {
    int isValid;
    u32 unpackedDay;
    u32 unpackedMonth;
    unpackedDay = date >> 0x18 & 0xff;
    unpackedMonth = date >> 0x10 & 0xff;
    date = date & (0x0000ffffu);
    isValid = GpiIsValidDate(unpackedDay, unpackedMonth, date);
    if (isValid == 0) {
        AssertionFailed(data_ov000_021b323c, data_ov000_021b31f8, NULL, 0xb7);
    }
    isValid = GpiIsValidDate(unpackedDay, unpackedMonth, date);
    if (isValid == 0) {
        GpiSetErrorMessage((u32 *) (u32) connection, data_ov000_021b3254);
        return 2;
    }
    *day = unpackedDay;
    *month = unpackedMonth;
    *year = date;
    return 0;
}

void gpiInfoCacheToArg(GPIInfoCache *cache, GetInfoReply *arg) {
    if (cache->mUnk_00[0] != NULL) {
        GpiCopyString(arg->mUnk_008, cache->mUnk_00[0], 0x1f);
    } else {
        arg->mUnk_008[0] = 0;
    }
    if (cache->mUnk_00[1] != NULL) {
        GpiCopyString(arg->mUnk_027, cache->mUnk_00[1], 0x15);
    } else {
        arg->mUnk_027[0] = 0;
    }
    if (cache->mUnk_00[2] != NULL) {
        GpiCopyString(arg->mUnk_03c, cache->mUnk_00[2], 0x33);
    } else {
        arg->mUnk_03c[0] = 0;
    }
    if (cache->mUnk_00[3] != NULL) {
        GpiCopyString(arg->mUnk_06f, cache->mUnk_00[3], 0x1f);
    } else {
        arg->mUnk_06f[0] = 0;
    }
    if (cache->mUnk_00[4] != NULL) {
        GpiCopyString(arg->mUnk_08e, cache->mUnk_00[4], 0x1f);
    } else {
        arg->mUnk_08e[0] = 0;
    }
    if (cache->mUnk_00[5] != NULL) {
        GpiCopyString(arg->mUnk_0ad, cache->mUnk_00[5], 0x4c);
    } else {
        arg->mUnk_0ad[0] = 0;
    }
    arg->mUnk_0fc = cache->mUnk_18;
    GpiCopyString(arg->mUnk_100, cache->mUnk_1c, 0xb);
    GpiCopyString(arg->mUnk_10b, cache->mUnk_27, 3);
    arg->mUnk_110 = cache->mUnk_2c;
    arg->mUnk_114 = cache->mUnk_30;
    if (cache->mUnk_34 != NULL) {
        GpiCopyString(arg->mUnk_118, cache->mUnk_34, 0x80);
    } else {
        arg->mUnk_118[0] = 0;
    }
    arg->mUnk_198 = cache->mUnk_b4;
    arg->mUnk_19c = cache->mUnk_b8;
    arg->mUnk_1a0 = cache->mUnk_bc;
    arg->mUnk_1a4 = cache->mUnk_c0;
    arg->mUnk_1a8 = cache->mUnk_c4;
    if (cache->mUnk_c8 != NULL) {
        GpiCopyString(arg->mUnk_1ac, cache->mUnk_c8, 0x33);
    } else {
        arg->mUnk_1ac[0] = 0;
    }
    arg->mUnk_0fc = cache->mUnk_18;
    arg->mUnk_110 = cache->mUnk_2c;
    arg->mUnk_114 = cache->mUnk_30;
    arg->mUnk_198 = cache->mUnk_b4;
    arg->mUnk_19c = cache->mUnk_b8;
    arg->mUnk_1a0 = cache->mUnk_bc;
    arg->mUnk_1a4 = cache->mUnk_c0;
    arg->mUnk_1a8 = cache->mUnk_c4;
    arg->mUnk_1e0 = cache->mUnk_cc[0];
    arg->mUnk_1e4 = cache->mUnk_cc[1];
    arg->mUnk_1e8 = cache->mUnk_cc[2];
    arg->mUnk_1ec = cache->mUnk_cc[3];
    arg->mUnk_1f0 = cache->mUnk_cc[4];
    arg->mUnk_1f4 = cache->mUnk_cc[5];
    arg->mUnk_1f8 = cache->mUnk_cc[6];
    arg->mUnk_1fc = cache->mUnk_cc[7];
    arg->mUnk_200 = cache->mUnk_cc[8];
}

s32 GpiProcessInfoOperation(GpConnection *connection, GpiOperation *operation, const char *input) {
    GpiConnection *gpState;
    GpiProfile *profileRec;
    GpiCallback callback;
    char buffer[0x40];
    char nickText[0x1f];
    char uniqueNickText[0x15];
    char mailText[0x33];
    char givenName[0x1f];
    char familyName[0x1f];
    char webPage[0x33];
    GetInfoReply *arg;
    GpiPeer *peerConn;
    s32 profileid;
    s32 result;
    s32 saveFlag;

    gpState = connection->mGpiConnection;
    if (GpiReadError(connection, input, 1) != FALSE) {
        return 4;
    }
    if (strncmp(input, gPiKey, 4) != 0) {
        GpiSetError(connection, 1, data_ov000_021b31b8);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (GpiGetValue(input, data_ov000_021b2f80, buffer, 0x40) == FALSE) {
        GpiSetError(connection, 1, data_ov000_021b31b8);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    profileid = StrtolBase10(buffer);
    if (profileid <= 0) {
        AssertionFailed(data_ov000_021b31e8, data_ov000_021b31f8, NULL, 0x15a);
    }
    GpiFindProfile(connection, profileid, &profileRec);
    {
        GPIInfoCache infoRecord = {0};
        char aimHandleBuf[0x4c];
        infoRecord.mUnk_00[0] = nickText;
        infoRecord.mUnk_00[1] = uniqueNickText;
        infoRecord.mUnk_00[2] = mailText;
        infoRecord.mUnk_00[3] = givenName;
        infoRecord.mUnk_00[4] = familyName;
        infoRecord.mUnk_00[5] = aimHandleBuf;
        infoRecord.mUnk_c8 = webPage;
        if (GpiGetValue(input, data_ov000_021b2fcc, infoRecord.mUnk_00[0], 0x1f) == FALSE) {
            infoRecord.mUnk_00[0][0] = 0;
        }
        if (GpiGetValue(input, data_ov000_021b2fd4, infoRecord.mUnk_00[1], 0x15) == FALSE) {
            infoRecord.mUnk_00[1][0] = 0;
        }
        if (GpiGetValue(input, data_ov000_021b2fe4, infoRecord.mUnk_00[2], 0x33) == FALSE) {
            infoRecord.mUnk_00[2][0] = 0;
        }
        if (GpiGetValue(input, gFirstnameKey, infoRecord.mUnk_00[3], 0x1f) == FALSE) {
            infoRecord.mUnk_00[3][0] = 0;
        }
        if (GpiGetValue(input, gLastnameKey, infoRecord.mUnk_00[4], 0x1f) == FALSE) {
            infoRecord.mUnk_00[4][0] = 0;
        }
        if (GpiGetValue(input, data_ov000_021b3064, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_18 = -1;
        } else {
            infoRecord.mUnk_18 = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gHomepageKey, infoRecord.mUnk_00[5], 0x4c) == FALSE) {
            infoRecord.mUnk_00[5][0] = 0;
        }
        if (GpiGetValue(input, gZipcodeKey, infoRecord.mUnk_1c, 0xb) == FALSE) {
            infoRecord.mUnk_1c[0] = 0;
        }
        if (GpiGetValue(input, gCountrycodeKey, infoRecord.mUnk_27, 3) == FALSE) {
            infoRecord.mUnk_27[0] = 0;
        }
        if (GpiGetValue(input, data_ov000_021b3204, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_2c = 0;
        } else {
            infoRecord.mUnk_2c = atof(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b320c, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_30 = 0;
        } else {
            infoRecord.mUnk_30 = atof(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b3214, infoRecord.mUnk_34, 0x80) == FALSE) {
            infoRecord.mUnk_34[0] = 0;
        }
        if (GpiGetValue(input, data_ov000_021b2fb0, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_b4 = 0;
            infoRecord.mUnk_b8 = 0;
            infoRecord.mUnk_bc = 0;
        } else {
            result = GpiUnpackDate((u32 *) connection, StrtolBase10(buffer), &infoRecord.mUnk_b4, &infoRecord.mUnk_b8,
                                   &infoRecord.mUnk_bc);
            if (result != 0) {
                return result;
            }
        }
        if (GpiGetValue(input, gSexKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_c0 = 0x502;
        } else if ((s8) buffer[0] == 0x30) {
            infoRecord.mUnk_c0 = 0x500;
        } else if ((s8) buffer[0] == 0x31) {
            infoRecord.mUnk_c0 = 0x501;
        } else {
            infoRecord.mUnk_c0 = 0x502;
        }
        if (GpiGetValue(input, data_ov000_021b321c, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_c4 = -1;
        } else {
            infoRecord.mUnk_c4 = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b30a4, infoRecord.mUnk_c8, 0x33) == FALSE) {
            infoRecord.mUnk_c8[0] = 0;
        }
        if (GpiGetValue(input, data_ov000_021b30ac, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[0] = 0;
        } else {
            infoRecord.mUnk_cc[0] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b30b4, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[1] = 0;
        } else {
            infoRecord.mUnk_cc[1] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b30bc, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[2] = 0;
        } else {
            infoRecord.mUnk_cc[2] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b30c4, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[3] = 0;
        } else {
            infoRecord.mUnk_cc[3] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b30cc, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[4] = 0;
        } else {
            infoRecord.mUnk_cc[4] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b30d4, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[5] = 0;
        } else {
            infoRecord.mUnk_cc[5] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b30dc, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[6] = 0;
        } else {
            infoRecord.mUnk_cc[6] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b3224, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[7] = 0;
        } else {
            infoRecord.mUnk_cc[7] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b322c, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[8] = 0;
        } else {
            infoRecord.mUnk_cc[8] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b3234, buffer, 0x40) == FALSE) {
            GpiSetError(connection, 1, data_ov000_021b31b8);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        saveFlag = gpState->mUnk_100;
        peerConn = gpState->mPeerList;
        while (peerConn != NULL) {
            if (peerConn->mProfileId == profileid && peerConn->mState == 0x65) {
                if (profileRec == NULL) {
                    profileRec = GpiFindOrAddProfile(connection, profileid);
                }
                peerConn->mState = 0x66;
                saveFlag = 1;
            }
            peerConn = peerConn->mNext;
        }
        if (profileRec == NULL && gpState->mUnk_100 != 0) {
            profileRec = GpiFindOrAddProfile(connection, profileid);
        }
        if (saveFlag != 0) {
            DWCi_GsFree(profileRec->mUnk_18);
            profileRec->mUnk_18 = NULL;
            profileRec->mUnk_18 = goastrdup(buffer);
        }
        if (gpState->mUnk_100 != 0) {
            gpiSetInfoCache(connection, profileRec, &infoRecord);
        }
        callback = operation->mUnk_0c;
        if (callback.mCallback != NULL) {
            arg = DWCi_GsMalloc(0x204);
            if (arg == NULL) {
                GpiSetErrorMessage(connection, data_ov000_021b2f58);
                return 1;
            }
            gpiInfoCacheToArg(&infoRecord, arg);
            arg->mUnk_000 = 0;
            arg->mUnk_004 = profileid;
            result = GpiQueueCallback(connection, callback, arg, operation, 0);
            if (result != 0) {
                return result;
            }
        }
        GpiRemoveOperation(connection, operation);
        return 0;
    }
}

u32 GpiWriteUpdateBuffers(GpConnection *connection, GpiBuffer *buffer) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    if (0 < gpState->mUpdateproBufferLength) {
        GpiAppendBufferString(connection, buffer, gUpdateproKey);
        GpiAppendBufferNumber(connection, buffer, gpState->mSesskey);
        GpiAppendBufferString(connection, buffer, gpState->mUpdateproBuffer);
        GpiAppendBufferString(connection, buffer, data_ov000_021b2f94);
        gpState->mUpdateproBufferLength = 0;
    }
    if (0 < gpState->mUpdateuiBufferLength) {
        GpiAppendBufferString(connection, buffer, gUpdateuiKey);
        GpiAppendBufferNumber(connection, buffer, gpState->mSesskey);
        GpiAppendBufferString(connection, buffer, gpState->mUpdateuiBuffer);
        GpiAppendBufferString(connection, buffer, data_ov000_021b2f94);
        gpState->mUpdateuiBufferLength = 0;
    }
    return 0;
}

u32 gpiSendLocalInfo(GpConnection *connection, const char *info, const char *value) {
    GpiConnection *gpState;
    u32 result;

    gpState = connection->mGpiConnection;
    result = GpiAppendBufferString(connection, &gpState->mUpdateproBuffer, info);
    if (result != 0) {
        return result;
    }
    result = GpiAppendBufferString(connection, &gpState->mUpdateproBuffer, value);
    if (result != 0) {
        return result;
    }
    return 0;
}

u32 gpiSendUserInfo(GpConnection *connection, const char *info, const char *value) {
    GpiConnection *gpState;
    u32 result;

    gpState = connection->mGpiConnection;
    result = GpiAppendBufferString(connection, &gpState->mUpdateuiBuffer, info);
    if (result != 0) {
        return result;
    }
    result = GpiAppendBufferString(connection, &gpState->mUpdateuiBuffer, value);
    if (result != 0) {
        return result;
    }
    return 0;
}

u32 gpiSetInfoi(GpConnection *connection, s32 info, s32 value) {
    char intText[0x10];
    u32 result;

    switch (info) {
        case 0x708:
            if (value < 0) {
                GpiSetErrorMessage(connection, data_ov000_021b30e4);
                return 2;
            }
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gZipcodeKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70b:
            switch (value) {
                case 0x500:
                    result = gpiSendLocalInfo(connection, gSexKey, data_ov000_021b3050);
                    if (result != 0) {
                        return result;
                    }
                    break;
                case 0x501:
                    result = gpiSendLocalInfo(connection, gSexKey, data_ov000_021b3054);
                    if (result != 0) {
                        return result;
                    }
                    break;
                case 0x502:
                    result = gpiSendLocalInfo(connection, gSexKey, data_ov000_021b3058);
                    if (result != 0) {
                        return result;
                    }
                    break;
                default:
                    GpiSetErrorMessage(connection, data_ov000_021b30f8);
                    return 2;
            }
            break;
        case 0x706:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b3064, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70c:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, data_ov000_021b3108, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70d:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, data_ov000_021b3118, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70e:
            sprintf(intText, data_ov000_021b2f9c, value / 16);
            result = gpiSendUserInfo(connection, data_ov000_021b3124, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x710:
            sprintf(intText, data_ov000_021b2f9c, value / 4);
            result = gpiSendUserInfo(connection, data_ov000_021b3130, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x712:
            sprintf(intText, data_ov000_021b2f9c, value / 4);
            result = gpiSendUserInfo(connection, data_ov000_021b3140, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x713:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, data_ov000_021b3150, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x714:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, data_ov000_021b3160, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x715:
            if (value != 0) {
                value = 1;
            }
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, data_ov000_021b3174, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x718:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b30ac, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x719:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b30b4, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71a:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b30bc, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71b:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b30c4, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71c:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b30cc, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71d:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b30d4, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71e:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, data_ov000_021b30dc, intText);
            if (result != 0) {
                return result;
            }
            break;
        default:
            GpiSetErrorMessage(connection, gInvalidInfoErrorString);
            return 2;
    }
    return 0;
}

u32 gpiSetInfos(GpConnection *connection, s32 info, const s8 *value) {
    GpiConnection *gpState;
    char valueCopy[0x100];
    u32 result;

    gpState = connection->mGpiConnection;
    if (value == NULL) {
        GpiSetErrorMessage(connection, gInvalidValueErrorString);
        return 2;
    }
    switch (info) {
        case 0x700:
            if (*value == 0) {
                GpiSetErrorMessage(connection, gInvalidValueErrorString);
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            GpiCopyString(gpState->mNick, valueCopy, 0x1f);
            result = gpiSendLocalInfo(connection, data_ov000_021b2fcc, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x701:
            if (*value == 0) {
                GpiSetErrorMessage(connection, gInvalidValueErrorString);
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x15);
            GpiCopyString((char *) gpState->mUniquenick, valueCopy, 0x15);
            result = gpiSendLocalInfo(connection, data_ov000_021b2fd4, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x702:
            if (*value == 0) {
                GpiSetErrorMessage(connection, gInvalidValueErrorString);
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x33);
            _strlwr((s8 *) valueCopy);
            GpiCopyString(gpState->mEmail, valueCopy, 0x33);
            result = gpiSendUserInfo(connection, data_ov000_021b2fe4, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x703:
            if (*value == 0) {
                GpiSetErrorMessage(connection, gInvalidValueErrorString);
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            GpiCopyString((char *) gpState->mPassword, valueCopy, 0x1f);
            result = gpiSendUserInfo(connection, gPasswordKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x704:
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            result = gpiSendLocalInfo(connection, gFirstnameKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x705:
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            result = gpiSendLocalInfo(connection, gLastnameKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x707:
            GpiCopyString(valueCopy, (const char *) value, 0x4c);
            result = gpiSendLocalInfo(connection, gHomepageKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x708:
            GpiCopyString(valueCopy, (const char *) value, 0xb);
            result = gpiSendLocalInfo(connection, gZipcodeKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x709:
            if (strlen((const char *) value) != 2) {
                GpiSetErrorMessage(connection, gInvalidCountrycodeErrorString);
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 3);
            result = gpiSendLocalInfo(connection, gCountrycodeKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70b: {
            s32 d;

            d = *value;
            if (d >= 0 && d < 0x80) {
                d = gUpperCaseMap[d];
            }
            if ((s8) d == 0x4d) {
                __memcpy(valueCopy, data_ov000_021b3050, 2);
            } else if ((s8) d == 0x46) {
                __memcpy(valueCopy, data_ov000_021b3054, 2);
            } else {
                __memcpy(valueCopy, data_ov000_021b3058, 2);
            }
            result = gpiSendLocalInfo(connection, gSexKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        }
        case 0x706:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b3064, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70d:
            result = gpiSetInfoi(connection, 0x70d, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case 0x70e:
            result = gpiSetInfoi(connection, 0x70e, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case 0x70f:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b3070, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x710:
            result = gpiSetInfoi(connection, 0x710, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case 0x711:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b3084, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x712:
            result = gpiSetInfoi(connection, 0x712, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case 0x714:
            result = gpiSetInfoi(connection, 0x714, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case 0x715:
            result = gpiSetInfoi(connection, 0x715, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case 0x716:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b3098, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x717:
            GpiCopyString(valueCopy, (const char *) value, 0x33);
            result = gpiSendLocalInfo(connection, data_ov000_021b30a4, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x718:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b30ac, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x719:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b30b4, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71a:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b30bc, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71b:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b30c4, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71c:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b30cc, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71d:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b30d4, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71e:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, data_ov000_021b30dc, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        default:
            GpiSetErrorMessage(connection, gInvalidInfoErrorString);
            return 2;
    }
    return 0;
}

u32 gpiSendGetInfo(GpConnection *connection, u32 profileid, u32 operationid) {
    GpiConnection *gpState;

    gpState = connection->mGpiConnection;
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gGetprofileKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b2f80);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, profileid);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b2f8c);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, operationid);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b2f94);
    return 0;
}

u32 gpiGetInfo(GpConnection *connection, u32 profile, s32 checkCache, u32 blocking, u32 callback, u32 param) {
    GpiProfile *profileEntry;
    Unk021919ac_node *pendingOp;
    Unk021919ac_m *arg;
    GpiCallback queuedCallback;
    u32 result;
    BOOL reuseCached;
    u32 operationId;
    GpiConnection *gpState;

    gpState = connection->mGpiConnection;
    pendingOp = NULL;
    reuseCached = FALSE;
    if (checkCache == 1) {
        reuseCached = TRUE;
    }
    if (gpState->mUnk_100 == 0) {
        reuseCached = FALSE;
    }
    if (callback != 0 && reuseCached != FALSE && GpiFindProfile(connection, profile, &profileEntry) != 0 &&
        profileEntry->mUnk_0c != 0) {
        arg = DWCi_GsMalloc(0x204);
        if (arg == NULL) {
            GpiSetErrorMessage(connection, data_ov000_021b2f58);
            return 1;
        }
        gpiInfoCacheToArg(profileEntry->mUnk_0c, (GetInfoReply *) arg);
        arg->mUnk_000 = 0;
        arg->mUnk_004 = profile;
        queuedCallback.mCallback = (void (*)(void *, void *, u32)) callback;
        queuedCallback.mUnk_04 = param;
        result = GpiCreateOperation(connection, 2, 0, (s32 *) &pendingOp, 1, callback, param);
        if (result != 0) {
            return result;
        }
        operationId = pendingOp->mId;
        result = GpiQueueCallback(connection, queuedCallback, arg, (GpiOperation *) pendingOp, 0);
        if (result != 0) {
            return result;
        }
        GpiRemoveOperation(connection, (GpiOperation *) pendingOp);
    } else {
        result = GpiCreateOperation(connection, 2, 0, (s32 *) &pendingOp, blocking, callback, param);
        if (result != 0) {
            return result;
        }
        operationId = pendingOp->mId;
        result = gpiSendGetInfo(connection, profile, operationId);
        if (result != 0) {
            return result;
        }
    }
    if (blocking != 0) {
        result = GpiUpdateConnection(connection, operationId);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

u32 gpiSetInfoCache(GpConnection *connection, GpiProfile *profile, GPIInfoCache *cache) {
    if (connection->mGpiConnection->mUnk_100 == 0) {
        return 1;
    }
    gpiFreeInfoCache(profile);
    profile->mUnk_0c = DWCi_GsMalloc(0xf0);
    if (profile->mUnk_0c != NULL) {
        *profile->mUnk_0c = *cache;
        profile->mUnk_0c->mUnk_00[0] = goastrdup(cache->mUnk_00[0]);
        profile->mUnk_0c->mUnk_00[1] = goastrdup(cache->mUnk_00[1]);
        profile->mUnk_0c->mUnk_00[2] = goastrdup(cache->mUnk_00[2]);
        profile->mUnk_0c->mUnk_00[3] = goastrdup(cache->mUnk_00[3]);
        profile->mUnk_0c->mUnk_00[4] = goastrdup(cache->mUnk_00[4]);
        profile->mUnk_0c->mUnk_00[5] = goastrdup(cache->mUnk_00[5]);
        profile->mUnk_0c->mUnk_c8 = goastrdup(cache->mUnk_c8);
    }
    if (profile->mUnk_0c != NULL) {
        return 1;
    }
    return 0;
}
