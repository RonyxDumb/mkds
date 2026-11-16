#include "Main/Unknown/code_0204f19c.h"
#include "Main/Unknown/code_0204f220.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void ParentBlockTransferCallback(BlockTransferRecord *record) {
    s32 callbackCode = record->mCallbackCode;
    if (callbackCode == 10) {
        func_0204f220(&record->field14, *((u8 *) &record->field1C[0] + 1));
        return;
    }
    switch (gStruct217AA00->field1E46) {
        case 0:
            if (callbackCode == 2) {
                gStruct217AA00->field1E46 = 1;
            }
            break;
        case 1:
            if (callbackCode == 8) {
                gStruct217AA00->field1E46 = 2;
            }
            break;
        case 2:
            if (callbackCode == 8) {
                gStruct217AA00->field1E44 |= 4;
                gStruct217AA00->field1E46 = 0;
            }
            break;
    }
}

#pragma thumb off
