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
        case 0:
        case 1:
        case 3:
        case 5:
            return 0;
        case 2:
            return 1;
        case 4:
            return 2;
        case 6:
            if (CopyExchangeResult(&exchangeResult) != 1) {
                OS_Terminate();
            }
            if (exchangeResult.mKind >= 0 && exchangeResult.mKind <= 3 && exchangeResult.mUnk_24 == 1) {
                return 3;
            }
            return 5;
        case 7:
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
