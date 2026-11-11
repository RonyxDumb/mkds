#include "00/code_02194bb8.h"
#include "00/code_0218f960.h"

#include "00/code_02196590.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e2dc.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021965a0.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "00/code_02196594.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "code_0213a460.h"
#include "00/code_021947e4.h"
#include "00/unk_021b2000.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02193b88.h"
#include "00/code_0218f15c.h"
#include "00/code_02193000.h"
#include "00/code_02193634.h"
#include "code_021384cc.h"
#include "00/unk_021b4000.h"
#include "00/code_02190cd4.h"
#include "00/code_021a6d5c.h"

void gpiHandleTransferMessage(GpConnection *connection, GpiPeer *peer, s32 type, const char *headers, s32 buffer,
                              s32 len) {
    char value[0x40];
    s32 transferKey[3];

    if (GpiGetValue(headers, gXferKey, value, 0x40) != FALSE) {
        if (sscanf(value, gTransferIdFormat, &transferKey[0], &transferKey[1], &transferKey[2]) == 3) {
            gpiSendTransferReply(connection, transferKey, peer, 2, NULL);
        }
    }
}

s32 GpiOpenSearchSocket(GpConnection *connection, GpiOperation *operation) {
    GPISearchData *data;
    SOCHostEnt *resolvedHost;
    s32 openResult;

    data = operation->mData;
    data->mInputBufferCapacity = 0x1000;
    data->mInputBuffer = DWCi_GsMalloc(data->mInputBufferCapacity + 1);
    if (data->mInputBuffer == NULL) {
        GpiSetErrorMessage(connection, data_ov000_021b35f8);
        return 1;
    }
    data->mSocket = OpenNetSocket(2, 1, 0);
    if (data->mSocket == -1) {
        GpiSetError(connection, 5, data_ov000_021b38c0);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (SetSockBlocking(data->mSocket, 0) == FALSE) {
        GpiSetError(connection, 5, data_ov000_021b38e8);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    resolvedHost = SOC_GetHostByName(gSearchManagerName);
    if (resolvedHost == NULL) {
        GpiSetError(connection, 5, gResolveSearchHostErrorString);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    {
        SOCSockAddrIn address = {0};

        address.mFamily = 2;
        address.mAddr = resolvedHost->mAddrList[0][0];
        if (address.mAddr == 0) {
            AssertionFailed(data_ov000_021b394c, gGpiSearchFileName, NULL, 0x59);
        }
        address.mPort = 0xcd74;
        if (connect(data->mSocket, &address, 8) == -1) {
            openResult = GOAGetLastError(data->mSocket);
            if (openResult != -6 && openResult != -0x1a && openResult != -0x4c) {
                GpiSetError(connection, 5, data_ov000_021b396c);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
        }
    }
    operation->mState = 1;
    return 0;
}

BOOL GpiCreateSearch(GpConnection *connection, GPISearchData **searchData, u32 kind) {
    GPISearchData *data;

    data = DWCi_GsMalloc(0x144);
    if (data == NULL) {
        GpiSetErrorMessage(connection, data_ov000_021b35f8);
        return TRUE;
    }
    memset(data, 0, 0x144);
    data->mKind = kind;
    data->mSocket = -1;
    data->mInputBuffer = NULL;
    data->mInputBufferLength = 0;
    data->mInputBufferPos = 0;
    data->mInputBufferCapacity = 0;
    data->mOutputBufferLength = 0;
    data->mOutputBufferPos = 0;
    data->mOutputBufferCapacity = 0x1000;
    data->mOutputBuffer = DWCi_GsMalloc(data->mOutputBufferCapacity + 1);
    if (data->mOutputBuffer == NULL) {
        GpiSetErrorMessage(connection, data_ov000_021b35f8);
        return TRUE;
    }
    data->mProcessing = 0;
    data->mRemove = 0;
    *searchData = data;
    return FALSE;
}

int GpiStartSearchOperation(GpConnection *connection, u32 data, u32 blocking, u32 callback, u32 param) {
    int result;
    int pendingOp;
    connection->mGpiConnection->mSearchCount = connection->mGpiConnection->mSearchCount + 1;
    result = GpiCreateOperation(connection, 3, data, &pendingOp, blocking, callback, param);
    if (((result == 0) && (result = GpiOpenSearchSocket(connection, (GpiOperation *) pendingOp), result == 0)) &&
        ((*(s32 *) (pendingOp + 8) == 0 ||
          (result = GpiUpdateConnection(connection, *(u32 *) (pendingOp + 0x18)), result == 0)))) {
        result = 0;
    }
    return result;
}

int gpiProfileSearch(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                         int icquin, int skip, u32 blocking, u32 callback, u32 param) {
    int result;
    GPISearchData *data;
    if ((((((nick == NULL) || (*nick == 0)) && ((email == NULL || (*email == 0)))) &&
          ((firstname == NULL || (*firstname == 0)))) &&
         ((lastname == NULL || (*lastname == 0)))) &&
        ((icquin == 0 && ((uniquenick == NULL || (*uniquenick == 0)))))) {
        GpiSetErrorMessage((u32 *) connection, gNoSearchCriteriaErrorString);
        return 2;
    }
    result = GpiCreateSearch(connection, &data, 1);
    if (result == 0) {
        if (nick == NULL) {
            data->mNick[0] = 0;
        } else {
            GpiCopyString((char *) data->mNick, (const char *) nick, 0x1f);
        }
        if (uniquenick == NULL) {
            data->mUniquenick[0] = 0;
        } else {
            GpiCopyString((char *) data->mUniquenick, (const char *) uniquenick, 0x15);
        }
        if (email == NULL) {
            data->mEmail[0] = 0;
        } else {
            GpiCopyString((char *) data->mEmail, (const char *) email, 0x33);
        }
        _strlwr(data->mEmail);
        if (firstname == NULL) {
            data->mFirstname[0] = 0;
        } else {
            GpiCopyString((char *) data->mFirstname, (const char *) firstname, 0x1f);
        }
        if (lastname == NULL) {
            data->mLastname[0] = 0;
        } else {
            GpiCopyString((char *) data->mLastname, (const char *) lastname, 0x1f);
        }
        data->mIcquin = icquin;
        if (skip < 0) {
            skip = 0;
        }
        data->mSkip = skip;
        result = GpiStartSearchOperation(connection, (u32) data, blocking, callback, param);
        if (result == 0) {
            result = 0;
        }
    }
    return result;
}

s32 GpiUpdateSearch(GpConnection *connection, GpiOperation *operation) {
    char key[0x200];
    char value[0x200];
    Unk02194cac_10 e;
    u32 state;
    s32 n;
    GpiCallback c1;
    u32 j;
    u32 socketGone;
    GpiCallback c8;
    GpiCallback c7;
    GpiCallback c6;
    GpiCallback c5;
    GpiCallback c4;
    GpiCallback c3;
    GpiCallback c2;
    BOOL d;
    s32 g;
    GpiConnection *gpState;
    GPISearchData *data;
    BOOL loop;
    s32 result;
    BOOL f;
    s32 x;
    s32 y;
    s32 v;
    char *q;
    ProfileMatch *q1;
    ProfileMatch *t1;
    PlayerMatch *q4;
    PlayerMatch *t4;
    EmailCheckReply *u2;
    UserNicksReply *u3;
    FindPlayersReply *u4;
    GpCheckNewUserResponseArg *u5;
    ReverseBuddiesReply *u7;
    s32 i;
    SuggestNickReply *u9;

    gpState = connection->mGpiConnection;
    data = operation->mData;
    if (operation->mBlocking != 0) {
        loop = TRUE;
    } else {
        loop = FALSE;
    }
    do {
        result =
            GpiSendBuffer(connection, data->mSocket, (GpiBuffer *) &data->mOutputBuffer, &socketGone, 1, gSmString);
        if (result != 0) {
            return result;
        }
        if (operation->mState == 1) {
            result = GpiCheckConnectComplete(connection, data->mSocket, &state);
            if (result != 0) {
                return result;
            }
            if (state == 4) {
                GpiSetError(connection, 0xd01, gSearchManagerConnectErrorString);
                GpiQueueErrorCallback(connection, 4, 0);
                return 4;
            }
            if (state == 3) {
                if (data->mKind == 1) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gSearchKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3670);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mSesskey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b367c);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProfileId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                    if (data->mNick[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3698);
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mNick);
                    }
                    if (data->mUniquenick[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36a0);
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mUniquenick);
                    }
                    if (data->mEmail[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36b0);
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    }
                    if (data->mFirstname[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36b8);
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mFirstname);
                    }
                    if (data->mLastname[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36c4);
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mLastname);
                    }
                    if (data->mIcquin != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36d0);
                        GpiAppendBufferNumber(connection, &data->mOutputBuffer, data->mIcquin);
                    }
                    if (data->mSkip > 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, gSkipKey);
                        GpiAppendBufferNumber(connection, &data->mOutputBuffer, data->mSkip);
                    }
                } else if (data->mKind == 2) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gValidKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                } else if (data->mKind == 3) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gNicksKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gPassKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mPassword);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else if (data->mKind == 4) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gPmatchKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3670);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mSesskey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b367c);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProfileId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3708);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, data->mProductId);
                } else if (data->mKind == 5) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gCheckKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3698);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mNick);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gPassKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mPassword);
                } else if (data->mKind == 6) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b371c);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3698);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mNick);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gPassKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mPassword);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gProductIDKey);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProductId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b36a0);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mUniquenick);
                    if (data->mCdkey[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, gCdkeyKey);
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mCdkey);
                    }
                } else if (data->mKind == 7) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gOthersKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3670);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mSesskey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b367c);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProfileId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else if (data->mKind == 8) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gUniquesearchKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, gPreferrednickKey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mUniquenick);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else {
                    AssertionFailed(data_ov000_021b3768, gGpiSearchFileName, NULL, 0x275);
                }
                GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b376c);
                GpiAppendBufferString(connection, &data->mOutputBuffer, gGsiAcGamename);
                GpiAppendBufferString(connection, &data->mOutputBuffer, data_ov000_021b3778);
                operation->mState = 4;
            }
        } else if (operation->mState == 4) {
            result = GpiReceiveBuffer(connection, data->mSocket, (GpiBuffer *) &data->mInputBuffer, (s32 *) &j,
                                      &socketGone, gSmString);
            if (result != 0) {
                if (result != 3) {
                    return result;
                }
                GpiSetError(connection, 0xd01, data_ov000_021b3780);
                GpiQueueErrorCallback(connection, 3, 0);
                return 3;
            }
            if (strstr(data->mInputBuffer, data_ov000_021b3778) != NULL) {
                n = 0;
                operation->mState = 5;
                if (GpiReadError(connection, data->mInputBuffer, 1) != FALSE) {
                    data->mRemove = TRUE;
                    return 4;
                }
                if (data->mKind == 1) {
                    d = FALSE;
                    e.mUnk_00 = 0;
                    e.mUnk_04 = 0;
                    e.mUnk_0c = NULL;
                    e.mUnk_08 = 0x601;
                    do {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, gBsrdoneKey) == 0) {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, gMoreKey) == 0 && strcmp(value, data_ov000_021b3768) != 0) {
                                e.mUnk_08 = 0x600;
                            }
                            d = TRUE;
                        } else if (strcmp(key, gBsrKey) == 0) {
                            q1 = DWCi_GsRealloc(e.mUnk_0c, ++e.mUnk_04 * 0xac);
                            e.mUnk_0c = q1;
                            if (q1 == NULL) {
                                GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                return 1;
                            }
                            i = e.mUnk_04 - 1;
                            t1 = &q1[i];
                            memset(t1, 0, 0xac);
                            q1[i].mProfile = StrtolBase10(value);
                            f = FALSE;
                            do {
                                g = n;
                                result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                                if (result != 0) {
                                    return result;
                                }
                                if (strcmp(key, gNickResultKey) == 0) {
                                    GpiCopyString(t1->mNick, value, 0x1f);
                                } else if (strcmp(key, gUniquenickResultKey) == 0) {
                                    GpiCopyString(t1->mUniquenick, value, 0x15);
                                } else if (strcmp(key, gSearchFirstnameKey) == 0) {
                                    GpiCopyString(t1->mFirstname, value, 0x1f);
                                } else if (strcmp(key, gSearchLastnameKey) == 0) {
                                    GpiCopyString(t1->mLastname, value, 0x1f);
                                } else if (strcmp(key, gSearchEmailKey) == 0) {
                                    GpiCopyString(t1->mEmail, value, 0x33);
                                } else if (strcmp(key, gBsrKey) == 0 || strcmp(key, gBsrdoneKey) == 0) {
                                    f = TRUE;
                                    n = g;
                                }
                            } while (f == FALSE);
                        } else {
                            GpiSetError(connection, 1, gSearchServerReadErrorString);
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                    } while (d == FALSE);
                    v = e.mUnk_08;
                    c1 = operation->mCallback;
                    if (c1.mCallback != NULL) {
                        c1.mCallback(connection, &e, c1.mParam);
                    }
                    if (v == 0x600 && e.mUnk_08 == 0x600) {
                        result = gpiProfileSearch(
                            connection, data->mNick, data->mUniquenick, data->mEmail, data->mFirstname, data->mLastname,
                            data->mIcquin, e.mUnk_04 + data->mSkip, operation->mBlocking,
                            (u32) operation->mCallback.mCallback, operation->mCallback.mParam);
                        if (result != 0) {
                            return result;
                        }
                    }
                    DWCi_GsFree(e.mUnk_0c);
                    e.mUnk_0c = NULL;
                } else if (data->mKind == 2) {
                    c2 = operation->mCallback;
                    if (c2.mCallback != NULL) {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, gVrKey) != 0) {
                            GpiSetError(connection, 1, gSearchServerReadErrorString);
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        u2 = DWCi_GsMalloc(0x3c);
                        if (u2 == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        u2->mResult = 0;
                        GpiCopyString(u2->mEmail, (const char *) data->mEmail, 0x33);
                        if ((s8) value[0] == 0x30) {
                            u2->mIsValid = FALSE;
                        } else {
                            u2->mIsValid = TRUE;
                        }
                        result = GpiQueueCallback(connection, c2, u2, operation, 0);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == 3) {
                    c3 = operation->mCallback;
                    if (c3.mCallback != NULL) {
                        u3 = DWCi_GsMalloc(0x44);
                        if (u3 == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        u3->mResult = 0;
                        strcpy(u3->mEmail, (const char *) data->mEmail);
                        u3->mNumNicks = 0;
                        u3->mNicks = NULL;
                        u3->mUniquenicks = NULL;
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, gNrKey) != 0) {
                            GpiSetError(connection, 1, gSearchServerReadErrorString);
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        d = FALSE;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, gNickResultKey) == 0) {
                                q = DWCi_GsRealloc(u3->mNicks, (u3->mNumNicks + 1) * 4);
                                if (q == NULL) {
                                    GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                    return 1;
                                }
                                u3->mNicks = (char **) q;
                                q = DWCi_GsMalloc(0x1f);
                                if (q == NULL) {
                                    GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                    return 1;
                                }
                                u3->mNicks[u3->mNumNicks] = q;
                                GpiCopyString(u3->mNicks[u3->mNumNicks], value, 0x1f);
                                u3->mNumNicks++;
                            } else if (strcmp(key, gUniquenickResultKey) == 0) {
                                if (u3->mNumNicks > 0) {
                                    q = DWCi_GsRealloc(u3->mUniquenicks, u3->mNumNicks * 4);
                                    if (q == NULL) {
                                        GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                        return 1;
                                    }
                                    u3->mUniquenicks = (char **) q;
                                    q = DWCi_GsMalloc(0x15);
                                    if (q == NULL) {
                                        GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                        return 1;
                                    }
                                    u3->mUniquenicks[u3->mNumNicks - 1] = q;
                                    GpiCopyString(u3->mUniquenicks[u3->mNumNicks - 1], value, 0x15);
                                }
                            } else if (strcmp(key, gNdoneKey) == 0) {
                                d = TRUE;
                            } else {
                                GpiSetError(connection, 1, gSearchServerReadErrorString);
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        result = GpiQueueCallback(connection, c3, u3, operation, 3);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == 4) {
                    c4 = operation->mCallback;
                    if (c4.mCallback != NULL) {
                        u4 = DWCi_GsMalloc(0x10);
                        if (u4 == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        u4->mProductId = data->mProductId;
                        d = FALSE;
                        u4->mResult = 0;
                        u4->mNumMatches = 0;
                        u4->mMatches = NULL;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, gPsrdoneKey) == 0) {
                                d = TRUE;
                            } else if (strcmp(key, gPsrKey) == 0) {
                                u4->mNumMatches++;
                                u4->mMatches = DWCi_GsRealloc(u4->mMatches, u4->mNumMatches * 0x128);
                                q4 = u4->mMatches;
                                if (q4 == NULL) {
                                    GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                    return 1;
                                }
                                i = u4->mNumMatches - 1;
                                t4 = &q4[i];
                                memset(t4, 0, 0x128);
                                t4->mStatus = 1;
                                q4[i].mProfile = StrtolBase10(value);
                                f = FALSE;
                                do {
                                    g = n;
                                    result =
                                        GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                                    if (result != 0) {
                                        return result;
                                    }
                                    if (strcmp(key, gStatusResultKey) == 0) {
                                        GpiCopyString(t4->mStatusString, value, 0x100);
                                    } else if (strcmp(key, gNickResultKey) == 0) {
                                        GpiCopyString(t4->mNick, value, 0x1f);
                                    }
                                    if (strcmp(key, gStatuscodeKey) == 0) {
                                        t4->mStatus = StrtolBase10(value);
                                    } else if (strcmp(key, gPsrKey) == 0 || strcmp(key, gPsrdoneKey) == 0) {
                                        f = TRUE;
                                        n = g;
                                    }
                                } while (f == FALSE);
                            } else {
                                GpiSetError(connection, 1, gSearchServerReadErrorString);
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        result = GpiQueueCallback(connection, c4, u4, operation, 4);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == 5) {
                    c5 = operation->mCallback;
                    if (c5.mCallback != NULL) {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, gCurKey) != 0) {
                            GpiSetError(connection, 1, gSearchServerReadErrorString);
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        x = StrtolBase10(value);
                        if (x != 0) {
                            gpState->mErrorNumber = x;
                            y = 0;
                        } else {
                            if (GpiGetValue(data->mInputBuffer, data_ov000_021b3850, value, 0x200) == FALSE) {
                                GpiSetError(connection, 1, gSearchServerReadErrorString);
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                            y = StrtolBase10(value);
                        }
                        u5 = DWCi_GsMalloc(8);
                        if (u5 == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        u5->mResult = x;
                        u5->mProfile = y;
                        result = GpiQueueCallback(connection, c5, u5, operation, 0);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == 6) {
                    c6 = operation->mCallback;
                    if (c6.mCallback != NULL) {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, gNurResultKey) != 0) {
                            GpiSetError(connection, 1, gSearchServerReadErrorString);
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        x = StrtolBase10(value);
                        if (x != 0) {
                            gpState->mErrorNumber = x;
                        }
                        if (GpiGetValue(data->mInputBuffer, data_ov000_021b3850, value, 0x200) == FALSE) {
                            if (x == 0) {
                                GpiSetError(connection, 1, gSearchServerReadErrorString);
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                            y = 0;
                        } else {
                            y = StrtolBase10(value);
                        }
                        u5 = DWCi_GsMalloc(8);
                        if (u5 == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        u5->mResult = x;
                        u5->mProfile = y;
                        result = GpiQueueCallback(connection, c6, u5, operation, 0);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == 7) {
                    c7 = operation->mCallback;
                    if (c7.mCallback != NULL) {
                        u7 = DWCi_GsMalloc(0xc);
                        if (u7 == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        u7->mResult = 0;
                        u7->mNumProfiles = 0;
                        u7->mProfiles = NULL;
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, gOthersResultKey) != 0) {
                            GpiSetError(connection, 1, gSearchServerReadErrorString);
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        d = FALSE;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, gOdoneKey) == 0) {
                                d = TRUE;
                            } else if (strcmp(key, gOKey) == 0) {
                                q1 = DWCi_GsRealloc(u7->mProfiles, (u7->mNumProfiles + 1) * 0xac);
                                if (q1 == NULL) {
                                    GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                    return 1;
                                }
                                u7->mProfiles = q1;
                                q1 = u7->mProfiles;
                                i = u7->mNumProfiles;
                                t1 = &q1[i];
                                memset(t1, 0, 0xac);
                                u7->mNumProfiles++;
                                q1[i].mProfile = StrtolBase10(value);
                                f = FALSE;
                                do {
                                    g = n;
                                    result =
                                        GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                                    if (result != 0) {
                                        return result;
                                    }
                                    if (strcmp(key, gNickResultKey) == 0) {
                                        GpiCopyString(t1->mNick, value, 0x1f);
                                    } else if (strcmp(key, gUniquenickResultKey) == 0) {
                                        GpiCopyString(t1->mUniquenick, value, 0x15);
                                    } else if (strcmp(key, gOthersFirstKey) == 0) {
                                        GpiCopyString(t1->mFirstname, value, 0x1f);
                                    } else if (strcmp(key, gOthersLastKey) == 0) {
                                        GpiCopyString(t1->mLastname, value, 0x1f);
                                    } else if (strcmp(key, gSearchEmailKey) == 0) {
                                        GpiCopyString(t1->mEmail, value, 0x33);
                                    } else if (strcmp(key, gOKey) == 0 || strcmp(key, gOdoneKey) == 0) {
                                        f = TRUE;
                                        n = g;
                                    }
                                } while (f == FALSE);
                            } else {
                                GpiSetError(connection, 1, gSearchServerReadErrorString);
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        result = GpiQueueCallback(connection, c7, u7, operation, 8);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == 8) {
                    c8 = operation->mCallback;
                    if (c8.mCallback != NULL) {
                        i = 0;
                        u9 = DWCi_GsMalloc(0xc);
                        if (u9 == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        u9->mResult = 0;
                        u9->mNumSuggestedNicks = 0;
                        u9->mSuggestedNicks = NULL;
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, gUsKey) != 0) {
                            GpiSetError(connection, 1, gSearchServerReadErrorString);
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        u9->mNumSuggestedNicks = StrtolBase10(value);
                        u9->mSuggestedNicks = DWCi_GsMalloc(u9->mNumSuggestedNicks * 4);
                        if (u9->mSuggestedNicks == NULL) {
                            GpiSetErrorMessage(connection, data_ov000_021b35f8);
                            return 1;
                        }
                        d = FALSE;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &n, (s8 *) key, (s8 *) value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, gNickResultKey) == 0) {
                                u9->mSuggestedNicks[i] = DWCi_GsMalloc(0x15);
                                if (u9->mSuggestedNicks[i] == NULL) {
                                    GpiSetErrorMessage(connection, data_ov000_021b35f8);
                                    return 1;
                                }
                                GpiCopyString(u9->mSuggestedNicks[i], value, 0x15);
                                i++;
                            } else if (strcmp(key, gUsdoneKey) == 0) {
                                if (i != u9->mNumSuggestedNicks) {
                                    AssertionFailed(gSuggestedNickCountAssertion, gGpiSearchFileName, NULL, 0x515);
                                }
                                u9->mNumSuggestedNicks = i;
                                d = TRUE;
                            } else {
                                GpiSetError(connection, 1, gSearchServerReadErrorString);
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        result = GpiQueueCallback(connection, c8, u9, operation, 9);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else {
                    AssertionFailed(data_ov000_021b3768, gGpiSearchFileName, NULL, 0x52a);
                }
                data->mRemove = TRUE;
                loop = FALSE;
            }
        }
        if (loop != FALSE) {
            msleep(10);
        }
    } while (loop != FALSE);
    return 0;
}

BOOL GpiUpdateSearches(GpConnection *connection) {
    GpiConnection *gpState;
    GpiOperation **operations;
    GpiOperation *pendingOp;
    GPISearchData *data;
    u32 result;
    s32 count;
    s32 index;

    gpState = connection->mGpiConnection;
    count = 0;
    if (gpState->mSearchCount > 0) {
        operations = DWCi_GsMalloc(gpState->mSearchCount * 4);
        if (operations == NULL) {
            GpiSetErrorMessage(connection, data_ov000_021b35f8);
            return TRUE;
        }
        for (pendingOp = gpState->mOperationList; pendingOp != NULL; pendingOp = pendingOp->mNext) {
            if (pendingOp->mType == 3 && pendingOp->mState != 5 && pendingOp->mData->mProcessing == 0) {
                if (count >= gpState->mSearchCount) {
                    AssertionFailed(gSearchIndexAssertion, gGpiSearchFileName, NULL, 0x563);
                }
                operations[count++] = pendingOp;
                pendingOp->mData->mProcessing = 1;
            }
        }
        for (index = 0; index < count; index++) {
            result = GpiUpdateSearch(connection, operations[index]);
            if (result != 0) {
                operations[index]->mResult = result;
            }
        }
        for (index = 0; index < count; index++) {
            data = operations[index]->mData;
            data->mProcessing = 0;
            if (data->mRemove != 0) {
                GpiRemoveOperation(connection, operations[index]);
            }
        }
        DWCi_GsFree(operations);
    }
    return FALSE;
}
