/* Decompiled C draft; module arm9; ROM address 020f0898. No matching claim. */
#include "types.h"
#include "deps/020f0898_func_020f0898.h"

undefined4 func_020f0898(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_30;
  
  uVar1 = param_1 + 0x14 & 3;
  uVar6 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  iVar7 = 0;
  local_30 = 0;
  bVar3 = *(byte *)(param_2 + 1);
  uVar1 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  if (0 < (int)uVar6) {
    do {
      uVar5 = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) + iVar7 * 4;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      if ((ushort)bVar3 == *(ushort *)(uVar5 + 0x4e)) {
        local_30 = 1;
        uVar4 = *(undefined1 *)(param_2 + 2);
        if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 1) {
          func_020f5cc4(uVar5,uVar4);
        }
        if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 5) {
          func_020fc8ec(uVar5,uVar4);
        }
        if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 0xb) {
          func_021003e8(uVar5,uVar4,*(undefined1 *)(param_2 + 3));
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar6);
  }
  return local_30;
}

