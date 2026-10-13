/* Decompiled C draft; module arm9; ROM address 020c657c. No matching claim. */
#include "types.h"
#include "deps/020c657c_CheckHandleSaveTimeTrialRecord2.h"

undefined4 CheckHandleSaveTimeTrialRecord2(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  byte local_20;
  byte local_1f;
  ushort local_1e [3];
  
  uVar3 = GetCurrentPlayerRacerId();
  GetPlayerTotalTime(uVar3,&local_20,&local_1f,local_1e);
  uVar7 = uRam020c6768;
  uVar6 = uRam020c6764;
  uVar4 = *(uint *)(uRam020c6764 & 0xfffffffc) >> (uRam020c6764 & 3) * 8 |
          *(uint *)(uRam020c6764 & 0xfffffffc) << (uRam020c6764 & 3) * -8 + 0x20;
  puVar9 = (ushort *)(uVar4 + 0x1c);
  iVar11 = 0;
  while (((char)puVar9[0xc] != '\0' &&
         ((int)((uint)*puVar9 +
               (uint)*(byte *)((int)puVar9 + 3) * 1000 + (uint)(byte)puVar9[1] * iRam020c6760) <=
          (int)((uint)local_1e[0] + (uint)local_1f * 1000 + (uint)local_20 * iRam020c6760)))) {
    iVar11 = iVar11 + 1;
    puVar9 = puVar9 + 0x10;
    if (4 < iVar11) {
      return 0;
    }
  }
  if (param_1 == 0) {
    *(int *)(uVar4 + 0xc) = iVar11;
  }
  else {
    iVar13 = 4;
    if (iVar11 < 4) {
      iVar12 = 0x80;
      do {
        uVar4 = uVar6 & 3;
        uVar5 = *(uint *)(uVar6 & 0xfffffffc);
        uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
        puVar15 = (undefined2 *)(uVar4 + (iVar13 + -1) * 0x20 + 0x1c);
        puVar14 = (undefined2 *)(uVar4 + iVar13 * 0x20 + 0x1c);
        iVar10 = 8;
        do {
          puVar16 = puVar15 + 1;
          uVar1 = *puVar15;
          puVar15 = puVar15 + 2;
          uVar2 = *puVar16;
          iVar10 = iVar10 + -1;
          puVar16 = puVar14 + 1;
          *puVar14 = uVar1;
          puVar14 = puVar14 + 2;
          *puVar16 = uVar2;
        } while (iVar10 != 0);
        uVar5 = uVar7 & 3;
        uVar8 = *(uint *)(uVar7 & 0xfffffffc);
        uVar8 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
        uVar5 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        TimeTrialCopyToSaveData_from_thumb
                  (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20,iVar13,uVar4 + 0x1c + iVar12);
        iVar13 = iVar13 + -1;
        iVar12 = iVar12 + -0x20;
      } while (iVar11 < iVar13);
    }
    iVar13 = (*(uint *)(uRam020c6764 & 0xfffffffc) >> (uRam020c6764 & 3) * 8 |
             *(uint *)(uRam020c6764 & 0xfffffffc) << (uRam020c6764 & 3) * -8 + 0x20) + 0x1c;
    iVar12 = iVar13 + iVar11 * 0x20;
    *(byte *)(iVar12 + 2) = local_20;
    *(byte *)(iVar12 + 3) = local_1f;
    *(ushort *)(iVar13 + iVar11 * 0x20) = local_1e[0];
    iVar13 = GetCurrentPlayerRacerId();
    uVar6 = iVar13 * 0x30 +
            (*(uint *)(uRam020c6768 & 0xfffffffc) >> (uRam020c6768 & 3) * 8 |
            *(uint *)(uRam020c6768 & 0xfffffffc) << (uRam020c6768 & 3) * -8 + 0x20) + 0x88;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    CopyMemory16(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,iVar12 + 4,0x14);
    *(undefined1 *)(iVar12 + 0x18) = 1;
    iVar13 = GetCurrentPlayerRacerId();
    uVar6 = iVar13 * 0x30 +
            (*(uint *)(uRam020c6768 & 0xfffffffc) >> (uRam020c6768 & 3) * 8 |
            *(uint *)(uRam020c6768 & 0xfffffffc) << (uRam020c6768 & 3) * -8 + 0x20) + 0x68;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(byte *)(iVar12 + 0x19) = (byte)(uVar6 >> uVar7 * 8) | (byte)(uVar6 << uVar7 * -8 + 0x20);
    iVar13 = GetCurrentPlayerRacerId();
    uVar4 = uRam020c6768;
    uVar6 = iVar13 * 0x30 +
            (*(uint *)(uRam020c6768 & 0xfffffffc) >> (uRam020c6768 & 3) * 8 |
            *(uint *)(uRam020c6768 & 0xfffffffc) << (uRam020c6768 & 3) * -8 + 0x20) + 0x6c;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(byte *)(iVar12 + 0x1a) = (byte)(uVar6 >> uVar7 * 8) | (byte)(uVar6 << uVar7 * -8 + 0x20);
    uVar6 = uVar4 & 3;
    uVar7 = *(uint *)(uVar4 & 0xfffffffc);
    uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    TimeTrialCopyToSaveData_from_thumb
              (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,iVar11,iVar12);
    if (iVar11 != 5) {
      *(int *)((*(uint *)(uRam020c6764 & 0xfffffffc) >> (uRam020c6764 & 3) * 8 |
               *(uint *)(uRam020c6764 & 0xfffffffc) << (uRam020c6764 & 3) * -8 + 0x20) + 0xc) =
           iVar11;
    }
  }
  return 1;
}

