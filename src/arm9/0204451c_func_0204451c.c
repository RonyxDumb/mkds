/* Decompiled C draft; module arm9; ROM address 0204451c. No matching claim. */
#include "types.h"
#include "deps/0204451c_func_0204451c.h"

void func_0204451c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  uVar5 = *(uint *)(uRam020445f4 & 0xfffffffc) >> (uRam020445f4 & 3) * 8 |
          *(uint *)(uRam020445f4 & 0xfffffffc) << (uRam020445f4 & 3) * -8 + 0x20;
  uVar9 = 3;
  if (*(char *)(uVar5 + 0x3d5) == -1) {
    uVar9 = 0;
  }
  else if (*(char *)(uVar5 + 0x3d6) == -1) {
    uVar9 = 1;
  }
  iVar8 = param_1 * 0x30;
  iVar6 = (*(uint *)(uRam020445f4 & 0xfffffffc) >> (uRam020445f4 & 3) * 8 |
          *(uint *)(uRam020445f4 & 0xfffffffc) << (uRam020445f4 & 3) * -8 + 0x20) + iVar8;
  uVar5 = iVar6 + 0x74U & 3;
  uVar3 = *(uint *)(iVar6 + 0x74U & 0xfffffffc);
  uVar1 = iVar6 + 0x68U & 3;
  uVar4 = *(uint *)(iVar6 + 0x68U & 0xfffffffc);
  uVar2 = iVar6 + 0x6cU & 3;
  uVar7 = *(uint *)(iVar6 + 0x6cU & 0xfffffffc);
  StructCO_ConfigureRacerDefault
            (param_1,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
             uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20,1,
             uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,uVar9);
  uVar5 = *(uint *)(uRam020445f4 & 0xfffffffc) >> (uRam020445f4 & 3) * 8 |
          *(uint *)(uRam020445f4 & 0xfffffffc) << (uRam020445f4 & 3) * -8 + 0x20;
  iVar6 = uVar5 + iVar8;
  *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 0x250);
  *(undefined4 *)(iVar6 + 0x6c) = *(undefined4 *)(iVar6 + 0x254);
  *(undefined4 *)(iVar6 + 0x70) = *(undefined4 *)(iVar6 + 600);
  *(undefined4 *)(iVar6 + 0x74) = *(undefined4 *)(iVar6 + 0x25c);
  *(undefined4 *)(iVar6 + 0x78) = *(undefined4 *)(iVar6 + 0x260);
  *(undefined4 *)(iVar6 + 0x7c) = *(undefined4 *)(iVar6 + 0x264);
  *(undefined4 *)(iVar6 + 0x80) = *(undefined4 *)(iVar6 + 0x268);
  *(undefined4 *)(iVar6 + 0x84) = *(undefined4 *)(iVar6 + 0x26c);
  *(undefined4 *)(iVar6 + 0x88) = *(undefined4 *)(iVar6 + 0x270);
  *(undefined4 *)(iVar6 + 0x8c) = *(undefined4 *)(iVar6 + 0x274);
  *(undefined4 *)(iVar6 + 0x90) = *(undefined4 *)(iVar6 + 0x278);
  *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x27c);
  if (uVar9 < 2) {
    *(char *)(uVar5 + uVar9 + 0x3d5) = (char)param_1;
  }
  uVar9 = uRam020445f4;
  uVar5 = *(uint *)(uRam020445f4 & 0xfffffffc) >> (uRam020445f4 & 3) * 8 |
          *(uint *)(uRam020445f4 & 0xfffffffc) << (uRam020445f4 & 3) * -8 + 0x20;
  *(undefined1 *)(uVar5 + iVar8 + 0x26e) = *(undefined1 *)(uVar5 + 0x3e1);
  uVar5 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  *(char *)(uVar5 + 0x3e1) = *(char *)(uVar5 + 0x3e1) + '\x01';
  return;
}

