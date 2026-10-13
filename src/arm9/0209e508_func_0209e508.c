/* Decompiled C draft; module arm9; ROM address 0209e508. No matching claim. */
#include "types.h"
#include "deps/0209e508_func_0209e508.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0209e508(undefined4 param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_f8;
  int iStack_f0;
  int local_ec;
  int local_e8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 auStack_94 [36];
  undefined1 auStack_70 [36];
  undefined1 auStack_4c [40];
  
  iVar3 = GetGlobalHD4();
  iVar3 = VecFx32_CrossProduct_0(param_2 + 0x28,iVar3 + 0x15c);
  local_f8 = 0;
  if (*(short *)(param_2 + 0xa0) != 0) {
    local_ec = param_2 + 0xc4;
    uVar6 = 0;
    iVar8 = param_2;
    do {
      uVar10 = uVar6;
      if ((0x3fff < *(ushort *)(iVar8 + 0xd0)) && (*(ushort *)(iVar8 + 0xd0) < 0xc000)) {
        uVar10 = 1;
      }
      if ((-1 < iVar3 != uVar10) &&
         (iVar7 = local_ec, uVar10 = uVar6, *(short *)(param_2 + 0xa2) != 0)) {
        do {
          local_a0 = 0x1e;
          func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_a0),1);
          uVar4 = func_020e6cf8(iVar7);
          func_01ff9048(0x19,uVar4,0xc);
          uVar5 = (uint)*(ushort *)(iVar8 + uVar10 * 0x10 + 0xd2);
          if (uVar5 != 0) {
            iVar9 = (int)uVar5 >> 4;
            MTX_RotZ33__from_thumb
                      ((undefined4 *)(void *)(auStack_94),(int)*(short *)(iRam0209e930 + iVar9 * 4),
                       (int)*(short *)(iRam0209e930 + (iVar9 * 2 + 1) * 2));
            func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_94),9);
          }
          func_01ff9048(0x1b,param_2 + 0x1c,3);
          uVar4 = func_020d3c44();
          StructMapObject_MaybeSetPolygonId
                    (*(uint *)(uRam0209e934 & 0xfffffffc) >> (uRam0209e934 & 3) * 8 |
                     *(uint *)(uRam0209e934 & 0xfffffffc) << (uRam0209e934 & 3) * -8 + 0x20,uVar4);
          DrawObject2D3D(param_1,*(uint *)(uRam0209e934 & 0xfffffffc) >> (uRam0209e934 & 3) * 8 |
                                 *(uint *)(uRam0209e934 & 0xfffffffc) <<
                                 (uRam0209e934 & 3) * -8 + 0x20,param_2);
          uVar10 = uVar10 + 1;
          iVar7 = iVar7 + 0x10;
        } while ((int)uVar10 < (int)(uint)*(ushort *)(param_2 + 0xa2));
      }
      local_ec = local_ec + 0x140;
      iVar8 = iVar8 + 0x140;
      local_f8 = local_f8 + 1;
    } while (local_f8 < (int)(uint)*(ushort *)(param_2 + 0xa0));
  }
  if (1 < *(ushort *)(param_2 + 0xa2)) {
    local_9c = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_9c),1);
    uVar4 = func_020e6cf8(param_2 + 0xb4);
    func_01ff9048(0x19,uVar4,0xc);
    if (*(ushort *)(param_2 + 0xc2) != 0) {
      iVar8 = (int)(uint)*(ushort *)(param_2 + 0xc2) >> 4;
      MTX_RotZ33__from_thumb
                ((undefined4 *)(void *)(auStack_70),(int)*(short *)(iRam0209e930 + iVar8 * 4),
                 (int)*(short *)(iRam0209e930 + (iVar8 * 2 + 1) * 2));
      func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_70),9);
    }
    func_01ff9048(0x1b,param_2 + 0x1c,3);
    uVar4 = func_020d3c44();
    StructMapObject_MaybeSetPolygonId
              (*(uint *)(uRam0209e934 & 0xfffffffc) >> (uRam0209e934 & 3) * 8 |
               *(uint *)(uRam0209e934 & 0xfffffffc) << (uRam0209e934 & 3) * -8 + 0x20,uVar4);
    DrawObject2D3D(param_1,*(uint *)(uRam0209e934 & 0xfffffffc) >> (uRam0209e934 & 3) * 8 |
                           *(uint *)(uRam0209e934 & 0xfffffffc) << (uRam0209e934 & 3) * -8 + 0x20,
                   param_2);
  }
  local_e8 = 0;
  if (*(short *)(param_2 + 0xa0) != 0) {
    iStack_f0 = param_2 + 0xc4;
    iVar8 = param_2;
    do {
      bVar2 = false;
      if ((0x3fff < *(ushort *)(iVar8 + 0xd0)) && (*(ushort *)(iVar8 + 0xd0) < 0xc000)) {
        bVar2 = true;
      }
      if ((-1 < iVar3 == bVar2) && (iVar7 = *(ushort *)(param_2 + 0xa2) - 1, -1 < iVar7)) {
        iVar9 = iStack_f0 + iVar7 * 0x10;
        do {
          uStack_98 = 0x1e;
          func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_98),1);
          uVar4 = func_020e6cf8(iVar9);
          func_01ff9048(0x19,uVar4,0xc);
          uVar6 = (uint)*(ushort *)(iVar8 + iVar7 * 0x10 + 0xd2);
          if (uVar6 != 0) {
            iVar1 = (int)uVar6 >> 4;
            MTX_RotZ33__from_thumb
                      ((undefined4 *)(void *)(auStack_4c),(int)*(short *)(iRam0209e930 + iVar1 * 4),
                       (int)*(short *)(iRam0209e930 + (iVar1 * 2 + 1) * 2));
            func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_4c),9);
          }
          func_01ff9048(0x1b,param_2 + 0x1c,3);
          uVar4 = func_020d3c44();
          StructMapObject_MaybeSetPolygonId
                    (*(uint *)(uRam0209e934 & 0xfffffffc) >> (uRam0209e934 & 3) * 8 |
                     *(uint *)(uRam0209e934 & 0xfffffffc) << (uRam0209e934 & 3) * -8 + 0x20,uVar4);
          DrawObject2D3D(param_1,*(uint *)(uRam0209e934 & 0xfffffffc) >> (uRam0209e934 & 3) * 8 |
                                 *(uint *)(uRam0209e934 & 0xfffffffc) <<
                                 (uRam0209e934 & 3) * -8 + 0x20,param_2);
          iVar9 = iVar9 + -0x10;
          iVar7 = iVar7 + -1;
        } while (-1 < iVar7);
      }
      iStack_f0 = iStack_f0 + 0x140;
      iVar8 = iVar8 + 0x140;
      local_e8 = local_e8 + 1;
    } while (local_e8 < (int)(uint)*(ushort *)(param_2 + 0xa0));
    return;
  }
  return;
}

