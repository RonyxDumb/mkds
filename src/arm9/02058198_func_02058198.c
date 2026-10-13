/* Decompiled C draft; module arm9; ROM address 02058198. No matching claim. */
#include "types.h"
#include "deps/02058198_func_02058198.h"

void func_02058198(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = piRam020581ec;
  iVar3 = *piRam020581ec;
  if (*(int *)(iVar3 + 0x10) == 0) {
    iVar2 = *(int *)(iVar3 + 0xc);
    if (iVar2 < 0x26) {
      if (0x24 < iVar2) {
LAB_020581ca:
        func_02051734();
        return;
      }
      if ((iVar2 < 0xf) && (0xb < iVar2)) {
        if (iVar2 == 0xc) goto LAB_020581ca;
        if (iVar2 != 0xe) {
          return;
        }
        *(undefined4 *)(iVar3 + 4) = 7;
        iVar3 = *piVar1 + iRam020581f0;
        *(undefined2 *)(iVar3 + 0x10) = 5;
        *(undefined2 *)(iVar3 + 0x12) = 1;
      }
    }
    else if (iVar2 == 0x27) goto LAB_020581ca;
  }
  return;
}

