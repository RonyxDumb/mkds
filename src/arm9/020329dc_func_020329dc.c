/* Decompiled C draft; module arm9; ROM address 020329dc. No matching claim. */
#include "types.h"
#include "deps/020329dc_func_020329dc.h"

void func_020329dc(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam02032a1c;
  if (*psRam02032a18 != 2) {
    iVar2 = *piRam02032a1c;
    iVar5 = 0;
    if (0 < *(int *)(iVar2 + 0x48)) {
      iVar4 = 0;
      iVar3 = iVar2;
      do {
        *(undefined4 *)
         (*(int *)(iVar2 + 0x34) + (uint)*(ushort *)(*(int *)(iVar3 + 0x4c) + iVar4 + 2) * 0x40) =
             param_1;
        iVar4 = iVar4 + 6;
        iVar5 = iVar5 + 1;
        iVar3 = *piVar1;
      } while (iVar5 < *(int *)(iVar3 + 0x48));
    }
  }
  return;
}

