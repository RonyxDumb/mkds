#include "01/MapObjects/lld.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "animation_data_unpack.h"
#include "sound_archive_load.h"
#include "sprite_animation_control.h"
#include "cell_animation.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fixed_vector_math.h"

Lld *CreateLld(const char *fileName, void *cells, void *cellAnims) {
    s16 *box;
    LldEntry *entry;
    s32 entryIndex;
    Lld *list;
    LldData *data;
    LldRecord *rec;
    NNSG2dCellDataWithBR *cell;

    list = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(Lld));
    data = FindSceneFile((fileName));
    list->mEntryCount = data->mEntryCount;
    list->mEntries = HeapAlloc(GetHeap(GetCurrentHeapCall()), list->mEntryCount * sizeof(LldEntry));
    list->mCells = cells;
    list->mCellAnims = cellAnims;
    rec = data->mRecords;
    for (entryIndex = 0; entryIndex < list->mEntryCount; entryIndex++) {
        entry = &list->mEntries[entryIndex];
        entry->mLld = list;
        entry->mAnimIndex = rec[entryIndex].mAnimIndex;
        entry->mPosX = rec[entryIndex].mPosX > 0 ? 0.5f + TO_FIXED12(rec[entryIndex].mPosX)
                                                 : TO_FIXED12(rec[entryIndex].mPosX) - 0.5f;
        entry->mPosY = rec[entryIndex].mPosY > 0 ? 0.5f + TO_FIXED12(rec[entryIndex].mPosY)
                                                 : TO_FIXED12(rec[entryIndex].mPosY) - 0.5f;
        entry->mScale = TO_FIXED12(1);
        entry->mShown = rec[entryIndex].mShowMode != 0;
        NNS_G2dInitCellAnimation(&entry->mCellAnim, NNS_G2dGetAnimSequenceByIdx(cellAnims, rec[entryIndex].mAnimIndex),
                                 cells);
        if (rec[entryIndex].mShowMode > 1) {
            entry->mCellAnim.mActive = TRUE;
        } else {
            entry->mCellAnim.mActive = FALSE;
        }
        cell = entry->mCellAnim.mPCurrentCell;
        if ((cell->mCellAttr >> 11) & 1) {
            box = &cell->mMaxX;
            entry->mBoundsLeft = TO_FIXED12(box[2]);
            entry->mBoundsTop = TO_FIXED12(box[3]);
            entry->mBoundsRight = TO_FIXED12(box[0]);
            entry->mBoundsBottom = TO_FIXED12(box[1]);
        }
    }
    return list;
}

void AdvanceLld(Lld *lld, OamBuffer *oamBuffer) {
    s32 entryIndex;
    LldEntry *entry;
    NNSG2dCellAnimation *cellAnim;
    s32 screenX;
    s32 screenY;
    s32 scaledPos[2];
    s32 unscaledPos[2];
    NNSG2dCellDataWithBR *cell;

    for (entryIndex = 0; entryIndex < lld->mEntryCount; entryIndex++) {
        entry = &lld->mEntries[entryIndex];
        cellAnim = &entry->mCellAnim;
        if (entry->mCallback != NULL) {
            if (entry->mCallback(entry) != 0) {
                entry->mCallback = NULL;
            }
        }
        if (entry->mShown != FALSE && entry->mScale > 0) {
            screenX = FROM_FIXED12(entry->mPosX) + lld->mOffsetX;
            screenY = FROM_FIXED12(entry->mPosY) + lld->mOffsetY;
            if (screenX >= -64 && screenX <= 0x140 && screenY >= -48 && screenY <= 0xf0) {
                if (entry->mScale != TO_FIXED12(1)) {
                    u16 idx = AllocOamMatrixIndex(oamBuffer);
                    MtxFx22 mtx = {{0, 0, 0, 0}};

                    mtx.mElements[0] = FX_Div(0x1000, entry->mScale);
                    mtx.mElements[3] = FX_Div(0x1000, entry->mScale);
                    ((OamAffineGroup *) oamBuffer->mOams)[idx].mPA = mtx.mElements[0] >> 4;
                    ((OamAffineGroup *) oamBuffer->mOams)[idx].mPB = mtx.mElements[1] >> 4;
                    ((OamAffineGroup *) oamBuffer->mOams)[idx].mPC = mtx.mElements[2] >> 4;
                    ((OamAffineGroup *) oamBuffer->mOams)[idx].mPD = mtx.mElements[3] >> 4;
                    mtx.mElements[0] = entry->mScale;
                    mtx.mElements[3] = entry->mScale;
                    cell = entry->mCellAnim.mPCurrentCell;
                    scaledPos[0] = TO_FIXED12(screenX);
                    scaledPos[1] = TO_FIXED12(screenY);
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mOams[oamBuffer->mOamCount * 8],
                                              0x80 - oamBuffer->mOamCount, cell, &mtx, scaledPos, idx, 1);
                } else {
                    cell = entry->mCellAnim.mPCurrentCell;
                    unscaledPos[0] = TO_FIXED12(screenX);
                    unscaledPos[1] = TO_FIXED12(screenY);
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mOams[oamBuffer->mOamCount * 8],
                                              0x80 - oamBuffer->mOamCount, cell, NULL, unscaledPos, 0, 0);
                }
            }
        }
        if (cellAnim->mActive != FALSE) {
            NNS_G2dSetCellAnimationSpeed(&entry->mCellAnim, 0x1000);
            NNS_G2dTickCellAnimation(&entry->mCellAnim, 0x1000);
        }
    }
}

LldEntry *GetLldEntry(Lld *lld, s32 index) {
    return &lld->mEntries[index];
}

s32 FindLldEntryAtPoint(Lld *lld, s32 startIndex, s32 pointX, s32 pointY) {
    s32 fixedX;
    s32 fixedY;
    u16 count;
    LldEntry *entry;

    fixedX = pointX > 0 ? 0.5f + TO_FIXED12(pointX) : TO_FIXED12(pointX) - 0.5f;
    fixedY = pointY > 0 ? 0.5f + TO_FIXED12(pointY) : TO_FIXED12(pointY) - 0.5f;
    count = lld->mEntryCount;
    for (; startIndex < count; startIndex++) {
        entry = &lld->mEntries[startIndex];
        if (fixedX > entry->mPosX + entry->mBoundsLeft && fixedX < entry->mPosX + entry->mBoundsRight &&
            fixedY > entry->mPosY + entry->mBoundsTop && fixedY < entry->mPosY + entry->mBoundsBottom) {
            return startIndex;
        }
    }
    return -1;
}

void SetLldEntryCallback(LldEntry *entry, s32 (*callback)(LldEntry *)) {
    entry->mCallback = callback;
    entry->mCallbackCallCount = 0;
    entry->mUnk_14 = 0;
}

void ApplyLldEntryFrameCommand(LldEntry *entry, s32 frameOrCommand) {
    NNSG2dCellAnimation *cellAnim = &entry->mCellAnim;

    if (frameOrCommand == -1) {
        cellAnim->mOverriddenPlayMode = NNS_G2D_ANIMATIONPLAYMODE_FORWARD_LOOP;
        entry->mCellAnim.mActive = TRUE;
    } else if (frameOrCommand == -2) {
        NNS_G2dResetAnimCtrlState(cellAnim);
        cellAnim->mOverriddenPlayMode = NNS_G2D_ANIMATIONPLAYMODE_FORWARD;
        entry->mCellAnim.mActive = TRUE;
    } else if (frameOrCommand == -3) {
        entry->mCellAnim.mActive = FALSE;
    } else if (frameOrCommand == -4) {
        entry->mShown = TRUE;
    } else if (frameOrCommand == -5) {
        entry->mShown = FALSE;
    } else if (frameOrCommand >= 0) {
        entry->mShown = TRUE;
        NNS_G2dSetCellAnimationCurrentFrame(cellAnim, frameOrCommand);
    }
}

s32 GetLldEntryFrameIndex(LldEntry *entry) {
    if (entry->mShown != FALSE) {
        return NNS_G2dGetAnimCtrlCurrentFrame(&entry->mCellAnim);
    }
    return -5;
}

void SetLldEntryPos(LldEntry *entry, s32 screenX, s32 screenY) {
    entry->mPosX = TO_FIXED12(screenX - entry->mLld->mOffsetX);
    entry->mPosY = TO_FIXED12(screenY - entry->mLld->mOffsetY);
}

s32 GetLldEntryX(LldEntry *entry) {
    return FROM_FIXED12(entry->mPosX) + entry->mLld->mOffsetX;
}

s32 GetLldEntryY(LldEntry *entry) {
    return FROM_FIXED12(entry->mPosY) + entry->mLld->mOffsetY;
}

void SetLldEntryScale(LldEntry *entry, s32 scale) {
    entry->mScale = scale;
}

s32 GetLldEntryScale(LldEntry *entry) {
    return entry->mScale;
}

void SetLldEntryBounds(LldEntry *entry, s32 left, s32 top, s32 right, s32 bottom) {
    entry->mBoundsLeft = TO_FIXED12(left);
    entry->mBoundsTop = TO_FIXED12(top);
    entry->mBoundsRight = TO_FIXED12(right);
    entry->mBoundsBottom = TO_FIXED12(bottom);
}

void StartDonketuStepSoundFirst(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x210);
}

void StartDonketuStepSoundSecond(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x210);
}
