/* Decompiled C draft; module arm9; ROM address 02078420. No matching claim. */
#include "types.h"
#include "deps/02078420_func_02078420.h"

void func_02078420(int param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *piRam020784ec;
  *(int *)(iVar8 + iRam020784f0) = param_1;
  func_02077b3c();
  func_020789f4();
  iVar6 = *piRam020784ec;
  sVar1 = *(short *)(iVar6 + iRam020784f4);
  if (-1 < sVar1) {
    if ((*(int *)(iVar6 + iRam020784f8) == 0) && (*(int *)(iVar6 + iRam020784fc) == 0)) {
      *(short *)(iVar8 + 0x38) = *(short *)(iVar8 + 0x38) + 100;
    }
    else {
      func_02077f0c((ushort *)(uintptr_t)(iVar8 + 0x38),uRam02078500,*puRam02078504);
      iVar4 = iRam02078508;
      iVar3 = iRam020784fc;
      piVar2 = piRam020784ec;
      iVar7 = *piRam020784ec;
      if (*(int *)(iVar7 + iRam020784f8) == 0) {
        if (*(int *)(iVar7 + iRam020784fc) != 0) {
          *(short *)(iVar7 + iRam02078508) = *(short *)(iVar7 + iRam02078508) + 1;
          if (0x3c < *(short *)(*piVar2 + iVar4)) {
            *(undefined4 *)(*piVar2 + iVar3) = 0;
          }
        }
      }
    }
    if (param_1 == 0) {
      sVar5 = *(short *)(iVar8 + 0x38);
    }
    else {
      sVar5 = -*(short *)(iVar8 + 0x38);
    }
    *(short *)(iVar8 + 0x3a) = sVar5;
    Animation_Update(*(undefined4 *)(iVar6 + sVar1 * 0xb8 + 0x60));
    iVar6 = *piRam020784ec;
    if ((*(int *)(iVar6 + iRam0207850c) != 0) && (*(int *)(iVar6 + iRam02078510) != 0)) {
      if (*(int *)(iVar6 + *(short *)(iVar6 + iRam02078514) * 0x34 + iRam02078518) == 0) {
        func_02078e4c();
      }
    }
  }
  func_02077b1c();
  return;
}

