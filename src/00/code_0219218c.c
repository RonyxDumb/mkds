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
        AssertionFailed(gIsValidDateAssertText, gGpiInfoFileName, NULL, 0xb7);
    }
    isValid = GpiIsValidDate(unpackedDay, unpackedMonth, date);
    if (isValid == 0) {
        GpiSetErrorMessage((u32 *) (u32) connection, gInvalidDateErrorString);
        return 2;
    }
    *day = unpackedDay;
    *month = unpackedMonth;
    *year = date;
    return 0;
}

void gpiInfoCacheToArg(GPIInfoCache *cache, GetInfoReply *arg) {
    if (cache->mUnk_00[0] != NULL) {
        GpiCopyString(arg->mNick, cache->mUnk_00[0], 0x1f);
    } else {
        arg->mNick[0] = 0;
    }
    if (cache->mUnk_00[1] != NULL) {
        GpiCopyString(arg->mUniquenick, cache->mUnk_00[1], 0x15);
    } else {
        arg->mUniquenick[0] = 0;
    }
    if (cache->mUnk_00[2] != NULL) {
        GpiCopyString(arg->mEmail, cache->mUnk_00[2], 0x33);
    } else {
        arg->mEmail[0] = 0;
    }
    if (cache->mUnk_00[3] != NULL) {
        GpiCopyString(arg->mFirstname, cache->mUnk_00[3], 0x1f);
    } else {
        arg->mFirstname[0] = 0;
    }
    if (cache->mUnk_00[4] != NULL) {
        GpiCopyString(arg->mLastname, cache->mUnk_00[4], 0x1f);
    } else {
        arg->mLastname[0] = 0;
    }
    if (cache->mUnk_00[5] != NULL) {
        GpiCopyString(arg->mHomepage, cache->mUnk_00[5], 0x4c);
    } else {
        arg->mHomepage[0] = 0;
    }
    arg->mIcquin = cache->mIcquin;
    GpiCopyString(arg->mZipcode, cache->mZipcode, 0xb);
    GpiCopyString(arg->mCountrycode, cache->mCountrycode, 3);
    arg->mLongitude = cache->mLongitude;
    arg->mLatitude = cache->mLatitude;
    if (cache->mPlace != NULL) {
        GpiCopyString(arg->mPlace, cache->mPlace, 0x80);
    } else {
        arg->mPlace[0] = 0;
    }
    arg->mBirthday = cache->mBirthday;
    arg->mBirthmonth = cache->mBirthmonth;
    arg->mBirthyear = cache->mBirthyear;
    arg->mSex = cache->mSex;
    arg->mPmask = cache->mPmask;
    if (cache->mAimName != NULL) {
        GpiCopyString(arg->mAimName, cache->mAimName, 0x33);
    } else {
        arg->mAimName[0] = 0;
    }
    arg->mIcquin = cache->mIcquin;
    arg->mLongitude = cache->mLongitude;
    arg->mLatitude = cache->mLatitude;
    arg->mBirthday = cache->mBirthday;
    arg->mBirthmonth = cache->mBirthmonth;
    arg->mBirthyear = cache->mBirthyear;
    arg->mSex = cache->mSex;
    arg->mPmask = cache->mPmask;
    arg->mPic = cache->mUnk_cc[0];
    arg->mOccupationid = cache->mUnk_cc[1];
    arg->mIndustryid = cache->mUnk_cc[2];
    arg->mIncomeid = cache->mUnk_cc[3];
    arg->mMarriedid = cache->mUnk_cc[4];
    arg->mChildcount = cache->mUnk_cc[5];
    arg->mInterests1 = cache->mUnk_cc[6];
    arg->mOwnership1 = cache->mUnk_cc[7];
    arg->mConntypeid = cache->mUnk_cc[8];
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
        AssertionFailed(gProfileidAssertion, gGpiInfoFileName, NULL, 0x15a);
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
        infoRecord.mAimName = webPage;
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
        if (GpiGetValue(input, gIcquinKey, buffer, 0x40) == FALSE) {
            infoRecord.mIcquin = -1;
        } else {
            infoRecord.mIcquin = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gHomepageKey, infoRecord.mUnk_00[5], 0x4c) == FALSE) {
            infoRecord.mUnk_00[5][0] = 0;
        }
        if (GpiGetValue(input, gZipcodeKey, infoRecord.mZipcode, 0xb) == FALSE) {
            infoRecord.mZipcode[0] = 0;
        }
        if (GpiGetValue(input, gCountrycodeKey, infoRecord.mCountrycode, 3) == FALSE) {
            infoRecord.mCountrycode[0] = 0;
        }
        if (GpiGetValue(input, gLonKey, buffer, 0x40) == FALSE) {
            infoRecord.mLongitude = 0;
        } else {
            infoRecord.mLongitude = atof(buffer);
        }
        if (GpiGetValue(input, gLatKey, buffer, 0x40) == FALSE) {
            infoRecord.mLatitude = 0;
        } else {
            infoRecord.mLatitude = atof(buffer);
        }
        if (GpiGetValue(input, gLocKey, infoRecord.mPlace, 0x80) == FALSE) {
            infoRecord.mPlace[0] = 0;
        }
        if (GpiGetValue(input, gBirthdayKey, buffer, 0x40) == FALSE) {
            infoRecord.mBirthday = 0;
            infoRecord.mBirthmonth = 0;
            infoRecord.mBirthyear = 0;
        } else {
            result = GpiUnpackDate((u32 *) connection, StrtolBase10(buffer), &infoRecord.mBirthday,
                                   &infoRecord.mBirthmonth, &infoRecord.mBirthyear);
            if (result != 0) {
                return result;
            }
        }
        if (GpiGetValue(input, gSexKey, buffer, 0x40) == FALSE) {
            infoRecord.mSex = 0x502;
        } else if ((s8) buffer[0] == 0x30) {
            infoRecord.mSex = 0x500;
        } else if ((s8) buffer[0] == 0x31) {
            infoRecord.mSex = 0x501;
        } else {
            infoRecord.mSex = 0x502;
        }
        if (GpiGetValue(input, gPmaskKey, buffer, 0x40) == FALSE) {
            infoRecord.mPmask = -1;
        } else {
            infoRecord.mPmask = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gAimKey, infoRecord.mAimName, 0x33) == FALSE) {
            infoRecord.mAimName[0] = 0;
        }
        if (GpiGetValue(input, gPicKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[0] = 0;
        } else {
            infoRecord.mUnk_cc[0] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gOccKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[1] = 0;
        } else {
            infoRecord.mUnk_cc[1] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gIndKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[2] = 0;
        } else {
            infoRecord.mUnk_cc[2] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gIncKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[3] = 0;
        } else {
            infoRecord.mUnk_cc[3] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gMarKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[4] = 0;
        } else {
            infoRecord.mUnk_cc[4] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gChcKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[5] = 0;
        } else {
            infoRecord.mUnk_cc[5] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gI1Key, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[6] = 0;
        } else {
            infoRecord.mUnk_cc[6] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gO1Key, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[7] = 0;
        } else {
            infoRecord.mUnk_cc[7] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gConnKey, buffer, 0x40) == FALSE) {
            infoRecord.mUnk_cc[8] = 0;
        } else {
            infoRecord.mUnk_cc[8] = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, data_ov000_021b3234, buffer, 0x40) == FALSE) {
            GpiSetError(connection, 1, data_ov000_021b31b8);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        saveFlag = gpState->mInfoCaching;
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
        if (profileRec == NULL && gpState->mInfoCaching != 0) {
            profileRec = GpiFindOrAddProfile(connection, profileid);
        }
        if (saveFlag != 0) {
            DWCi_GsFree(profileRec->mPeerSig);
            profileRec->mPeerSig = NULL;
            profileRec->mPeerSig = goastrdup(buffer);
        }
        if (gpState->mInfoCaching != 0) {
            gpiSetInfoCache(connection, profileRec, &infoRecord);
        }
        callback = operation->mCallback;
        if (callback.mCallback != NULL) {
            arg = DWCi_GsMalloc(0x204);
            if (arg == NULL) {
                GpiSetErrorMessage(connection, data_ov000_021b2f58);
                return 1;
            }
            gpiInfoCacheToArg(&infoRecord, arg);
            arg->mResult = 0;
            arg->mProfile = profileid;
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
                GpiSetErrorMessage(connection, gInvalidZipcodeErrorString);
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
                    result = gpiSendLocalInfo(connection, gSexKey, gSexOtherValue);
                    if (result != 0) {
                        return result;
                    }
                    break;
                default:
                    GpiSetErrorMessage(connection, gInvalidSexErrorString);
                    return 2;
            }
            break;
        case 0x706:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gIcquinKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70c:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, gCpubrandidKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70d:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, gCpuspeedKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x70e:
            sprintf(intText, data_ov000_021b2f9c, value / 16);
            result = gpiSendUserInfo(connection, gMemoryKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x710:
            sprintf(intText, data_ov000_021b2f9c, value / 4);
            result = gpiSendUserInfo(connection, gVideocard1ramKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x712:
            sprintf(intText, data_ov000_021b2f9c, value / 4);
            result = gpiSendUserInfo(connection, gVideocard2ramKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x713:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, gConnectionidKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x714:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, gConnectionspeedKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x715:
            if (value != 0) {
                value = 1;
            }
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendUserInfo(connection, gHasnetworkKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x718:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gPicKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x719:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gOccKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71a:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gIndKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71b:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gIncKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71c:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gMarKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71d:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gChcKey, intText);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71e:
            sprintf(intText, data_ov000_021b2f9c, value);
            result = gpiSendLocalInfo(connection, gI1Key, intText);
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
                __memcpy(valueCopy, gSexOtherValue, 2);
            }
            result = gpiSendLocalInfo(connection, gSexKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        }
        case 0x706:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gIcquinKey, valueCopy);
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
            result = gpiSendLocalInfo(connection, gVideocard1stringKey, valueCopy);
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
            result = gpiSendLocalInfo(connection, gVideocard2stringKey, valueCopy);
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
            result = gpiSendLocalInfo(connection, gOsstringKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x717:
            GpiCopyString(valueCopy, (const char *) value, 0x33);
            result = gpiSendLocalInfo(connection, gAimKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x718:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gPicKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x719:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gOccKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71a:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gIndKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71b:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gIncKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71c:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gMarKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71d:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gChcKey, valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case 0x71e:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, gI1Key, valueCopy);
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
    GpiOperation *pendingOp;
    GetInfoReply *arg;
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
    if (gpState->mInfoCaching == 0) {
        reuseCached = FALSE;
    }
    if (callback != 0 && reuseCached != FALSE && GpiFindProfile(connection, profile, &profileEntry) != 0 &&
        profileEntry->mCache != 0) {
        arg = DWCi_GsMalloc(0x204);
        if (arg == NULL) {
            GpiSetErrorMessage(connection, data_ov000_021b2f58);
            return 1;
        }
        gpiInfoCacheToArg(profileEntry->mCache, arg);
        arg->mResult = 0;
        arg->mProfile = profile;
        queuedCallback.mCallback = (void (*)(void *, void *, u32)) callback;
        queuedCallback.mParam = param;
        result = GpiCreateOperation(connection, 2, 0, (s32 *) &pendingOp, 1, callback, param);
        if (result != 0) {
            return result;
        }
        operationId = pendingOp->mId;
        result = GpiQueueCallback(connection, queuedCallback, arg, pendingOp, 0);
        if (result != 0) {
            return result;
        }
        GpiRemoveOperation(connection, pendingOp);
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
    if (connection->mGpiConnection->mInfoCaching == 0) {
        return 1;
    }
    gpiFreeInfoCache(profile);
    profile->mCache = DWCi_GsMalloc(0xf0);
    if (profile->mCache != NULL) {
        *profile->mCache = *cache;
        profile->mCache->mUnk_00[0] = goastrdup(cache->mUnk_00[0]);
        profile->mCache->mUnk_00[1] = goastrdup(cache->mUnk_00[1]);
        profile->mCache->mUnk_00[2] = goastrdup(cache->mUnk_00[2]);
        profile->mCache->mUnk_00[3] = goastrdup(cache->mUnk_00[3]);
        profile->mCache->mUnk_00[4] = goastrdup(cache->mUnk_00[4]);
        profile->mCache->mUnk_00[5] = goastrdup(cache->mUnk_00[5]);
        profile->mCache->mAimName = goastrdup(cache->mAimName);
    }
    if (profile->mCache != NULL) {
        return 1;
    }
    return 0;
}
