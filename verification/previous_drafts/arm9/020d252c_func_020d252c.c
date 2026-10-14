/* Decompiled C draft; module arm9; ROM address 020d252c. No matching claim. */
#include "types.h"
#include "deps/020d252c_func_020d252c.h"

uint func_020d252c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x98U & 3;
  uVar1 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  switch(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020d2560;
  case 4:
    goto LAB_020d2560;
  case 5:
LAB_020d2560:
    uVar2 = VecFx32_Norm(param_1 + 0x58);
    return uVar2;
  }
  uVar2 = param_1 + 0x58U & 3;
  uVar1 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  return uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
}

