#include "Main/Unknown/code_020d129c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/code_020d12b0.h"
#include "Main/Unknown/unk_0217b000.h"

void InitRaceStartBattle(void) {
    gRaceStartBattle = HeapAlloc(GetHeap(GetCurrentHeapCall()), 4);
}

void ClearRaceStartBattlePointer(void) {
    gRaceStartBattle = NULL;
}
