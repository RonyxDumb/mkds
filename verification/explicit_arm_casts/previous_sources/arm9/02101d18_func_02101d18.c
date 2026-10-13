/* Decompiled C draft; module arm9; ROM address 02101d18. No matching claim. */
#include "types.h"
#include "deps/02101d18_func_02101d18.h"

void func_02101d18(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x10U & 3;
  uVar1 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  StructMQRacerEntry_SomeFn_54(uVar2);
  func_020f8e3c(uVar2,0xf6);
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  func_020f81b8(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,0x10);
  LightInfo_SomeFn(param_2 + 0x7c,1);
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if ((*(ushort *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1ec) & 0x20) == 0) {
    *(undefined4 *)(param_2 + 0x148) = 1;
  }
  else {
    *(undefined4 *)(param_2 + 0x148) = 0;
  }
  StateDualHandler_SetState(param_2 + 300,0);
  *(undefined4 *)(param_2 + 0x24c) = 1;
  return;
}

