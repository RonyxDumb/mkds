/* Decompiled C draft; module arm9; ROM address 02134890. No matching claim. */
#include "types.h"
#include "deps/02134890_func_02134890.h"

undefined4 func_02134890(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  if (param_4 == iRam021349ac) {
    iVar10 = 3;
  }
  else if (param_4 == iRam021349b0) {
    iVar10 = 4;
  }
  else {
    iVar10 = 5;
  }
  iVar9 = iVar10 * 0x14 + iRam021349b4;
  iVar3 = Os_Mutex_TryLock(iVar9);
  iVar2 = iRam021349c0;
  if (iVar3 == 0) {
    uVar8 = iRam021349b8 + 8U & 3;
    uVar6 = *(uint *)(iRam021349b8 + 8U & 0xfffffffc);
    uVar8 = (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 0x6c;
    uVar6 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(iRam021349bc + iVar10 * 4) = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    *(undefined4 *)(iVar2 + iVar10 * 4) = 1;
  }
  else {
    uVar6 = iRam021349b8 + 8U & 3;
    uVar4 = *(uint *)(iRam021349b8 + 8U & 0xfffffffc);
    uVar8 = iRam021349bc + iVar10 * 4;
    uVar1 = uVar8 & 3;
    uVar7 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x6c;
    uVar6 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if ((uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) ==
        (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20)) {
      uVar8 = iRam021349c0 + iVar10 * 4;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)(iRam021349c0 + iVar10 * 4) = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + 1;
    }
    else {
      Os_Mutex_Lock(iVar9);
      iVar2 = iRam021349c0;
      uVar8 = iRam021349b8 + 8U & 3;
      uVar6 = *(uint *)(iRam021349b8 + 8U & 0xfffffffc);
      uVar8 = (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 0x6c;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)(iRam021349bc + iVar10 * 4) = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      *(undefined4 *)(iVar2 + iVar10 * 4) = 1;
    }
  }
  uVar5 = func_02134540(param_1,param_2,param_3,param_4);
  iVar2 = iRam021349c0;
  uVar8 = iRam021349c0 + iVar10 * 4;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  *(uint *)(iRam021349c0 + iVar10 * 4) = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) - 1;
  uVar8 = iVar2 + iVar10 * 4;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if (uVar8 >> uVar6 * 8 == 0 && uVar8 << uVar6 * -8 + 0x20 == 0) {
    Os_Mutex_Unlock(iVar9);
  }
  return uVar5;
}

