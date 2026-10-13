/* Decompiled C draft; module arm9; ROM address 0208ee7c. No matching claim. */
#include "types.h"
#include "deps/0208ee7c_func_0208ee7c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0208ee7c(undefined4 param_1)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint local_40;
  
  local_40 = (uint)*pbRam0208f05c;
  bVar1 = false;
  iVar5 = IntrusiveListWrapper_NextItem
                    (*(uint *)(uRam0208f060 & 0xfffffffc) >> (uRam0208f060 & 3) * 8 |
                     *(uint *)(uRam0208f060 & 0xfffffffc) << (uRam0208f060 & 3) * -8 + 0x20,0);
  uVar4 = uRam0208f068;
  puVar3 = puRam0208f064;
  uVar2 = uRam0208f060;
  if (iVar5 != 0) {
    do {
      if (!bVar1) {
        *puRam0208f06c = *puRam0208f06c & 0xcfff | 8;
        *puRam0208f074 = uRam0208f070;
        *puRam0208f07c = uRam0208f078;
        *puRam0208f080 = 3;
        *puRam0208f084 = 0;
        *puRam0208f080 = 2;
        *puRam0208f088 =
             *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
             *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        uVar10 = uVar4 + 0x18 & 3;
        uVar9 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
        bVar1 = true;
        *puRam0208f08c =
             (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) >>
             (4 - (((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) >> 0x1a & 7) == 2) &
             0xff);
      }
      *puRam0208f094 = uRam0208f090;
      iVar6 = IntrusiveListWrapper_NextItem(iVar5 + 8,0);
      if (((iVar6 != 0) &&
          (*(uint *)(uRam0208f098 & 0xfffffffc) >> (uRam0208f098 & 3) * 8 != 0 ||
           *(uint *)(uRam0208f098 & 0xfffffffc) << (uRam0208f098 & 3) * -8 + 0x20 != 0)) &&
         (iVar7 = IntrusiveListWrapper_NextItem(iVar5 + 8,0), iVar7 != 0)) {
        do {
          uVar10 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x34;
          uVar9 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          *puVar3 = local_40 << 0x18 | uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20 | 0xc0 |
                    (0x1f - (uint)*(ushort *)(iVar6 + 0xc) * (uint)*pbRam0208f09c) * 0x10000;
          func_0208e82c(param_1,iVar6,iVar7,uVar4);
          iVar8 = IntrusiveListWrapper_NextItem(iVar5 + 8,iVar7);
          iVar6 = iVar7;
          iVar7 = iVar8;
        } while (iVar8 != 0);
      }
      local_40 = local_40 + 1 & 0xff;
      iVar5 = IntrusiveListWrapper_NextItem
                        (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,iVar5);
    } while (iVar5 != 0);
    return;
  }
  return;
}

