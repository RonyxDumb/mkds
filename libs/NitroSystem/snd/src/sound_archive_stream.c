#include "sound_archive_stream.h"

#include "reset_interrupts_halt.h"
#include "linked_list_ops.h"
#include "Main/Menu/menu_screens_work.h"
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
#include "file_archive_access.h"
#include "thread_mutex_types.h"
#include "sound_fader.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "color_mask_tables.h"
#include "sound_wave_channel_volume.h"

NNSSndStrmThread *sPrepareThread;
NNSFndList sFreeCommandList;
NNSSndStrmThread sStrmThread;
NNSSndStrmPlayer sStrmPlayer[4];

// Steps the four stream players: start, volume and fade-out.
void NNSi_SndArcStrmMain(void) {
    s32 playerIndex;
    s32 initVolume;
    s32 mixedLevel;
    NNSSndStrmPlayer *strmSlot;

    strmSlot = sStrmPlayer;
    for (playerIndex = 0; playerIndex < 4; playerIndex++, strmSlot++) {
        if (!strmSlot->mActiveFlag) {
            continue;
        }
        if (strmSlot->mFinishCounter == 0) {
            ForceStopStrm_(strmSlot);
            continue;
        }
        if (strmSlot->mStartFlag && strmSlot->mPrepareFlag != 0) {
            NNS_SndStrmStart(&strmSlot->mStream);
            strmSlot->mPlayFlag = 1;
            strmSlot->mStartFlag = 0;
        }
        if (strmSlot->mPlayFlag) {
            NNSi_SndFaderUpdate(&strmSlot->mFader);
            initVolume = gVolumeDecibelTable[strmSlot->mInitVolume];
            mixedLevel = gVolumeDecibelTable[NNSi_SndFaderGet(&strmSlot->mFader) >> 8];
            mixedLevel += initVolume;
            if (mixedLevel != strmSlot->mVolume) {
                NNS_SndStrmSetVolume(&strmSlot->mStream, mixedLevel);
                strmSlot->mVolume = mixedLevel;
            }
            if (strmSlot->mFadeOutFlag) {
                if (NNSi_SndFaderIsFinished(&strmSlot->mFader) != 0) {
                    ForceStopStrm_(strmSlot);
                }
            }
        }
    }
}

void FreePlayer(NNSSndStrmPlayer *player) {
    if (player->mHandle != 0) {
        *player->mHandle = 0;
        player->mHandle = 0;
    }
    player->mActiveFlag = 0;
    player->mStartFlag = 0;
    player->mPlayFlag = 0;
}

// Stops the player with the thread mutexes held.
void ForceStopStrm_(NNSSndStrmPlayer *player) {
    OS_LockMutex(&sStrmThread.mMutex);
    if (sPrepareThread != 0) {
        OS_LockMutex(&sPrepareThread->mMutex);
    }
    if (player->mPlayFlag) {
        NNS_SndStrmStop(&player->mStream);
    }
    if (player->mActiveFlag) {
        FS_CancelFile(&player->mFile);
    }
    ShutdownPlayer_(player);
    OS_UnlockMutex(&sStrmThread.mMutex);
    if (sPrepareThread != 0) {
        OS_UnlockMutex(&sPrepareThread->mMutex);
    }
}

// Frees the channels and file and drops the player's load commands.
void ShutdownPlayer_(NNSSndStrmPlayer *player) {
    if (!player->mActiveFlag) {
        return;
    }
    FreeChannel(player);
    FS_CloseFile(&player->mFile);
    RemoveCommandByPlayer(&sStrmThread.mCommandList, player);
    if (sPrepareThread != 0) {
        RemoveCommandByPlayer(&sPrepareThread->mCommandList, player);
    }
    FreePlayer(player);
}

// Frees the stream channel when the count reaches 0.
void FreeChannel(NNSSndStrmPlayer *player) {
    if (player->mAllocChannelCount == 0) {
        return;
    }
    player->mAllocChannelCount = player->mAllocChannelCount - 1;
    if (player->mAllocChannelCount != 0) {
        return;
    }
    NNS_SndStrmFreeChannel(&player->mStream);
}

void RemoveCommandByPlayer(NNSFndList *commandList, NNSSndStrmPlayer *player) {
    u32 enabled;
    LoadCommand *request;
    LoadCommand *next;

    enabled = OS_DisableInterrupts();
    request = NNS_FndGetNextListObject(commandList, 0);
    if (request != 0) {
        do {
            next = NNS_FndGetNextListObject(commandList, request);
            if (request->mPlayer == player) {
                NNS_FndRemoveListObject(commandList, request);
                FreeCommandBuffer(request);
            }
            request = next;
        } while (request != 0);
    }
    OS_RestoreInterrupts(enabled);
}

void FreeCommandBuffer(LoadCommand *command) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    NNS_FndAppendListObject(&sFreeCommandList, command);
    OS_RestoreInterrupts(enabled);
}
