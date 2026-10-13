/* Decompiled C draft; module arm9; ROM address 02119a38. No matching claim. */
#include "types.h"
#include "deps/02119a38_func_02119a38.h"

void func_02119a38(void)

{
  int *piVar1;
  
  piVar1 = DAT_02119a88;
  *(undefined4 *)(*DAT_02119a88 + 0x38) = 7;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
  switch(*(undefined4 *)(*piVar1 + 0x40)) {
  case 0:
  case 1:
  case 3:
    func_021277e4();
    return;
  case 2:
    func_021277e4();
    if (*DAT_02119a8c == 2) {
      TextSystem_CloseDialog_from_thumb();
    }
  }
  return;
}

