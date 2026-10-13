/* Decompiled C draft; module arm9; ROM address 02055fc8. No matching claim. */
#include "types.h"
#include "deps/02055fc8_func_02055fc8.h"

void func_02055fc8(void)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uVar6 = (*(uint *)(uRam02056100 & 0xfffffffc) >> (uRam02056100 & 3) * 8 |
          *(uint *)(uRam02056100 & 0xfffffffc) << (uRam02056100 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  if (uVar6 != 0) {
    uStack_38 = 0x1000;
    uStack_2c = 0x1000;
    uStack_34 = 0;
    uStack_30 = 0;
    func_0214a428(uRam02056104,&uStack_38,0,0);
    iVar4 = 0;
    iVar8 = 0;
    do {
      *(undefined4 *)(uVar6 + iVar4 * 8) = 0;
      iVar9 = iVar4 * 8;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(uVar6 + iVar9 + 4) = 0;
      uVar2 = uRam0205610c;
      uVar1 = uRam02056108;
    } while (iVar4 < 0x80);
    iVar4 = 0;
    uVar7 = 0;
    uVar11 = 0;
    do {
      iVar9 = 0;
      uVar10 = 0;
      uVar5 = uVar11;
      do {
        *(uint *)(uVar6 + iVar8 * 8) = uVar7 & 0xff | uVar2 | (uVar1 & uVar10) << 0x10;
        iVar9 = iVar9 + 1;
        *(ushort *)(uVar6 + iVar8 * 8 + 4) = uVar5 | 0xf000;
        iVar8 = iVar8 + 1;
        uVar10 = uVar10 + 0x40;
        uVar5 = uVar5 + 8;
      } while (iVar9 < 4);
      iVar4 = iVar4 + 1;
      uVar7 = uVar7 + 0x40;
      uVar11 = uVar11 + 0x100;
    } while (iVar4 < 3);
    Arm_FlushRange(uVar6,0x400);
    CopyToOamB(uVar6,0,0x400);
    VBlankIntrWait();
    puVar3 = puRam02056110;
    uVar6 = *(uint *)(uRam02056100 & 0xfffffffc) >> (uRam02056100 & 3) * 8 |
            *(uint *)(uRam02056100 & 0xfffffffc) << (uRam02056100 & 3) * -8 + 0x20;
    *(ushort *)(uVar6 + 8) = *(ushort *)(uVar6 + 8) & 0xfffe;
    *puVar3 = *puVar3 | 0x8000;
    func_02055e54();
    return;
  }
  return;
}

