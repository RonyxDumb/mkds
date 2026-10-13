/* Decompiled C draft; module arm9; ROM address 0205d558. No matching claim. */
#include "types.h"
#include "deps/0205d558_func_0205d558.h"

void func_0205d558(uint param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined2 *puVar10;
  uint uVar9;
  
  uVar7 = 0;
  do {
    uVar5 = *(uint *)(uRam0205d6c4 & 0xfffffffc) >> (uRam0205d6c4 & 3) * 8 |
            *(uint *)(uRam0205d6c4 & 0xfffffffc) << (uRam0205d6c4 & 3) * -8 + 0x20;
    uVar8 = uVar5 + 8;
    uVar3 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar9 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
    uVar3 = *(uint *)(uRam0205d6c8 & 0xfffffffc) >> (uRam0205d6c8 & 3) * 8 |
            *(uint *)(uRam0205d6c8 & 0xfffffffc) << (uRam0205d6c8 & 3) * -8 + 0x20;
    iVar4 = *(ushort *)(uVar5 + 0x60) - 1;
    iVar6 = iVar4 >> 0x1f;
    uVar5 = ((uint)(iVar4 * 0x40000000 + iVar6) >> 0x1e | iVar6 << 2) - iVar6 & 0xff;
    uVar8 = 0;
    puVar10 = (undefined2 *)(uVar3 + 0x144 + uVar5 * 8 + uVar7 * 4);
    iVar6 = (int)((uVar5 - 1) * 0x1000000) >> 0x18;
    if ((((uVar9 == 2) || (uVar9 == 3)) || (uVar9 == 5)) && (iVar6 < 0)) {
      iVar6 = (iVar6 + 4) * 0x1000000 >> 0x18;
    }
    if (iVar6 < 0) {
      bVar2 = 0;
    }
    else {
      bVar2 = *(byte *)(uVar3 + iVar6 * 8 + uVar7 * 4 + 0x146);
    }
    uVar3 = 0;
    if (uVar7 == param_1) {
      bVar2 = bVar2 + 1;
    }
    if (99 < bVar2) {
      bVar2 = 99;
    }
    *(byte *)(puVar10 + 1) = bVar2;
    uVar5 = *(uint *)(uRam0205d6c4 & 0xfffffffc) >> (uRam0205d6c4 & 3) * 8 |
            *(uint *)(uRam0205d6c4 & 0xfffffffc) << (uRam0205d6c4 & 3) * -8 + 0x20;
    if (*(char *)(uVar5 + 0x3d0) != '\0') {
      do {
        uVar9 = uVar3 * 0x30 + uVar5 + 0x74;
        uVar1 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        if (uVar7 == (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20)) {
          iVar4 = *(ushort *)(uVar5 + 0x60) - 1;
          iVar6 = iVar4 >> 0x1f;
          uVar8 = uVar8 + *(ushort *)
                           ((uVar3 & 0xff) * 10 +
                           (((uint)(iVar4 * 0x40000000 + iVar6) >> 0x1e | iVar6 << 2) - iVar6 & 0xff
                           ) * 0x50 +
                           (*(uint *)(uRam0205d6c8 & 0xfffffffc) >> (uRam0205d6c8 & 3) * 8 |
                           *(uint *)(uRam0205d6c8 & 0xfffffffc) << (uRam0205d6c8 & 3) * -8 + 0x20))
                  & 0xffff;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < *(byte *)(uVar5 + 0x3d0));
    }
    uVar7 = uVar7 + 1;
    if (uRam0205d6cc < uVar8) {
      uVar8 = uRam0205d6cc;
    }
    *puVar10 = (short)uVar8;
  } while ((int)uVar7 < 2);
  return;
}

