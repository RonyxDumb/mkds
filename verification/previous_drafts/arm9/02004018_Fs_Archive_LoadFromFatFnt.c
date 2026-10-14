/* Decompiled C draft; module arm9; ROM address 02004018. No matching claim. */
#include "types.h"
#include "deps/02004018_Fs_Archive_LoadFromFatFnt.h"

undefined4
Fs_Archive_LoadFromFatFnt
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,int param_7,int param_8)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined4 *)(param_1 + 0x30) = param_4;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  uVar1 = param_1 + 0x3cU & 3;
  uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x38) = param_6;
  *(undefined4 *)(param_1 + 0x40) = param_5;
  uVar1 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  *(uint *)(param_1 + 0x34) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (param_7 == 0) {
    param_7 = iRam02004088;
  }
  *(int *)(param_1 + 0x48) = param_7;
  if (param_8 == 0) {
    param_8 = iRam0200408c;
  }
  *(int *)(param_1 + 0x4c) = param_8;
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x50) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x44) = 0;
  uVar1 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 2;
  return 1;
}

