/* Decompiled C draft; module arm9; ROM address 020106c8. No matching claim. */
#include "types.h"
#include "deps/020106c8_func_020106c8.h"

void func_020106c8(int param_1,ushort *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  uint local_30;
  
  local_30 = *(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
             *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20;
  bVar7 = (local_30 & 0x1c000000) != 0x14000000;
  uVar1 = *param_2;
  if (bVar7) {
    uVar6 = param_3 + 8U & 3;
    uVar3 = *(uint *)(param_3 + 8U & 0xfffffffc);
    local_30 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  }
  uVar6 = 0;
  if (!bVar7) {
    uVar3 = param_3 + 0x18U & 3;
    uVar4 = *(uint *)(param_3 + 0x18U & 0xfffffffc);
    local_30 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  }
  local_30 = local_30 & uRam020107dc;
  if ((char)param_2[1] != '\0') {
    do {
      uVar3 = (uint)*(ushort *)(param_1 + 4 + (uint)*(ushort *)(param_1 + 10)) *
              (uint)*(byte *)(param_1 + (uint)uVar1 + uVar6) +
              param_1 + 4 + (uint)*(ushort *)(param_1 + 10) + 4;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar5 = param_1 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
      uVar3 = iVar5 + 0x14U & 3;
      uVar4 = *(uint *)(iVar5 + 0x14U & 0xfffffffc);
      *(uint *)(iVar5 + 0x14) =
           uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 |
           (*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
           *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20) + local_30;
      uVar3 = param_4 + 4 & 3;
      uVar4 = *(uint *)(param_4 + 4 & 0xfffffffc);
      uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      uVar4 = uVar3 & uRam020107e0;
      uVar3 = uRam020107e0 & uVar3 >> 0xb;
      if (uVar4 == *(ushort *)(iVar5 + 0x20)) {
        uVar2 = 0x1000;
      }
      else {
        uVar2 = FX_Div(uVar4 << 0xc,(uint)*(ushort *)(iVar5 + 0x20) << 0xc);
      }
      *(undefined4 *)(iVar5 + 0x24) = uVar2;
      if (uVar3 == *(ushort *)(iVar5 + 0x22)) {
        uVar2 = 0x1000;
      }
      else {
        uVar2 = FX_Div(uVar3 << 0xc,(uint)*(ushort *)(iVar5 + 0x22) << 0xc);
      }
      *(undefined4 *)(iVar5 + 0x28) = uVar2;
      uVar6 = uVar6 + 1;
    } while (uVar6 < (byte)param_2[1]);
  }
  *(byte *)((int)param_2 + 3) = *(byte *)((int)param_2 + 3) | 1;
  return;
}

