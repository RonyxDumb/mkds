/* Decompiled C draft; module arm9; ROM address 02029248. No matching claim. */
#include "types.h"
#include "deps/02029248_func_02029248.h"

void func_02029248(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(*piRam020292b8 + 0x9c) + -1;
  if (iVar4 < 0) {
    iVar4 = 0x23;
  }
  while( true ) {
    iVar3 = *piRam020292b8;
    if (iVar4 == *(int *)(iVar3 + 0x9c)) break;
    uVar2 = func_02025e28(iVar4);
    iVar3 = func_0205fd2c(*(undefined4 *)(iVar3 + 0x98),*(undefined4 *)(iVar3 + 0xa4),uVar2);
    piVar1 = piRam020292b8;
    if (iVar3 == 0) {
      iVar4 = iVar4 + -1;
      if (iVar4 < 0) {
        iVar4 = 0x23;
      }
    }
    else {
      *(int *)(*piRam020292b8 + 0x9c) = iVar4;
      uVar2 = func_02025e28(*(undefined4 *)(*piVar1 + 0x9c));
      *(undefined4 *)(*piRam020292b8 + 0xa8) = uVar2;
    }
  }
  func_02029330();
  return;
}

