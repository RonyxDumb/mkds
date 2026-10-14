/* Decompiled C draft; module arm9; ROM address 0200cc74. No matching claim. */
#include "types.h"
#include "deps/0200cc74_Os_SetIrqHandler.h"

void Os_SetIrqHandler(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar2 = iRam0200cd00;
  iVar1 = iRam0200ccfc;
  iVar4 = 0;
  do {
    if ((param_1 & 1) != 0) {
      puVar3 = (undefined4 *)0x0;
      if ((iVar4 < 8) || (0xb < iVar4)) {
        if ((iVar4 < 3) || (6 < iVar4)) {
          *(undefined4 *)(iVar1 + iVar4 * 4) = param_2;
        }
        else {
          puVar3 = (undefined4 *)((iVar4 + 1) * 0xc + iVar2);
        }
      }
      else {
        puVar3 = (undefined4 *)((iVar4 + -8) * 0xc + iVar2);
      }
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = param_2;
        puVar3[2] = 0;
        puVar3[1] = 1;
      }
    }
    iVar4 = iVar4 + 1;
    param_1 = param_1 >> 1;
  } while (iVar4 < 0x16);
  return;
}

