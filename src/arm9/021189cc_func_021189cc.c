/* Decompiled C draft; module arm9; ROM address 021189cc. No matching claim. */
#include "types.h"
#include "deps/021189cc_func_021189cc.h"

void func_021189cc(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = piRam021189f0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    uVar2 = func_021189f4(iVar4);
    *(undefined4 *)(*piVar1 + iVar3 + 0x48) = uVar2;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

