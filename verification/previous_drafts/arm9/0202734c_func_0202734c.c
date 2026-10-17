/* Decompiled C draft; module arm9; ROM address 0202734c. No matching claim. */
#include "types.h"
#include "deps/0202734c_func_0202734c.h"

void func_0202734c(undefined4 param_1)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *piRam020273b0;
  if (*psRam020273b4 != 2) {
    iVar2 = 0;
    psVar1 = psRam020273b8;
    if (0 < *(int *)(iVar3 + 0x7c)) {
      do {
        *(undefined4 *)(*(int *)(iVar3 + 0x34) + psVar1[2] * 0x40) = param_1;
        *(undefined4 *)(*(int *)(iVar3 + 0x34) + psVar1[1] * 0x40) =
             *(undefined4 *)(*(int *)(iVar3 + 0x34) + psVar1[2] * 0x40);
        *(undefined4 *)(*(int *)(iVar3 + 0x34) + *psVar1 * 0x40) =
             *(undefined4 *)(*(int *)(iVar3 + 0x34) + psVar1[1] * 0x40);
        iVar2 = iVar2 + 1;
        psVar1 = psVar1 + 4;
      } while (iVar2 < *(int *)(*piRam020273b0 + 0x7c));
    }
    *(undefined4 *)(*(int *)(iVar3 + 0x34) + iRam020273bc) = param_1;
  }
  return;
}

