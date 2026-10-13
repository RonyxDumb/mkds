/* Decompiled C draft; module arm9_ov000; ROM address 021a8b20. No matching claim. */
#include "types.h"
#include "deps/021a8b20_FUN_021a8b20.h"

int FUN_021a8b20(undefined4 *param_1,uint param_2,uint param_3,int param_4)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  uint local_20;
  int local_1c;
  
  local_20 = param_3;
  local_1c = param_4;
  if (param_4 == -1 && param_3 == 0xffffffff) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  while( true ) {
    iVar5 = 0;
    uVar6 = 0;
    puVar4 = param_1;
    if (param_2 != 0) {
      do {
        sVar1 = *(short *)(puVar4 + 1);
        uVar3 = FUN_021a8994(*puVar4);
        uVar3 = ((int)sVar1 | 0xe0U) & uVar3;
        if (uVar3 != 0) {
          iVar5 = iVar5 + 1;
        }
        *(short *)((int)puVar4 + 6) = (short)uVar3;
        puVar4 = puVar4 + 2;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2);
    }
    if ((0 < iVar5) || ((bVar2 && ((int)(uint)(local_20 != 0) <= -local_1c)))) break;
    func_0x0200dc3c(1);
    bVar7 = local_20 < DAT_021a8bac;
    local_20 = local_20 - DAT_021a8bac;
    local_1c = local_1c - (uint)bVar7;
  }
  return iVar5;
}

