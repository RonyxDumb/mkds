/* Decompiled C draft; module arm9; ROM address 020c5f7c. No matching claim. */
#include "types.h"
#include "deps/020c5f7c_StructE8_SomeFnHandle4.h"

void StructE8_SomeFnHandle4(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [2];
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  if (*(char *)((*(uint *)(uRam020c60f0 & 0xfffffffc) >> (uRam020c60f0 & 3) * 8 |
                *(uint *)(uRam020c60f0 & 0xfffffffc) << (uRam020c60f0 & 3) * -8 + 0x20) + 0x28) ==
      '\0') {
    uVar4 = *(uint *)(uRam020c60f4 & 0xfffffffc) >> (uRam020c60f4 & 3) * 8 |
            *(uint *)(uRam020c60f4 & 0xfffffffc) << (uRam020c60f4 & 3) * -8 + 0x20;
    uVar2 = uVar4 + 0xc;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0) {
      uVar2 = 0;
    }
    else {
      uVar4 = uVar4 + 0x10;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    }
  }
  else {
    uVar2 = 1;
  }
  if (uVar2 != 0) {
    return;
  }
  bVar6 = false;
  iVar3 = func_020ba620();
  if (iVar3 != 0) {
    uVar5 = *(uint *)(uRam020c60f8 & 0xfffffffc) >> (uRam020c60f8 & 3) * 8 |
            *(uint *)(uRam020c60f8 & 0xfffffffc) << (uRam020c60f8 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 8 & 3;
    uVar4 = *(uint *)(uVar5 + 8 & 0xfffffffc);
    if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == 1) &&
       (*(char *)(uVar5 + 0x3e6) == '\x01')) {
      Mem_CpuCopy8(uVar5 + iRam020c60fc,auStack_10,4);
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
    if (bVar6) {
      GetPlayerTotalTime((short)*(char *)((*(uint *)(uRam020c60f8 & 0xfffffffc) >>
                                           (uRam020c60f8 & 3) * 8 |
                                          *(uint *)(uRam020c60f8 & 0xfffffffc) <<
                                          (uRam020c60f8 & 3) * -8 + 0x20) + 0x62),&uStack_a,
                         &uStack_9,auStack_c);
      iVar3 = StructRCTime_SmallerThan_from_thumb(auStack_c,auStack_10);
      bVar6 = iVar3 != 0;
    }
    else {
      bVar6 = true;
    }
  }
  uVar1 = uRam020c6108;
  uVar4 = uRam020c6100;
  uVar2 = uRam020c60f8;
  if (bVar6) {
    *(undefined4 *)
     ((*(uint *)(uRam020c6100 & 0xfffffffc) >> (uRam020c6100 & 3) * 8 |
      *(uint *)(uRam020c6100 & 0xfffffffc) << (uRam020c6100 & 3) * -8 + 0x20) + 0x18) = 1;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    FillPersonalGhostData_from_thumb
              (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
               *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,
               (short)*(char *)(uVar2 + 0x62));
    uVar4 = uRam020c6100;
    *(undefined4 *)
     (*(uint *)(uRam020c6100 & 0xfffffffc) >> (uRam020c6100 & 3) * 8 |
     *(uint *)(uRam020c6100 & 0xfffffffc) << (uRam020c6100 & 3) * -8 + 0x20) = uRam020c6104;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(undefined4 *)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 4) = 0;
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020c6100 & 0xfffffffc) >> (uRam020c6100 & 3) * 8 |
    *(uint *)(uRam020c6100 & 0xfffffffc) << (uRam020c6100 & 3) * -8 + 0x20) + 0x18) = 0;
  *(undefined4 *)
   (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
   *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) = uVar1;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 4) = 0;
  return;
}

