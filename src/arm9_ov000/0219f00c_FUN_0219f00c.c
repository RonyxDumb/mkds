/* Decompiled C draft; module arm9_ov000; ROM address 0219f00c. No matching claim. */
#include "types.h"
#include "deps/0219f00c_FUN_0219f00c.h"

undefined4 FUN_0219f00c(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_11c;
  undefined4 local_118 [32];
  undefined4 local_98 [33];
  
  iVar7 = 0;
  local_11c = 0;
  iVar6 = 1;
  iVar2 = *DAT_0219f0e8;
  if (*(char *)(iVar2 + 0xd) != '\0') {
    puVar4 = local_98;
    puVar3 = local_118;
    iVar1 = iVar2;
    iVar5 = iVar2;
    do {
      iVar5 = iVar5 + 1;
      if ((param_1 & 1 << *(sbyte *)(iVar5 + DAT_0219f0ec)) == 0) {
        *puVar3 = *(undefined4 *)(iVar1 + 0xf8);
        puVar3 = puVar3 + 1;
        iVar7 = iVar7 + 1;
      }
      else {
        *puVar4 = *(undefined4 *)(iVar1 + 0xf8);
        puVar4 = puVar4 + 1;
        local_11c = local_11c + 1;
      }
      iVar6 = iVar6 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar6 <= (int)(uint)*(byte *)(iVar2 + 0xd));
  }
  iVar2 = 0;
  if (0 < local_11c) {
    puVar4 = local_98;
    do {
      FUN_021a0ae8(0x10,*puVar4,0,0,local_118,iVar7);
      iVar6 = FUN_0219fee4();
      if (iVar6 != 0) {
        return 0;
      }
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_11c);
  }
  *(undefined1 *)(*DAT_0219f0e8 + DAT_0219f0f0) = 2;
  iVar2 = 0;
  if (0 < iVar7) {
    puVar4 = local_118;
    do {
      iVar6 = FUN_0219e948(*puVar4,0);
      if (iVar6 != 0xff) {
        FUN_0219bbac();
      }
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar7);
  }
  *(undefined1 *)(*DAT_0219f0e8 + DAT_0219f0f0) = 0;
  return 1;
}

