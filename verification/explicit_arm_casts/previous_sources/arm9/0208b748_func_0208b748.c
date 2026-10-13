/* Decompiled C draft; module arm9; ROM address 0208b748. No matching claim. */
#include "types.h"
#include "deps/0208b748_func_0208b748.h"

void func_0208b748(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  uVar2 = (*(code *)(*(uint *)(uRam0208b7b8 & 0xfffffffc) >> (uRam0208b7b8 & 3) * 8 |
                    *(uint *)(uRam0208b7b8 & 0xfffffffc) << (uRam0208b7b8 & 3) * -8 + 0x20))
                    (&local_24,param_1);
  local_20 = (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                  *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 4;
  uVar1 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  local_1c = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  local_18 = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  func_02018578(uVar2,local_24,&local_20,param_3,param_4);
  return;
}

