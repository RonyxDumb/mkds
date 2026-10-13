/* Decompiled C draft; module arm9; ROM address 020fa0e8. No matching claim. */
#include "types.h"
#include "deps/020fa0e8_func_020fa0e8.h"

uint func_020fa0e8(int param_1,undefined4 param_2)

{
  int iVar1;
  
  switch(param_2) {
  case 0:
    return (*(uint *)(*DAT_020fa138 + param_1 * 0xa8 + 0x4c) & 0xff) + 1 & 0xff;
  case 1:
    return 0x12;
  case 2:
    return 3;
  case 3:
    break;
  default:
    return 0;
  }
  if (param_1 == 0xb) {
    iVar1 = 3;
  }
  else {
    iVar1 = 2;
  }
  return iVar1 + 1;
}

