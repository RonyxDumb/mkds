/* Decompiled C draft; module arm9; ROM address 02004d80. No matching claim. */
#include "types.h"
#include "deps/02004d80_Fs_File_Initialize.h"

void Fs_File_Initialize(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  
  *param_1 = 0;
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  param_1[7] = 0;
  uVar1 = (uint)(param_1 + 7) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
  param_1[6] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[2] = 0;
  param_1[4] = 0xe;
  param_1[3] = 0;
  return;
}

