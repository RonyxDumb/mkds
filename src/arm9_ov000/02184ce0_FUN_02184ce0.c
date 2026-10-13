/* Decompiled C draft; module arm9_ov000; ROM address 02184ce0. No matching claim. */
#include "types.h"
#include "deps/02184ce0_FUN_02184ce0.h"

void FUN_02184ce0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_0x02125f88();
  if (iVar2 == 0) {
    iVar2 = func_0x02125f54();
    if (iVar2 != 0) {
      func_0x02125fc0();
    }
    return;
  }
  iVar2 = func_0x02125f60();
  piVar1 = DAT_02184d44;
  if (iVar2 == 0) {
    *(undefined4 *)(*DAT_02184d44 + 0x10) = 0xe;
    iVar2 = func_ov000_021806c4();
    if (iVar2 == -1) {
      func_ov000_021806b8(8);
    }
    *(undefined4 *)(*DAT_02184d48 + 0x50) = 1;
    return;
  }
  *(undefined4 *)(*DAT_02184d44 + 4) = 1;
  *(undefined4 *)(*piVar1 + 0x10) = 0xffffffff;
  return;
}

