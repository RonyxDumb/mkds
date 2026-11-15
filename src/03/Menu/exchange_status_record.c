#include "03/Menu/exchange_status_record.h"
#include "03/unk_021da000.h"
#include "03/code_021cb000.h"
#include "03/code_021cd2e0.h"
#include "03/unk_021d8000.h"
#include "03/Net/exchange_essid.h"
#include "03/System/free_exp_heap_block.h"
#include "03/System/alloc_exp_heap_block.h"
#include "03/System/exp_heap.h"
#include "os_thread.h"
#include "code_0200fc8c.h"

ExchangeStatus *gExchangeStatusRecord;

void StartExchangeWithStatusRecord(void) {
    gExchangeStatusRecord = AllocZeroedExpHeapBlock(0xc, -4);
    if (StartExchange(0xf, 0x40, StoreExchangeStatus, AllocExpHeapBlockWrapper, FreeExpHeapBlockWrapper, 0x800) != 1) {
        OS_Terminate();
    }
    OS_Sleep(0xa);
}

void StopExchangeWithStatusRecord(void) {
    if (StopExchange() != 1) {
        OS_Terminate();
    }
    FreeExpHeapBlockAndClearPointer(&gExchangeStatusRecord);
}

u32 GetExchangeOutcome(void) {
    ExchangeResult exchangeResult;
    switch (gExchangeStatusRecord->mStatus) {
        case EXCHANGE_STATUS_NONE:
        case EXCHANGE_STATUS_STARTED:
        case EXCHANGE_STATUS_ENTRY_FOUND:
        case EXCHANGE_STATUS_SECOND_KEY_RECEIVED:
            return 0;
        case EXCHANGE_STATUS_SEARCH_ROUND_DONE:
            return 1;
        case EXCHANGE_STATUS_FIRST_PACKET_ACCEPTED:
            return 2;
        case EXCHANGE_STATUS_SUCCEEDED:
            if (CopyExchangeResult(&exchangeResult) != 1) {
                OS_Terminate();
            }
            if (exchangeResult.mKind >= EXCHANGE_RESULT_KIND_NONE &&
                exchangeResult.mKind <= EXCHANGE_RESULT_KIND_VALUES_16 && exchangeResult.mUnk_24 == 1) {
                return 3;
            }
            return 5;
        case EXCHANGE_STATUS_ENDED_WITHOUT_RESULT:
            return 4;
    }
}

void StoreExchangeResultForAp(void) {
    ExchangeResult exchangeResult;
    if (CopyExchangeResult(&exchangeResult) != 1) {
        OS_Terminate();
    }
    WriteApWorkFromExchangeResult(&exchangeResult);
}

void StoreExchangeStatus(const ExchangeStatus *status) {
    *gExchangeStatusRecord = *status;
}
