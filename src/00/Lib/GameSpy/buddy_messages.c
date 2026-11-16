#include "00/Lib/GameSpy/buddy_messages.h"
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

u32 gpiSendAuthBuddyRequest(GpConnection *connection, GpiProfile *profile) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\authadd\\");
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\fromprofileid\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, profile->mProfileId);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\sig\\");
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, profile->mAuthSig);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

s32 gpiProcessRecvBuddyMessage(GpConnection *connection, char *input) {
    char buffer[0x1000];
    char replyValue[0x100];
    char intText[0x10];
    GpiCallback messageCallback;
    GpiCallback inviteCallback;
    GpiCallback statusCallback;
    GpiCallback requestCallback;
    s32 date;
    s32 profileNumber;
    s32 type;
    s32 productNumber;
    s32 result;
    u16 netPort;
    char *str;
    u8 *cursor;
    enum { REMAINING_NONE } remaining;
    GpiConnection *gpState;
    BuddyMessageData *messageArg;
    BuddyRequestData *requestArg;
    GameInviteData *inviteArg;
    GpiProfile *profileRec;
    GpiBuddyStatus *buddyInfo;

    gpState = connection->mGpiConnection;
    if (GpiGetValue(input, "\\bm\\", buffer, 0x1000) == FALSE) {
        GpiSetError(connection, 1, "Unexpected data was received from the server.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    type = StrtolBase10(buffer);
    if (GpiGetValue(input, "\\f\\", buffer, 0x1000) == FALSE) {
        GpiSetError(connection, 1, "Unexpected data was received from the server.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    profileNumber = StrtolBase10(buffer);
    if (GpiGetValue(input, "\\date\\", buffer, 0x1000) != FALSE) {
        date = StrtolBase10(buffer);
    } else {
        date = GetUnixTime(NULL);
    }
    switch (type) {
        case GPI_BM_MESSAGE:
            messageCallback = gpState->mCallbacks[3];
            if (messageCallback.mCallback == NULL) {
                break;
            }
            messageArg = DWCi_GsMalloc(0xc);
            if (messageArg == NULL) {
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            if (GpiGetValue(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            messageArg->mUnk_08 = DWCi_GsMalloc(strlen(buffer) + 1);
            if (messageArg->mUnk_08 == NULL) {
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            strcpy(messageArg->mUnk_08, buffer);
            messageArg->mProfile = profileNumber;
            messageArg->mDate = date;
            result = GpiQueueCallback(connection, messageCallback, messageArg, NULL,
                                      PROFILE_CALLBACK_TYPE_FREE_MESSAGE_TEXT);
            if (result != 0) {
                return result;
            }
            break;
        case GPI_BM_REQUEST:
            profileRec = GpiFindOrAddProfile(connection, profileNumber);
            if (profileRec == NULL) {
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            if (GpiGetValue(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            str = strstr(buffer, "|signed|");
            if (str == NULL) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            *str = 0;
            if (strlen(str + 8) != 0x20) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
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
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            GpiCopyString(requestArg->mReason, buffer, 0x401);
            requestArg->mProfile = profileNumber;
            requestArg->mDate = date;
            result = GpiQueueCallback(connection, requestCallback, requestArg, NULL, PROFILE_CALLBACK_TYPE_REQUEST);
            if (result != 0) {
                return result;
            }
            break;
        case GPI_BM_STATUS:
            profileRec = GpiFindOrAddProfile(connection, profileNumber);
            if (profileRec == NULL) {
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            if (profileRec->mBuddyStatus == NULL) {
                profileRec->mBuddyStatus = DWCi_GsMalloc(0x18);
                if (profileRec->mBuddyStatus == NULL) {
                    GpiSetErrorMessage(connection, "Out of memory.");
                    return 1;
                }
                cursor = (u8 *) profileRec->mBuddyStatus;
                remaining = 0x18;
                do {
                    *cursor++ = 0;
                } while (--remaining != 0);
                profileRec->mBuddyStatus->mIndex = gpState->mBuddyCount++;
            }
            buddyInfo = profileRec->mBuddyStatus;
            if (GpiGetValue(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (GpiGetValue(buffer, "|s|", intText, 0x10) == FALSE) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            buddyInfo->mStatus = StrtolBase10(intText);
            DWCi_GsFree(buddyInfo->mStatusString);
            buddyInfo->mStatusString = NULL;
            if (GpiGetValue(buffer, "|ss|", replyValue, 0x100) == FALSE) {
                replyValue[0] = 0;
            }
            buddyInfo->mStatusString = goastrdup(replyValue);
            if (buddyInfo->mStatusString == NULL) {
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            DWCi_GsFree(buddyInfo->mLocationString);
            buddyInfo->mLocationString = NULL;
            if (GpiGetValue(buffer, "|ls|", replyValue, 0x100) == FALSE) {
                replyValue[0] = 0;
            }
            buddyInfo->mLocationString = goastrdup(replyValue);
            if (buddyInfo->mLocationString == NULL) {
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            if (GpiGetValue(buffer, "|ip|", intText, 0x10) == FALSE) {
                buddyInfo->mIp = 0;
            } else {
                buddyInfo->mIp =
                    (((u32) StrtolBase10(intText) >> 24) & 0xff) | (((u32) StrtolBase10(intText) >> 8) & 0xff00) |
                    ((StrtolBase10(intText) << 8) & 0xff0000) | ((StrtolBase10(intText) << 24) & 0xff000000);
            }
            if (GpiGetValue(buffer, "|p|", intText, 0x10) == FALSE) {
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
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            messageArg->mProfile = profileNumber;
            messageArg->mUnk_08 = (void *) buddyInfo->mIndex;
            messageArg->mDate = date;
            result = GpiQueueCallback(connection, statusCallback, messageArg, NULL, PROFILE_CALLBACK_TYPE_STATUS);
            if (result != 0) {
                return result;
            }
            break;
        case GPI_BM_INVITE:
            if (GpiGetValue(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            str = strstr(buffer, "|p|");
            if (str == NULL) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if ((s8) str[3] == 0) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            productNumber = StrtolBase10(str + 3);
            str = strstr(buffer, "|l|");
            if (str != NULL) {
                GpiCopyString(replyValue, (str + 3), 0x100);
            } else {
                replyValue[0] = 0;
            }
            inviteCallback = gpState->mCallbacks[4];
            if (inviteCallback.mCallback == NULL) {
                break;
            }
            inviteArg = DWCi_GsMalloc(0x108);
            if (inviteArg == NULL) {
                GpiSetErrorMessage(connection, "Out of memory.");
                return 1;
            }
            inviteArg->mProfile = profileNumber;
            inviteArg->mProductId = productNumber;
            strcpy(inviteArg->mLocation, replyValue);
            result = GpiQueueCallback(connection, inviteCallback, inviteArg, NULL, PROFILE_CALLBACK_TYPE_PLAIN);
            if (result != 0) {
                return result;
            }
            break;
        case GPI_BM_PING:
            if (GpiGetValue(input, "\\msg\\", buffer, 0x1000) == FALSE) {
                GpiSetError(connection, 1, "Unexpected data was received from the server.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            gpiSendBuddyMessage(connection, profileNumber, GPI_BM_PONG, "1");
            break;
    }
    return 0;
}

u32 gpiSendServerBuddyMessage(GpConnection *connection, s32 profileid, s32 type, const char *message) {
    GpiConnection *gpState;
    char buffer[0xdad];
    gpState = connection->mGpiConnection;
    GpiCopyString(buffer, message, 0xdad);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\bm\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, type);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\t\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, profileid);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\msg\\");
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, buffer);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

u32 gpiSendBuddyMessage(GpConnection *connection, s32 profileid, s32 type, const char *message) {
    GpiProfile *profileRec;
    GpiPeer *peerConn;
    u32 result;
    peerConn = gpiGetConnectedPeer(connection, profileid);
    if (peerConn == NULL) {
        if (GpiFindProfile(connection, profileid, &profileRec) == 0 || profileRec->mBuddyStatus == NULL ||
            profileRec->mBuddyStatus->mPort == 0) {
            return gpiSendServerBuddyMessage(connection, profileid, type, message);
        }
        peerConn = GpiPeerCreate(connection, profileid, 1);
        if (peerConn == NULL) {
            return 1;
        }
        if (profileRec->mPeerSig == NULL) {
            result = gpiPeerGetSig(connection, peerConn);
            if (result != 0) {
                return result;
            }
        } else {
            result = GpiPeerConnect(connection, peerConn);
            if (result != 0) {
                return result;
            }
        }
    }
    result = GpiPeerQueueMessage(connection, peerConn, type, message);
    if (result == 0) {
        return 0;
    }
    return result;
}

u32 gpiAuthBuddyRequest(GpConnection *connection, u32 profile) {
    GpiConnection *gpState;
    GpiProfile *profileEntry;
    u32 result;
    gpState = connection->mGpiConnection;
    if (GpiFindProfile(connection, profile, &profileEntry) == 0) {
        GpiSetErrorMessage(connection, "Invalid profile.");
        return 2;
    }
    if (profileEntry->mAuthSig == NULL) {
        GpiSetErrorMessage(connection, "Invalid profile.");
        return 2;
    }
    result = gpiSendAuthBuddyRequest(connection, profileEntry);
    if (result == 0) {
        profileEntry->mRequestCount--;
        if (gpState->mInfoCaching == 0 && profileEntry->mRequestCount <= 0) {
            DWCi_GsFree(profileEntry->mAuthSig);
            profileEntry->mAuthSig = NULL;
            if (GpiIsProfileEmpty(profileEntry) != 0) {
                GpiRemoveProfile(connection, profileEntry);
            }
        }
        return 0;
    }
    return result;
}

s32 GpiDecrementBuddyIndexAbove(GpConnection *unused, GpiProfile *profile, void *data) {
    s32 minimum = (s32) data;
    if (profile->mBuddyStatus != NULL && profile->mBuddyStatus->mIndex > minimum) {
        --profile->mBuddyStatus->mIndex;
    }
    return 1;
}

u32 GpiWriteDelbuddyAndRemoveBuddy(GpConnection *connection, u32 profile) {
    GpiConnection *gpState;
    GpiProfile *profileEntry;
    s32 buddyIndex;

    gpState = connection->mGpiConnection;
    if (GpiFindProfile(connection, profile, &profileEntry) == 0) {
        GpiSetErrorMessage(connection, "Invalid profile.");
        return 2;
    }
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\delbuddy\\");
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\sesskey\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\delprofileid\\");
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, profileEntry->mProfileId);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, "\\final\\");
    if (profileEntry->mBuddyStatus != NULL) {
        buddyIndex = profileEntry->mBuddyStatus->mIndex;
        if (buddyIndex < 0) {
            LogThrowAssertion("index >= 0", "gpiBuddy.c", NULL, 0x1fd);
        }
        DWCi_GsFree(profileEntry->mBuddyStatus->mStatusString);
        profileEntry->mBuddyStatus->mStatusString = NULL;
        DWCi_GsFree(profileEntry->mBuddyStatus->mLocationString);
        profileEntry->mBuddyStatus->mLocationString = NULL;
        DWCi_GsFree(profileEntry->mBuddyStatus);
        profileEntry->mBuddyStatus = NULL;
        if (GpiIsProfileEmpty(profileEntry) != 0) {
            GpiRemoveProfile(connection, profileEntry);
        }
        gpState->mBuddyCount--;
        if (gpState->mBuddyCount < 0) {
            LogThrowAssertion("iconnection->profileList.numBuddies >= 0", "gpiBuddy.c", NULL, 0x204);
        }
        GpiForEachProfileWhileNonZero(connection, GpiDecrementBuddyIndexAbove, (void *) buddyIndex);
    }
    return 0;
}
