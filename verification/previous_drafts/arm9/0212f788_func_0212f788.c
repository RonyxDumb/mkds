/* Decompiled C draft; module arm9; ROM address 0212f788. No matching claim. */
#include "types.h"
#include "deps/0212f788_func_0212f788.h"

int func_0212f788(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((int)param_2 < 0) {
    return 0;
  }
  uVar2 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (param_2 < (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
    uVar2 = param_1 + 0x20 + param_2 * 0xc;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    iVar1 = param_1 + 0x20 + param_2 * 0xc;
    if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 0xffffffff) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 0;
}

