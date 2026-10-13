/* Decompiled C draft; module arm7; ROM address 0600f54c. No matching claim. */
#include "types.h"
#include "deps/0600f54c_FUN_0600f54c.h"

void FUN_0600f54c(void)

{
  thunk_FUN_037fb218(0,(*(uint *)(DAT_0600f584 & 0xfffffffc) >> (DAT_0600f584 & 3) * 8 |
                       *(uint *)(DAT_0600f584 & 0xfffffffc) << (DAT_0600f584 & 3) * -8 + 0x20) +
                       DAT_0600f588,0x20);
  return;
}

