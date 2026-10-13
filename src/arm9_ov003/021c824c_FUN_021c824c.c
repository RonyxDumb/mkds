/* Decompiled C draft; module arm9_ov003; ROM address 021c824c. No matching claim. */
#include "types.h"
#include "deps/021c824c_FUN_021c824c.h"

void FUN_021c824c(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(*DAT_021c829c + 0x44) != '\0') {
    iVar2 = func_0x02147d30(*DAT_021c82a0,0x1d);
    iVar3 = func_0x02147cd8(*DAT_021c82a0,0x1d);
    uVar1 = DAT_021c82a4;
    *DAT_021c82a8 = (iVar3 + -0x33) * 0x10000 & DAT_021c82a4;
    *DAT_021c82b0 = (iVar3 + -0x33 + (uint)*(byte *)(DAT_021c82ac + iVar2)) * 0x10000 & uVar1;
    *(undefined1 *)(*DAT_021c829c + 0x44) = 0;
  }
  return;
}

