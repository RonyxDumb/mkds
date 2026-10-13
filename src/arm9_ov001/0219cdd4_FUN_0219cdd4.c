/* Decompiled C draft; module arm9_ov001; ROM address 0219cdd4. No matching claim. */
#include "types.h"
#include "deps/0219cdd4_FUN_0219cdd4.h"

void FUN_0219cdd4(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  piVar1 = DAT_0219ceb8;
  *(int *)(*DAT_0219ceb8 + 0xc) = *(int *)(*DAT_0219ceb8 + 0xc) + 1;
  iVar6 = DAT_0219cec0;
  iVar4 = *(int *)(*piVar1 + 0xc);
  if (0x14 < iVar4) {
    *(undefined4 *)(*piVar1 + 4) = 1;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    *(undefined4 *)(*piVar1 + 4) = 1;
    func_0x02128374();
    return;
  }
  if (iVar4 < 0xb) {
    uVar3 = func_0x020ae4c0(1,0xa0,0,iVar4,10);
    *(undefined4 *)(*piVar1 + 0x14) = uVar3;
    uVar3 = func_0x020ae4c0(1,0xffffff00,0,*(undefined4 *)(*piVar1 + 0xc),10);
    *(undefined4 *)(*piVar1 + 0x18) = uVar3;
    local_20 = 0;
    local_18 = 0;
    iVar6 = local_18;
    iVar4 = DAT_0219cebc;
    do {
      do {
        uVar2 = func_0x020ae4c0(1,0xdc,0,*(undefined4 *)(*piVar1 + 0xc),10);
        *(undefined2 *)
         (*(int *)(*piVar1 + DAT_0219cec0) + (uint)*(byte *)(iVar4 + iVar6) * 0x40 + 4) = uVar2;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
      iVar4 = iVar4 + 3;
      local_20 = local_20 + 1;
      iVar6 = local_18;
    } while (local_20 < 6);
    return;
  }
  local_24 = 0;
  local_1c = 0;
  iVar4 = local_1c;
  iVar5 = DAT_0219cebc;
  do {
    do {
      uVar2 = func_0x020ae488(*(int *)(*piVar1 + 0xc) + -10);
      *(undefined2 *)(*(int *)(*piVar1 + iVar6) + (uint)*(byte *)(iVar5 + iVar4) * 0x40 + 4) = uVar2
      ;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    iVar5 = iVar5 + 3;
    local_24 = local_24 + 1;
    iVar4 = local_1c;
  } while (local_24 < 6);
  return;
}

