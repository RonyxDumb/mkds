/* Decompiled C draft; module arm7; ROM address 06001224. No matching claim. */
#include "types.h"
#include "deps/06001224_FUN_06001224.h"

void FUN_06001224(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x1544U & 3;
  uVar3 = *(uint *)(iVar2 + 0x1544U & 0xfffffffc);
  uVar6 = iVar2 + 0x1548U & 3;
  uVar8 = *(uint *)(iVar2 + 0x1548U & 0xfffffffc);
  iVar4 = thunk_FUN_037fa04c(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                             uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,0x40);
  *(short *)(iVar4 + 0xc) = (short)DAT_060012b8;
  *(undefined2 *)(iVar4 + 0xe) = 0;
  iVar5 = thunk_FUN_037f9854(iVar2 + 0x28,iVar4);
  if (iVar5 == 0) {
    FUN_06001c98(iVar4);
    uVar1 = iVar2 + 0x154cU & 3;
    uVar6 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
    if (uVar6 >> uVar1 * 8 != 0 || uVar6 << uVar1 * -8 + 0x20 != 0) {
      puVar7 = (undefined2 *)thunk_FUN_03807424();
      *puVar7 = 0x80;
      puVar7[1] = 8;
      puVar7[2] = 0x16;
      puVar7[3] = 0x80;
      thunk_FUN_038074cc();
    }
  }
  return;
}

