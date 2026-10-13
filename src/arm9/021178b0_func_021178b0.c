/* Decompiled C draft; module arm9; ROM address 021178b0. No matching claim. */
#include "types.h"
#include "deps/021178b0_func_021178b0.h"

void func_021178b0(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  short *psVar8;
  
  uVar6 = 0xffffffff;
  func_021184d4();
  func_02118414();
  bVar4 = false;
  bVar1 = false;
  psVar8 = (short *)(DAT_02117ba4 + 0x2e0);
  if ((*(short *)(DAT_02117ba4 + 0x2e0) == 0) && (*(ushort *)(DAT_02117ba8 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_02117bac + 0x2e0) == 0)) &&
     (*(short *)(DAT_02117ba4 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    uVar6 = func_0201ea84(*(undefined4 *)(*DAT_02117bb0 + 0x14),
                          *(undefined2 *)(DAT_02117bb4 + 0x2e0),
                          *(undefined2 *)(DAT_02117bb8 + 0x2e0));
  }
  puVar7 = (ushort *)(DAT_02117bbc + 0x2e0);
  if ((*(ushort *)(DAT_02117bbc + 0x2e0) & 2) == 0) {
    bVar4 = false;
    bVar1 = false;
    if ((*psVar8 == 0) && (*(ushort *)(DAT_02117ba8 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_02117bac + 0x2e0) == 0)) && (*psVar8 != 0)) {
      bVar4 = true;
    }
    if ((!bVar4) ||
       (iVar3 = func_02128210(*(undefined2 *)(DAT_02117bb4 + 0x2e0),
                              *(undefined2 *)(DAT_02117bb8 + 0x2e0)), iVar3 == 0)) {
      if (uVar6 < 8) {
        iVar3 = *(int *)(DAT_02117bc8 + uVar6 * 4);
        iVar5 = *DAT_02117bb0;
        if (*(int *)(iVar5 + iVar3 * 4 + 0x48) != 0) {
          if (*(int *)(iVar5 + 0x44) == iVar3) {
            *(undefined4 *)(iVar5 + 0x68) = 0;
          }
          *(int *)(*DAT_02117bb0 + 0x44) = iVar3;
          func_02118184();
          return;
        }
        if (*DAT_02117bc4 == 2) {
          return;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_02117bcc,0,0x16);
        return;
      }
      if ((*puVar7 & 1) != 0) {
        func_02118184();
        *(undefined4 *)(*DAT_02117bb0 + 0x68) = 0;
        return;
      }
      iVar3 = func_020ae408(8,0x40);
      if (iVar3 != 0) {
        iVar3 = *DAT_02117bb0;
        iVar5 = (int)*(short *)(DAT_02117bd0 + *(int *)(iVar3 + 0x44) * 2);
        if (iVar5 == 0) {
          return;
        }
        iVar5 = *(int *)(iVar3 + 0x44) + iVar5;
        if (*(int *)(iVar3 + iVar5 * 4 + 0x48) == 0) {
          return;
        }
        *(int *)(iVar3 + 0x44) = iVar5;
        func_02118400();
        if (*DAT_02117bc4 == 2) {
          return;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_02117bcc,0,0);
        return;
      }
      iVar3 = func_020ae408(8,0x80);
      if (iVar3 != 0) {
        iVar3 = *DAT_02117bb0;
        iVar5 = (int)*(short *)(DAT_02117bd4 + *(int *)(iVar3 + 0x44) * 2);
        if (iVar5 == 0) {
          return;
        }
        iVar5 = *(int *)(iVar3 + 0x44) + iVar5;
        if (*(int *)(iVar3 + iVar5 * 4 + 0x48) == 0) {
          return;
        }
        *(int *)(iVar3 + 0x44) = iVar5;
        func_02118400();
        if (*DAT_02117bc4 == 2) {
          return;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_02117bcc,0,0);
        return;
      }
      iVar3 = func_020ae408(8,0x20);
      if (iVar3 != 0) {
        iVar3 = *DAT_02117bb0;
        iVar5 = (int)*(short *)(DAT_02117bd8 + *(int *)(iVar3 + 0x44) * 2);
        if (iVar5 == 0) {
          return;
        }
        iVar5 = *(int *)(iVar3 + 0x44) + iVar5;
        if (*(int *)(iVar3 + iVar5 * 4 + 0x48) == 0) {
          return;
        }
        *(int *)(iVar3 + 0x44) = iVar5;
        func_02118400();
        if (*DAT_02117bc4 == 2) {
          return;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_02117bcc,0,0);
        return;
      }
      iVar3 = func_020ae408(8,0x10);
      if (iVar3 == 0) {
        return;
      }
      iVar3 = *DAT_02117bb0;
      iVar5 = (int)*(short *)(DAT_02117bdc + *(int *)(iVar3 + 0x44) * 2);
      if (iVar5 == 0) {
        return;
      }
      iVar5 = *(int *)(iVar3 + 0x44) + iVar5;
      if (*(int *)(iVar3 + iVar5 * 4 + 0x48) == 0) {
        return;
      }
      *(int *)(iVar3 + 0x44) = iVar5;
      func_02118400();
      if (*DAT_02117bc4 == 2) {
        return;
      }
      NNSi_MaybeSndPlayerStartSeq(DAT_02117bcc,0,0);
      return;
    }
  }
  iVar3 = func_021185d4();
  if (iVar3 == 0) {
    func_021281c8(0xe);
    switch(*(undefined4 *)(*DAT_02117bb0 + 0x3c)) {
    case 0:
    case 1:
      func_02118024();
      *(undefined4 *)(*DAT_02117bb0 + 0x88) = 2;
      func_02128310(0);
      return;
    case 2:
    case 3:
    case 4:
      if (*(int *)(*DAT_02117bc0 + 8) - 2U < 2) {
        func_02118088();
        if (*DAT_02117bc4 == 2) {
          func_021281c8(0xffffffff);
        }
        func_02128310(0);
        return;
      }
      func_02118024();
      piVar2 = DAT_02117bb0;
      *(undefined4 *)(*DAT_02117bb0 + 0x88) = 2;
      if (*(int *)(*piVar2 + 0x3c) == 2) {
        func_02128310(0);
        return;
      }
      func_02128310(1);
      if (*DAT_02117bc4 == 2) {
        func_0211f378();
        return;
      }
    }
  }
  return;
}

