/* Decompiled C draft; module arm9; ROM address 02083de8. No matching claim. */
#include "types.h"
#include "deps/02083de8_func_02083de8.h"

void func_02083de8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  uint uVar10;
  
  iVar6 = iRam02083eb8 + param_1 * 0x20;
  puVar9 = (ushort *)
           ((uint)*(ushort *)
                   ((*(uint *)(uRam02083eb4 & 0xfffffffc) >> (uRam02083eb4 & 3) * 8 |
                    *(uint *)(uRam02083eb4 & 0xfffffffc) << (uRam02083eb4 & 3) * -8 + 0x20) +
                   (uint)*(ushort *)(param_2 + 0x74) * 2) * 0xc + iVar6);
  uVar10 = iVar6 + 0x1cU & 3;
  uVar5 = *(uint *)(iVar6 + 0x1cU & 0xfffffffc);
  uVar1 = iVar6 + 0x18U & 3;
  uVar7 = *(uint *)(iVar6 + 0x18U & 0xfffffffc);
  iVar6 = (*(code *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20))
                    (puVar9,uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20,param_2);
  puVar4 = puRam02083ec0;
  if (iVar6 == 0) {
    return;
  }
  uVar3 = *(ushort *)(param_2 + 0x74);
  uVar1 = uRam02083ebc & 3;
  uVar5 = *(uint *)(uRam02083ebc & 0xfffffffc);
  uVar10 = 0;
  if (*puVar9 == 0) {
    return;
  }
  do {
    uVar7 = 0;
    do {
      uVar8 = (uint)uVar3 * 0x58 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + uVar10 * 8 +
              uVar7 * 4 + 0x10;
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
      if (uVar8 != 0) {
        *(undefined2 *)(uVar8 + 0x72) = *puVar4;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 2);
    uVar10 = uVar10 + 1 & 0xffff;
  } while (uVar10 < *puVar9);
  return;
}

