/* Decompiled C draft; module arm9_ov000; ROM address 021a3910. No matching claim. */
#include "types.h"
#include "deps/021a3910_FUN_021a3910.h"

void FUN_021a3910(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  
  if (*DAT_021a3970 == 0) {
    FUN_0219c384(0xb,0xfffffffc);
  }
  else if (*(short *)(*DAT_021a3970 + 4) == 1) {
    func_0x0214d168(&local_10,0,0xc);
    iVar1 = *DAT_021a3970;
    local_8 = (undefined1)*(undefined2 *)(iVar1 + 8);
    local_7 = (undefined1)*(undefined2 *)(iVar1 + 10);
    local_10 = DAT_021a3974;
    local_c = DAT_021a3978;
    *(undefined2 *)(iVar1 + 4) = 2;
    iVar1 = FUN_02188868(&local_10);
    if (iVar1 == 0) {
      FUN_0219c384(0xb,0xfffffffa);
      return;
    }
  }
  return;
}

