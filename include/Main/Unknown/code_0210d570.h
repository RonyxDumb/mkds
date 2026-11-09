#pragma once

#include "types.h"

typedef struct ScenePlayers ScenePlayers;

void ReleaseScenePlayers(ScenePlayers *scenePlayers, s32 unused);

unsigned int ScenePlayersReturnArgument(ScenePlayers *scenePlayers);
