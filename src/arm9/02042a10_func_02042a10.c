/* Decompiled C draft; module arm9; ROM address 02042a10. No matching claim. */
#include "types.h"
#include "deps/02042a10_func_02042a10.h"

void func_02042a10(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  ushort *puVar8;
  undefined2 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int *piVar14;
  int local_34;
  uint local_1c;
  
  iVar10 = *piRam02042c38;
  puVar8 = *(ushort **)(iVar10 + 0x8c);
  piVar3 = (int *)(iVar10 + 0xb8);
  uVar1 = Mem_AllocateHeap(param_1,(uint)*(ushort *)(iVar10 + 0x88) * 0x30);
  *(undefined4 *)(iVar10 + 0xb8) = uVar1;
  *(undefined4 *)(iVar10 + 0xbc) = *(undefined4 *)(iVar10 + 0xb8);
  *(uint *)(iVar10 + 0xc0) =
       *(int *)(iVar10 + 0xb8) + (uint)*(ushort *)(*piRam02042c38 + 0x88) * 0x30;
  iVar10 = 0;
  iVar5 = *piRam02042c38;
  uVar11 = (uint)*(ushort *)(iVar5 + 0x88);
  if (uVar11 != 0) {
    iVar7 = 0;
    do {
      puVar13 = (undefined4 *)(*piVar3 + iVar7);
      iVar5 = 0;
      puVar6 = puVar13;
      do {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      *(undefined2 *)(puVar13 + 0xb) = 0;
      puVar13[8] = 0;
      puVar13[10] = 0;
      puVar13[9] = 0;
      iVar7 = iVar7 + 0x30;
      iVar10 = iVar10 + 1;
      iVar5 = *piRam02042c38;
      uVar11 = (uint)*(ushort *)(iVar5 + 0x88);
    } while (iVar10 < (int)uVar11);
  }
  local_1c = 0;
  if (uVar11 != 0) {
    local_34 = 0;
    do {
      iVar10 = *(int *)(*piRam02042c38 + 0x84) + (local_1c & 0xffff) * 0x18;
      piVar14 = (int *)(*piVar3 + local_34);
      uVar11 = 0;
      if (*(short *)(*piRam02042c38 + 0x90) != 0) {
        uVar2 = uVar11;
        do {
          puVar8 = (ushort *)(*(int *)(iVar5 + 0x8c) + uVar2 * 0x14);
          uVar4 = (uint)*(ushort *)(*(int *)(iVar5 + 0x8c) + uVar2 * 0x14);
          if (((int)uVar4 <= (int)local_1c) && ((int)local_1c < (int)(uVar4 + puVar8[1]))) break;
          uVar2 = uVar2 + 1 & 0xffff;
        } while (uVar2 < *(ushort *)(iVar5 + 0x90));
      }
      *(undefined1 *)((int)piVar14 + 0x2e) = 0;
      uVar2 = ((uint)*puVar8 + (uint)puVar8[1]) - 1 & 0xffff;
      if (local_1c == *puVar8) {
        uVar4 = 0;
        do {
          uVar12 = uVar11;
          if (*(char *)((int)puVar8 + uVar4 + 0xc) != -1) {
            *(byte *)((int)piVar14 + 0x2e) =
                 *(byte *)((int)piVar14 + 0x2e) | (byte)(1 << (uVar11 & 0xff));
            uVar12 = uVar11 + 1 & 0xffff;
            piVar14[uVar11] = *piVar3 + (uint)*(byte *)((int)puVar8 + uVar4 + 0xc) * 0x30;
          }
          uVar4 = uVar4 + 1 & 0xffff;
          uVar11 = uVar12;
        } while (uVar4 < 8);
        if (1 < puVar8[1]) {
          uVar11 = uVar12 + 1 & 0xffff;
          piVar14[uVar12] = (int)(piVar14 + 0xc);
        }
      }
      if (local_1c == uVar2) {
        uVar4 = 0;
        do {
          uVar12 = uVar11;
          if (*(char *)((int)puVar8 + uVar4 + 4) != -1) {
            *(byte *)((int)piVar14 + 0x2e) =
                 *(byte *)((int)piVar14 + 0x2e) | (byte)(1 << (uVar11 & 0xff));
            uVar12 = uVar11 + 1 & 0xffff;
            piVar14[uVar11] = *piVar3 + (uint)*(byte *)((int)puVar8 + uVar4 + 4) * 0x30;
          }
          uVar4 = uVar4 + 1 & 0xffff;
          uVar11 = uVar12;
        } while (uVar4 < 8);
        if (1 < puVar8[1]) {
          uVar11 = uVar12 + 1 & 0xffff;
          piVar14[uVar12] = (int)(piVar14 + -0xc);
        }
      }
      uVar9 = (undefined2)uVar11;
      if ((local_1c != *puVar8) && (local_1c != uVar2)) {
        *piVar14 = (int)(piVar14 + 0xc);
        uVar9 = 2;
        piVar14[1] = (int)(piVar14 + -0xc);
      }
      piVar14[8] = iVar10;
      piVar14[9] = *(int *)(iVar10 + 0xc);
      piVar14[10] = iVar10 + 0x10;
      *(undefined2 *)(piVar14 + 0xb) = uVar9;
      local_34 = local_34 + 0x30;
      local_1c = local_1c + 1;
      iVar5 = *piRam02042c38;
    } while ((int)local_1c < (int)(uint)*(ushort *)(iVar5 + 0x88));
  }
  return;
}

