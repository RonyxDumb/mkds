/* Decompiled C draft; module arm9; ROM address 02058338. No matching claim. */
#include "types.h"
#include "deps/02058338_func_02058338.h"

void func_02058338(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  func_0214358c(0xe,0,0);
  iVar2 = iRam020583ac;
  piVar1 = piRam020583a4;
  *(byte *)(*piRam020583a4 + iRam020583ac) = *(byte *)(*piRam020583a4 + iRam020583a8) >> 4;
  if (*psRam020583b0 == 2) {
    *(uint *)(*piRam020583b4 + 4) = (uint)*(byte *)(*piVar1 + iVar2);
  }
  iVar2 = iRam020583b8;
  piVar1 = piRam020583a4;
  uVar3 = 1;
  do {
    if (((uint)*(byte *)(*piVar1 + iRam020583bc) & 1 << uVar3) == 0) {
      Mem_CpuFill8((uint *)(uintptr_t)(*piVar1 + iRam020583c0 + iVar2 * uVar3),0,iVar2);
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 8);
  return;
}

