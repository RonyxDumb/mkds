/* Decompiled C draft; module arm9; ROM address 0201063c. No matching claim. */
#include "types.h"
#include "deps/0201063c_func_0201063c.h"

void func_0201063c(int param_1,ushort *param_2)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar3 = uRam020106c4;
  uVar2 = *param_2;
  uVar4 = 0;
  if ((char)param_2[1] != '\0') {
    do {
      pbVar1 = (byte *)(param_1 + (uint)uVar2 + uVar4);
      uVar4 = uVar4 + 1;
      uVar5 = (uint)*(ushort *)(param_1 + 4 + (uint)*(ushort *)(param_1 + 10)) * (uint)*pbVar1 +
              param_1 + 4 + (uint)*(ushort *)(param_1 + 10) + 4;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      iVar7 = param_1 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
      uVar5 = iVar7 + 0x14U & 3;
      uVar6 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
      *(uint *)(iVar7 + 0x14) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & uVar3;
      *(undefined4 *)(iVar7 + 0x24) = 0x1000;
      uVar5 = iVar7 + 0x24U & 3;
      uVar6 = *(uint *)(iVar7 + 0x24U & 0xfffffffc);
      *(uint *)(iVar7 + 0x28) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    } while (uVar4 < (byte)param_2[1]);
  }
  *(byte *)((int)param_2 + 3) = *(byte *)((int)param_2 + 3) & 0xfe;
  return;
}

