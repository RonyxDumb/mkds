#include "Main/Save/ghost_record_file.h"
#include "Main/System/archive_slots.h"
#include "Main/MapObjects/data_0217a000.h"

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
