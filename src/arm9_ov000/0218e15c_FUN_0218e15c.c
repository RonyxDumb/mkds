/* Decompiled C draft; module arm9_ov000; ROM address 0218e15c. No matching claim. */
#include "types.h"
#include "deps/0218e15c_FUN_0218e15c.h"

void FUN_0218e15c(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  int extraout_r1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int local_1c;
  
  pcVar3 = DAT_0218e214;
  if ((param_4 != 1) && (pcVar3 = DAT_0218e218, param_4 != 2)) {
    pcVar3 = DAT_0218e21c;
  }
  pcVar4 = param_2;
  local_1c = param_3;
  if (0 < param_3) {
    do {
      iVar2 = param_3;
      if (2 < param_3) {
        iVar2 = 3;
      }
      FUN_0218e220(param_1,pcVar4,iVar2);
      pcVar4 = pcVar4 + 4;
      param_1 = param_1 + 3;
      local_1c = local_1c + -3;
    } while (0 < local_1c);
  }
  func_0x02133068(param_3,3);
  if (extraout_r1 == 1) {
    pcVar5 = pcVar4 + -2;
  }
  else {
    pcVar5 = pcVar4;
    if (extraout_r1 == 2) {
      pcVar5 = pcVar4 + -1;
    }
  }
  *pcVar4 = '\0';
  while (param_2 < pcVar4) {
    pcVar4 = pcVar4 + -1;
    if (pcVar4 < pcVar5) {
      cVar1 = *pcVar4;
      if (cVar1 < '\x1a') {
        *pcVar4 = cVar1 + 'A';
      }
      else if (cVar1 < '4') {
        *pcVar4 = cVar1 + 'G';
      }
      else if (cVar1 < '>') {
        *pcVar4 = cVar1 + -4;
      }
      else if (cVar1 == '>') {
        *pcVar4 = *pcVar3;
      }
      else if (cVar1 == '?') {
        *pcVar4 = pcVar3[1];
      }
    }
    else {
      *pcVar4 = pcVar3[2];
    }
  }
  return;
}

