/* Decompiled C draft; module arm9; ROM address 02042d34. No matching claim. */
#include "types.h"
#include "deps/02042d34_func_02042d34.h"

void func_02042d34(int *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = *(int *)(*piRam02042e08 + 100) + param_3 * 0x18;
  iVar6 = *(int *)(*piRam02042e08 + 0xa0) + param_3 * 0x28;
  iVar5 = 0;
  iVar1 = iVar6;
  do {
    if ((param_1 != (int *)0x0) && (*(int **)(iVar1 + 0xc) == param_1)) {
      return;
    }
    iVar1 = iVar1 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  *(int *)(iVar6 + 0x18) = iVar3;
  *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar3 + 0xc);
  *(int *)(iVar6 + 0x20) = iVar3 + 0x10;
  if (param_1 != (int *)0x0) {
    iVar1 = 0;
    piVar4 = param_1;
    do {
      if (*piVar4 == 0) {
        param_1[iVar1] = iVar6;
        *(short *)(param_1 + 9) = (short)param_1[9] + 1;
        break;
      }
      piVar4 = piVar4 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    iVar3 = 0;
    iVar1 = iVar6;
    do {
      if (*(int *)(iVar1 + 0xc) == 0) {
        *(int **)(iVar6 + iVar3 * 4 + 0xc) = param_1;
        *(short *)(iVar6 + 0x26) = *(short *)(iVar6 + 0x26) + 1;
        break;
      }
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  piVar4 = piRam02042e08;
  if ((int)((uint)*param_2 + (uint)param_2[1] + -1) <= param_3) {
    iVar1 = 0;
    do {
      uVar2 = (uint)*(byte *)((int)param_2 + iVar1 + 4);
      if (uVar2 != 0xff) {
        iVar3 = uVar2 * 0xc;
        func_02042d34(iVar6,*(int *)(*piVar4 + 0x6c) + iVar3,
                      *(undefined2 *)(*(int *)(*piVar4 + 0x6c) + iVar3));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    return;
  }
  func_02042d34(iVar6,param_2,param_3 + 1U & 0xffff);
  return;
}

