/* Decompiled C draft; module arm9; ROM address 02141538. No matching claim. */
#include "types.h"
#include "deps/02141538_func_02141538.h"

bool func_02141538(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar2 = param_1 + 5U & 3;
  uVar3 = *(uint *)(param_1 + 5U & 0xfffffffc);
  if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff) == 0) {
    uVar2 = param_2 + 5U & 3;
    uVar3 = *(uint *)(param_2 + 5U & 0xfffffffc);
    return ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff) != 0;
  }
  uVar2 = param_2 + 5U & 3;
  uVar3 = *(uint *)(param_2 + 5U & 0xfffffffc);
  if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff) == 0) {
    return false;
  }
  if (*(short *)(param_1 + 2) != *(short *)(param_2 + 2)) {
    return *(short *)(param_1 + 2) < *(short *)(param_2 + 2);
  }
  uVar2 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar7 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff;
  uVar2 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  iVar6 = 0;
  uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff;
  uVar2 = uVar7;
  if (uVar3 < uVar7) {
    uVar2 = uVar3;
  }
  if (uVar2 != 0) {
    do {
      uVar4 = param_2 + iVar6 + 5;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar5 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xff;
      uVar4 = param_1 + iVar6 + 5;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xff;
      if (uVar4 < uVar5) {
        return true;
      }
      if (uVar5 < uVar4) {
        return false;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)uVar2);
  }
  if ((uVar2 == uVar7) && (iVar6 < (int)uVar3)) {
    do {
      uVar2 = param_2 + iVar6 + 5;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xff) != 0) {
        return true;
      }
      iVar6 = iVar6 + 1;
      uVar2 = param_2 + 4U & 3;
      uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
    } while (iVar6 < (int)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff));
  }
  return false;
}

