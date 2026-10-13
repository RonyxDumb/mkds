/* Decompiled C draft; module arm9; ROM address 02010310. No matching claim. */
#include "types.h"
#include "deps/02010310_ModelBlock_SomeTexPltFn_11.h"

undefined4 ModelBlock_SomeTexPltFn_11(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  param_1 = param_1 + (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
  uVar4 = 1;
  uVar5 = 0;
  iVar6 = param_1 + (uint)*(ushort *)(param_1 + 2);
  if (*(char *)(iVar6 + 1) != '\0') {
    iVar3 = 0;
    do {
      iVar2 = iVar6 + (uint)*(ushort *)(iVar6 + 6);
      iVar2 = NNS_G3dGetResDataByName
                        (param_2 + (uint)*(ushort *)(param_2 + 0x34),
                         iVar2 + (uint)*(ushort *)(iVar2 + 2) + iVar3);
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        iVar2 = *(ushort *)(iVar6 + (uint)*(ushort *)(iVar6 + 6)) * uVar5 +
                iVar6 + (uint)*(ushort *)(iVar6 + 6) + 4;
        if ((*(byte *)(iVar2 + 3) & 1) == 0) {
          func_020103c0(param_1,iVar2,param_2);
        }
      }
      uVar5 = uVar5 + 1;
      iVar3 = iVar3 + 0x10;
    } while (uVar5 < *(byte *)(iVar6 + 1));
  }
  return uVar4;
}

