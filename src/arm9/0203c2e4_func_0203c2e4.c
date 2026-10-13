/* Decompiled C draft; module arm9; ROM address 0203c2e4. No matching claim. */
#include "types.h"
#include "deps/0203c2e4_func_0203c2e4.h"

void func_0203c2e4(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  
  uVar4 = DAT_0203c4c8;
  uVar12 = *(uint *)(DAT_0203c4c4 & 0xfffffffc) >> (DAT_0203c4c4 & 3) * 8 |
           *(uint *)(DAT_0203c4c4 & 0xfffffffc) << (DAT_0203c4c4 & 3) * -8 + 0x20;
  bVar3 = false;
  iVar8 = uVar12 + 0x14;
  uVar5 = iVar8 + param_1 * 0x8c;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  puVar13 = (undefined4 *)(iVar8 + param_1 * 0x8c);
  if (((uVar5 == 1) || (uVar5 == 2)) || (uVar5 == 3)) {
    bVar3 = true;
  }
  if (!bVar3) {
    uVar1 = *(ushort *)(puVar13 + 0xf);
    uVar9 = (uint)*(byte *)((*(uint *)(DAT_0203c4c8 & 0xfffffffc) >> (DAT_0203c4c8 & 3) * 8 |
                            *(uint *)(DAT_0203c4c8 & 0xfffffffc) << (DAT_0203c4c8 & 3) * -8 + 0x20)
                           + 0x3d0) - (uint)*(ushort *)(uVar12 + 0x10);
    *(ushort *)(puVar13 + 0xf) = uVar1 & 0xfff0 | (ushort)(uVar9 * 0x10000 >> 0x10) & 0xf;
    iVar8 = DAT_0203c4cc;
    uVar5 = DAT_0203c4c4;
    iVar11 = 0;
    if (*(char *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
      iVar10 = 0;
      do {
        uVar12 = uVar5 & 3;
        uVar6 = *(uint *)(uVar5 & 0xfffffffc);
        iVar7 = (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + 0x14 + iVar10;
        if (iVar11 != param_1) {
          uVar2 = *(ushort *)(iVar7 + 0x3c);
          uVar12 = uVar2 & 0xf;
          if (((uVar1 & 0xf) < uVar12) && (uVar12 <= (uVar9 & 0xffff))) {
            *(ushort *)(iVar7 + 0x3c) =
                 uVar2 & 0xfff0 | (ushort)((uVar12 + iVar8) * 0x10000 >> 0x10) & 0xf;
          }
        }
        iVar11 = iVar11 + 1;
        iVar10 = iVar10 + 0x8c;
      } while (iVar11 < (int)(uint)*(byte *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                                             *(uint *)(uVar4 & 0xfffffffc) <<
                                             (uVar4 & 3) * -8 + 0x20) + 0x3d0));
    }
    uVar5 = *(uint *)(DAT_0203c4c4 & 0xfffffffc) >> (DAT_0203c4c4 & 3) * 8 |
            *(uint *)(DAT_0203c4c4 & 0xfffffffc) << (DAT_0203c4c4 & 3) * -8 + 0x20;
    *(short *)(uVar5 + 0x10) = *(short *)(uVar5 + 0x10) + 1;
  }
  uVar5 = (*(uint *)(DAT_0203c4c8 & 0xfffffffc) >> (DAT_0203c4c8 & 3) * 8 |
          *(uint *)(DAT_0203c4c8 & 0xfffffffc) << (DAT_0203c4c8 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) == 2) {
    func_020a16d0(param_1);
  }
  *puVar13 = 4;
  GetDriverEntry(param_1);
  StructMQRacerEntry_SomeFn_34();
  func_020b1cdc(param_1,1);
  iVar8 = func_0203ef58();
  if (iVar8 != 0) {
    uVar5 = (*(uint *)(DAT_0203c4c8 & 0xfffffffc) >> (DAT_0203c4c8 & 3) * 8 |
            *(uint *)(DAT_0203c4c8 & 0xfffffffc) << (DAT_0203c4c8 & 3) * -8 + 0x20) + 8;
    uVar9 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    switch(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) {
    case 0:
      break;
    case 1:
      return;
    case 2:
      RaceModeBattle_OrMissionRun_SomeFn();
      return;
    case 3:
      break;
    case 4:
      RaceModeMissionRun_SomeFn();
      return;
    case 5:
      RaceModeNet_SomeFn();
      return;
    }
    RaceModeDefault_SomeFn();
    return;
  }
  return;
}

