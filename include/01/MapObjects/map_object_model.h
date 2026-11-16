#pragma once

#include "types.h"
#include "Main/MapObjects/pendulum.h" // NsbmdModel
#include "Main/MapObjects/woodbox.h" // Nsbmd
#include "Main/Graphics/model_animation.h" // ModelAnimation
#include "Main/Kart/shadow_model.h" // ShadowModel

// The model bundle a map object kind or a mission run map object loads: its scale, models and animations.
typedef struct MapObjectModel {
    // mScale: three words, 0x1000 each from the creators; DrawMapObjectModel and DrawMapObjectModelWithPos send them as
    // command 0x1b, and
    // SetMapObjectModelMirror sets x and y to -0x1000 or 0x1000.
    /* 00 */ Vec3 mScale;
    // NsbmdModel made by CreateMapObjectModelNsbmd, or with an .nsbtp by CreateMapObjectModelNsbmdNsbtp; the other
    // creators leave it unset and the draws test it for NULL.
    /* 0c */ NsbmdModel *mNsbmdModel;
    // The Nsbmd model made by CreateMapObjectModelAnimated or LoadMapObjectModelAnimated; the animation objects attach
    // to it. A bundle may attach none (NsKiller1, Berry, Cream).
    /* 10 */ Nsbmd *mAnimatedModel;
    // A ShadowModel (the type the kart, killer item and jg shadows use) made from a shadow .nsbmd by
    // CreateMapObjectModelShadow or LoadMapObjectModelShadow; MissionRunMapObject.mShadowNsbmd points at a bundle that
    // holds one.
    /* 14 */ ShadowModel *mShadowModel;
    // The .nsbmd file as FindCourseMapObjFile returned it (a pointer into the archive), or as LoadMissionRunFile read
    // it in overlay 1; used by the animation creators; set only by the Animated creators.
    /* 18 */ void *mNsbmdFile;
    // Animations by slot: 0 .nsbca, 1 .nsbtp, 2 .nsbma, 3 .nsbta; filled by the Create..., Load... and Init...Animation
    // functions (slot 2 only by LoadMapObjectModelNsbmaAnimation in overlay 1).
    /* 1c */ ModelAnimation *mAnimations[4];
} MapObjectModel;

