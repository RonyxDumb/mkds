/* Decompiled C draft; module arm9; ROM address 0207f554. No matching claim. */
#include "types.h"
#include "deps/0207f554_func_0207f554.h"

undefined4 func_0207f554(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar7 = *(uint *)(uRam0207f5f8 & 0xfffffffc) >> (uRam0207f5f8 & 3) * 8 |
          *(uint *)(uRam0207f5f8 & 0xfffffffc) << (uRam0207f5f8 & 3) * -8 + 0x20;
  uVar8 = 0;
  if ((*(char *)(uVar7 + 0x58) == '\0') ||
     (uVar4 = param_2 * 0x30 + uVar7 + 0x74, uVar1 = uVar4 & 3,
     uVar5 = *(uint *)(uVar4 & 0xfffffffc), uVar4 = param_1 * 0x30 + uVar7 + 0x74, uVar2 = uVar4 & 3
     , uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) !=
     (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20))) {
    uVar7 = param_2 * 0x30 + uVar7 + 0x70;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
    bVar6 = false;
    if (uVar7 < 4) {
      if ((1 << (uVar7 & 0xff) & 0xdU) != 0) {
        bVar6 = true;
      }
    }
    if (((bVar6) || (iVar3 = func_02085824(), iVar3 < 1)) &&
       (iVar3 = GetDriverEntry(param_2), uVar7 = iVar3 + 0x7cU & 3,
       uVar4 = *(uint *)(iVar3 + 0x7cU & 0xfffffffc),
       ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & uRam0207f5fc) == 0)) {
      uVar8 = 1;
    }
  }
  return uVar8;
}

