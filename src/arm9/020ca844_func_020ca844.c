/* Decompiled C draft; module arm9; ROM address 020ca844. No matching claim. */
#include "types.h"
#include "deps/020ca844_func_020ca844.h"

void func_020ca844(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = piRam020ca980;
  *(int *)(*piRam020ca980 + 0x24) = *(int *)(*piRam020ca980 + 0x24) + 1;
  if (0x31 < *(int *)(*piVar3 + 0x24)) {
    *(undefined4 *)(*piVar3 + 0x24) = 0;
  }
  piVar3 = (int *)*piRam020ca980;
  if ((((piVar3[5] == 0) && (piVar3[6] == 0)) && (*piVar3 != 0)) && (piVar3[1] != 0)) {
    iVar1 = func_020cacc0();
    if (iVar1 == 0) {
      uVar2 = func_020ca9dc();
      iVar1 = func_020ca9ac(uVar2,1);
      piVar3 = piRam020ca980;
      if (iVar1 == 0) {
        uVar2 = func_020ca9dc();
        iVar1 = func_020ca9ac(uVar2,10);
        if (iVar1 != 0) {
          *(undefined4 *)(*piRam020ca980 + 0x18) = 1;
          func_020ca984(0x10);
        }
      }
      else {
        *(undefined4 *)(*piRam020ca980 + 0x14) = 1;
        *(undefined4 *)(*piVar3 + 0x10) = 1;
        iVar1 = *(int *)(*piVar3 + 0x20);
        if (iVar1 == 0) {
          func_020ca984(0x10);
        }
        else if (iVar1 == 1) {
          func_020ca984(0xb);
        }
        else if (iVar1 == 2) {
          func_020ca984(5);
        }
      }
    }
    else {
      *(undefined4 *)(*piRam020ca980 + 0x14) = 1;
    }
    uVar2 = func_020ca9dc();
    iVar1 = func_020ca9ac(uVar2,0x40);
    if (iVar1 == 0) {
      uVar2 = func_020ca9dc();
      iVar1 = func_020ca9ac(uVar2,0x80);
      if (iVar1 != 0) {
        func_020cadac(1);
      }
    }
    else {
      func_020cadac(0xffffffff);
    }
  }
  piVar3 = piRam020ca980;
  iVar1 = *(int *)(*piRam020ca980 + 0x14);
  if (iVar1 != 0) {
    *(int *)(*piRam020ca980 + 0x14) = iVar1 + 1;
    piVar4 = (int *)*piVar3;
    if (0xf < piVar4[5]) {
      if (*piVar4 != 0) {
        piVar4[7] = piVar4[8];
        *(undefined4 *)(*piVar3 + 0x14) = 0;
      }
      piVar3 = piRam020ca980;
      *(undefined4 *)(*piRam020ca980 + 0x14) = 0;
      *(undefined4 *)(*piVar3 + 0x10) = 0;
    }
  }
  piVar3 = piRam020ca980;
  iVar1 = *(int *)(*piRam020ca980 + 0x18);
  if (iVar1 != 0) {
    *(int *)(*piRam020ca980 + 0x18) = iVar1 + 1;
    piVar4 = (int *)*piVar3;
    if (4 < piVar4[6]) {
      if (*piVar4 != 0) {
        piVar4[7] = -2;
        *(undefined4 *)(*piVar3 + 0x14) = 0;
      }
      *(undefined4 *)(*piRam020ca980 + 0x18) = 0;
    }
  }
  return;
}

