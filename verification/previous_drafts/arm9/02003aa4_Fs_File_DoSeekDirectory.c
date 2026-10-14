/* Decompiled C draft; module arm9; ROM address 02003aa4. No matching claim. */
#include "types.h"
#include "deps/02003aa4_Fs_File_DoSeekDirectory.h"

void Fs_File_DoSeekDirectory(int param_1,undefined2 param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 4;
  UNRECOVERED_JUMPTABLE = pcRam02003ad4;
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(uint *)(param_1 + 0x30) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined2 *)(param_1 + 0x36) = 0;
  *(undefined2 *)(param_1 + 0x34) = param_2;
                    /* WARNING: Could not recover jumptable at 0x02003ad0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,2);
  return;
}

