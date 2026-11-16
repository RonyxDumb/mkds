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

// Values GetExchangeOutcome returns: the step the exchange reached, as the screens tell them apart. RESULT_USABLE is a
// finished exchange whose result has a known kind and item value 1; BAD_RESULT is a finished one that has not.
#define EXCHANGE_OUTCOME_PENDING 0
#define EXCHANGE_OUTCOME_SEARCH_ROUND_DONE 1
#define EXCHANGE_OUTCOME_FIRST_PACKET_ACCEPTED 2
#define EXCHANGE_OUTCOME_RESULT_USABLE 3
#define EXCHANGE_OUTCOME_ENDED_WITHOUT_RESULT 4
#define EXCHANGE_OUTCOME_UNUSABLE_RESULT 5

// One exchange status: the status code, the milliseconds left before the timeout (0xffffffff when none is set) and the
// result code.
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
