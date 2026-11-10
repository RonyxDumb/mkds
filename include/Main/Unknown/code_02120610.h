#pragma once

#include "types.h"

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
