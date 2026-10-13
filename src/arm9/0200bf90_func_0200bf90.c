/* Decompiled C draft; module arm9; ROM address 0200bf90. No matching claim. */
#include "types.h"
#include "deps/0200bf90_func_0200bf90.h"

void func_0200bf90(int param_1)

{
  if (*(short *)(param_1 + 2) == 0) {
    switch(*(undefined2 *)(param_1 + 8)) {
    case 7:
      if (*(code **)*DAT_0200c004 != (code *)0x0) {
        (**(code **)*DAT_0200c004)(6);
      }
      break;
    case 9:
      if (*(code **)*DAT_0200c004 != (code *)0x0) {
        (**(code **)*DAT_0200c004)(10,0);
        return;
      }
    }
  }
  else if (*(code **)*DAT_0200c004 != (code *)0x0) {
    (**(code **)*DAT_0200c004)(0xb);
    return;
  }
  return;
}

