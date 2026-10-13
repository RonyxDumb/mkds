/* Decompiled C draft; module arm9_ov000; ROM address 021a3810. No matching claim. */
#include "types.h"
#include "deps/021a3810_FUN_021a3810.h"

undefined4 FUN_021a3810(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (*DAT_021a387c != 0) {
    iVar3 = FUN_02188758(0);
    piVar1 = DAT_021a387c;
    if (iVar3 == 5) {
      *(undefined2 *)(*DAT_021a387c + 4) = 4;
      *(undefined2 *)(*piVar1 + 6) = 1;
      return 4;
    }
    if (iVar3 < 0) {
      if (-0xb < iVar3) {
        FUN_0219c384(0xb,iVar3 - DAT_021a3880);
        *(undefined2 *)(*DAT_021a387c + 4) = 8;
        return 8;
      }
      FUN_0219c384(5);
      *(undefined2 *)(*DAT_021a387c + 4) = 7;
      return 7;
    }
    uVar2 = 2;
  }
  return uVar2;
}

