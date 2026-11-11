#include "Main/Unknown/code_020f7c90.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020f6be8.h"

#pragma thumb on

void RemapItemSlotRows(ItemSlotTable *table, s32 kartCount) {
    u16(*tab)[0x12];
    s32 i;
    s32 j;
    u16 sourceRow;
    u16 *sourceRows;

    sourceRows = (u16 *) &gItemSlotRowRemaps[kartCount - 1];
    tab = table->mRows;
    if (kartCount == 8) {
        return;
    }
    for (i = 0; i < kartCount; i++) {
        sourceRow = sourceRows[i] - 1;
        for (j = 0; j < 0x12; j++) {
            tab[i][j] = tab[sourceRow][j];
        }
    }
    for (; i < 8; i++) {
        for (j = 0; j < 0x12; j++) {
            tab[i][j] = 0;
        }
    }
}

void CreateItemSlotTables(void) {
    u8 *data;
    enum { K0 } i;
    s32 j;
    s32 rowCount;
    s32 *entry;
    enum { K1 } k;

    data = FindMainRaceOrMainEffectFile(gItemSlotListDatName);
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
            data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data + 1);
            data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            break;
        case MODE_BATTLE:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            switch (gRaceSetup->mBattleKind) {
                case BATTLE_KIND_BALLOON:
                default:
                    data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
                    data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
                    break;
                case BATTLE_KIND_SHINE:
                    data = ComputeItemSlotTableDataEnd(data);
                    data = ComputeItemSlotTableDataEnd(data);
                    data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
                    data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
                    break;
            }
            break;
        case MODE_VS:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
            data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            if (gRaceSetup->mCpuDifficulty == 0) {
                RemapItemSlotRows(&gItemSlotHumanGhostPeerTable, gRaceSetup->mKartCount);
                RemapItemSlotRows(&gItemSlotCpuTable, gRaceSetup->mKartCount);
            }
            break;
        case 5:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
            data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            if (gRaceSetup->mCpuDifficulty == 0) {
                RemapItemSlotRows(&gItemSlotHumanGhostPeerTable, gRaceSetup->mKartCount);
                RemapItemSlotRows(&gItemSlotCpuTable, gRaceSetup->mKartCount);
            }
            break;
    }
    rowCount = gItemSlotHumanGhostPeerTable.mRowCount;
    for (i = 0; i < 0x12; i++) {
        gItemSlotPossibleItems[i] = 0x12;
        for (j = 0; j < rowCount; j++) {
            if (gItemSlotHumanGhostPeerTable.mRows[j][i] != 0 || gItemSlotCpuTable.mRows[j][i] != 0) {
                gItemSlotPossibleItems[i] = i;
            }
        }
    }
    gItemSlotPossibleItemCount = 0;
    for (k = 0; k < 0x12; k++) {
        entry = &gItemSlotPossibleItems[k];
        if (gItemSlotPossibleItems[k] != 0x12) {
            gItemSlotPossibleItems[gItemSlotPossibleItemCount++] = *entry;
        }
    }
    gItemSlotSpinItemCount = 0;
}

#pragma thumb off

u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam) {
    ItemObject *item = itemParam;
    ItemObject *other = otherParam;

    return (gItemHitTypes + item->mKind * 0xe)[other->mKind];
}

void DeflectItemObjectRandomly(ItemObject *item, Vec3 *otherPos, Vec3 *normal) {
    RandomState64 *random;
    s64 distanceSquared;
    s32 angleIndex;
    s32 angle;

    if (item->mFlags & 0x2000000) {
        if (LENGTH_SQUARED(*normal) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(normal, normal);
        }
        if (Vec3DotUnrounded(normal, &item->mUnk_108) > 0x800) {
            item->mVelocity.z = MUL_FIXED12_NO_ROUND(normal->z, 0x14cd);
            item->mVelocity.x = MUL_FIXED12_NO_ROUND(normal->x, 0x14cd);
        }
    }
    distanceSquared = (s64) (item->mPos.x - otherPos->x) * (item->mPos.x - otherPos->x) +
                      (s64) (item->mPos.y - otherPos->y) * (item->mPos.y - otherPos->y) +
                      (s64) (item->mPos.z - otherPos->z) * (item->mPos.z - otherPos->z);
    if (distanceSquared >= (s64) item->mRadius * item->mRadius) {
        return;
    }
    item->mFlags |= 0x4000000;
    if (item->mFlags & 0x2000000) {
        return;
    }
    if (Vec3DotUnrounded(&item->mVelocity, normal) >= 0) {
        return;
    }
    random = &gRaceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    angleIndex = (u16) ((((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32)) >> 4;
    item->mUnk_108.z = gPairsByAngle[angleIndex * 2 + 1];
    item->mUnk_108.x = gPairsByAngle[angleIndex * 2];
    item->mVelocity.z = MUL_FIXED12_NO_ROUND(item->mUnk_108.z, 0x14cd);
    item->mVelocity.x = MUL_FIXED12_NO_ROUND(item->mUnk_108.x, 0x14cd);
    item->mFlags |= 0x2000000;
}
