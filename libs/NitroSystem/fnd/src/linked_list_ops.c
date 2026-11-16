#include "linked_list_ops.h"
#include "linked_list_init.h"

// Adds object at the end of list; an empty list gets it as its only object.
void IntrusiveListWrapper_InsertLast(NNSFndList *list, void *object) {
    NNSFndLink *links;

    if (list->mHead == 0) {
        IntrusiveListWrapper_InsertFirstItem(list, object);
        return;
    }
    links = OFFSET_PTR(NNSFndLink, object, list->mLinkOffset);
    links->mPrevObject = list->mTail;
    links->mNextObject = 0;
    (OFFSET_PTR(NNSFndLink, list->mTail, list->mLinkOffset))->mNextObject = object;
    list->mTail = object;
    list->mCount++;
}

// Adds object at the start of list; an empty list gets it as its only object.
void IntrusiveListWrapper_InsertFirst(NNSFndList *list, void *object) {
    NNSFndLink *links;

    if (list->mHead == 0) {
        IntrusiveListWrapper_InsertFirstItem(list, object);
        return;
    }
    links = OFFSET_PTR(NNSFndLink, object, list->mLinkOffset);
    links->mPrevObject = 0;
    links->mNextObject = list->mHead;
    (OFFSET_PTR(NNSFndLink, list->mHead, list->mLinkOffset))->mPrevObject = object;
    list->mHead = object;
    list->mCount++;
}

// Puts object in front of target; a NULL target appends it at the end.
void IntrusiveListWrapper_SomeFn_0(NNSFndList *list, void *target, void *object) {
    u32 linkOffset;
    NNSFndLink *links;
    void *prevElement;

    if (target == 0) {
        IntrusiveListWrapper_InsertLast(list, object);
        return;
    }
    if (target == list->mHead) {
        IntrusiveListWrapper_InsertFirst(list, object);
        return;
    }
    linkOffset = list->mLinkOffset;
    links = OFFSET_PTR(NNSFndLink, object, linkOffset);
    prevElement = (OFFSET_PTR(NNSFndLink, target, linkOffset))->mPrevObject;
    links->mPrevObject = prevElement;
    links->mNextObject = target;
    (OFFSET_PTR(NNSFndLink, prevElement, linkOffset))->mNextObject = object;
    (OFFSET_PTR(NNSFndLink, target, list->mLinkOffset))->mPrevObject = object;
    list->mCount++;
}

// Unlinks object from list and clears its links.
void IntrusiveListWrapper_RemoveItem(NNSFndList *list, void *object) {
    NNSFndLink *links;
    void *neighbor;

    links = OFFSET_PTR(NNSFndLink, object, list->mLinkOffset);
    neighbor = links->mPrevObject;
    if (neighbor == 0) {
        list->mHead = links->mNextObject;
    } else {
        (OFFSET_PTR(NNSFndLink, neighbor, list->mLinkOffset))->mNextObject = links->mNextObject;
    }
    neighbor = links->mNextObject;
    if (neighbor == 0) {
        list->mTail = links->mPrevObject;
    } else {
        (OFFSET_PTR(NNSFndLink, neighbor, list->mLinkOffset))->mPrevObject = links->mPrevObject;
    }
    links->mPrevObject = 0;
    links->mNextObject = 0;
    list->mCount--;
}

// Returns the element after object, or the first element when object is NULL.
void *IntrusiveListWrapper_NextItem(NNSFndList *list, void *object) {
    if (object == 0) {
        return list->mHead;
    }
    return (OFFSET_PTR(NNSFndLink, object, list->mLinkOffset))->mNextObject;
}

// Returns the element before object, or the last element when object is NULL.
void *IntrusiveListWrapper_GetPrevItem(NNSFndList *list, void *object) {
    if (object == 0) {
        return list->mTail;
    }
    return (OFFSET_PTR(NNSFndLink, object, list->mLinkOffset))->mPrevObject;
}

// Returns the element at position index counted from the start of list, or NULL.
void *IntrusiveListWrapper_GetAtIndex(NNSFndList *list, u16 index) {
    s32 seen;
    void *element;

    seen = 0;
    element = IntrusiveListWrapper_NextItem(list, 0);
    while (element != 0) {
        if (seen == index) {
            return element;
        }
        seen++;
        element = IntrusiveListWrapper_NextItem(list, element);
    }
    return 0;
}

s32 ComputeSomeAllocSize_1(s32 blockCount) {
    return blockCount << 4;
}
