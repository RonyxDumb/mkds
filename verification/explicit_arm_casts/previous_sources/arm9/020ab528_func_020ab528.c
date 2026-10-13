/* Decompiled C draft; module arm9; ROM address 020ab528. No matching claim. */
#include "types.h"
#include "deps/020ab528_func_020ab528.h"

void func_020ab528(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((*(short *)(iRam020ab57c + 10) == 0) &&
     (iVar2 = func_020ab650(*(undefined2 *)(iRam020ab57c + 8)), iVar2 != 0)) {
    uVar1 = func_020ab650(*(undefined2 *)(iRam020ab57c + 8));
    *(undefined2 *)(iRam020ab57c + 10) = uVar1;
    return;
  }
  iVar2 = func_020ab640(*(undefined2 *)(iRam020ab57c + 10));
  if (iVar2 != 0) {
    func_020ab5bc(iRam020ab57c);
    return;
  }
  func_020ab5b4(iRam020ab57c);
  *(undefined2 *)(iRam020ab57c + 10) = 0;
  return;
}

