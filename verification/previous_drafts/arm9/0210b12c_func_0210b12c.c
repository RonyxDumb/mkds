/* Decompiled C draft; module arm9; ROM address 0210b12c. No matching claim. */
#include "types.h"
#include "deps/0210b12c_func_0210b12c.h"

void func_0210b12c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((*(uint *)(uRam0210b194 & 0xfffffffc) >> (uRam0210b194 & 3) * 8 |
      *(uint *)(uRam0210b194 & 0xfffffffc) << (uRam0210b194 & 3) * -8 + 0x20) < 0x78) {
    return;
  }
  iVar1 = StructMQRacerEntry_SomeFn_6(param_1,0,param_2 + 0xc1,0x7f);
  if (iVar1 != 0) {
    *(byte *)(iVar1 + 0x19) = *(byte *)(iVar1 + 0x19) | 0x20;
    *(byte *)(iVar1 + 0x19) = *(byte *)(iVar1 + 0x19) | 0x40;
    return;
  }
  return;
}

