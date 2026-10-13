/* Decompiled C draft; module arm9; ROM address 0211ccac. No matching claim. */
#include "types.h"
#include "deps/0211ccac_func_0211ccac.h"

void func_0211ccac(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam0211cdd8;
  iVar4 = *piRam0211cdd8 + 0x68;
  iVar3 = *(int *)(*piRam0211cdd8 + 0x60) * 4;
  *(int *)(iVar4 + iVar3) = *(int *)(iVar4 + iVar3) + 1;
  iVar4 = *(int *)(*piVar1 + 0x60);
  iVar3 = *piVar1 + 0x68;
  iVar5 = iVar4 * 4;
  if ((int)(uint)*(ushort *)(iRam0211cddc + iVar4 * 2) <= *(int *)(iVar3 + iVar5)) {
    *(undefined4 *)(iVar3 + iVar5) = 0;
  }
  iVar3 = func_0211cea8();
  if (iVar3 == 0) {
    func_0211ccac(0);
  }
  iVar3 = *piRam0211cdd8;
  if (*(int *)(iVar3 + 0x60) == 3) {
    if (*(int *)(iVar3 + 0x74) == 0) {
      func_0211d910((int)*(short *)(iVar3 + 0x88));
    }
    else if (*(int *)(iVar3 + 0x74) == 1) {
      func_0211d844((int)*(short *)(iVar3 + 0x8a));
    }
    piVar1 = piRam0211cdd8;
    iVar4 = 0;
    iVar3 = 0;
    do {
      *(undefined2 *)(*piVar1 + iVar3 + 0x50) = 0;
      iVar3 = iVar3 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
  }
  else {
    iVar4 = *(int *)(iVar3 + 0x60) * 4;
    uVar2 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(iVar3 + 0x1c),
                       *(undefined2 *)
                        (*(int *)(iRam0211cde0 + iVar4) + *(int *)(iVar3 + iVar4 + 0x68) * 2));
    func_0212426c(1,*(undefined2 *)(iRam0211cde4 + *(int *)(iVar3 + 0x60) * 4),
                  *(undefined4 *)(iVar3 + 0xc),uVar2,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x14));
  }
  piVar1 = piRam0211cdd8;
  if (*(int *)(*piRam0211cdd8 + 0x60) == 4) {
    iVar3 = 0;
    iVar4 = 0;
    do {
      *(undefined2 *)(*piVar1 + iVar4 + 0x54) = 0;
      iVar4 = iVar4 + 2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
  }
  if (*(int *)(*piRam0211cdd8 + 0x60) == 1) {
    if (*(int *)(*piRam0211cdd8 + 0x6c) == 0) {
      iVar3 = func_0211cdec();
      if (iVar3 == 0) {
        func_0211d09c();
      }
      func_0202b618(0);
    }
    else {
      iVar3 = func_0211cdec();
      if (iVar3 == 0) {
        func_0211cfd0();
      }
      func_0202b618(1);
    }
  }
  *(undefined2 *)(*piRam0211cdd8 + *(int *)(*piRam0211cdd8 + 0x60) * 4 + 0x3e) = 6;
  if (param_1 != 0) {
    NNSi_MaybeSndPlayerStartSeq(uRam0211cde8,0,1);
  }
  return;
}

