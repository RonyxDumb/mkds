#pragma once

#include "types.h"

typedef struct EmblemRecord EmblemRecord;

typedef struct GrandPrixRecordBlock GrandPrixRecordBlock;

typedef struct MissionRecordBlock MissionRecordBlock;

typedef struct CourseTimeRecordBlock CourseTimeRecordBlock;

void ReadSaveDataSection_MissionRun_from_thumb(void *block);
void WriteSaveDataSection_MissionRun_from_thumb(MissionRecordBlock *block);
void ReadSaveDataSection_TimeTrial_from_thumb(void *block);
void WriteSaveDataSection_TimeTrials_from_thumb(CourseTimeRecordBlock *block);
void ReadSaveDataSection_GrandPrix_from_thumb(void *block);
void WriteSaveDataSection_GrandPrix_from_thumb(GrandPrixRecordBlock *block);
void ReadSaveDataSection_Emblem_from_thumb(void *block);
void WriteSaveDataSection_Emblem_from_thumb(EmblemRecord *block);
void ReadSaveDataSection_Header_from_thumb(void *block);
