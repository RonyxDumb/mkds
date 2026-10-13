/* Decompiled C draft; module arm9; ROM address 0203003c. No matching claim. */
#include "types.h"
#include "deps/0203003c_func_0203003c.h"

void func_0203003c(int param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int local_40;
  uint local_3c;
  ushort *local_38;
  int local_24;
  uint local_1c [2];
  
  iVar5 = *piRam020301ec;
  local_1c[0] = *puRam020301f0;
  local_1c[1] = puRam020301f0[1];
  iVar4 = 0;
  local_40 = 0;
  local_38 = puRam020301f4;
  local_24 = 0;
  do {
    local_3c = 0;
    if ((*(int *)(*piRam020301ec + 0x48) == local_40) && (param_1 != 0)) {
      local_3c = 1;
    }
    uVar1 = *(uint *)(*piRam020301ec + iVar4 + 0x58);
    *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)*local_38 * 0x40) = local_3c;
    *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[0xc] * 0x40) = (uint)(local_3c == 0);
    iVar2 = 1;
    puVar3 = local_38;
    do {
      *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)puVar3[1] * 0x40) = local_3c & uVar1;
      *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)puVar3[0xd] * 0x40) = local_3c == 0 & uVar1;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < 0xc);
    *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[1] * 0x40) =
         *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[1] * 0x40) &
         *(uint *)(*piRam020301ec + iVar4 + 0x5c);
    *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[0xd] * 0x40) =
         *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[0xd] * 0x40) &
         *(uint *)(*piRam020301ec + iVar4 + 0x5c);
    *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[2] * 0x40) =
         *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[2] * 0x40) &
         (uint)(*(int *)(*piRam020301ec + iVar4 + 0x5c) == 0);
    *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[0xe] * 0x40) =
         *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)local_38[0xe] * 0x40) &
         (uint)(*(int *)(*piRam020301ec + iVar4 + 0x5c) == 0);
    iVar2 = local_24;
    puVar3 = local_38;
    do {
      uVar1 = (uint)(iVar2 == *(int *)(iVar4 + *piRam020301ec + 0x60));
      *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)puVar3[4] * 0x40) =
           *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)puVar3[4] * 0x40) & uVar1;
      *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)puVar3[0x10] * 0x40) =
           *(uint *)(*(int *)(iVar5 + 0x3c) + (uint)puVar3[0x10] * 0x40) & uVar1;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    func_02124100(local_38[0x18],local_1c[local_3c] & 0xff,*(undefined4 *)(iVar5 + 0x38),
                  *(undefined4 *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x30));
    iVar4 = iVar4 + 0xc;
    local_38 = local_38 + 0x19;
    local_40 = local_40 + 1;
  } while (local_40 < 4);
  if ((*(int *)(*piRam020301ec + 0x48) == local_40) && (param_1 != 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  *(int *)(*(int *)(iVar5 + 0x3c) + iRam020301f8) = iVar4;
  *(uint *)(*(int *)(iVar5 + 0x3c) + iRam020301fc) = (uint)(iVar4 == 0);
  func_02124100(4,local_1c[iVar4] & 0xff,*(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c)
                ,*(undefined4 *)(iVar5 + 0x30));
  return;
}

