#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h"

typedef struct SlotGhostRecord SlotGhostRecord;

SlotGhostRecord *GetReadStaffGhost_from_thumb(const char *path);

extern struct CupRecords *g_GlobalLU;
extern struct BackupBuffers *g_SaveDataHolder;
extern struct ThreadFunctionQueue *g_WorkerContext;
extern struct OverlayLoader *g_OverlayManager;
extern struct WiFiRaceSync *g_GlobalAA;
extern struct ParticipantKartMap *g_GlobalRE;
