#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"

void AddItemData(u32 itemKind, u32 messageKind, void *data, u8 size) {
    ItemDataSlot *slot;
    u16 slotIndex;

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        slot = &gStruct217AA14->field324[slotIndex];
        if (slot->field8 == 0) {
            goto found;
        }
    }
    slot = NULL;
found:
    slot->mItemKind = itemKind;
    slot->mMessageKind = messageKind;
    slot->field8 = 1;
    slot->field0 = gStruct217AA14->field728 + 0x28;
    MI_CpuFill8(slot->mData, 0, 20);
    if (size == 0) {
        slot->mDataSize = 0;
        return;
    }
    MI_CpuCopy8(data, slot->mData, size);
    slot->mDataSize = size;
}

void sub_205A7DC(s32 participantIndex, u16 remaining, s32 itemIndex, s32 state) {
    Unk0217aa14_754_04_20 *entry;

    entry = &((Unk0217aa14_754_04 *) (void *) &gStruct217AA14->field754->field4)->field20[participantIndex];
    entry->field0_0 = remaining;
    entry->field0_7 = itemIndex;
    entry->field0_12 = state;
}

void sub_205A7AC(s32 participantIndex) {
    Unk0217aa14_754_04 *p = (void *) &gStruct217AA14->field754->field4;
    MI_CpuFill8(&p->field20[participantIndex], 0, 2);
}

void sub_205A750(s32 itemIndex) {
    Unk0217aa14_104_68 *view;
    s32 t;

    view = &gStruct217AA14->field104[func_ov000_0219bb50()].mUnk_68_view;
    view->fieldE = 0;
    t = gStruct217AA14->field728;
    view->fieldC = 2;
    view->field0 = itemIndex;
    view->field8 = t + 0x78;
    view->field4 = 0x13;
}

void sub_205A71C(s32 participantIndex) {
    sub_20F86C4(&it_sDriverItemStatus[(u8) gStruct217AA18->mKartOfParticipant[participantIndex]]);
}

void sub_205A6B4(void) {
    u16 participantIndex;
    Unk0217aa14_104_68 *view;

    for (participantIndex = 0; participantIndex < 4;) {
        view = &gStruct217AA14->field104[participantIndex].mUnk_68_view;
        participantIndex++;
        view->field0 = 0x13;
        view->field4 = 0x13;
        view->field8 = 0;
        view->fieldC = 0;
        view->field10 = 0x13;
        view->field14 = 0;
    }
}

s32 sub_205A630(s32 participantIndex) {
    BOOL result;
    s32 itemInfoIndex;

    itemInfoIndex = gStruct217AA14->field104[participantIndex].field6C;
    result = FALSE;
    if (sub_20EFD84(&it_sDriverItemStatus[(u8) gStruct217AA18->mKartOfParticipant[participantIndex]], itemInfoIndex) !=
        FALSE) {
        gStruct217AA14->field104[participantIndex].field6C = 0x13;
        result = TRUE;
    }
    return result;
}

void sub_205A5B0(u32 participantIndex) {
    Unk0217aa14_104_68 *view;

    view = &gStruct217AA14->field104[participantIndex].mUnk_68_view;
    if (view->fieldC != 0) {
        return;
    }
    view->field4 = 0x13;
    it_resetSlot(&it_sDriverItemStatus[(u16) gStruct217AA18->mKartOfParticipant[participantIndex]].mHeldItem);
}

void func_0205a548(s32 participantIndex, s32 itemInfoIndex, s32 count) {
    Unk0217aa14_104_68 *view;

    view = &gStruct217AA14->field104[participantIndex].mUnk_68_view;
    view->field0 = itemInfoIndex;
    view->field4 = itemInfoIndex;
    SetHeldItemWithCount(&it_sDriverItemStatus[(u16) gStruct217AA18->mKartOfParticipant[participantIndex]].mHeldItem,
                         itemInfoIndex, count);
}
