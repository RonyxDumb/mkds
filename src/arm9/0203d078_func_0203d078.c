/* Decompiled C draft; module arm9; ROM address 0203d078. No matching claim. */
#include "types.h"
#include "deps/0203d078_func_0203d078.h"

void func_0203d078(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  iVar3 = func_020a128c();
  uVar2 = DAT_0203d218;
  uVar5 = DAT_0203d214;
  if (iVar3 != 0) {
    uVar7 = 0;
    if (*(char *)((*(uint *)(DAT_0203d214 & 0xfffffffc) >> (DAT_0203d214 & 3) * 8 |
                  *(uint *)(DAT_0203d214 & 0xfffffffc) << (DAT_0203d214 & 3) * -8 + 0x20) + 0x3d0)
        != '\0') {
      do {
        iVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x14;
        uVar4 = iVar3 + uVar7 * 0x8c;
        uVar1 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        puVar6 = (undefined4 *)(iVar3 + uVar7 * 0x8c);
        if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
          iVar3 = func_020a100c(uVar7);
          if (iVar3 == 0) {
            *puVar6 = 2;
          }
          else {
            *puVar6 = 1;
          }
          *(ushort *)(puVar6 + 0xc) = *(ushort *)(puVar6 + 0xc) | 2;
        }
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < *(byte *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                                 *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x3d0))
      ;
      return;
    }
    return;
  }
  uVar7 = 0;
  if (*(char *)((*(uint *)(DAT_0203d214 & 0xfffffffc) >> (DAT_0203d214 & 3) * 8 |
                *(uint *)(DAT_0203d214 & 0xfffffffc) << (DAT_0203d214 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      iVar3 = func_020a1084(uVar7);
      if ((iVar3 != 0) &&
         (iVar3 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                  *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x14,
         uVar4 = iVar3 + uVar7 * 0x8c, uVar1 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
         puVar6 = (undefined4 *)(iVar3 + uVar7 * 0x8c),
         uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0)) {
        iVar3 = func_020a100c(uVar7);
        if (iVar3 == 0) {
          *puVar6 = 2;
        }
        else {
          *puVar6 = 1;
        }
        *(ushort *)(puVar6 + 0xc) = *(ushort *)(puVar6 + 0xc) | 2;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(byte *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x3d0));
  }
  iVar3 = func_0203ef58();
  if (iVar3 != 0) {
    uVar5 = (*(uint *)(DAT_0203d214 & 0xfffffffc) >> (DAT_0203d214 & 3) * 8 |
            *(uint *)(DAT_0203d214 & 0xfffffffc) << (DAT_0203d214 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    switch(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) {
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

