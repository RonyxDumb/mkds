/* Decompiled C draft; module arm9_ov003; ROM address 021ba524. No matching claim. */
#include "types.h"
#include "deps/021ba524_func_ov003_021ba524.h"

undefined4 func_ov003_021ba524(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  
  uVar2 = 0xffffffff;
  iVar1 = FUN_021baa28();
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
    func_0x0200ea3c(uRam021ba55c,&local_18,1);
    if (local_18 == 0xe) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

