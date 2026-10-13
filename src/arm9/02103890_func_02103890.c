/* Decompiled C draft; module arm9; ROM address 02103890. No matching claim. */
#include "types.h"
#include "deps/02103890_func_02103890.h"

void func_02103890(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = puRam021038ec;
  if (param_1 ==
      *(char *)((*(uint *)(uRam021038e4 & 0xfffffffc) >> (uRam021038e4 & 3) * 8 |
                *(uint *)(uRam021038e4 & 0xfffffffc) << (uRam021038e4 & 3) * -8 + 0x20) + 0x62)) {
    *puRam021038e8 = 0;
    *puVar1 = 0;
    uVar2 = func_02108e6c(6);
    func_0212c6f0(uVar2,1);
    return;
  }
  return;
}

