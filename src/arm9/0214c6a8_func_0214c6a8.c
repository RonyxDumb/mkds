/* Decompiled C draft; module arm9; ROM address 0214c6a8. No matching claim. */
#include "types.h"
#include "deps/0214c6a8_func_0214c6a8.h"

void func_0214c6a8(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = func_02149004();
  piVar6 = piRam0214c724;
  piVar5 = piRam0214c720;
  piVar4 = piRam0214c71c;
  iVar8 = iVar7 * 6;
  uVar1 = *(ushort *)(iRam0214c70c + iVar8);
  uVar2 = *(ushort *)(iRam0214c710 + iVar8);
  uVar3 = *(ushort *)(iRam0214c714 + iVar8);
  *piRam0214c718 = iVar7;
  *piVar4 = (uint)uVar1 << 0xc;
  *piVar5 = (uint)uVar2 << 0xc;
  *piVar6 = (uint)uVar3 << 0xc;
  return;
}

