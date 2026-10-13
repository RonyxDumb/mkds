/* Decompiled C draft; module arm9; ROM address 020b1a34. No matching claim. */
#include "types.h"
#include "deps/020b1a34_func_020b1a34.h"

void func_020b1a34(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar7;
  uint uVar8;
  ushort uStack_64;
  byte bStack_62;
  byte bStack_61;
  ushort uStack_60;
  byte bStack_5e;
  byte bStack_5d;
  undefined2 uStack_5c;
  undefined1 uStack_5a;
  undefined1 uStack_59;
  int aiStack_58 [6];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uVar6;
  
  uVar1 = (*(uint *)(uRam020b1bec & 0xfffffffc) >> (uRam020b1bec & 3) * 8 |
          *(uint *)(uRam020b1bec & 0xfffffffc) << (uRam020b1bec & 3) * -8 + 0x20) + 8;
  uVar8 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar8 * 8 | uVar1 << uVar8 * -8 + 0x20) < 2) {
    *(undefined4 *)
     ((*(uint *)(uRam020b1bf0 & 0xfffffffc) >> (uRam020b1bf0 & 3) * 8 |
      *(uint *)(uRam020b1bf0 & 0xfffffffc) << (uRam020b1bf0 & 3) * -8 + 0x20) + 0x8dc) = 1;
  }
  uVar1 = (*(uint *)(uRam020b1bf0 & 0xfffffffc) >> (uRam020b1bf0 & 3) * 8 |
          *(uint *)(uRam020b1bf0 & 0xfffffffc) << (uRam020b1bf0 & 3) * -8 + 0x20) + 0x8e4;
  uVar8 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (uVar1 >> uVar8 * 8 != 0 || uVar1 << uVar8 * -8 + 0x20 != 0) {
    uVar1 = 0;
    do {
      uVar8 = uVar1 + 1 & 0xff;
      aiStack_58[uVar1 * 3] = 0;
      aiStack_58[uVar1 * 3 + 1] = 0;
      aiStack_58[uVar1 * 3 + 2] = 0;
      uVar1 = uVar8;
    } while (uVar8 < 2);
    uVar8 = 1;
    iVar2 = GetSomeLapCount();
    uVar1 = uRam020b1bec;
    if (0 < iVar2) {
      do {
        uVar3 = uVar1 & 3;
        uVar5 = *(uint *)(uVar1 & 0xfffffffc);
        uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
        uVar3 = uVar6 + 8;
        uVar5 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) == 1) {
          Mem_CpuCopy8((ushort *)(uintptr_t)(uVar6 + 0x3ec + (uVar8 - 1) * 4),(uint *)(void *)(&uStack_64),4);
        }
        aiStack_58[0] = aiStack_58[0] + (uint)bStack_62;
        aiStack_58[1] = aiStack_58[1] + (uint)bStack_61;
        aiStack_58[2] = aiStack_58[2] + (uint)uStack_64;
        uVar4 = GetCurrentPlayerRacerId();
        MaybeGetPlayerLapTime(uVar4,uVar8,&bStack_5e,&bStack_5d);
        uVar8 = uVar8 + 1 & 0xff;
        aiStack_58[3] = aiStack_58[3] + (uint)bStack_5e;
        aiStack_58[4] = aiStack_58[4] + (uint)bStack_5d;
        aiStack_58[5] = aiStack_58[5] + (uint)uStack_60;
        iVar2 = GetSomeLapCount();
      } while ((int)uVar8 <= iVar2);
    }
    uVar4 = func_020b1bf8((uint)(uintptr_t)(aiStack_58 + 3),(uint)(uintptr_t)(aiStack_58),&uStack_5c);
    *(undefined4 *)
     ((*(uint *)(uRam020b1bf0 & 0xfffffffc) >> (uRam020b1bf0 & 3) * 8 |
      *(uint *)(uRam020b1bf0 & 0xfffffffc) << (uRam020b1bf0 & 3) * -8 + 0x20) + 0x8e8) = uVar4;
    func_020ae7c4(uStack_5a,uStack_59,uStack_5c,&uStack_40);
    puVar7 = (undefined4 *)
             ((*(uint *)(uRam020b1bf0 & 0xfffffffc) >> (uRam020b1bf0 & 3) * 8 |
              *(uint *)(uRam020b1bf0 & 0xfffffffc) << (uRam020b1bf0 & 3) * -8 + 0x20) + iRam020b1bf4
             );
    *puVar7 = uStack_40;
    puVar7[1] = uStack_3c;
    puVar7[2] = uStack_38;
    puVar7[3] = uStack_34;
    puVar7[4] = uStack_30;
    puVar7[5] = uStack_2c;
    puVar7[6] = uStack_28;
    return;
  }
  return;
}

