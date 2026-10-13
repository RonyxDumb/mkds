/* Decompiled C draft; module arm9_ov000; ROM address 021805cc. No matching claim. */
#include "types.h"
#include "deps/021805cc_func_ov000_021805cc.h"

void func_ov000_021805cc(short *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  uVar2 = func_0x02036bec(uVar1,uRam021805f8);
  *puRam021805fc = uVar2;
  FUN_02180844(uVar1,(int)*param_1);
  return;
}

