#include "Main/Net/participant_index.h"
#include "Main/Net/scan_slot.h"
#include "Main/Net/mp_states.h"
#include "Main/System/backup_net_camera_work.h"

u32 GetParticipantIndex(u32 position) {
    return (g_GlobalZE->mParticipantIndices[position]);
}

// Also rebuilds the participant index tables, combines the participants' bits and requests the next state.
void SetParticipantMask(u8 mask) {
    u32 maskWord = mask;
    g_GlobalZE->mParticipantMask = maskWord;
    RefreshParticipantTables();
    RequestMPReadyAfterCombine();
}
