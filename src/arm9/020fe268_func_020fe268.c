/* Decompiled C draft; module arm9; ROM address 020fe268. No matching claim. */
#include "types.h"
#include "deps/020fe268_func_020fe268.h"

uint func_020fe268(int param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  func_020f9114(param_2);
  *(ushort *)(param_2 + 0x78) = *(ushort *)(param_2 + 0x78) | *puRam020fe3c4;
  uVar4 = param_1 + 0x68U & 3;
  uVar3 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar2 = (ulonglong)uVar4 * 0x1ec;
  *(uint *)(param_2 + 0x134) =
       ((uint)lVar2 >> 0xc |
       (((int)uVar4 >> 0x1f) * 0x1ec + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000) + iRam020fe3c8;
  uVar4 = param_2 + 0x134U & 3;
  uVar3 = *(uint *)(param_2 + 0x134U & 0xfffffffc);
  if (iRam020fe3cc < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
    *(int *)(param_2 + 0x134) = iRam020fe3cc;
  }
  uVar4 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar1 = *(ushort *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x1ec);
  if ((uVar1 & 0x20) != 0) {
    func_020f3150(param_2,param_1,2,0,0x7800,0x5000,uRam020fe3d0);
    *(undefined4 *)(param_2 + 0x170) = 0x5a;
    *(undefined4 *)(param_2 + 0x130) = 0;
    uVar4 = param_2 + 0x130U & 3;
    uVar3 = *(uint *)(param_2 + 0x130U & 0xfffffffc);
    return uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  if ((uVar1 & 0x10) == 0) {
    func_020f3150(param_2,param_1,3,1,0x6000,0x5000,uRam020fe3d4);
  }
  else {
    func_020f3150(param_2,param_1,3,1,0x9800,0x5000,uRam020fe3d4);
  }
  DriverContext_MaybeQueuePlaySfx(param_2,0xda,0x7f,0);
  *(undefined4 *)(param_2 + 0x130) = 1;
  uVar4 = param_2 + 0x130U & 3;
  uVar3 = *(uint *)(param_2 + 0x130U & 0xfffffffc);
  return uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
}

