/* Decompiled C draft; module arm9; ROM address 020049e8. No matching claim. */
#include "types.h"
#include "deps/020049e8_Fs_File_Close.h"

undefined4 Fs_File_Close(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = Fs_File_SendOperation((uint *)(uintptr_t)(param_1),8);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xe;
    uVar1 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffffcf;
    return 1;
  }
  return 0;
}

