/* Decompiled C draft; module arm9; ROM address 020def00. No matching claim. */
#include "types.h"
#include "deps/020def00_func_020def00.h"

void func_020def00(undefined4 param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint auStack_3c [3];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  uVar2 = func_020d3c44();
  *(undefined2 *)(param_2 + 0xf0) = uVar2;
  uVar9 = param_2 + 0x100U & 3;
  uVar3 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
  if (uVar3 >> uVar9 * 8 != 0 || uVar3 << uVar9 * -8 + 0x20 != 0) {
    return;
  }
  uVar9 = param_2 + 0x78U & 3;
  uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if ((iRam020df058 < (int)((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) & 0x3fffffe0)) &&
     (iVar4 = func_0203c5e4(), iVar4 == 0)) {
    return;
  }
  uVar3 = uRam020df060;
  uVar9 = param_2 + 0xecU & 3;
  uVar5 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  if (0 < (int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20)) {
    uVar6 = *(uint *)(uRam020df05c & 0xfffffffc) >> (uRam020df05c & 3) * 8 |
            *(uint *)(uRam020df05c & 0xfffffffc) << (uRam020df05c & 3) * -8 + 0x20;
    iVar4 = 0;
    uVar9 = uVar6 + (uint)*(ushort *)(param_2 + 0xa2) * 8;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    auStack_3c[0] = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    auStack_3c[1] = 0;
    uVar9 = uVar6 + (uint)*(ushort *)(param_2 + 0xa2) * 8 + 4;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uStack_24 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    auStack_3c[2] = -uStack_24;
    uStack_30 = 0;
    uStack_28 = 0;
    uStack_20 = 0;
    uStack_2c = 0x1000;
    uVar9 = param_2 + 0xfcU & 3;
    uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar6 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
    uVar8 = *(uint *)(uRam020df060 & 0xfffffffc) >> (uRam020df060 & 3) * 8 |
            *(uint *)(uRam020df060 & 0xfffffffc) << (uRam020df060 & 3) * -8 + 0x20;
    iStack_18 = (int)(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                     *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) >> 4;
    uVar9 = uVar6 + 4 & 3;
    uVar5 = *(uint *)(uVar6 + 4 & 0xfffffffc);
    iStack_14 = (int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) >> 4;
    uVar9 = uVar6 + 8 & 3;
    uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    iStack_10 = (int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) >> 4;
    uVar9 = uVar8 + 0x14 & 3;
    uVar6 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
    uVar5 = param_2 + 0xecU & 3;
    uVar7 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
    *(uint *)(uVar8 + 0x14) = (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) & 0xffe0ffff;
    uVar9 = uVar8 + 0x14 & 3;
    uVar6 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
    *(uint *)(uVar8 + 0x14) =
         uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20 |
         (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) << 0x10;
    uVar9 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar5 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
    uVar1 = *(ushort *)(param_2 + 0xf0);
    uVar9 = uVar5 + 0x14 & 3;
    uVar3 = *(uint *)(uVar5 + 0x14 & 0xfffffffc);
    *(uint *)(uVar5 + 0x14) = (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) & 0xc0ffffff;
    uVar9 = uVar5 + 0x14 & 3;
    uVar3 = *(uint *)(uVar5 + 0x14 & 0xfffffffc);
    *(uint *)(uVar5 + 0x14) = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20 | (uint)uVar1 << 0x18;
    uVar9 = param_2 + 0xfcU & 3;
    uVar3 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    if (uVar3 >> uVar9 * 8 != 0 || uVar3 << uVar9 * -8 + 0x20 != 0) {
      iVar4 = param_2 + 0x1c;
    }
    uStack_1c = auStack_3c[0];
    func_020e67c4(*(uint *)(uRam020df060 & 0xfffffffc) >> (uRam020df060 & 3) * 8 |
                  *(uint *)(uRam020df060 & 0xfffffffc) << (uRam020df060 & 3) * -8 + 0x20,auStack_3c,
                  iVar4,0);
    return;
  }
  return;
}

