/* Decompiled C draft; module arm9; ROM address 0210045c. No matching claim. */
#include "types.h"
#include "deps/0210045c_func_0210045c.h"

void func_0210045c(int param_1)

{
  uint uVar1;
  
  func_020f8e78();
  LightInfo_SomeFn((ushort *)(uintptr_t)(param_1 + 0x7c),1);
  StateDualHandler_SetState(param_1 + 300,0);
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar1 = 8;
  }
  func_020f81b8(uVar1 * 0x210 +
                (*(uint *)(uRam021004c0 & 0xfffffffc) >> (uRam021004c0 & 3) * 8 |
                *(uint *)(uRam021004c0 & 0xfffffffc) << (uRam021004c0 & 3) * -8 + 0x20),0x10);
  return;
}

