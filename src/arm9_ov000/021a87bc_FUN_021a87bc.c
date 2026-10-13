/* Decompiled C draft; module arm9_ov000; ROM address 021a87bc. No matching claim. */
#include "types.h"
#include "deps/021a87bc_FUN_021a87bc.h"

int FUN_021a87bc(void)

{
  int iVar1;
  
  if (*DAT_021a8820 == 0) {
    *DAT_021a8820 = *DAT_021a8824;
  }
  iVar1 = FUN_021a86e8();
  while (iVar1 == -0x1a) {
    func_0x0200dc3c(100);
    iVar1 = FUN_021a86e8();
  }
  iVar1 = FUN_021a70b0();
  if (-1 < iVar1) {
    FUN_021b026c();
    FUN_021b02b0(0);
    if (*(int *)(*DAT_021a8828 + 0x28) == 0) {
      (**(code **)(*DAT_021a8828 + 0x1c))(*(undefined4 *)(DAT_021a882c + 0x1c));
    }
    *DAT_021a8828 = 0;
  }
  return iVar1;
}

