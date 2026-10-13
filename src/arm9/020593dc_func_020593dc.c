/* Decompiled C draft; module arm9; ROM address 020593dc. No matching claim. */
#include "types.h"
#include "deps/020593dc_func_020593dc.h"

undefined4 func_020593dc(void)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  undefined4 uVar4;
  bool bVar5;
  int iVar6;
  
  bVar2 = false;
  bVar1 = false;
  bVar5 = false;
  piVar3 = (int *)*piRam0205948c;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar3;
  }
  if ((iVar6 != 0) && (piVar3[1] != 0xd)) {
    bVar5 = true;
  }
  if ((bVar5) && ((*(ushort *)((int)piVar3 + iRam02059490) & 0x80) == 0)) {
    bVar1 = true;
  }
  if ((bVar1) && (piVar3[2] != 9)) {
    bVar2 = true;
  }
  if (bVar2) {
    return 3;
  }
  bVar5 = false;
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar3;
  }
  if ((iVar6 != 0) && (piVar3[1] != 0xd)) {
    bVar5 = true;
  }
  if (!bVar5) {
    return 1;
  }
  if (piVar3 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar3;
  }
  if (iVar6 != 1) {
    if (iVar6 != 2) {
      return 3;
    }
    uVar4 = func_020595e8(1,*(undefined4 *)(*piRam0205948c + iRam02059494),
                          *(undefined4 *)(*piRam0205948c + iRam02059498));
    return uVar4;
  }
  uVar4 = func_02059700();
  return uVar4;
}

