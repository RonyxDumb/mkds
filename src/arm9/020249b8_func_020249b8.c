/* Decompiled C draft; module arm9; ROM address 020249b8. No matching claim. */
#include "types.h"
#include "deps/020249b8_func_020249b8.h"

void func_020249b8(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 < 1) {
    return;
  }
  if (0xfff < param_2) {
    return;
  }
  iVar2 = (param_2 << 0xe) >> 0x10;
  uVar3 = (param_2 << 7) >> 0xc & 0xff;
  if (0x400 < iVar2) {
    iVar2 = 0x400;
  }
  if (0x7f < uVar3) {
    uVar3 = 0x7f;
  }
  uVar1 = uRam02024a24;
  if (0 < param_3) {
    uVar1 = 0x150;
  }
  func_02109078(param_1,uVar1,uVar3,iVar2);
  return;
}

