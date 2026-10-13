/* Decompiled C draft; module arm9; ROM address 0206cc60. No matching claim. */
#include "types.h"
#include "deps/0206cc60_func_0206cc60.h"

void func_0206cc60(int param_1,int param_2)

{
  uint uVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = iRam0206cdcc;
  iVar4 = iRam0206cdc4;
  uVar1 = param_1 + 0x2c4U & 3;
  uVar6 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
  if ((int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) < 1) {
    sVar2 = *(short *)(param_1 + 0x388);
    uVar3 = (undefined2)iRam0206cdcc;
    if (sVar2 < iRam0206cdcc) {
      *(short *)(param_1 + 0x388) = sVar2 + 200;
      if (iVar5 < *(short *)(param_1 + 0x388)) {
        *(undefined2 *)(param_1 + 0x388) = uVar3;
      }
    }
    else if ((iRam0206cdcc < sVar2) &&
            (*(short *)(param_1 + 0x388) = sVar2 - (short)uRam0206cdc8,
            *(short *)(param_1 + 0x388) < iVar5)) {
      *(undefined2 *)(param_1 + 0x388) = uVar3;
    }
  }
  else {
    sVar2 = *(short *)(param_1 + 0x388);
    uVar3 = (undefined2)iRam0206cdc4;
    if (iRam0206cdc4 < sVar2) {
      *(short *)(param_1 + 0x388) = sVar2 + -200;
      if (*(short *)(param_1 + 0x388) < iVar4) {
        *(undefined2 *)(param_1 + 0x388) = uVar3;
      }
    }
    else if ((sVar2 < iRam0206cdc4) &&
            (*(short *)(param_1 + 0x388) = sVar2 + (short)uRam0206cdc8,
            iVar4 < *(short *)(param_1 + 0x388))) {
      *(undefined2 *)(param_1 + 0x388) = uVar3;
    }
  }
  if (param_2 != 0) {
    return;
  }
  if (*(short *)(param_1 + 0x38a) < 0x33) {
    *(undefined2 *)(param_1 + 0x38a) = 0x32;
  }
  else {
    *(short *)(param_1 + 0x38a) = (short)((uint)(iRam0206cdd0 * *(short *)(param_1 + 0x38a)) >> 0xc)
    ;
  }
  StructMQRacerEntry_SomeFn_33(param_1);
  uVar1 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x10) == 0) {
    return;
  }
  func_01ffc9e8(param_1,1);
  uVar1 = param_1 + 0x4cU & 3;
  uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | 2;
  uVar1 = param_1 + 0x2fcU & 3;
  uVar6 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
  if ((int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) < 3) {
    return;
  }
  uVar1 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 1) == 0) {
    return;
  }
  func_02109078(param_1,0xd1,0x7f,0);
  return;
}

