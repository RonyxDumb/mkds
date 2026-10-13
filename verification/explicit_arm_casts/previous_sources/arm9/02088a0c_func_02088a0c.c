/* Decompiled C draft; module arm9; ROM address 02088a0c. No matching claim. */
#include "types.h"
#include "deps/02088a0c_func_02088a0c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_02088a0c(uint param_1)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  undefined4 local_58;
  uint local_54;
  undefined4 uStack_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [12];
  undefined1 auStack_28 [12];
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uVar12;
  
  uVar12 = param_1 + 0xd0 & 3;
  uVar11 = *(uint *)(param_1 + 0xd0 & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  if (uVar12 == 0) {
    uVar12 = func_02061f90();
    if (*(ushort *)(param_1 + 4) == uVar12) {
      func_020888b4(param_1,uRam02088c78,
                    *(uint *)(uRam02088c68 & 0xfffffffc) >> (uRam02088c68 & 3) * 8 |
                    *(uint *)(uRam02088c68 & 0xfffffffc) << (uRam02088c68 & 3) * -8 + 0x20);
      return;
    }
    return;
  }
  if ((*(ushort *)(uVar12 + 2) & 1) != 0) {
    *(undefined4 *)(param_1 + 0xd0) = 0;
    *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
    return;
  }
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar11 = uVar4 + 0x88 & 3;
  uVar10 = *(uint *)(uVar4 + 0x88 & 0xfffffffc);
  uVar13 = uVar12 + 0xc & 3;
  uVar8 = *(uint *)(uVar12 + 0xc & 0xfffffffc);
  iVar5 = (int)((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) -
               (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20)) >> 0xc;
  uVar11 = uVar4 + 0x80 & 3;
  uVar10 = *(uint *)(uVar4 + 0x80 & 0xfffffffc);
  uVar13 = uVar12 + 4 & 3;
  uVar8 = *(uint *)(uVar12 + 4 & 0xfffffffc);
  iVar1 = (int)((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) -
               (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20)) >> 0xc;
  uVar11 = uRam02088c68 & 3;
  uVar13 = *(uint *)(uRam02088c68 & 0xfffffffc);
  if ((iVar1 * iVar1 + iVar5 * iVar5 < iRam02088c6c) &&
     (uVar8 = uVar4 + 0x84 & 3, uVar9 = *(uint *)(uVar4 + 0x84 & 0xfffffffc), uVar4 = uVar12 + 8 & 3
     , uVar10 = *(uint *)(uVar12 + 8 & 0xfffffffc),
     iVar5 = AbsValue((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) -
                      (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20)),
     iVar5 < (int)(uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20))) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (!bVar3) {
    *(undefined4 *)(param_1 + 0xd0) = 0;
    *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
    return;
  }
  bVar3 = false;
  VecFx32_Subtract(uVar12 + 4,
                   (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x80,&local_4c);
  iVar5 = Vector3_DotProduct(&local_4c,
                             (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x138);
  if (0 < iVar5) {
    lVar2 = (longlong)local_44 * (longlong)local_44 +
            (longlong)local_4c * (longlong)local_4c + (longlong)local_48 * (longlong)local_48;
    if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
      Vector3_MaybeNormalize(&local_4c,&local_4c);
    }
    uVar6 = Vector3_DotProduct(&local_4c,
                               (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x138
                              );
    *(undefined4 *)(param_1 + 0xd8) = uVar6;
    bVar3 = true;
  }
  if ((bVar3) &&
     (uVar11 = param_1 + 0xd8 & 3, uVar13 = *(uint *)(param_1 + 0xd8 & 0xfffffffc),
     iRam02088c70 < (int)(uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20))) {
    local_58 = *(undefined4 *)(uVar12 + 4);
    uStack_50 = *(undefined4 *)(uVar12 + 0xc);
    uVar12 = param_1 + 0x48 & 3;
    uVar11 = *(uint *)(param_1 + 0x48 & 0xfffffffc);
    local_54 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    uVar12 = param_1 + 0x28 & 3;
    uVar11 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
    uVar12 = (uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) + 0x20;
    uVar11 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    puVar7 = (undefined4 *)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20);
    local_40 = *puVar7;
    uStack_3c = puVar7[1];
    uStack_38 = puVar7[2];
    local_1c = *puRam02088c74;
    uStack_18 = puRam02088c74[1];
    uStack_14 = puRam02088c74[2];
    VecFx32_CrossProduct(param_1 + 0x30,&local_1c,auStack_34);
    VecFx32_Subtract(&local_58,&local_40,auStack_28);
    VecFx32_CrossProduct_0(auStack_28,auStack_34);
    uVar12 = param_1 + 0x28 & 3;
    uVar11 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
    uVar12 = (uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) + 0x24;
    uVar11 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    iVar5 = AbsValue();
    if (iVar5 < (int)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0xdc) = local_58;
      *(uint *)(param_1 + 0xe0) = local_54;
      *(undefined4 *)(param_1 + 0xe4) = uStack_50;
      *(undefined4 **)(param_1 + 0x5c) = (undefined4 *)(param_1 + 0xdc);
      return;
    }
    *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
    return;
  }
  *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
  return;
}

