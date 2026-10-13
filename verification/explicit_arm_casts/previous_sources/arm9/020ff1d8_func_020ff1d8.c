/* Decompiled C draft; module arm9; ROM address 020ff1d8. No matching claim. */
#include "types.h"
#include "deps/020ff1d8_func_020ff1d8.h"

void func_020ff1d8(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  if (*(int *)(*piRam020ff240 + 0x54) != 0) {
    local_24 = *puRam020ff244;
    uStack_20 = puRam020ff244[1];
    local_1c = puRam020ff244[2];
    func_02146f98(uRam020ff248,&local_24,uRam020ff24c,uRam020ff24c);
    iVar1 = *piRam020ff250 + iRam020ff254;
    piVar3 = *(int **)(iVar1 + 4);
    iVar6 = *(int *)(iVar1 + 8);
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        iVar4 = *piVar3;
        uVar2 = func_0210543c();
        *(undefined4 *)(iVar4 + iRam020ff258) = uVar2;
        *(int *)(*(int *)(iVar4 + iRam020ff258) + 0xfc) = iVar4 + 0x50;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar6);
    }
    *(undefined4 *)(iVar1 + 0x40) = 1;
  }
  return;
}

