/* Decompiled C draft; module arm7; ROM address 0600722c. No matching claim. */
#include "types.h"
#include "deps/0600722c_FUN_0600722c.h"

/* WARNING: Heritage AFTER dead removal. Example location: s0x00000004 : 0x06007288 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined2
FUN_0600722c(ushort param_1,int param_2,ushort param_3,ushort param_4,undefined4 param_5,
            ushort param_6,undefined4 param_7,undefined4 param_8)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  uint uVar9;
  
  iVar3 = FUN_06000680();
  uVar9 = iVar3 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  uVar9 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar9 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  iVar3 = uVar9 + 0x2f4;
  puVar8 = (ushort *)(uVar9 + DAT_06007388 + param_2 * 4);
  if (param_6 == 0) {
    return 6;
  }
  if ((param_3 & 8) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 2;
  }
  if ((uint)*(ushort *)(uVar9 + 0x18e) < (uint)param_6 + iVar6) {
    return 6;
  }
  thunk_FUN_037f9a0c(uVar9 + DAT_0600738c);
  uVar4 = DAT_06007390;
  uVar1 = *(ushort *)(uVar9 + 0x6f4);
  uVar5 = (uint)uVar1;
  if (uVar5 == DAT_06007390) {
    thunk_FUN_037f999c(uVar9 + DAT_0600738c);
    return 10;
  }
  puVar7 = (undefined2 *)(iVar3 + uVar5 * 0x20);
  *(undefined2 *)(uVar9 + 0x6f4) = *(undefined2 *)(iVar3 + uVar5 * 0x20);
  if (*(ushort *)(uVar9 + 0x6f6) == uVar5) {
    *(short *)(uVar9 + 0x6f6) = (short)uVar4;
  }
  puVar7[1] = param_3;
  puVar7[2] = param_4;
  puVar7[3] = param_4 & param_1;
  puVar7[4] = 0;
  puVar7[5] = 0;
  *(undefined4 *)(puVar7 + 10) = param_5;
  puVar7[7] = param_6;
  *(undefined4 *)(puVar7 + 0xc) = param_7;
  *(undefined4 *)(puVar7 + 0xe) = param_8;
  uVar4 = DAT_06007390;
  uVar2 = (undefined2)DAT_06007390;
  *puVar7 = uVar2;
  puVar7[8] = uVar2;
  puVar7[9] = *(undefined2 *)(uVar9 + 0x98);
  if (puVar8[1] == uVar4) {
    *puVar8 = uVar1;
  }
  else {
    *(ushort *)(iVar3 + (uint)puVar8[1] * 0x20) = uVar1;
  }
  puVar8[1] = uVar1;
  thunk_FUN_037f999c(uVar9 + DAT_0600738c);
  return 2;
}

