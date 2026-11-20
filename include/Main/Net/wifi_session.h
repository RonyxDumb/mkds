#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks

typedef struct PlayerRecord PlayerRecord;

// The (enter, update) pairs of the Wi-Fi session state machine, one per WiFiSessionState value; empty slots hold 0.
extern StateCallbacks gWiFiSessionStateTable[7];

u32 GetWiFiLinkLevel(void);
void InitWiFiSession(void *heap);
void CreateWiFiSessionHeap(void *heap);
void DeleteWiFiSessionHeap(void);
void ResetWiFiSessionToOff(void);
void UpdateBuddyStatuses(void);
void UpdateWiFiSession(void);
s32 SendWiFiPacketToParticipant(u32 participantIndex, void *packet, s32 size, u32 (*finishCallback)(void));
PlayerRecord *GetWiFiSessionPlayerRecordData(u32 index);

unsigned int GetWiFiSessionErrorCodeNegated(void);

typedef struct WiFiSessionMessageHeader WiFiSessionMessageHeader;

void SetWiFiSessionOwnContinueChoice(u32 wantsContinue);
s32 GetWiFiSessionCourseId(void);
BOOL IsWiFiStep5ReachedNoDisconnect(void);
BOOL IsWiFiSessionStep7Reached(void);
BOOL IsWiFiSessionStep10Reached(void);
s32 GetWiFiSessionContinueResult(void);
void TallyPickedCourse(void);
void WriteWiFiSessionToRaceSetupCopy(void);
BOOL DoesMessageHeaderMatch(WiFiSessionMessageHeader *header, u32 size, u32 fromIndex, u32 toIndex);
BOOL IsWiFiSessionMessageKindAllowed(u32 kind);
u8 PickNextToIndex(void);
BOOL AreAllStepMessagesReceived(void);
void EndWiFiSessionOnPicksMismatch(u32 index);
BOOL IsWiFiMatchingBeforeTimeLimit(void);
u8 GetWiFiMatchingParticipantCount(void);
BOOL HasWiFiBuddyStatus4(void);
u32 StopWiFiSessionMatching(void);
BOOL IsWiFiSessionMatchingActive(void);
BOOL IsKartKeysStartStatus2(void);
void RequestWiFiSessionMatching(u32 kartType, s32 useTimeLimit, s32 unused);
s32 CheckWiFiMatchingResult(void);
void RegisterKartKeysAndStart(void);
BOOL IsKartKeysStartStatus3(void);
s32 ComputeEloEval(u32 serverIndex);
BOOL ComputeRegionEval(u32 serverIndex);
s32 ComputeRegionEloEval(u32 serverIndex);
void KartKeysStartCallback(u32 result, s32 flag);
void SetWiFiDisconnectKind(s32 kind);
void ResetWiFiSession(void);
u32 CheckWiFiSessionDisconnect(void);
void ClearWiFiDisconnectStatus(void);

u32 GetWiFiSessionPickedCourseId(u8 index);
u32 GetWiFiSessionKartIndex(u8 index);
u32 GetWiFiSessionCharacterIndex(u8 index);

void SetWiFiSessionOwnPickedCourseId(s32 pickedCourseId);
void SetWiFiSessionOwnKartIndex(s32 kartIndex);
void SetWiFiSessionOwnCharacterIndexNone(void);
void SetWiFiSessionOwnCharacterIndex(s32 characterIndex);
void ReceiveWiFiSessionMessage(u32 fromIndex, void *buffer, u32 size);
BOOL UpdateWiFiSessionStepTimeout(u32 limit);
void PackWiFiSessionIndices(void);
void PackWiFiSessionIndicesWrapper(void);

extern char gKartFilterString[0x64];

extern struct WiFiSession *gWiFiSession;
