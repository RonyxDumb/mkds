#include "Main/Save/ghost_record_file.h"
#include "Main/System/archive_slots.h"
#include "Main/System/backup_net_camera_work.h"

#pragma thumb on

CupRecords *gCupRecords;
BackupBuffers *gBackupBuffers;
ThreadFunctionQueue *gThreadFunctionQueue;
OverlayLoader *gOverlayLoader;
WiFiRaceSync *gWiFiRaceSync;
ParticipantKartMap *gParticipantKartMap;

SlotGhostRecord *LoadGhostRecordFile(const char *path) {
    int result;
    result = ReadWholeFile(path, gBackupBuffers->mSlotGhostRecords[1], (0x00001000u));
    if (result != 0) {
        return gBackupBuffers->mSlotGhostRecords[1];
    }
    return NULL;
}

#pragma thumb off
