/* Decompiled C draft; module arm9_ov003; ROM address 021c5650. No matching claim. */
#include "types.h"
#include "deps/021c5650_FUN_021c5650.h"

void FUN_021c5650(void)

{
  FUN_021bf620(DAT_021c568c,DAT_021c5690);
  *DAT_021c5694 = *DAT_021c5694 & 0xfffc | 3;
  *DAT_021c5698 = *DAT_021c5698 & 0xfffc | 3;
  *DAT_021c569c = *DAT_021c569c & 0xfffc | 3;
  *DAT_021c56a0 = *DAT_021c56a0 & 0xfffc | 3;
  return;
}

