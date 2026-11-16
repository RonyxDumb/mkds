#include "Main/Race/results_gp_frame_limit.h"

s32 GetResultsGpFrameLimit(s32 cupRankIndex) {
    return cupRankIndex < 3 ? 0xb4 : 0x78;
}
