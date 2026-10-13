/* Decompiled C draft; module arm9; ROM address 020b302c. No matching claim. */
#include "types.h"
#include "deps/020b302c_func_020b302c.h"

int func_020b302c(void)

{
  short sVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  int *piVar9;
  short local_60 [4];
  int local_58;
  int local_54;
  int local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  short local_44 [24];
  
  local_58 = 0;
  iVar3 = func_020b2e98();
  if (iVar3 != 0) {
    MaybeOnMenuOptionScroll_from_thumb(0);
    local_50 = GetCurrentOptionMenuKind_from_thumb();
    local_50 = local_50 * 0x1c;
    local_54 = *(int *)(*piRam020b311c + local_50 + 0x50);
    for (iVar3 = 0; iVar3 < local_54; iVar3 = iVar3 + 1) {
      sVar1 = ((short)local_54 * -2 + 0xc + (short)iVar3 * 4) * 8;
      local_44[iVar3 * 4] = 8;
      local_44[iVar3 * 4 + 2] = 0xf8;
      local_44[iVar3 * 4 + 1] = sVar1 + 6;
      local_44[iVar3 * 4 + 3] = sVar1 + 0x1c;
    }
    local_48 = 0;
    piVar9 = &local_58;
    for (iVar3 = 0; iVar3 < local_54; iVar3 = iVar3 + 1) {
      uVar4 = Const8_0();
      local_4c = (undefined1 *)piVar9;
      psVar8 = local_44 + iVar3 * 4;
      iVar5 = 4;
      psVar7 = (short *)((int)piVar9 + -8);
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
        *psVar7 = sVar1;
        puVar2 = local_4c;
        psVar7 = psVar7 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      iVar5 = func_020ae244(uVar4,*(undefined4 *)((int)piVar9 + -8),
                            *(undefined4 *)((int)piVar9 + -4));
      if (iVar5 != 0) {
        iVar5 = *piRam020b311c;
        iVar6 = *(int *)(local_50 + iVar5 + iVar3 * 4 + 0x38);
        if (*(int *)(iVar5 + 0x28) == iVar6) {
          *(undefined4 *)(iVar5 + 0x10) = 1;
        }
        else {
          *(int *)(iVar5 + 0x28) = iVar6;
          MaybeOnMenuOptionScroll_from_thumb(local_48);
        }
        local_58 = 1;
      }
      piVar9 = (int *)puVar2;
    }
    if (local_58 != 0) {
      if (*(int *)(*piRam020b311c + 0x28) == 0) {
        func_02105c4c();
      }
      else {
        func_020b3278();
      }
    }
  }
  return local_58;
}

