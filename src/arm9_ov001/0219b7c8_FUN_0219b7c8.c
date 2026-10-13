/* Decompiled C draft; module arm9_ov001; ROM address 0219b7c8. No matching claim. */
#include "types.h"
#include "deps/0219b7c8_FUN_0219b7c8.h"

void FUN_0219b7c8(void)

{
  int iVar1;
  
  iVar1 = func_0x021277ac();
  if (iVar1 != 0) {
    iVar1 = func_0x02127794();
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        FUN_0219bfc0();
        *(undefined4 *)(*DAT_0219b818 + 0x6c) = 1;
        FUN_0219c3a8();
        func_0x021282c8();
        return;
      }
      if (iVar1 != 1) {
        return;
      }
    }
    func_0x0212b7d8();
    FUN_0219c458();
  }
  return;
}

