/* Decompiled C draft; module arm9; ROM address 0205e1c4. No matching claim. */
#include "types.h"
#include "deps/0205e1c4_func_0205e1c4.h"

undefined4 func_0205e1c4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  uVar5 = *(uint *)(uRam0205e2b4 & 0xfffffffc) >> (uRam0205e2b4 & 3) * 8 |
          *(uint *)(uRam0205e2b4 & 0xfffffffc) << (uRam0205e2b4 & 3) * -8 + 0x20;
  uVar7 = 0;
  if (*(short *)(uVar5 + 4) != 0) {
    do {
      uVar5 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      iVar6 = uVar5 + uVar7 * 0xc;
      iVar1 = GetGlobalPENkmAREAByIndex_from_thumb(*(undefined2 *)(uVar5 + uVar7 * 0xc));
      uVar5 = iVar6 + 4U & 3;
      uVar4 = *(uint *)(iVar6 + 4U & 0xfffffffc);
      iVar2 = GetAreaSomeCount(iVar1,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,
                               *(undefined2 *)(iVar1 + 0x3c));
      uVar4 = uVar8;
      uVar5 = uVar8;
      if (0 < iVar2) {
        do {
          iVar3 = func_020d411c(uVar5);
          iVar3 = func_02041944(iVar3 + 4,iVar1);
          if (iVar3 != 0) {
            uVar4 = uVar4 + 1 & 0xff;
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while ((int)uVar5 < iVar2);
      }
      if (*(byte *)(iVar6 + 9) < uVar4) {
        *(char *)(iVar6 + 8) = *(char *)(iVar6 + 8) + '\x01';
      }
      *(char *)(iVar6 + 9) = (char)uVar4;
      if (*(short *)(iVar1 + 0x3e) < (short)(ushort)*(byte *)(iVar6 + 8)) {
        return 1;
      }
      uVar5 = *(uint *)(uRam0205e2b4 & 0xfffffffc) >> (uRam0205e2b4 & 3) * 8 |
              *(uint *)(uRam0205e2b4 & 0xfffffffc) << (uRam0205e2b4 & 3) * -8 + 0x20;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(ushort *)(uVar5 + 4));
  }
  return 0;
}

