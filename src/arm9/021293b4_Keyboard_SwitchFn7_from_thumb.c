/* Decompiled C draft; module arm9; ROM address 021293b4. No matching claim. */
#include "types.h"
#include "deps/021293b4_Keyboard_SwitchFn7_from_thumb.h"

void Keyboard_SwitchFn7_from_thumb(void)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  bVar2 = false;
  iVar7 = -1;
  bVar1 = false;
  if ((*(short *)(DAT_021295bc + 0x2e0) == 0) && (*(ushort *)(DAT_021295c0 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_021295c4 + 0x2e0) == 0)) &&
     (*(short *)(DAT_021295bc + 0x2e0) != 0)) {
    bVar2 = true;
  }
  if (bVar2) {
    iVar7 = func_0201ea84(*(undefined4 *)(*DAT_021295c8 + 0xa8),
                          *(undefined2 *)(DAT_021295cc + 0x2e0),
                          *(undefined2 *)(DAT_021295d0 + 0x2e0));
  }
  iVar4 = *DAT_021295c8;
  iVar6 = *(int *)(iVar4 + 4);
  uVar5 = func_020ab798();
  CopyMemory16(uVar5,iVar4 + 0x2c + iVar6 * 0x18,0x18);
  func_021296b4();
  if ((iVar7 == 5) ||
     ((iVar4 = func_020ab8c4(), iVar4 == 1 && ((*(ushort *)(DAT_021295d4 + 0x2e0) & 1) != 0)))) {
    piVar3 = DAT_021295c8;
    if (*(int *)(*DAT_021295c8 + 0x1c) == 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_021295d8,0,0x16);
    }
    else {
      *(undefined4 *)(*DAT_021295c8 + 0x10) = 8;
      *(undefined4 *)(*piVar3 + 0x6c) = 1;
      TextSystem_CloseDialog_from_thumb();
      func_020ab8cc(1);
      *(undefined4 *)(*DAT_021295c8 + 0x24) = 0;
      NNSi_MaybeSndPlayerStartSeq(DAT_021295d8,0,4);
    }
  }
  else if ((iVar7 == 6) ||
          ((iVar4 = func_020ab8c4(), piVar3 = DAT_021295c8, iVar4 == 2 &&
           ((*(ushort *)(DAT_021295d4 + 0x2e0) & 1) != 0)))) {
    piVar3 = DAT_021295c8;
    if (*(int *)(*DAT_021295c8 + 0x20) == 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_021295d8,0,0x16);
    }
    else {
      *(undefined4 *)(*DAT_021295c8 + 0x10) = 8;
      *(undefined4 *)(*piVar3 + 0x6c) = 0;
      TextSystem_CloseDialog_from_thumb();
      func_020ab8cc(2);
      *(undefined4 *)(*DAT_021295c8 + 0x24) = 0;
      NNSi_MaybeSndPlayerStartSeq(DAT_021295d8,0,0xe);
    }
  }
  else if ((*(ushort *)(DAT_021295d4 + 0x2e0) & DAT_021295dc) == 0) {
    iVar4 = *DAT_021295c8;
    iVar6 = *(int *)(iVar4 + 8);
    bVar1 = false;
    switch(iVar7) {
    case 0:
      *(undefined4 *)(iVar4 + 8) = 1;
      func_020ab9d0(*(undefined4 *)(*piVar3 + 8));
      bVar1 = true;
      break;
    case 1:
      *(undefined4 *)(iVar4 + 8) = 2;
      func_020ab9d0(*(undefined4 *)(*piVar3 + 8));
      bVar1 = true;
      break;
    case 2:
      *(undefined4 *)(iVar4 + 8) = 3;
      func_020ab9d0(*(undefined4 *)(*piVar3 + 8));
      bVar1 = true;
      break;
    case 3:
      *(undefined4 *)(iVar4 + 8) = 4;
      func_020ab9d0(*(undefined4 *)(*piVar3 + 8));
      bVar1 = true;
      break;
    case 4:
      *(undefined4 *)(iVar4 + 8) = 5;
      func_020ab9d0(*(undefined4 *)(*piVar3 + 8));
      bVar1 = true;
    }
    if (bVar1) {
      if (iVar6 == *(int *)(*DAT_021295c8 + 8)) {
        NNSi_MaybeSndPlayerStartSeq(DAT_021295d8,0,DAT_021295f0);
      }
      else {
        NNSi_MaybeSndPlayerStartSeq(DAT_021295d8,0,DAT_021295ec);
      }
    }
  }
  else {
    if (*(int *)*DAT_021295e0 == 0) {
      *(uint *)(*DAT_021295c8 + 8) = (uint)*(byte *)(DAT_021295e4 + *(int *)(*DAT_021295c8 + 8));
    }
    else {
      *(uint *)(*DAT_021295c8 + 8) = (uint)*(byte *)(DAT_021295e8 + *(int *)(*DAT_021295c8 + 8));
    }
    func_020ab9d0(*(undefined4 *)(*DAT_021295c8 + 8));
    NNSi_MaybeSndPlayerStartSeq(DAT_021295d8,0,DAT_021295ec);
  }
  func_02128b0c();
  return;
}

