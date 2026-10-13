/* Decompiled C draft; module arm9_ov003; ROM address 021be9b8. No matching claim. */
#include "types.h"
#include "deps/021be9b8_FUN_021be9b8.h"

undefined4 FUN_021be9b8(void)

{
  int iVar1;
  
  switch(*DAT_021bea30) {
  default:
    return 0;
  case 1:
    iVar1 = func_0x021a629c(*DAT_021bea34,DAT_021bea38);
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

