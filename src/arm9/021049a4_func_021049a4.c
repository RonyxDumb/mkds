/* Decompiled C draft; module arm9; ROM address 021049a4. No matching claim. */
#include "types.h"
#include "deps/021049a4_func_021049a4.h"

void func_021049a4(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(*piRam021049f4 + iRam021049f8) != 0) {
    iVar1 = *piRam021049fc + iRam02104a00;
    piVar3 = *(int **)(iVar1 + 4);
    iVar6 = *(int *)(iVar1 + 8);
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        iVar4 = *piVar3;
        uVar2 = func_0210543c();
        *(undefined4 *)(iVar4 + iRam02104a04) = uVar2;
        *(int *)(*(int *)(iVar4 + iRam02104a04) + 0xfc) = iVar4 + iRam02104a08;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar6);
    }
    *(undefined4 *)(iVar1 + 0x40) = 1;
  }
  return;
}

