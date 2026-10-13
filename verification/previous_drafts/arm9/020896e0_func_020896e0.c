/* Decompiled C draft; module arm9; ROM address 020896e0. No matching claim. */
#include "types.h"
#include "deps/020896e0_func_020896e0.h"

void func_020896e0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  func_02088d34();
  uVar2 = param_1 + 0xc4U & 3;
  uVar1 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    func_0207e668(param_1);
  }
  func_02089494(param_1);
  uVar2 = (*(uint *)(uRam02089750 & 0xfffffffc) >> (uRam02089750 & 3) * 8 |
          *(uint *)(uRam02089750 & 0xfffffffc) << (uRam02089750 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    func_02088e44(param_1);
    return;
  }
  uVar2 = param_1 + 0xd0U & 3;
  uVar1 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
    func_02088e44(param_1);
  }
  func_02088a0c(param_1);
  return;
}

