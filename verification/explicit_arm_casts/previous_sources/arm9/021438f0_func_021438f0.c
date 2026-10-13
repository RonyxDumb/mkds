/* Decompiled C draft; module arm9; ROM address 021438f0. No matching claim. */
#include "types.h"
#include "deps/021438f0_func_021438f0.h"

int func_021438f0(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  iVar1 = func_02142988(3,2,3,5);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 == 0) {
    return 6;
  }
  if (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 == 0 &&
      *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20 == 0) {
    return 6;
  }
  if (*(ushort *)(param_2 + 4) < 0x401) {
    if (0x20 < *(ushort *)(param_2 + 0x12)) {
      return 6;
    }
    uVar2 = (uint)*(ushort *)(param_2 + 0x10);
    if ((((uVar2 != 0) && (uVar2 != 1)) && (uVar2 != 2)) && (uVar2 != 3)) {
      return 6;
    }
    if (((uVar2 + iRam02143a74 & 0xffff) < 2) && (0x20 < *(ushort *)(param_2 + 0x34))) {
      return 6;
    }
    SetSomeFunctionPtr(0x26,param_1);
    iVar1 = Wm_GetGlobal();
    uVar2 = iVar1 + 0xcU & 3;
    uVar3 = *(uint *)(iVar1 + 0xcU & 0xfffffffc);
    puVar4 = (undefined2 *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    *puVar4 = 0x26;
    puVar4[1] = *(undefined2 *)(param_2 + 6);
    *(uint *)(puVar4 + 2) =
         *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    puVar4[4] = *(undefined2 *)(param_2 + 4);
    puVar4[5] = *(undefined2 *)(param_2 + 8);
    Mem_CpuCopy8(param_2 + 10,puVar4 + 6,6);
    puVar4[9] = *(undefined2 *)(param_2 + 0x10);
    puVar4[0x1b] = *(undefined2 *)(param_2 + 0x34);
    puVar4[10] = *(undefined2 *)(param_2 + 0x12);
    Mem_CpuCopy8(param_2 + 0x14,puVar4 + 0xb,0x20);
    iVar1 = WM_SomeFn(0x26,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return 6;
}

