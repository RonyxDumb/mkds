/* Decompiled C draft; module arm9_ov000; ROM address 021afd8c. No matching claim. */
#include "types.h"
#include "deps/021afd8c_FUN_021afd8c.h"

void FUN_021afd8c(void)

{
  uint *puVar1;
  uint uVar2;
  
  func_0x0200fca0();
  puVar1 = DAT_021afdc0;
  uVar2 = *DAT_021afdc0;
  uVar2 = uVar2 + (uint)*(byte *)(*DAT_021afdc4 + uVar2) +
                  (uint)*(byte *)(*DAT_021afdc4 + uVar2 + 1) * 0x100;
  *DAT_021afdc0 = uVar2;
  if (*DAT_021afdc8 <= uVar2) {
    *puVar1 = 0;
  }
  func_0x0200fcb4();
  return;
}

