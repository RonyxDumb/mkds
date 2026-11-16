#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

void InitModelAnimationWithEntries(u32 animationKind, void *model, void *animation, void *nsbmdFile,
                                   void *animationFile);

extern const Vec3 gJgMatrixRow1Source;
extern const MapObjectKindDescriptor gWoodbox1KindDescriptor;
