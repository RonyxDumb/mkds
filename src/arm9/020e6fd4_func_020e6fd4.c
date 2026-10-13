/* Decompiled C draft; module arm9; ROM address 020e6fd4. No matching claim. */
#include "types.h"
#include "deps/020e6fd4_func_020e6fd4.h"

void func_020e6fd4(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  byte local_28 [8];
  code *pcVar4;
  
  uVar1 = *(ushort *)(param_1 + 4);
  uVar2 = param_1 + 0x1c & 3;
  uVar3 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  pcVar4 = (code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar5 = *(uint *)(param_1 & 0xfffffffc);
  uVar2 = param_1 + 0x20 & 3;
  uVar3 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  local_28[0] = (byte)(uVar3 >> uVar2 * 8) | (byte)(uVar3 << uVar2 * -8 + 0x20);
  iVar6 = 0;
  local_28[1] = 0;
  if (pcVar4 == (code *)0x0) {
    return;
  }
  if (uVar1 != 0) {
    do {
      uVar2 = (uVar5 >> (param_1 & 3) * 8 | uVar5 << (param_1 & 3) * -8 + 0x20) + iVar6 * 4;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((*(ushort *)(uVar2 + 2) & 0x88) == 0) {
        (*pcVar4)(uVar2,0,local_28,local_28 + 1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)uVar1);
    return;
  }
  return;
}

