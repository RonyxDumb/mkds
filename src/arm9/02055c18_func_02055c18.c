/* Decompiled C draft; module arm9; ROM address 02055c18. No matching claim. */
#include "types.h"
#include "deps/02055c18_func_02055c18.h"

void func_02055c18(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = func_02049838();
  if (iVar1 == 2) {
    uVar2 = *(uint *)(uRam02055c58 & 0xfffffffc) >> (uRam02055c58 & 3) * 8 |
            *(uint *)(uRam02055c58 & 0xfffffffc) << (uRam02055c58 & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 8) = *(ushort *)(uVar2 + 8) | 4;
    BrightCtx_SomeFn_0(param_1,1);
    return;
  }
  return;
}

