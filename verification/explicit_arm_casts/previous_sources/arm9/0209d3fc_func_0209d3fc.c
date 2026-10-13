/* Decompiled C draft; module arm9; ROM address 0209d3fc. No matching claim. */
#include "types.h"
#include "deps/0209d3fc_func_0209d3fc.h"

void func_0209d3fc(undefined4 param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  local_28 = 0x1e;
  func_01ff9048(0x14,&local_28,1);
  uVar3 = func_020e6cf8(param_2 + 4);
  func_01ff9048(0x19,uVar3,0xc);
  uVar6 = param_2 + 0xdcU & 3;
  uVar4 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
  if ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) - 3 < 2) {
    uVar6 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar6 = (uint)*(short *)(iRam0209d5d8 +
                            (((int)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0xffff) >> 4
                             ) * 2 + 1) * 2);
    lVar2 = (ulonglong)uVar6 * 0xfffec000;
    iVar5 = (int)(uint)*(ushort *)(param_2 + 0xb0) >> 4;
    iVar7 = ((uint)lVar2 >> 0xc | ((int)((ulonglong)lVar2 >> 0x20) - uVar6) * 0x100000) + 0x14000;
    local_1c = 0;
    lVar2 = (longlong)iVar7 * (longlong)(int)*(short *)(iRam0209d5d8 + iVar5 * 4);
    lVar1 = (longlong)iVar7 * (longlong)(int)*(short *)(iRam0209d5d8 + (iVar5 * 2 + 1) * 2);
    local_24 = (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) >> 4;
    local_20 = (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14) >> 4;
    func_01ff9048(0x1c,&local_24,3);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  iVar5 = func_02061818();
  if (iVar5 == 2) {
    StructMapObject_SomeFn_9
              (param_1,*(uint *)(uRam0209d5dc & 0xfffffffc) >> (uRam0209d5dc & 3) * 8 |
                       *(uint *)(uRam0209d5dc & 0xfffffffc) << (uRam0209d5dc & 3) * -8 + 0x20);
    StructMapObject_MaybeSetNsbcaFrame
              (*(uint *)(uRam0209d5dc & 0xfffffffc) >> (uRam0209d5dc & 3) * 8 |
               *(uint *)(uRam0209d5dc & 0xfffffffc) << (uRam0209d5dc & 3) * -8 + 0x20,
               *(undefined2 *)(param_2 + 0xb2));
    DrawObject2D3D(param_1,*(uint *)(uRam0209d5dc & 0xfffffffc) >> (uRam0209d5dc & 3) * 8 |
                           *(uint *)(uRam0209d5dc & 0xfffffffc) << (uRam0209d5dc & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  uVar6 = param_2 + 0x78U & 3;
  uVar4 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if ((int)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x3fffffe0) < iRam0209d5e0) {
    StructMapObject_SomeFn_9
              (param_1,*(uint *)(uRam0209d5dc & 0xfffffffc) >> (uRam0209d5dc & 3) * 8 |
                       *(uint *)(uRam0209d5dc & 0xfffffffc) << (uRam0209d5dc & 3) * -8 + 0x20);
    StructMapObject_MaybeSetNsbcaFrame
              (*(uint *)(uRam0209d5dc & 0xfffffffc) >> (uRam0209d5dc & 3) * 8 |
               *(uint *)(uRam0209d5dc & 0xfffffffc) << (uRam0209d5dc & 3) * -8 + 0x20,
               *(undefined2 *)(param_2 + 0xb2));
    DrawObject2D3D(param_1,*(uint *)(uRam0209d5dc & 0xfffffffc) >> (uRam0209d5dc & 3) * 8 |
                           *(uint *)(uRam0209d5dc & 0xfffffffc) << (uRam0209d5dc & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  StructMapObject_SomeFn_9
            (param_1,*(uint *)(uRam0209d5e4 & 0xfffffffc) >> (uRam0209d5e4 & 3) * 8 |
                     *(uint *)(uRam0209d5e4 & 0xfffffffc) << (uRam0209d5e4 & 3) * -8 + 0x20);
  func_0209ba58(param_1,*(uint *)(uRam0209d5e4 & 0xfffffffc) >> (uRam0209d5e4 & 3) * 8 |
                        *(uint *)(uRam0209d5e4 & 0xfffffffc) << (uRam0209d5e4 & 3) * -8 + 0x20,
                param_2);
  return;
}

