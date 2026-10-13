/* Decompiled C draft; module arm9; ROM address 020792c8. No matching claim. */
#include "types.h"
#include "deps/020792c8_CharacterKart_PatchRobPalette_from_thumb.h"

void CharacterKart_PatchRobPalette_from_thumb(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_18;
  
  if (param_1[0x2c] != 0) {
    iVar4 = param_1[1];
    if (iVar4 - 0x22U < 2) {
      iVar6 = *(int *)(param_1[5] + 4);
      uVar8 = uRam020793dc;
      if ((iVar4 != 0x22) && (uVar8 = uRam020793e0, iVar4 != 0x23)) {
        uVar8 = 0;
      }
      iVar4 = Dict_SomeFn_0(iVar6 + *(int *)(iVar6 + 8) + 4,uRam020793e4);
      iVar6 = iVar6 + *(int *)(iVar6 + 8);
      iVar6 = iVar6 + *(int *)(iVar6 + 4 + (uint)*(ushort *)(iVar6 + 10) +
                               iVar4 * (uint)*(ushort *)(iVar6 + 4 + (uint)*(ushort *)(iVar6 + 10))
                              + 4);
      *piRam020793e8 = iVar6;
      uVar1 = *(ushort *)(iVar6 + 0x1c);
      func_0214c48c();
      SomeDmaCopy_0(uVar8,(uint)uVar1 * 0x10,0x20);
      func_0214c3c0();
    }
    if (*param_1 == 0xb) {
      iVar4 = *(int *)(param_1[4] + 4);
      if (param_2 == 0) {
        iVar6 = Dict_SomeFn_0(iVar4 + *(int *)(iVar4 + 8) + 4,uRam020793fc);
        iVar2 = Dict_SomeFn_0(iVar4 + *(int *)(iVar4 + 8) + 4,uRam02079400);
        local_18 = uRam02079408;
        uVar7 = 0x10;
        uVar8 = uRam02079404;
      }
      else {
        iVar6 = Dict_SomeFn_0(iVar4 + *(int *)(iVar4 + 8) + 4,uRam020793ec);
        iVar2 = Dict_SomeFn_0(iVar4 + *(int *)(iVar4 + 8) + 4,uRam020793f0);
        local_18 = uRam020793f8;
        uVar7 = 0x40;
        uVar8 = uRam020793f4;
      }
      iVar4 = iVar4 + *(int *)(iVar4 + 8);
      iVar3 = iVar4 + 4 + (uint)*(ushort *)(iVar4 + 10);
      uVar5 = (uint)*(ushort *)(iVar4 + 4 + (uint)*(ushort *)(iVar4 + 10));
      iVar2 = *(int *)(iVar3 + iVar2 * uVar5 + 4);
      uVar1 = *(ushort *)(iVar4 + *(int *)(iVar3 + iVar6 * uVar5 + 4) + 0x1c);
      func_0214c48c();
      SomeDmaCopy_0(uVar8,(uint)uVar1 * 0x10,0x20);
      func_0214c3c0();
      uVar1 = *(ushort *)(iVar4 + iVar2 + 0x1c);
      func_0214c48c();
      SomeDmaCopy_0(local_18,(uint)uVar1 * 0x10,uVar7);
      func_0214c3c0();
    }
  }
  return;
}

