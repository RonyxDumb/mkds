#pragma once

#include "types.h"

typedef struct EmblemRecord EmblemRecord;

typedef struct GrandPrixRecordBlock GrandPrixRecordBlock;

typedef struct MissionRecordBlock MissionRecordBlock;

typedef struct CourseTimeRecordBlock CourseTimeRecordBlock;

void savd_readNkmr(void *block);
void savd_writeNkmr(MissionRecordBlock *block);
void savd_readNkta(void *block);
void savd_writeNkta(CourseTimeRecordBlock *block);
void savd_readNkgp(void *block);
void savd_writeNkgp(GrandPrixRecordBlock *block);
void savd_readNkem(void *block);
void savd_writeNkem(EmblemRecord *block);
void savd_readNksy(void *block);
