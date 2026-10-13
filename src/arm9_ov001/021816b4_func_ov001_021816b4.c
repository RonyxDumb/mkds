/* Decompiled C draft; module arm9_ov001; ROM address 021816b4. No matching claim. */
#include "types.h"
#include "deps/021816b4_func_ov001_021816b4.h"

undefined4 func_ov001_021816b4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)func_0x02100138(0x6c);
  if (piVar1 != (int *)0x0) {
    iVar3 = 0;
    for (iVar2 = 0; (iVar3 < (int)(uint)*(ushort *)(piVar1 + 1) && (*(int *)(*piVar1 + iVar2) != 0))
        ; iVar2 = iVar2 + 4) {
      if ((*(ushort *)(*(int *)(*piVar1 + iVar2) + 2) & uRam021816f8) == 0) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    }
  }
  return 0;
}

