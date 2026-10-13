/* Decompiled C draft; module arm9; ROM address 0210ad58. No matching claim. */
#include "types.h"
#include "deps/0210ad58_StructMQRacerEntry_SomeFn_41.h"

void StructMQRacerEntry_SomeFn_41(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = iRam0210adcc;
  uVar1 = iRam0210adcc + 100U & 3;
  uVar3 = *(uint *)(iRam0210adcc + 100U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    return;
  }
  if ((uint)*(ushort *)(param_1 + 0x74) !=
      (int)*(char *)((*(uint *)(uRam0210add0 & 0xfffffffc) >> (uRam0210add0 & 3) * 8 |
                     *(uint *)(uRam0210add0 & 0xfffffffc) << (uRam0210add0 & 3) * -8 + 0x20) + 0x62)
     ) {
    uVar1 = iRam0210adcc + 0x60U & 3;
    uVar3 = *(uint *)(iRam0210adcc + 0x60U & 0xfffffffc);
    *(int *)(iRam0210adcc + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 4) = param_1;
    uVar1 = iVar2 + 0x60U & 3;
    uVar3 = *(uint *)(iVar2 + 0x60U & 0xfffffffc);
    *(undefined4 *)(iVar2 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 4 + 0x20) = param_2;
    uVar1 = iVar2 + 0x60U & 3;
    uVar3 = *(uint *)(iVar2 + 0x60U & 0xfffffffc);
    *(uint *)(iVar2 + 0x60) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
    return;
  }
  StructMQRacerEntry_SomeFn_13(param_1,param_2,1,0x6e);
  *(undefined4 *)(iVar2 + 0x6c) = 0;
  return;
}

