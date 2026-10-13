/* Decompiled C draft; module arm9; ROM address 02044fc0. No matching claim. */
#include "types.h"
#include "deps/02044fc0_func_02044fc0.h"

void func_02044fc0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar3 = uRam02045080;
  cVar4 = '\0';
  iVar7 = 0;
  do {
    iVar5 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar7;
    iVar7 = (iVar7 + 1) * 0x1000000 >> 0x18;
    *(undefined1 *)(iVar5 + 0x3d5) = 0xff;
    uVar2 = uRam02045080;
  } while (iVar7 < 2);
  uVar8 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  uVar3 = 0;
  if (*(char *)(uVar8 + 0x3d0) != '\0') {
    iVar7 = 0;
    do {
      if ((*(ushort *)((uVar3 & 0xffff) * 0x30 + uVar8 + 0x84) & 1) != 0) {
        uVar6 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
        cVar4 = cVar4 + '\x01';
        uVar8 = uVar6 + iVar7 + 0x78;
        uVar1 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(char *)(uVar6 + ((uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) & 0xff) + 0x3d5) =
             (char)uVar3;
      }
      uVar8 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar3 = (int)((uVar3 + 1) * 0x1000000) >> 0x18;
      iVar7 = iVar7 + 0x30;
    } while ((int)uVar3 < (int)(uint)*(byte *)(uVar8 + 0x3d0));
  }
  *(char *)(uVar8 + 0x3d4) = cVar4;
  return;
}

