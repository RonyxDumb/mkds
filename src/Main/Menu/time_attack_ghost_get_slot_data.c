#include "Main/Menu/time_attack_ghost_get_slot_data.h"
#include "Main/Menu/time_attack_ghost_get_scan.h"

GhostSceneCallbacks gTimeAttackGhostGetSlotCallbacks = {InitTimeAttackGhostGetSlot, AdvanceTimeAttackGhostGetSlot,
                                                        ReleaseTimeAttackGhostGetSlot, WriteGhostGetSlotRegisters};
s16 gTimeAttackGhostGetSlotSLabelTextRows[14][4] = {
    {0, 0x82, 0x10, 0},    {1, 0x82, 0x10, 1},    {2, 0x82, 0x10, 2},    {3, 0x82, 0x10, 3},   {4, 0x82, 0x10, 4},
    {5, 0x82, 0x10, 5},    {6, 0x82, 0x10, 6},    {7, 0x50, 0x10, -1},   {8, 0x50, 0x10, -1},  {9, 0x50, 0x10, -1},
    {0xa, 0x50, 0x10, -1}, {0xb, 0x50, 0x10, -1}, {0xc, 0x50, 0x10, -1}, {0xd, 0x50, 0x10, -1}};