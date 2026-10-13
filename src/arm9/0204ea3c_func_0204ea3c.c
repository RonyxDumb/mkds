/* Decompiled C draft; module arm9; ROM address 0204ea3c. No matching claim. */
#include "types.h"
#include "deps/0204ea3c_func_0204ea3c.h"

undefined4 func_0204ea3c(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = ComputeRomBinarySize_from_thumb(0);
  if (uRam0204ea80 <= uVar1) {
    iVar2 = FsUnk_ReadCartHeader_from_thumb
                      (0,*(undefined4 *)(*piRam0204ea84 + iRam0204ea88),
                       *(undefined4 *)(*piRam0204ea84 + iRam0204ea8c));
    if ((iVar2 != 0) &&
       (iVar2 = func_02008310(uRam0204ea90,*(undefined4 *)(*piRam0204ea84 + iRam0204ea88)),
       iVar2 != 0)) {
      uVar3 = 1;
    }
  }
  return uVar3;
}

