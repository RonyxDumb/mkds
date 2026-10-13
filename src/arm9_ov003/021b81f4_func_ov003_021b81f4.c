/* Decompiled C draft; module arm9_ov003; ROM address 021b81f4. No matching claim. */
#include "types.h"
#include "deps/021b81f4_func_ov003_021b81f4.h"

undefined4
func_ov003_021b81f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4,
                   undefined4 param_5,undefined4 param_6,int param_7)

{
  undefined1 uVar1;
  undefined2 local_28 [2];
  undefined1 auStack_24 [8];
  int local_1c;
  
  uVar1 = func_ov003_021b8050(param_1,param_3);
  *param_4 = uVar1;
  local_1c = func_ov003_021ba178(param_3);
  if (local_1c == 0) {
    return 0xffffffff;
  }
  local_28[0] = func_ov003_021b7bb4();
  func_ov003_021b7d90(param_5,local_28,2);
  func_ov003_021b7d90(uRam021b8270,param_5,2);
  func_ov003_021b7d90(uRam021b8274,param_6,param_7);
  func_ov003_021b80f4((undefined4 *)(void *)(auStack_24),uRam021b8270,param_7 + 2,param_3);
  func_ov003_021b80c4((undefined4)(uintptr_t)(auStack_24),param_2,param_1,param_3);
  func_ov003_021ba164(local_1c);
  return 0;
}

