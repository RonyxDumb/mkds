#include "Main/Net/participant_index.h"
#include "Main/Unknown/code_02050000.h"
#include "Main/Net/scan_slot.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Net/mp_states.h"
#include "Main/Unknown/unk_0217a000.h"

u32 GetParticipantIndex(u32 position) {
    return (gConnectionWork->mParticipantIndices[position]);
}

// Also rebuilds the participant index tables, combines the participants' bits and requests the next state.
void SetParticipantMask(u8 mask) {
    u32 value0 = mask;
    gConnectionWork->mParticipantMask = value0;
    RefreshParticipantTables();
    RequestMPState15AfterCombine();
}
