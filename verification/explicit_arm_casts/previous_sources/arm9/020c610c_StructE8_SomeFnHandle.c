/* Decompiled C draft; module arm9; ROM address 020c610c. No matching claim. */
#include "types.h"
#include "deps/020c610c_StructE8_SomeFnHandle.h"

void StructE8_SomeFnHandle(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar7;
  undefined4 uVar8;
  bool bVar9;
  byte bStack_28;
  byte bStack_27;
  char cStack_26;
  char cStack_25;
  ushort uStack_24;
  short sStack_22;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [2];
  undefined1 uStack_1a;
  undefined1 auStack_19 [5];
  uint uVar6;
  
  uVar2 = (*(uint *)(uRam020c6408 & 0xfffffffc) >> (uRam020c6408 & 3) * 8 |
          *(uint *)(uRam020c6408 & 0xfffffffc) << (uRam020c6408 & 3) * -8 + 0x20) + 0x4cc;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0) {
    return;
  }
  iVar3 = func_020b1a20();
  if (iVar3 != 0) {
    return;
  }
  uVar2 = (*(uint *)(uRam020c640c & 0xfffffffc) >> (uRam020c640c & 3) * 8 |
          *(uint *)(uRam020c640c & 0xfffffffc) << (uRam020c640c & 3) * -8 + 0x20) + 0xc;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0) {
    uVar4 = CheckHandleSaveTimeTrialRecord2(1);
    *(undefined4 *)
     ((*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
      *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) + 8) = uVar4;
    uVar4 = CheckHandleSaveTimeTrialRecord_LeastLap(1);
    uVar5 = uRam020c6410;
    *(undefined4 *)
     ((*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
      *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) + 0x10) = uVar4;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    uVar2 = uVar6 + 8 & 3;
    uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    if ((uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) &&
       (uVar2 = uVar6 + 0x10 & 3, uVar5 = *(uint *)(uVar6 + 0x10 & 0xfffffffc),
       uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0)) {
      bVar9 = false;
      iVar3 = func_020ba620();
      if (iVar3 != 0) {
        uVar6 = *(uint *)(uRam020c640c & 0xfffffffc) >> (uRam020c640c & 3) * 8 |
                *(uint *)(uRam020c640c & 0xfffffffc) << (uRam020c640c & 3) * -8 + 0x20;
        uVar2 = uVar6 + 8 & 3;
        uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc);
        if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 1) &&
           (*(char *)(uVar6 + 0x3e6) == '\x01')) {
          Mem_CpuCopy8(uVar6 + iRam020c6418,auStack_20,4);
          bVar9 = true;
        }
        else {
          bVar9 = false;
        }
        if (bVar9) {
          GetPlayerTotalTime((short)*(char *)((*(uint *)(uRam020c640c & 0xfffffffc) >>
                                               (uRam020c640c & 3) * 8 |
                                              *(uint *)(uRam020c640c & 0xfffffffc) <<
                                              (uRam020c640c & 3) * -8 + 0x20) + 0x62),&uStack_1a,
                             auStack_19,auStack_1c);
          iVar3 = StructRCTime_SmallerThan_from_thumb(auStack_1c,auStack_20);
          bVar9 = iVar3 != 0;
        }
        else {
          bVar9 = true;
        }
      }
      uVar5 = uRam020c6410;
      uVar2 = uRam020c640c;
      if (bVar9) {
        *(undefined4 *)
         ((*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
          *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) + 0x18) = 1;
        uVar5 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
        FillPersonalGhostData_from_thumb
                  (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,
                   (short)*(char *)(uVar2 + 0x62));
        uVar5 = uRam020c6410;
        *(undefined4 *)
         (*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
         *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) = uRam020c641c;
        uVar2 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        *(undefined4 *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 4) = 0;
      }
      else {
        *(undefined4 *)
         (*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
         *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) = uRam020c6420;
        uVar2 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        *(undefined4 *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 4) = 0;
      }
    }
    else {
      *(undefined4 *)(uVar6 + 0x18) = 1;
      WriteTimeTrialsSaveDataSection_from_thumb();
      uVar5 = uRam020c6410;
      *(undefined4 *)
       (*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
       *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) = uRam020c6414;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(undefined4 *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 4) = 0;
    }
  }
  else {
    uVar4 = GetCurrentPlayerRacerId();
    GetPlayerTotalTime(uVar4,&bStack_28,&bStack_27,&uStack_24);
    uVar2 = uRam020c6410;
    uVar5 = *(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
            *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20;
    puVar7 = (ushort *)(uVar5 + 0x9c);
    iVar3 = 4;
    do {
      if (((char)puVar7[0xc] != '\0') &&
         ((uint)uStack_24 + (uint)bStack_27 * 1000 + (uint)bStack_28 * iRam020c6424 ==
          (uint)*puVar7 +
          (uint)*(byte *)((int)puVar7 + 3) * 1000 + (uint)(byte)puVar7[1] * iRam020c6424)) {
        uVar4 = 1;
        goto LAB_020c6360;
      }
      puVar7 = puVar7 + -0x10;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
    uVar4 = 0;
LAB_020c6360:
    *(undefined4 *)(uVar5 + 8) = uVar4;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar4 = GetCurrentPlayerRacerId();
    uVar1 = GetLeastTimeLap(uVar4,&cStack_26,&cStack_25,&sStack_22);
    *(undefined2 *)
     ((*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
      *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) + 0x14) = uVar1;
    uVar4 = uRam020c6420;
    uVar2 = uRam020c6410;
    if (((cStack_26 == *(char *)(uVar5 + 0xbe)) && (cStack_25 == *(char *)(uVar5 + 0xbf))) &&
       (sStack_22 == *(short *)(uVar5 + 0xbc))) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    *(undefined4 *)
     ((*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
      *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) + 0x10) = uVar8;
    *(undefined4 *)
     (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = uVar4;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 4) = 0;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020c6410 & 0xfffffffc) >> (uRam020c6410 & 3) * 8 |
    *(uint *)(uRam020c6410 & 0xfffffffc) << (uRam020c6410 & 3) * -8 + 0x20) + 0xdc) = 1;
  return;
}

