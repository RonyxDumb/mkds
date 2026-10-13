/* Decompiled C draft; module arm9; ROM address 02031208. No matching claim. */
#include "types.h"
#include "deps/02031208_func_02031208.h"

void func_02031208(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam0203124c;
  if (*(int *)(*piRam0203124c + 0x94) != 6) {
    iVar5 = 0;
    iVar4 = 0;
    iVar3 = 0;
    do {
      iVar2 = *piVar1 + 0x24 + iVar4;
      func_02124c30(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8),
                    *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(*piVar1 + iVar3 + 0x5c),
                    *(undefined4 *)(iVar2 + 0x18));
      iVar4 = iVar4 + 0x1c;
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
  }
  return;
}

