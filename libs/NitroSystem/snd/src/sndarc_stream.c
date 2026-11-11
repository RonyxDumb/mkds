#include "sndarc_stream.h"

#include "code_0200fc8c.h"
#include "code_020172d0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02003be0.h"
#include "code_0200e77c.h"
#include "code_0212f788.h"
#include "stream.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/unk_0217e000.h"
#include "Main/Unknown/unk_02152000.h"

// Steps the four stream players: start, volume and fade-out.
void NNSi_SndArcStrmMain(void) {
    s32 playerIndex;
    s32 initVolume;
    s32 volume;
    Unk0212c7f0 *player;

    player = data_0217e404;
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
    OS_LockMutex(&data_0217e3e0);
    if (data_0217df04 != 0) {
        OS_LockMutex(&data_0217df04->mMutex);
    }
    if (player->mPlayFlag) {
        NNS_SndStrmStop(&player->mStream);
    }
    if (player->mActiveFlag) {
        FS_CancelFile(&player->mFile);
    }
    ShutdownPlayer_(player);
    OS_UnlockMutex(&data_0217e3e0);
    if (data_0217df04 != 0) {
        OS_UnlockMutex(&data_0217df04->mMutex);
    }
}

// Frees the channels and file and drops the player's load commands.
void ShutdownPlayer_(Unk0212c7f0 *player) {
    if (!player->mActiveFlag) {
        return;
    }
    FreeChannel(player);
    FS_CloseFile(&player->mFile);
    RemoveCommandByPlayer(&data_0217e3f8, player);
    if (data_0217df04 != 0) {
        RemoveCommandByPlayer(&data_0217df04->mCommandList, player);
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
    NNS_FndAppendListObject(&data_0217df08, command);
    OS_RestoreInterrupts(enabled);
}
