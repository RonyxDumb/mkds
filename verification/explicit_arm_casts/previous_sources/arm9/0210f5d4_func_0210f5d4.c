/* Decompiled C draft; module arm9; ROM address 0210f5d4. No matching claim. */
#include "types.h"
#include "deps/0210f5d4_func_0210f5d4.h"

void func_0210f5d4(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  
  iVar7 = DAT_0210f6fc;
  iVar6 = DAT_0210f6fc;
  switch(param_1) {
  case 0x1c:
    iVar6 = 1;
    break;
  case 0x1d:
    iVar6 = 0;
    break;
  case 0x1e:
    break;
  case 0x1f:
    break;
  case 0x20:
    iVar6 = 2;
    break;
  case 0x21:
    iVar6 = 3;
    break;
  case 0x22:
    iVar6 = 4;
  }
  *DAT_0210f700 = iVar6;
  if (iVar6 != iVar7) {
    iVar9 = 0;
    func_0210f208(DAT_0210f704,3,0);
    func_0210f208(DAT_0210f708,3,0);
    iVar7 = DAT_0210f70c + iVar6 * 0x10;
    puVar8 = DAT_0210f704;
    do {
      if (iVar9 == 0) {
        sVar3 = 0x1000;
      }
      else {
        sVar3 = 0x2000;
      }
      iVar5 = 0;
      do {
        if (sVar3 == *(short *)(iVar5 * 2 + iVar7)) {
          func_0210f208(puVar8,0);
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      iVar9 = iVar9 + 1;
      puVar8 = puVar8 + 4;
    } while (iVar9 < 2);
  }
  puVar8 = DAT_0210f704;
  uVar4 = 0;
  if ((iVar6 == 1) &&
     (uVar2 = (*(uint *)(DAT_0210f710 & 0xfffffffc) >> (DAT_0210f710 & 3) * 8 |
              *(uint *)(DAT_0210f710 & 0xfffffffc) << (DAT_0210f710 & 3) * -8 + 0x20) + 8,
     uVar1 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
     (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 4)) {
    uVar4 = 3;
  }
  DAT_0210f704[1] = uVar4;
  *puVar8 = uVar4;
  return;
}

