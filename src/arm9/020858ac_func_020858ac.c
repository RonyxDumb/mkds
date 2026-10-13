/* Decompiled C draft; module arm9; ROM address 020858ac. No matching claim. */
#include "types.h"
#include "deps/020858ac_func_020858ac.h"

void func_020858ac(int param_1)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  bVar2 = false;
  uVar6 = *(uint *)(uRam02085978 & 0xfffffffc) >> (uRam02085978 & 3) * 8 |
          *(uint *)(uRam02085978 & 0xfffffffc) << (uRam02085978 & 3) * -8 + 0x20;
  uVar3 = uVar6 + param_1 * 0x30 + 0x70;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar3 < 4) && ((1 << (uVar3 & 0xff) & 0xdU) != 0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    return;
  }
  if (*(char *)(uVar6 + 0x58) == '\0') {
    uVar3 = *(uint *)(uRam0208597c & 0xfffffffc) >> (uRam0208597c & 3) * 8 |
            *(uint *)(uRam0208597c & 0xfffffffc) << (uRam0208597c & 3) * -8 + 0x20;
    sVar1 = *(short *)(uVar3 + 0x13c);
    if (0 < sVar1) {
      *(short *)(uVar3 + 0x13c) = sVar1 + -1;
    }
    return;
  }
  uVar3 = uVar6 + param_1 * 0x30 + 0x74;
  uVar4 = uVar3 & 3;
  uVar6 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = 0;
  while (uVar3 != (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20)) {
    uVar3 = (int)((uVar3 + 1) * 0x10000) >> 0x10;
    if (1 < (int)uVar3) {
      return;
    }
  }
  uVar4 = *(uint *)(uRam0208597c & 0xfffffffc) >> (uRam0208597c & 3) * 8 |
          *(uint *)(uRam0208597c & 0xfffffffc) << (uRam0208597c & 3) * -8 + 0x20;
  if (0 < *(short *)(uVar4 + uVar3 * 2 + 0x13e)) {
    iVar5 = uVar4 + iRam02085980;
    *(short *)(iVar5 + uVar3 * 2) = *(short *)(iVar5 + uVar3 * 2) + -1;
    return;
  }
  return;
}

