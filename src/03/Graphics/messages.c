#include "03/Graphics/messages.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "03/code_021c2530.h"
#include "03/System/pointer_stack.h"
#include "03/unk_021da000.h"
#include "03/System/dwc_archive.h"
#include "03/unk_021d5000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/code_021d1000.h"
#include "03/System/exp_heap.h"
#include "03/code_021d1d60.h"

MessagesPool *gMessagesPool;

void InitMessagesPool(void) {
    gMessagesPool = AllocExpHeapBlock(sizeof(MessagesPool), 4);
    gMessagesPool->mFreeList = CreateFilledPointerStack(8, gMessagesPool, 12);
}

void FreeMessagesPool(void) {
    FreeExpHeapBlockAndClearPointer(&gMessagesPool);
}

MessageFile *LoadMessages(void *path) {
    MessageFile *messages;
    BmgEntryOffsetSection *section;
    u32 size;
    messages = PopPointerStack(gMessagesPool->mFreeList);
    messages->mFile = LoadFile(path, &size, 4);
    section = (BmgEntryOffsetSection *) &messages->mFile->mFirstSection;
    messages->mOffsets = section->mEntryOffsets;
    messages->mData = OFFSET_PTR(BmgBodySection, section, section->mNextOffset)->mBody;
    return messages;
}

void ReleaseMessages(MessageFile *messages) {
    DeleteLoadedFile(messages->mFile);
    PushPointerStack(gMessagesPool->mFreeList, messages);
}

void *GetMessageEntry(MessageFile *messages, u32 index) {
    return messages->mData + messages->mOffsets[index & 0x0000ffffu];
}

void *GetMessageEntryAndWriteDigit(MessageFile *table, u32 index, s32 column, s32 value) {
    u16 *cell = (u16 *) (table->mData + table->mOffsets[index & 0xffff]);
    if (column >= 0) {
        cell[column] = value + 0x30;
    }
    return cell;
}
