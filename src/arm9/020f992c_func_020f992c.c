/* Decompiled C draft; module arm9; ROM address 020f992c. No matching claim. */
#include "types.h"
#include "deps/020f992c_func_020f992c.h"

void func_020f992c(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  code *pcVar5;
  
  if (*(short *)(param_1 + 0xda) != -1) {
    uVar1 = func_020d5344();
    *(undefined2 *)(param_1 + 0xda) = uVar1;
  }
  uVar4 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x400000) != 0) {
    func_02109054(param_1);
    *(undefined4 *)(param_1 + 0x30) = 0;
    uVar4 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffbfffff;
  }
  uVar3 = uRam020f99b4;
  uVar4 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 4;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar4 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) * 0xa8 +
          (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x3c;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  pcVar5 = (code *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(param_1);
    return;
  }
  return;
}

