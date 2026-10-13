/* Decompiled C draft; module arm9; ROM address 020bbbb4. No matching claim. */
#include "types.h"
#include "deps/020bbbb4_MaybeWhenFewSecondsRemaining.h"

void MaybeWhenFewSecondsRemaining(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cStack_c;
  byte bStack_b;
  short sStack_a;
  
  iVar2 = func_020b1dbc();
  if (iVar2 == 6) {
    return;
  }
  iVar2 = func_020b1a20();
  if (iVar2 == 0) {
    uVar6 = (*(uint *)(uRam020bc0f4 & 0xfffffffc) >> (uRam020bc0f4 & 3) * 8 |
            *(uint *)(uRam020bc0f4 & 0xfffffffc) << (uRam020bc0f4 & 3) * -8 + 0x20) + 8;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) != 2) {
      GetCurrentPlayerRacerId();
      iVar2 = IsRacerFinishedRace();
      if (iVar2 != 0) {
        uVar3 = GetCurrentPlayerRacerId();
        GetPlayerTotalTime(uVar3,&cStack_c,&bStack_b,&sStack_a);
        goto LAB_020bbc54;
      }
    }
    GetSomeMVTime(&cStack_c,&bStack_b,&sStack_a);
  }
  else {
    uVar3 = GetCurrentPlayerRacerId();
    uVar4 = GetSomeLapCount();
    MaybeGetPlayerLapTime(uVar3,uVar4,&cStack_c,&bStack_b);
  }
LAB_020bbc54:
  func_020ae7c4(cStack_c,bStack_b,sStack_a,
                (undefined4 *)(uintptr_t)(*(uint *)(uRam020bc0f8 & 0xfffffffc) >> (uRam020bc0f8 & 3) * 8 |
                *(uint *)(uRam020bc0f8 & 0xfffffffc) << (uRam020bc0f8 & 3) * -8 + 0x20));
  uVar8 = uRam020bc0f8;
  uVar7 = *(uint *)(uRam020bc0f8 & 0xfffffffc) >> (uRam020bc0f8 & 3) * 8 |
          *(uint *)(uRam020bc0f8 & 0xfffffffc) << (uRam020bc0f8 & 3) * -8 + 0x20;
  uVar6 = uVar7 + 0x1c & 3;
  uVar5 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
  if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
    return;
  }
  if ((cStack_c == '\0') && (6 < bStack_b)) {
    iVar2 = 0;
    do {
      uVar6 = uVar8 & 3;
      uVar5 = *(uint *)(uVar8 & 0xfffffffc);
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + iVar1 + 0x20) = 0;
    } while (iVar2 < 6);
    return;
  }
  if (((cStack_c == '\0') && (((bStack_b == 5 && (sStack_a == 0)) || (bStack_b < 5)))) &&
     (uVar6 = uVar7 + 0x20 & 3, uVar8 = *(uint *)(uVar7 + 0x20 & 0xfffffffc),
     uVar8 >> uVar6 * 8 == 0 && uVar8 << uVar6 * -8 + 0x20 == 0)) {
    iVar2 = GetCurrentPlayerRacerId();
    uVar6 = iVar2 * 0x8c +
            (*(uint *)(uRam020bc0fc & 0xfffffffc) >> (uRam020bc0fc & 3) * 8 |
            *(uint *)(uRam020bc0fc & 0xfffffffc) << (uRam020bc0fc & 3) * -8 + 0x20) + 0x14;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) != 2) {
      func_02089ef4(2);
    }
    if (((*(uint *)(uRam020bc100 & 0xfffffffc) >> (uRam020bc100 & 3) * 8 |
         *(uint *)(uRam020bc100 & 0xfffffffc) << (uRam020bc100 & 3) * -8 + 0x20) & 1) != 0) {
      func_02108ea0(0);
      uVar8 = GetSomeSndPlayer();
      uVar6 = iRam020bc104 + 0xcU & 3;
      uVar5 = *(uint *)(iRam020bc104 + 0xcU & 0xfffffffc);
      if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar8,0,0x49);
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020bc0f8 & 0xfffffffc) >> (uRam020bc0f8 & 3) * 8 |
      *(uint *)(uRam020bc0f8 & 0xfffffffc) << (uRam020bc0f8 & 3) * -8 + 0x20) + 0x20) = 1;
    return;
  }
  if (((cStack_c == '\0') && (((bStack_b == 4 && (sStack_a == 0)) || (bStack_b < 4)))) &&
     (uVar6 = uVar7 + 0x24 & 3, uVar8 = *(uint *)(uVar7 + 0x24 & 0xfffffffc),
     uVar8 >> uVar6 * 8 == 0 && uVar8 << uVar6 * -8 + 0x20 == 0)) {
    if (((*(uint *)(uRam020bc100 & 0xfffffffc) >> (uRam020bc100 & 3) * 8 |
         *(uint *)(uRam020bc100 & 0xfffffffc) << (uRam020bc100 & 3) * -8 + 0x20) & 1) != 0) {
      func_02108ea0(0);
      uVar8 = GetSomeSndPlayer();
      uVar6 = iRam020bc104 + 0xcU & 3;
      uVar5 = *(uint *)(iRam020bc104 + 0xcU & 0xfffffffc);
      if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar8,0,0x49);
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020bc0f8 & 0xfffffffc) >> (uRam020bc0f8 & 3) * 8 |
      *(uint *)(uRam020bc0f8 & 0xfffffffc) << (uRam020bc0f8 & 3) * -8 + 0x20) + 0x24) = 1;
    return;
  }
  if (((cStack_c == '\0') && (((bStack_b == 3 && (sStack_a == 0)) || (bStack_b < 3)))) &&
     (uVar6 = uVar7 + 0x28 & 3, uVar8 = *(uint *)(uVar7 + 0x28 & 0xfffffffc),
     uVar8 >> uVar6 * 8 == 0 && uVar8 << uVar6 * -8 + 0x20 == 0)) {
    if (((*(uint *)(uRam020bc100 & 0xfffffffc) >> (uRam020bc100 & 3) * 8 |
         *(uint *)(uRam020bc100 & 0xfffffffc) << (uRam020bc100 & 3) * -8 + 0x20) & 1) != 0) {
      func_02108ea0(0);
      uVar8 = GetSomeSndPlayer();
      uVar6 = iRam020bc104 + 0xcU & 3;
      uVar5 = *(uint *)(iRam020bc104 + 0xcU & 0xfffffffc);
      if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar8,0,0x49);
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020bc0f8 & 0xfffffffc) >> (uRam020bc0f8 & 3) * 8 |
      *(uint *)(uRam020bc0f8 & 0xfffffffc) << (uRam020bc0f8 & 3) * -8 + 0x20) + 0x28) = 1;
    return;
  }
  if ((cStack_c == '\0') &&
     ((((bStack_b == 2 && (sStack_a == 0)) || (bStack_b < 2)) &&
      (uVar6 = uVar7 + 0x2c & 3, uVar8 = *(uint *)(uVar7 + 0x2c & 0xfffffffc),
      uVar8 >> uVar6 * 8 == 0 && uVar8 << uVar6 * -8 + 0x20 == 0)))) {
    if (((*(uint *)(uRam020bc100 & 0xfffffffc) >> (uRam020bc100 & 3) * 8 |
         *(uint *)(uRam020bc100 & 0xfffffffc) << (uRam020bc100 & 3) * -8 + 0x20) & 1) != 0) {
      func_02108ea0(0);
      uVar8 = GetSomeSndPlayer();
      uVar6 = iRam020bc104 + 0xcU & 3;
      uVar5 = *(uint *)(iRam020bc104 + 0xcU & 0xfffffffc);
      if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar8,0,0x49);
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020bc0f8 & 0xfffffffc) >> (uRam020bc0f8 & 3) * 8 |
      *(uint *)(uRam020bc0f8 & 0xfffffffc) << (uRam020bc0f8 & 3) * -8 + 0x20) + 0x2c) = 1;
    return;
  }
  if (((cStack_c == '\0') && (((bStack_b == 1 && (sStack_a == 0)) || (bStack_b == 0)))) &&
     (uVar6 = uVar7 + 0x30 & 3, uVar8 = *(uint *)(uVar7 + 0x30 & 0xfffffffc),
     uVar8 >> uVar6 * 8 == 0 && uVar8 << uVar6 * -8 + 0x20 == 0)) {
    if (((*(uint *)(uRam020bc100 & 0xfffffffc) >> (uRam020bc100 & 3) * 8 |
         *(uint *)(uRam020bc100 & 0xfffffffc) << (uRam020bc100 & 3) * -8 + 0x20) & 1) != 0) {
      func_02108ea0(0);
      uVar8 = GetSomeSndPlayer();
      uVar6 = iRam020bc104 + 0xcU & 3;
      uVar5 = *(uint *)(iRam020bc104 + 0xcU & 0xfffffffc);
      if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar8,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar8,0,0x49);
      }
    }
    *(undefined4 *)
     ((*(uint *)(uRam020bc0f8 & 0xfffffffc) >> (uRam020bc0f8 & 3) * 8 |
      *(uint *)(uRam020bc0f8 & 0xfffffffc) << (uRam020bc0f8 & 3) * -8 + 0x20) + 0x30) = 1;
    return;
  }
  if (cStack_c != '\0') {
    return;
  }
  if (bStack_b == 0) {
    if (sStack_a == 0) {
      uVar6 = uVar7 + 0x34 & 3;
      uVar8 = *(uint *)(uVar7 + 0x34 & 0xfffffffc);
      if (uVar8 >> uVar6 * 8 == 0 && uVar8 << uVar6 * -8 + 0x20 == 0) {
        *(undefined4 *)(uVar7 + 0x34) = 1;
      }
      return;
    }
    return;
  }
  return;
}

