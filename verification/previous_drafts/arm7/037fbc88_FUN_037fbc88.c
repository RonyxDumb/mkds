/* Decompiled C draft; module arm7; ROM address 037fbc88. No matching claim. */
#include "types.h"
#include "deps/037fbc88_FUN_037fbc88.h"

void FUN_037fbc88(uint param_1,undefined4 param_2,int param_3)

{
  *(char *)(DAT_037fbd00 + param_1) = (char)param_2;
  if ((0 < (int)(*(uint *)(DAT_037fbd04 & 0xfffffffc) >> (DAT_037fbd04 & 3) * 8 |
                *(uint *)(DAT_037fbd04 & 0xfffffffc) << (DAT_037fbd04 & 3) * -8 + 0x20)) &&
     ((1 << (param_1 & 0xff) & DAT_037fbd08) != 0)) {
    param_2 = FUN_037fba94(param_2,*(undefined1 *)(param_1 * 0x10 + 0x4000402));
  }
  *(ushort *)(param_1 * 0x10 + 0x4000400) = (ushort)param_2 | (ushort)(param_3 << 8);
  return;
}

