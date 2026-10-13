/* Decompiled C draft; module arm9; ROM address 021420c0. No matching claim. */
#include "types.h"
#include "deps/021420c0_func_021420c0.h"

void func_021420c0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  if ((int)param_2 < 1) {
    return;
  }
  uVar1 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  if ((int)param_2 < (int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xff)) {
    iVar2 = func_02142224();
    puVar4 = (uint *)(param_1 + 4);
    uVar3 = param_2 & 0xff |
            (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
    uVar1 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
    *puVar4 = uVar3 >> uVar1 | uVar3 << 0x20 - uVar1;
    if (-1 < iVar2) {
      func_0214214c(param_1,param_2);
      return;
    }
    return;
  }
  return;
}

