/* Decompiled C draft; module arm9; ROM address 02118458. No matching claim. */
#include "types.h"
#include "deps/02118458_func_02118458.h"

void func_02118458(void)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  int iVar5;
  
  piVar1 = piRam021184d0;
  if (*psRam021184c4 != 2) {
    iVar5 = 0;
    puVar3 = puRam021184cc;
    puVar4 = puRam021184c8;
    do {
      iVar2 = *piVar1;
      if (*(short *)(iVar2 + 0x78) == iVar5) {
        *(undefined4 *)(*(int *)(iVar2 + 0x18) + (uint)*puVar4 * 0x40) = 1;
        iVar2 = *piVar1;
        func_02124100(*puVar3,0xe,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x18),
                      *(undefined4 *)(iVar2 + 4));
      }
      else {
        *(undefined4 *)(*(int *)(iVar2 + 0x18) + (uint)*puVar4 * 0x40) = 0;
        iVar2 = *piVar1;
        func_02124100(*puVar3,0xf,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x18),
                      *(undefined4 *)(iVar2 + 4));
      }
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  return;
}

