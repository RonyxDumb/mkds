/* Decompiled C draft; module arm9; ROM address 02110fb8. No matching claim. */
#include "types.h"
#include "deps/02110fb8_func_02110fb8.h"

undefined4 func_02110fb8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xb;
  if (param_1 == 1) {
    return 9;
  }
  switch(*(undefined1 *)
          ((*(uint *)(DAT_02111020 & 0xfffffffc) >> (DAT_02111020 & 3) * 8 |
           *(uint *)(DAT_02111020 & 0xfffffffc) << (DAT_02111020 & 3) * -8 + 0x20) + 0x3d0)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    goto LAB_02111004;
  case 5:
LAB_02111004:
    if (param_1 < 3) {
      uVar1 = 10;
    }
    break;
  case 6:
    goto LAB_02111010;
  case 7:
    goto LAB_02111010;
  case 8:
LAB_02111010:
    if (param_1 < 4) {
      uVar1 = 10;
    }
  }
  return uVar1;
}

