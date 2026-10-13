/* Decompiled C draft; module arm9; ROM address 0211256c. No matching claim. */
#include "types.h"
#include "deps/0211256c_func_0211256c.h"

void func_0211256c(void)

{
  short sVar1;
  int *piVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  short *psVar9;
  
  uVar8 = 0xffffffff;
  func_021137f4();
  func_021136f8();
  bVar6 = true;
  bVar7 = false;
  psVar9 = (short *)(iRam02112880 + 0x2e0);
  if ((*(short *)(iRam02112880 + 0x2e0) == 0) && (*(ushort *)(iRam02112884 + 0x2e0) < 5)) {
    bVar7 = true;
  }
  if ((!bVar7) && (*(short *)(iRam02112880 + 0x2e0) == 0)) {
    bVar6 = false;
  }
  uVar3 = uVar8;
  if (bVar6) {
    uVar3 = func_0201ea84(*(undefined4 *)(*piRam02112888 + 0x34),
                          *(undefined2 *)(iRam0211288c + 0x2e0),
                          *(undefined2 *)(iRam02112890 + 0x2e0));
  }
  bVar7 = false;
  bVar6 = false;
  sVar1 = *psVar9;
  if ((sVar1 == 0) && (*(ushort *)(iRam02112884 + 0x2e0) < 5)) {
    bVar6 = true;
  }
  if (((!bVar6) && (*(short *)(iRam02112894 + 0x2e0) == 0)) && (sVar1 != 0)) {
    bVar7 = true;
  }
  if (bVar7) {
    uVar8 = func_0201ea84(*(undefined4 *)(*piRam02112888 + 0x34),
                          *(undefined2 *)(iRam0211288c + 0x2e0),
                          *(undefined2 *)(iRam02112890 + 0x2e0));
  }
  if (uVar3 != 10) {
    *(undefined4 *)(*piRam02112888 + 0x88) = 0;
  }
  if (uVar3 != 0xb) {
    *(undefined4 *)(*piRam02112888 + 0x8c) = 0;
  }
  puVar4 = (ushort *)(iRam02112898 + 0x2e0);
  if ((*(ushort *)(iRam02112898 + 0x2e0) & 2) == 0) {
    bVar7 = false;
    bVar6 = false;
    sVar1 = *psVar9;
    if ((sVar1 == 0) && (*(ushort *)(iRam02112884 + 0x2e0) < 5)) {
      bVar6 = true;
    }
    if (((!bVar6) && (*(short *)(iRam02112894 + 0x2e0) == 0)) && (sVar1 != 0)) {
      bVar7 = true;
    }
    if ((!bVar7) ||
       (iVar5 = func_02128210(*(undefined2 *)(iRam0211288c + 0x2e0),
                              *(undefined2 *)(iRam02112890 + 0x2e0)), iVar5 == 0)) {
      if (((uVar3 == 10) && (*(int *)(*piRam02112888 + 0x88) != 0)) ||
         (((uVar8 == 10 && (*(int *)(*piRam02112888 + 0x88) == 0)) ||
          ((*(ushort *)(iRam0211289c + 0x2e0) & 0x20) != 0)))) {
        iVar5 = func_02113790();
        piVar2 = piRam02112888;
        if (iVar5 != 0) {
          return;
        }
        if (*(int *)(*(int *)(*piRam02112888 + 0x3c) + iRam021128a0) == 0) {
          return;
        }
        *(undefined4 *)(*piRam02112888 + 0x6c) = 1;
        *(undefined4 *)(*piVar2 + 0x80) = 6;
        *(undefined4 *)(*piVar2 + 0x88) = 1;
        func_02113458();
        NNSi_MaybeSndPlayerStartSeq(uRam021128a4,0,2);
        return;
      }
      if ((((uVar3 == 0xb) && (*(int *)(*piRam02112888 + 0x8c) != 0)) ||
          ((uVar8 == 0xb && (*(int *)(*piRam02112888 + 0x8c) == 0)))) ||
         ((*(ushort *)(iRam0211289c + 0x2e0) & 0x10) != 0)) {
        iVar5 = func_02113790();
        piVar2 = piRam02112888;
        if (iVar5 != 0) {
          return;
        }
        if (*(int *)(*(int *)(*piRam02112888 + 0x3c) + iRam021128a8) == 0) {
          return;
        }
        *(undefined4 *)(*piRam02112888 + 0x6c) = 0;
        *(undefined4 *)(*piVar2 + 0x84) = 6;
        *(undefined4 *)(*piVar2 + 0x8c) = 1;
        func_02113458();
        NNSi_MaybeSndPlayerStartSeq(uRam021128a4,0,2);
        return;
      }
      if (uVar8 - 5 < 5) {
        sVar1 = *(short *)(iRam021128ac + uVar8 * 2);
        iVar5 = func_02113ef0((int)sVar1);
        if (iVar5 == 0) {
          return;
        }
        *(short *)(*piRam02112888 + 0x68) = sVar1;
        func_021137a8((int)sVar1);
        return;
      }
      if (uVar8 < 5) {
        sVar1 = *(short *)(iRam021128ac + uVar8 * 2);
        iVar5 = (int)sVar1;
        if (iVar5 == *(short *)(*piRam02112888 + 0x68)) {
          func_021137a8(iVar5);
          return;
        }
        iVar5 = func_02113ef0(iVar5);
        if (iVar5 == 0) {
          return;
        }
        *(short *)(*piRam02112888 + 0x68) = sVar1;
        NNSi_MaybeSndPlayerStartSeq(uRam021128a4,0,0);
        return;
      }
      if ((uVar8 == 0xc) || ((*puVar4 & uRam021128b0) != 0)) {
        func_021132b4();
        *(undefined4 *)(*piRam02112888 + 0x90) = 4;
        return;
      }
      if ((*puVar4 & 1) != 0) {
        func_021137a8((int)*(short *)(*piRam02112888 + 0x68));
        return;
      }
      iVar5 = func_020ae408(8,0x40);
      if (iVar5 == 0) {
        iVar5 = func_020ae408(8,0x80);
        if (iVar5 == 0) {
          return;
        }
        func_02113940();
        return;
      }
      func_021138e4();
      return;
    }
  }
  iVar5 = func_02113790();
  if (iVar5 != 0) {
    return;
  }
  func_0211340c();
  iVar5 = func_0211146c();
  if (iVar5 == 0xc) {
    *(undefined4 *)(*piRam02112888 + 0x90) = 6;
    func_02128310(1);
    return;
  }
  *(undefined4 *)(*piRam02112888 + 0x90) = 0;
  func_02128310();
  return;
}

