#pragma once

#include "types.h"

typedef struct SoundModeHolder SoundModeHolder;

void RestoreSavedSoundMode(SoundModeHolder *modeHolder);

typedef struct ScenePlayers ScenePlayers;

void SetupSoundMode(SoundModeHolder *modeHolder, ScenePlayers *scenePlayers, unsigned int p2);
