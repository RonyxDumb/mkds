/* Decompiled C draft; module arm9; ROM address 02004238. No matching claim. */
#include "types.h"
#include "deps/02004238_Fs_Archive_Initialize.h"

void Fs_Archive_Initialize(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  Mem_CpuFill8(param_1,0,0x5c);
  *(undefined4 *)(param_1 + 0x10) = 0;
  uVar1 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x18) = 0;
  uVar1 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

