/* Decompiled C draft; module arm9; ROM address 020292bc. No matching claim. */
#include "types.h"
#include "deps/020292bc_func_020292bc.h"

void func_020292bc(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(*piRam0202932c + 0x9c) + 1;
  if (0x23 < iVar4) {
    iVar4 = 0;
  }
  while( true ) {
    iVar3 = *piRam0202932c;
    if (iVar4 == *(int *)(iVar3 + 0x9c)) break;
    uVar2 = func_02025e28(iVar4);
    iVar3 = func_0205fd2c(*(undefined4 *)(iVar3 + 0x98),*(undefined4 *)(iVar3 + 0xa4),uVar2);
    piVar1 = piRam0202932c;
    if (iVar3 == 0) {
      iVar4 = iVar4 + 1;
      if (0x23 < iVar4) {
        iVar4 = 0;
      }
    }
    else {
      *(int *)(*piRam0202932c + 0x9c) = iVar4;
      uVar2 = func_02025e28(*(undefined4 *)(*piVar1 + 0x9c));
      *(undefined4 *)(*piRam0202932c + 0xa8) = uVar2;
    }
  }
  func_02029330();
  return;
}

