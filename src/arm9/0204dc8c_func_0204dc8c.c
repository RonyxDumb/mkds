/* Decompiled C draft; module arm9; ROM address 0204dc8c. No matching claim. */
#include "types.h"
#include "deps/0204dc8c_func_0204dc8c.h"

undefined4 func_0204dc8c(void)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar3 = *piRam0204dce0;
  if (*(byte *)(iVar3 + iRam0204dce4) == (*(byte *)(iVar3 + iRam0204dce4) & *(byte *)(iVar3 + 0x87))
     ) {
    uVar4 = 1;
  }
  else {
    uVar1 = *(ushort *)(iVar3 + iRam0204dce8);
    if (uRam0204dcec < uVar1) {
      if (*(byte *)(iVar3 + 0x87) == 0) {
        func_02050e60(5);
      }
      else {
        uVar2 = func_0204dcf0();
        *(undefined1 *)(*piRam0204dce0 + iRam0204dce4) = uVar2;
        uVar4 = 1;
      }
    }
    else {
      *(ushort *)(iVar3 + iRam0204dce8) = uVar1 + 1;
    }
  }
  return uVar4;
}

