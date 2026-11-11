#include "01/code_021a2398.h"
#include "01/code_021a2408.h"
#include "01/code_021a2a40.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"

void InitEmblemAndAdvanceKartList(void) {
    InitEmblem();
    AdvanceEmblemKartList();
}

BOOL AdvanceEmblemAndCheckDone(void) {
    AdvanceEmblem();
    if (gEmblem->mUnk_1090 == 0xc) {
        return TRUE;
    }
    return FALSE;
}

void AdvanceEmblemDisplayWrapper(void) {
    AdvanceEmblemDisplay();
}

u16 *GetEmblemSBPalette(void) {
    return gEmblem->mEmblemSBNclr->mData;
}

u8 *GetEmblemRecordBytes(void) {
    return gEmblem->mUnk_087c;
}
