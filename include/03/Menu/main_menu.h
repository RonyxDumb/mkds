#pragma once

#include "types.h"

typedef struct ExchangeStatus {
    /* 00 */ u32 mStatus;
    /* 04 */ u32 mTimeoutMillisecondsRemaining;
    /* 08 */ u32 mResultCode;
} ExchangeStatus;

void StoreExchangeStatus(const ExchangeStatus *status);
void StoreExchangeResultForAp(void);
u32 GetExchangeOutcome(void);
void StopExchangeWithStatusRecord(void);
void StartExchangeWithStatusRecord(void);
void ReleaseMainAndQuit(void);

extern void *gLanguageBmgNames[6];
extern ExchangeStatus *gExchangeStatusRecord;
