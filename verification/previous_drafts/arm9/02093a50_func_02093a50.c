/* Decompiled C draft; module arm9; ROM address 02093a50. No matching claim. */
#include "types.h"
#include "deps/02093a50_func_02093a50.h"

void func_02093a50(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uStack_38;
  undefined1 auStack_34 [40];
  
  uVar2 = param_2 + 0xa0U & 3;
  uVar4 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  if (0 < (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) {
    uStack_38 = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_38),1);
    uVar3 = func_020e6b58(param_2 + 4);
    func_01ff9048(0x19,uVar3,0xc);
    iVar1 = (int)(uint)*(ushort *)(param_2 + 0x7e) >> 4;
    MTX_RotY33__from_thumb
              ((undefined4 *)(void *)(auStack_34),(int)*(short *)(iRam02093b24 + iVar1 * 4),
               (int)*(short *)(iRam02093b24 + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_34),9);
    func_01ff9048(0x1b,param_2 + 0x1c,3);
    DrawObject2D3D(param_1,*(uint *)(uRam02093b28 & 0xfffffffc) >> (uRam02093b28 & 3) * 8 |
                           *(uint *)(uRam02093b28 & 0xfffffffc) << (uRam02093b28 & 3) * -8 + 0x20,
                   param_2);
    DrawObject2D3D(param_1,*(uint *)(uRam02093b2c & 0xfffffffc) >> (uRam02093b2c & 3) * 8 |
                           *(uint *)(uRam02093b2c & 0xfffffffc) << (uRam02093b2c & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  return;
}

