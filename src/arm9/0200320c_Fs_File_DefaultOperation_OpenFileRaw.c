/* Decompiled C draft; module arm9; ROM address 0200320c. No matching claim. */
#include "types.h"
#include "deps/0200320c_Fs_File_DefaultOperation_OpenFileRaw.h"

undefined4 Fs_File_DefaultOperation_OpenFileRaw(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x30U & 3;
  uVar2 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x30U & 3;
  uVar2 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x34U & 3;
  uVar2 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x38U & 3;
  uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  *(uint *)(param_1 + 0x20) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return 0;
}

