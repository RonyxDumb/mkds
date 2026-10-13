/* Decompiled C draft; module arm9; ROM address 02104368. No matching claim. */
#include "types.h"
#include "deps/02104368_func_02104368.h"

void func_02104368(void)

{
  uint uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = uRam02104480;
  puVar3 = puRam0210447c;
  uVar5 = *(uint *)((uint)puRam0210447c & 0xfffffffc) >> ((uint)puRam0210447c & 3) * 8 |
          *(uint *)((uint)puRam0210447c & 0xfffffffc) << ((uint)puRam0210447c & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    return;
  }
  iVar9 = 0;
  if (0 < (int)uVar5) {
    iVar8 = 0;
    do {
      uVar5 = uVar1 & 3;
      uVar6 = *(uint *)(uVar1 & 0xfffffffc);
      uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + iVar8 + 0x24;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      (*(code *)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20))();
      uVar5 = (uint)puVar3 & 3;
      uVar6 = *(uint *)((uint)puVar3 & 0xfffffffc);
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + 0x34;
    } while (iVar9 < (int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20));
  }
  uVar1 = uRam02104488 & 3;
  uVar5 = *(uint *)(uRam02104488 & 0xfffffffc);
  uVar6 = (*(uint *)((uint)puRam02104484 & 0xfffffffc) >> ((uint)puRam02104484 & 3) * 8 |
          *(uint *)((uint)puRam02104484 & 0xfffffffc) << ((uint)puRam02104484 & 3) * -8 + 0x20) + 1;
  *puRam02104484 = uVar6;
  puVar4 = puRam0210448c;
  if ((int)uVar6 <= (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)) {
    return;
  }
  if ((uVar6 & 1) != 0) {
    return;
  }
  *puRam0210448c = *puRam0210448c - 1;
  puVar3 = puRam02104490;
  uVar2 = *puVar4;
  if (uVar2 == 0) {
    *puRam0210447c = 0;
    *puVar3 = 0;
    uVar7 = func_02108e6c(6);
    func_0212c6f0(uVar7,1);
    return;
  }
  iVar9 = iRam02104494;
  if (*(uint *)((uint)puRam02104490 & 0xfffffffc) >> ((uint)puRam02104490 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02104490 & 0xfffffffc) << ((uint)puRam02104490 & 3) * -8 + 0x20 == 0) {
    iVar9 = iRam02104498;
  }
  uVar1 = iVar9 + 4U & 3;
  uVar5 = *(uint *)(iVar9 + 4U & 0xfffffffc);
  *(uint *)(iVar9 + 4) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffe0ffff;
  uVar1 = iVar9 + 4U & 3;
  uVar5 = *(uint *)(iVar9 + 4U & 0xfffffffc);
  *(uint *)(iVar9 + 4) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20 | (uint)uVar2 << 0x10;
  return;
}

