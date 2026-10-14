/* Decompiled C draft; module arm9; ROM address 020acff4. No matching claim. */
#include "types.h"
#include "deps/020acff4_func_020acff4.h"

void func_020acff4(void)

{
  int iVar1;
  
  func_020ad028();
  iVar1 = *piRam020ad020;
  func_02124c30(*(undefined4 *)(iVar1 + 0x6c),*(undefined4 *)(iVar1 + 0xa8),
                *(undefined4 *)(iVar1 + 0x74),iVar1 + iRam020ad024,*(undefined4 *)(iVar1 + 0x68));
  return;
}

