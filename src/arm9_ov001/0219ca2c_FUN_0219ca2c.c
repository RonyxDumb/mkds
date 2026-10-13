/* Decompiled C draft; module arm9_ov001; ROM address 0219ca2c. No matching claim. */
#include "types.h"
#include "deps/0219ca2c_FUN_0219ca2c.h"

void FUN_0219ca2c(void)

{
  int iVar1;
  
  iVar1 = func_0x02127788();
  if (iVar1 != 0) {
    if (*(int *)(*DAT_0219ca90 + 0x28) + 2U < 2) {
      iVar1 = func_0x02127794();
      if (iVar1 == 1) {
        *(undefined4 *)(*DAT_0219ca90 + 4) = 6;
      }
      else {
        *(undefined4 *)(*DAT_0219ca90 + 4) = 2;
      }
    }
    else {
      iVar1 = func_0x02127794();
      if (iVar1 == 0) {
        *(undefined4 *)(*DAT_0219ca90 + 4) = 6;
        func_0x021282c8();
        *(undefined4 *)(*DAT_0219ca90 + 0x2c) = 1;
      }
      else {
        *(undefined4 *)(*DAT_0219ca90 + 4) = 2;
      }
    }
    func_0x021277e4();
  }
  return;
}

