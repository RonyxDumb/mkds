#include "03/Menu/exchange_status_record.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Net/ap_entries.h"
#include "03/Net/exchange_result_records.h"
#include "03/Net/exchange_essid.h"
#include "03/System/free_exp_heap_block.h"
#include "03/System/alloc_exp_heap_block.h"
#include "03/System/exp_heap.h"
#include "thread_scheduler.h"
#include "reset_interrupts_halt.h"

ExchangeStatus *gExchangeStatusRecord;

void StartExchangeWithStatusRecord(void) {
    gExchangeStatusRecord = AllocZeroedExpHeapBlock(0xc, -4);
    if (StartExchange(0xf, 0x40, StoreExchangeStatus, AllocExpHeapBlockWrapper, FreeExpHeapBlockWrapper, 0x800) != 1) {
        Os_Terminate();
    }
    Os_Sleep(0xa);
}

void StopExchangeWithStatusRecord(void) {
    if (StopExchange() != 1) {
        Os_Terminate();
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
            return EXCHANGE_OUTCOME_PENDING;
        case EXCHANGE_STATUS_SEARCH_ROUND_DONE:
            return EXCHANGE_OUTCOME_SEARCH_ROUND_DONE;
        case EXCHANGE_STATUS_FIRST_PACKET_ACCEPTED:
            return EXCHANGE_OUTCOME_FIRST_PACKET_ACCEPTED;
        case EXCHANGE_STATUS_SUCCEEDED:
            if (CopyExchangeResult(&exchangeResult) != 1) {
                Os_Terminate();
            }
            if (exchangeResult.mKind >= EXCHANGE_RESULT_KIND_NONE &&
                exchangeResult.mKind <= EXCHANGE_RESULT_KIND_WEP_KEY_16_BYTES && exchangeResult.mItem205Value == 1) {
                return EXCHANGE_OUTCOME_RESULT_USABLE;
            }
            return EXCHANGE_OUTCOME_BAD_RESULT;
        case EXCHANGE_STATUS_ENDED_WITHOUT_RESULT:
            return EXCHANGE_OUTCOME_ENDED_WITHOUT_RESULT;
    }
}

void StoreExchangeResultForAp(void) {
    ExchangeResult exchangeResult;
    if (CopyExchangeResult(&exchangeResult) != 1) {
        Os_Terminate();
    }
    WriteApWorkFromExchangeResult(&exchangeResult);
}

void StoreExchangeStatus(const ExchangeStatus *status) {
    *gExchangeStatusRecord = *status;
}
