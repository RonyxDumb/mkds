/* Decompiled C draft; module arm9; ROM address 02071c18. No matching claim. */
#include "types.h"
#include "deps/02071c18_DriverContext_InitializeSfx.h"

void DriverContext_InitializeSfx(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x508U & 3;
  uVar3 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
  StructMQRacerEntry_SomeFn_45(param_1,0,uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  DriverContext_CreateSub450_1(param_1,param_1 + 0x450);
  DriverContext_CreateSub450_2(param_1);
  uVar4 = param_1 + 0x590U & 3;
  uVar3 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) {
  case 0:
    *(undefined4 *)(param_1 + 0x3cc) = 4;
    break;
  case 1:
    *(undefined4 *)(param_1 + 0x3cc) = 0;
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x3cc) = 1;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x3cc) = 2;
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x3cc) = 5;
    break;
  case 5:
    *(undefined4 *)(param_1 + 0x3cc) = 6;
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x3cc) = 7;
    break;
  case 7:
    *(undefined4 *)(param_1 + 0x3cc) = 3;
    break;
  case 8:
    *(undefined4 *)(param_1 + 0x3cc) = 10;
    break;
  case 9:
    *(undefined4 *)(param_1 + 0x3cc) = 8;
    break;
  case 10:
    *(undefined4 *)(param_1 + 0x3cc) = 9;
    break;
  case 0xb:
    *(undefined4 *)(param_1 + 0x3cc) = 0xb;
    break;
  case 0xc:
    *(undefined4 *)(param_1 + 0x3cc) = 0xc;
  }
  uVar4 = param_1 + 0x590U & 3;
  uVar3 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  lVar1 = (longlong)DAT_02071dd0 *
          (longlong)
          ((int)((ulonglong)((longlong)DAT_02071dcc * (longlong)(int)uVar4) >> 0x20) -
          ((int)uVar4 >> 0x1f));
  uVar2 = (undefined4)((ulonglong)lVar1 >> 0x20);
  *(short *)(param_1 + 0x3d0) = (short)uVar4 - (short)lVar1;
  uVar4 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) == 0) {
    if ((*(ushort *)(param_1 + 0x34) & 1) != 0) {
      StructMQRacerEntry_SomeFn_47(param_1,2,1);
      uVar2 = extraout_r1_00;
    }
    func_0210b850(param_1 + DAT_02071dd8,uVar2);
    return;
  }
  if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
    StructMQRacerEntry_SomeFn_47(param_1,2,1);
    uVar2 = extraout_r1;
  }
  uVar4 = (*(uint *)(DAT_02071dd4 & 0xfffffffc) >> (DAT_02071dd4 & 3) * 8 |
          *(uint *)(DAT_02071dd4 & 0xfffffffc) << (DAT_02071dd4 & 3) * -8 + 0x20) + 0xc;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 2) {
    return;
  }
  func_0210b850(param_1 + DAT_02071dd8,uVar2);
  return;
}

