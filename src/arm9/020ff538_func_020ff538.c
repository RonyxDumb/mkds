/* Decompiled C draft; module arm9; ROM address 020ff538. No matching claim. */
#include "types.h"
#include "deps/020ff538_func_020ff538.h"

uint func_020ff538(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  func_020f9114(param_2);
  uVar2 = uRam020ff630;
  *(ushort *)(param_2 + 0x78) = *(ushort *)(param_2 + 0x78) | *puRam020ff62c;
  MTX_Concat33(uVar2,(uint *)(uintptr_t)(param_2 + 0x94),(uint *)(uintptr_t)(param_2 + 0x94));
  *(undefined4 *)(param_2 + 0x130) = 0;
  *(undefined4 *)(param_2 + 0x134) = 0;
  *(undefined4 *)(param_2 + 0x138) = 0;
  uVar1 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if ((*(ushort *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x1ec) & 0x10) != 0) {
    func_020f3150(param_2,param_1,0,1,0x4000,0x3000,uRam020ff634);
    DriverContext_MaybeQueuePlaySfx(param_2,0xda,0x7f,0);
    *(undefined4 *)(param_2 + 0x13c) = 1;
    uVar1 = param_2 + 0x13cU & 3;
    uVar3 = *(uint *)(param_2 + 0x13cU & 0xfffffffc);
    return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  func_020f3150(param_2,param_1,0,0,0x4000,0x3000,uRam020ff634);
  *(undefined4 *)(param_2 + 0x13c) = 0;
  uVar1 = param_2 + 0x13cU & 3;
  uVar3 = *(uint *)(param_2 + 0x13cU & 0xfffffffc);
  return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
}

