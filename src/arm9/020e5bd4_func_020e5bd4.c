/* Decompiled C draft; module arm9; ROM address 020e5bd4. No matching claim. */
#include "types.h"
#include "deps/020e5bd4_func_020e5bd4.h"

void func_020e5bd4(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  *(short *)(param_2 + 0xb8) = *(short *)(param_2 + 0xb8) + 1;
  if (((*(ushort *)(param_2 + 0xb8) & 0x1f) == 0) &&
     (uVar1 = param_2 + 0x78U & 3, uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
     ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 4) == 0)) {
    uVar1 = param_2 + 0x70U & 3;
    uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = iRam020e5c64 + 0x68U & 3;
    uVar2 = *(uint *)(iRam020e5c64 + 0x68U & 0xfffffffc);
    if (uVar3 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
      local_10 = 2;
    }
    else {
      uVar1 = iRam020e5c64 + 0x8cU & 3;
      uVar2 = *(uint *)(iRam020e5c64 + 0x8cU & 0xfffffffc);
      if (uVar3 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
        local_10 = 3;
      }
      else {
        local_10 = 4;
      }
    }
    local_14 = param_2 + 4;
    local_18 = uRam020e5c68;
    local_c = func_020d4ef4();
    func_0210b7a8((uint)(uintptr_t)(&local_18));
  }
  StateDualHandler_Execute(param_2 + 0x80);
  return;
}

