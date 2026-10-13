/* Decompiled C draft; module arm9; ROM address 0200be44. No matching claim. */
#include "types.h"
#include "deps/0200be44_func_0200be44.h"

void func_0200be44(undefined2 *param_1)

{
  int *piVar1;
  undefined2 local_10;
  short local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  piVar1 = DAT_0200bef0;
  local_e = param_1[1];
  if (local_e == 0) {
    switch(param_1[2]) {
    case 10:
      *(undefined2 *)(*DAT_0200bef0 + 0x1a) = 1;
      *(undefined2 *)(*piVar1 + 0x20) = 0;
      *(undefined2 *)(*piVar1 + 0x1e) = 0;
      if (*(code **)*piVar1 != (code *)0x0) {
        (**(code **)*piVar1)(0x14);
      }
      if (*(code **)*DAT_0200bef0 != (code *)0x0) {
        (**(code **)*DAT_0200bef0)(0x19,0);
        return;
      }
      break;
    default:
      local_c = *param_1;
      if (*(int *)*DAT_0200bef0 != 0) {
        local_a = 1;
        (**(code **)*DAT_0200bef0)(DAT_0200bef4,&local_c);
      }
      break;
    case 0xc:
    case 0xd:
      break;
    }
  }
  else if (((local_e != 0xf) && (local_e != 9)) && (local_e != 0xd)) {
    local_10 = *param_1;
    if (*(int *)*DAT_0200bef0 != 0) {
      (**(code **)*DAT_0200bef0)(DAT_0200bef4,&local_10);
      return;
    }
  }
  return;
}

