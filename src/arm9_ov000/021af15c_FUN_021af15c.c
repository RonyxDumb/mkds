/* Decompiled C draft; module arm9_ov000; ROM address 021af15c. No matching claim. */
#include "types.h"
#include "deps/021af15c_FUN_021af15c.h"

int * FUN_021af15c(int param_1,ushort *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_021af1e0 + 8);
  while( true ) {
    if (iVar1 == 0) {
      return (int *)0x0;
    }
    piVar2 = *(int **)(iVar1 + 0xa4);
    if (((((piVar2 != (int *)0x0) && (*piVar2 != 0)) && ((char)piVar2[2] == '\x01')) &&
        (((uint)*(ushort *)((int)piVar2 + 10) ==
          ((int)(uint)param_2[1] >> 8 | (param_2[1] & 0xff) << 8) &&
         ((*(ushort *)(piVar2 + 6) == 0 ||
          ((uint)*(ushort *)(piVar2 + 6) == ((int)(uint)*param_2 >> 8 | (*param_2 & 0xff) << 8))))))
        ) && ((piVar2[7] == 0 ||
              (piVar2[7] ==
               (((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
               (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 | (*(ushort *)(param_1 + 0xe) & 0xff) << 8
               ))))) break;
    iVar1 = *(int *)(iVar1 + 0x68);
  }
  return piVar2;
}

