/* Decompiled C draft; module arm9; ROM address 02104c68. No matching claim. */
#include "types.h"
#include "deps/02104c68_func_02104c68.h"

uint func_02104c68(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  func_020f9114(param_2);
  *(ushort *)(param_2 + 0x78) = *(ushort *)(param_2 + 0x78) | *puRam02104d70;
  uVar1 = param_2 + 0x138U & 3;
  uVar2 = *(uint *)(param_2 + 0x138U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar1 = param_2 + 0x134U & 3;
    uVar2 = *(uint *)(param_2 + 0x134U & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xb0) = 1;
  }
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if ((*(ushort *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1ec) & 0x10) == 0) {
    func_020f3150(param_2,param_1,0,0,0x4000,0x3000,uRam02104d74);
    uVar1 = param_1 + 0x68U & 3;
    uVar2 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
    if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0x1000) {
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined4 *)(param_2 + 0x60) = 0;
      *(undefined4 *)(param_2 + 100) = 0;
    }
    *(undefined4 *)(param_2 + 0x130) = 0;
    uVar1 = param_2 + 0x130U & 3;
    uVar2 = *(uint *)(param_2 + 0x130U & 0xfffffffc);
    return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  func_020f3150(param_2,param_1,0,1,0x4000,0x3000,uRam02104d74);
  DriverContext_MaybeQueuePlaySfx(param_2,0xda,0x7f,0);
  *(undefined4 *)(param_2 + 0x130) = 1;
  uVar1 = param_2 + 0x130U & 3;
  uVar2 = *(uint *)(param_2 + 0x130U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

