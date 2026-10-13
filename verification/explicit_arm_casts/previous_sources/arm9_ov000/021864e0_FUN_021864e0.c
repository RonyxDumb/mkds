/* Decompiled C draft; module arm9_ov000; ROM address 021864e0. No matching claim. */
#include "types.h"
#include "deps/021864e0_FUN_021864e0.h"

void FUN_021864e0(void)

{
  int *piVar1;
  int iVar2;
  
  func_0x0200edc0(*DAT_02186540 + DAT_02186544);
  piVar1 = DAT_02186540;
  *(undefined4 *)(*DAT_02186540 + DAT_02186548) = 0;
  if ((*(int *)(*piVar1 + DAT_0218654c) == 0) ||
     (iVar2 = func_0x0200e070(*piVar1 + DAT_02186550), iVar2 != 0)) {
    func_0x0200e28c(*DAT_02186540 + DAT_02186550,DAT_02186558,DAT_02186540,
                    *DAT_02186540 + DAT_0218655c,DAT_02186554,0x10);
    func_0x0200df68(*DAT_02186540 + DAT_02186550);
  }
  return;
}

