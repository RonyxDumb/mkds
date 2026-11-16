#pragma once

#include "types.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/query_reporting.h"

void DWCi_QR2AddErrorCallback(s32 errorType, const u8 *message, void *userData);
s32 DWCi_QR2CountCallback(s32 keyType, void *userData);
void DWCi_QR2KeyListCallback(s32 keytype, MatchingKeyIds *keyIds, void *userdata);
void DWCi_QR2TeamKeyCallback(u8 keyId, s32 index, QueryBuffer *buffer, void *userData);
void DWCi_QR2PlayerKeyCallback(u8 keyId, s32 index, QueryBuffer *buffer, void *userData);

// Key ids of the matching server's query reports: two reserved ids of the reporter (the completed and entry counts),
// then the ids of this matching code, then the game's own keys from SERVER_KEY_GAME_FIRST on (there are
// DWC_QR2_GAME_RESERVED_KEYS of them).
#define NUMPLAYERS_KEY 8
#define MAXPLAYERS_KEY 10
#define NUM_RESERVED_KEYS 50
#define MAX_REGISTERED_KEYS 254
#define DWC_QR2_PID_KEY NUM_RESERVED_KEYS
#define DWC_QR2_MATCH_TYPE_KEY (NUM_RESERVED_KEYS + 1)
#define DWC_QR2_MATCH_RESV_KEY (NUM_RESERVED_KEYS + 2)
#define DWC_QR2_MATCH_VER_KEY (NUM_RESERVED_KEYS + 3)
#define DWC_QR2_MATCH_EVAL_KEY (NUM_RESERVED_KEYS + 4)
#define DWC_QR2_GAME_KEY_START 100
#define DWC_QR2_GAME_RESERVED_KEYS (MAX_REGISTERED_KEYS - NUM_RESERVED_KEYS - (100 - NUM_RESERVED_KEYS))

// The matching version: the value of the version key and the version in the header of every matching command.
#define WIFI_MATCH_VERSION 3

// Values of the keytype argument of the key list callback.
enum {
    QUERY_KEY_TYPE_SERVER,
    QUERY_KEY_TYPE_PLAYER,
    QUERY_KEY_TYPE_TEAM,
};
