/* Decompiled C draft; module arm9_ov003; ROM address 021b8278. No matching claim. */
#include "types.h"
#include "deps/021b8278_func_ov003_021b8278.h"

void func_ov003_021b8278(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 uStack_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined4 local_1c;
  
  func_ov003_021b7d84(&uStack_20,0,8);
  local_1f = 2;
  local_1e = func_ov003_021b7c94(uRam021b82d8);
  local_1c = func_ov003_021b7cac(*(undefined4 *)(iRam021b82dc + 0x10));
  if ((param_3 == 0xff) || (*(char *)(iRam021b82dc + 0x18) == '\0')) {
    local_1c = 0xffffffff;
  }
  func_ov003_021b7d04(param_4,param_1,param_2,0,&uStack_20,8);
  return;
}

