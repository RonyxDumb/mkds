/* Decompiled C draft; module arm9; ROM address 020b32f8. No matching claim. */
#include "types.h"
#include "deps/020b32f8_func_020b32f8.h"

int func_020b32f8(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = GetCurrentOptionMenuKind_from_thumb();
  if (iVar1 == 0) {
    if (*(int *)(*piRam020b3360 + iRam020b3364) != 0) {
      iVar2 = *(int *)(*piRam020b3360 + iRam020b3364) + 0xc;
    }
  }
  else if (iVar1 == 1) {
    if (*(int *)(*piRam020b3360 + iRam020b3368) != 0) {
      iVar2 = *(int *)(*piRam020b3360 + iRam020b3368) + 0xc;
    }
  }
  else if (iVar1 == 2) {
    if (*(int *)(*piRam020b3360 + iRam020b336c) != 0) {
      iVar2 = *(int *)(*piRam020b3360 + iRam020b336c) + 0xc;
    }
  }
  else if ((iVar1 == 3) && (*(int *)(*piRam020b3360 + iRam020b3370) != 0)) {
    iVar2 = *(int *)(*piRam020b3360 + iRam020b3370) + 0xc;
  }
  return iVar2;
}

