/* Decompiled C draft; module arm9_ov003; ROM address 021c5944. No matching claim. */
#include "types.h"
#include "deps/021c5944_FUN_021c5944.h"

void FUN_021c5944(void)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(*DAT_021c5980 + 0x56) != '\0') {
    iVar1 = func_0x02147cd8(*DAT_021c5984,0x1c);
    uVar2 = (iVar1 + -0x32) * 0x10000 & DAT_021c5988;
    *DAT_021c598c = uVar2;
    *DAT_021c5990 = uVar2;
    *(undefined1 *)(*DAT_021c5980 + 0x56) = 0;
  }
  return;
}

