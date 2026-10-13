/* Decompiled C draft; module arm9_ov003; ROM address 021b80c4. No matching claim. */
#include "types.h"
#include "deps/021b80c4_func_ov003_021b80c4.h"

void func_ov003_021b80c4(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_4 != 0) {
    do {
      bVar1 = func_ov003_021b807c((uint *)(uintptr_t)(param_1));
      *(byte *)(param_2 + uVar2) = bVar1 ^ *(byte *)(param_3 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_4);
  }
  return;
}

