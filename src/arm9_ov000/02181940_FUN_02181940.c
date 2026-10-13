/* Decompiled C draft; module arm9_ov000; ROM address 02181940. No matching claim. */
#include "types.h"
#include "deps/02181940_FUN_02181940.h"

void FUN_02181940(void)

{
  int iVar1;
  
  iVar1 = func_0x02125f54();
  if (iVar1 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar1 = func_0x02125f88();
  if (iVar1 != 0) {
    iVar1 = func_0x02125f60();
    if (iVar1 == 0) {
      func_0x0211fd28();
      *(undefined4 *)(*DAT_02181988 + 4) = 7;
      return;
    }
    *(undefined4 *)(*DAT_02181988 + 4) = 1;
  }
  return;
}

