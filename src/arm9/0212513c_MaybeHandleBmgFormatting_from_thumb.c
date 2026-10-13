/* Decompiled C draft; module arm9; ROM address 0212513c. No matching claim. */
#include "types.h"
#include "deps/0212513c_MaybeHandleBmgFormatting_from_thumb.h"

void MaybeHandleBmgFormatting_from_thumb(short *param_1,short *param_2,short *param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  iVar5 = 0;
  psVar4 = param_3;
  for (; ((*param_2 != 0x1a || (*(char *)((int)param_2 + 3) != '\x01')) || (param_2[2] != 0xff));
      param_2 = param_2 + 1) {
    *psVar4 = *param_2;
    psVar4 = psVar4 + 1;
    iVar5 = iVar5 + 1;
  }
  param_2 = param_2 + ((int)(uint)*(byte *)(param_2 + 1) >> 1);
  if (*param_1 != 0) {
    psVar4 = param_3 + iVar5;
    do {
      *psVar4 = *param_1;
      psVar4 = psVar4 + 1;
      iVar5 = iVar5 + 1;
      param_1 = param_1 + 1;
    } while (*param_1 != 0);
  }
  sVar2 = *param_2;
  while (sVar2 != 0) {
    if (sVar2 == 0x1a) {
      bVar1 = *(byte *)(param_2 + 1);
      CopyMemory16((int)(uintptr_t)(param_2),(int)(uintptr_t)(param_3 + iVar5),(uint)bVar1);
      iVar3 = (int)(uint)bVar1 >> 1;
      param_2 = param_2 + iVar3;
      iVar5 = iVar5 + iVar3;
    }
    else {
      param_3[iVar5] = sVar2;
      iVar5 = iVar5 + 1;
      param_2 = param_2 + 1;
    }
    sVar2 = *param_2;
  }
  param_3[iVar5] = 0;
  return;
}

