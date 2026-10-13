/* Decompiled C draft; module arm9_ov000; ROM address 021aadcc. No matching claim. */
#include "types.h"
#include "deps/021aadcc_FUN_021aadcc.h"

undefined4 FUN_021aadcc(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  while( true ) {
    while( true ) {
      cVar1 = *param_2;
      param_2 = param_2 + 1;
      cVar2 = *param_1;
      if (cVar2 != cVar1) break;
      param_1 = param_1 + 1;
      if (cVar2 == '\0') {
        return 0;
      }
    }
    if (cVar1 != '*') break;
    iVar3 = FUN_021aae2c(param_1);
    iVar4 = FUN_021aae2c(param_2);
    if (iVar3 < iVar4) {
      return 1;
    }
    param_1 = param_1 + (iVar3 - iVar4);
  }
  return 1;
}

