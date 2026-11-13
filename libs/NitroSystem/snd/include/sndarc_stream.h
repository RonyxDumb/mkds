#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "code_0200e77c.h"

// Element of a command list (links at 0): the stream player the command belongs to.
typedef struct LoadCommand {
    /* 00 */ u8 mLink[8];
    /* 08 */ void *mPlayer;
} LoadCommand;

// Stream thread: its mutex and the list of load commands.
typedef struct NNSSndStrmThread {
    /* 000 */ u8 mThread[0x4cc];
    /* 4cc */ OSMutex mMutex;
    /* 4e4 */ NNSFndList mCommandList;
} NNSSndStrmThread;

#include "stream.h" // NNSSndStrmPlayer

void FreeCommandBuffer(LoadCommand *command);
void RemoveCommandByPlayer(NNSFndList *commandList, NNSSndStrmPlayer *player);
void FreeChannel(NNSSndStrmPlayer *player);
void ShutdownPlayer_(NNSSndStrmPlayer *player);
void ForceStopStrm_(NNSSndStrmPlayer *player);
void FreePlayer(NNSSndStrmPlayer *player);
void NNSi_SndArcStrmMain(void);
