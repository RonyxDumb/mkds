/* Decompiled C draft; module arm9; ROM address 020e005c. No matching claim. */
#include "types.h"
#include "deps/020e005c_func_020e005c.h"

void func_020e005c(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  
  uVar4 = param_1 + 0x164U & 3;
  uVar3 = *(uint *)(param_1 + 0x164U & 0xfffffffc);
  if (*(short *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xe) == 0) {
    uVar4 = param_1 + 0x144U & 3;
    uVar3 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    bVar7 = false;
    uVar4 = uVar3 + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if (uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) {
      uVar4 = param_1 + 0x15cU & 3;
      uVar5 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
      if (uVar5 >> uVar4 * 8 == 0 && uVar5 << uVar4 * -8 + 0x20 == 0) {
        uVar4 = param_1 + 0x150U & 3;
        uVar3 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
        if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
          bVar8 = true;
        }
        else {
          bVar8 = false;
        }
      }
      else {
        uVar3 = uVar3 + 4;
        uVar4 = uVar3 & 3;
        uVar5 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = param_1 + 0x150U & 3;
        uVar6 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
        bVar8 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) ==
                (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) - 1;
      }
      if (bVar8) {
        bVar7 = true;
      }
    }
    if (!bVar7) {
      return;
    }
  }
  iVar1 = func_020d8cac();
  iVar2 = iVar1;
  if (0xeff < iVar1) {
    iVar2 = 2;
  }
  if (0xeff < iVar1) {
    *(short *)(param_1 + 0x90) = (short)iVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

