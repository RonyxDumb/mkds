/* Decompiled C draft; module arm9; ROM address 0200806c. No matching claim. */
#include "types.h"
#include "deps/0200806c_func_0200806c.h"

undefined4 func_0200806c(int *param_1,int param_2,uint param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = iRam020080e4;
  piVar1 = piRam020080e0;
  if (*(ushort *)(param_2 + 0x12) <= param_3) {
    return 0;
  }
  iVar5 = 2;
  iVar3 = param_2 + 4;
  do {
    if (*(ushort *)(iVar3 + 0xc) <= param_3) break;
    iVar3 = iVar3 + -2;
    iVar5 = (iVar5 + -1) * 0x1000000 >> 0x18;
  } while (-1 < iVar5);
  if (iVar5 < 0) {
    return 0;
  }
  iVar3 = *(int *)(*piRam020080e0 + iRam020080e4) *
          (param_3 - *(ushort *)(param_2 + iVar5 * 2 + 0xc));
  piVar4 = (int *)(param_4 + 0xc + iVar5 * 0x10);
  param_1[1] = piVar4[2] - iVar3;
  if (*(uint *)(*piVar1 + iVar2) < (uint)param_1[1]) {
    param_1[1] = *(uint *)(*piVar1 + iVar2);
  }
  param_1[2] = iVar3 + *(int *)(param_2 + iVar5 * 4);
  *param_1 = iVar3 + *piVar4;
  *(char *)(param_1 + 3) = (char)iVar5;
  return 1;
}

