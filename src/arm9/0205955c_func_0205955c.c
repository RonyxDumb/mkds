/* Decompiled C draft; module arm9; ROM address 0205955c. No matching claim. */
#include "types.h"
#include "deps/0205955c_func_0205955c.h"

undefined4 func_0205955c(void)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  
  bVar5 = false;
  bVar4 = false;
  bVar1 = false;
  piVar2 = (int *)*piRam020595e0;
  if (piVar2 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar2;
  }
  if ((iVar6 != 0) && (piVar2[1] != 0xd)) {
    bVar1 = true;
  }
  if ((bVar1) && ((*(ushort *)((int)piVar2 + iRam020595e4) & 0x80) == 0)) {
    bVar4 = true;
  }
  if ((bVar4) && (piVar2[2] != 9)) {
    bVar5 = true;
  }
  if (bVar5) {
    return 3;
  }
  if (piVar2 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar2;
  }
  if (iVar6 != 1) {
    if (iVar6 != 2) {
      return 3;
    }
    uVar3 = func_020595e8(0,0,0);
    return uVar3;
  }
  uVar3 = func_02059700();
  return uVar3;
}

