/* Decompiled C draft; module arm9; ROM address 0211a07c. No matching claim. */
#include "types.h"
#include "deps/0211a07c_func_0211a07c.h"

void func_0211a07c(void)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  int iVar5;
  
  piVar1 = piRam0211a0fc;
  if (*psRam0211a0f0 != 2) {
    iVar5 = 0;
    puVar3 = puRam0211a0f8;
    puVar4 = puRam0211a0f4;
    do {
      iVar2 = *piVar1;
      if ((*(short *)(iVar2 + 0x50) == iVar5) && (*(int *)(iVar2 + 0x54) != 0)) {
        *(undefined4 *)(*(int *)(iVar2 + 0x20) + (uint)*puVar4 * 0x40) = 1;
        iVar2 = *piVar1;
        func_02124100(*puVar3,0xe,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x20),
                      *(undefined4 *)(iVar2 + 0x10));
      }
      else {
        *(undefined4 *)(*(int *)(iVar2 + 0x20) + (uint)*puVar4 * 0x40) = 0;
        iVar2 = *piVar1;
        func_02124100(*puVar3,0xf,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x20),
                      *(undefined4 *)(iVar2 + 0x10));
      }
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  return;
}

