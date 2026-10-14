/* Decompiled C draft; module arm9; ROM address 0209280c. No matching claim. */
#include "types.h"
#include "deps/0209280c_func_0209280c.h"

void func_0209280c(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_38;
  undefined1 auStack_34 [36];
  
  uVar2 = param_2 + 0xc4U & 3;
  uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  local_38 = 0x1e;
  uVar4 = iRam0209291c - (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_38),1);
  uVar3 = func_020e6cf8(param_2 + 4);
  func_01ff9048(0x19,uVar3,0xc);
  uVar2 = param_2 + 0xccU & 3;
  uVar5 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
  if (uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) {
    iVar1 = (int)(uVar4 & 0xffff) >> 4;
    MTX_RotZ33__from_thumb
              ((undefined4 *)(void *)(auStack_34),(int)*(short *)(iRam02092920 + iVar1 * 4),
               (int)*(short *)(iRam02092920 + (iVar1 * 2 + 1) * 2));
  }
  else {
    iVar1 = (int)(uVar4 * -0x10000 >> 0x10) >> 4;
    MTX_RotZ33__from_thumb
              ((undefined4 *)(void *)(auStack_34),(int)*(short *)(iRam02092920 + iVar1 * 4),
               (int)*(short *)(iRam02092920 + (iVar1 * 2 + 1) * 2));
  }
  func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_34),9);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  StructMapObject_SetNsbtpFrame
            (*(uint *)(uRam02092924 & 0xfffffffc) >> (uRam02092924 & 3) * 8 |
             *(uint *)(uRam02092924 & 0xfffffffc) << (uRam02092924 & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xac));
  DrawObject2D3D(param_1,*(uint *)(uRam02092924 & 0xfffffffc) >> (uRam02092924 & 3) * 8 |
                         *(uint *)(uRam02092924 & 0xfffffffc) << (uRam02092924 & 3) * -8 + 0x20,
                 param_2);
  return;
}

