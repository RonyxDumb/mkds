/* Decompiled C draft; module arm9; ROM address 0207fba0. No matching claim. */
#include "types.h"
#include "deps/0207fba0_func_0207fba0.h"

void func_0207fba0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar5 = (*(uint *)(uRam0207fcdc & 0xfffffffc) >> (uRam0207fcdc & 3) * 8 |
          *(uint *)(uRam0207fcdc & 0xfffffffc) << (uRam0207fcdc & 3) * -8 + 0x20) + 8;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar7 = uRam0207fce0;
  if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 2) {
    uVar7 = uRam0207fce8;
  }
  *puRam0207fce4 = uVar7;
  iVar6 = func_020853dc();
  uVar4 = uRam0207fd08;
  uVar3 = uRam0207fd00;
  puVar2 = puRam0207fcf8;
  uVar7 = uRam0207fcf4;
  if (iVar6 == 0) {
    *puRam0207fcf0 = uRam0207fcec;
    *puVar2 = uVar7;
  }
  else if (iVar6 == 1) {
    *puRam0207fcf0 = uRam0207fcfc;
    *puVar2 = uVar3;
  }
  else if (iVar6 == 2) {
    *puRam0207fcf0 = uRam0207fd04;
    *puVar2 = uVar4;
  }
  else {
    *puRam0207fcf0 = uRam0207fd04;
    *puVar2 = uVar4;
  }
  uVar3 = uRam0207fd24;
  puVar2 = puRam0207fd18;
  uVar7 = uRam0207fd14;
  uVar5 = (*(uint *)(uRam0207fcdc & 0xfffffffc) >> (uRam0207fcdc & 3) * 8 |
          *(uint *)(uRam0207fcdc & 0xfffffffc) << (uRam0207fcdc & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  if (uVar5 == 5) {
    *puRam0207fd10 = uRam0207fd0c;
    *puVar2 = uVar7;
    return;
  }
  if (uVar5 == 6) {
    *puRam0207fd10 = uRam0207fd1c;
    *puVar2 = uVar7;
    return;
  }
  *puRam0207fd10 = uRam0207fd20;
  *puVar2 = uVar3;
  return;
}

