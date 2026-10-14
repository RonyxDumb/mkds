/* Decompiled C draft; module arm9; ROM address 0210e094. No matching claim. */
#include "types.h"
#include "deps/0210e094_func_0210e094.h"

void func_0210e094(int *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *param_1 = param_2;
  iVar2 = Sound_Context_Allocate(param_3,param_2 << 4,0,0,0);
  param_1[1] = iVar2;
  iVar2 = 0;
  if ((int)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) < 1) {
    return;
  }
  do {
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar2 * 0x10) = 0xffffffff;
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar2 * 0x10 + 4) = 0;
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar2 * 0x10 + 8) = 0;
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar2 * 0x10 + 0xc) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < (int)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20));
  return;
}

