/* Decompiled C draft; module arm9; ROM address 020aafa8. No matching claim. */
#include "types.h"
#include "deps/020aafa8_func_020aafa8.h"

void func_020aafa8(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_24;
  int local_20;
  
  puVar4 = *(ushort **)(*(int *)(param_1 + 0x2c) + 4);
  uVar1 = puVar4[1];
  uVar7 = (uint)uVar1;
  uVar2 = *puVar4;
  Mem_CpuFill16(uVar2 * uVar1,*(undefined4 *)(iRam020ab024 + 0xc),
                *(int *)(iRam020ab024 + 0x10) * 2 * *(int *)(iRam020ab024 + 0x14));
  iVar3 = iRam020ab024;
  iVar8 = 0;
  if (uVar2 != 0) {
    local_24 = 0;
    local_20 = 0;
    do {
      iVar6 = local_20;
      if (uVar7 != 0) {
        do {
          iVar5 = _s32_div_f(*(int *)(iVar3 + 0x14) * iVar8,2);
          *(ushort *)(*(int *)(iVar3 + 0xc) + (iVar6 + iVar5) * 2) =
               (ushort)(*(int *)(iVar3 + 0x18) << 0xc) |
               (short)iVar6 + (short)*(undefined4 *)(iVar3 + 0x1c) + (short)local_24;
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)uVar7);
      }
      local_24 = local_24 + uVar7;
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)uVar2);
  }
  return;
}

