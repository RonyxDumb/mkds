/* Decompiled C draft; module arm9; ROM address 0202d990. No matching claim. */
#include "types.h"
#include "deps/0202d990_func_0202d990.h"

undefined4 func_0202d990(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = func_0202dd9c();
  piVar1 = piRam0202d9ec;
  if (0 < iVar2) {
    iVar2 = 0;
    do {
      iVar3 = func_02061654(*(int *)(*piVar1 + iRam0202d9f0) +
                            iRam0202d9f8 * (*(uint *)(*piVar1 + iVar2 + iRam0202d9f4) & 0xff));
      if (param_1 == iVar3) {
        return *(undefined4 *)(*piRam0202d9ec + iVar4 * 4 + iRam0202d9f4);
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
      iVar3 = func_0202dd9c();
    } while (iVar4 < iVar3);
  }
  return 0xffffffff;
}

