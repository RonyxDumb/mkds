/* Decompiled C draft; module arm9_ov003; ROM address 021c2938. No matching claim. */
#include "types.h"
#include "deps/021c2938_FUN_021c2938.h"

undefined4 FUN_021c2938(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_f0 [32];
  int local_d0;
  int local_cc;
  
  switch(*(undefined4 *)*DAT_021c29b4) {
  case 0:
  case 1:
  case 3:
  case 5:
    return 0;
  case 2:
    return 1;
  case 4:
    return 2;
  case 6:
    break;
  case 7:
    param_1 = 4;
  default:
    return param_1;
  }
  iVar1 = FUN_021bb058((undefined4)(uintptr_t)(auStack_f0));
  if (iVar1 != 1) {
    func_0x0200fd1c();
  }
  if (((-1 < local_d0) && (local_d0 < 4)) && (local_cc == 1)) {
    return 3;
  }
  return 5;
}

