#pragma once

#include "types.h"

// Values of the type argument of DWCi_PostProcessConnection: the step the matching takes after a connection event.
// INFORM_PEERS sends the entry of participant mPostProcessPos + 1 to the newest peer, one per call; once all were told
// it sets the mode's next state and then
// either starts the sync (server mode, or when every entry is filled) or sends the participant info. Three others set
// the state to connected: CONNECTED_PEER keeps the last participant as the event profile only in the server-client
// mode, ACCEPTED_PEER sends the acknowledgement for the new entry only when more than one peer is in,
// OWN_ENTRY_ASSIGNED clears the event profile. FINISH reports the result to the game, then closes the matching
// (filter search and buddy list modes) or sets the state to accepting (server mode) or connected.
enum {
    POST_PROCESS_INFORM_PEERS,
    POST_PROCESS_CONNECTED_PEER,
    POST_PROCESS_ACCEPTED_PEER,
    POST_PROCESS_OWN_ENTRY_ASSIGNED,
    POST_PROCESS_FINISH,
};

u32 DWCi_AreAllBuddies(u32 *pidList, u32 pidListLen);
void DWCi_PostProcessConnection(s32 type);
u32 DWCi_ChangeToClient(void);
u32 DWCi_CancelPreConnectedClientProcess(u32 serverPid);
u32 DWCi_CancelPreConnectedServerProcess(u32 clientPid);
u32 DWCi_CancelReservation(u32 profileId);
