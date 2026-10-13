/* Decompiled C draft; module arm9; ROM address 0211003c. No matching claim. */
#include "types.h"
#include "deps/0211003c_func_0211003c.h"

void func_0211003c(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (((*(uint *)(uRam021100c8 & 0xfffffffc) >> (uRam021100c8 & 3) * 8 |
       *(uint *)(uRam021100c8 & 0xfffffffc) << (uRam021100c8 & 3) * -8 + 0x20) & 1) == 0) {
    return;
  }
  uVar1 = iRam021100cc + 0xcU & 3;
  uVar2 = *(uint *)(iRam021100cc + 0xcU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    if (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 != 0 ||
        *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20 != 0) {
      func_0212c6f0(param_2,0);
    }
    if (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 != 0 ||
        *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20 != 0) {
      func_0212c6f0(param_2,0);
    }
    NNSi_MaybeSndPlayerStartSeq(param_2,0,param_1);
    return;
  }
  return;
}

