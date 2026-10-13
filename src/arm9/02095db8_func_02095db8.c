/* Decompiled C draft; module arm9; ROM address 02095db8. No matching claim. */
#include "types.h"
#include "deps/02095db8_func_02095db8.h"

void func_02095db8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_18;
  
  local_18 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_18),1);
  uVar2 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar2,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar1 = param_2 + 0x78U & 3;
  uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if ((int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x3fffffe0) < iRam02095ea8) {
    StructMapObject_MaybeSetNsbcaFrame
              (*(uint *)(uRam02095eac & 0xfffffffc) >> (uRam02095eac & 3) * 8 |
               *(uint *)(uRam02095eac & 0xfffffffc) << (uRam02095eac & 3) * -8 + 0x20,
               *(undefined2 *)(param_2 + 0xac));
    DrawObject2D3D(param_1,*(uint *)(uRam02095eac & 0xfffffffc) >> (uRam02095eac & 3) * 8 |
                           *(uint *)(uRam02095eac & 0xfffffffc) << (uRam02095eac & 3) * -8 + 0x20,
                   param_2);
  }
  else {
    func_0209ba58(param_1,*(uint *)(uRam02095eac & 0xfffffffc) >> (uRam02095eac & 3) * 8 |
                          *(uint *)(uRam02095eac & 0xfffffffc) << (uRam02095eac & 3) * -8 + 0x20,
                  param_2);
  }
  uVar1 = param_2 + 0x78U & 3;
  uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if ((int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x3fffffe0) < iRam02095eb0) {
    func_020e5668(param_2 + 0xdc,param_2 + 4);
    func_020e53ac(param_2 + 0xdc,0,param_3,param_4);
    return;
  }
  return;
}

