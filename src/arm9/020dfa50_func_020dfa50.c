/* Decompiled C draft; module arm9; ROM address 020dfa50. No matching claim. */
#include "types.h"
#include "deps/020dfa50_func_020dfa50.h"

void func_020dfa50(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  StateDualHandler_Execute(param_2 + 0x80);
  uVar2 = param_2 + 0xf0U & 3;
  uVar1 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
    return;
  }
  if ((*(ushort *)(param_2 + 2) & 0x12) == 0) {
    uVar2 = param_2 + 0xe8U & 3;
    uVar1 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar3 + 0x24;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffff7;
    uVar2 = param_2 + 0xecU & 3;
    uVar1 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
    uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar3 + 0x24;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffff7;
    uVar2 = param_2 + 0xe8U & 3;
    uVar1 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    func_0208b5b0(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,param_2 + 4);
    uVar2 = param_2 + 0xecU & 3;
    uVar1 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
    func_0208b5b0(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,param_2 + 4);
    return;
  }
  uVar2 = param_2 + 0xe8U & 3;
  uVar1 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
  uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 + 0x24;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar3 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
  uVar2 = param_2 + 0xecU & 3;
  uVar1 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 + 0x24;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar3 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
  return;
}

