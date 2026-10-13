/* Decompiled C draft; module arm9_ov000; ROM address 021872bc. No matching claim. */
#include "types.h"
#include "deps/021872bc_FUN_021872bc.h"

void FUN_021872bc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x0200dcd8(*(undefined4 *)(DAT_02187334 + 4));
  *(undefined4 *)(param_1 + DAT_02187338) = 0;
  func_0x0200edc0(param_1 + DAT_0218733c);
  func_0x0200edc0(param_1 + DAT_02187340);
  if (*(int *)(param_1 + 0x1c) == 1) {
    *DAT_02187344 = 1;
  }
  else {
    *DAT_02187344 = 0;
  }
  if ((*(int *)(param_1 + DAT_02187348) == 0) ||
     (iVar2 = func_0x0200e070(param_1 + DAT_0218734c), iVar2 != 0)) {
    func_0x0200e28c(param_1 + DAT_0218734c,DAT_02187354,param_1,param_1 + DAT_02187358,DAT_02187350,
                    iVar1 + -1);
    func_0x0200df68(param_1 + DAT_0218734c);
  }
  return;
}

