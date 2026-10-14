/* Decompiled C draft; module arm9; ROM address 02094c70. No matching claim. */
#include "types.h"
#include "deps/02094c70_func_02094c70.h"

void func_02094c70(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(short *)(param_2 + 0xac) != 0) {
    GetDriverEntry((short)*(char *)((*(uint *)(uRam02094d94 & 0xfffffffc) >> (uRam02094d94 & 3) * 8
                                    | *(uint *)(uRam02094d94 & 0xfffffffc) <<
                                      (uRam02094d94 & 3) * -8 + 0x20) + 0x62));
    uVar1 = func_020d3c44();
    StructMapObject_MaybeSetPolygonId
              (*(uint *)(uRam02094d98 & 0xfffffffc) >> (uRam02094d98 & 3) * 8 |
               *(uint *)(uRam02094d98 & 0xfffffffc) << (uRam02094d98 & 3) * -8 + 0x20,uVar1);
    StructMapObject_SetNsbtpFrame
              (*(uint *)(uRam02094d98 & 0xfffffffc) >> (uRam02094d98 & 3) * 8 |
               *(uint *)(uRam02094d98 & 0xfffffffc) << (uRam02094d98 & 3) * -8 + 0x20,
               *(undefined2 *)(param_2 + 0xae));
    StructMapObject_SomeFn_6
              (*(uint *)(uRam02094d98 & 0xfffffffc) >> (uRam02094d98 & 3) * 8 |
               *(uint *)(uRam02094d98 & 0xfffffffc) << (uRam02094d98 & 3) * -8 + 0x20,
               *(undefined2 *)(param_2 + 0xac));
    uVar1 = func_0206183c();
    StructMapObject_SomeFn_7
              (*(uint *)(uRam02094d98 & 0xfffffffc) >> (uRam02094d98 & 3) * 8 |
               *(uint *)(uRam02094d98 & 0xfffffffc) << (uRam02094d98 & 3) * -8 + 0x20,uVar1);
    StructMapObject_SomeFn_8
              ((undefined4 *)(uintptr_t)(*(uint *)(uRam02094d98 & 0xfffffffc) >> (uRam02094d98 & 3) * 8 |
               *(uint *)(uRam02094d98 & 0xfffffffc) << (uRam02094d98 & 3) * -8 + 0x20),
               *(undefined2 *)(param_2 + 0xb0),0);
    uStack_20 = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_20),1);
    uVar1 = func_020e6cf8(param_2 + 4);
    func_01ff9048(0x19,uVar1,0xc);
    iVar2 = func_02061818();
    if (iVar2 == 2) {
      uStack_1c = 0x2000;
      uStack_18 = 0x2000;
      uStack_14 = 0x2000;
      func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_1c),3);
    }
    func_01ff9048(0x1b,param_2 + 0x1c,3);
    DrawObject2D3D(param_1,*(uint *)(uRam02094d98 & 0xfffffffc) >> (uRam02094d98 & 3) * 8 |
                           *(uint *)(uRam02094d98 & 0xfffffffc) << (uRam02094d98 & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  return;
}

