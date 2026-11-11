#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

struct GpConnection;

// Buddy layer of the online link, embedded in WiFiConnection at 0x2e8 (gWiFiBuddySync). Given the GP connection and
// the saved list (mBuddies, mBuddyEntryCount entries of 12 bytes), it makes the GP buddy list and the saved list
// agree: GP buddies the list lacks are deleted, list entries GP lacks are added (DWCi_GPSendBuddyRequest), entries that
// hold only a name are looked up by a GP profile search, entries with the same profile id are merged; when a name is
// given it also talks to the stats server first. The end is reported through mResultCallback (mBuddiesChanged: the list
// was rewritten and must be saved). DWCi_FriendProcess also pumps GpUpdate every 300 ms in connection states 3 to 6,
// and the object answers the GP buddy request and buddy status callbacks.
typedef struct WiFiBuddySync {
    // 0 idle, 1 running, 2 finished; only compared (the per-frame step does not switch on it). mUnk_1e (0..3) is the
    // phase inside state 1 and stays address-based.
    /* 00 */ s32 mState;
    /* 04 */ struct GpConnection *mGpConnection;
    // GpUpdate calls since the last restart (DWCi_InitGPProcessCount, at login success); the list part starts after
    // more than 7.
    /* 08 */ u32 mPollCount;
    // OS_GetTick reading at the last GpUpdate; the next one is allowed after 300 ms.
    /* 0c */ u64 mLastPollTime;
    // Capacity of the list at mBuddies (0x3c entries), not the number of entries in use (DWC_GetNumFriend counts
    // those).
    /* 14 */ s32 mBuddyEntryCount;
    // The saved list (WiFiSession.mBuddies, 12-byte entries), mBuddyEntryCount long.
    /* 18 */ DWCAccFriendData *mBuddies;
    // Entry of the list the sync step is on; advanced by the step loop and by the profile-search reply
    // (DWCi_GPProfileSearchCallback).
    /* 1c */ u8 mSyncIndex;
    // 1 when the sync rewrote or merged an entry; given to the result callback, whose receiver sets
    // WiFiSession.mUnk_1cfc so the list is saved (code_0211f6cc.c). Set early in the reply handler
    // DWCi_GPProfileSearchCallback, so it can be 1 without a change.
    /* 1d */ u8 mBuddiesChanged;
    /* 1e */ u8 mBuddyUpdateState;
    // Parts of the sync that ended; at 2 DWCi_FriendProcess calls DWCi_EndUpdateServers (the finish step). Part 1 is
    // the name part (only run when a name was given: the one caller passes NULL, so it is counted at once); part 2 is
    // the list part.
    /* 1f */ u8 mCompletedParts;
    // Stats-server requests in flight (++ before a request, -- in its reply); an error when it would wrap or while it
    // is nonzero and the stats link is gone (DWCi_FriendProcess). Only live when a name was given to StartBuddySync
    // (the one caller passes NULL).
    /* 20 */ u32 mPendingStatsRequestCount;
    /* 24 */ s32 mProfileId;
    /* 28 */ char *mPlayerName;
    // Set by StartBuddySync (the owner passes DWCi_UpdateServersCallback); called with (code, mBuddiesChanged, arg) by
    // the finish step DWCi_EndUpdateServers (code 0) and the error reporter DWCi_StopFriendProcess (error).
    /* 2c */ void (*mResultCallback)(s32, u8, void *);
    /* 30 */ void *mResultCallbackArg;
    // Called with (list index, status, status text, arg) from DWCi_GPRecvBuddyStatusCallback and from the change
    // notifier DWCi_CallBuddyFriendCallback.
    /* 34 */ void (*mBuddyStatusCallback)(s32, u8, void *, void *);
    /* 38 */ void *mBuddyStatusCallbackArg;
    // Set by StartBuddySync (seventh parameter; the owner passes WiFiSessionEntryMergedCallback). Called by
    // DWCi_DeleteFriendFromList with (index of the entry cleared, index of the entry kept, arg) when two entries of the
    // saved list hold the same profile id.
    /* 3c */ void (*mEntryMergedCallback)(s32, s32, void *);
    /* 40 */ void *mEntryMergedCallbackArg;
    // Set by DWC_SetBuddyFriendCallback (declared void *, called as void (*)(s32, void *)). Called by
    // DWCi_CallBuddyFriendCallback with (list index, arg) after a GP reply set an entry's profile id, unless a sync is
    // running (mState 1). The one caller passes BuddyChangedCallback.
    /* 44 */ void *mBuddyChangedCallback;
    /* 48 */ void *mBuddyChangedCallbackArg;
    /* 4c */ void (*mSaveCallback)(s32 a, s32 b, u32 c);
    /* 50 */ u32 mUnk_50;
} WiFiBuddySync;

// Written by DWCi_FriendInit and cleared by DWCi_ShutdownFriend, the release half.
extern WiFiBuddySync *gWiFiBuddySync;

void DWC_SetBuddyFriendCallback(void *callback, void *param);
