/* Decompiled C draft; module arm9; ROM address 0204f008. No matching claim. */
#include "types.h"
#include "deps/0204f008_func_0204f008.h"

void func_0204f008(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = piRam0204f064;
  uVar4 = *(undefined4 *)(*piRam0204f064 + 0xc);
  *(undefined4 *)(*piRam0204f064 + 0xc) = 0x2c;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  iVar2 = iRam0204f070;
  iVar3 = *piVar1;
  *(undefined4 *)(iVar3 + iRam0204f070) =
       *(undefined4 *)(iVar3 + *(short *)(iVar3 + iRam0204f068) * 0x88 + iRam0204f06c);
  iVar3 = *piVar1;
  iVar2 = func_02006d78(1,**(undefined4 **)(iVar3 + iRam0204f074),iVar3 + iVar2,
                        (*(undefined4 **)(iVar3 + iRam0204f074))[1],iVar3 + iRam0204f078,
                        uRam0204f07c);
  piVar1 = piRam0204f064;
  if (iVar2 == 0) {
    *(undefined4 *)(*piRam0204f064 + 0xc) = uVar4;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
  }
  return;
}

