/* Decompiled C draft; module arm9; ROM address 0209f5cc. No matching claim. */
#include "types.h"
#include "deps/0209f5cc_func_0209f5cc.h"

void func_0209f5cc(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  local_10 = 0x1e;
  func_01ff9048(0x14,&local_10,1);
  uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar1,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  StructMapObject_MaybeSetNsbcaFrame
            (*(uint *)(uRam0209f64c & 0xfffffffc) >> (uRam0209f64c & 3) * 8 |
             *(uint *)(uRam0209f64c & 0xfffffffc) << (uRam0209f64c & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xa0));
  DrawObject2D3D(param_1,*(uint *)(uRam0209f64c & 0xfffffffc) >> (uRam0209f64c & 3) * 8 |
                         *(uint *)(uRam0209f64c & 0xfffffffc) << (uRam0209f64c & 3) * -8 + 0x20,
                 param_2);
  return;
}

