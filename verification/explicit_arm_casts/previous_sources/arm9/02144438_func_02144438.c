/* Decompiled C draft; module arm9; ROM address 02144438. No matching claim. */
#include "types.h"
#include "deps/02144438_func_02144438.h"

int func_02144438(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  iVar1 = Wm_GetGlobal();
  iVar2 = func_02142988(1,0xb);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10,4);
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    if (param_4 <= uRam02144510) {
      DC_SomeClean(param_3,param_4);
      SetSomeFunctionPtr(0x12,param_1);
      Mem_CpuCopy8(param_2,&uStack_20,6);
      iVar1 = WM_SomeFn(0x12,4,uStack_20,uStack_1c);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      return iVar1;
    }
    return 6;
  }
  return 3;
}

