#include "Main/Net/participant_bits.h"
#include "Main/Save/backup_reset.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void CombineParticipantBits(void) {
    u8 participantIndex;
    u8 byteIndex;
    u8 value;
    u8 *bitsByte;
    PlayerRecord *entry;

    CleanSaveDataHolderFlagBytes_from_thumb();
    for (participantIndex = 0; participantIndex < 8; participantIndex++) {
        if (BIT_IS_SET(g_GlobalZE->mParticipantMask, participantIndex)) {
            for (byteIndex = 0; byteIndex < 4; byteIndex++) {
                entry = &g_GlobalZE->mPlayerRecords[participantIndex];
                bitsByte = &entry->mBits[byteIndex];
                if (participantIndex == 0) {
                    g_SaveDataHolder->mParticipantAndBits[byteIndex] = *bitsByte;
                    g_SaveDataHolder->mParticipantOrBits[byteIndex] = *bitsByte;
                } else {
                    g_SaveDataHolder->mParticipantAndBits[byteIndex] &= *bitsByte;
                    g_SaveDataHolder->mParticipantOrBits[byteIndex] |= *bitsByte;
                }
            }
            entry = &g_GlobalZE->mPlayerRecords[participantIndex];
            value = CheckExtraKartUnlockFlagsWith_from_thumb(entry->mBits);
            if (participantIndex == 0) {
                g_SaveDataHolder->mParticipantMaxValue = value;
                g_SaveDataHolder->mParticipantMinValue = value;
            } else {
                if (value > g_SaveDataHolder->mParticipantMaxValue) {
                    g_SaveDataHolder->mParticipantMaxValue = value;
                }
                if (value < g_SaveDataHolder->mParticipantMinValue) {
                    g_SaveDataHolder->mParticipantMinValue = value;
                }
            }
        }
    }
}

void CleanSaveDataHolderFlagBytes_from_thumb(void) {
    u8 byteIndex;

    for (byteIndex = 0; byteIndex < 4; byteIndex++) {
        g_SaveDataHolder->mParticipantAndBits[byteIndex] = 0;
        g_SaveDataHolder->mParticipantOrBits[byteIndex] = 0;
    }
    g_SaveDataHolder->mParticipantMaxValue = 0;
    g_SaveDataHolder->mParticipantMinValue = 0;
}
#pragma thumb off
