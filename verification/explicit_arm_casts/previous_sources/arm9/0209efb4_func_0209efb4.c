/* Decompiled C draft; module arm9; ROM address 0209efb4. No matching claim. */
#include "types.h"
#include "deps/0209efb4_func_0209efb4.h"

void func_0209efb4(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_10;
  
  local_10 = 0x1e;
  func_01ff9048(0x14,&local_10,1);
  uVar2 = param_2 + 4U & 3;
  uVar1 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = param_2 + 8U & 3;
  uVar1 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = param_2 + 0xcU & 3;
  uVar1 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) >> 4;
  func_01ff9048(0x19,param_2 + 0x28,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar2 = param_2 + 0xa4U & 3;
  uVar1 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    StructMapObject_MaybeSetNsbcaFrame
              (*(uint *)(uRam0209f0a0 & 0xfffffffc) >> (uRam0209f0a0 & 3) * 8 |
               *(uint *)(uRam0209f0a0 & 0xfffffffc) << (uRam0209f0a0 & 3) * -8 + 0x20,
               *(undefined2 *)(param_2 + 0xa0));
    DrawObject2D3D(param_1,*(uint *)(uRam0209f0a0 & 0xfffffffc) >> (uRam0209f0a0 & 3) * 8 |
                           *(uint *)(uRam0209f0a0 & 0xfffffffc) << (uRam0209f0a0 & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  if (uVar2 != 1) {
    return;
  }
  StructMapObject_MaybeSetNsbcaFrame
            (*(uint *)(uRam0209f0a4 & 0xfffffffc) >> (uRam0209f0a4 & 3) * 8 |
             *(uint *)(uRam0209f0a4 & 0xfffffffc) << (uRam0209f0a4 & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xa0));
  DrawObject2D3D(param_1,*(uint *)(uRam0209f0a4 & 0xfffffffc) >> (uRam0209f0a4 & 3) * 8 |
                         *(uint *)(uRam0209f0a4 & 0xfffffffc) << (uRam0209f0a4 & 3) * -8 + 0x20,
                 param_2);
  return;
}

