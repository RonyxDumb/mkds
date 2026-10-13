/* Decompiled C draft; module arm9_ov003; ROM address 021b8160. No matching claim. */
#include "types.h"
#include "deps/021b8160_func_ov003_021b8160.h"

undefined4
func_ov003_021b8160(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                   undefined4 param_5,undefined4 param_6,int param_7)

{
  int iVar1;
  undefined1 auStack_28 [8];
  int local_20;
  
  local_20 = func_ov003_021ba178(param_3);
  if (local_20 == 0) {
    func_ov003_021b94b8(2);
    return 0xffffffff;
  }
  func_ov003_021b7d90(uRam021b81ec,param_5,2);
  func_ov003_021b7d90(uRam021b81f0,param_6,param_7);
  func_ov003_021b80f4(auStack_28,uRam021b81ec,param_7 + 2,param_3);
  func_ov003_021b80c4(auStack_28,param_2,param_1,param_3);
  iVar1 = func_ov003_021b8050(param_2,param_3);
  if (iVar1 != param_4) {
    func_ov003_021b94b8(0x12);
    func_ov003_021ba164(local_20);
    return 0xffffffff;
  }
  func_ov003_021ba164(local_20);
  return 0;
}

