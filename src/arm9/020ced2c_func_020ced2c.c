/* Decompiled C draft; module arm9; ROM address 020ced2c. No matching claim. */
#include "types.h"
#include "deps/020ced2c_func_020ced2c.h"

void func_020ced2c(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020cedf4;
  uVar7 = *(uint *)(uRam020cedf4 & 0xfffffffc) >> (uRam020cedf4 & 3) * 8 |
          *(uint *)(uRam020cedf4 & 0xfffffffc) << (uRam020cedf4 & 3) * -8 + 0x20;
  iVar10 = 0;
  uVar4 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
    iVar8 = 0;
    do {
      uVar4 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar10 * 4;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      if ((*(ushort *)(uVar4 + 2) & 1) == 0) {
        uVar3 = uVar7 + 0x10 & 3;
        uVar7 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
        iVar5 = func_020b5ae8(uVar4 + 4,(int *)(uintptr_t)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar8),
                              uVar2,1,1);
        if (iVar5 != 0) {
          uVar6 = GetB3C4_Cell_RaceS(0xa4);
          iVar9 = iVar9 + 1;
          uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          *(undefined4 *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + iVar8 + 8) = uVar6;
          uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          *(undefined2 *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + iVar8 + 0xc) = 2;
          iVar8 = iVar8 + 0x14;
        }
      }
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar10 = iVar10 + 1;
      uVar4 = uVar7 + 8 & 3;
      uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    } while (iVar10 < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20));
  }
  *(int *)(uVar7 + 4) = iVar9;
  return;
}

