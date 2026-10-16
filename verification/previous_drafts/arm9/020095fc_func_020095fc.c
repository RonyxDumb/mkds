/* Decompiled C draft; module arm9; ROM address 020095fc. No matching claim. */
#include "types.h"
#include "deps/020095fc_func_020095fc.h"

undefined4 func_020095fc(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *piRam02009640;
  if (iVar3 == 0) {
    return 0;
  }
  if ((piRam02009640[1] != 0) && (iVar2 = *(int *)(piRam02009640[1] + iRam02009644), iVar2 != 0)) {
    iVar3 = iVar2;
  }
  piRam02009640[1] = iVar3;
  func_020096c0();
  piVar1 = piRam02009640;
  *(undefined1 *)((int)piRam02009640 + 0xe) = *(undefined1 *)(piRam02009640[1] + iRam02009648);
  *(undefined1 *)(piVar1 + 3) = 2;
  return 1;
}

