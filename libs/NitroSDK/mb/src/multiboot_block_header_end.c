#include "multiboot_block_header_end.h"
#include "multiboot_send_data.h"
#include "arena_cache_init.h"

#pragma thumb on

int MBi_BlockHeaderEnd(int size, u32 childMask, u32 data) {
    DC_FlushRange((const void *) data, (size + 0x1fU & 0xffffffe0));
    DC_WaitWriteBufferEmpty();
    return MBi_SendMP((void *) data, size, childMask);
}

#pragma thumb off
