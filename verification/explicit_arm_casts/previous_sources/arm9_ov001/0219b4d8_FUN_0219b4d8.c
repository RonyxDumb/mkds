/* Decompiled C draft; module arm9_ov001; ROM address 0219b4d8. No matching claim. */
#include "types.h"
#include "deps/0219b4d8_FUN_0219b4d8.h"

undefined4 FUN_0219b4d8(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_108;
  undefined1 auStack_104 [260];
  
  local_108 = 0;
  func_0x02135048(auStack_104,DAT_0219b508,DAT_0219b50c,param_1);
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  func_0x02048590(auStack_104,uVar1,&local_108);
  return local_108;
}

