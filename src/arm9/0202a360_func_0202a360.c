/* Decompiled C draft; module arm9; ROM address 0202a360. No matching claim. */
#include "types.h"
#include "deps/0202a360_func_0202a360.h"

undefined4 func_0202a360(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint unaff_r4;
  uint *puVar5;
  uint unaff_r5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_48;
  uint local_44;
  uint local_34 [8];
  
  uVar8 = (uint)*(byte *)(*DAT_0202a57c + DAT_0202a580);
  if (*(int *)(*DAT_0202a57c + 8) == 0) {
    if (*(int *)(*DAT_0202a584 + 0x7c) < 3) {
      return 0;
    }
    return 1;
  }
  switch(*(undefined4 *)(*DAT_0202a588 + 0x20)) {
  case 0:
    local_48 = 0;
    break;
  case 1:
  case 2:
    piVar2 = (int *)*DAT_0202a58c;
    if (*piVar2 == 2) {
      uVar6 = (uint)*(ushort *)((int)piVar2 + DAT_0202a590);
    }
    else {
      uVar6 = 0;
    }
    local_48 = (uint)*(ushort *)((int)piVar2 + DAT_0202a594 + ((uVar6 << 0x10) >> 0xd));
    break;
  case 3:
    func_0x0219bb50();
    uVar6 = func_02122778();
    local_48 = uVar6 & 0xffff;
  }
  iVar3 = *DAT_0202a57c;
  if (*(char *)(iVar3 + 0x58) == '\0') {
    uVar6 = 0;
    local_44 = 0xffffffff;
    bVar1 = true;
    if (uVar8 != 0) {
      puVar5 = local_34;
      do {
        if ((*(int *)(*DAT_0202a588 + 0x20) == 3) || (*(int *)(*DAT_0202a57c + 0x1c) == 2)) {
          uVar4 = Int32ToInt8(uVar6 & 0xffff);
          iVar3 = GetSomeLUMaxIndex();
          iVar7 = Int32ToInt8(uVar4);
          *puVar5 = (uint)*(ushort *)(*DAT_0202a598 + iVar3 * 0x50 + iVar7 * 10);
        }
        else {
          uVar4 = Int32ToInt8(uVar6 & 0xffff);
          iVar3 = GetSomeLUMaxIndex();
          iVar7 = Int32ToInt8(uVar4);
          *puVar5 = (uint)*(byte *)(*DAT_0202a598 + iVar3 * 0x50 + iVar7 * 10 + 5);
        }
        if ((int)local_44 < (int)*puVar5) {
          local_44 = *puVar5;
        }
        puVar5 = puVar5 + 1;
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < (int)uVar8);
    }
    iVar3 = 1;
    if (1 < uVar8) {
      puVar5 = local_34;
      do {
        puVar5 = puVar5 + 1;
        bVar1 = (bool)(bVar1 & local_34[0] == *puVar5);
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)uVar8);
    }
    if (bVar1) {
      return 4;
    }
    if (local_44 == local_34[local_48]) {
      return 2;
    }
    return 3;
  }
  iVar7 = *(int *)(iVar3 + local_48 * 0x30 + 0x74);
  if (*(int *)(iVar3 + 0x1c) == 1) {
    iVar3 = GetSomeLUMaxIndex();
    unaff_r4 = (uint)*(byte *)(*DAT_0202a598 + DAT_0202a59c + iVar3 * 8 + 2);
    iVar3 = GetSomeLUMaxIndex();
    unaff_r5 = (uint)*(byte *)(*DAT_0202a598 + DAT_0202a59c + iVar3 * 8 + 6);
  }
  else if (*(int *)(iVar3 + 0x1c) == 2) {
    iVar3 = GetSomeLUMaxIndex();
    unaff_r4 = (uint)*(ushort *)(*DAT_0202a598 + DAT_0202a59c + iVar3 * 8);
    iVar3 = GetSomeLUMaxIndex();
    unaff_r5 = (uint)*(ushort *)(*DAT_0202a598 + DAT_0202a59c + iVar3 * 8 + 4);
  }
  if (unaff_r4 == unaff_r5) {
    return 7;
  }
  if ((int)unaff_r4 <= (int)unaff_r5) {
    if (iVar7 == 1) {
      return 5;
    }
    return 6;
  }
  if (iVar7 == 0) {
    return 5;
  }
  return 6;
}

