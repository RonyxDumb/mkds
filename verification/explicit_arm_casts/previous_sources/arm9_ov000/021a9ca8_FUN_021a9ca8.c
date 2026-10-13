/* Decompiled C draft; module arm9_ov000; ROM address 021a9ca8. No matching claim. */
#include "types.h"
#include "deps/021a9ca8_FUN_021a9ca8.h"

void FUN_021a9ca8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  int local_8c;
  uint local_88;
  char acStack_84 [19];
  byte local_71 [93];
  
  if (*DAT_021a9d58 == '\0') {
    lVar7 = func_0x02133048((int)DAT_021a9d5c[1],*(undefined4 *)((int)DAT_021a9d5c + 0xc),
                            (int)*DAT_021a9d5c,*(undefined4 *)((int)DAT_021a9d5c + 4));
    local_88 = (uint)((ulonglong)(lVar7 + DAT_021a9d5c[2]) >> 0x20);
    *DAT_021a9d5c = lVar7 + DAT_021a9d5c[2];
    FUN_021a9c5c(&local_88,4);
  }
  iVar2 = 0x14;
  iVar5 = 0;
  if (0 < param_2) {
    local_8c = 0;
    do {
      if (iVar2 == 0x14) {
        FUN_021abd2c(local_71 + 1);
        uVar1 = func_0x0200fca0();
        FUN_021abca0(local_71 + 1,DAT_021a9d60,0x14);
        FUN_021abc24(local_71 + 1,acStack_84);
        uVar6 = 1;
        iVar2 = 0x13;
        pbVar4 = local_71;
        pbVar3 = DAT_021a9d64;
        do {
          local_88 = uVar6 + (uint)*pbVar3 + (uint)*pbVar4;
          *pbVar3 = (byte)local_88;
          uVar6 = local_88 >> 8;
          pbVar4 = pbVar4 + -1;
          pbVar3 = pbVar3 + -1;
          iVar2 = iVar2 + -1;
        } while (-1 < iVar2);
        func_0x0200fcb4(uVar1);
        iVar2 = local_8c;
      }
      if (acStack_84[iVar2] != '\0') {
        *(char *)(param_1 + iVar5) = acStack_84[iVar2];
        iVar5 = iVar5 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar5 < param_2);
  }
  return;
}

