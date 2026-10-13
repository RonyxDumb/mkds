/* Decompiled C draft; module arm9_ov000; ROM address 0218e130. No matching claim. */
#include "types.h"
#include "deps/0218e130_FUN_0218e130.h"

void FUN_0218e130(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = 0;
  do {
    func_0x02135014(param_2 + iVar1,DAT_0218e158,*(undefined1 *)(param_1 + uVar2));
    iVar1 = iVar1 + 2;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  return;
}

