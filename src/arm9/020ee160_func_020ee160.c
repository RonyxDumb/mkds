/* Decompiled C draft; module arm9; ROM address 020ee160. No matching claim. */
#include "types.h"
#include "deps/020ee160_func_020ee160.h"

void func_020ee160(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar1 = param_2 + 0x74U & 3;
  uVar6 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  if ((((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x1000) != 0) &&
     (uVar1 = param_1 + 0x48U & 3, uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
     uVar6 = param_2 + 0x48U & 3, uVar2 = *(uint *)(param_2 + 0x48U & 0xfffffffc),
     (int)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) <
     (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20))) {
    return;
  }
  uVar1 = param_2 + 0xe0U & 3;
  uVar6 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  iVar3 = func_020ee284(param_1,param_2 + 0x50,uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  if (iVar3 == 0) {
    uVar1 = param_2 + 0xe0U & 3;
    uVar6 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    iVar3 = func_020ee284(param_1,param_2 + 0xe4,uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    if (iVar3 == 0) {
      return;
    }
    uVar1 = param_1 + 0xe0U & 3;
    uVar6 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    iVar3 = func_020ee284(param_2,param_1 + 0xe4,uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    if (iVar3 == 0) {
      return;
    }
  }
  uStack_1c = *(undefined4 *)(param_1 + 0x5c);
  uStack_18 = *(undefined4 *)(param_1 + 0x60);
  uStack_14 = *(undefined4 *)(param_1 + 100);
  uVar4 = func_020f7ea8(param_1,param_2);
  uVar5 = func_020f7ea8(param_2,param_1);
  func_020f77f8(param_1,uVar4,param_2 + 0x50,param_2 + 0x5c);
  func_020f77f8(param_2,uVar5,param_1 + 0x50,&uStack_1c);
  uVar1 = param_2 + 0x44U & 3;
  uVar6 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  if ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) == 1) {
    func_020f5614(param_2,uVar5,param_1);
    return;
  }
  return;
}

