/* Decompiled C draft; module arm9_ov000; ROM address 0218e850. No matching claim. */
#include "types.h"
#include "deps/0218e850_FUN_0218e850.h"

char * FUN_0218e850(char *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  
  iVar2 = DAT_0218e87c;
  cVar4 = *param_1;
  pcVar3 = param_1;
  while (iVar1 = (int)cVar4, iVar1 != 0) {
    if ((-1 < iVar1) && (iVar1 < 0x80)) {
      cVar4 = *(char *)(iVar2 + iVar1);
    }
    *pcVar3 = cVar4;
    pcVar3 = pcVar3 + 1;
    cVar4 = *pcVar3;
  }
  return param_1;
}

