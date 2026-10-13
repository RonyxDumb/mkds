/* Decompiled C draft; module arm9; ROM address 021437d8. No matching claim. */
#include "types.h"
#include "deps/021437d8_func_021437d8.h"

int func_021437d8(undefined4 param_1,ushort *param_2,int param_3,undefined4 param_4,
                 undefined2 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  iVar2 = func_02142988(1,2);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (param_2 != (ushort *)0x0) {
    DC_SomeClean(param_2,(uint)*param_2 << 1);
    SetSomeFunctionPtr(0xc,param_1);
    iVar2 = Wm_GetGlobal();
    uVar1 = iVar2 + 0xcU & 3;
    uVar3 = *(uint *)(iVar2 + 0xcU & 0xfffffffc);
    puVar4 = (undefined2 *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    *puVar4 = 0xc;
    *(ushort **)(puVar4 + 2) = param_2;
    if (param_3 == 0) {
      Mem_CpuFill8(puVar4 + 4,0,0x18);
    }
    else {
      Mem_CpuCopy8(param_3,puVar4 + 4,0x18);
    }
    *(undefined4 *)(puVar4 + 0x10) = param_4;
    puVar4[0x13] = param_5;
    iVar2 = WM_SomeFn(0xc,0);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
    return iVar2;
  }
  return 6;
}

