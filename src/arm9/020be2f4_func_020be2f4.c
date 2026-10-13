/* Decompiled C draft; module arm9; ROM address 020be2f4. No matching claim. */
#include "types.h"
#include "deps/020be2f4_func_020be2f4.h"

void func_020be2f4(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar2 = GetRaceStartCountdown();
  if (iVar2 < 0x168) {
    return;
  }
  uVar1 = func_020ae5c4(param_1);
  uVar3 = DAT_020be3e0;
  *(undefined2 *)
   ((*(uint *)(DAT_020be3dc & 0xfffffffc) >> (DAT_020be3dc & 3) * 8 |
    *(uint *)(DAT_020be3dc & 0xfffffffc) << (DAT_020be3dc & 3) * -8 + 0x20) + 0xe4) = uVar1;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 8;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  switch(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) {
  case 0:
    goto LAB_020be350;
  case 1:
    break;
  case 2:
    uVar5 = func_020b1dbc();
    switch(uVar5) {
    case 0:
      func_020bd178(param_1);
      goto switchD_020be330_default;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      goto switchD_020be330_default;
    }
    func_020bcbe8(param_1);
    break;
  case 3:
    goto LAB_020be350;
  case 4:
    break;
  case 5:
LAB_020be350:
    func_020bd7f8(param_1);
  }
switchD_020be330_default:
  uVar6 = *(uint *)(DAT_020be3dc & 0xfffffffc) >> (DAT_020be3dc & 3) * 8 |
          *(uint *)(DAT_020be3dc & 0xfffffffc) << (DAT_020be3dc & 3) * -8 + 0x20;
  uVar4 = uVar6 + 0xe8 & 3;
  uVar3 = *(uint *)(uVar6 + 0xe8 & 0xfffffffc);
  param_1 = param_1 + (uint)*(ushort *)(uVar6 + 0xe4) * 0x20;
  *(short *)(param_1 + 6) = (short)((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) >> 4);
  uVar4 = uVar6 + 0xec & 3;
  uVar3 = *(uint *)(uVar6 + 0xec & 0xfffffffc);
  *(short *)(param_1 + 0xe) = (short)((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) >> 4);
  uVar4 = uVar6 + 0xf0 & 3;
  uVar3 = *(uint *)(uVar6 + 0xf0 & 0xfffffffc);
  *(short *)(param_1 + 0x16) = (short)((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) >> 4);
  uVar4 = uVar6 + 0xf4 & 3;
  uVar3 = *(uint *)(uVar6 + 0xf4 & 0xfffffffc);
  *(short *)(param_1 + 0x1e) = (short)((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) >> 4);
  return;
}

