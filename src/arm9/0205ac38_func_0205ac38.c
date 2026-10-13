/* Decompiled C draft; module arm9; ROM address 0205ac38. No matching claim. */
#include "types.h"
#include "deps/0205ac38_func_0205ac38.h"

void func_0205ac38(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  
  uVar1 = uRam0205ad40;
  uVar6 = 0;
  uVar9 = 0;
  uVar3 = (*(uint *)(uRam0205ad40 & 0xfffffffc) >> (uRam0205ad40 & 3) * 8 |
          *(uint *)(uRam0205ad40 & 0xfffffffc) << (uRam0205ad40 & 3) * -8 + 0x20) + 0x754;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar7 = uVar3 + 0x3c;
  pbVar8 = (byte *)(uVar3 + 0x2c);
  do {
    uVar3 = uVar1 & 3;
    uVar4 = *(uint *)(uVar1 & 0xfffffffc);
    iVar5 = uVar9 * 0xc + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x324;
    if (((*(char *)(iVar5 + 8) == '\0') || (*(char *)(iVar5 + 8) == '\x02')) ||
       (*(byte *)(iVar5 + 9) == 0xf)) {
      bVar2 = 0xf;
    }
    else {
      bVar2 = *(byte *)(iVar5 + 9) & 0x1f | (byte)((*(byte *)(iVar5 + 10) & 7) << 5);
    }
    *pbVar8 = bVar2;
    if (((*(char *)(iVar5 + 8) != '\0') && (*(char *)(iVar5 + 8) == '\x01')) &&
       ((*(byte *)(iVar5 + 0xb) != 0 && (-1 < (int)(0x30 - (uVar6 + *(byte *)(iVar5 + 0xb))))))) {
      uVar3 = iVar5 + 4U & 3;
      uVar4 = *(uint *)(iVar5 + 4U & 0xfffffffc);
      Mem_CpuCopy8(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,iVar7);
      uVar6 = uVar6 + *(byte *)(iVar5 + 0xb) & 0xffff;
      iVar7 = iVar7 + (uint)*(byte *)(iVar5 + 0xb);
    }
    uVar9 = uVar9 + 1 & 0xffff;
    pbVar8 = pbVar8 + 1;
  } while (uVar9 < 0x10);
  *(short *)((*(uint *)(uRam0205ad40 & 0xfffffffc) >> (uRam0205ad40 & 3) * 8 |
             *(uint *)(uRam0205ad40 & 0xfffffffc) << (uRam0205ad40 & 3) * -8 + 0x20) + 0x724) =
       0x30 - (short)uVar6;
  return;
}

