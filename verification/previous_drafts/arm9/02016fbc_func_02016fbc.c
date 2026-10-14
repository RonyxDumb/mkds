/* Decompiled C draft; module arm9; ROM address 02016fbc. No matching claim. */
#include "types.h"
#include "deps/02016fbc_func_02016fbc.h"

uint func_02016fbc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uStack_10;
  
  if (param_1 == 0) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = param_1 + 0xfU & 0xfffffff0;
  }
  if (uRam0201705c <= uVar2) {
    return 0;
  }
  if (param_2 == 0) {
    iVar1 = func_02016c44(uRam02017068,uRam02017064,&uStack_10,uVar2);
  }
  else {
    iVar1 = func_02016c44(uRam02017060,uRam02017064,&uStack_10,uVar2);
  }
  if (iVar1 != 0) {
    return uRam0201706c & uStack_10 >> 3 | (uVar2 >> 4) << 0x10 | param_2 << 0x1f;
  }
  return 0;
}

