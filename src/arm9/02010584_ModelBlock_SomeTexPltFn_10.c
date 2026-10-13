/* Decompiled C draft; module arm9; ROM address 02010584. No matching claim. */
#include "types.h"
#include "deps/02010584_ModelBlock_SomeTexPltFn_10.h"

undefined4 ModelBlock_SomeTexPltFn_10(int param_1,int param_2)

{
  uint uVar1;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar2;
  
  uVar2 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  iVar6 = param_1 + uVar2;
  uVar7 = 1;
  iVar5 = iVar6 + (uint)*(ushort *)(param_1 + uVar2);
  uVar2 = 0;
  if (*(char *)(iVar5 + 1) != '\0') {
    iVar4 = 0;
    do {
      iVar3 = iVar5 + (uint)*(ushort *)(iVar5 + 6);
      iVar3 = NNS_G3dGetResDataByName(param_2 + 0x3c,iVar3 + (uint)*(ushort *)(iVar3 + 2) + iVar4);
      if (iVar3 == 0) {
        uVar7 = 0;
      }
      else {
        iVar3 = *(ushort *)(iVar5 + (uint)*(ushort *)(iVar5 + 6)) * uVar2 +
                iVar5 + (uint)*(ushort *)(iVar5 + 6) + 4;
        if ((*(byte *)(iVar3 + 3) & 1) == 0) {
          func_020106c8(iVar6,iVar3,param_2);
        }
      }
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x10;
    } while (uVar2 < *(byte *)(iVar5 + 1));
  }
  return uVar7;
}

