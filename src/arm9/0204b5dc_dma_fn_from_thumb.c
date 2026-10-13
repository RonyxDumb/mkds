/* Decompiled C draft; module arm9; ROM address 0204b5dc. No matching claim. */
#include "types.h"
#include "deps/0204b5dc_dma_fn_from_thumb.h"

void dma_fn_from_thumb(code *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  bVar1 = true;
  uVar3 = Card_GetResult();
  CleanupUnlockBackup_from_thumb();
  iVar6 = 0;
  *(undefined4 *)(*DAT_0204b6c8 + 0x10) = 0;
  piVar2 = DAT_0204b6c8;
  switch(uVar3) {
  case 0:
    break;
  case 1:
  case 4:
  case 6:
    iVar6 = 2;
    break;
  default:
    iVar6 = 1;
  }
  iVar4 = *DAT_0204b6c8;
  uVar7 = *(undefined4 *)(iVar4 + 0x40);
  uVar3 = *(undefined4 *)(iVar4 + 0x48);
  iVar5 = *(int *)(iVar4 + 0x14);
  if (iVar5 == 0) {
    bVar1 = true;
  }
  else if (iVar5 == 1) {
    *(int *)(iVar4 + 0x1c) = iVar6;
    *(undefined4 *)(*piVar2 + 0x20) = *(undefined4 *)(*piVar2 + 0x40);
    *(undefined2 *)(*piVar2 + 0x24) = 0;
    iVar4 = *piVar2;
    SV_MaybeCompressWriteImpl_from_thumb
              (*(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar4 + 0x40),
               *(undefined4 *)(iVar4 + 0x48),param_1,2,*(undefined4 *)(iVar4 + 0x50));
    bVar1 = false;
  }
  else if ((iVar5 == 2) && (iVar6 != 0)) {
    iVar5 = *(int *)(iVar4 + 0x1c);
    if (iVar5 == 0) {
      uVar7 = *(undefined4 *)(iVar4 + 0x20);
      iVar6 = 0;
    }
    else if ((iVar6 == 2) || (iVar5 == 2)) {
      iVar6 = 2;
    }
    else if ((iVar6 == 1) || (iVar5 == 1)) {
      iVar6 = 1;
    }
    else {
      iVar6 = 3;
    }
  }
  if (bVar1) {
    if (iVar6 == 0) {
      if (param_1 != (code *)0x0) {
        (*param_1)(uVar7,uVar3);
      }
      SX1Zero_from_thumb();
      return;
    }
    if (iVar6 == 2) {
      *(undefined4 *)(*DAT_0204b6c8 + 0xc) = 0;
    }
    func_0204b344(iVar6);
  }
  return;
}

