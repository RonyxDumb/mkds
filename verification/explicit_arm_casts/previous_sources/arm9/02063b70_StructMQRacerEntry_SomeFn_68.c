/* Decompiled C draft; module arm9; ROM address 02063b70. No matching claim. */
#include "types.h"
#include "deps/02063b70_StructMQRacerEntry_SomeFn_68.h"

bool StructMQRacerEntry_SomeFn_68(int param_1)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar9;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint uVar6;
  undefined4 *puVar8;
  
  uVar3 = param_1 + 0x590U & 3;
  uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  uVar3 = uVar6 + 0x58;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  bVar2 = uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0;
  if (bVar2) {
    uVar3 = param_1 + 0x1d0U & 3;
    uVar9 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
    uVar5 = param_1 + 0x1b4U & 3;
    uVar7 = *(uint *)(param_1 + 0x1b4U & 0xfffffffc);
    puVar8 = (undefined4 *)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    local_44 = *puVar8;
    uStack_40 = puVar8[1];
    uStack_3c = puVar8[2];
    uStack_38 = puVar8[3];
    local_34 = puVar8[4];
    uStack_30 = puVar8[5];
    uStack_2c = puVar8[6];
    uStack_28 = puVar8[7];
    local_24 = puVar8[8];
    local_20 = puVar8[9];
    local_1c = puVar8[10];
    local_18 = puVar8[0xb];
    uVar5 = param_1 + 0x508U & 3;
    uVar7 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
    VecFx32_AddScale1((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + 0x5000,param_1 + 300,
                      uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20,&local_5c);
    local_1c = local_58 >> 4;
    local_20 = local_5c >> 4;
    local_18 = local_54 >> 4;
    uVar3 = param_1 + 0x4c8U & 3;
    uVar5 = *(uint *)(param_1 + 0x4c8U & 0xfffffffc);
    uVar7 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    uVar3 = param_1 + 0xbcU & 3;
    uVar5 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * (longlong)(int)uVar7;
    local_50 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar3 = param_1 + 0xc0U & 3;
    uVar5 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * (longlong)(int)uVar7;
    local_4c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar3 = param_1 + 0xc4U & 3;
    uVar5 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
    local_60 = 0x1e;
    lVar1 = (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * (longlong)(int)uVar7;
    local_48 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    func_01ff9048(0x14,&local_60,1);
    func_01ff9048(0x19,&local_44,0xc);
    func_01ff9048(0x1b,&local_50,3);
    LightInfo_MaybeApply(uVar6 + 0x40);
    func_0207a30c(*(undefined2 *)(param_1 + 0x74));
    uVar3 = param_1 + 0x590U & 3;
    uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0xa4;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar4 = GetKillerItemAnimation();
    *(uint *)(iVar4 + 0xc) = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar5 = iVar4 + 0xcU & 3;
    uVar7 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uVar3 = iVar4 + 0x1cU & 3;
    uVar6 = *(uint *)(iVar4 + 0x1cU & 0xfffffffc);
    uVar3 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) + (uint)*(ushort *)(iVar4 + 0x1a) * 4;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) =
         uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
    GetKillerItemModel();
    func_020849d0();
    GetSomeAD00Sh();
    StructAD00Sh_SomeFn_0();
  }
  return bVar2;
}

