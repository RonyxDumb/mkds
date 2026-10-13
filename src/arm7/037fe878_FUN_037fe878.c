/* Decompiled C draft; module arm7; ROM address 037fe878. No matching claim. */
#include "types.h"
#include "deps/037fe878_FUN_037fe878.h"

void FUN_037fe878(int param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x24 + DAT_037fe918;
  iVar2 = 0;
  for (; (iVar2 < 0x10 && (param_2 != 0)); param_2 = param_2 >> 1) {
    if (((param_2 & 1) != 0) && (iVar1 = FUN_037fe2e4(iVar3,iVar2), iVar1 != 0)) {
      if (param_5 == 1) {
        *(char *)(iVar1 + param_3) = (char)param_4;
      }
      else if (param_5 == 2) {
        *(short *)(iVar1 + param_3) = (short)param_4;
      }
      else if (param_5 == 4) {
        *(undefined4 *)(iVar1 + param_3) = param_4;
      }
    }
    iVar2 = iVar2 + 1;
  }
  return;
}

