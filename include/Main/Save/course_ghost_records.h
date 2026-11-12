#pragma once

#include "types.h"

void StartReadCourseGhostRecords(void *records);
void ReadCourseGhostRecords(void);

typedef struct GhostRecordHead GhostRecordHead;

GhostRecordHead *CreateCourseGhostRecords(void *heap);
