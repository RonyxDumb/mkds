/* Decompiled C draft; module arm9; ROM address 0203e788. No matching claim. */
#include "types.h"
#include "deps/0203e788_func_0203e788.h"

void func_0203e788(int param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  
  iVar7 = param_1 * 0x8c;
  iVar4 = (*(uint *)(DAT_0203e998 & 0xfffffffc) >> (DAT_0203e998 & 3) * 8 |
          *(uint *)(DAT_0203e998 & 0xfffffffc) << (DAT_0203e998 & 3) * -8 + 0x20) + 0x14;
  uVar3 = iVar4 + iVar7;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  bVar6 = false;
  if (((uVar3 == 1) || (uVar3 == 2)) || (uVar3 == 3)) {
    bVar6 = true;
  }
  if (bVar6) {
    return;
  }
  uVar2 = *(ushort *)(iVar4 + iVar7 + 0x30);
  if ((uVar2 & 0x10) != 0) {
    return;
  }
  if ((uVar2 & 0x20) == 0) {
    iVar4 = GetDriverEntry(param_1);
    uVar3 = *(uint *)(DAT_0203e998 & 0xfffffffc) >> (DAT_0203e998 & 3) * 8 |
            *(uint *)(DAT_0203e998 & 0xfffffffc) << (DAT_0203e998 & 3) * -8 + 0x20;
    *(undefined4 *)(uVar3 + 4) = 0;
    iVar7 = uVar3 + 0x14 + iVar7;
    MaybeConvertElapsedTime(&uStack_1a,(int)&uStack_1a + 1,&uStack_1c);
    *(undefined2 *)(iVar7 + 0x20) = uStack_1c;
    *(undefined2 *)(iVar7 + 0x22) = uStack_1a;
    uVar3 = DAT_0203e998;
    if ((*(ushort *)(iVar7 + 0x30) & 1) != 0) {
      *(int *)((*(uint *)(DAT_0203e998 & 0xfffffffc) >> (DAT_0203e998 & 3) * 8 |
               *(uint *)(DAT_0203e998 & 0xfffffffc) << (DAT_0203e998 & 3) * -8 + 0x20) + 0x4e0) =
           param_2;
      uVar1 = iVar4 + 0x7cU & 3;
      uVar5 = *(uint *)(iVar4 + 0x7cU & 0xfffffffc);
      *(uint *)(iVar4 + 0x7c) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20 | 0x20000000;
      uVar1 = iVar4 + 0x48U & 3;
      uVar5 = *(uint *)(iVar4 + 0x48U & 0xfffffffc);
      *(uint *)(iVar4 + 0x48) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xfdffffff;
      uVar1 = DAT_0203e99c;
      if (param_2 == 0) {
        *(ushort *)(iVar7 + 0x30) = *(ushort *)(iVar7 + 0x30) | 0x10;
        *(undefined2 *)
         ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x4fa) = 0;
        uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8;
        uVar1 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 4) {
          RaceModeBattle_OrMissionRun_SomeFn();
        }
      }
      else {
        *(ushort *)(iVar7 + 0x30) = *(ushort *)(iVar7 + 0x30) | 0x20;
        *(undefined2 *)
         ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x4fc) = 0;
        uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8;
        uVar1 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 4) {
          func_020a16d0(param_1);
        }
      }
    }
    NotifyDriverFinished((undefined4 *)(uintptr_t)(iVar7),param_2 == 0);
    iVar4 = func_0203ef58();
    if (iVar4 != 0) {
      uVar3 = (*(uint *)(DAT_0203e99c & 0xfffffffc) >> (DAT_0203e99c & 3) * 8 |
              *(uint *)(DAT_0203e99c & 0xfffffffc) << (DAT_0203e99c & 3) * -8 + 0x20) + 8;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      switch(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) {
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
  return;
}

