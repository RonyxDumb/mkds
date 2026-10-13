/* Decompiled C draft; module arm9_ov000; ROM address 02188b20. No matching claim. */
#include "types.h"
#include "deps/02188b20_FUN_02188b20.h"

int FUN_02188b20(undefined1 param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int local_1c;
  
  iVar4 = 0;
  local_1c = -1;
  iVar2 = local_1c;
  if (*(byte *)(param_3 + DAT_02188bb8) != 0) {
    pcVar3 = (char *)(param_3 + DAT_02188bbc);
    do {
      if ((((*(char *)(param_2 + 4) == *pcVar3) && (*(char *)(param_2 + 5) == pcVar3[1])) &&
          (*(char *)(param_2 + 6) == pcVar3[2])) &&
         (((*(char *)(param_2 + 7) == pcVar3[3] && (*(char *)(param_2 + 8) == pcVar3[4])) &&
          (iVar2 = iVar4, *(char *)(param_2 + 9) == pcVar3[5])))) break;
      pcVar3 = pcVar3 + 0xc0;
      iVar4 = iVar4 + 1;
      iVar2 = local_1c;
    } while (iVar4 < (int)(uint)*(byte *)(param_3 + DAT_02188bb8));
  }
  local_1c = iVar2;
  if (local_1c == -1) {
    FUN_02188ad4(param_1,param_2,param_3);
    bVar1 = *(byte *)(param_3 + DAT_02188bb8);
    if (bVar1 < 10) {
      *(byte *)(param_3 + DAT_02188bb8) = bVar1 + 1;
    }
    local_1c = 10;
  }
  else {
    FUN_02188a74(local_1c,param_2,param_3);
  }
  return local_1c;
}

