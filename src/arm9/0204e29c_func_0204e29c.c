/* Decompiled C draft; module arm9; ROM address 0204e29c. No matching claim. */
#include "types.h"
#include "deps/0204e29c_func_0204e29c.h"

undefined4 func_0204e29c(void)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  piVar1 = piRam0204e2fc;
  uVar4 = 0;
  iVar2 = *(int *)(*piRam0204e2fc + 0xc);
  if (iVar2 < 5) {
    if (-1 < iVar2) {
      if (iVar2 == 0) {
        puVar3 = (ushort *)(*piRam0204e2fc + iRam0204e300);
        *puVar3 = *puVar3 | 0x40;
        *(undefined4 *)(*piVar1 + 4) = 1;
        func_020536e0();
      }
      else if (iVar2 == 1) {
        func_02053094(0);
      }
      else if (iVar2 == 4) {
        func_0204f814();
        func_0204e568();
      }
    }
  }
  else if (iVar2 == 0x16) {
    func_0200104c();
    uVar4 = 1;
  }
  return uVar4;
}

