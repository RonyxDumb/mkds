/* Decompiled C draft; module arm9; ROM address 0208c0f0. No matching claim. */
#include "types.h"
#include "deps/0208c0f0_func_0208c0f0.h"

void func_0208c0f0(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = GetDriverEntry(param_2);
  *(uint *)(param_1 + 0x154) =
       (uint)((*(ushort *)
                (param_2 * 0x30 +
                 (*(uint *)(uRam0208c168 & 0xfffffffc) >> (uRam0208c168 & 3) * 8 |
                 *(uint *)(uRam0208c168 & 0xfffffffc) << (uRam0208c168 & 3) * -8 + 0x20) + 0x84) & 1
              ) != 0);
  uVar1 = param_1 + 0x154U & 3;
  uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
  func_0207fa74((int *)(uintptr_t)(param_1),uVar2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  func_0207e200((uint *)(uintptr_t)(param_1 + 0xe8),param_1);
  func_0207c448((undefined2 *)(uintptr_t)(param_1 + 0x11c));
  func_0207e088(param_1 + 0xe8,param_1);
  return;
}

