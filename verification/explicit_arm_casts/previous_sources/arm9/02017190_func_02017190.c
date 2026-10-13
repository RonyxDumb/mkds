/* Decompiled C draft; module arm9; ROM address 02017190. No matching claim. */
#include "types.h"
#include "deps/02017190_func_02017190.h"

uint func_02017190(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uStack_c;
  
  if (param_1 == 0) {
    uVar2 = 8;
  }
  else {
    uVar2 = param_1 + 7U & 0xfffffff8;
  }
  if (uRam02017264 <= uVar2) {
    return 0;
  }
  if (param_2 == 0) {
    iVar1 = func_02016b00(uRam02017268,uRam0201726c,&uStack_c,uVar2);
  }
  else {
    iVar1 = func_02016b00(uRam02017268,uRam0201726c,&uStack_c,uVar2);
    if (0x10000 < uStack_c + uVar2) {
      func_020169a4(uRam02017268,uRam0201726c,uStack_c,uVar2);
      return 0;
    }
  }
  if (iVar1 != 0) {
    return uRam02017270 & uStack_c >> 3 | (uVar2 >> 3) << 0x10;
  }
  return 0;
}

