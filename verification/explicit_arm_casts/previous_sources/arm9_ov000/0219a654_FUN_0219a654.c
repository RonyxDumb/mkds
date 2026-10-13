/* Decompiled C draft; module arm9_ov000; ROM address 0219a654. No matching claim. */
#include "types.h"
#include "deps/0219a654_FUN_0219a654.h"

undefined4 FUN_0219a654(char *param_1,int *param_2,undefined2 *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  int unaff_r7;
  char acStack_118 [260];
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    unaff_r7 = 0;
    uVar6 = 0;
  }
  else {
    pcVar2 = (char *)func_0x02139ffc(param_1,0x3a);
    if (pcVar2 == (char *)0x0) {
      uVar6 = 0;
    }
    else {
      if (pcVar2 == param_1) {
        param_1 = (char *)0x0;
        unaff_r7 = 0;
      }
      else {
        iVar4 = (int)pcVar2 - (int)param_1;
        if (DAT_0219a74c <= iVar4) {
          func_0x0213442c(DAT_0219a750,DAT_0219a754,0,0x81);
        }
        func_0x02134eb8(acStack_118,param_1,iVar4);
        param_1 = acStack_118;
        param_1[iVar4] = '\0';
      }
      pcVar3 = pcVar2 + 1;
      cVar1 = pcVar2[1];
      while (iVar4 = (int)cVar1, iVar4 != 0) {
        if ((iVar4 < 0) || (0x7f < iVar4)) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(ushort *)(DAT_0219a758 + iVar4 * 2) & 8;
        }
        if (uVar5 == 0) {
          return 0;
        }
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
      iVar4 = func_0x0213bf90(pcVar2 + 1);
      if ((iVar4 < 0) || (DAT_0219a75c < iVar4)) {
        return 0;
      }
      uVar6 = (undefined2)iVar4;
    }
    if ((param_1 != (char *)0x0) && (unaff_r7 = FUN_0218e374(param_1), unaff_r7 == -1)) {
      iVar4 = FUN_021a8f84(param_1);
      if (iVar4 == 0) {
        return 0;
      }
      unaff_r7 = *(int *)**(undefined4 **)(iVar4 + 0xc);
    }
  }
  if (param_2 != (int *)0x0) {
    *param_2 = unaff_r7;
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = uVar6;
  }
  return 1;
}

