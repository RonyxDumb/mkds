/* Decompiled C draft; module arm9_ov000; ROM address 0219dabc. No matching claim. */
#include "types.h"
#include "deps/0219dabc_FUN_0219dabc.h"

undefined4 FUN_0219dabc(void)

{
  int iVar1;
  
  iVar1 = *DAT_0219db0c;
  if (*(char *)(iVar1 + 0x15) == '\x02') {
    return 1;
  }
  if (*(char *)(iVar1 + 0x15) != '\x03') {
    *(char *)(iVar1 + DAT_0219db10) = *(char *)(iVar1 + DAT_0219db10) + '\x01';
  }
  if ((*(char *)(*DAT_0219db0c + 0x15) != '\x03') && (*(byte *)(*DAT_0219db0c + DAT_0219db10) < 5))
  {
    return 1;
  }
  FUN_021a1a38(6,DAT_0219db14);
  return 0;
}

