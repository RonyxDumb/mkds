/* Decompiled C draft; module arm9; ROM address 02095848. No matching claim. */
#include "types.h"
#include "deps/02095848_func_02095848.h"

void func_02095848(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_38;
  undefined1 auStack_34 [40];
  
  uVar2 = param_2 + 0xb0U & 3;
  uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 2) {
    uStack_38 = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_38),1);
    uVar2 = param_2 + 4U & 3;
    uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
    *(int *)(param_2 + 0x4c) = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
    uVar2 = param_2 + 8U & 3;
    uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(int *)(param_2 + 0x50) = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
    uVar2 = param_2 + 0xcU & 3;
    uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    *(int *)(param_2 + 0x54) = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
    func_01ff9048(0x19,param_2 + 0x28,0xc);
    func_01ff9048(0x1b,param_2 + 0x1c,3);
    DrawObject2D3D(param_1,*(uint *)(uRam0209594c & 0xfffffffc) >> (uRam0209594c & 3) * 8 |
                           *(uint *)(uRam0209594c & 0xfffffffc) << (uRam0209594c & 3) * -8 + 0x20,
                   param_2);
    uVar2 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    uVar2 = FX_Atan2(-(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20),0xc000);
    iVar1 = (int)(uVar2 & 0xffff) >> 4;
    MTX_RotX33__from_thumb
              ((undefined4 *)(void *)(auStack_34),(int)*(short *)(iRam02095950 + iVar1 * 4),
               (int)*(short *)(iRam02095950 + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_34),9);
    DrawObject2D3D(param_1,*(uint *)(uRam02095954 & 0xfffffffc) >> (uRam02095954 & 3) * 8 |
                           *(uint *)(uRam02095954 & 0xfffffffc) << (uRam02095954 & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  return;
}

