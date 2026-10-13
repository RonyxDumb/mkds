/* Decompiled C draft; module arm9; ROM address 0212e0b8. No matching claim. */
#include "types.h"
#include "deps/0212e0b8_Sound_PrepareSwarDataImpl.h"

int Sound_PrepareSwarDataImpl(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_20 [4];
  uint uVar5;
  
  puVar7 = (undefined4 *)auStack_20;
  iVar3 = Sound_MaybeGetRawFilePointer();
  if (iVar3 == 0) {
    iVar3 = Sound_ReadFile(param_1,iRam0212e1e4,0x3c,0);
    if (iVar3 != 0x3c) {
      return 0;
    }
    uVar5 = iRam0212e1e4 + 0x38U & 3;
    uVar4 = *(uint *)(iRam0212e1e4 + 0x38U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if (param_2 == 0) {
      puVar7 = (undefined4 *)&stack0xffffffe4;
    }
    iVar1 = uVar5 * 4;
    iVar2 = uVar5 * 8;
    if (param_2 == 0) {
      return 0;
    }
    if (param_3 != 0) {
      Sound_GetActiveSdat(iVar2);
    }
    *puVar7 = param_1;
    iVar3 = Sound_Context_Allocate(param_2,iVar2 + 0x5c,uRam0212e1e8);
    if (iVar3 == 0) {
      return 0;
    }
    iVar6 = Sound_ReadFile(param_1,iVar3,iVar1 + 0x3c,0);
    if (iVar6 != iVar1 + 0x3c) {
      return 0;
    }
    uVar5 = iVar3 + 0x38U & 3;
    uVar4 = *(uint *)(iVar3 + 0x38U & 0xfffffffc);
    Mem_CpuCopy8((ushort *)(uintptr_t)(iVar3 + 0x3c),(uint *)(uintptr_t)(iVar3 + 0x3c + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 4),
                 iVar1);
    Mem_CpuFill8((uint *)(uintptr_t)(iVar3 + 0x3c),0,iVar1);
    DC_SomeClean(iVar3,iVar2 + 0x3c);
    if (param_3 != 0) {
      Sound_SetFileFatDynamicOffsetField(param_1,iVar3);
    }
  }
  return iVar3;
}

