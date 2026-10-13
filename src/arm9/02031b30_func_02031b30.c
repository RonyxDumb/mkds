/* Decompiled C draft; module arm9; ROM address 02031b30. No matching claim. */
#include "types.h"
#include "deps/02031b30_func_02031b30.h"

void func_02031b30(int param_1)

{
  int iVar1;
  
  iVar1 = *piRam02031b64;
  *(int *)(*(int *)(iVar1 + 0x58) + iRam02031b68) = param_1;
  func_02124100(8,param_1 != 0,*(undefined4 *)(iVar1 + 0x54),*(undefined4 *)(iVar1 + 0x58),
                *(undefined4 *)(iVar1 + 0x4c));
  return;
}

