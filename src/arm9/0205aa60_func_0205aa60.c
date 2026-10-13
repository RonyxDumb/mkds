/* Decompiled C draft; module arm9; ROM address 0205aa60. No matching claim. */
#include "types.h"
#include "deps/0205aa60_func_0205aa60.h"

void func_0205aa60(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  uint local_2c;
  
  uVar3 = uRam0205ab74;
  uVar10 = 0;
  local_2c = 0;
  do {
    uVar5 = func_0x0219bb50();
    if (((uVar10 != uVar5) &&
        (uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20,
        ((uint)*(byte *)(uVar5 + 0x749) & 1 << uVar10) != 0)) &&
       ((int)((uint)*(byte *)(uVar5 + uVar10 * 0x88 + 0x18a) << 0x1f) < 0)) {
      iVar6 = uVar5 + uVar10 * 0x88;
      iVar8 = iVar6 + 0x13c;
      pbVar9 = (byte *)(iVar6 + 300);
      uVar5 = local_2c;
      do {
        bVar2 = *pbVar9;
        iVar6 = uVar5 * 0x30 +
                (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3e4 + uVar10 * 0xc;
        *(byte *)(iVar6 + 9) = bVar2 & 0x1f;
        *(char *)(iVar6 + 10) = (char)((int)(bVar2 & 0xe0) >> 5);
        if (*(char *)(iVar6 + 9) == '\x0f') {
          *(undefined1 *)(iVar6 + 0xb) = 0;
        }
        else {
          uVar4 = func_020fa0e8(*(char *)(iVar6 + 9),*(undefined1 *)(iVar6 + 10));
          *(undefined1 *)(iVar6 + 0xb) = uVar4;
        }
        if (*(char *)(iVar6 + 0xb) != '\0') {
          uVar1 = iVar6 + 4U & 3;
          uVar7 = *(uint *)(iVar6 + 4U & 0xfffffffc);
          Mem_CpuCopy8(iVar8,uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
          iVar8 = iVar8 + (uint)*(byte *)(iVar6 + 0xb);
        }
        uVar5 = uVar5 + 1 & 0xffff;
        pbVar9 = pbVar9 + 1;
      } while (uVar5 < 0x10);
    }
    uVar10 = uVar10 + 1 & 0xff;
  } while (uVar10 < 4);
  return;
}

