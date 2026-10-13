/* Decompiled C draft; module arm9_ov003; ROM address 021d2094. No matching claim. */
#include "types.h"
#include "deps/021d2094_FUN_021d2094.h"

void FUN_021d2094(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 short *param_6,int param_7)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  
  if (*param_6 != 0) {
    do {
      piVar4 = (int *)(*DAT_021d2114 + param_7 * 0xc);
      uVar1 = func_0x02022ce4(piVar4);
      if (uVar1 == DAT_021d2118) {
        uVar1 = (uint)*(ushort *)(*piVar4 + 2);
      }
      pcVar2 = (char *)func_0x02022c80((uint)(uintptr_t)(piVar4),uVar1);
      if ((short)piVar4[2] == 0) {
        iVar3 = (int)pcVar2[2];
      }
      else {
        iVar3 = (int)*pcVar2 + (uint)(byte)pcVar2[1];
      }
      FUN_021d211c(param_1,param_2 + (param_5 - iVar3 >> 1),param_3,param_4,*param_6,param_7);
      param_2 = param_2 + param_5;
      param_6 = param_6 + 1;
    } while (*param_6 != 0);
  }
  return;
}

