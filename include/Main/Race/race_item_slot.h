#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// Frames of the item cell animation in gRaceItemSlot.mSlotFrames. The item cells scroll one row (0x20 pixels, 1 << the
// shift) per cycle; the cycle gets longer (2, 4, 8 and 16 frames) at each stage end below. The final scroll that
// lands on the result starts after the last stage and lasts KartItems.mSlotFinalScrollFrameCount frames.
#define RACE_ITEM_SLOT_ROW_HEIGHT_SHIFT 5
#define RACE_ITEM_SLOT_SCROLL_START_FRAME 6
#define RACE_ITEM_SLOT_STAGE_2_END_FRAME 0x12
#define RACE_ITEM_SLOT_STAGE_4_END_FRAME 0x4e
#define RACE_ITEM_SLOT_STAGE_8_END_FRAME 0x76
#define RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME 0xd6
// The frames where the shown item changes; the first ones come every frame, later ones further apart.
// UpdateRaceItemSlot also jumps to RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME at the next of them once the kart's slot has
// stopped spinning.
#define RACE_ITEM_SLOT_CHANGE_FRAME_CASES                                                                              \
    case 1:                                                                                                            \
    case 2:                                                                                                            \
    case 3:                                                                                                            \
    case 4:                                                                                                            \
    case 5:                                                                                                            \
    case 6:                                                                                                            \
    case 8:                                                                                                            \
    case 10:                                                                                                           \
    case 12:                                                                                                           \
    case 14:                                                                                                           \
    case 16:                                                                                                           \
    case 18:                                                                                                           \
    case 22:                                                                                                           \
    case 26:                                                                                                           \
    case 30:                                                                                                           \
    case 34:                                                                                                           \
    case 38:                                                                                                           \
    case 42:                                                                                                           \
    case 46:                                                                                                           \
    case 50:                                                                                                           \
    case 54:                                                                                                           \
    case 58:                                                                                                           \
    case 62:                                                                                                           \
    case 66:                                                                                                           \
    case 70:                                                                                                           \
    case 74:                                                                                                           \
    case 78:                                                                                                           \
    case 86:                                                                                                           \
    case 94:                                                                                                           \
    case 102:                                                                                                          \
    case 110:                                                                                                          \
    case 118:                                                                                                          \
    case 134:                                                                                                          \
    case 150:                                                                                                          \
    case 166:                                                                                                          \
    case 182:                                                                                                          \
    case 198:                                                                                                          \
    case 214:
// Scale spring of the item cells (fixed-point): the target and the per-frame step stored at InitRaceItemSlot and when a
// mushroom boost starts, the pull toward the target, the damping per frame, and the frame counts after which the target
// returns to normal and the spring stops.
#define RACE_ITEM_SLOT_SCALE_NORMAL TO_FIXED12(1)
#define RACE_ITEM_SLOT_SCALE_START_TARGET FIXED12_RATIO(1, 2)
#define RACE_ITEM_SLOT_SCALE_START_Y_PER_FRAME (-FIXED12_RATIO(2, 5))
#define RACE_ITEM_SLOT_SCALE_BOOST_TARGET FIXED12_RATIO(7, 10)
#define RACE_ITEM_SLOT_SCALE_BOOST_STEP (-FIXED12_RATIO(1, 10))
#define RACE_ITEM_SLOT_SCALE_SPRING FIXED12_RATIO(1, 5)
#define RACE_ITEM_SLOT_SCALE_DAMPING FIXED12_RATIO(3, 4)
#define RACE_ITEM_SLOT_SCALE_BOOST_TARGET_FRAMES 7
#define RACE_ITEM_SLOT_SCALE_END_FRAME 10

void DrawRaceMissionRunCount(RaceHudOamBuffer *oamBuffer);
void DrawRaceModeCount(RaceHudOamBuffer *oamBuffer);
void UpdateRaceModeCount(void);
void InitRaceModeCount(void);
BOOL IsRaceKeyRecordingNotFull(void);
void DrawRaceItemSlot(RaceHudOamBuffer *oamBuffer);
void UpdateRaceItemSlot(void);
void ClearRaceItemSlotPointer(void);

void ClearRaceModeCountPointer(void);

void InitRaceItemSlot(void);

extern struct RaceItemSlot *gRaceItemSlot;
extern struct RaceModeCount *gRaceModeCount;
