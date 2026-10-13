/* Decompiled C draft; module arm9; ROM address 020072c0. No matching claim. */
#include "types.h"
#include "deps/020072c0_func_020072c0.h"

undefined4 func_020072c0(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined1 extraout_r1;
  byte bVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  uint uVar9;
  undefined1 local_30 [2];
  ushort local_2e;
  undefined2 local_2c;
  undefined1 auStack_28 [4];
  int local_24;
  int local_20;
  byte local_1c;
  
  iVar5 = iRam0200744c;
  piVar8 = piRam02007444;
  if (*(char *)(*piRam02007444 + iRam02007448) == '\0') {
    return 0x15;
  }
  bVar3 = 0;
  do {
    iVar6 = *piVar8;
    _s32_div_f(*(byte *)(iVar6 + iVar5) + 1,0x10);
    *(undefined1 *)(iVar6 + iVar5) = extraout_r1;
    iVar6 = *piVar8;
    iVar6 = iVar6 + iRam02007450 * (uint)*(byte *)(iVar6 + iVar5);
    if (*(char *)(iVar6 + iRam02007454) != '\0') {
      if (*(short *)(iVar6 + iRam02007458) != 0) break;
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x10);
  if (bVar3 == 0x10) {
    return 0x15;
  }
  func_02007154();
  iVar6 = *piRam02007444;
  iVar5 = iRam02007450 * (uint)*(byte *)(iVar6 + iRam0200744c);
  iVar5 = func_0200806c(auStack_28,iVar6 + iRam0200745c + iVar5,
                        *(undefined2 *)(iVar6 + iVar5 + iRam02007460),iVar6 + iRam02007464 + iVar5);
  if (iVar5 == 0) {
    return 0x15;
  }
  local_30[0] = 4;
  pbVar1 = (byte *)(*piRam02007444 + iRam0200744c);
  local_2e = (ushort)*pbVar1;
  local_2c = *(undefined2 *)(*piRam02007444 + iRam02007450 * (uint)*pbVar1 + iRam02007460);
  uVar2 = func_0200c3a4(local_30);
  iVar5 = *piRam02007444 + iRam02007450 * (uint)*(byte *)(*piRam02007444 + iRam0200744c);
  uVar9 = (local_20 - *(int *)(iVar5 + (uint)local_1c * 4 + iRam0200745c)) +
          *(int *)(*(int *)(iVar5 + iRam02007468) + (uint)local_1c * 4);
  piVar8 = *(int **)(iVar5 + iRam0200746c);
  iVar5 = func_0200adfc(piVar8,uVar9,uVar2,local_24);
  if (iVar5 != 0) {
    uVar2 = func_02008908(local_24 + 6,
                          *(undefined2 *)
                           (*piRam02007444 +
                            iRam02007450 * (uint)*(byte *)(*piRam02007444 + iRam0200744c) +
                           iRam02007458));
    return uVar2;
  }
  iVar6 = *piRam02007444 + iRam02007470;
  iVar5 = func_0200aff8(iVar6);
  if ((iVar5 == 0) && (*piVar8 != 0)) {
    puVar4 = (uint *)(piVar8 + 0xc);
    puVar7 = (uint *)0x0;
    iVar5 = 0;
    do {
      if (puVar4[3] == 2) {
        if (puVar7 != (uint *)0x0) {
          if (*puVar7 <= *puVar4) goto LAB_020073ea;
        }
        puVar7 = puVar4;
      }
LAB_020073ea:
      puVar4 = puVar4 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    if (puVar7 == (uint *)0x0) {
      Os_Terminate();
    }
    *piVar8 = 0;
    puVar7[3] = 1;
    *puVar7 = uVar9 & 0xffffffe0;
    *(uint **)(iVar6 + 0x10) = puVar7;
    *(int **)(iVar6 + 0x14) = piVar8;
    StructANN_SomeFn_from_thumb(iVar6,uRam02007474,0,4);
  }
  return 0x15;
}

