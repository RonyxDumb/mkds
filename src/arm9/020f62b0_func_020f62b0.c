/* Decompiled C draft; module arm9; ROM address 020f62b0. No matching claim. */
#include "types.h"
#include "deps/020f62b0_func_020f62b0.h"

void func_020f62b0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (((*(uint *)(uRam020f637c & 0xfffffffc) >> (uRam020f637c & 3) * 8 |
       *(uint *)(uRam020f637c & 0xfffffffc) << (uRam020f637c & 3) * -8 + 0x20) & 1) != 0) {
    func_02108ea0(0);
    uVar1 = GetSomeSndPlayer();
    uVar2 = iRam020f6380 + 0xcU & 3;
    uVar3 = *(uint *)(iRam020f6380 + 0xcU & 0xfffffffc);
    if (uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0) {
      if (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 != 0 ||
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar1,0);
      }
      if (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 != 0 ||
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar1,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar1,0,0xde);
    }
  }
  uVar2 = param_2 + 4U & 3;
  uVar1 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1fc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  DriverContext_InvokeThunderShrink(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  func_020d3cc8();
  func_020f82e8(0);
  func_020f4754((undefined4 *)(uintptr_t)(param_2),1);
  uVar2 = (*(uint *)(uRam020f6384 & 0xfffffffc) >> (uRam020f6384 & 3) * 8 |
          *(uint *)(uRam020f6384 & 0xfffffffc) << (uRam020f6384 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5) {
    func_020fe958(6);
    return;
  }
  return;
}

