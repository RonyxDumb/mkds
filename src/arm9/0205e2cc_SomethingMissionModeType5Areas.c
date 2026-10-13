/* Decompiled C draft; module arm9; ROM address 0205e2cc. No matching claim. */
#include "types.h"
#include "deps/0205e2cc_SomethingMissionModeType5Areas.h"

void SomethingMissionModeType5Areas(undefined4 param_1)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  undefined1 auStack_28 [4];
  
  uVar1 = *(ushort *)
           ((*(uint *)(uRam0205e4dc & 0xfffffffc) >> (uRam0205e4dc & 3) * 8 |
            *(uint *)(uRam0205e4dc & 0xfffffffc) << (uRam0205e4dc & 3) * -8 + 0x20) + 0x78);
  uVar10 = 0;
  uVar5 = Mem_AllocateHeap(param_1,8);
  *puRam0205e4e0 = uVar5;
  uVar12 = 0;
  if (uVar1 != 0) {
    do {
      iVar6 = GetGlobalPENkmAREAByIndex_from_thumb(uVar12);
      if (*(char *)(iVar6 + 0x44) == '\x05') {
        uVar10 = uVar10 + 1 & 0xffff;
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar1);
  }
  if (uVar10 != 0) {
    uVar5 = Mem_AllocateHeap(param_1,uVar10 * 0xc);
    *(undefined4 *)
     (*(uint *)((uint)puRam0205e4e0 & 0xfffffffc) >> ((uint)puRam0205e4e0 & 3) * 8 |
     *(uint *)((uint)puRam0205e4e0 & 0xfffffffc) << ((uint)puRam0205e4e0 & 3) * -8 + 0x20) = uVar5;
  }
  uVar13 = 0;
  uVar12 = 0;
  puVar16 = (uint *)auStack_28;
  if (uVar1 == 0) {
    puVar16 = (uint *)&stack0xffffffdc;
  }
  *(short *)((*(uint *)((uint)puRam0205e4e0 & 0xfffffffc) >> ((uint)puRam0205e4e0 & 3) * 8 |
             *(uint *)((uint)puRam0205e4e0 & 0xfffffffc) << ((uint)puRam0205e4e0 & 3) * -8 + 0x20) +
            4) = (short)uVar10;
  if (uVar1 == 0) {
    return;
  }
  *puVar16 = 0;
  do {
    iVar6 = GetGlobalPENkmAREAByIndex_from_thumb(uVar12);
    if (*(char *)(iVar6 + 0x44) == '\x05') {
      uVar9 = *(uint *)((uint)puRam0205e4e0 & 0xfffffffc) >> ((uint)puRam0205e4e0 & 3) * 8 |
              *(uint *)((uint)puRam0205e4e0 & 0xfffffffc) << ((uint)puRam0205e4e0 & 3) * -8 + 0x20;
      uVar7 = *puVar16;
      uVar10 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
      *(ushort *)(uVar10 + uVar13 * 0xc) = uVar12;
      iVar11 = uVar10 + uVar13 * 0xc;
      if (*(char *)(iVar6 + 0x42) == '\0') {
        uVar10 = iVar6 + 0xcU & 3;
        uVar7 = *(uint *)(iVar6 + 0xcU & 0xfffffffc);
        iVar8 = Const204800();
        lVar2 = (longlong)iVar8 * (longlong)(int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20)
                + 0x800;
        uVar10 = iVar6 + 0x10U & 3;
        uVar14 = *(uint *)(iVar6 + 0x10U & 0xfffffffc);
        uVar9 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
        iVar8 = Const409600();
        uVar7 = iVar6 + 0x14U & 3;
        uVar15 = *(uint *)(iVar6 + 0x14U & 0xfffffffc);
        lVar2 = (longlong)iVar8 *
                (longlong)(int)(uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) + 0x800;
        iVar6 = (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) >> 1;
        iVar8 = Const204800();
        lVar2 = (longlong)iVar8 * (longlong)(int)(uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20)
                + 0x800;
        uVar10 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
        lVar4 = (longlong)(int)uVar10 * (longlong)(int)uVar10 + 0x800;
        lVar2 = (longlong)(int)uVar9 * (longlong)(int)uVar9 + 0x800;
        lVar3 = (longlong)iVar6 * (longlong)iVar6 + 0x800;
        uVar7 = FX_Sqrt(((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000) +
                        ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
                        ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000));
      }
      else if (*(char *)(iVar6 + 0x42) == '\x01') {
        uVar10 = iVar6 + 0xcU & 3;
        uVar7 = *(uint *)(iVar6 + 0xcU & 0xfffffffc);
        iVar6 = Const204800_0();
        lVar2 = (longlong)iVar6 * (longlong)(int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20)
                + 0x800;
        uVar7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
      }
      *(uint *)(iVar11 + 4) = uVar7;
      *(undefined1 *)(iVar11 + 9) = 0;
      *(undefined1 *)(iVar11 + 8) = 0;
      uVar13 = uVar13 + 1 & 0xffff;
    }
    uVar12 = uVar12 + 1;
  } while (uVar12 < uVar1);
  return;
}

