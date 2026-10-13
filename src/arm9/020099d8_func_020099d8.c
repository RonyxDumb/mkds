/* Decompiled C draft; module arm9; ROM address 020099d8. No matching claim. */
#include "types.h"
#include "deps/020099d8_func_020099d8.h"

int func_020099d8(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *piRam02009a84;
  if ((*(short *)(iVar1 + iRam02009a88) == 0) || (*(short *)(iVar1 + iRam02009a8c) == 1)) {
    return 1;
  }
  if (*(short *)(iVar1 + iRam02009a90) == 1) {
    uVar2 = uRam02009a98;
    if (*(short *)(iVar1 + iRam02009a94) != 0) {
      uVar2 = 0;
    }
    iVar1 = func_02009aa8(*(undefined4 *)(iVar1 + iRam02009a9c),param_1,param_2,uVar2 & 0xffff,
                          param_3);
    if (iVar1 == 2) {
      *(undefined1 *)(*piRam02009a84 + iRam02009aa0) = 1;
      return 0;
    }
  }
  else if (*(short *)(iVar1 + iRam02009a90) == 2) {
    iVar1 = func_02009aa8(uRam02009aa4,param_1,param_2,0,param_3);
    if (iVar1 == 2) {
      *(undefined1 *)(*piRam02009a84 + iRam02009aa0) = 1;
      return 0;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

