/* Decompiled C draft; module arm7; ROM address 06000d04. No matching claim. */
#include "types.h"
#include "deps/06000d04_FUN_06000d04.h"

void FUN_06000d04(int param_1)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  short *psVar8;
  
  iVar3 = FUN_06000680();
  uVar1 = iVar3 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  psVar8 = (short *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  if ((psVar8[0x6d] == 1) && (*(short *)(param_1 + 0x10) == 0x20)) {
    uVar5 = thunk_FUN_037faf70();
    thunk_FUN_037fa564(psVar8 + 0x2c);
    psVar8[0x42] = 0;
    thunk_FUN_037faf84(uVar5);
    psVar8[0x45] = 0;
    FUN_06006f18(1);
    puVar6 = (undefined2 *)thunk_FUN_03807424();
    *puVar6 = 0x80;
    puVar6[1] = 0;
    puVar6[2] = 0x17;
    puVar6[3] = 1;
    thunk_FUN_038074cc();
  }
  else {
    puVar7 = (undefined4 *)FUN_06000000();
    if (puVar7 == (undefined4 *)0x0) {
      iVar3 = 0;
    }
    else {
      *puVar7 = 0x25;
      puVar7[2] = DAT_06000e3c;
      sVar2 = *psVar8;
      if ((sVar2 == 9) || (sVar2 == 7)) {
        puVar7[1] = DAT_06000e40;
      }
      else if ((sVar2 == 10) || (sVar2 == 8)) {
        puVar7[1] = 1;
      }
      iVar3 = FUN_06000680();
      iVar3 = thunk_FUN_037f9854(iVar3 + 0x88,puVar7,0);
    }
    if (iVar3 == 0) {
      puVar6 = (undefined2 *)thunk_FUN_03807424();
      *puVar6 = 0x80;
      puVar6[1] = 8;
      puVar6[2] = 0x16;
      puVar6[3] = 0x25;
      thunk_FUN_038074cc();
    }
  }
  return;
}

