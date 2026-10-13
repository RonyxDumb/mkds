/* Decompiled C draft; module arm9; ROM address 0214c2f8. No matching claim. */
#include "types.h"
#include "deps/0214c2f8_func_0214c2f8.h"

void func_0214c2f8(void)

{
  undefined4 uVar1;
  
  uVar1 = func_02148fdc();
  *DAT_0214c3ac = uVar1;
  switch(uVar1) {
  case 0:
    break;
  case 1:
    *DAT_0214c3b0 = DAT_0214c3b8;
    return;
  case 2:
    goto LAB_0214c34c;
  case 3:
LAB_0214c34c:
    *DAT_0214c3b0 = 0x6800000;
    return;
  case 4:
    *DAT_0214c3b0 = DAT_0214c3bc;
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    goto LAB_0214c364;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
LAB_0214c364:
    *DAT_0214c3b0 = DAT_0214c3b4;
    return;
  }
  return;
}

