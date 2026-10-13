/* Decompiled C draft; module arm9; ROM address 020935fc. No matching claim. */
#include "types.h"
#include "deps/020935fc_func_020935fc.h"

void func_020935fc(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  
  uVar1 = param_2 + 0xa8U & 3;
  uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    uVar2 = func_020d3c44();
    StructMapObject_MaybeSetPolygonId
              (*(uint *)(uRam020936ec & 0xfffffffc) >> (uRam020936ec & 3) * 8 |
               *(uint *)(uRam020936ec & 0xfffffffc) << (uRam020936ec & 3) * -8 + 0x20,uVar2);
    uStack_28 = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_28),1);
    uVar2 = MaybeGetBBMtxAtPosition(param_2 + 4);
    func_01ff9048(0x19,uVar2,0xc);
    uVar1 = param_2 + 0x5cU & 3;
    uVar3 = *(uint *)(param_2 + 0x5cU & 0xfffffffc);
    iStack_20 = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
    uStack_24 = 0;
    uStack_1c = 0;
    func_01ff9048(0x1c,(undefined4)(uintptr_t)(&uStack_24),3);
    uVar1 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uStack_18 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uStack_14 = uStack_18;
    uStack_10 = uStack_18;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_18),3);
    func_01ff9048(0x1b,param_2 + 0x1c,3);
    StructMapObject_SomeFn_3
              (*(uint *)(uRam020936ec & 0xfffffffc) >> (uRam020936ec & 3) * 8 |
               *(uint *)(uRam020936ec & 0xfffffffc) << (uRam020936ec & 3) * -8 + 0x20,
               *(undefined2 *)(param_2 + 0xa4));
    DrawObject2D3D(param_1,*(uint *)(uRam020936ec & 0xfffffffc) >> (uRam020936ec & 3) * 8 |
                           *(uint *)(uRam020936ec & 0xfffffffc) << (uRam020936ec & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  return;
}

