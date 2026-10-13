/* Decompiled C draft; module arm9; ROM address 020ab2a4. No matching claim. */
#include "types.h"
#include "deps/020ab2a4_func_020ab2a4.h"

undefined2 func_020ab2a4(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(iRam020ab330 + 0x2c);
  if (piVar2 != (int *)0x0) {
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == iRam020ab330) {
      return 1;
    }
    if (param_1 == iRam020ab334) {
      return 2;
    }
    iVar3 = 0;
    iVar1 = *piVar2;
    if (*(ushort *)((int)piVar2 + 0xe) != 0) {
      do {
        if (((1 < *(byte *)(iVar1 + 2)) && (1 < *(byte *)(iVar1 + 3))) && (param_1 == iVar1)) {
          if (iVar3 == 0) {
            return 8;
          }
          if (iVar3 == 1) {
            return 10;
          }
          if (iVar3 == 2) {
            return 0x20;
          }
          return *(undefined2 *)
                  (*(int *)(iRam020ab330 + 0x30) +
                  (((uint)*(ushort *)(*piVar2 + iVar3 * 8 + 6) - (uint)*(ushort *)(piVar2 + 3)) + -1
                  ) * 2);
        }
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + 8;
      } while (iVar3 < (int)(uint)*(ushort *)((int)piVar2 + 0xe));
    }
  }
  return 0;
}

