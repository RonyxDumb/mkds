/* Decompiled C draft; module arm9; ROM address 0204e3f0. No matching claim. */
#include "types.h"
#include "deps/0204e3f0_func_0204e3f0.h"

int func_0204e3f0(int param_1)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  undefined1 auStack_d4 [4];
  char local_d0;
  char local_cf;
  char local_ce;
  char local_cd;
  char local_cc;
  char local_cb;
  
  piVar1 = piRam0204e46c;
  uVar2 = 0;
  if (*(int *)(*piRam0204e46c + 0xc) == 0x1e) {
    do {
      iVar3 = func_0200b1b0(uVar2,auStack_d4);
      if ((((iVar3 != 0) &&
           (iVar3 = *piVar1 + iRam0204e470 + param_1 * 0xe0,
           local_d0 == *(char *)(*piVar1 + iRam0204e470 + param_1 * 0xe0))) &&
          (local_cf == *(char *)(iVar3 + 1))) &&
         (((local_ce == *(char *)(iVar3 + 2) && (local_cd == *(char *)(iVar3 + 3))) &&
          ((local_cc == *(char *)(iVar3 + 4) && (local_cb == *(char *)(iVar3 + 5))))))) {
        return (int)(char)uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x10);
  }
  return -1;
}

