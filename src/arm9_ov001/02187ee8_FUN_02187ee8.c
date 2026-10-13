/* Decompiled C draft; module arm9_ov001; ROM address 02187ee8. No matching claim. */
#include "types.h"
#include "deps/02187ee8_FUN_02187ee8.h"

undefined4 FUN_02187ee8(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + DAT_02187f30);
  if ((int)uVar2 < (int)(uint)*(ushort *)(*DAT_02187f2c + 0xc)) {
    uVar3 = *(int *)(param_1 + DAT_02187f34) + 1;
    if ((int)(uint)*(ushort *)(*(int *)(*DAT_02187f2c + 8) + ((uVar2 << 0x10) >> 0xe) + 2) <=
        (int)uVar3) {
      uVar3 = 0;
    }
    uVar1 = func_0x02042044(uVar2 & 0xffff,uVar3 & 0xffff);
    return uVar1;
  }
  return 0;
}

