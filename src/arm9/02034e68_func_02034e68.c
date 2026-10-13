/* Decompiled C draft; module arm9; ROM address 02034e68. No matching claim. */
#include "types.h"
#include "deps/02034e68_func_02034e68.h"

undefined4 func_02034e68(short *param_1,short *param_2)

{
  bool bVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  
  bVar1 = false;
  iVar4 = 0;
  psVar2 = param_1;
  psVar3 = param_2;
  do {
    bVar1 = (bool)(bVar1 | *psVar2 != *psVar3);
    psVar3 = psVar3 + 1;
    psVar2 = psVar2 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xb);
  if ((((!bVar1) && (*(int *)(param_1 + 0xe) == *(int *)(param_2 + 0xe))) &&
      (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) &&
     (((*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10) &&
       ((char)param_1[0x13] == (char)param_2[0x13])) &&
      ((*(char *)((int)param_1 + 0x27) == *(char *)((int)param_2 + 0x27) &&
       (param_1[0x12] == param_2[0x12])))))) {
    return 0;
  }
  return 1;
}

