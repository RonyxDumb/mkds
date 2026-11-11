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
    PlayerRecord *entry;

    ClearParticipantBits();
    for (i = 0; i < 8; i++) {
        if ((gConnectionWork->mParticipantMask & (1 << i)) != 0) {
            for (j = 0; j < 4; j++) {
                entry = &gConnectionWork->mPlayerRecords[i];
                bitsByte = &entry->mBits[j];
                if (i == 0) {
                    gBackupBuffers->mParticipantAndBits[j] = *bitsByte;
                    gBackupBuffers->mParticipantOrBits[j] = *bitsByte;
                } else {
                    gBackupBuffers->mParticipantAndBits[j] &= *bitsByte;
                    gBackupBuffers->mParticipantOrBits[j] |= *bitsByte;
                }
            }
            entry = &gConnectionWork->mPlayerRecords[i];
            value = GetKartAppearLimitFromBits(entry->mBits);
            if (i == 0) {
                gBackupBuffers->mParticipantMaxValue = value;
                gBackupBuffers->mParticipantMinValue = value;
            } else {
                if (value > gBackupBuffers->mParticipantMaxValue) {
                    gBackupBuffers->mParticipantMaxValue = value;
                }
                if (value < gBackupBuffers->mParticipantMinValue) {
                    gBackupBuffers->mParticipantMinValue = value;
                }
            }
        }
    }
}

void ClearParticipantBits(void) {
    u8 i;

    for (i = 0; i < 4; i++) {
        gBackupBuffers->mParticipantAndBits[i] = 0;
        gBackupBuffers->mParticipantOrBits[i] = 0;
    }
    gBackupBuffers->mParticipantMaxValue = 0;
    gBackupBuffers->mParticipantMinValue = 0;
}
#pragma thumb off
