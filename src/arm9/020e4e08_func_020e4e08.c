/* Decompiled C draft; module arm9; ROM address 020e4e08. No matching claim. */
#include "types.h"
#include "deps/020e4e08_func_020e4e08.h"

void func_020e4e08(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 uStack_14;
  
  if ((*(short *)(param_2 + 0x8e) != 0) && (*(short *)(param_2 + 0x8e) != 1)) {
    return;
  }
  uVar1 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar2 = param_2 + 0xbcU & 3;
  uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
  local_20 = 0x1000 - ((int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
                            (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) >> 6);
  local_1c = *(undefined4 *)(param_2 + 4);
  uStack_14 = *(undefined4 *)(param_2 + 0xc);
  uVar1 = param_2 + 0xfcU & 3;
  uVar4 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
  uVar2 = param_2 + 0x100U & 3;
  uVar3 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
  local_18 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
             (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  func_020e5634(param_2 + 200,(uint)(uintptr_t)(&local_1c));
  func_020e54e4(param_2 + 200,(uint)(uintptr_t)(&local_20),0,param_4);
  return;
}

