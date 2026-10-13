/* Decompiled C draft; module arm9; ROM address 0208be00. No matching claim. */
#include "types.h"
#include "deps/0208be00_func_0208be00.h"

void func_0208be00(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = GetDriverEntry(param_2);
  *(undefined4 *)(param_1 + 0x154) = 0;
  uVar2 = param_1 + 0x154U & 3;
  uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
  func_0207e594(param_1,uVar1,uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  func_0207d814((uint *)(uintptr_t)(param_1 + 0xe8),param_1);
  uVar2 = (*(uint *)(uRam0208be78 & 0xfffffffc) >> (uRam0208be78 & 3) * 8 |
          *(uint *)(uRam0208be78 & 0xfffffffc) << (uRam0208be78 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 4) {
    *(undefined4 *)(param_1 + 0x114) = 1;
    *(undefined2 *)(param_1 + 0x118) = 4;
    return;
  }
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined2 *)(param_1 + 0x118) = 0;
  return;
}

