/* Decompiled C draft; module arm9_ov003; ROM address 021bac0c. No matching claim. */
#include "types.h"
#include "deps/021bac0c_FUN_021bac0c.h"

undefined4 FUN_021bac0c(void)

{
  int iVar1;
  
  switch(*DAT_021bac84) {
  default:
    return 0;
  case 1:
    iVar1 = func_0x021a629c(*DAT_021bac88,DAT_021bac8c);
    if (iVar1 != 3) {
      return 0;
    }
    break;
  case 5:
    iVar1 = func_0x021a61c4(0,0,0);
    if (iVar1 != 3) {
      return 0;
    }
    break;
  case 7:
    iVar1 = func_0x021a5db0();
    if (iVar1 != 3) {
      return 0;
    }
  }
  return 1;
}

