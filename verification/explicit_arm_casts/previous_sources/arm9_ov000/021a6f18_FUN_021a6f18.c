/* Decompiled C draft; module arm9_ov000; ROM address 021a6f18. No matching claim. */
#include "types.h"
#include "deps/021a6f18_FUN_021a6f18.h"

void FUN_021a6f18(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *local_18;
  
  while( true ) {
    func_0x0200e904(param_1,&local_18,1);
    if (local_18 == (undefined4 *)0x0) break;
    uVar1 = (*(code *)*local_18)();
    uVar2 = func_0x0200fca0();
    func_0x0200db9c();
    func_0x0200ea3c(param_1,0,0);
    if (local_18[1] != 0) {
      *(undefined4 *)(local_18[1] + 0x6c) = uVar1;
    }
    if (local_18[2] != 0) {
      func_0x0200eae8(local_18[2],uVar1,0);
    }
    FUN_021a7048(local_18);
    func_0x0200db64();
    func_0x0200fcb4(uVar2);
    func_0x0200de50();
  }
  return;
}

