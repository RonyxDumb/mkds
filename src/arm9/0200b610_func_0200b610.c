/* Decompiled C draft; module arm9; ROM address 0200b610. No matching claim. */
#include "types.h"
#include "deps/0200b610_func_0200b610.h"

undefined4 func_0200b610(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_02008934();
  piVar1 = piRam0200b67c;
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined4 *)(*piRam0200b67c + iRam0200b680) = *(undefined4 *)(iVar2 + iRam0200b678);
  *(ushort *)(*piVar1 + iRam0200b688) = (ushort)*(byte *)(iVar2 + iRam0200b684);
  func_0200c0ac(*piVar1 + iRam0200b68c);
  func_0200c090(uRam0200b690);
  func_0200ba44(1,0);
  Mem_CpuCopy8((ushort *)(uintptr_t)(iVar2 + iRam0200b694),(uint *)(uintptr_t)(*piRam0200b67c + iRam0200b694),0xc0);
  func_0200c008(*piRam0200b67c + iRam0200b694);
  return 1;
}

