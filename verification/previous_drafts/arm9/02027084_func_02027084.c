/* Decompiled C draft; module arm9; ROM address 02027084. No matching claim. */
#include "types.h"
#include "deps/02027084_func_02027084.h"

void func_02027084(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *piRam020270c8;
  if (*psRam020270cc != 2) {
    uVar4 = (uint)*(ushort *)(*(int *)(iVar3 + 0x28) + 6);
    iVar2 = 0;
    if (uVar4 != 0) {
      iVar1 = 0;
      do {
        func_02124b1c(*(int *)(iVar3 + 0x34) + iVar1,*(undefined2 *)(*piRam020270c8 + 0x74),
                      *(undefined4 *)(*piRam020270c8 + 0x70));
        iVar1 = iVar1 + 0x40;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)uVar4);
    }
  }
  return;
}

