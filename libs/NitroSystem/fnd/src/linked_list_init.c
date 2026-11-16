#include "linked_list_init.h"

// Empties list and sets the offset of the links in its elements.
void IntrusiveListWrapper_InitializeEmpty(NNSFndList *list, u16 offset) {
    list->mHead = 0;
    list->mTail = 0;
    list->mCount = 0;
    list->mLinkOffset = offset;
}

// Makes object the only object of the empty list.
void IntrusiveListWrapper_InsertFirstItem(NNSFndList *list, void *object) {
    NNSFndLink *links;

    links = OFFSET_PTR(NNSFndLink, object, list->mLinkOffset);
    links->mNextObject = 0;
    links->mPrevObject = 0;
    list->mHead = object;
    list->mTail = object;
    list->mCount++;
}
