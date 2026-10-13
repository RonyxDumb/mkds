/* Decompiled C draft; module arm9_ov003; ROM address 021c7e8c. No matching claim. */
#include "types.h"
#include "deps/021c7e8c_FUN_021c7e8c.h"

void FUN_021c7e8c(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = DAT_021c7ec0;
  iVar4 = 0;
  do {
    iVar3 = *piVar2 + iVar4;
    cVar1 = *(char *)(iVar3 + 4);
    if (cVar1 != '\0') {
      *(char *)(iVar3 + 4) = cVar1 + -1;
      if (*(char *)(*piVar2 + iVar4 + 4) == '\0') {
        FUN_021c8b94();
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  return;
}

