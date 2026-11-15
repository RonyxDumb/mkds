#include "Main/Net/participant_index.h"
#include "Main/Net/scan_slot.h"
#include "Main/Net/mp_states.h"
#include "Main/MapObjects/data_0217a000.h"

u32 GetParticipantIndex(u32 position) {
    return (gConnectionWork->mParticipantIndices[position]);
}

// Also rebuilds the participant index tables, combines the participants' bits and requests the next state.
void SetParticipantMask(u8 mask) {
    u32 maskWord = mask;
    gConnectionWork->mParticipantMask = maskWord;
    RefreshParticipantTables();
    RequestMPState15AfterCombine();
}
