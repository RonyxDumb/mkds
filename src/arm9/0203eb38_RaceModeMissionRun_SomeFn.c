/* Decompiled C draft; module arm9; ROM address 0203eb38. No matching claim. */
#include "types.h"
#include "deps/0203eb38_RaceModeMissionRun_SomeFn.h"

void RaceModeMissionRun_SomeFn(void)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  uVar5 = uRam0203ece8;
  uVar4 = uRam0203ece4;
  uVar11 = 0;
  uVar6 = *(uint *)(uRam0203ece4 & 0xfffffffc) >> (uRam0203ece4 & 3) * 8 |
          *(uint *)(uRam0203ece4 & 0xfffffffc) << (uRam0203ece4 & 3) * -8 + 0x20;
  bVar2 = *(byte *)(uVar6 + 0x3d0);
  if (bVar2 != 0) {
    do {
      uVar9 = (*(uint *)(uRam0203ecec & 0xfffffffc) >> (uRam0203ecec & 3) * 8 |
              *(uint *)(uRam0203ecec & 0xfffffffc) << (uRam0203ecec & 3) * -8 + 0x20) +
              uVar11 * 0x8c + 0x14;
      uVar7 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      if (((uVar9 == 1) || (uVar9 == 2)) || (bVar1 = false, uVar9 == 3)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar9 = uVar6 + 8 & 3;
        uVar7 = *(uint *)(uVar6 + 8 & 0xfffffffc);
        uVar6 = *(uint *)(uRam0203ecec & 0xfffffffc) >> (uRam0203ecec & 3) * 8 |
                *(uint *)(uRam0203ecec & 0xfffffffc) << (uRam0203ecec & 3) * -8 + 0x20;
        iVar10 = uVar6 + 0x14 + uVar11 * 0x8c;
        uVar12 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                 *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
        uVar6 = uVar12;
        if ((uVar7 >> uVar9 * 8 == 0 && uVar7 << uVar9 * -8 + 0x20 == 0) &&
           (uVar9 = iVar10 + 0x44U & 3, uVar7 = *(uint *)(iVar10 + 0x44U & 0xfffffffc),
           uVar6 = uVar5, 0 < (int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20))) {
          iVar8 = FX_Inv();
          uVar6 = uVar12 * iVar8 >> 0xc;
          if (uVar5 < uVar6) {
            uVar6 = uVar5;
          }
        }
        MaybeConvertElapsedTime((undefined1 *)(uintptr_t)(iVar10 + 0x22),(undefined1 *)(uintptr_t)(iVar10 + 0x23),(undefined2 *)(uintptr_t)(iVar10 + 0x20),0,uVar6);
        uVar6 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        bVar1 = true;
        iVar8 = GetGlobalRK();
        cVar3 = *(char *)(uVar6 + 0x2f);
        if (cVar3 == '\x04') {
          uVar9 = iVar8 + 4U & 3;
          uVar7 = *(uint *)(iVar8 + 4U & 0xfffffffc);
          bVar1 = (uint)*(byte *)(uVar6 + 0x37) <= (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20)
          ;
        }
        else if ((cVar3 == '\x06') && ((*(ushort *)(iVar10 + 0x3c) & 0xf) != 1)) {
          bVar1 = false;
        }
        if (bVar1) {
          uVar6 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8;
          uVar9 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          if ((uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) == 4) {
            func_0203e788(((uint)*(ushort *)(iVar10 + 0x3c) << 0x18) >> 0x1c,0);
          }
        }
        else {
          func_0203e788(((uint)*(ushort *)(iVar10 + 0x3c) << 0x18) >> 0x1c,4);
        }
      }
      uVar6 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      bVar2 = *(byte *)(uVar6 + 0x3d0);
      uVar11 = uVar11 + 1 & 0xffff;
    } while (uVar11 < bVar2);
  }
  *(ushort *)
   ((*(uint *)(uRam0203ecec & 0xfffffffc) >> (uRam0203ecec & 3) * 8 |
    *(uint *)(uRam0203ecec & 0xfffffffc) << (uRam0203ecec & 3) * -8 + 0x20) + 0xe) = (ushort)bVar2;
  return;
}

