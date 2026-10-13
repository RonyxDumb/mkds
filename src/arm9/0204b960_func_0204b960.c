/* Decompiled C draft; module arm9; ROM address 0204b960. No matching claim. */
#include "types.h"
#include "deps/0204b960_func_0204b960.h"

int func_0204b960(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  for (uVar2 = 0; (iVar3 == 1 && (uVar2 < 8)); uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = func_02133458(uRam0204b9a4,uRam0204b9a8,uVar2 << 3);
    if (*param_1 != uVar1) {
      iVar3 = 0;
    }
    param_1 = param_1 + 1;
  }
  return iVar3;
}

