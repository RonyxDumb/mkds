/* Decompiled C draft; module arm9; ROM address 0214c48c. No matching claim. */
#include "types.h"
#include "deps/0214c48c_func_0214c48c.h"

void func_0214c48c(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = func_02148ff0();
  piVar2 = piRam0214c4d0;
  uVar1 = *(ushort *)(iRam0214c4cc + (iVar3 >> 4) * 2);
  *piRam0214c4c8 = iVar3;
  *piVar2 = (uint)uVar1 << 0xc;
  return;
}

