/* Decompiled C draft; module arm9; ROM address 02097d80. No matching claim. */
#include "types.h"
#include "deps/02097d80_func_02097d80.h"

void func_02097d80(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_10;
  uint uVar7;
  
  local_10 = 0x1e;
  func_01ff9048(0x14,&local_10,1);
  uVar6 = param_2 + 0xec0U & 3;
  uVar3 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
  iVar2 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) * 0x30 + param_2 + 0xa8;
  uVar6 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(iVar2 + 0x24) = (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) >> 4;
  uVar6 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(iVar2 + 0x28) = (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) >> 4;
  uVar6 = param_2 + 0xcU & 3;
  uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(iVar2 + 0x2c) = (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) >> 4;
  func_01ff9048(0x19,iVar2,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar6 = param_2 + 0xa4U & 3;
  uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  StructMapObject_SomeFn_8
            (*(uint *)(uRam02097e80 & 0xfffffffc) >> (uRam02097e80 & 3) * 8 |
             *(uint *)(uRam02097e80 & 0xfffffffc) << (uRam02097e80 & 3) * -8 + 0x20,
             uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20,0);
  uVar1 = uRam02097e80;
  uVar6 = (*(uint *)(uRam02097e80 & 0xfffffffc) >> (uRam02097e80 & 3) * 8 |
          *(uint *)(uRam02097e80 & 0xfffffffc) << (uRam02097e80 & 3) * -8 + 0x20) + 0x20;
  uVar3 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  *(uint *)(uVar7 + 0xc) = (uint)*(ushort *)(param_2 + 0xec4) << 0xc;
  uVar6 = uVar7 + 0x1c & 3;
  uVar4 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
  uVar3 = uVar7 + 0xc & 3;
  uVar5 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
  uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + (uint)*(ushort *)(uVar7 + 0x1a) * 4;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) =
       uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  uVar6 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x28;
  uVar3 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  *(uint *)(uVar7 + 0xc) = (uint)*(ushort *)(param_2 + 0xec6) << 0xc;
  uVar6 = uVar7 + 0x1c & 3;
  uVar4 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
  uVar3 = uVar7 + 0xc & 3;
  uVar5 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
  uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + (uint)*(ushort *)(uVar7 + 0x1a) * 4;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) =
       uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  DrawObject2D3D(param_1,*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20,param_2);
  return;
}

