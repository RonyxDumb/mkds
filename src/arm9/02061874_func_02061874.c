/* Decompiled C draft; module arm9; ROM address 02061874. No matching claim. */
#include "types.h"
#include "deps/02061874_func_02061874.h"

void func_02061874(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = *(uint *)(uRam0206191c & 0xfffffffc) >> (uRam0206191c & 3) * 8 |
          *(uint *)(uRam0206191c & 0xfffffffc) << (uRam0206191c & 3) * -8 + 0x20;
  uVar7 = uVar8 + 0x24;
  uVar9 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if ((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) == 1) {
    *(undefined4 *)(uVar8 + 0x24) = 0;
  }
  *(undefined4 *)
   ((*(uint *)(uRam0206191c & 0xfffffffc) >> (uRam0206191c & 3) * 8 |
    *(uint *)(uRam0206191c & 0xfffffffc) << (uRam0206191c & 3) * -8 + 0x20) + 0x20) = 1;
  func_0207a5f0(0);
  func_02062ef8(1);
  *puRam02061920 = 0x48;
  func_02061944(0x48,1);
  puVar6 = puRam0206193c;
  puVar5 = puRam02061938;
  puVar4 = puRam02061934;
  puVar3 = puRam02061930;
  puVar2 = puRam0206192c;
  uVar1 = *puRam02061924;
  uVar7 = uRam02061928 & 3;
  uVar9 = *(uint *)(uRam02061928 & 0xfffffffc);
  *puRam02061940 = 1;
  *puVar4 = 0;
  *puVar5 = 0;
  *puVar6 = 0;
  *puVar2 = uVar1;
  *puVar3 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  return;
}

