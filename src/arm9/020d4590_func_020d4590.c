/* Decompiled C draft; module arm9; ROM address 020d4590. No matching claim. */
#include "types.h"
#include "deps/020d4590_func_020d4590.h"

void func_020d4590(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  code *pcVar5;
  
  uVar2 = *(uint *)(uRam020d468c & 0xfffffffc) >> (uRam020d468c & 3) * 8 |
          *(uint *)(uRam020d468c & 0xfffffffc) << (uRam020d468c & 3) * -8 + 0x20;
  uVar6 = (uint)*(ushort *)(uVar2 + 0x174);
  iVar1 = GetRaceStartCountdown();
  if ((iVar1 < 0x169) &&
     (uVar3 = (*(uint *)(uRam020d4690 & 0xfffffffc) >> (uRam020d4690 & 3) * 8 |
              *(uint *)(uRam020d4690 & 0xfffffffc) << (uRam020d4690 & 3) * -8 + 0x20) + 0xc,
     uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
     (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != 3)) {
    if (iVar1 == -0x73) {
      func_020d3b74();
    }
    else if (iVar1 == 0x168) {
      func_020d3b10();
    }
  }
  uVar3 = (*(uint *)(uRam020d468c & 0xfffffffc) >> (uRam020d468c & 3) * 8 |
          *(uint *)(uRam020d468c & 0xfffffffc) << (uRam020d468c & 3) * -8 + 0x20) + 0x2b8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) && (iVar1 = 0, uVar6 != 0)) {
    do {
      uVar3 = uVar2 + 0x134 + iVar1 * 4;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar7 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar3 = uVar7 + 0xc & 3;
      uVar4 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      pcVar5 = (code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(uVar7);
      }
      func_020e705c(uVar7);
      uVar3 = uVar7 + 0x14 & 3;
      uVar4 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
      pcVar5 = (code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(uVar7);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)uVar6);
  }
  iVar1 = func_020d50b4();
  if (iVar1 == 0) {
    func_020d47e0();
  }
  else {
    func_020d4698();
  }
  if (*(uint *)(uRam020d4694 & 0xfffffffc) >> (uRam020d4694 & 3) * 8 != 0 ||
      *(uint *)(uRam020d4694 & 0xfffffffc) << (uRam020d4694 & 3) * -8 + 0x20 != 0) {
    func_020d9f8c();
    return;
  }
  return;
}

