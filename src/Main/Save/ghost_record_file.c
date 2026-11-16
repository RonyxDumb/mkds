#include "Main/Save/ghost_record_file.h"
#include "Main/System/archive_slots.h"
#include "Main/System/backup_net_camera_work.h"

#pragma thumb on

CupRecords *g_GlobalLU;
BackupBuffers *g_SaveDataHolder;
ThreadFunctionQueue *g_WorkerContext;
OverlayLoader *g_OverlayManager;
WiFiRaceSync *g_GlobalAA;
ParticipantKartMap *g_GlobalRE;

SlotGhostRecord *GetReadStaffGhost_from_thumb(const char *path) {
    int result;
    result = OpenReadEntireFileBuffer_from_thumb(path, g_SaveDataHolder->mSlotGhostRecords[1], (0x00001000u));
    if (result != 0) {
        return g_SaveDataHolder->mSlotGhostRecords[1];
    }
    return NULL;
}

#pragma thumb off
