#pragma once

#include "types.h"
#include "Main/Race/data_020f36d8.h"

typedef struct SegmentProgress SegmentProgress;

void GetSegmentProgressPointXz(SegmentProgress *segmentProgress, Vec3 *output);
void GetSegmentProgressPoint(SegmentProgress *segmentProgress, Vec3 *output);
