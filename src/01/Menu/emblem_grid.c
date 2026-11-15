#include "01/Menu/emblem_grid.h"

#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/System/heap.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "signed_int_divide.h"
#include "fixed_vector_math.h"
#include "cpu_copy_fill.h"
#include "01/Race/mission_run_state.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "01/Race/race_hud_king_cells.h"
#include "03/Net/essid_packet_steps.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/font_and_player_character.h"
#include "sprite_animation_control.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

EmblemGrid *gEmblemGrid;

void CreateEmblemGrid(s32 side, s32 scrSide, s32 tableCount) {
    s32 column;
    s32 row;
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid = HeapAllocAligned(heap, sizeof(EmblemGrid), HEAP_ALIGN_CACHE_LINE);
    gEmblemGrid->mSide = side;
    gEmblemGrid->mScrSide = scrSide;
    gEmblemGrid->mTableCount = tableCount;
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mTableHalfwordBuffer = HeapAllocAligned(heap, gEmblemGrid->mTableCount * 2, HEAP_ALIGN_CACHE_LINE);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[0] =
        HeapAllocAligned(heap, gEmblemGrid->mScrSide / 8 * (gEmblemGrid->mScrSide / 8), HEAP_ALIGN_CACHE_LINE);
    MI_CpuFill8(gEmblemGrid->mBuffers[0], gEmblemGrid->mSide / 8 * gEmblemGrid->mSide / 8,
                gEmblemGrid->mScrSide / 8 * (gEmblemGrid->mScrSide / 8));
    for (row = 0; row < gEmblemGrid->mSide / 8; row++) {
        for (column = 0; column < gEmblemGrid->mSide / 8; column++) {
            gEmblemGrid->mBuffers[0][row * gEmblemGrid->mScrSide / 8 + column] = column + row * gEmblemGrid->mSide / 8;
        }
    }
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[1] =
        HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide + EMBLEM_GRID_TILE_BYTES, HEAP_ALIGN_CACHE_LINE);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[2] =
        HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide + EMBLEM_GRID_TILE_BYTES, HEAP_ALIGN_CACHE_LINE);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[3] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide, HEAP_ALIGN_CACHE_LINE);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mPointStack =
        HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide * 2, HEAP_ALIGN_CACHE_LINE);
}

u32 GetEmblemGridSide(void) {
    return (gEmblemGrid->mSide);
}

u8 *GetEmblemGridCellPtr(s32 cellX, s32 cellY) {
    if (cellX >= 0 && cellX < gEmblemGrid->mSide && cellY >= 0 && cellY < gEmblemGrid->mSide) {
        return gEmblemGrid->mBuffers[1] +
               ((cellY & 7) * 8 + ((cellX & 7) + cellX / 8 * 64) + gEmblemGrid->mSide / 8 * (cellY / 8 * 64));
    }
    return NULL;
}

void CopyEmblemGridCellsOnFirstChange(void) {
    if (gEmblemGrid->mCopied == FALSE) {
        gEmblemGrid->mChanged = 1;
        gEmblemGrid->mCopied = TRUE;
        gEmblemGrid->mSwapped = 0;
        MIi_CpuCopyFast(gEmblemGrid->mBuffers[1], gEmblemGrid->mBuffers[2], gEmblemGrid->mSide * gEmblemGrid->mSide);
    }
}

void *GetEmblemGridScr(void) {
    return gEmblemGrid->mBuffers[0];
}

u32 GetEmblemGridScrOffset(void) {
    return 0x0u;
}

int GetEmblemGridScrSize(void) {
    int charsPerSide;
    charsPerSide = _s32_div_f(gEmblemGrid->mScrSide, 8);
    return charsPerSide * charsPerSide;
}

u32 GetEmblemGridCharOffset(void) {
    return 0x0u;
}

u32 GetEmblemGridCharSize(void) {
    return gEmblemGrid->mSide * gEmblemGrid->mSide + 0x40;
}

u8 *GetEmblemGridCells(void) {
    return gEmblemGrid->mBuffers[1];
}

u32 SetEmblemGridCells(u8 *src) {
    int cellIndex;
    u32 ret;

    ret = 0;
    for (cellIndex = 0; cellIndex < gEmblemGrid->mSide * gEmblemGrid->mSide; cellIndex++) {
        if (gEmblemGrid->mBuffers[1][cellIndex] != src[cellIndex]) {
            ret = 1;
            CopyEmblemGridCellsOnFirstChange();
            gEmblemGrid->mBuffers[1][cellIndex] = src[cellIndex];
        }
    }
    return ret;
}

s32 SetEmblemGridCellsFromTable(u8 *indices, u16 *table) {
    s32 cellIndex;
    BOOL changed;

    changed = FALSE;
    for (cellIndex = 0; cellIndex < gEmblemGrid->mSide * gEmblemGrid->mSide; cellIndex++) {
        if (indices[cellIndex] < gEmblemGrid->mTableCount &&
            gEmblemGrid->mBuffers[1][cellIndex] != (u8) table[indices[cellIndex]]) {
            changed = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            gEmblemGrid->mBuffers[1][cellIndex] = table[indices[cellIndex]];
        }
    }
    return changed;
}

void SwapEmblemGridCells(void) {
    u8 *swapBuffer;

    swapBuffer = gEmblemGrid->mBuffers[1];
    gEmblemGrid->mBuffers[1] = gEmblemGrid->mBuffers[2];
    gEmblemGrid->mBuffers[2] = swapBuffer;
    gEmblemGrid->mSwapped = gEmblemGrid->mSwapped == 0 ? 1 : 0;
}

u32 IsEmblemGridSwapped(void) {
    return (gEmblemGrid->mSwapped);
}

void ClearEmblemGridCopied(void) {
    gEmblemGrid->mCopied = FALSE;
}

u32 IsEmblemGridChanged(void) {
    return (gEmblemGrid->mChanged);
}

void ResetEmblemGridChanges(void) {
    gEmblemGrid->mChanged = 0;
    gEmblemGrid->mCopied = FALSE;
    gEmblemGrid->mSwapped = 0;
    MIi_CpuCopyFast(gEmblemGrid->mBuffers[1], gEmblemGrid->mBuffers[2], gEmblemGrid->mSide * gEmblemGrid->mSide);
}

u32 SetEmblemGridCellValue(u32 cellX, u32 cellY, u32 value) {
    u8 *cellPtr;
    u32 changed;
    changed = 0;
    cellPtr = GetEmblemGridCellPtr(cellX, cellY);
    if ((cellPtr != NULL) && (*cellPtr != value)) {
        changed = 1;
        CopyEmblemGridCellsOnFirstChange();
        *cellPtr = value;
    }
    return changed;
}

u8 GetEmblemGridCellValue(s32 cellX, s32 cellY) {
    u8 *cellPtr;
    cellPtr = GetEmblemGridCellPtr(cellX, cellY);
    if (cellPtr != NULL) {
        return *cellPtr;
    }
    return 0;
}

s32 SetEmblemGridLine(s32 lineX, s32 lineY, s32 endX, s32 endY, s32 value) {
    s32 dy;
    s32 dx;
    s32 stepY;
    s32 stepX;
    BOOL changed;
    s32 stepCount;
    s32 stepIndex;
    u8 *cellPtr;

    changed = FALSE;
    if (FROM_FIXED12(endX) > FROM_FIXED12(lineX)) {
        dx = endX - lineX;
    } else if (FROM_FIXED12(lineX) > FROM_FIXED12(endX)) {
        dx = lineX - endX;
    } else {
        dx = 0;
    }
    if (FROM_FIXED12(endY) > FROM_FIXED12(lineY)) {
        dy = endY - lineY;
    } else if (FROM_FIXED12(lineY) > FROM_FIXED12(endY)) {
        dy = lineY - endY;
    } else {
        dy = 0;
    }
    if (dx == 0) {
        stepX = 0;
    } else if (dx < dy) {
        stepX = FX_Div(endX - lineX, dy);
    } else if (endX > lineX) {
        stepX = 0x1000;
    } else {
        stepX = -0x1000;
    }
    if (dy == 0) {
        stepY = 0;
    } else if (dy < dx) {
        stepY = FX_Div(endY - lineY, dx);
    } else if (endY > lineY) {
        stepY = 0x1000;
    } else {
        stepY = -0x1000;
    }
    if (dx > dy) {
        stepCount = FROM_FIXED12(dx);
    } else {
        stepCount = FROM_FIXED12(dy);
    }
    for (stepIndex = 0; stepIndex <= stepCount; stepIndex++, lineX += stepX, lineY += stepY) {
        cellPtr = GetEmblemGridCellPtr(FROM_FIXED12(lineX), FROM_FIXED12(lineY));
        if (cellPtr != NULL && *cellPtr != value) {
            changed = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            *cellPtr = value;
        }
    }
    cellPtr = GetEmblemGridCellPtr(FROM_FIXED12(endX), FROM_FIXED12(endY));
    if (cellPtr != NULL && *cellPtr != value) {
        changed = TRUE;
        CopyEmblemGridCellsOnFirstChange();
        *cellPtr = value;
    }
    return changed;
}

s32 FillEmblemGridRegion(s32 startX, s32 startY, s32 newValue) {
    BOOL result;
    s32 stackCount;
    s32 edgeIndex;
    s32 *rowStep;
    u8 rightEdge;
    s32 *scanStep;
    s32 rowY;
    s32 rowStepIndex;
    u8 *cellPtr;
    u8 *visitedCell;
    u8 oldValue;
    u8 *edgeSlot;
    EmblemGridPoint point;
    u8 edges[2];
    EmblemGridPoint scanPoint;

    result = FALSE;
    point.mX = startX;
    point.mY = startY;
    cellPtr = GetEmblemGridCellPtr(point.mX, point.mY);
    if (cellPtr != NULL) {
        oldValue = *cellPtr;
        if (oldValue != newValue) {
            stackCount = 1;
            gEmblemGrid->mPointStack[0] = point;
            MemFillWordsByBlock_inline(gEmblemGrid->mBuffers[3], gEmblemGrid->mSide * gEmblemGrid->mSide);
            do {
                s32 steps[2] = {-1, 1};

                stackCount--;
                point = gEmblemGrid->mPointStack[stackCount];
                for (edgeIndex = 0, edgeSlot = edges, scanStep = steps, rowY = point.mY; edgeIndex < 2; edgeIndex++) {
                    *edgeSlot = point.mX;
                    for (;;) {
                        cellPtr = GetEmblemGridCellPtr(*edgeSlot, rowY);
                        visitedCell = &gEmblemGrid->mBuffers[3][*edgeSlot + rowY * gEmblemGrid->mSide];
                        if (cellPtr == NULL || *cellPtr != oldValue) {
                            break;
                        }
                        *edgeSlot += *scanStep;
                        *visitedCell = 1;
                    }
                    *edgeSlot -= *scanStep;
                    edgeSlot++;
                    scanStep++;
                }
                for (rowStepIndex = 0, rowStep = steps, rightEdge = edges[1]; rowStepIndex < 2; rowStepIndex++) {
                    scanPoint.mY = rowY + *rowStep;
                    for (scanPoint.mX = edges[0]; scanPoint.mX <= rightEdge; scanPoint.mX++) {
                        cellPtr = GetEmblemGridCellPtr(scanPoint.mX, scanPoint.mY);
                        visitedCell = &gEmblemGrid->mBuffers[3][scanPoint.mX + scanPoint.mY * gEmblemGrid->mSide];
                        if (cellPtr != NULL && *cellPtr == oldValue && *visitedCell == 0) {
                            do {
                                scanPoint.mX++;
                                cellPtr = GetEmblemGridCellPtr(scanPoint.mX, scanPoint.mY);
                                visitedCell =
                                    &gEmblemGrid->mBuffers[3][scanPoint.mX + scanPoint.mY * gEmblemGrid->mSide];
                            } while (cellPtr != NULL && *cellPtr == oldValue && *visitedCell == 0);
                            scanPoint.mX--;
                            gEmblemGrid->mPointStack[stackCount++] = scanPoint;
                        }
                    }
                    rowStep++;
                }
            } while (stackCount > 0);
            result = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            for (point.mY = 0; point.mY < gEmblemGrid->mSide; point.mY++) {
                for (point.mX = 0; point.mX < gEmblemGrid->mSide; point.mX++) {
                    if (gEmblemGrid->mBuffers[3][point.mX + point.mY * gEmblemGrid->mSide] != 0) {
                        *GetEmblemGridCellPtr(point.mX, point.mY) = newValue;
                    }
                }
            }
        }
    }
    return result;
}
