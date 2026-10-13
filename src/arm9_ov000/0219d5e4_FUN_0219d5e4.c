/* Decompiled C draft; module arm9_ov000; ROM address 0219d5e4. No matching claim. */
#include "types.h"
#include "deps/0219d5e4_FUN_0219d5e4.h"

int FUN_0219d5e4(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_0219d62c;
  if ((*DAT_0219d62c != 0) && (param_1 != 0)) {
    iVar3 = 0;
    if (0 < *(int *)(*DAT_0219d62c + 0x14)) {
      do {
        iVar2 = FUN_0219d630(iVar3);
        if (param_1 == iVar2) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(*piVar1 + 0x14));
    }
    return -1;
  }
  return -1;
}

