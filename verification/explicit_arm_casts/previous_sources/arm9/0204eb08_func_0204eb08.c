/* Decompiled C draft; module arm9; ROM address 0204eb08. No matching claim. */
#include "types.h"
#include "deps/0204eb08_func_0204eb08.h"

undefined4 func_0204eb08(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = (int *)*puRam0204eba4;
  if (piVar3 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar3;
  }
  if (iVar2 == 1) {
    if ((*(ushort *)((int)piVar3 + iRam0204eba8) & 0x40) == 0) {
      cVar1 = (char)piVar3[0x21];
    }
    else {
      cVar1 = *(char *)((int)piVar3 + iRam0204ebac);
    }
  }
  else {
    cVar1 = '\0';
  }
  if (cVar1 == '\x01') {
    if (piVar3 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *piVar3;
    }
    if (iVar2 == 1) {
      uVar4 = 1;
      do {
        if (((uint)*(byte *)((int)piVar3 + 0x87) & 1 << uVar4) != 0) {
          Mem_CpuCopy8((int)piVar3 + iRam0204ebb4 * uVar4 + iRam0204ebb0,param_1,0x14);
          return 1;
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 8);
      return 0;
    }
    return 0;
  }
  return 0;
}

