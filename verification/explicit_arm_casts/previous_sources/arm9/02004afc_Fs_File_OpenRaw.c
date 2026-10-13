/* Decompiled C draft; module arm9; ROM address 02004afc. No matching claim. */
#include "types.h"
#include "deps/02004afc_Fs_File_OpenRaw.h"

undefined4
Fs_File_OpenRaw(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x38) = param_5;
  *(undefined4 *)(param_1 + 0x30) = param_3;
  *(undefined4 *)(param_1 + 0x34) = param_4;
  iVar2 = Fs_File_SendOperation(param_1,7);
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

