/* Decompiled C draft; module arm7; ROM address 06017e6c. No matching claim. */
#include "types.h"
#include "deps/06017e6c_FUN_06017e6c.h"

void FUN_06017e6c(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar3;
  
  uVar5 = *(uint *)(DAT_0601805c & 0xfffffffc) >> (DAT_0601805c & 3) * 8 |
          *(uint *)(DAT_0601805c & 0xfffffffc) << (DAT_0601805c & 3) * -8 + 0x20;
  iVar7 = uVar5 + DAT_06018060;
  uVar3 = iVar7 + 0x90U & 3;
  uVar2 = *(uint *)(iVar7 + 0x90U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (((*(short *)(iVar7 + 0x3c) != 0) &&
      (iVar4 = FUN_0600a578(param_1 + 0x18,uVar5 + 0x3a8), iVar4 != 0)) &&
     ((int)(*(ushort *)(param_1 + 0x10) - 0x18) <= (int)(*(ushort *)(uVar3 + 0x16) - 8))) {
    uVar2 = FUN_0600ef30(param_1 + 0x1e);
    if ((uVar2 == 0xff) || ((uVar2 != 0 && (iVar4 = FUN_0600e918(), iVar4 != 0x40)))) {
      iVar7 = FUN_06013528(param_1 + 0x1e,0xc0);
      if ((iVar7 == 0) && (iVar7 = FUN_0601364c(param_1 + 0x1e,7), iVar7 != 0)) {
        FUN_060143ac();
      }
    }
    else if (uVar2 != 0) {
      iVar4 = FUN_0600e918(uVar2);
      if (iVar4 == 0x40) {
        FUN_0600eb40(uVar2 & 0xffff,((uint)*(ushort *)(param_1 + 0x14) << 0x13) >> 0x1f);
        FUN_0600ea58(uVar2);
        uVar2 = FUN_0600e840(uVar2);
        uVar5 = 1 << (uVar2 & 0xff);
        uVar2 = uVar5 & 0xffff;
        if (((uVar2 & *(ushort *)(iVar7 + 0x9a)) == 0) && ((uVar2 & *(ushort *)(iVar7 + 0x98)) != 0)
           ) {
          uVar1 = (ushort)uVar5;
          *(ushort *)(iVar7 + 0x9a) = *(ushort *)(iVar7 + 0x9a) | uVar1;
          *(ushort *)(uVar3 + 0x10) = *(ushort *)(uVar3 + 0x10) & ~uVar1;
          puVar6 = (ushort *)(uVar3 + 0x1a);
          while (uVar2 = (uVar2 << 0xf) >> 0x10, uVar2 != 1) {
            if ((uVar2 & *(ushort *)(iVar7 + 0x98)) != 0) {
              puVar6 = (ushort *)((int)puVar6 + (uint)*(ushort *)(uVar3 + 0x16));
            }
          }
          *puVar6 = *(short *)(param_1 + 0x10) - 0x18;
          FUN_060096e4((int)puVar6 + 3,*(ushort *)(param_1 + 0x12) & 0xff);
          FUN_060096e4(puVar6 + 1,*(ushort *)(param_1 + 0xe) & 0xff);
          if (*puVar6 != 0) {
            thunk_FUN_037fb230(param_1 + 0x2c,puVar6 + 4,*puVar6 + 1);
          }
        }
      }
      else {
        iVar7 = FUN_06013528(param_1 + 0x1e,0xc0);
        if ((iVar7 == 0) && (iVar7 = FUN_0601364c(param_1 + 0x1e,7), iVar7 != 0)) {
          FUN_060143ac();
        }
      }
    }
  }
  return;
}

