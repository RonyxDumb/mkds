/* Decompiled C draft; module arm9_ov000; ROM address 021856a8. No matching claim. */
#include "types.h"
#include "deps/021856a8_FUN_021856a8.h"

void FUN_021856a8(void)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int iVar8;
  int local_38;
  undefined2 local_30;
  undefined2 local_2e;
  char local_2c [12];
  char local_20 [12];
  
  iVar8 = DAT_02185774;
  pcVar4 = local_2c;
  iVar3 = 0xc;
  pcVar6 = DAT_02185778;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pcVar4 = local_20;
  iVar3 = 0xc;
  pcVar6 = DAT_0218577c;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = *(undefined2 *)(*(int *)(*DAT_02185780 + 0x40) + 6);
  FUN_02185788();
  iVar3 = 0;
  pcVar4 = local_20;
  pcVar6 = local_2c;
  do {
    if (*pcVar4 == '\0') {
      *pcVar6 = *pcVar6 + (char)uVar2;
    }
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  local_38 = 0;
  pcVar4 = local_2c;
  iVar3 = 0;
  puVar7 = DAT_02185784;
  do {
    iVar5 = *DAT_02185780;
    iVar5 = func_0x021243ac(*(undefined4 *)(iVar5 + 0x2c),*puVar7,*(undefined4 *)(iVar5 + 0x48),8,
                            0x10,*pcVar4,*(undefined4 *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x40)
                            ,*(undefined4 *)(iVar5 + 0x30),iVar8);
    iVar8 = iVar8 - iVar5;
    local_2e = 0;
    iVar5 = *DAT_02185780;
    local_30 = *(undefined2 *)(iVar5 + iVar3 + 0xe);
    func_0x0212426c(0,*puVar7,*(undefined4 *)(iVar5 + 0x48),&local_30,*(undefined4 *)(iVar5 + 0x40),
                    *(undefined4 *)(iVar5 + 0x30));
    pcVar4 = pcVar4 + 1;
    puVar7 = puVar7 + 1;
    iVar3 = iVar3 + 2;
    local_38 = local_38 + 1;
  } while (local_38 < 0xc);
  return;
}

