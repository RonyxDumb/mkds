/* Decompiled C draft; module arm9; ROM address 02144048. No matching claim. */
#include "types.h"
#include "deps/02144048_func_02144048.h"

int func_02144048(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  short sVar5;
  bool bVar6;
  uint uVar4;
  
  sVar5 = 1;
  iVar2 = Wm_GetGlobal();
  uVar4 = iVar2 + 4U & 3;
  uVar3 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar2 = func_02142988(2,9,10);
  if (iVar2 != 0) {
    return iVar2;
  }
  DC_InvalidateRangeNoClean(uVar4 + iRam021441c8,2);
  uVar1 = *(ushort *)(uVar4 + 0x18e);
  DC_InvalidateRangeNoClean(uVar4 + 0x184,2);
  bVar6 = *(short *)(uVar4 + 0x184) == 0;
  if (bVar6) {
    DC_InvalidateRangeNoClean(uVar4 + iRam021441cc,2);
    sVar5 = *(short *)(uVar4 + 0x17e);
    DC_InvalidateRangeNoClean(uVar4 + 0x86,2);
  }
  if (param_3 == 0) {
    return 6;
  }
  if (sVar5 == 0) {
    return 7;
  }
  DC_InvalidateRangeNoClean(uVar4 + 0x50,2);
  uVar3 = uVar4 + 0x50 & 3;
  uVar4 = *(uint *)(uVar4 + 0x50 & 0xfffffffc);
  if (param_3 != (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) {
    if (bVar6) {
      iVar2 = 4;
    }
    else {
      iVar2 = 2;
    }
    if (param_4 + iVar2 <= (int)(uint)uVar1) {
      if (param_4 != 0) {
        DC_SomeClean(param_3,param_4);
        iVar2 = WM_SomeFn(0xf,7,param_3,param_4);
        if (iVar2 == 0) {
          iVar2 = 2;
        }
        return iVar2;
      }
      return 6;
    }
    return 6;
  }
  return 6;
}

