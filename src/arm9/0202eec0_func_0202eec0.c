/* Decompiled C draft; module arm9; ROM address 0202eec0. No matching claim. */
#include "types.h"
#include "deps/0202eec0_func_0202eec0.h"

void func_0202eec0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar2 = GetDirectInputUnitIndex();
  iVar3 = func_0202f0a8();
  if (iVar3 == 0) {
    *(undefined4 *)(*piRam0202efc0 + 0x20) = 0xffffffff;
  }
  else {
    uVar4 = func_0202f080(uVar2);
    uVar5 = func_0202f058(uVar2);
    uVar4 = func_020291c4(uVar4,uVar5,*(undefined4 *)(*piRam0202efc0 + 0xc));
    piVar1 = piRam0202efc0;
    *(undefined4 *)(*piRam0202efc0 + 0x1c) = uVar4;
    iVar3 = *piVar1;
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(*piVar1 + iRam0202efc4) = 1;
  }
  if (*(int *)(*piRam0202efc0 + iRam0202efc4) != 0) {
    iVar3 = func_0202efc8(uVar2);
    piVar1 = piRam0202efc0;
    if (iVar3 == 0) {
      *(undefined4 *)(*piRam0202efc0 + 0x1c) = 0xffffffff;
      *(undefined4 *)(*piVar1 + iRam0202efc4) = 0;
    }
    else {
      uVar4 = func_0202f080(uVar2);
      uVar5 = func_0202f058(uVar2);
      iVar3 = func_020291c4(uVar4,uVar5,*(undefined4 *)(*piRam0202efc0 + 0xc));
      piVar1 = piRam0202efc0;
      if (iVar3 != *(int *)(*piRam0202efc0 + 0x1c)) {
        *(undefined4 *)(*piRam0202efc0 + 0x1c) = 0xffffffff;
        *(undefined4 *)(*piVar1 + iRam0202efc4) = 0;
      }
    }
  }
  iVar3 = func_0202ec7c(uVar2,0x40);
  if ((iVar3 == 0) && (iVar3 = *piRam0202efc0, *(int *)(iVar3 + 0x1c) != *(int *)(iVar3 + 0x10))) {
    *(undefined4 *)(iVar3 + 0x50) = 0;
  }
  else {
    *(int *)(*piRam0202efc0 + 0x50) = *(int *)(*piRam0202efc0 + 0x50) + 1;
  }
  iVar3 = func_0202ec7c(uVar2,0x80);
  if ((iVar3 == 0) && (iVar3 = *piRam0202efc0, *(int *)(iVar3 + 0x1c) != *(int *)(iVar3 + 0x14))) {
    *(undefined4 *)(iVar3 + 0x54) = 0;
  }
  else {
    *(int *)(*piRam0202efc0 + 0x54) = *(int *)(*piRam0202efc0 + 0x54) + 1;
  }
  return;
}

