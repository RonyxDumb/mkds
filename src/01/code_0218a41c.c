#include "01/code_0218a41c.h"
#include "01/code_02188218.h"
#include "01/code_02188260.h"
#include "01/code_0218a444.h"
#include "01/code_02187000.h"
#include "01/code_0218a000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"

void StartBombKingItemHitState(Unk02188950 *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartBombKingBounceStateAfterHits(mapObject);
    } else {
        StartBombKingBounceState(mapObject);
    }
    IncrementHitCountAndCheckLimit(mapObject);
}
