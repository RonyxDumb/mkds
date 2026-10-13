/* Decompiled C draft; module arm9; ROM address 0200b43c. No matching claim. */
#include "types.h"
#include "deps/0200b43c_func_0200b43c.h"

void func_0200b43c(int param_1,undefined2 *param_2)

{
  undefined2 local_8;
  undefined2 local_6 [3];
  
  if (param_1 < 0x2a) {
    switch(param_1) {
    case 6:
      func_0200ba44(2);
      func_0200bef8(*DAT_0200b600,*DAT_0200b600 + 0x20);
      return;
    case 9:
      func_0200b344((int)(uintptr_t)(param_2));
      return;
    case 10:
      func_0200ba44(4);
      return;
    case 0xb:
      func_0200ba44(3,0);
      return;
    case 0xf:
      if (*(short *)(*DAT_0200b600 + DAT_0200b604) == 10) {
        func_0200ba44(0xb,0);
      }
      else {
        func_0200ba44(0xc,0);
      }
      if (*(int *)(*DAT_0200b600 + DAT_0200b608) != 0) {
        func_0200bab0();
        return;
      }
      break;
    case 0x19:
      func_0200b200();
      return;
    }
  }
  else if (param_1 < 0x100) {
    if (param_1 != 0xff) {
      return;
    }
    if (*(int *)(*DAT_0200b600 + DAT_0200b60c) != 0) {
      switch(param_2[1]) {
      default:
        local_8 = 8;
        break;
      case 1:
      case 4:
      case 5:
      case 6:
      case 8:
      case 9:
        local_8 = 9;
      }
      (**(code **)(*DAT_0200b600 + DAT_0200b60c))(0x13,&local_8);
      return;
    }
  }
  else {
    if (param_1 != DAT_0200b5fc) {
      return;
    }
    if (*(int *)(*DAT_0200b600 + DAT_0200b60c) != 0) {
      switch(*param_2) {
      case 0:
      case 7:
      case 8:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x11:
      case 0x12:
      case 0x15:
      case 0x19:
      case 0x1d:
        local_6[0] = 9;
        break;
      default:
        local_6[0] = 8;
      }
      (**(code **)(*DAT_0200b600 + DAT_0200b60c))(0x13,local_6);
    }
  }
  return;
}

