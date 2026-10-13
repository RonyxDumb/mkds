/* Decompiled C draft; module arm9; ROM address 021219cc. No matching claim. */
#include "types.h"
#include "deps/021219cc_func_021219cc.h"

void func_021219cc(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = uRam02121af0;
  uVar6 = 0;
  uVar5 = *(uint *)(uRam02121af0 & 0xfffffffc) >> (uRam02121af0 & 3) * 8 |
          *(uint *)(uRam02121af0 & 0xfffffffc) << (uRam02121af0 & 3) * -8 + 0x20;
  if (*(char *)(uVar5 + 0x1f53) == '\0') {
    return;
  }
  do {
    if (((uint)*(byte *)(uVar5 + 0x1f55) & 1 << uVar6) != 0) {
      uVar5 = func_0x0219bb50();
      if (uVar6 == uVar5) {
        cVar2 = *(char *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + uVar6 + 0x1f4e
                         );
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(cVar2 * 0x18 + iVar4 + 8) = 0;
      }
      else {
        cVar2 = *(char *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + uVar6 + 0x1f4e
                         );
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(cVar2 * 0x18 + iVar4 + 8) = 3;
      }
      uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      cVar2 = *(char *)(uVar5 + uVar6 + 0x1f4e);
      iVar4 = GetGlobalCA_from_thumb();
      uVar5 = uVar5 + uVar6 * 0x44 + 0x1e40;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(iVar4 + cVar2 * 0x18) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      cVar2 = *(char *)(uVar5 + uVar6 + 0x1f4e);
      iVar4 = GetGlobalCA_from_thumb();
      uVar5 = uVar5 + uVar6 * 0x44 + 0x1e44;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(cVar2 * 0x18 + iVar4 + 4) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    }
    uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < *(byte *)(uVar5 + 0x1f53));
  return;
}

