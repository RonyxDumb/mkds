#include "Main/Item/item_links.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma thumb on

void InitIndexLinks(u8 *usedHead, u8 *freeHead, u8 (*entries)[2]) {
    u8 index;
    u8 next;

    *usedHead = 0xff;
    *freeHead = 0;
    index = 0;
    do {
        next = index + 1;
        entries[index][0] = next;
        index = next;
    } while (next < 0x20);
    entries[next - 1][0] = 0xff;
}

void InitItemDataQueueLinks(void) {
    InitIndexLinks(gItemDataQueueUsedHead, gItemDataQueueFreeHead, gItemDataQueueLinks);
}

void InitItemDataDelayedLinks(void) {
    InitIndexLinks(gItemDataDelayedUsedHead, gItemDataDelayedFreeHead, gItemDataDelayedLinks);
}

#pragma thumb off
