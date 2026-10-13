/* Decompiled C draft; module arm7; ROM address 0600e1f4. No matching claim. */
#include "types.h"
#include "deps/0600e1f4_FUN_0600e1f4.h"

void FUN_0600e1f4(void)

{
  if (*(short *)((*(uint *)(DAT_0600e244 & 0xfffffffc) >> (DAT_0600e244 & 3) * 8 |
                 *(uint *)(DAT_0600e244 & 0xfffffffc) << (DAT_0600e244 & 3) * -8 + 0x20) + 1000) !=
      0) {
    FUN_06013db0();
  }
  if ((int)((uint)*(ushort *)
                   ((*(uint *)(DAT_0600e244 & 0xfffffffc) >> (DAT_0600e244 & 3) * 8 |
                    *(uint *)(DAT_0600e244 & 0xfffffffc) << (DAT_0600e244 & 3) * -8 + 0x20) + 0x33a)
           << 0x19) < 0) {
    FUN_0600f6b8();
  }
  return;
}

