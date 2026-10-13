/* Decompiled C draft; module arm9; ROM address 020e84b0. No matching claim. */
#include "types.h"
#include "deps/020e84b0_E7Fn2_3.h"

void E7Fn2_3(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar5;
  
  uVar7 = uRam020e8768;
  uVar6 = uRam020e8764;
  piVar1 = piRam020e874c;
  uVar4 = uRam020e8744;
  uVar8 = *(uint *)((uint)piRam020e873c & 0xfffffffc) >> ((uint)piRam020e873c & 3) * 8 |
          *(uint *)((uint)piRam020e873c & 0xfffffffc) << ((uint)piRam020e873c & 3) * -8 + 0x20;
  uVar3 = iRam020e8740 +
          (*(uint *)(uRam020e8738 & 0xfffffffc) >> (uRam020e8738 & 3) * 8 |
          *(uint *)(uRam020e8738 & 0xfffffffc) << (uRam020e8738 & 3) * -8 + 0x20) * 0x10;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0xc;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) << 4) >> 0x10;
  if (((int)uVar8 < 1) || (0xffff < (int)uVar8)) {
    *puRam020e8760 = 0;
    func_020ea1d4(uVar4,uVar6,uVar7);
    if ((*(uint *)(uRam020e876c & 0xfffffffc) >> (uRam020e876c & 3) * 8 == 0 &&
         *(uint *)(uRam020e876c & 0xfffffffc) << (uRam020e876c & 3) * -8 + 0x20 == 0) &&
       (*(uint *)(uRam020e8770 & 0xfffffffc) >> (uRam020e8770 & 3) * 8 == 0 &&
        *(uint *)(uRam020e8770 & 0xfffffffc) << (uRam020e8770 & 3) * -8 + 0x20 == 0)) {
      StateDualHandler_SetState(uRam020e8774,1);
    }
  }
  else {
    uVar12 = *(uint *)(uRam020e8744 & 0xfffffffc) >> (uRam020e8744 & 3) * 8 |
             *(uint *)(uRam020e8744 & 0xfffffffc) << (uRam020e8744 & 3) * -8 + 0x20;
    uVar9 = (uint)*(short *)(iRam020e8748 + (((int)uVar8 >> 4) * 2 + 1) * 2);
    uVar8 = (uint)*(short *)(iRam020e8748 + ((int)uVar8 >> 4) * 4);
    uVar5 = uRam020e8744 + 8 & 3;
    uVar4 = *(uint *)(uRam020e8744 + 8 & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    iVar10 = (int)((ulonglong)((longlong)(int)uVar12 * (longlong)(int)uVar8) >> 0x20);
    iVar13 = ((uint)((longlong)(int)uVar5 * (longlong)(int)uVar9) >> 0xc |
             (int)((ulonglong)((longlong)(int)uVar5 * (longlong)(int)uVar9) >> 0x20) << 0x14) -
             ((uint)((longlong)(int)uVar12 * (longlong)(int)uVar8) >> 0xc | iVar10 << 0x14);
    if (0 < iVar13) {
      iVar10 = iVar13 * 3;
    }
    piRam020e874c[2] = iVar13;
    if (0 < iVar13) {
      piVar1[2] = iVar10;
    }
    uVar6 = uRam020e8750;
    piVar1 = piRam020e874c;
    uVar4 = uRam020e8744 + 4 & 3;
    uVar11 = *(uint *)(uRam020e8744 + 4 & 0xfffffffc);
    *piRam020e874c =
         ((uint)((ulonglong)uVar8 * (ulonglong)uVar5) >> 0xc |
         (((int)uVar5 >> 0x1f) * uVar8 +
         uVar5 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)uVar8 * (ulonglong)uVar5 >> 0x20)) *
         0x100000) +
         ((uint)((ulonglong)uVar9 * (ulonglong)uVar12) >> 0xc |
         (((int)uVar12 >> 0x1f) * uVar9 +
         uVar12 * ((int)uVar9 >> 0x1f) + (int)((ulonglong)uVar9 * (ulonglong)uVar12 >> 0x20)) *
         0x100000);
    piVar1[1] = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
    func_02147288((uint)(uintptr_t)(piVar1),uVar6,piVar1);
    if (*(uint *)(uRam020e8754 & 0xfffffffc) >> (uRam020e8754 & 3) * 8 == 0 &&
        *(uint *)(uRam020e8754 & 0xfffffffc) << (uRam020e8754 & 3) * -8 + 0x20 == 0) {
      *piRam020e873c =
           (*(uint *)((uint)piRam020e873c & 0xfffffffc) >> ((uint)piRam020e873c & 3) * 8 |
           *(uint *)((uint)piRam020e873c & 0xfffffffc) << ((uint)piRam020e873c & 3) * -8 + 0x20) +
           0xf0;
    }
    else {
      *piRam020e873c =
           (*(uint *)((uint)piRam020e873c & 0xfffffffc) >> ((uint)piRam020e873c & 3) * 8 |
           *(uint *)((uint)piRam020e873c & 0xfffffffc) << ((uint)piRam020e873c & 3) * -8 + 0x20) -
           0xf0;
    }
    puVar2 = puRam020e8760;
    *puRam020e875c =
         *(uint *)(uRam020e8758 & 0xfffffffc) >> (uRam020e8758 & 3) * 8 |
         *(uint *)(uRam020e8758 & 0xfffffffc) << (uRam020e8758 & 3) * -8 + 0x20;
    *puVar2 = 1;
  }
  if ((uVar3 == 10) || (uVar3 == 0x28)) {
    uVar6 = func_02108e6c(4);
    uVar7 = func_020d4ef4(uRam020e8778);
    *(undefined4 *)(iRam020e877c + 0xc) = uVar7;
    func_0212c6f0(uVar6,0);
    func_0210b760(iRam020e877c,uVar6);
  }
  iVar10 = IsRacerFinishedRace(*puRam020e8780);
  if ((iVar10 != 0) ||
     (uVar5 = *(uint *)(uRam020e8784 & 0xfffffffc) >> (uRam020e8784 & 3) * 8 |
              *(uint *)(uRam020e8784 & 0xfffffffc) << (uRam020e8784 & 3) * -8 + 0x20,
     uVar3 = uVar5 + 0x48, uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
     ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x800) != 0)) {
    StateDualHandler_SetState(uRam020e8774,5);
    return;
  }
  if ((*(ushort *)
        ((uint)*puRam020e8780 * 0x8c +
         (*(uint *)(uRam020e8788 & 0xfffffffc) >> (uRam020e8788 & 3) * 8 |
         *(uint *)(uRam020e8788 & 0xfffffffc) << (uRam020e8788 & 3) * -8 + 0x20) + 0x44) & 4) == 0)
  {
    iVar10 = (*(uint *)((uint)piRam020e878c & 0xfffffffc) >> ((uint)piRam020e878c & 3) * 8 |
             *(uint *)((uint)piRam020e878c & 0xfffffffc) << ((uint)piRam020e878c & 3) * -8 + 0x20) +
             1;
    *piRam020e878c = iVar10;
    if (0x3c < iVar10) {
      StateDualHandler_SetState(uRam020e8774,5);
      return;
    }
  }
  else {
    *piRam020e878c = 0;
  }
  uVar5 = uVar5 + 0x48;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 1) == 0) {
    return;
  }
  StateDualHandler_SetState(uRam020e8774,5);
  return;
}

