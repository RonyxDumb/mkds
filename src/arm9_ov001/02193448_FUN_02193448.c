/* Decompiled C draft; module arm9_ov001; ROM address 02193448. No matching claim. */
#include "types.h"
#include "deps/02193448_FUN_02193448.h"

void FUN_02193448(void)

{
  int iVar1;
  
  iVar1 = FUN_02192e84();
  if ((iVar1 == -1) && (*(int *)(*DAT_02193488 + 0x10) == 4)) {
    FUN_02192e78(0);
  }
  iVar1 = func_0x02125f54();
  if (iVar1 != 0) {
    func_0x02125ebc(0x23);
    func_0x02125fc0();
    *(undefined4 *)(*DAT_02193488 + 0x10) = 4;
  }
  return;
}

