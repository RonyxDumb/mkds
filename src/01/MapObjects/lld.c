#include "01/MapObjects/lld.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "g2d_NAN_load.h"
#include "code_0212d214.h"
#include "g2d_Animation.h"
#include "code_020222ec.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "code_02147cd8.h"

Lld *CreateLld(const char *fileName, void *cells, void *cellAnims) {
    s16 *box;
    LldEntry *entry;
    s32 entryIndex;
    Lld *list;
    LldData *data;
    LldRecord *rec;
    NNSG2dCellDataWithBR *cell;

    list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x18);
    data = FindSceneFile((fileName));
    list->mEntryCount = data->mEntryCount;
    list->mEntries = HeapAlloc(GetHeap(GetCurrentHeapCall()), list->mEntryCount * 0x88);
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
        entry->mScale = 0x1000;
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
                if (entry->mScale != 0x1000) {
                    u16 idx = AllocOamMatrixIndex(oamBuffer);
                    MtxFx22 mtx = {{0, 0, 0, 0}};

                    mtx.a[0] = FX_Div(0x1000, entry->mScale);
                    mtx.a[3] = FX_Div(0x1000, entry->mScale);
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mPA = mtx.a[0] >> 4;
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mPB = mtx.a[1] >> 4;
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mPC = mtx.a[2] >> 4;
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mPD = mtx.a[3] >> 4;
                    mtx.a[0] = entry->mScale;
                    mtx.a[3] = entry->mScale;
                    cell = entry->mCellAnim.mPCurrentCell;
                    scaledPos[0] = TO_FIXED12(screenX);
                    scaledPos[1] = TO_FIXED12(screenY);
                    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
                        (GXOamAttr *) &oamBuffer->mOams[oamBuffer->mOamCount * 8], 0x80 - oamBuffer->mOamCount,
                        cell, &mtx, scaledPos, idx, 1);
                } else {
                    cell = entry->mCellAnim.mPCurrentCell;
                    unscaledPos[0] = TO_FIXED12(screenX);
                    unscaledPos[1] = TO_FIXED12(screenY);
                    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
                        (GXOamAttr *) &oamBuffer->mOams[oamBuffer->mOamCount * 8], 0x80 - oamBuffer->mOamCount,
                        cell, NULL, unscaledPos, 0, 0);
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
        cellAnim->mOverriddenPlayMode = 2;
        entry->mCellAnim.mActive = TRUE;
    } else if (frameOrCommand == -2) {
        NNS_G2dResetAnimCtrlState(cellAnim);
        cellAnim->mOverriddenPlayMode = 1;
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
    StartMapObjectSound(&mapObject->mUnk_000, 0x210);
}

void StartDonketuStepSoundSecond(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x210);
}
