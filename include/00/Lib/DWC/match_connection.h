#pragma once

#include "types.h"

// Values of the type argument of DWCi_PostProcessConnection: what the matching does once a connection is set up.
// INFORM_PEERS
// sends the participant list entry on to the next peer (or ends the matching when all were told), the others set
// the state to connected: FIRST_PEER_CONNECTED keeps the last participant as the event profile, ACCEPTED_PEER sends the
// acknowledgement for the new entry, OWN_ENTRY_ASSIGNED keeps the profile it was called with, and FINISH reports the
// result to the game and closes or keeps the matching.
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
