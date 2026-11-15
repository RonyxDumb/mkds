#include "00/Lib/GameSpy/profile_info_set.h"

#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/info_cache_free.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "string.h"
#include "print_memory_functions.h"
#include "text_to_number.h"
#include "signed_int_divide.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "00/Lib/GameSpy/operation_queue.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/GameSpy/peer_connection.h"

u32 GpiUnpackDate(GpConnection *connection, s32 date, u32 *day, u32 *month, u32 *year) {
    int isValid;
    u32 unpackedDay;
    u32 unpackedMonth;
    unpackedDay = date >> 0x18 & 0xff;
    unpackedMonth = date >> 0x10 & 0xff;
    date = date & (0x0000ffffu);
    isValid = GpiIsValidDate(unpackedDay, unpackedMonth, date);
    if (isValid == 0) {
        AssertionFailed("gpiIsValidDate(d, m, y)", "gpiInfo.c", NULL, 0xb7);
    }
    isValid = GpiIsValidDate(unpackedDay, unpackedMonth, date);
    if (isValid == 0) {
        GpiSetErrorMessage(connection, "Invalid date.");
        return 2;
    }
    *day = unpackedDay;
    *month = unpackedMonth;
    *year = date;
    return 0;
}

void gpiInfoCacheToArg(GPIInfoCache *cache, GetInfoReply *arg) {
    if (cache->mNick != NULL) {
        GpiCopyString(arg->mNick, cache->mNick, 0x1f);
    } else {
        arg->mNick[0] = 0;
    }
    if (cache->mUniquenick != NULL) {
        GpiCopyString(arg->mUniquenick, cache->mUniquenick, 0x15);
    } else {
        arg->mUniquenick[0] = 0;
    }
    if (cache->mEmail != NULL) {
        GpiCopyString(arg->mEmail, cache->mEmail, 0x33);
    } else {
        arg->mEmail[0] = 0;
    }
    if (cache->mFirstname != NULL) {
        GpiCopyString(arg->mFirstname, cache->mFirstname, 0x1f);
    } else {
        arg->mFirstname[0] = 0;
    }
    if (cache->mLastname != NULL) {
        GpiCopyString(arg->mLastname, cache->mLastname, 0x1f);
    } else {
        arg->mLastname[0] = 0;
    }
    if (cache->mHomepage != NULL) {
        GpiCopyString(arg->mHomepage, cache->mHomepage, 0x4c);
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
    arg->mPic = cache->mPic;
    arg->mOccupationid = cache->mOccupationid;
    arg->mIndustryid = cache->mIndustryid;
    arg->mIncomeid = cache->mIncomeid;
    arg->mMarriedid = cache->mMarriedid;
    arg->mChildcount = cache->mChildcount;
    arg->mInterests1 = cache->mInterests1;
    arg->mOwnership1 = cache->mOwnership1;
    arg->mConntypeid = cache->mConntypeid;
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
    if (strncmp(input, "\\pi\\", 4) != 0) {
        GpiSetError(connection, 1, "Unexpected data was received from the server.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (GpiGetValue(input, "\\profileid\\", buffer, 0x40) == FALSE) {
        GpiSetError(connection, 1, "Unexpected data was received from the server.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    profileid = StrtolBase10(buffer);
    if (profileid <= 0) {
        AssertionFailed("profileid > 0", "gpiInfo.c", NULL, 0x15a);
    }
    GpiFindProfile(connection, profileid, &profileRec);
    {
        GPIInfoCache infoRecord = {0};
        char aimHandleBuf[0x4c];
        infoRecord.mNick = nickText;
        infoRecord.mUniquenick = uniqueNickText;
        infoRecord.mEmail = mailText;
        infoRecord.mFirstname = givenName;
        infoRecord.mLastname = familyName;
        infoRecord.mHomepage = aimHandleBuf;
        infoRecord.mAimName = webPage;
        if (GpiGetValue(input, "\\nick\\", infoRecord.mNick, 0x1f) == FALSE) {
            infoRecord.mNick[0] = 0;
        }
        if (GpiGetValue(input, "\\uniquenick\\", infoRecord.mUniquenick, 0x15) == FALSE) {
            infoRecord.mUniquenick[0] = 0;
        }
        if (GpiGetValue(input, "\\email\\", infoRecord.mEmail, 0x33) == FALSE) {
            infoRecord.mEmail[0] = 0;
        }
        if (GpiGetValue(input, "\\firstname\\", infoRecord.mFirstname, 0x1f) == FALSE) {
            infoRecord.mFirstname[0] = 0;
        }
        if (GpiGetValue(input, "\\lastname\\", infoRecord.mLastname, 0x1f) == FALSE) {
            infoRecord.mLastname[0] = 0;
        }
        if (GpiGetValue(input, "\\icquin\\", buffer, 0x40) == FALSE) {
            infoRecord.mIcquin = -1;
        } else {
            infoRecord.mIcquin = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\homepage\\", infoRecord.mHomepage, 0x4c) == FALSE) {
            infoRecord.mHomepage[0] = 0;
        }
        if (GpiGetValue(input, "\\zipcode\\", infoRecord.mZipcode, 0xb) == FALSE) {
            infoRecord.mZipcode[0] = 0;
        }
        if (GpiGetValue(input, "\\countrycode\\", infoRecord.mCountrycode, 3) == FALSE) {
            infoRecord.mCountrycode[0] = 0;
        }
        if (GpiGetValue(input, "\\lon\\", buffer, 0x40) == FALSE) {
            infoRecord.mLongitude = 0;
        } else {
            infoRecord.mLongitude = atof(buffer);
        }
        if (GpiGetValue(input, "\\lat\\", buffer, 0x40) == FALSE) {
            infoRecord.mLatitude = 0;
        } else {
            infoRecord.mLatitude = atof(buffer);
        }
        if (GpiGetValue(input, "\\loc\\", infoRecord.mPlace, 0x80) == FALSE) {
            infoRecord.mPlace[0] = 0;
        }
        if (GpiGetValue(input, "\\birthday\\", buffer, 0x40) == FALSE) {
            infoRecord.mBirthday = 0;
            infoRecord.mBirthmonth = 0;
            infoRecord.mBirthyear = 0;
        } else {
            result = GpiUnpackDate(connection, StrtolBase10(buffer), &infoRecord.mBirthday, &infoRecord.mBirthmonth,
                                   &infoRecord.mBirthyear);
            if (result != 0) {
                return result;
            }
        }
        if (GpiGetValue(input, "\\sex\\", buffer, 0x40) == FALSE) {
            infoRecord.mSex = PROFILE_SEX_CODE_DEFAULT;
        } else if ((s8) buffer[0] == 0x30) {
            infoRecord.mSex = PROFILE_SEX_CODE_MALE;
        } else if ((s8) buffer[0] == 0x31) {
            infoRecord.mSex = PROFILE_SEX_CODE_FEMALE;
        } else {
            infoRecord.mSex = PROFILE_SEX_CODE_DEFAULT;
        }
        if (GpiGetValue(input, "\\pmask\\", buffer, 0x40) == FALSE) {
            infoRecord.mPmask = -1;
        } else {
            infoRecord.mPmask = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\aim\\", infoRecord.mAimName, 0x33) == FALSE) {
            infoRecord.mAimName[0] = 0;
        }
        if (GpiGetValue(input, "\\pic\\", buffer, 0x40) == FALSE) {
            infoRecord.mPic = 0;
        } else {
            infoRecord.mPic = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\occ\\", buffer, 0x40) == FALSE) {
            infoRecord.mOccupationid = 0;
        } else {
            infoRecord.mOccupationid = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\ind\\", buffer, 0x40) == FALSE) {
            infoRecord.mIndustryid = 0;
        } else {
            infoRecord.mIndustryid = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\inc\\", buffer, 0x40) == FALSE) {
            infoRecord.mIncomeid = 0;
        } else {
            infoRecord.mIncomeid = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\mar\\", buffer, 0x40) == FALSE) {
            infoRecord.mMarriedid = 0;
        } else {
            infoRecord.mMarriedid = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\chc\\", buffer, 0x40) == FALSE) {
            infoRecord.mChildcount = 0;
        } else {
            infoRecord.mChildcount = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\i1\\", buffer, 0x40) == FALSE) {
            infoRecord.mInterests1 = 0;
        } else {
            infoRecord.mInterests1 = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\o1\\", buffer, 0x40) == FALSE) {
            infoRecord.mOwnership1 = 0;
        } else {
            infoRecord.mOwnership1 = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\conn\\", buffer, 0x40) == FALSE) {
            infoRecord.mConntypeid = 0;
        } else {
            infoRecord.mConntypeid = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\sig\\", buffer, 0x40) == FALSE) {
            GpiSetError(connection, 1, "Unexpected data was received from the server.");
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        saveFlag = gpState->mInfoCaching;
        peerConn = gpState->mPeerList;
        while (peerConn != NULL) {
            if (peerConn->mProfileId == profileid && peerConn->mState == PROFILE_PEER_STATE_WAIT_PROFILE_INFO) {
                if (profileRec == NULL) {
                    profileRec = GpiFindOrAddProfile(connection, profileid);
                }
                peerConn->mState = PROFILE_PEER_STATE_START_CONNECT;
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
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            gpiInfoCacheToArg(&infoRecord, arg);
            arg->mResult = GP_REQUEST_OK;
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
        GpiAppendBufferString(connection, buffer, "\\updatepro\\\\sesskey\\");
        GpiAppendBufferNumber(connection, buffer, gpState->mSesskey);
        GpiAppendBufferString(connection, buffer, gpState->mUpdateproBuffer);
        GpiAppendBufferString(connection, buffer, "\\final\\");
        gpState->mUpdateproBufferLength = 0;
    }
    if (0 < gpState->mUpdateuiBufferLength) {
        GpiAppendBufferString(connection, buffer, "\\updateui\\\\sesskey\\");
        GpiAppendBufferNumber(connection, buffer, gpState->mSesskey);
        GpiAppendBufferString(connection, buffer, gpState->mUpdateuiBuffer);
        GpiAppendBufferString(connection, buffer, "\\final\\");
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
        case GP_ZIPCODE:
            if (value < 0) {
                GpiSetErrorMessage(connection, "Invalid zipcode.");
                return 2;
            }
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\zipcode\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_SEX:
            switch (value) {
                case PROFILE_SEX_CODE_MALE:
                    result = gpiSendLocalInfo(connection, "\\sex\\", "0");
                    if (result != 0) {
                        return result;
                    }
                    break;
                case PROFILE_SEX_CODE_FEMALE:
                    result = gpiSendLocalInfo(connection, "\\sex\\", "1");
                    if (result != 0) {
                        return result;
                    }
                    break;
                case PROFILE_SEX_CODE_DEFAULT:
                    result = gpiSendLocalInfo(connection, "\\sex\\", "2");
                    if (result != 0) {
                        return result;
                    }
                    break;
                default:
                    GpiSetErrorMessage(connection, "Invalid sex.");
                    return 2;
            }
            break;
        case GP_ICQUIN:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\icquin\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_CPUBRANDID:
            sprintf(intText, "%d", value);
            result = gpiSendUserInfo(connection, "\\cpubrandid\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_CPUSPEED:
            sprintf(intText, "%d", value);
            result = gpiSendUserInfo(connection, "\\cpuspeed\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_MEMORY:
            sprintf(intText, "%d", value / 16);
            result = gpiSendUserInfo(connection, "\\memory\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_VIDEOCARD1RAM:
            sprintf(intText, "%d", value / 4);
            result = gpiSendUserInfo(connection, "\\videocard1ram\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_VIDEOCARD2RAM:
            sprintf(intText, "%d", value / 4);
            result = gpiSendUserInfo(connection, "\\videocard2ram\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_CONNECTIONID:
            sprintf(intText, "%d", value);
            result = gpiSendUserInfo(connection, "\\connectionid\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_CONNECTIONSPEED:
            sprintf(intText, "%d", value);
            result = gpiSendUserInfo(connection, "\\connectionspeed\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_HASNETWORK:
            if (value != 0) {
                value = 1;
            }
            sprintf(intText, "%d", value);
            result = gpiSendUserInfo(connection, "\\hasnetwork\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_PIC:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\pic\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_OCCUPATIONID:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\occ\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_INDUSTRYID:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\ind\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_INCOMEID:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\inc\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_MARRIEDID:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\mar\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_CHILDCOUNT:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\chc\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        case GP_INTERESTS1:
            sprintf(intText, "%d", value);
            result = gpiSendLocalInfo(connection, "\\i1\\", intText);
            if (result != 0) {
                return result;
            }
            break;
        default:
            GpiSetErrorMessage(connection, "Invalid info.");
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
        GpiSetErrorMessage(connection, "Invalid value.");
        return 2;
    }
    switch (info) {
        case GP_NICK:
            if (*value == 0) {
                GpiSetErrorMessage(connection, "Invalid value.");
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            GpiCopyString(gpState->mNick, valueCopy, 0x1f);
            result = gpiSendLocalInfo(connection, "\\nick\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_UNIQUENICK:
            if (*value == 0) {
                GpiSetErrorMessage(connection, "Invalid value.");
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x15);
            GpiCopyString((char *) gpState->mUniquenick, valueCopy, 0x15);
            result = gpiSendLocalInfo(connection, "\\uniquenick\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_EMAIL:
            if (*value == 0) {
                GpiSetErrorMessage(connection, "Invalid value.");
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x33);
            _strlwr((s8 *) valueCopy);
            GpiCopyString(gpState->mEmail, valueCopy, 0x33);
            result = gpiSendUserInfo(connection, "\\email\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_PASSWORD:
            if (*value == 0) {
                GpiSetErrorMessage(connection, "Invalid value.");
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            GpiCopyString((char *) gpState->mPassword, valueCopy, 0x1f);
            result = gpiSendUserInfo(connection, "\\password\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_FIRSTNAME:
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            result = gpiSendLocalInfo(connection, "\\firstname\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_LASTNAME:
            GpiCopyString(valueCopy, (const char *) value, 0x1f);
            result = gpiSendLocalInfo(connection, "\\lastname\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_HOMEPAGE:
            GpiCopyString(valueCopy, (const char *) value, 0x4c);
            result = gpiSendLocalInfo(connection, "\\homepage\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_ZIPCODE:
            GpiCopyString(valueCopy, (const char *) value, 0xb);
            result = gpiSendLocalInfo(connection, "\\zipcode\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_COUNTRYCODE:
            if (strlen((const char *) value) != 2) {
                GpiSetErrorMessage(connection, "Invalid countrycode.");
                return 2;
            }
            GpiCopyString(valueCopy, (const char *) value, 3);
            result = gpiSendLocalInfo(connection, "\\countrycode\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_SEX: {
            s32 character;

            character = *value;
            if (character >= 0 && character < 0x80) {
                character = gUpperCaseMap[character];
            }
            if ((s8) character == 0x4d) {
                __memcpy(valueCopy, "0", 2);
            } else if ((s8) character == 0x46) {
                __memcpy(valueCopy, "1", 2);
            } else {
                __memcpy(valueCopy, "2", 2);
            }
            result = gpiSendLocalInfo(connection, "\\sex\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        }
        case GP_ICQUIN:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\icquin\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_CPUSPEED:
            result = gpiSetInfoi(connection, GP_CPUSPEED, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case GP_MEMORY:
            result = gpiSetInfoi(connection, GP_MEMORY, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case GP_VIDEOCARD1STRING:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\videocard1string\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_VIDEOCARD1RAM:
            result = gpiSetInfoi(connection, GP_VIDEOCARD1RAM, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case GP_VIDEOCARD2STRING:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\videocard2string\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_VIDEOCARD2RAM:
            result = gpiSetInfoi(connection, GP_VIDEOCARD2RAM, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case GP_CONNECTIONSPEED:
            result = gpiSetInfoi(connection, GP_CONNECTIONSPEED, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case GP_HASNETWORK:
            result = gpiSetInfoi(connection, GP_HASNETWORK, StrtolBase10((const char *) value));
            if (result != 0) {
                return result;
            }
            break;
        case GP_OSSTRING:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\osstring\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_AIMNAME:
            GpiCopyString(valueCopy, (const char *) value, 0x33);
            result = gpiSendLocalInfo(connection, "\\aim\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_PIC:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\pic\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_OCCUPATIONID:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\occ\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_INDUSTRYID:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\ind\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_INCOMEID:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\inc\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_MARRIEDID:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\mar\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_CHILDCOUNT:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\chc\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        case GP_INTERESTS1:
            GpiCopyString(valueCopy, (const char *) value, 0x100);
            result = gpiSendLocalInfo(connection, "\\i1\\", valueCopy);
            if (result != 0) {
                return result;
            }
            break;
        default:
            GpiSetErrorMessage(connection, "Invalid info.");
            return 2;
    }
    return 0;
}

static void UnusedLiteralsInfo(GpConnection *connection, s32 value) {
    char intValue[0x10];

    sprintf(intValue, "%d", value);
    GpiSetErrorMessage(connection, "Invalid info.");
    gpiSendLocalInfo(connection, "\\birthday\\", intValue);
}

u32 gpiSendGetInfo(GpConnection *connection, u32 profileid, u32 operationid) {
    GpiConnection *gpState;

    gpState = connection->mGpiConnection;
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\getprofile\\\\sesskey\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\profileid\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, profileid);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\id\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, operationid);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

u32 gpiGetInfo(GpConnection *connection, u32 profile, s32 checkCache, u32 blocking, GpiCallbackFn callback, u32 param) {
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
            GpiSetErrorMessage(connection, "Out of memory.");
            return 1;
        }
        gpiInfoCacheToArg(profileEntry->mCache, arg);
        arg->mResult = GP_REQUEST_OK;
        arg->mProfile = profile;
        queuedCallback.mCallback = callback;
        queuedCallback.mParam = param;
        result = GpiCreateOperation(connection, PROFILE_OPERATION_INFO, 0, &pendingOp, 1, callback, param);
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
        result = GpiCreateOperation(connection, PROFILE_OPERATION_INFO, 0, &pendingOp, blocking, callback, param);
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
        profile->mCache->mNick = goastrdup(cache->mNick);
        profile->mCache->mUniquenick = goastrdup(cache->mUniquenick);
        profile->mCache->mEmail = goastrdup(cache->mEmail);
        profile->mCache->mFirstname = goastrdup(cache->mFirstname);
        profile->mCache->mLastname = goastrdup(cache->mLastname);
        profile->mCache->mHomepage = goastrdup(cache->mHomepage);
        profile->mCache->mAimName = goastrdup(cache->mAimName);
    }
    if (profile->mCache != NULL) {
        return 1;
    }
    return 0;
}
