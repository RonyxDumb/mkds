/* Decompiled C draft; module arm9_ov003; ROM address 021c812c. No matching claim. */
#include "types.h"
#include "deps/021c812c_FUN_021c812c.h"

void FUN_021c812c(void)

{
  int iVar1;
  int iVar2;
  
  if ((byte)(*DAT_021c81a8 - 0xbU) < 3) {
    FUN_021c81b8();
    return;
  }
  iVar1 = FUN_021cdb6c();
  iVar2 = func_0x02147d30(*DAT_021c81ac,0x1d);
  iVar2 = (uint)*DAT_021c81b0 + iVar2;
  if (iVar2 == 2) {
    if (*(char *)(iVar1 + 0xf5) == '\0') {
      *DAT_021c81a8 = '\x03';
    }
    else {
      *DAT_021c81a8 = '\x02';
    }
  }
  else if (iVar2 == 6) {
    if (*(char *)(iVar1 + 0xf6) == '\0') {
      *DAT_021c81a8 = '\b';
    }
    else {
      *DAT_021c81a8 = '\a';
    }
  }
  else {
    *DAT_021c81a8 = *(char *)(DAT_021c81b4 + iVar2);
  }
  FUN_021c81b8();
  return;
}

