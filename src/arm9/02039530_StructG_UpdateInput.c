/* Decompiled C draft; module arm9; ROM address 02039530. No matching claim. */
#include "types.h"
#include "deps/02039530_StructG_UpdateInput.h"

void StructG_UpdateInput(ushort param_1,ushort *param_2)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar1 = (uint)(param_2 + 0x10) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 0x10) & 0xfffffffc);
  if (uVar5 >> uVar1 * 8 != 0 || uVar5 << uVar1 * -8 + 0x20 != 0) {
    func_020392c8();
  }
  uVar3 = uRam02039700;
  *param_2 = param_1 & (param_1 ^ param_2[1]);
  param_2[2] = (param_1 ^ (ushort)uVar3) & (param_1 ^ param_2[1]);
  param_2[1] = param_1;
  param_2[3] = 0;
  uVar2 = param_2[4];
  if (uVar2 == 0) {
    if ((param_1 & param_2[6]) != 0) {
      param_2[4] = 1;
      param_2[5] = 0;
      param_2[3] = param_1 & param_2[6];
    }
  }
  else if (uVar2 == 1) {
    if ((param_1 & param_2[6]) == 0) {
      param_2[4] = 0;
    }
    else {
      param_2[5] = param_2[5] + 1;
      if (param_2[7] <= param_2[5]) {
        param_2[4] = 2;
        param_2[5] = 0;
        param_2[3] = param_1 & param_2[6];
      }
    }
  }
  else if (uVar2 == 2) {
    if ((param_1 & param_2[6]) == 0) {
      param_2[4] = 0;
    }
    else {
      param_2[5] = param_2[5] + 1;
      if (param_2[8] <= param_2[5]) {
        param_2[5] = 0;
        param_2[3] = param_1 & param_2[6];
      }
    }
  }
  if ((param_2[10] == 0) || ((param_2[1] & 0x30c) != 0x30c)) {
    if ((param_2[1] & 0x30c) != 0x30c) {
      param_2[10] = 1;
    }
    param_2[9] = 0;
    return;
  }
  if ((*param_2 & 0x30c) != 0) {
    uVar6 = Os_GetTick();
    *(undefined8 *)(param_2 + 0xc) = uVar6;
    param_2[9] = 0;
    return;
  }
  if (param_2[9] != 0) {
    return;
  }
  iVar4 = Os_GetTick();
  uVar1 = (uint)(param_2 + 0xc) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 0xc) & 0xfffffffc);
  if (uRam02039704 < iVar4 - (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)) {
    param_2[9] = 1;
  }
  return;
}

