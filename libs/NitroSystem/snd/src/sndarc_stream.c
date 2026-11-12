#include "sndarc_stream.h"

#include "code_0200fc8c.h"
#include "code_020172d0.h"
#include "Main/Menu/data_0217d000.h"
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
#include "code_02003be0.h"
#include "code_0200e77c.h"
#include "code_0212f788.h"
#include "Main/Net/data_0217e000.h"
#include "unk_02152000_data.h"

NNSSndStrmThread *sPrepareThread;
NNSFndList sFreeCommandList;
NNSSndStrmThread sStrmThread;
Unk0212c7f0 sStrmPlayer[4];

// Steps the four stream players: start, volume and fade-out.
void NNSi_SndArcStrmMain(void) {
    s32 playerIndex;
    s32 initVolume;
    s32 volume;
    Unk0212c7f0 *player;

    player = sStrmPlayer;
    for (playerIndex = 0; playerIndex < 4; playerIndex++, player++) {
        if (!player->mActiveFlag) {
            continue;
        }
        if (player->mFinishCounter == 0) {
            ForceStopStrm_(player);
            continue;
        }
        if (player->mStartFlag && player->mPrepareFlag != 0) {
            NNS_SndStrmStart(&player->mStream);
            player->mPlayFlag = 1;
            player->mStartFlag = 0;
        }
        if (player->mPlayFlag) {
            NNSi_SndFaderUpdate(&player->mFader);
            initVolume = data_02152ce4[player->mInitVolume];
            volume = data_02152ce4[NNSi_SndFaderGet(&player->mFader) >> 8];
            volume += initVolume;
            if (volume != player->mVolume) {
                NNS_SndStrmSetVolume(&player->mStream, volume);
                player->mVolume = volume;
            }
            if (player->mFadeOutFlag) {
                if (NNSi_SndFaderIsFinished(&player->mFader) != 0) {
                    ForceStopStrm_(player);
                }
            }
        }
    }
}

void FreePlayer(Unk0212c7f0 *player) {
    if (player->mHandle != 0) {
        *player->mHandle = 0;
        player->mHandle = 0;
    }
    player->mActiveFlag = 0;
    player->mStartFlag = 0;
    player->mPlayFlag = 0;
}

// Stops the player with the thread mutexes held.
void ForceStopStrm_(Unk0212c7f0 *player) {
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
void ShutdownPlayer_(Unk0212c7f0 *player) {
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
void FreeChannel(Unk0212c7f0 *player) {
    if (player->mAllocChannelCount == 0) {
        return;
    }
    player->mAllocChannelCount = player->mAllocChannelCount - 1;
    if (player->mAllocChannelCount != 0) {
        return;
    }
    NNS_SndStrmFreeChannel(&player->mStream);
}

void RemoveCommandByPlayer(NNSFndList *commandList, Unk0212c7f0 *player) {
    u32 enabled;
    LoadCommand *command;
    LoadCommand *next;

    enabled = OS_DisableInterrupts();
    command = NNS_FndGetNextListObject(commandList, 0);
    if (command != 0) {
        do {
            next = NNS_FndGetNextListObject(commandList, command);
            if (command->mPlayer == player) {
                NNS_FndRemoveListObject(commandList, command);
                FreeCommandBuffer(command);
            }
            command = next;
        } while (command != 0);
    }
    OS_RestoreInterrupts(enabled);
}

void FreeCommandBuffer(LoadCommand *command) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    NNS_FndAppendListObject(&sFreeCommandList, command);
    OS_RestoreInterrupts(enabled);
}
