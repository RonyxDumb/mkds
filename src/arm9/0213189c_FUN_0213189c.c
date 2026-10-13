/* Decompiled C draft; module arm9; ROM address 0213189c. No matching claim. */
#include "types.h"
#include "deps/0213189c_FUN_0213189c.h"

uint FUN_0213189c(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 in_lr;
  
  if (param_1 << 1 < 0xff000001 && param_2 << 1 < 0xff000001) {
    if ((int)param_1 < 0) {
      param_1 = -(param_1 & 0x7fffffff);
    }
    if ((int)param_2 < 0) {
      param_2 = -(param_2 & 0x7fffffff);
    }
    return (uint)((int)param_2 <= (int)param_1);
  }
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  if ((uVar2 & 0x100) != 0) {
    uVar2 = func_021340d4(param_1,param_2,DAT_021321f8,uVar2,in_lr);
    return uVar2;
  }
  *puVar1 = uVar2 | 1;
  return 0;
}

