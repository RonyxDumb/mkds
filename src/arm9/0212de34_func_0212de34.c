/* Decompiled C draft; module arm9; ROM address 0212de34. No matching claim. */
#include "types.h"
#include "deps/0212de34_func_0212de34.h"

undefined4 func_0212de34(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar1 = SND_GetWaveDataAddress();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = func_020219e8(param_1);
  uVar3 = param_1 + 0x38U & 3;
  uVar6 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar2 = iVar1 - 1;
  iVar1 = param_1 + ((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) + param_2) * 4;
  bVar7 = param_2 < uVar2;
  if (bVar7) {
    uVar3 = iVar1 + 0x40;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  uVar3 = iVar1 + 0x3c;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if (!bVar7) {
    uVar2 = param_1 + 8U & 3;
    uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  }
  iVar1 = uVar2 - uVar3;
  if (param_4 == 0) {
    return 0;
  }
  iVar4 = Sound_Context_Allocate(param_4,iVar1 + 0x20,uRam0212df24,param_1);
  if (iVar4 == 0) {
    return 0;
  }
  iVar5 = Sound_ReadFile(param_3,iVar4,iVar1,uVar3);
  if (iVar1 == iVar5) {
    DC_SomeClean(iVar4,iVar1);
    SND_SetWaveDataAddress(param_1,param_2,iVar4);
    return 1;
  }
  return 0;
}

