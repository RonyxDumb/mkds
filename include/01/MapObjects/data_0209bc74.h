#pragma once

#include "types.h"
#include "Main/MapObjects/pendulum.h" // NsbmdModel
#include "Main/MapObjects/woodbox.h" // Nsbmd
#include "Main/Graphics/model_animation.h" // ModelAnimation
#include "Main/Kart/shadow_model.h" // ShadowModel

// The model bundle of one map object kind: one per kind (the global g<Stem> that Create<Stem> stores), shared by every
// object of the kind; 0x2c bytes, the allocation size. A creator builds exactly one of mNsbmdModel / mAnimatedModel /
// mShadowModel and leaves the others 0; the draw tests each.
typedef struct MapObjectModel {
    // Three words (1.0 = 0x1000 each) set by the creators and sent to the geometry engine as the scale command (0x1b)
    // by both draw functions; afterwards only the mirror setter writes them (it flips the sign of x and y).
    /* 00 */ Vec3 mScale;
    // NsbmdModel built from an .nsbmd (and an optional .nsbtp) by CreateMapObjectModelNsbmd / NsbmdNsbtp; 0 in the
    // other bundles. The other models are built from an .nsbmd too.
    /* 0c */ NsbmdModel *mNsbmdModel;
    // The 0x6c model instance of CreateMapObjectModelAnimated; the animation objects attach to this model. A bundle
    // made this way may attach none (NsKiller1, Berry, Cream).
    /* 10 */ Nsbmd *mAnimatedModel;
    // The 0x74 shadow model object (the type the kart, killer item and jg shadows use) built from an .nsbmd shadow file
    // by CreateMapObjectModelShadow; MissionRunMapObject.mShadowNsbmd points at a bundle that holds one.
    /* 14 */ ShadowModel *mShadowModel;
    // The .nsbmd file as FindCourseMapObjFile returned it (pointer into the archive), used by the animation creators;
    // 0 unless the Animated creator ran (overlay 1: the file LoadMissionRunFile read).
    /* 18 */ void *mNsbmdFile;
    // Slot table of the 0x38-byte animation objects: 0 .nsbca, 1 .nsbtp, 2 .nsbma, 3 .nsbta; filled by the
    // Create...Animation functions (slot 2 only by overlay 1, never in a main-code bundle).
    /* 1c */ ModelAnimation *mAnimations[4];
} MapObjectModel;

