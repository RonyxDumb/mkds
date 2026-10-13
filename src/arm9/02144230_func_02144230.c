/* Decompiled C draft; module arm9; ROM address 02144230. No matching claim. */
#include "types.h"
#include "deps/02144230_func_02144230.h"

int func_02144230(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 ushort param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = Wm_GetGlobal();
  iVar2 = func_02142988(2,7,8);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x184,2);
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xc2,2);
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((*(short *)(uVar4 + 0x184) != 0) && (*(short *)(uVar4 + 0xc2) != 1)) {
    return 3;
  }
  DC_InvalidateRangeNoClean(uVar4 + 0xc,4);
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xc;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar4 == 1) {
    return 3;
  }
  iVar1 = func_021433b0(uVar4);
  if (iVar1 <= (int)param_3) {
    if ((param_3 & 0x3f) != 0) {
      return 6;
    }
    iVar1 = func_0214349c(0);
    if (iVar1 <= (int)(uint)param_5) {
      if ((param_5 & 0x1f) == 0) {
        SetSomeFunctionPtr(0xe,param_1);
        iVar1 = WM_SomeFn(0xe,10,param_2,param_3 >> 1);
        if (iVar1 == 0) {
          iVar1 = 2;
        }
        return iVar1;
      }
      return 6;
    }
    return 6;
  }
  return 6;
}

