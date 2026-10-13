/* Decompiled C draft; module arm7; ROM address 03806714. No matching claim. */
#include "types.h"
#include "deps/03806714_FUN_03806714.h"

void FUN_03806714(void)

{
  if (*(uint *)(DAT_03806754 & 0xfffffffc) >> (DAT_03806754 & 3) * 8 != 0 ||
      *(uint *)(DAT_03806754 & 0xfffffffc) << (DAT_03806754 & 3) * -8 + 0x20 != 0) {
    FUN_037fb278(0,(undefined4 *)(uintptr_t)(0x6000000),
                 *(uint *)(DAT_03806758 & 0xfffffffc) >> (DAT_03806758 & 3) * 8 |
                 *(uint *)(DAT_03806758 & 0xfffffffc) << (DAT_03806758 & 3) * -8 + 0x20);
  }
  return;
}

