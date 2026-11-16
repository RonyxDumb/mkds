#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"

typedef struct SegmentProgress SegmentProgress;

void pwex_interpolateXZ(SegmentProgress *segmentProgress, Vec3 *output);
void pwex_interpolateXYZ(SegmentPoints *progressOwner, Vec3 *output);
