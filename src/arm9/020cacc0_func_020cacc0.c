/* Decompiled C draft; module arm9; ROM address 020cacc0. No matching claim. */
#include "types.h"
#include "deps/020cacc0_func_020cacc0.h"

undefined4 func_020cacc0(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  undefined4 *puVar8;
  short local_60 [4];
  undefined4 local_58;
  int local_54;
  undefined1 *local_50;
  undefined4 local_4c;
  short local_48 [26];
  
  local_58 = 0;
  if (*(int *)*piRam020cada8 != 0) {
    func_020cadac(0);
    local_54 = *(int *)(*piRam020cada8 + 0x28);
    for (iVar6 = 0; iVar6 < local_54; iVar6 = iVar6 + 1) {
      sVar1 = ((short)local_54 * -2 + 0xc + (short)iVar6 * 4) * 8;
      local_48[iVar6 * 4] = 8;
      local_48[iVar6 * 4 + 2] = 0xf8;
      local_48[iVar6 * 4 + 1] = sVar1 + 6;
      local_48[iVar6 * 4 + 3] = sVar1 + 0x1c;
    }
    local_4c = 0;
    puVar8 = &local_58;
    for (iVar6 = 0; iVar6 < local_54; iVar6 = iVar6 + 1) {
      uVar3 = func_020ca9dc();
      local_50 = (undefined1 *)puVar8;
      psVar7 = local_48 + iVar6 * 4;
      iVar4 = 4;
      psVar5 = (short *)((int)puVar8 + -8);
      do {
        sVar1 = *psVar7;
        psVar7 = psVar7 + 1;
        *psVar5 = sVar1;
        puVar2 = local_50;
        psVar5 = psVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar4 = func_020ae244(uVar3,*(undefined4 *)((int)puVar8 + -8),
                            *(undefined4 *)((int)puVar8 + -4));
      if (iVar4 != 0) {
        iVar4 = *piRam020cada8;
        if (*(int *)(iVar4 + 0x20) == iVar6) {
          *(undefined4 *)(iVar4 + 0x10) = 1;
        }
        else {
          *(int *)(iVar4 + 0x20) = iVar6;
          func_020cadac(local_4c);
        }
        iVar4 = *(int *)(*piRam020cada8 + 0x20);
        if (iVar4 == 0) {
          func_020ca984(0x10);
        }
        else if (iVar4 == 1) {
          func_020ca984(0xb);
        }
        else if (iVar4 == 2) {
          func_020ca984(5);
        }
        local_58 = 1;
      }
      puVar8 = (undefined4 *)puVar2;
    }
  }
  return local_58;
}

