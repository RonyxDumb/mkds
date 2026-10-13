/* Decompiled C draft; module arm9_ov000; ROM address 0218cd94. No matching claim. */
#include "types.h"
#include "deps/0218cd94_FUN_0218cd94.h"

void FUN_0218cd94(int *param_1,undefined4 param_2,int *param_3)

{
  undefined1 *puVar1;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  puVar1 = (undefined1 *)*param_1;
  local_c = (undefined1)param_2;
  *puVar1 = local_c;
  local_b = (undefined1)((uint)param_2 >> 8);
  puVar1[1] = local_b;
  local_a = (undefined1)((uint)param_2 >> 0x10);
  puVar1[2] = local_a;
  local_9 = (undefined1)((uint)param_2 >> 0x18);
  puVar1[3] = local_9;
  *param_3 = *param_3 + 4;
  *param_1 = *param_1 + 4;
  return;
}

