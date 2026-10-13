/* Decompiled C draft; module arm9; ROM address 020586ac. No matching claim. */
#include "types.h"
#include "deps/020586ac_func_020586ac.h"

undefined4
func_020586ac(undefined1 param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if ((*(byte *)(*piRam02058744 + iRam02058748) & 1) == 0) {
    return 0;
  }
  puVar3 = *(undefined1 **)(*piRam02058744 + iRam0205874c);
  puVar3[1] = param_1;
  *(short *)(puVar3 + 2) = (short)param_3;
  *puVar3 = param_4;
  if (param_2 == 0) {
    param_3 = 0;
  }
  else {
    Mem_CpuCopy8(param_2,puVar3 + 4);
  }
  DC_SomeClean(puVar3,param_3 + 4);
  piVar1 = piRam02058744;
  *(byte *)(*piRam02058744 + iRam02058748) = *(byte *)(*piRam02058744 + iRam02058748) & 0xfe;
  iVar2 = func_02050650(*(undefined4 *)(*piVar1 + iRam0205874c),param_3 + 4,param_5,0,uRam02058750);
  if (iVar2 == 0) {
    *(byte *)(*piRam02058744 + iRam02058748) = *(byte *)(*piRam02058744 + iRam02058748) | 1;
    return 0;
  }
  return 1;
}

