/* Decompiled C draft; module arm9; ROM address 0209f1c8. No matching claim. */
#include "types.h"
#include "deps/0209f1c8_func_0209f1c8.h"

void func_0209f1c8(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_38;
  undefined1 auStack_34 [40];
  
  local_38 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_38),1);
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
  if (*(ushort *)(param_2 + 0x7e) != 0) {
    iVar1 = (int)(uint)*(ushort *)(param_2 + 0x7e) >> 4;
    MTX_RotY33__from_thumb
              ((undefined4 *)(void *)(auStack_34),(int)*(short *)(iRam0209f2a8 + iVar1 * 4),
               (int)*(short *)(iRam0209f2a8 + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_34),9);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  StructMapObject_SomeFn_3
            (*(uint *)(uRam0209f2ac & 0xfffffffc) >> (uRam0209f2ac & 3) * 8 |
             *(uint *)(uRam0209f2ac & 0xfffffffc) << (uRam0209f2ac & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xa0));
  DrawObject2D3D(param_1,*(uint *)(uRam0209f2ac & 0xfffffffc) >> (uRam0209f2ac & 3) * 8 |
                         *(uint *)(uRam0209f2ac & 0xfffffffc) << (uRam0209f2ac & 3) * -8 + 0x20,
                 param_2);
  return;
}

