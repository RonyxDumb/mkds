/* Decompiled C draft; module arm9_ov003; ROM address 021c5ec4. No matching claim. */
#include "types.h"
#include "deps/021c5ec4_FUN_021c5ec4.h"

void FUN_021c5ec4(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  if (*(int *)(*DAT_021c5f88 + 0x38) == 0) {
    if (*(char *)(*DAT_021c5f88 + 0x57) == '\0') {
      iVar3 = FUN_021bf334();
      if (iVar3 == 0) {
        FUN_021cdc10(7);
      }
      else {
        if (iVar3 != 1) {
          return;
        }
        if (*DAT_021c5f8c == 4) {
          *(undefined1 *)(*DAT_021c5f88 + 0x54) = 1;
          FUN_021cdc10(6);
          FUN_021c5724();
        }
        else {
          iVar3 = func_0x02147d30(*DAT_021c5f90,0x1c);
          piVar2 = DAT_021c5f88;
          bVar1 = *DAT_021c5f8c;
          if (*(char *)(*(int *)*DAT_021c5f88 + ((uint)bVar1 + iVar3) * 0x2a + 0x28) == '\x02') {
            FUN_021cdc10(9);
            FUN_021cce38();
            FUN_021bf2d0();
            FUN_021cefc0(0x42,1,1,0xffffffff,0);
            FUN_021c212c(DAT_021c5f94);
            return;
          }
          *(undefined1 *)((int *)*DAT_021c5f88 + 0x15) = 1;
          *(char *)(*piVar2 + 0x52) = (char)((uint)bVar1 + iVar3);
          FUN_021cdc10(6);
        }
      }
      FUN_021c212c(DAT_021c5f98);
    }
  }
  return;
}

