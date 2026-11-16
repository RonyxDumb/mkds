#include "Main/MapObjects/picture.h"
#include "Main/MapObjects/picture_puddle.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "Main/MapObjects/picture_init.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"
#include "Main/System/init_after_startup.h"

MapObjectModel *gPicture1;
MapObjectModel *gPicture2;

MapObjectKindDescriptor gPicture1KindDescriptor = {0,
                                             {0, 0},
                                             0xb0,
                                             InitPicture1,
                                             CreateEmptyMapObjectKindData,
                                             CreatePictureDrawList,
                                             0,
                                             0,
                                             CreatePictureUpdateList};
MapObjectKindDescriptor gPicture2KindDescriptor = {0,
                                             {0, 0},
                                             0xb0,
                                             InitPicture2,
                                             CreateEmptyMapObjectKindData,
                                             CreatePictureDrawList,
                                             0,
                                             0,
                                             CreatePictureUpdateList};

void CreatePicture1AndPicture2(void *mapObjectList) {
    gPicture1 = CreateMapObjectFromModel_from_thumb(mapObjectList, "picture1.nsbmd");
    StructMapObject_AddAnimationNsbca_from_thumb(gPicture1, "picture1.nsbca");
    gPicture2 = CreateMapObjectFromModel_from_thumb(mapObjectList, "picture2.nsbmd");
    StructMapObject_AddAnimationNsbca_from_thumb(gPicture2, "picture2.nsbca");
    StructMapObject_MaybeSetPolygonId(gPicture1, 0x3f);
    StructMapObject_MaybeSetPolygonId(gPicture2, 0x3f);
}

void DrawPicture(void *mapObjectList, Picture *picture) {
    s32 commandParam;

    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    picture->mMapObject.mMatrix.mRows[3].x = picture->mMapObject.mPos.x >> 4;
    picture->mMapObject.mMatrix.mRows[3].y = picture->mMapObject.mPos.y >> 4;
    picture->mMapObject.mMatrix.mRows[3].z = picture->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &picture->mMapObject.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &picture->mMapObject.mScale, 3);
    switch (picture->mPictureIndex) {
        case 0:
            StructMapObject_MaybeSetNsbcaFrame(gPicture1, picture->mNsbcaFrameIndex);
            DrawMapObjectModel(mapObjectList, gPicture1, picture);
            break;
        case 1:
            StructMapObject_MaybeSetNsbcaFrame(gPicture2, picture->mNsbcaFrameIndex);
            DrawMapObjectModel(mapObjectList, gPicture2, picture);
            break;
    }
}

// mState stays IDLE: nothing in the code sets WAIT.
void UpdatePicture(void *mapObjectList, Picture *picture) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    SoundStartParams thirdSoundParams;
    SoundStartParams fourthSoundParams;
    RandomState64 *randomState64;
    s32 nextFrameIndex;
    s32 falloffIndex;

    switch (picture->mState) {
        case PICTURE_STATE_WAIT:
            if (picture->mWaitFrames-- <= 0) {
                picture->mState = PICTURE_STATE_PLAY;
            }
            break;
        case PICTURE_STATE_PLAY:
            if (picture->mPictureIndex == 0) {
                nextFrameIndex = picture->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= StructMapObject_GetAnimationBCAFrameCount(gPicture1)) {
                    nextFrameIndex = 0;
                }
                picture->mNsbcaFrameIndex = nextFrameIndex;
                if (picture->mNsbcaFrameIndex == 0 || picture->mNsbcaFrameIndex == 0xf ||
                    picture->mNsbcaFrameIndex == 0x1f || picture->mNsbcaFrameIndex == 0x37 ||
                    picture->mNsbcaFrameIndex == 0x51) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        firstSoundParams.mSoundId = PICTURE_MAIN_FRAMES_SOUND_ID;
                        firstSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        firstSoundParams.mFalloffIndex = falloffIndex;
                        firstSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&firstSoundParams);
                    }
                } else if (picture->mNsbcaFrameIndex == 8 || picture->mNsbcaFrameIndex == 0x14 ||
                           picture->mNsbcaFrameIndex == 0x2c || picture->mNsbcaFrameIndex == 0x44) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        secondSoundParams.mSoundId = PICTURE_SIDE_FRAMES_SOUND_ID;
                        secondSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        secondSoundParams.mFalloffIndex = falloffIndex;
                        secondSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&secondSoundParams);
                    }
                } else if (picture->mNsbcaFrameIndex == 0x78) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        thirdSoundParams.mSoundId = PICTURE_LAST_FRAME_SOUND_ID;
                        thirdSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        thirdSoundParams.mFalloffIndex = falloffIndex;
                        thirdSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&thirdSoundParams);
                    }
                }
            } else if (picture->mPictureIndex == 1) {
                nextFrameIndex = picture->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= StructMapObject_GetAnimationBCAFrameCount(gPicture2)) {
                    nextFrameIndex = 0;
                }
                picture->mNsbcaFrameIndex = nextFrameIndex;
                if (picture->mNsbcaFrameIndex == 0) {
                    if (IsMapObjectOutOfRange(&picture->mMapObject) == FALSE) {
                        if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                            falloffIndex = 2;
                        } else if (picture->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                        fourthSoundParams.mSoundId = PICTURE_SECOND_PICTURE_SOUND_ID;
                        fourthSoundParams.mPositionSource = &picture->mMapObject.mPos;
                        fourthSoundParams.mFalloffIndex = falloffIndex;
                        fourthSoundParams.mDistanceSquared =
                            GetHorizontalCameraDistanceSquared(&picture->mMapObject.mPos);
                        StartSoundFromParams(&fourthSoundParams);
                    }
                }
            }
            if (picture->mNsbcaFrameIndex != 0) {
                return;
            }
            randomState64 = &g_GlobalMV->mLocalRandom;
            randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
            picture->mWaitFrames = (u16) (((randomState64->mValue >> 32) * 0x78) >> 32) + 0x3c;
            picture->mState = PICTURE_STATE_WAIT;
            break;
    }
}

MapObjectList *CreatePictureDrawList(void) {
    return CreateMapObjectDrawList1(CreatePicture1AndPicture2, DrawPicture, NULL);
}

MapObjectList *CreatePictureUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdatePicture, NULL);
}
