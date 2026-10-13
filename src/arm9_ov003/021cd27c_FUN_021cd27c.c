/* Decompiled C draft; module arm9_ov003; ROM address 021cd27c. No matching claim. */
#include "types.h"
#include "deps/021cd27c_FUN_021cd27c.h"

void FUN_021cd27c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_021cd2a0;
  if (*DAT_021cd29c != 0) {
    do {
      iVar2 = func_0x02143280();
    } while (iVar2 != iVar1);
    FUN_021d2808(DAT_021cd29c);
  }
  return;
}

