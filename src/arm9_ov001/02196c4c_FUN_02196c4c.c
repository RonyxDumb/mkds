/* Decompiled C draft; module arm9_ov001; ROM address 02196c4c. No matching claim. */
#include "types.h"
#include "deps/02196c4c_FUN_02196c4c.h"

undefined4 FUN_02196c4c(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_02196ccc;
  uVar1 = *(ushort *)(DAT_02196cc4 + 0x2e0);
  if (uVar1 != 0) {
    if (*DAT_02196cc8 == (*DAT_02196cc8 | uVar1)) {
      *(undefined2 *)(*DAT_02196ccc + 0x80) = 1;
      *(undefined4 *)(*piVar2 + 0x84) = 0;
    }
    else {
      iVar3 = *DAT_02196ccc;
      if (DAT_02196cc8[*(short *)(iVar3 + 0x80)] == (DAT_02196cc8[*(short *)(iVar3 + 0x80)] | uVar1)
         ) {
        *(short *)(iVar3 + 0x80) = *(short *)(iVar3 + 0x80) + 1;
        *(undefined4 *)(*piVar2 + 0x84) = 0;
        if (5 < *(short *)(*piVar2 + 0x80)) {
          *(undefined2 *)(*piVar2 + 0x80) = 0;
          return 1;
        }
      }
      else {
        *(undefined2 *)(iVar3 + 0x80) = 0;
      }
    }
  }
  return 0;
}

