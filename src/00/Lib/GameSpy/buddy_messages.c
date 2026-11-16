#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/DWC/matching_result_codes.h"
#include "narrow_string_functions.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/profile_walk.h"
#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"

u32 gpiSendAuthBuddyRequest(GPConnection *connection, GPIProfile *profile) {
    GPIConnection *gpState;
    gpState = connection->mGpiConnection;
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\authadd\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\fromprofileid\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, profile->mProfileId);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\sig\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, profile->mAuthSig);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

s32 gpiProcessRecvBuddyMessage(GPConnection *connection, char *input) {
    char buffer[0x1000];
    char valueText[0x100];
    char intText[0x10];
    GPICallback messageCallback;
    GPICallback inviteCallback;
    GPICallback statusCallback;
    GPICallback requestCallback;
    s32 date;
    s32 profileNumber;
    s32 type;
    s32 productNumber;
    s32 result;
    u16 netPort;
    char *str;
    u8 *cursor;
    enum { REMAINING_NONE } remaining;
    GPIConnection *gpState;
    BuddyMessageData *messageArg;
    BuddyRequestData *requestArg;
    GameInviteData *inviteArg;
    GPIProfile *profileRec;
    GPIBuddyStatus *buddyInfo;

    gpState = connection->mGpiConnection;
    if (gpiValueForKey(input, "\\bm\\", buffer, 0x1000) == FALSE) {
        gpiSetError(connection, 1, "Unexpected data was received from the server.");
        gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
        return GP_NETWORK_ERROR;
    }
    type = StrtolBase10(buffer);
    if (gpiValueForKey(input, "\\f\\", buffer, 0x1000) == FALSE) {
        gpiSetError(connection, 1, "Unexpected data was received from the server.");
        gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
        return GP_NETWORK_ERROR;
    }
    profileNumber = StrtolBase10(buffer);
    if (gpiValueForKey(input, "\\date\\", buffer, 0x1000) != FALSE) {
        date = StrtolBase10(buffer);
    } else {
        date = GetTickSeconds(NULL);
    }
    switch (type) {
        case BUDDY_MESSAGE_TYPE_MESSAGE:
            messageCallback = gpState->mCallbacks[3];
            if (messageCallback.mCallback == NULL) {
                break;
            }
            messageArg = DWCi_GsMalloc(0xc);
            if (messageArg == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            if (gpiValueForKey(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            messageArg->mUnk_08 = DWCi_GsMalloc(strlen(buffer) + 1);
            if (messageArg->mUnk_08 == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            strcpy(messageArg->mUnk_08, buffer);
            messageArg->mProfile = profileNumber;
            messageArg->mDate = date;
            result = gpiAddCallback(connection, messageCallback, messageArg, NULL,
                                      PROFILE_CALLBACK_TYPE_FREE_MESSAGE_TEXT);
            if (result != 0) {
                return result;
            }
            break;
        case BUDDY_MESSAGE_TYPE_REQUEST:
            profileRec = gpiProfileListAdd(connection, profileNumber);
            if (profileRec == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            if (gpiValueForKey(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            str = strstr(buffer, "|signed|");
            if (str == NULL) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            *str = 0;
            if (strlen(str + 8) != 0x20) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            DWCi_GsFree(profileRec->mAuthSig);
            profileRec->mAuthSig = NULL;
            str += 8;
            profileRec->mAuthSig = goastrdup(str);
            profileRec->mRequestCount++;
            requestCallback = gpState->mCallbacks[1];
            if (requestCallback.mCallback == NULL) {
                break;
            }
            requestArg = DWCi_GsMalloc(0x40c);
            if (requestArg == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            CopyStringWithTerminator(requestArg->mReason, buffer, 0x401);
            requestArg->mProfile = profileNumber;
            requestArg->mDate = date;
            result = gpiAddCallback(connection, requestCallback, requestArg, NULL, PROFILE_CALLBACK_TYPE_REQUEST);
            if (result != 0) {
                return result;
            }
            break;
        case BUDDY_MESSAGE_TYPE_STATUS:
            profileRec = gpiProfileListAdd(connection, profileNumber);
            if (profileRec == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            if (profileRec->mBuddyStatus == NULL) {
                profileRec->mBuddyStatus = DWCi_GsMalloc(0x18);
                if (profileRec->mBuddyStatus == NULL) {
                    gpiSetErrorString(connection, "Out of memory.");
                    return GP_MEMORY_ERROR;
                }
                cursor = (u8 *) profileRec->mBuddyStatus;
                remaining = 0x18;
                do {
                    *cursor++ = 0;
                } while (--remaining != 0);
                profileRec->mBuddyStatus->mIndex = gpState->mBuddyCount++;
            }
            buddyInfo = profileRec->mBuddyStatus;
            if (gpiValueForKey(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            if (gpiValueForKey(buffer, "|s|", intText, 0x10) == FALSE) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            buddyInfo->mStatus = StrtolBase10(intText);
            DWCi_GsFree(buddyInfo->mStatusString);
            buddyInfo->mStatusString = NULL;
            if (gpiValueForKey(buffer, "|ss|", valueText, 0x100) == FALSE) {
                valueText[0] = 0;
            }
            buddyInfo->mStatusString = goastrdup(valueText);
            if (buddyInfo->mStatusString == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            DWCi_GsFree(buddyInfo->mLocationString);
            buddyInfo->mLocationString = NULL;
            if (gpiValueForKey(buffer, "|ls|", valueText, 0x100) == FALSE) {
                valueText[0] = 0;
            }
            buddyInfo->mLocationString = goastrdup(valueText);
            if (buddyInfo->mLocationString == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            if (gpiValueForKey(buffer, "|ip|", intText, 0x10) == FALSE) {
                buddyInfo->mIp = 0;
            } else {
                buddyInfo->mIp =
                    (((u32) StrtolBase10(intText) >> 24) & 0xff) | (((u32) StrtolBase10(intText) >> 8) & 0xff00) |
                    ((StrtolBase10(intText) << 8) & 0xff0000) | ((StrtolBase10(intText) << 24) & 0xff000000);
            }
            if (gpiValueForKey(buffer, "|p|", intText, 0x10) == FALSE) {
                buddyInfo->mPort = 0;
            } else {
                netPort = StrtolBase10(intText);
                buddyInfo->mPort = (u16) (((netPort >> 8) & 0xff) | ((netPort << 8) & 0xff00));
            }
            statusCallback = gpState->mCallbacks[2];
            if (statusCallback.mCallback == NULL) {
                break;
            }
            messageArg = DWCi_GsMalloc(0xc);
            if (messageArg == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            messageArg->mProfile = profileNumber;
            messageArg->mUnk_08 = (void *) buddyInfo->mIndex;
            messageArg->mDate = date;
            result = gpiAddCallback(connection, statusCallback, messageArg, NULL, PROFILE_CALLBACK_TYPE_STATUS);
            if (result != 0) {
                return result;
            }
            break;
        case BUDDY_MESSAGE_TYPE_INVITE:
            if (gpiValueForKey(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            str = strstr(buffer, "|p|");
            if (str == NULL) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            if ((s8) str[3] == 0) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            productNumber = StrtolBase10(str + 3);
            str = strstr(buffer, "|l|");
            if (str != NULL) {
                CopyStringWithTerminator(valueText, (str + 3), 0x100);
            } else {
                valueText[0] = 0;
            }
            inviteCallback = gpState->mCallbacks[4];
            if (inviteCallback.mCallback == NULL) {
                break;
            }
            inviteArg = DWCi_GsMalloc(0x108);
            if (inviteArg == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
            inviteArg->mProfile = profileNumber;
            inviteArg->mProductId = productNumber;
            strcpy(inviteArg->mLocation, valueText);
            result = gpiAddCallback(connection, inviteCallback, inviteArg, NULL, PROFILE_CALLBACK_TYPE_PLAIN);
            if (result != 0) {
                return result;
            }
            break;
        case GPI_BM_PING:
            if (gpiValueForKey(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 1);
                return GP_NETWORK_ERROR;
            }
            gpiSendBuddyMessage(connection, profileNumber, BUDDY_MESSAGE_TYPE_PONG, "1");
            break;
    }
    return 0;
}

u32 gpiSendServerBuddyMessage(GPConnection *connection, s32 profileid, s32 type, const char *message) {
    GPIConnection *gpState;
    char buffer[0xdad];
    gpState = connection->mGpiConnection;
    CopyStringWithTerminator(buffer, message, 0xdad);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\bm\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, type);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\t\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, profileid);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\msg\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, buffer);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

u32 gpiSendBuddyMessage(GPConnection *connection, s32 profileid, s32 type, const char *message) {
    GPIProfile *profileRec;
    GPIPeer *peerConn;
    u32 result;
    peerConn = gpiGetConnectedPeer(connection, profileid);
    if (peerConn == NULL) {
        if (gpiGetProfile(connection, profileid, &profileRec) == 0 || profileRec->mBuddyStatus == NULL ||
            profileRec->mBuddyStatus->mPort == 0) {
            return gpiSendServerBuddyMessage(connection, profileid, type, message);
        }
        peerConn = gpiAddPeer(connection, profileid, 1);
        if (peerConn == NULL) {
            return 1;
        }
        if (profileRec->mPeerSig == NULL) {
            result = gpiPeerGetSig(connection, peerConn);
            if (result != 0) {
                return result;
            }
        } else {
            result = gpiPeerStartConnect(connection, peerConn);
            if (result != 0) {
                return result;
            }
        }
    }
    result = gpiPeerAddMessage(connection, peerConn, type, message);
    if (result == 0) {
        return 0;
    }
    return result;
}

u32 gpiAuthBuddyRequest(GPConnection *connection, u32 profile) {
    GPIConnection *gpState;
    GPIProfile *profileEntry;
    u32 result;
    gpState = connection->mGpiConnection;
    if (gpiGetProfile(connection, profile, &profileEntry) == 0) {
        gpiSetErrorString(connection, "Invalid profile.");
        return GP_PARAMETER_ERROR;
    }
    if (profileEntry->mAuthSig == NULL) {
        gpiSetErrorString(connection, "Invalid profile.");
        return GP_PARAMETER_ERROR;
    }
    result = gpiSendAuthBuddyRequest(connection, profileEntry);
    if (result == 0) {
        profileEntry->mRequestCount--;
        if (gpState->mInfoCaching == 0 && profileEntry->mRequestCount <= 0) {
            DWCi_GsFree(profileEntry->mAuthSig);
            profileEntry->mAuthSig = NULL;
            if (gpiCanFreeProfile(profileEntry) != 0) {
                gpiRemoveProfile(connection, profileEntry);
            }
        }
        return 0;
    }
    return result;
}

s32 gpiFixBuddyIndices(GPConnection *unused, GPIProfile *profile, void *data) {
    s32 cutoff = (s32) data;
    if (profile->mBuddyStatus != NULL && profile->mBuddyStatus->mIndex > cutoff) {
        --profile->mBuddyStatus->mIndex;
    }
    return 1;
}

u32 gpiDeleteBuddy(GPConnection *connection, u32 profile) {
    GPIConnection *gpState;
    GPIProfile *profileEntry;
    s32 buddyIndex;

    gpState = connection->mGpiConnection;
    if (gpiGetProfile(connection, profile, &profileEntry) == 0) {
        gpiSetErrorString(connection, "Invalid profile.");
        return GP_PARAMETER_ERROR;
    }
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\delbuddy\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\delprofileid\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, profileEntry->mProfileId);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
    if (profileEntry->mBuddyStatus != NULL) {
        buddyIndex = profileEntry->mBuddyStatus->mIndex;
        if (buddyIndex < 0) {
            AssertionFailed("index >= 0", "gpiBuddy.c", NULL, 0x1fd);
        }
        DWCi_GsFree(profileEntry->mBuddyStatus->mStatusString);
        profileEntry->mBuddyStatus->mStatusString = NULL;
        DWCi_GsFree(profileEntry->mBuddyStatus->mLocationString);
        profileEntry->mBuddyStatus->mLocationString = NULL;
        DWCi_GsFree(profileEntry->mBuddyStatus);
        profileEntry->mBuddyStatus = NULL;
        if (gpiCanFreeProfile(profileEntry) != 0) {
            gpiRemoveProfile(connection, profileEntry);
        }
        gpState->mBuddyCount--;
        if (gpState->mBuddyCount < 0) {
            AssertionFailed("iconnection->profileList.numBuddies >= 0", "gpiBuddy.c", NULL, 0x204);
        }
        gpiProfileMap(connection, gpiFixBuddyIndices, (void *) buddyIndex);
    }
    return 0;
}
