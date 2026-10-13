/* Decompiled C draft; module arm9; ROM address 0200c2e0. No matching claim. */
#include "types.h"
#include "deps/0200c2e0_func_0200c2e0.h"

char * func_0200c2e0(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  *param_2 = *param_1;
  cVar1 = *param_2;
  if (cVar1 == '\a') {
    iVar2 = func_0200c20c(param_3);
    if (iVar2 != 0) {
      return (char *)(*piRam0200c398 + (param_3 + -1) * 0x20);
    }
    param_2[2] = param_1[1];
    if (piRam0200c39c[1] < (int)(uint)(byte)param_2[2]) {
      return (char *)0x0;
    }
    Mem_CpuCopy8((ushort *)(void *)(param_1 + 2),(uint *)(void *)(param_2 + 3),*piRam0200c39c);
    pcVar3 = (char *)func_0200c25c((int)(uintptr_t)(param_2),param_3);
  }
  else if (cVar1 == '\b') {
    *(ushort *)(param_2 + 2) = (ushort)(byte)param_1[1];
    pcVar3 = param_1 + 3;
    *(ushort *)(param_2 + 2) =
         *(ushort *)(param_2 + 2) | (ushort)(byte)param_1[2] << 8 & (ushort)uRam0200c3a0;
  }
  else {
    if (cVar1 != '\t') {
      return (char *)0x0;
    }
    *(ushort *)(param_2 + 2) = (ushort)(byte)param_1[1];
    *(ushort *)(param_2 + 2) =
         *(ushort *)(param_2 + 2) | (ushort)(byte)param_1[2] << 8 & (ushort)uRam0200c3a0;
    Mem_CpuCopy8((ushort *)(void *)(param_1 + 3),(uint *)(void *)(param_2 + 4),*piRam0200c39c);
    pcVar3 = param_1 + 3 + *piRam0200c39c;
  }
  return pcVar3;
}

