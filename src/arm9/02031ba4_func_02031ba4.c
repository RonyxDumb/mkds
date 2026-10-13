/* Decompiled C draft; module arm9; ROM address 02031ba4. No matching claim. */
#include "types.h"
#include "deps/02031ba4_func_02031ba4.h"

void func_02031ba4(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int extraout_r1;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  int local_28;
  
  iVar4 = *piRam02031e44;
  uVar11 = (uint)*(ushort *)(*(int *)(iVar4 + 0x38) + 6);
  uVar1 = *(ushort *)(*(int *)(iVar4 + 0x30) + 6);
  uVar2 = *(ushort *)(*(int *)(iVar4 + 0x54) + 6);
  uVar7 = (uint)*(ushort *)(*(int *)(iVar4 + 0x4c) + 6);
  func_02025edc((int *)(uintptr_t)(iVar4 + 0xa0));
  uVar3 = func_02025ebc(*piRam02031e44 + 0xa0);
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + 0x86) = uVar3;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + 0x46) = *(undefined2 *)(*(int *)(iVar4 + 0x3c) + 0x86);
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + 6) = *(undefined2 *)(*(int *)(iVar4 + 0x3c) + 0x46);
  iVar8 = iRam02031e48;
  *(int *)(*piRam02031e44 + iRam02031e48) = *(int *)(*piRam02031e44 + iRam02031e48) + 1;
  piVar5 = (int *)(*piRam02031e44 + iRam02031e4c);
  iVar9 = *piVar5;
  if ((int)(uint)*(ushort *)(iRam02031e50 + iVar9 * 4) < *(int *)(*piRam02031e44 + iVar8)) {
    *piVar5 = iVar9 + 1;
    if (*(int *)(*piRam02031e44 + iRam02031e4c) == 4) {
      *(int *)(*piRam02031e44 + iRam02031e4c) = 0;
    }
    *(undefined4 *)(*piRam02031e44 + iRam02031e48) = 0;
  }
  **(uint **)(iVar4 + 0x3c) =
       (uint)(*(short *)(iRam02031e54 + *(int *)(*piRam02031e44 + iRam02031e4c) * 4) == 0);
  *(uint *)(*(int *)(iVar4 + 0x3c) + 0x40) =
       (uint)(*(short *)(iRam02031e54 + *(int *)(*piRam02031e44 + iRam02031e4c) * 4) == 1);
  *(uint *)(*(int *)(iVar4 + 0x3c) + 0x80) =
       (uint)(*(short *)(iRam02031e54 + *(int *)(*piRam02031e44 + iRam02031e4c) * 4) == 2);
  func_02025edc((int *)(uintptr_t)(*piRam02031e44 + 0xb0));
  uVar3 = func_02025ebc(*piRam02031e44 + 0xb0);
  iVar8 = iRam02031e58;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e58) = uVar3;
  iVar9 = iRam02031e5c;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e5c) =
       *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar8);
  iVar8 = iRam02031e60;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e60) =
       *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar9);
  iVar9 = iRam02031e64;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e64) =
       *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar8);
  iVar8 = iRam02031e68;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e68) =
       *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar9);
  iVar9 = iRam02031e6c;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e6c) =
       *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar8);
  iVar8 = iRam02031e70;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e70) =
       *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar9);
  iVar9 = iRam02031e74;
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iRam02031e74) =
       *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar8);
  *(undefined2 *)(*(int *)(iVar4 + 0x3c) + 0xc6) = *(undefined2 *)(*(int *)(iVar4 + 0x3c) + iVar9);
  iVar8 = 0;
  if (uVar11 != 0) {
    do {
      *(undefined2 *)(*(int *)(iVar4 + 0x3c) + (iVar8 + (uint)uVar1) * 0x40 + 6) = uVar3;
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)uVar11);
  }
  func_02025edc((int *)(uintptr_t)(*piRam02031e44 + 0xc0));
  uVar3 = func_02025ebc(*piRam02031e44 + 0xc0);
  iVar9 = 0;
  iVar8 = uVar7 + uVar2;
  if (iVar8 != 0) {
    iVar10 = 0;
    do {
      *(undefined2 *)(*(int *)(iVar4 + 0x58) + iVar10 + 6) = uVar3;
      iVar10 = iVar10 + 0x40;
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar8);
  }
  iVar8 = *piRam02031e44;
  if (*(int *)(iVar8 + 0x74) < 1) {
    func_02025f14((int *)(uintptr_t)(iVar8 + 0xd0),2);
  }
  else {
    func_02025f14((int *)(uintptr_t)(iVar8 + 0xd0),0);
  }
  func_02025edc((int *)(uintptr_t)(*piRam02031e44 + 0xd0));
  uVar3 = func_02025ebc(*piRam02031e44 + 0xd0);
  iVar9 = (uVar7 + 8) * 0x40;
  *(undefined2 *)(*(int *)(iVar4 + 0x58) + iVar9 + 6) = uVar3;
  iVar8 = iRam02031e78;
  *(undefined2 *)(*(int *)(iVar4 + 0x58) + iRam02031e78) =
       *(undefined2 *)(*(int *)(iVar4 + 0x58) + iVar9 + 6);
  *(undefined2 *)(*(int *)(iVar4 + 0x58) + iRam02031e7c) =
       *(undefined2 *)(*(int *)(iVar4 + 0x58) + iVar8);
  if (*(int *)(*piRam02031e44 + 0x84) == 0) {
    iVar8 = 0;
    local_28 = 0;
    do {
      puVar12 = (undefined4 *)(*piRam02031e44 + 0xe0 + iVar8);
      iVar9 = *(int *)(*piRam02031e44 + 0xe0 + iVar8);
      if (iVar9 == 0) {
        *(undefined4 *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)((int)puVar12 + 10) * 0x40) = 0;
        *(undefined4 *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)(puVar12 + 2) * 0x40) =
             *(undefined4 *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)((int)puVar12 + 10) * 0x40);
        puVar12[1] = 0;
      }
      else if (iVar9 == 1) {
        puVar12[1] = puVar12[1] + 1;
        if ((int)puVar12[1] < 0x15) {
          uVar6 = _s32_div_f(puVar12[1],4);
          _s32_div_f(uVar6,2);
          *(uint *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)(puVar12 + 2) * 0x40) =
               (uint)(extraout_r1 == 0);
          *(uint *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)((int)puVar12 + 10) * 0x40) =
               (uint)((extraout_r1 == 0) == 0);
        }
        else {
          *puVar12 = 2;
        }
      }
      else if (iVar9 == 2) {
        *(undefined4 *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)((int)puVar12 + 10) * 0x40) = 1;
        *(undefined4 *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)(puVar12 + 2) * 0x40) =
             *(undefined4 *)(*(int *)(iVar4 + 0x58) + (uint)*(ushort *)((int)puVar12 + 10) * 0x40);
        puVar12[1] = 0;
      }
      iVar8 = iVar8 + 0xc;
      local_28 = local_28 + 1;
    } while (local_28 < 8);
  }
  return;
}

