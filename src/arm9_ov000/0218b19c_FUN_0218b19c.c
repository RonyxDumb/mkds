/* Decompiled C draft; module arm9_ov000; ROM address 0218b19c. No matching claim. */
#include "types.h"
#include "deps/0218b19c_FUN_0218b19c.h"

char * FUN_0218b19c(int param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  if (param_1 != 0) {
    *DAT_0218b1dc = param_1;
  }
  piVar1 = DAT_0218b1dc;
  pcVar2 = (char *)*DAT_0218b1dc;
  while( true ) {
    pcVar3 = (char *)*piVar1;
    iVar4 = (int)*pcVar3;
    if ((iVar4 == 0) || (iVar4 == param_2)) break;
    *piVar1 = *piVar1 + 1;
  }
  if (pcVar3 == pcVar2) {
    pcVar2 = (char *)0x0;
  }
  if (iVar4 != 0) {
    *DAT_0218b1dc = *DAT_0218b1dc + 1;
    *pcVar3 = '\0';
  }
  return pcVar2;
}

