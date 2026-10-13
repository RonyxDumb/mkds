/* Decompiled C draft; module arm9; ROM address 0200b344. No matching claim. */
#include "types.h"
#include "deps/0200b344_func_0200b344.h"

void func_0200b344(int param_1)

{
  undefined1 local_10 [16];
  
  func_0200c0d8(local_10,(undefined1 *)(uintptr_t)(*(undefined4 *)(param_1 + 0xc)));
  switch(local_10[0]) {
  case 1:
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 2) {
      func_0200ba44(5,0);
      return;
    }
    break;
  case 2:
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 5) {
      func_0200ba44(6,0);
      return;
    }
    break;
  case 3:
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 5) {
      func_0200ba44(7,0);
      return;
    }
    break;
  case 4:
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 7) {
      func_0200ba44(8,0);
    }
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 8) {
      func_0200ba44(9,0);
      return;
    }
    break;
  case 5:
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 9) {
      func_0200ba44(10,0);
      return;
    }
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 10) {
      func_0200be00();
    }
    break;
  case 6:
    if (*(short *)(*DAT_0200b434 + DAT_0200b438) == 5) {
      func_0200ba44(0xe,0);
      return;
    }
  }
  return;
}

