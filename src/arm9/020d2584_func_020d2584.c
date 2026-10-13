/* Decompiled C draft; module arm9; ROM address 020d2584. No matching claim. */
#include "types.h"
#include "deps/020d2584_func_020d2584.h"

void func_020d2584(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  lVar1 = (longlong)param_2 * (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  *(uint *)(param_1 + 0x5c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if (*(short *)(param_1 + 100) < 0) {
    return;
  }
  uVar3 = param_1 + 0x98U & 3;
  uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020d25dc;
  case 4:
    goto LAB_020d25dc;
  case 5:
LAB_020d25dc:
    uVar3 = VecFx32_Norm(param_1 + 0x58);
    goto LAB_020d25f0;
  }
  uVar3 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
LAB_020d25f0:
  func_020d5148((int)*(short *)(param_1 + 100),uVar3);
  return;
}

