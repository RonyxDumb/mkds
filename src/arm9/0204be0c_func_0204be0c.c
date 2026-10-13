/* Decompiled C draft; module arm9; ROM address 0204be0c. No matching claim. */
#include "types.h"
#include "deps/0204be0c_func_0204be0c.h"

void func_0204be0c(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar9;
  code *pcVar8;
  
  uVar1 = uRam0204bf34;
  uVar7 = uRam0204bf34 & 3;
  uVar6 = *(uint *)(uRam0204bf34 & 0xfffffffc);
  *(undefined4 *)(uRam0204bf34 + 4) = 1;
  iVar5 = iRam0204bf38;
  if (uVar6 >> uVar7 * 8 == 0 && uVar6 << uVar7 * -8 + 0x20 == 0) {
    func_02143520(iRam0204bf38 + 0x340);
    func_02007008(*(undefined2 *)(iVar5 + 0x4c4));
    func_02006ddc(1,uRam0204bf3c);
  }
  else {
    uVar7 = uVar1 + 0x10;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    pcVar8 = (code *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    *(undefined4 *)(uVar1 + 0xc) = 2;
    if (pcVar8 != (code *)0x0) {
      (*pcVar8)(0);
    }
  }
  uVar1 = uRam0204bf34;
  uVar7 = *(uint *)(uRam0204bf34 & 0xfffffffc) >> (uRam0204bf34 & 3) * 8;
  iVar5 = *(uint *)(uRam0204bf34 & 0xfffffffc) << (uRam0204bf34 & 3) * -8 + 0x20;
  if (uVar7 == 0 && iVar5 == 0) {
    uVar6 = uRam0204bf34 + 0x2c & 3;
    uVar3 = *(uint *)(uRam0204bf34 + 0x2c & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  }
  else {
    uVar6 = uRam0204bf34 + 0x28 & 3;
    uVar3 = *(uint *)(uRam0204bf34 + 0x28 & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  }
  uVar3 = uRam0204bf34 + 4 & 3;
  uVar4 = *(uint *)(uRam0204bf34 + 4 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    iVar9 = uRam0204bf34 + 0x40;
    if (uVar7 == 0 && iVar5 == 0) {
      uVar2 = func_02006914(iVar9,uVar6 & 0xffff);
    }
    else {
      uVar2 = func_02006954(iVar9);
    }
    iVar5 = func_02144048(uRam0204bf44,0,iVar9,uVar2);
    uVar6 = uRam0204bf34;
    *(uint *)(uVar1 + 8) = (uint)(iVar5 == 2);
    uVar7 = uVar6 + 8 & 3;
    uVar6 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    *(uint *)(uVar1 + 4) = (uint)(uVar6 >> uVar7 * 8 == 0 && uVar6 << uVar7 * -8 + 0x20 == 0);
    return;
  }
  return;
}

