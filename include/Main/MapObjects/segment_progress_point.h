#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"

typedef struct SegmentProgress SegmentProgress;

void GetSegmentProgressPointXz(SegmentProgress *segmentProgress, Vec3 *output);
void GetSegmentProgressPoint(SegmentProgress *segmentProgress, Vec3 *output);
