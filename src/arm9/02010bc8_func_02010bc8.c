/* Decompiled C draft; module arm9; ROM address 02010bc8. No matching claim. */
#include "types.h"
#include "deps/02010bc8_func_02010bc8.h"

void func_02010bc8(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    *param_1 = param_2;
    return;
  }
  uVar4 = uVar5 + 0x10 & 3;
  uVar3 = *(uint *)(uVar5 + 0x10 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 == 0) {
    if (*(byte *)(uVar5 + 0x18) <= *(byte *)(param_2 + 0x18)) {
      *(uint *)(uVar5 + 0x10) = param_2;
      return;
    }
    uVar4 = param_2 + 0x10 & 3;
    uVar2 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
    uVar3 = param_2;
    if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
      do {
        uVar4 = uVar3 + 0x10 & 3;
        uVar3 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
        uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = uVar3 + 0x10 & 3;
        uVar2 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
      } while (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0);
    }
    *(uint *)(uVar3 + 0x10) = uVar5;
    *param_1 = param_2;
    return;
  }
  if (uVar4 != 0) {
    uVar3 = uVar5;
    do {
      uVar5 = uVar4;
      if (*(byte *)(param_2 + 0x18) <= *(byte *)(uVar5 + 0x18)) {
        uVar4 = param_2 + 0x10 & 3;
        uVar1 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
        uVar2 = param_2;
        if (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) {
          do {
            uVar4 = uVar2 + 0x10 & 3;
            uVar2 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
            uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
            uVar4 = uVar2 + 0x10 & 3;
            uVar1 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
          } while (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0);
        }
        *(uint *)(uVar3 + 0x10) = param_2;
        *(uint *)(uVar2 + 0x10) = uVar5;
        return;
      }
      uVar4 = uVar5 + 0x10 & 3;
      uVar3 = *(uint *)(uVar5 + 0x10 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar3 = uVar5;
    } while (uVar4 != 0);
  }
  *(uint *)(uVar5 + 0x10) = param_2;
  return;
}

