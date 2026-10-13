/* Decompiled C draft; module arm9; ROM address 02042ec0. No matching claim. */
#include "types.h"
#include "deps/02042ec0_func_02042ec0.h"

void func_02042ec0(int *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *piRam02042fbc;
  if (*(ushort *)(iVar1 + iRam02042fc0) < 0x21) {
    iVar6 = *(int *)(iVar1 + 0x54) + param_3 * 0x10;
  }
  else {
    iVar6 = *(int *)(iVar1 + 0x54) + param_3 * 0x14;
  }
  iVar5 = *(int *)(iVar1 + 0xac) + param_3 * 0x28;
  iVar3 = 0;
  iVar1 = iVar5;
  do {
    if ((param_1 != (int *)0x0) && (*(int **)(iVar1 + 0xc) == param_1)) {
      return;
    }
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  *(int *)(iVar5 + 0x18) = iVar6;
  *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar6 + 0xc);
  if (*(ushort *)(*piRam02042fbc + iRam02042fc0) < 0x21) {
    *(undefined1 *)(iVar5 + 0x20) = 0;
  }
  else {
    *(undefined1 *)(iVar5 + 0x20) = *(undefined1 *)(iVar6 + 0x10);
  }
  iVar1 = 0;
  piVar4 = param_1;
  do {
    if (*piVar4 == 0) {
      param_1[iVar1] = iVar5;
      *(short *)(param_1 + 9) = (short)param_1[9] + 1;
      break;
    }
    piVar4 = piVar4 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  iVar6 = 0;
  iVar1 = iVar5;
  do {
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(int **)(iVar5 + iVar6 * 4 + 0xc) = param_1;
      *(short *)(iVar5 + 0x26) = *(short *)(iVar5 + 0x26) + 1;
      break;
    }
    iVar1 = iVar1 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  piVar4 = piRam02042fbc;
  if ((int)((uint)*param_2 + (uint)param_2[1] + -1) <= param_3) {
    iVar1 = 0;
    do {
      uVar2 = (uint)*(byte *)((int)param_2 + iVar1 + 4);
      if ((uVar2 != 0xff) && (uVar2 != 0)) {
        func_02042ec0(iVar5,*(int *)(*piVar4 + 0x5c) + uVar2 * 0xc,
                      *(undefined2 *)(*(int *)(*piVar4 + 0x5c) + uVar2 * 0xc));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    return;
  }
  func_02042ec0(iVar5,param_2,param_3 + 1U & 0xffff);
  return;
}

