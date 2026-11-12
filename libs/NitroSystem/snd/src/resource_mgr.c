#include "resource_mgr.h"

#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "snd_interface.h"

u32 sChannelLock;
u32 sCaptureLock;
u32 sAlarmLock;

// Locks the channels in channels unless one of them is already locked.
BOOL NNS_SndLockChannel(u32 channels) {
    if (channels == 0) {
        return 1;
    }
    if (channels & sChannelLock) {
        return 0;
    }
    SND_LockChannel(channels, 0);
    sChannelLock |= channels;
    return 1;
}

// Unlocks the channels in channels.
void NNS_SndUnlockChannel(u32 channels) {
    if (channels == 0) {
        return;
    }
    SND_UnlockChannel(channels, 0);
    sChannelLock &= ~channels;
}

// Locks the capture units in captures unless one of them is already locked.
BOOL NNS_SndLockCapture(u32 captures) {
    if (captures & sCaptureLock) {
        return 0;
    }
    sCaptureLock |= captures;
    return 1;
}

// Unlocks the capture units in captures.
void NNS_SndUnlockCapture(u32 captures) {
    sCaptureLock &= ~captures;
}

// Returns the number of the first free alarm and marks it used, or -1 when all eight are used.
s32 NNS_SndAllocAlarm(void) {
    s32 alarm;
    u32 bit;

    bit = 1;
    for (alarm = 0; alarm < 8; alarm++) {
        if ((sAlarmLock & bit) == 0) {
            sAlarmLock |= bit;
            return alarm;
        }
        bit <<= 1;
    }
    return -1;
}

// Marks alarm number alarm free.
void NNS_SndFreeAlarm(s32 alarm) {
    sAlarmLock &= ~(1 << alarm);
}

// Clears the channel, capture and alarm locks.
void NNSi_SndInitResourceMgr(void) {
    sChannelLock = 0;
    sCaptureLock = 0;
    sAlarmLock = 0;
}
