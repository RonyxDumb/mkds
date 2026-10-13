/* Decompiled C draft; module arm9_ov000; ROM address 02193f50. No matching claim. */
#include "types.h"
#include "deps/02193f50_FUN_02193f50.h"

undefined4 FUN_02193f50(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *param_1;
  if (((*(int *)(iVar4 + DAT_02193fec) != -1) && (iVar2 = FUN_0218e668(), iVar2 != 0)) &&
     (iVar2 = FUN_0218e478(*(undefined4 *)(iVar4 + DAT_02193fec),0,0), iVar2 != -1)) {
    puVar3 = (undefined4 *)FUN_02193eac(param_1);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_0218e53c(iVar2);
    }
    else {
      *puVar3 = 0x68;
      puVar3[2] = iVar2;
      FUN_0218e80c(iVar2,0);
      FUN_02193ff4(puVar3[2]);
    }
  }
  piVar5 = *(int **)(iVar4 + DAT_02193ff0);
  while (piVar1 = piVar5, piVar1 != (int *)0x0) {
    piVar5 = (int *)piVar1[0xf];
    iVar4 = FUN_02194160(param_1,piVar1);
    if (((*piVar1 == 0x6a) || (iVar4 != 0)) || (iVar4 = FUN_0218e320(0), piVar1[4] < iVar4)) {
      FUN_0219405c(param_1,piVar1);
    }
  }
  return 0;
}

