/* Decompiled C draft; module arm9; ROM address 02004a80. No matching claim. */
#include "types.h"
#include "deps/02004a80_Fs_File_OpenById.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Fs_File_OpenById(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x34) = param_3;
  iVar2 = Fs_File_SendOperation(param_1,6);
  if (iVar2 != 0) {
    uVar1 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x10;
    uVar1 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffffdf;
    return 1;
  }
  return 0;
}

