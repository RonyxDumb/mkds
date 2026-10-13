/* Decompiled C draft; module arm9_ov000; ROM address 02190ff8. No matching claim. */
#include "types.h"
#include "deps/02190ff8_FUN_02190ff8.h"

void FUN_02190ff8(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 auStack_18 [8];
  
  iVar3 = *param_1;
  iVar2 = *(int *)(iVar3 + DAT_0219113c);
  if (iVar2 != 4) {
    if (iVar2 != 0) {
      if ((param_2 != 0) && (iVar2 == 3)) {
        FUN_02190b80(param_1,iVar3 + DAT_02191140,DAT_02191144);
        FUN_02190b58(param_1,iVar3 + DAT_02191140,*(undefined4 *)(iVar3 + DAT_02191148));
        FUN_02190b80(param_1,iVar3 + DAT_02191140,DAT_0219114c);
      }
      FUN_021906e4(param_1,*(undefined4 *)(iVar3 + DAT_02191154),iVar3 + DAT_02191140,auStack_18,1,
                   DAT_02191150);
      if (*(int *)(iVar3 + DAT_02191154) != -1) {
        FUN_0218e524(*(int *)(iVar3 + DAT_02191154),2);
        FUN_0218e53c(*(undefined4 *)(iVar3 + DAT_02191154));
        *(undefined4 *)(iVar3 + DAT_02191154) = 0xffffffff;
      }
      if (*(int *)(iVar3 + DAT_02191158) != -1) {
        FUN_0218e524(*(int *)(iVar3 + DAT_02191158),2);
        FUN_0218e53c(*(undefined4 *)(iVar3 + DAT_02191158));
        *(undefined4 *)(iVar3 + DAT_02191158) = 0xffffffff;
      }
      *(undefined4 *)(iVar3 + DAT_0219113c) = 4;
      *(undefined4 *)(iVar3 + DAT_0219115c) = 0;
      *(undefined4 *)(iVar3 + DAT_02191160) = 0;
    }
    FUN_021a3668(*(undefined4 *)(iVar3 + DAT_02191164));
    *(undefined4 *)(iVar3 + DAT_02191164) = 0;
    FUN_021a3668(*(undefined4 *)(iVar3 + DAT_02191168));
    *(undefined4 *)(iVar3 + DAT_02191168) = 0;
    FUN_021a3668(*(undefined4 *)(iVar3 + DAT_02191140));
    *(undefined4 *)(iVar3 + DAT_02191140) = 0;
    FUN_021a3668(*(undefined4 *)(iVar3 + DAT_0219116c));
    *(undefined4 *)(iVar3 + DAT_0219116c) = 0;
    FUN_021a3668(*(undefined4 *)(iVar3 + DAT_02191170));
    *(undefined4 *)(iVar3 + DAT_02191170) = 0;
    piVar4 = (int *)(iVar3 + DAT_02191174);
    iVar2 = *piVar4;
    while (iVar2 != 0) {
      FUN_02193818(param_1);
      iVar2 = *piVar4;
    }
    *(undefined4 *)(iVar3 + DAT_02191174) = 0;
    iVar2 = *(int *)(iVar3 + DAT_02191178);
    while (iVar2 != 0) {
      iVar5 = *(int *)(iVar2 + 0x3c);
      FUN_02194120(param_1,iVar2);
      iVar2 = iVar5;
    }
    *(undefined4 *)(iVar3 + DAT_02191178) = 0;
    uVar1 = DAT_0219117c;
    do {
      iVar2 = FUN_02194840(param_1,uVar1,0);
    } while (iVar2 == 0);
  }
  return;
}

