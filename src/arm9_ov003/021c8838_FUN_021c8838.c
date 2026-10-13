/* Decompiled C draft; module arm9_ov003; ROM address 021c8838. No matching claim. */
#include "types.h"
#include "deps/021c8838_FUN_021c8838.h"

void FUN_021c8838(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  ushort local_20 [4];
  undefined2 local_18;
  
  local_20[0] = *DAT_021c88dc;
  local_20[1] = *DAT_021c88e0;
  local_20[3] = *DAT_021c88e4;
  piVar3 = (int *)(*DAT_021c88e8 + 0x18 + param_3 * 4);
  local_20[2] = local_20[1];
  local_18 = local_20[3];
  if (param_1 - 1U < 2) {
    iVar2 = FUN_021c83b0(param_3);
    if (iVar2 == 2) {
      piVar3 = (int *)(*DAT_021c88e8 + 0x2c);
    }
    else {
      piVar3 = (int *)(*DAT_021c88e8 + 0x30);
    }
  }
  cVar1 = *(char *)(param_2 + DAT_021c88ec + param_1 * 3);
  if (cVar1 != '\0') {
    FUN_021d1c3c(0,cVar1,*piVar3);
    *(uint *)*piVar3 = (local_20[param_1] & DAT_021c88f0) << 0x10 | *(uint *)*piVar3 & DAT_021c88f4;
    *(ushort *)(*piVar3 + 4) =
         *(ushort *)(*piVar3 + 4) & (ushort)DAT_021c88f8 | (ushort)DAT_021c88fc;
    return;
  }
  *(uint *)*piVar3 = *(uint *)*piVar3 & DAT_021c88f4 | DAT_021c8900;
  return;
}

