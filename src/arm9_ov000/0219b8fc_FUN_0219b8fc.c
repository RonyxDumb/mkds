/* Decompiled C draft; module arm9_ov000; ROM address 0219b8fc. No matching claim. */
#include "types.h"
#include "deps/0219b8fc_FUN_0219b8fc.h"

undefined4 FUN_0219b8fc(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (0 < param_2) {
    do {
      if (param_1 == *(int *)(*DAT_0219b94c + uVar2 * 4 + DAT_0219b950)) break;
      uVar2 = uVar2 + 1 & 0xff;
    } while ((int)uVar2 < param_2);
  }
  if (param_2 <= (int)uVar2) {
    return 0;
  }
  FUN_0219b9d4(*(undefined1 *)(*DAT_0219b94c + uVar2 + DAT_0219b954));
  FUN_0219b9b4();
  uVar1 = FUN_0219b958();
  return uVar1;
}

