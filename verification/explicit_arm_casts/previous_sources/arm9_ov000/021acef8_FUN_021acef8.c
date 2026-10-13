/* Decompiled C draft; module arm9_ov000; ROM address 021acef8. No matching claim. */
#include "types.h"
#include "deps/021acef8_FUN_021acef8.h"

int FUN_021acef8(undefined4 param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  undefined2 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  longlong lVar7;
  int local_34;
  int local_30;
  char local_20 [4];
  int local_1c;
  undefined2 local_18 [2];
  
  lVar7 = func_0x02133048((int)DAT_021acfd0[1],*(undefined4 *)((int)DAT_021acfd0 + 0xc),
                          (int)*DAT_021acfd0,*(undefined4 *)((int)DAT_021acfd0 + 4));
  plVar2 = DAT_021acfd0;
  plVar1 = DAT_021acfd0 + 2;
  *DAT_021acfd0 = lVar7 + *plVar1;
  local_18[0] = (undefined2)((ulonglong)(lVar7 + *plVar1) >> 0x30);
  lVar7 = func_0x02133048((int)plVar2[1],*(undefined4 *)((int)plVar2 + 0xc));
  *plVar2 = lVar7 + plVar2[2];
  local_18[1] = (undefined2)((ulonglong)(lVar7 + plVar2[2]) >> 0x30);
  iVar3 = FUN_021ad018(param_1,&local_1c);
  if (iVar3 != 0) {
    return local_1c;
  }
  local_20[0] = '\x01';
  local_20[1] = 1;
  local_34 = 0;
  local_30 = 0;
  do {
    pcVar5 = local_20;
    puVar4 = local_18;
    puVar6 = DAT_021acfd4;
    iVar3 = local_30;
    do {
      if (*pcVar5 != '\0') {
        local_1c = FUN_021acfd8(param_1,*puVar6,*puVar4);
        if ((local_1c != 0) && (local_1c != -1)) goto LAB_021acfba;
        if (local_1c == -1) {
          *pcVar5 = '\0';
        }
      }
      pcVar5 = pcVar5 + 1;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    local_34 = local_34 + 1;
  } while (local_34 < 3);
LAB_021acfba:
  if (local_1c == -1) {
    local_1c = 0;
  }
  return local_1c;
}

