/* Decompiled C draft; module arm9_ov003; ROM address 021be3b8. No matching claim. */
#include "types.h"
#include "deps/021be3b8_FUN_021be3b8.h"

undefined4 FUN_021be3b8(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = true;
  iVar2 = FUN_021be7b8();
  if (iVar2 != 0) {
    do {
      func_0x0200dc3c(10);
      iVar2 = FUN_021be528();
      while (iVar2 != 0) {
        if ((iVar2 != 4) && (iVar2 != 5)) {
          if (iVar2 == 0x14) {
            bVar1 = false;
          }
          else {
            bVar1 = false;
          }
        }
        iVar2 = FUN_021be528();
      }
    } while (bVar1);
  }
  if (*DAT_021be410 != 0) {
    (*(code *)*DAT_021be414)();
    *DAT_021be410 = 0;
  }
  return 1;
}

