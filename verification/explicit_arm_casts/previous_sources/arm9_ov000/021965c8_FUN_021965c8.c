/* Decompiled C draft; module arm9_ov000; ROM address 021965c8. No matching claim. */
#include "types.h"
#include "deps/021965c8_FUN_021965c8.h"

undefined4 FUN_021965c8(undefined4 param_1,int param_2,int *param_3,char *param_4,char *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_2 == 0) {
    func_0x0213442c(DAT_021966f0,DAT_021966f4,0,DAT_021966f8);
  }
  if (param_4 == (char *)0x0) {
    func_0x0213442c(DAT_021966fc,DAT_021966f4,0,DAT_02196700);
  }
  if (param_5 == (char *)0x0) {
    func_0x0213442c(DAT_02196704,DAT_021966f4,0,DAT_02196708);
  }
  iVar2 = DAT_02196710;
  iVar3 = param_2 + *param_3;
  if (*(char *)(param_2 + *param_3) == '\\') {
    iVar4 = 0;
    pcVar5 = (char *)(iVar3 + 2);
    cVar1 = *(char *)(iVar3 + 1);
    while( true ) {
      if (cVar1 == '\\') {
        iVar4 = 0;
        *param_4 = '\0';
        iVar2 = DAT_02196710;
        while( true ) {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          if ((cVar1 == '\\') || (cVar1 == '\0')) break;
          if (iVar4 == iVar2) {
            FUN_021965a0(param_1,1,DAT_0219670c);
            FUN_02190f4c(param_1,3,1);
            return 3;
          }
          *param_5 = cVar1;
          param_5 = param_5 + 1;
          iVar4 = iVar4 + 1;
        }
        *param_5 = '\0';
        *param_3 = (int)(pcVar5 + *param_3 + (-1 - iVar3));
        return 0;
      }
      if (cVar1 == '\0') {
        FUN_021965a0(param_1,1,DAT_0219670c);
        FUN_02190f4c(param_1,3,1);
        return 3;
      }
      if (iVar4 == iVar2) break;
      *param_4 = cVar1;
      param_4 = param_4 + 1;
      iVar4 = iVar4 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    }
    FUN_021965a0(param_1,1,DAT_0219670c);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  FUN_021965a0(param_1,1,DAT_0219670c);
  FUN_02190f4c(param_1,3,1);
  return 3;
}

