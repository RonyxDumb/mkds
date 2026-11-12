#include "Main/Net/participant_bits.h"
#include "Main/Save/backup_reset.h"
#include "Main/MapObjects/data_0217a000.h"

#pragma thumb on

void CombineParticipantBits(void) {
    u8 participantIndex;
    u8 byteIndex;
    u8 value;
    u8 *bitsByte;
    PlayerRecord *entry;

    ClearParticipantBits();
    for (participantIndex = 0; participantIndex < 8; participantIndex++) {
        if ((gConnectionWork->mParticipantMask & (1 << participantIndex)) != 0) {
            for (byteIndex = 0; byteIndex < 4; byteIndex++) {
                entry = &gConnectionWork->mPlayerRecords[participantIndex];
                bitsByte = &entry->mBits[byteIndex];
                if (participantIndex == 0) {
                    gBackupBuffers->mParticipantAndBits[byteIndex] = *bitsByte;
                    gBackupBuffers->mParticipantOrBits[byteIndex] = *bitsByte;
                } else {
                    gBackupBuffers->mParticipantAndBits[byteIndex] &= *bitsByte;
                    gBackupBuffers->mParticipantOrBits[byteIndex] |= *bitsByte;
                }
            }
            entry = &gConnectionWork->mPlayerRecords[participantIndex];
            value = GetKartAppearLimitFromBits(entry->mBits);
            if (participantIndex == 0) {
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
    u8 byteIndex;

    for (byteIndex = 0; byteIndex < 4; byteIndex++) {
        gBackupBuffers->mParticipantAndBits[byteIndex] = 0;
        gBackupBuffers->mParticipantOrBits[byteIndex] = 0;
    }
    gBackupBuffers->mParticipantMaxValue = 0;
    gBackupBuffers->mParticipantMinValue = 0;
}
#pragma thumb off
