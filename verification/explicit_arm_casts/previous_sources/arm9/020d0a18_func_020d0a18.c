/* Decompiled C draft; module arm9; ROM address 020d0a18. No matching claim. */
#include "types.h"
#include "deps/020d0a18_func_020d0a18.h"

void func_020d0a18(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined2 auStack_22 [3];
  
  uVar1 = (*(uint *)(uRam020d0bb4 & 0xfffffffc) >> (uRam020d0bb4 & 3) * 8 |
          *(uint *)(uRam020d0bb4 & 0xfffffffc) << (uRam020d0bb4 & 3) * -8 + 0x20) + 8;
  uVar6 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20;
  if ((uVar1 != 0) && (uVar1 != 1)) {
    return;
  }
  uVar2 = GetCurrentPlayerRacerId();
  GetPlayerTotalTime(uVar2,&uStack_24,&uStack_23,auStack_22);
  func_020ae7c4(uStack_24,uStack_23,auStack_22[0],
                *(uint *)(uRam020d0bb8 & 0xfffffffc) >> (uRam020d0bb8 & 3) * 8 |
                *(uint *)(uRam020d0bb8 & 0xfffffffc) << (uRam020d0bb8 & 3) * -8 + 0x20);
  uVar1 = 0;
  iVar3 = GetCurrentLapCount();
  uVar6 = uRam020d0bb8;
  if (iVar3 != 0) {
    do {
      uVar2 = GetCurrentPlayerRacerId();
      MaybeGetPlayerLapTime(uVar2,uVar1 + 1 & 0xffff,&uStack_24,&uStack_23);
      uVar4 = uVar6 & 3;
      uVar5 = *(uint *)(uVar6 & 0xfffffffc);
      func_020ae7c4(uStack_24,uStack_23,auStack_22[0],
                    uVar1 * 0x1c + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x1c);
      uVar1 = uVar1 + 1 & 0xffff;
      uVar4 = GetCurrentLapCount();
    } while (uVar1 < uVar4);
  }
  uVar1 = (*(uint *)(uRam020d0bb4 & 0xfffffffc) >> (uRam020d0bb4 & 3) * 8 |
          *(uint *)(uRam020d0bb4 & 0xfffffffc) << (uRam020d0bb4 & 3) * -8 + 0x20) + 8;
  uVar6 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) != 1) {
    return;
  }
  iVar3 = func_020c7148();
  if ((iVar3 == 0) && (iVar3 = GetLastTimeTrialWasRecord(), iVar3 == 0)) {
    return;
  }
  uVar4 = uRam020d0bb8;
  uVar5 = *(uint *)(uRam020d0bb8 & 0xfffffffc) >> (uRam020d0bb8 & 3) * 8 |
          *(uint *)(uRam020d0bb8 & 0xfffffffc) << (uRam020d0bb8 & 3) * -8 + 0x20;
  uVar1 = uVar5 + 0xa8;
  uVar6 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(uVar5 + 0xa8) = (uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) + 1;
  uVar1 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 + 0xa8;
  uVar6 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (0xf < (int)(uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20)) {
    *(undefined4 *)(uVar4 + 0xa8) = 0;
  }
  uVar4 = *(uint *)(uRam020d0bb8 & 0xfffffffc) >> (uRam020d0bb8 & 3) * 8 |
          *(uint *)(uRam020d0bb8 & 0xfffffffc) << (uRam020d0bb8 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 0xa8 & 3;
  uVar6 = *(uint *)(uVar4 + 0xa8 & 0xfffffffc);
  uVar1 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  iVar3 = (int)uVar1 >> 0x1f;
  iVar3 = (uVar1 * 0x10000000 + iVar3 >> 0x1c | iVar3 << 4) - iVar3;
  if (3 < iVar3) {
    if (7 < iVar3) {
      if (iVar3 < 0xc) {
        *(undefined4 *)(uVar4 + 0xac) = 0x1a;
      }
      else {
        *(undefined4 *)(uVar4 + 0xac) = 0xd;
      }
      return;
    }
    *(undefined4 *)(uVar4 + 0xac) = 0xd;
    return;
  }
  *(undefined4 *)(uVar4 + 0xac) = 0;
  return;
}

