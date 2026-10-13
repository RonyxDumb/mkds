/* Decompiled C draft; module arm9; ROM address 0210f8b0. No matching claim. */
#include "types.h"
#include "deps/0210f8b0_LoadSomeSseq.h"

void LoadSomeSseq(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  Maybe_helper_10ef34();
  if (param_2 == 4) {
    param_3 = 0x23;
  }
  uVar3 = func_02108950();
  func_0210dccc(param_1,param_2,param_3,0xff,uVar3);
  iVar5 = iRam0210f9a0;
  uVar7 = 0;
  do {
    *(undefined2 *)(iVar5 + uVar7 * 0xc) = 0xffff;
    iVar6 = iVar5 + uVar7 * 0xc;
    *(undefined2 *)(iVar6 + 2) = 0xffff;
    *(undefined4 *)(iVar6 + 4) = 0xffffffff;
    *(char *)(iVar6 + 8) = (char)uVar7;
    puVar1 = puRam0210f9a4;
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 2);
  *puRam0210f9a4 = 1;
  puVar2 = puRam0210f9a4;
  iVar5 = 0;
  do {
    uVar7 = (uint)(puVar1 + iVar5) & 3;
    uVar4 = *(uint *)((uint)(puVar1 + iVar5) & 0xfffffffc);
    if ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) == 1) break;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  puRam0210f9a4[1] = 1;
  iVar5 = 0;
  do {
    uVar7 = (uint)(puVar2 + iVar5) & 3;
    uVar4 = *(uint *)((uint)(puVar2 + iVar5) & 0xfffffffc);
    if ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) == 1) {
      *puRam0210f9a8 = 1;
      return;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  *puRam0210f9a8 = 0;
  return;
}

