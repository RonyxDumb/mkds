/* Decompiled C draft; module arm9; ROM address 020ab338. No matching claim. */
#include "types.h"
#include "deps/020ab338_func_020ab338.h"

int func_020ab338(uint param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = *(int **)(DAT_020ab3e0 + 0x2c);
  if (piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
    if ((int)param_1 < 0x21) {
      if (0x1f < (int)param_1) {
LAB_020ab39e:
        return iVar2 + 0x10;
      }
      iVar1 = DAT_020ab3e0;
      switch(param_1) {
      case 0:
        iVar1 = 0;
      case 1:
        return iVar1;
      case 2:
        return DAT_020ab3e8;
      case 8:
        return iVar2;
      case 10:
        return iVar2 + 8;
      }
    }
    else if (param_1 == DAT_020ab3e4) goto LAB_020ab39e;
    iVar4 = 0;
    iVar1 = iVar2;
    if (*(ushort *)((int)piVar3 + 0xe) != 0) {
      do {
        if (((1 < *(byte *)(iVar1 + 2)) && (1 < *(byte *)(iVar1 + 3))) &&
           (param_1 ==
            *(ushort *)
             (*(int *)(DAT_020ab3e0 + 0x30) +
             (((uint)*(ushort *)(iVar1 + 6) - (uint)*(ushort *)(piVar3 + 3)) + -1) * 2))) {
          return iVar2 + iVar4 * 8;
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar1 + 8;
      } while (iVar4 < (int)(uint)*(ushort *)((int)piVar3 + 0xe));
    }
  }
  return 0;
}

