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
#define SERVER_KEY_NN_COMPLETED_COUNT 8
#define SERVER_KEY_ENTRY_COUNT 10
#define SERVER_KEY_PROFILE_ID REPORT_KEY_REGISTER_FIRST
#define SERVER_KEY_MODE (REPORT_KEY_REGISTER_FIRST + 1)
#define SERVER_KEY_RESERVED_PROFILE_ID (REPORT_KEY_REGISTER_FIRST + 2)
#define SERVER_KEY_VERSION (REPORT_KEY_REGISTER_FIRST + 3)
#define SERVER_KEY_EVAL (REPORT_KEY_REGISTER_FIRST + 4)
#define SERVER_KEY_GAME_FIRST 100
#define DWC_QR2_GAME_RESERVED_KEYS \
    (REPORT_KEY_MAX - REPORT_KEY_REGISTER_FIRST - (SERVER_KEY_GAME_FIRST - REPORT_KEY_REGISTER_FIRST))

// The matching version: the value of the version key and the version in the header of every matching command.
#define WIFI_MATCH_VERSION 3

// Values of the keytype argument of the key list callback.
enum {
    QUERY_KEY_TYPE_SERVER,
    QUERY_KEY_TYPE_PLAYER,
    QUERY_KEY_TYPE_TEAM,
};
