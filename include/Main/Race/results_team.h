#pragma once

#include "types.h"

// Results of GetResultSceneSeqKind: the cup rank in a grand prix, then the outcome of a race against others alone or in
// teams. GetResultSceneSeqId picks the same sequence for the won, lost and draw outcomes of both.
#define RESULT_SCENE_SEQ_KIND_GP_TROPHY 0
#define RESULT_SCENE_SEQ_KIND_GP_NO_TROPHY 1
#define RESULT_SCENE_SEQ_KIND_WON 2
#define RESULT_SCENE_SEQ_KIND_LOST 3
#define RESULT_SCENE_SEQ_KIND_DRAW 4
#define RESULT_SCENE_SEQ_KIND_TEAM_WON 5
#define RESULT_SCENE_SEQ_KIND_TEAM_LOST 6
#define RESULT_SCENE_SEQ_KIND_TEAM_DRAW 7

u32 GetResultSceneSeqKind(void);
