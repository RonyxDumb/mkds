#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217a000.h"

typedef struct SlotGhostRecord SlotGhostRecord;

SlotGhostRecord *LoadGhostRecordFile(const char *path);

extern struct CupRecords *gCupRecords;
extern struct BackupBuffers *gBackupBuffers;
extern struct ThreadFunctionQueue *gThreadFunctionQueue;
extern struct OverlayLoader *gOverlayLoader;
extern struct WiFiRaceSync *gWiFiRaceSync;
extern struct ParticipantKartMap *gParticipantKartMap;
