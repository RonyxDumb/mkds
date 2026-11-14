#pragma once

#include "types.h"

// Values of ExchangeStatus.mStatus (the value of gExchangeStatus when the status was copied); 1 to 5 are the running
// steps.
enum {
    EXCHANGE_STATUS_NONE,
    EXCHANGE_STATUS_STARTED,
    EXCHANGE_STATUS_SEARCH_ROUND_DONE,
    EXCHANGE_STATUS_ENTRY_FOUND,
    EXCHANGE_STATUS_FIRST_PACKET_ACCEPTED,
    EXCHANGE_STATUS_SECOND_KEY_RECEIVED,
    EXCHANGE_STATUS_SUCCEEDED,
    EXCHANGE_STATUS_ENDED_WITHOUT_RESULT,
};

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

extern ExchangeStatus *gExchangeStatusRecord;
