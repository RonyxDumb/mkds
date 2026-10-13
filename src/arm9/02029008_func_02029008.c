/* Decompiled C draft; module arm9; ROM address 02029008. No matching claim. */
#include "types.h"
#include "deps/02029008_func_02029008.h"

void func_02029008(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  
  iVar4 = *piRam0202908c;
  if (*(int *)(iVar4 + iRam02029090) == 0) {
    uVar3 = func_02025ebc(iVar4 + 0xac);
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + 0x44) = uVar3;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + 0x84) = *(undefined2 *)(*(int *)(iVar4 + 0x60) + 0x44);
    uVar3 = func_02025ebc(*piRam0202908c + 0xbc);
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + 6) = uVar3;
    uVar3 = func_02025ebc(*piRam0202908c + 0xcc);
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + 0xc6) = uVar3;
    uVar3 = func_02025ebc(*piRam0202908c + 0xdc);
    iVar1 = iRam02029094;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + iRam02029094) = uVar3;
    iVar2 = iRam02029098;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + iRam02029098) =
         *(undefined2 *)(*(int *)(iVar4 + 0x60) + iVar1);
    iVar1 = iRam0202909c;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + iRam0202909c) =
         *(undefined2 *)(*(int *)(iVar4 + 0x60) + iVar2);
    iVar2 = iRam020290a0;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + iRam020290a0) =
         *(undefined2 *)(*(int *)(iVar4 + 0x60) + iVar1);
    iVar1 = iRam020290a4;
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + iRam020290a4) =
         *(undefined2 *)(*(int *)(iVar4 + 0x60) + iVar2);
    *(undefined2 *)(*(int *)(iVar4 + 0x60) + iRam020290a8) =
         *(undefined2 *)(*(int *)(iVar4 + 0x60) + iVar1);
  }
  return;
}

