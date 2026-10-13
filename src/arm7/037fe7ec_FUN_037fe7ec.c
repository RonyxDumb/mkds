/* Decompiled C draft; module arm7; ROM address 037fe7ec. No matching claim. */
#include "types.h"
#include "deps/037fe7ec_FUN_037fe7ec.h"

undefined1 FUN_037fe7ec(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 < (*(uint *)(DAT_037fe834 & 0xfffffffc) >> (DAT_037fe834 & 3) * 8 |
                 *(uint *)(DAT_037fe834 & 0xfffffffc) << (DAT_037fe834 & 3) * -8 + 0x20)) ||
     (uVar1 = DAT_037fe834 + 4 & 3, uVar2 = *(uint *)(DAT_037fe834 + 4 & 0xfffffffc),
     (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) <= param_1)) {
    FUN_037fe83c(param_1);
  }
  return *(undefined1 *)
          (DAT_037fe838 +
          (param_1 -
          (*(uint *)(DAT_037fe834 & 0xfffffffc) >> (DAT_037fe834 & 3) * 8 |
          *(uint *)(DAT_037fe834 & 0xfffffffc) << (DAT_037fe834 & 3) * -8 + 0x20)));
}

