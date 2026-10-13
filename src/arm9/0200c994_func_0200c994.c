/* Decompiled C draft; module arm9; ROM address 0200c994. No matching claim. */
#include "types.h"
#include "deps/0200c994_func_0200c994.h"

void func_0200c994(int param_1)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar7;
  code *pcVar6;
  
  iVar7 = param_1 * 0xc;
  uVar1 = iRam0200ca1c + iVar7 & 3;
  uVar5 = *(uint *)(iRam0200ca1c + iVar7 & 0xfffffffc);
  pcVar6 = (code *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  uVar2 = *(ushort *)(iRam0200ca20 + param_1 * 2);
  *(undefined4 *)(iRam0200ca1c + iVar7) = 0;
  uVar1 = 1 << (uVar2 & 0xff);
  if (pcVar6 != (code *)0x0) {
    uVar5 = iRam0200ca24 + iVar7 & 3;
    uVar4 = *(uint *)(iRam0200ca24 + iVar7 & 0xfffffffc);
    (*pcVar6)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  iVar3 = iRam0200ca2c;
  uVar5 = iRam0200ca28 + 0x3ff8U & 3;
  uVar4 = *(uint *)(iRam0200ca28 + 0x3ff8U & 0xfffffffc);
  *(uint *)(iRam0200ca28 + 0x3ff8) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | uVar1;
  uVar5 = iVar3 + iVar7 & 3;
  uVar4 = *(uint *)(iVar3 + iVar7 & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) {
    Os_DisableIrqHandler(uVar1);
    return;
  }
  return;
}

