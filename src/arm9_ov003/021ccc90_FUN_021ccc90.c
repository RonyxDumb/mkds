/* Decompiled C draft; module arm9_ov003; ROM address 021ccc90. No matching claim. */
#include "types.h"
#include "deps/021ccc90_FUN_021ccc90.h"

void FUN_021ccc90(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  ushort local_10;
  ushort local_e;
  
  iVar2 = FUN_021d2a80((ushort *)(uintptr_t)(DAT_021ccd0c));
  if (iVar2 != 0) {
    FUN_021d2940(&local_10);
    iVar2 = *DAT_021ccd10;
    if ((int)(*(ushort *)(iVar2 + 0x10) - 0x1e) <= (int)(uint)local_10) {
      iVar3 = (uint)*(byte *)(iVar2 + 0x18) + ((uint)local_e - (uint)*(ushort *)(iVar2 + 0x16));
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else {
        iVar2 = (uint)*(byte *)(iVar2 + 0x19) -
                (uint)*(byte *)(DAT_021ccd14 + (uint)*(byte *)(iVar2 + 0x1b));
        if (iVar2 <= iVar3) {
          iVar3 = iVar2;
        }
      }
      FUN_021ccc24(iVar3);
      FUN_021cca74(iVar3);
      *(undefined1 *)(*DAT_021ccd10 + 0x1d) = 2;
      return;
    }
  }
  FUN_021cdbd0();
  piVar1 = DAT_021ccd10;
  *(undefined1 *)(*DAT_021ccd10 + 0x1c) = 0;
  *(undefined1 *)(*piVar1 + 0x1d) = 3;
  return;
}

