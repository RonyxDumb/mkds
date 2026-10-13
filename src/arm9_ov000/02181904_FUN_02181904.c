/* Decompiled C draft; module arm9_ov000; ROM address 02181904. No matching claim. */
#include "types.h"
#include "deps/02181904_FUN_02181904.h"

void FUN_02181904(void)

{
  int iVar1;
  
  iVar1 = func_ov000_021806c4();
  if ((iVar1 == -1) && (*(int *)(*DAT_0218193c + 0x10) == 10)) {
    func_ov000_021806b8(0);
  }
  iVar1 = func_0x0211fd68();
  if (iVar1 != 1) {
    *(undefined4 *)(*DAT_0218193c + 0x10) = 10;
  }
  return;
}

