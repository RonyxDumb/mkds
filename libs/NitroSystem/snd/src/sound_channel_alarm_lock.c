#include "sound_channel_alarm_lock.h"

#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "sound_command_requests.h"

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
    BIT_CLEAR(sAlarmLock, alarm);
}

// Clears the channel, capture and alarm locks.
void NNSi_SndInitResourceMgr(void) {
    sChannelLock = 0;
    sCaptureLock = 0;
    sAlarmLock = 0;
}
