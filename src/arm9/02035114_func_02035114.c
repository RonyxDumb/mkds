/* Decompiled C draft; module arm9; ROM address 02035114. No matching claim. */
#include "types.h"
#include "deps/02035114_func_02035114.h"

void func_02035114(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = piRam020351b8;
  iVar2 = *piRam020351b8;
  if (-1 < *(int *)(iVar2 + 0x80)) {
    if (*(int *)(iVar2 + iRam020351c4) == 0) {
      *(undefined4 *)(*(int *)(iVar2 + 0x60) + iRam020351bc) = 0;
      *(undefined4 *)(*piVar1 + 0x80) = 0xffffffff;
      return;
    }
    if (*(int *)(iVar2 + *(int *)(iVar2 + 0x80) * 0x3c + 0xc4) == 0) {
      iVar3 = 0;
      iVar4 = iVar2;
      do {
        if (*(int *)(iVar4 + 0xc4) != 0) {
          *(int *)(iVar2 + 0x80) = iVar3;
          return;
        }
        iVar4 = iVar4 + 0x3c;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
    }
    return;
  }
  iVar3 = 0;
  iVar4 = iVar2;
  do {
    if (*(int *)(iVar4 + 0xc4) != 0) {
      *(int *)(iVar2 + 0x80) = iVar3;
      *(undefined4 *)(*(int *)(iVar2 + 0x60) + iRam020351bc) = 1;
      func_02025c6c(4,(int)*(short *)(iRam020351c0 + iVar3 * 8),*(undefined4 *)(iVar2 + 0x54));
      return;
    }
    iVar4 = iVar4 + 0x3c;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}

