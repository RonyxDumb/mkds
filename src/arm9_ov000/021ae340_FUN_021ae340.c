/* Decompiled C draft; module arm9_ov000; ROM address 021ae340. No matching claim. */
#include "types.h"
#include "deps/021ae340_FUN_021ae340.h"

ushort FUN_021ae340(void)

{
  bool bVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  puVar3 = DAT_021ae39c;
  uVar2 = DAT_021ae398;
  iVar4 = *(int *)(DAT_021ae394 + 8);
  do {
    bVar1 = false;
    *puVar3 = *puVar3 + 1;
    if ((*puVar3 < uVar2) || (DAT_021ae3a0 <= *puVar3)) {
      *puVar3 = (ushort)uVar2;
    }
    if (iVar4 != 0) {
      iVar5 = iVar4;
      do {
        piVar6 = *(int **)(iVar5 + 0xa4);
        if (((piVar6 != (int *)0x0) && (*piVar6 != 0)) && (*(ushort *)((int)piVar6 + 10) == *puVar3)
           ) {
          bVar1 = true;
          break;
        }
        iVar5 = *(int *)(iVar5 + 0x68);
      } while (iVar5 != 0);
    }
    if (!bVar1) {
      return *DAT_021ae39c;
    }
  } while( true );
}

