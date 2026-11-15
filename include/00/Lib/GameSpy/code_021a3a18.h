#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218e2dc.h" // SOCSockAddrIn

typedef struct DWCInetControl DWCInetControl;

typedef struct NatnegMagic {
    /* 0 */ u8 mBytes[6];
} NatnegMagic;

typedef struct QueryBuffer QueryBuffer;
typedef struct QueryRecord QueryRecord;

typedef struct SOCHostEnt SOCHostEnt;

// Output buffer the string writers append to: bytes at mUnk_000, used length at mLen.
typedef struct QueryBuffer {
    /* 000 */ u8 mBuffer[0x800];
    /* 800 */ s32 mLen;
} QueryBuffer;

// Four-byte entry moved by enum_local_ips.
typedef struct LocalIpAddressBytes {
    /* 0 */ u8 mUnk_00[4];
} LocalIpAddressBytes;

typedef struct QueryRecord QueryRecord;

// List of values and their count; filled by the callback at mUnk_094 of a QueryRecord.
typedef struct MatchingKeyIds {
    /* 000 */ u8 mKeys[0x100];
    /* 100 */ s32 mKeyCount;
} MatchingKeyIds;

typedef void (*QueryServerKeyFunc)(u8 a, QueryBuffer *b, void *c);
typedef void (*QueryPlayerTeamKeyFunc)(u8 a, s32 b, QueryBuffer *c, void *d);
typedef void (*QueryKeyListFunc)(s32 a, MatchingKeyIds *b, void *c);
typedef s32 (*QueryCountFunc)(s32 a, void *b);
typedef void (*QueryErrorFunc)(s32 a, const u8 *b, void *c);
typedef void (*QueryPublicAddressFunc)(u32 a, u16 b, void *c);

// 0x110 bytes; qr2_init_socketA fills it, gCurrentQr2Rec points at the one in use.
typedef struct QueryRecord {
    /* 000 */ s32 mHbSock;
    /* 004 */ char mGameName[0x40];
    /* 044 */ u8 mSecretKey[0x40];
    /* 084 */ s8 mInstanceKey[4];
    /* 088 */ QueryServerKeyFunc mServerKeyCallback;
    /* 08c */ QueryPlayerTeamKeyFunc mPlayerKeyCallback;
    /* 090 */ QueryPlayerTeamKeyFunc mTeamKeyCallback;
    /* 094 */ QueryKeyListFunc mKeyListCallback;
    /* 098 */ QueryCountFunc mPlayerTeamCountCallback;
    /* 09c */ QueryErrorFunc mAddErrorCallback;
    /* 0a0 */ UnkFunc *mNatnegCallback;
    /* 0a4 */ UnkFunc *mClientMessageCallback;
    /* 0a8 */ QueryPublicAddressFunc mPublicAddressCallback;
    /* 0ac */ u32 mLastHeartbeat;
    /* 0b0 */ u32 mLastKeepalive;
    /* 0b4 */ BOOL mUserStateChangeRequested;
    /* 0b8 */ s32 mListedState;
    /* 0bc */ s32 mIsPublic;
    /* 0c0 */ s32 mQport;
    /* 0c4 */ BOOL mReadSocket;
    /* 0c8 */ s32 mNatNegotiate;
    /* 0cc */ SOCSockAddrIn mHbAddr;
    /* 0d4 */ UnkFunc *mCdkeyProcess;
    /* 0d8 */ s32 mClientMessageKeys[10];
    /* 100 */ s32 mCurMessageKey;
    /* 104 */ u32 mPublicIp;
    /* 108 */ u16 mPublicPort;
    /* 10c */ void *mUserData;
} QueryRecord;

s32 qr2_init_socketA(QueryRecord **qrec, s32 socket, s32 boundport, const char *gamename, const char *secretKey,
                     s32 isPublic, s32 natFlag, QueryServerKeyFunc serverKeyFn,
                     QueryPlayerTeamKeyFunc playerKeyFn, QueryPlayerTeamKeyFunc teamKeyFn,
                     QueryKeyListFunc keyListFn, QueryCountFunc countFn,
                     QueryErrorFunc errorFn, void *userData);

extern QueryRecord gStaticQr2Rec;
extern s32 gNumLocalIps;
extern u8 gLocalIpList[5 * 4];
extern char gQr2Hostname[];
extern s8 gQr2Indata[];

void send_heartbeat(QueryRecord *qrec, s32 statechanged);
void send_keepalive(QueryRecord *qrec);
void qr2_parse_queryA(QueryRecord *qrec, s8 *query, s32 len, void *sender);
BOOL qr_got_recent_message(QueryRecord *qrec, int msgkey);
void qr_process_client_message(QueryRecord *qrec, u8 *buf, s32 len);
void qr_process_old_query(QueryRecord *qrec, QueryBuffer *buf);
void qr_build_partial_old_query_reply(QueryRecord *qrec, QueryBuffer *buf, s32 keytype);
void qr_process_query(QueryRecord *qrec, QueryBuffer *buf, const u8 *qdata, s32 len);
void qr_build_query_reply(QueryRecord *qrec, QueryBuffer *buf, s32 serverkeycount, const u8 *serverkeys,
                          s32 playerkeycount, const u8 *playerkeys, s32 teamkeycount, const u8 *teamkeys);
void qr_build_partial_query_reply(QueryRecord *qrec, QueryBuffer *buf, s32 keytype, s32 keycount, const u8 *keys);
void handle_public_address(QueryRecord *qrec, const char *buffer);
void compute_challenge_response(QueryRecord *qrec, QueryBuffer *buf, const char *challenge, s32 challengelen);
void qr_add_packet_header(unsigned int buf, unsigned int ptype, unsigned int reqkey);
void gs_encrypt(u8 *key, s32 keyLength, u8 *dataBytes, s32 bufferLength);
void gs_encode(const u8 *ins, s32 size, u8 *result);
unsigned char encode_ct(u32 value);
void swap_byte(u8 *first, u8 *second);
BOOL ResolveQueryHostAddress(const char *host, u32 port, SOCSockAddrIn *saddr, SOCHostEnt **savehent);
void enum_local_ips(void);
void qr2_buffer_addA(QueryBuffer *outbuf, const char *value);
void qr2_buffer_add_int(QueryBuffer *outbuf, s32 value);
void qr2_keybuffer_add(MatchingKeyIds *keybuffer, int keyid);
void qr2_shutdown(QueryRecord *qrec);
void qr2_send_statechanged(QueryRecord *qrec);
void qr2_check_send_heartbeat(QueryRecord *qrec);
void qr2_check_queries(QueryRecord *qrec);
void qr2_think(QueryRecord *qrec);
void qr2_register_publicaddress_callback(QueryRecord *qrec, QueryPublicAddressFunc pacallback);
void qr2_register_clientmessage_callback(QueryRecord *qrec, UnkFunc *cmcallback);
void qr2_register_natneg_callback(QueryRecord *qrec, UnkFunc *nncallback);
