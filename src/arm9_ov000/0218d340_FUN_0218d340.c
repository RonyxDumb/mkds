/* Decompiled C draft; module arm9_ov000; ROM address 0218d340. No matching claim. */
#include "types.h"
#include "deps/0218d340_FUN_0218d340.h"

void FUN_0218d340(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0218dbc0((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 4)),(undefined4)(uintptr_t)(&local_c));
  (**(code **)(param_1 + DAT_0218d370))(param_1,0,local_c,*(undefined4 *)(param_1 + DAT_0218d36c));
  return;
}

