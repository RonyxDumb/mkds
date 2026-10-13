/* Decompiled C draft; module arm9; ROM address 020df07c. No matching claim. */
#include "types.h"
#include "deps/020df07c_func_020df07c.h"

void func_020df07c(undefined4 param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  int iStack_20;
  uint uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  uVar9 = param_2 + 0xe8U & 3;
  uVar2 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
  if ((int)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) < 1) {
    return;
  }
  uVar9 = param_2 + 0x100U & 3;
  uVar2 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
  pcVar5 = (code *)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20);
  if (pcVar5 == (code *)0x0) {
    iVar3 = (uint)*(ushort *)(param_2 + 0xa0) * 0x14;
    uVar6 = *(uint *)(uRam020df21c & 0xfffffffc) >> (uRam020df21c & 3) * 8 |
            *(uint *)(uRam020df21c & 0xfffffffc) << (uRam020df21c & 3) * -8 + 0x20;
    uVar9 = uVar6 + iVar3;
    uVar2 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uStack_3c = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
    iVar3 = uVar6 + iVar3;
    uVar9 = iVar3 + 4U & 3;
    uVar2 = *(uint *)(iVar3 + 4U & 0xfffffffc);
    uStack_38 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
    uStack_34 = 0;
    uVar9 = iVar3 + 0x10U & 3;
    uVar2 = *(uint *)(iVar3 + 0x10U & 0xfffffffc);
    uVar6 = *(uint *)(uRam020df218 & 0xfffffffc) >> (uRam020df218 & 3) * 8 |
            *(uint *)(uRam020df218 & 0xfffffffc) << (uRam020df218 & 3) * -8 + 0x20;
    iStack_30 = -(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20);
    uVar9 = iVar3 + 8U & 3;
    uVar2 = *(uint *)(iVar3 + 8U & 0xfffffffc);
    uStack_2c = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
    uVar9 = iVar3 + 0xcU & 3;
    uVar2 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
    uStack_24 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
    uVar9 = param_2 + 0xfcU & 3;
    uVar2 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar4 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
    iStack_18 = (int)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) >> 4;
    uVar9 = uVar4 + 4 & 3;
    uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc);
    iStack_14 = (int)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) >> 4;
    uVar9 = uVar4 + 8 & 3;
    uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc);
    iStack_10 = (int)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) >> 4;
    uVar9 = uVar6 + 0x14 & 3;
    uVar2 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
    uVar1 = *(ushort *)(param_2 + 0xf0);
    *(uint *)(uVar6 + 0x14) = (uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) & 0xc0ffffff;
    uVar9 = uVar6 + 0x14 & 3;
    uVar2 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
    *(uint *)(uVar6 + 0x14) = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20 | (uint)uVar1 << 0x18;
    uStack_28 = uStack_38;
    iStack_20 = iStack_30;
    uStack_1c = uStack_3c;
  }
  else {
    uVar9 = param_2 + 0x104U & 3;
    uVar2 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
    (*pcVar5)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20,&uStack_3c);
    iVar3 = func_020d3c44();
    uVar6 = *(uint *)(uRam020df218 & 0xfffffffc) >> (uRam020df218 & 3) * 8 |
            *(uint *)(uRam020df218 & 0xfffffffc) << (uRam020df218 & 3) * -8 + 0x20;
    uVar9 = uVar6 + 0x14 & 3;
    uVar2 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
    *(uint *)(uVar6 + 0x14) = (uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) & 0xc0ffffff;
    uVar9 = uVar6 + 0x14 & 3;
    uVar2 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
    *(uint *)(uVar6 + 0x14) = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20 | iVar3 << 0x18;
  }
  uVar6 = uRam020df218;
  uVar9 = param_2 + 0xe8U & 3;
  uVar4 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
  uVar8 = *(uint *)(uRam020df218 & 0xfffffffc) >> (uRam020df218 & 3) * 8 |
          *(uint *)(uRam020df218 & 0xfffffffc) << (uRam020df218 & 3) * -8 + 0x20;
  uVar2 = uVar8 + 0x14 & 3;
  uVar7 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
  *(uint *)(uVar8 + 0x14) = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) & 0xffe0ffff;
  uVar2 = uVar8 + 0x14 & 3;
  uVar7 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
  *(uint *)(uVar8 + 0x14) =
       uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20 |
       (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) << 0x10;
  uVar9 = param_2 + 0xfcU & 3;
  uVar2 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
  if (uVar2 >> uVar9 * 8 != 0 || uVar2 << uVar9 * -8 + 0x20 != 0) {
    uVar9 = param_2 + 0x24U & 3;
    uVar2 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
    if (0x28 < (int)(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20)) {
      func_020e67c4(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20,&uStack_3c,
                    param_2 + 0x1c,0);
      return;
    }
    return;
  }
  func_020e67c4(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20,&uStack_3c,0,0);
  return;
}

