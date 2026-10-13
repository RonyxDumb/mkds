/* Decompiled C draft; module arm9; ROM address 020fb46c. No matching claim. */
#include "types.h"
#include "deps/020fb46c_func_020fb46c.h"

void func_020fb46c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_18 [12];
  
  uVar2 = uRam020fb5d4;
  uVar7 = param_1 + 0x260U & 3;
  uVar6 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  *(uint *)(param_1 + 0x260) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) - 0x7000;
  uVar7 = param_1 + 0x260U & 3;
  uVar6 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  func_020fcce4(param_1,uVar2,uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
  uVar7 = param_1 + 0x260U & 3;
  uVar6 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  if ((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < -0x32000) {
    func_020f7104(param_1,0);
    uVar7 = param_1 + 0x74U & 3;
    uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000000) != 0) {
      uVar7 = param_1 + 0x228U & 3;
      uVar6 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
      func_020fe71c(5,*(undefined2 *)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x1f8),
                    (int)*(short *)(param_1 + 0x4e));
    }
  }
  else {
    iVar4 = param_1 + 0x50;
    uVar7 = param_1 + 0xdcU & 3;
    uVar6 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
    iVar3 = func_01ffdee4((int *)(uintptr_t)(iVar4),(undefined4 *)(uintptr_t)(param_1 + 0xe4),0,uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,4,
                          (int)*(short *)(param_1 + 0xda),(int *)(void *)(auStack_18),0,0,(uint *)(uintptr_t)(param_1 + 0xfc),0,0,0,0);
    if (iVar3 != 0) {
      VecFx32_Add((uint)(uintptr_t)(auStack_18),iVar4,(int *)(uintptr_t)(iVar4));
      func_020f7104(param_1,0);
      uVar7 = param_1 + 0x74U & 3;
      uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000000) != 0) {
        uVar7 = param_1 + 0x228U & 3;
        uVar6 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
        func_020fe71c(5,*(undefined2 *)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x1f8),
                      (int)*(short *)(param_1 + 0x4e));
      }
    }
  }
  uVar7 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  iVar3 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020fb5d8 & 0xfffffffc) >> (uRam020fb5d8 & 3) * 8 |
          *(uint *)(uRam020fb5d8 & 0xfffffffc) << (uRam020fb5d8 & 3) * -8 + 0x20);
  uVar7 = iVar3 + 0x74;
  uVar6 = uVar7 & 3;
  uVar5 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = iVar3 + 0x78;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar3 = func_020fa0b8(param_1,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                        uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  iVar4 = func_020f9ce8(param_1);
  if (iVar4 == 0) {
    if (iVar3 != 0) {
      func_020fa030(param_1);
      return;
    }
    return;
  }
  return;
}

