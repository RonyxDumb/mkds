/* Decompiled C draft; module arm9; ROM address 02070484. No matching claim. */
#include "types.h"
#include "deps/02070484_StructMQRacerEntry_SomeFn_88.h"

void StructMQRacerEntry_SomeFn_88(int param_1,int *param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_88 [48];
  undefined1 auStack_58 [48];
  undefined1 auStack_28 [12];
  undefined1 auStack_1c [12];
  
  uVar1 = param_1 + 0x2a4U & 3;
  uVar3 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 0x1000) {
    return;
  }
  iVar4 = VecFx32_CrossProduct_0(param_1 + 300,uRam020705ec);
  iVar5 = iRam020705f0;
  if (0 < iVar4) {
    *(short *)(param_1 + 0x234) = *(short *)(param_1 + 0x234) + *(short *)(param_1 + 1000);
    uVar2 = *(ushort *)(param_1 + 0x234);
    iVar4 = (int)(uint)*(ushort *)(param_1 + 0x236) >> 4;
    MTX_RotY43__from_thumb
              (auStack_88,(int)*(short *)(iVar5 + iVar4 * 4),
               (int)*(short *)(iVar5 + (iVar4 * 2 + 1) * 2));
    func_02147288(uRam020705f4,auStack_88,auStack_28);
    iVar5 = (int)(uint)uVar2 >> 4;
    func_021478f0(auStack_58,auStack_28,(int)*(short *)(iRam020705f0 + iVar5 * 4),
                  (int)*(short *)(iRam020705f0 + (iVar5 * 2 + 1) * 2));
    func_02147288(uRam020705ec,auStack_58,auStack_1c);
    func_01ffd0e8(param_2,uRam020705ec,auStack_1c);
    uVar1 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x80000000) != 0) {
      *param_2 = -(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                  *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20);
      uVar1 = (uint)(param_2 + 1) & 3;
      uVar3 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
      param_2[1] = -(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      uVar1 = (uint)(param_2 + 2) & 3;
      uVar3 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      param_2[2] = -(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      uVar1 = (uint)(param_2 + 3) & 3;
      uVar3 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
      param_2[3] = -(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    }
    uVar1 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 2) == 0) {
      iVar5 = VecFx32_CrossProduct_0(param_1 + 0xb0,param_1 + 0x138);
      if (iVar5 < 1) {
        iVar5 = -iVar5;
      }
      *(int *)(param_1 + 0x3f8) = iVar5;
      uVar1 = param_1 + 0x3f8U & 3;
      uVar3 = *(uint *)(param_1 + 0x3f8U & 0xfffffffc);
      if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < iRam020705f8) {
        *(int *)(param_1 + 0x3f8) = iRam020705f8;
      }
      return;
    }
    return;
  }
  return;
}

