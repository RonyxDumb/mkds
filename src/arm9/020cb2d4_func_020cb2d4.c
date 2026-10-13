/* Decompiled C draft; module arm9; ROM address 020cb2d4. No matching claim. */
#include "types.h"
#include "deps/020cb2d4_func_020cb2d4.h"

void func_020cb2d4(void)

{
  int iVar1;
  
  func_020cb340();
  iVar1 = *piRam020cb31c;
  func_02124c30(*(undefined4 *)(iVar1 + iRam020cb324),*(undefined4 *)(iVar1 + iRam020cb328),0,
                iVar1 + iRam020cb32c,*(undefined4 *)(iVar1 + iRam020cb320));
  iVar1 = *piRam020cb31c;
  func_02124c30(*(undefined4 *)(iVar1 + iRam020cb334),*(undefined4 *)(iVar1 + iRam020cb338),0,
                iVar1 + iRam020cb33c,*(undefined4 *)(iVar1 + iRam020cb330));
  return;
}

