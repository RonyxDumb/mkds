/* Decompiled C draft; module arm9; ROM address 020f95d4. No matching claim. */
#include "types.h"
#include "deps/020f95d4_func_020f95d4.h"

void func_020f95d4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uVar8;
  
  if (*(short *)(param_2 + 0xda) == -1) {
    return;
  }
  uVar8 = param_2 + 0x74U & 3;
  uVar7 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if ((uVar8 & 0x1000) != 0) {
    return;
  }
  if (((uVar8 & 0x8000) == 0) &&
     (uVar7 = param_1 + 0x48U & 3, uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
     uVar2 = param_2 + 0x48U & 3, uVar1 = *(uint *)(param_2 + 0x48U & 0xfffffffc),
     (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) <
     (int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20))) {
    return;
  }
  uVar7 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if ((((((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x10000000) != 0) &&
       ((uVar8 & 0x10000000) != 0)) && (iVar3 = func_020f7ea8(param_1,param_2), iVar3 != 1)) &&
     (iVar3 = func_020f7ea8(param_2,param_1), iVar3 != 1)) {
    return;
  }
  uVar8 = param_2 + 0xe0U & 3;
  uVar7 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  iVar3 = func_020f9780(param_1,param_2 + 0x50,uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
  if (iVar3 == 0) {
    uVar8 = param_2 + 0xe0U & 3;
    uVar7 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    iVar3 = func_020f9780(param_1,param_2 + 0xe4,uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
    if (iVar3 == 0) {
      return;
    }
    uVar8 = param_1 + 0xe0U & 3;
    uVar7 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    iVar3 = func_020f9780(param_2,param_1 + 0xe4,uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
    if (iVar3 == 0) {
      return;
    }
  }
  uStack_24 = *(undefined4 *)(param_1 + 0x5c);
  uStack_20 = *(undefined4 *)(param_1 + 0x60);
  uStack_1c = *(undefined4 *)(param_1 + 100);
  uVar4 = func_020f7ea8(param_1,param_2);
  uVar5 = func_020f7ea8(param_2,param_1);
  func_020f77f8(param_1,uVar4,param_2 + 0x50,param_2 + 0x5c);
  func_020f77f8(param_2,uVar5,param_1 + 0x50,&uStack_24);
  uVar8 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 1) {
    func_020f5614(param_1,uVar4,param_2);
  }
  uVar8 = param_2 + 0x44U & 3;
  uVar7 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 1) {
    func_020f5614(param_2,uVar5,param_1);
    return;
  }
  return;
}

