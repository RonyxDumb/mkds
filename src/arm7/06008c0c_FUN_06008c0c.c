/* Decompiled C draft; module arm7; ROM address 06008c0c. No matching claim. */
#include "types.h"
#include "deps/06008c0c_FUN_06008c0c.h"

void FUN_06008c0c(void)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(DAT_06008c8c & 0xfffffffc) >> (DAT_06008c8c & 3) * 8 |
          *(uint *)(DAT_06008c8c & 0xfffffffc) << (DAT_06008c8c & 3) * -8 + 0x20;
  uVar5 = 0;
  *(undefined2 *)(uVar7 + 0x10) = 0;
  *(undefined2 *)(uVar7 + 0x12) = 0;
  uVar2 = (undefined2)DAT_06008c90;
  do {
    iVar3 = uVar7 + uVar5 * 2;
    *(undefined2 *)(iVar3 + 8) = uVar2;
    *(undefined2 *)(uVar7 + uVar5 * 2) = *(undefined2 *)(iVar3 + 8);
    iVar3 = DAT_06008c94;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 4);
  uVar5 = 0;
  uVar2 = (undefined2)DAT_06008c90;
  do {
    iVar6 = uVar7 + uVar5 * 8;
    *(undefined2 *)(iVar6 + 0xbc) = uVar2;
    *(undefined2 *)(iVar6 + 0xbe) = 0;
    uVar4 = iVar3 + uVar5 * 4;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(iVar6 + 0xc0) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x18);
  FUN_06008a8c(3,0xc);
  return;
}

