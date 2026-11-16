#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

struct GPConnection;

// Values of WiFiBuddySync.mState: no update is running, the buddy update is running, it has finished.
enum {
    BUDDY_SYNC_STATE_NONE,
    BUDDY_SYNC_STATE_UPDATING,
    BUDDY_SYNC_STATE_FINISHED,
};

// Values of WiFiBuddySync.mBuddyUpdateState: the list step starts, then goes through the entries, waits for a profile
// search reply, and is done when every entry has been passed.
enum {
    BUDDY_UPDATE_STATE_START,
    BUDDY_UPDATE_STATE_SYNC_ENTRIES,
    BUDDY_UPDATE_STATE_WAIT_PROFILE_SEARCH,
    BUDDY_UPDATE_STATE_DONE,
};

// Buddy layer of the online connection: it makes the GP buddy list and the saved list (mBuddies) agree and reports the
// end through mResultCallback (mBuddiesChanged says the list must be saved).
typedef void (*DWCBuddyFriendCallback)(s32 index, void *arg);

typedef struct WiFiBuddySync {
    // Values BUDDY_SYNC_STATE_*: set by DWCi_FriendInit and CloseStatsAndResetBuddySync (NONE), StartBuddySync
    // (UPDATING) and DWCi_EndUpdateServers (FINISHED); only compared elsewhere.
    // CloseStatsAndResetBuddySync (NONE); only compared elsewhere.
    /* 00 */ s32 mState;
    /* 04 */ struct GPConnection *mGpConnection;
    // gpProcess calls since the last restart (DWCi_InitGPProcessCount, at login success); the list part starts after
    // more than 7.
    /* 08 */ u32 mPollCount;
    // OS_GetTick reading at the last gpProcess (also set by DWCi_InitGPProcessCount); the next gpProcess is allowed
    // once 300 ms have passed.
    /* 0c */ u64 mLastPollTime;
    // Capacity of the list at mBuddies (0x3c entries), not the number of entries in use (DWC_GetNumFriend counts
    // those).
    /* 14 */ s32 mBuddyEntryCount;
    // The saved list (WiFiSession.mBuddies, 12-byte entries), mBuddyEntryCount long.
    /* 18 */ DWCAccFriendData *mBuddies;
    // Entry of the list the sync step is on; advanced by the step loop and by the profile-search reply
    // (DWCi_GPProfileSearchCallback).
    /* 1c */ u8 mSyncIndex;
    // 1 when the sync rewrote or merged an entry; given to the result callback, whose receiver
    // WiFiSessionBuddySyncCallback sets WiFiSession.mBuddiesChanged from it on result 0, so the list is saved. Set
    // early in
    // DWCi_GPProfileSearchCallback, so it can be 1 without a change.
    /* 1d */ u8 mBuddiesChanged;
    /* 1e */ u8 mBuddyUpdateState;
    // Parts of the sync that ended; at 2 DWCi_FriendProcess calls DWCi_EndUpdateServers (the finish step). Part 1 is
    // the name part (only run when a name was given: the one caller passes NULL, so it is counted at once); part 2 is
    // the list part.
    /* 1f */ u8 mCompletedParts;
    // Stats-server requests in flight (++ for each request sent, -- in its reply); an error when it would wrap or fall
    // below 0, and while it is nonzero when PersistThink returns FALSE (DWCi_FriendProcess). Only used when a name was
    // given to StartBuddySync (the one caller passes NULL).
    /* 20 */ u32 mPendingStatsRequestCount;
    /* 24 */ s32 mProfileId;
    /* 28 */ char *mPlayerName;
    // Set by StartBuddySync (DWC_UpdateServersAsync passes DWCi_UpdateServersCallback); called with (code,
    // mBuddiesChanged, arg) by DWCi_EndUpdateServers (code 0) and, only while the sync is running (mState
    // BUDDY_SYNC_STATE_UPDATING), by DWCi_StopFriendProcess (the error).
    /* 2c */ void (*mResultCallback)(s32, u8, void *);
    /* 30 */ void *mResultCallbackArg;
    // Called with (list index, status, location string, arg) from DWCi_GPRecvBuddyStatusCallback and from
    // DWCi_CallBuddyFriendCallback.
    /* 34 */ void (*mBuddyStatusCallback)(s32, u8, void *, void *);
    /* 38 */ void *mBuddyStatusCallbackArg;
    // Set by StartBuddySync (seventh parameter; the owner passes WiFiSessionEntryMergedCallback). Called by
    // DWCi_DeleteFriendFromList with (index of the entry cleared, index of the entry kept, arg) when two entries of the
    // saved list hold the same profile id.
    /* 3c */ void (*mEntryMergedCallback)(s32, s32, void *);
    /* 40 */ void *mEntryMergedCallbackArg;
    // Set by DWC_SetBuddyFriendCallback. Called by DWCi_CallBuddyFriendCallback with (list index, arg) after a GP reply
    // set an entry's profile id, except while mState is BUDDY_SYNC_STATE_UPDATING. The one caller passes
    // BuddyChangedCallback.
    /* 44 */ DWCBuddyFriendCallback mBuddyChangedCallback;
    /* 48 */ void *mBuddyChangedCallbackArg;
    /* 4c */ void (*mSaveCallback)(s32 success, s32 isPublicData, u32 instance);
    /* 50 */ u32 mUnk_50;
} WiFiBuddySync;

// Set by DWCi_FriendInit to the buddy object inside the connection; NULL again after DWCi_ShutdownFriend.
extern WiFiBuddySync *gWiFiBuddySync;

void DWC_SetBuddyFriendCallback(DWCBuddyFriendCallback callback, void *param);
