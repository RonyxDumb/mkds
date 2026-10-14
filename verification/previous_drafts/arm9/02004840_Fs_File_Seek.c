/* Decompiled C draft; module arm9; ROM address 02004840. No matching claim. */
#include "types.h"
#include "deps/02004840_Fs_File_Seek.h"

undefined4 Fs_File_Seek(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 == 0) {
    uVar1 = param_1 + 0x24U & 3;
    uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar1 = param_2 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  else if (param_3 == 1) {
    uVar1 = param_1 + 0x2cU & 3;
    uVar2 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
    uVar1 = param_2 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  else {
    if (param_3 != 2) {
      return 0;
    }
    uVar1 = param_1 + 0x28U & 3;
    uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar1 = param_2 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  uVar2 = param_1 + 0x24U & 3;
  uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if ((int)uVar1 < (int)uVar2) {
    uVar1 = uVar2;
  }
  uVar2 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if ((int)uVar2 < (int)uVar1) {
    uVar1 = uVar2;
  }
  *(uint *)(param_1 + 0x2c) = uVar1;
  return 1;
}

