#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void CombineParticipantBits(void) {
    u8 i;
    u8 j;
    u8 value;
    u8 *bitsByte;
    Unk0217aa00_45c *entry;

    ClearParticipantBits();
    for (i = 0; i < 8; i++) {
        if ((gStruct217AA00->mParticipantMask & (1 << i)) != 0) {
            for (j = 0; j < 4; j++) {
                entry = &gStruct217AA00->field45C[i];
                bitsByte = &entry->mBits[j];
                if (i == 0) {
                    gSaveData->mParticipantAndBits[j] = *bitsByte;
                    gSaveData->mParticipantOrBits[j] = *bitsByte;
                } else {
                    gSaveData->mParticipantAndBits[j] &= *bitsByte;
                    gSaveData->mParticipantOrBits[j] |= *bitsByte;
                }
            }
            entry = &gStruct217AA00->field45C[i];
            value = savd_calcKartUnlockLevel(entry->mBits);
            if (i == 0) {
                gSaveData->mParticipantMaxValue = value;
                gSaveData->mParticipantMinValue = value;
            } else {
                if (value > gSaveData->mParticipantMaxValue) {
                    gSaveData->mParticipantMaxValue = value;
                }
                if (value < gSaveData->mParticipantMinValue) {
                    gSaveData->mParticipantMinValue = value;
                }
            }
        }
    }
}

void ClearParticipantBits(void) {
    u8 i;

    for (i = 0; i < 4; i++) {
        gSaveData->mParticipantAndBits[i] = 0;
        gSaveData->mParticipantOrBits[i] = 0;
    }
    gSaveData->mParticipantMaxValue = 0;
    gSaveData->mParticipantMinValue = 0;
}
#pragma thumb off
