/* Decompiled C draft; module arm7; ROM address 037fbbf4. No matching claim. */
#include "types.h"
#include "deps/037fbbf4_FUN_037fbbf4.h"

void FUN_037fbbf4(uint param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  *(char *)(DAT_037fbc5c + param_1) = (char)param_2;
  uVar2 = *(uint *)(DAT_037fbc60 & 0xfffffffc) >> (DAT_037fbc60 & 3) * 8 |
          *(uint *)(DAT_037fbc60 & 0xfffffffc) << (DAT_037fbc60 & 3) * -8 + 0x20;
  if (-1 < (int)uVar2) {
    param_2 = uVar2;
  }
  *(char *)(param_1 * 0x10 + 0x4000402) = (char)param_2;
  if ((0 < (int)(*(uint *)(DAT_037fbc64 & 0xfffffffc) >> (DAT_037fbc64 & 3) * 8 |
                *(uint *)(DAT_037fbc64 & 0xfffffffc) << (DAT_037fbc64 & 3) * -8 + 0x20)) &&
     ((1 << (param_1 & 0xff) & DAT_037fbc68) != 0)) {
    uVar1 = FUN_037fba94(*(undefined1 *)(DAT_037fbc6c + param_1));
    *(undefined1 *)(param_1 * 0x10 + 0x4000400) = uVar1;
  }
  return;
}

