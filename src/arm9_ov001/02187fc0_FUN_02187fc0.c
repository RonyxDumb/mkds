/* Decompiled C draft; module arm9_ov001; ROM address 02187fc0. No matching claim. */
#include "types.h"
#include "deps/02187fc0_FUN_02187fc0.h"

undefined4 FUN_02187fc0(int param_1)

{
  undefined4 uVar1;
  
  if ((int)*(uint *)(param_1 + DAT_02187ff4) < (int)(uint)*(ushort *)(*DAT_02187ff8 + 0xc)) {
    uVar1 = func_0x02042044(*(uint *)(param_1 + DAT_02187ff4) & 0xffff,
                            *(uint *)(param_1 + DAT_02187ffc) & 0xffff);
    return uVar1;
  }
  return 0;
}

