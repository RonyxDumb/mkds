/* Decompiled C draft; module arm9_ov000; ROM address 021970fc. No matching claim. */
#include "types.h"
#include "deps/021970fc_FUN_021970fc.h"

char * FUN_021970fc(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined1 local_110 [260];
  
  puVar6 = local_110;
  iVar5 = DAT_02197180;
  puVar8 = DAT_0219717c;
  do {
    uVar1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar6 = uVar1;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *DAT_02197184 = *DAT_02197184 ^ 1;
  func_0x0213a1c0(local_110);
  func_0x0213a1c0(local_110,DAT_02197188);
  iVar5 = func_0x02139f70(param_1,local_110);
  if (iVar5 == 0) {
    return (char *)0x0;
  }
  iVar2 = func_0x0213a434(local_110);
  pcVar3 = (char *)(DAT_0219718c + *DAT_02197184 * 0x100);
  pcVar7 = pcVar3;
  for (pcVar4 = (char *)(iVar5 + iVar2); (*pcVar4 != '\0' && (*pcVar4 != '\\')); pcVar4 = pcVar4 + 1
      ) {
    *pcVar7 = *pcVar4;
    pcVar7 = pcVar7 + 1;
  }
  *pcVar7 = '\0';
  return pcVar3;
}

