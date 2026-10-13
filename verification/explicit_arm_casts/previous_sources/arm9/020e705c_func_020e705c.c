/* Decompiled C draft; module arm9; ROM address 020e705c. No matching claim. */
#include "types.h"
#include "deps/020e705c_func_020e705c.h"

void func_020e705c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar7;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  code *pcVar6;
  
  uVar4 = param_1 + 0x10 & 3;
  uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  pcVar6 = (code *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  uVar5 = (uint)*(ushort *)(param_1 + 4);
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (pcVar6 == (code *)0x0) {
    iVar7 = 0;
    if (uVar5 == 0) {
      return;
    }
    do {
      uVar1 = uVar4 + iVar7 * 4;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      uVar1 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x94;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
        func_020e71a0();
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar5);
    return;
  }
  uVar1 = param_1 + 0x18 & 3;
  uVar2 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 2) {
    iVar7 = 0;
    if (uVar5 == 0) {
      return;
    }
    do {
      uVar1 = uVar4 + iVar7 * 4;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
      if (((*(ushort *)(uVar1 + 2) & 4) == 0) &&
         ((*pcVar6)(param_1,uVar1), uVar2 = uVar1 + 0x94 & 3,
         uVar3 = *(uint *)(uVar1 + 0x94 & 0xfffffffc),
         uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0)) {
        func_020e71a0(uVar1);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar5);
    return;
  }
  iVar7 = 0;
  if (uVar5 == 0) {
    return;
  }
  do {
    uVar1 = uVar4 + iVar7 * 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if ((*(ushort *)(uVar1 + 2) & 4) == 0) {
      uStack_30 = *(undefined4 *)(uVar1 + 4);
      uStack_2c = *(undefined4 *)(uVar1 + 8);
      uStack_28 = *(undefined4 *)(uVar1 + 0xc);
      (*pcVar6)(param_1,uVar1);
      VecFx32_Subtract(uVar1 + 4,&uStack_30,uVar1 + 0x10);
      uVar2 = uVar1 + 0x94 & 3;
      uVar3 = *(uint *)(uVar1 + 0x94 & 0xfffffffc);
      if (uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0) {
        func_020e71a0(uVar1);
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < (int)uVar5);
  return;
}

