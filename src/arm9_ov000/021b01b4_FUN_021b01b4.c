/* Decompiled C draft; module arm9_ov000; ROM address 021b01b4. No matching claim. */
#include "types.h"
#include "deps/021b01b4_FUN_021b01b4.h"

uint FUN_021b01b4(ushort *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (((uint)param_1 & 1) == 0) {
    uVar1 = (int)(param_3 & 0xffff) >> 8 | (param_3 & 0xff) << 8;
    if (1 < param_2) {
      do {
        uVar1 = uVar1 + *param_1;
        param_1 = param_1 + 1;
        param_2 = param_2 - 2;
      } while (1 < param_2);
    }
    uVar1 = uVar1 >> 8 & DAT_021b0234 | uVar1 << 8 & DAT_021b0238;
    param_3 = uVar1 >> 0x10 | uVar1 << 0x10;
  }
  else if (1 < param_2) {
    do {
      param_3 = param_3 + CONCAT11((byte)*param_1,*(byte *)((int)param_1 + 1));
      param_1 = param_1 + 1;
      param_2 = param_2 - 2;
    } while (1 < param_2);
  }
  if (param_2 != 0) {
    param_3 = param_3 + (uint)(byte)*param_1 * 0x100;
  }
  uVar1 = (param_3 & DAT_021b023c) + (param_3 >> 0x10);
  return uVar1 + (uVar1 >> 0x10) & 0xffff;
}

