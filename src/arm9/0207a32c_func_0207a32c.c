/* Decompiled C draft; module arm9; ROM address 0207a32c. No matching claim. */
#include "types.h"
#include "deps/0207a32c_func_0207a32c.h"

void func_0207a32c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_18 [3];
  
  uVar2 = GetDriverPlace((short)*(char *)((*(uint *)(uRam0207a4ec & 0xfffffffc) >>
                                           (uRam0207a4ec & 3) * 8 |
                                          *(uint *)(uRam0207a4ec & 0xfffffffc) <<
                                          (uRam0207a4ec & 3) * -8 + 0x20) + 0x62));
  iVar4 = iRam0207a4f4;
  uVar1 = uRam0207a4f0;
  uVar5 = *(uint *)(uRam0207a4ec & 0xfffffffc) >> (uRam0207a4ec & 3) * 8 |
          *(uint *)(uRam0207a4ec & 0xfffffffc) << (uRam0207a4ec & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0xc;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) == 5) {
    uVar3 = 0;
    do {
      uVar6 = uVar1 & 3;
      uVar2 = *(uint *)(uVar1 & 0xfffffffc);
      iVar7 = uVar3 * iVar4 + (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
      uVar6 = iVar7 + 0x4c;
      uVar2 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar3 = uVar3 + 1 & 0xffff;
      *(uint *)(iVar7 + 0x4c) = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20 | 0x8000;
    } while (uVar3 < 3);
    return;
  }
  local_18[0] = (int)*(char *)(uVar5 + 0x62);
  if (uVar2 == 1) {
    func_02085408(2);
  }
  else {
    local_18[1] = func_02085408(uVar2 - 1 & 0xffff);
    if ((-1 < local_18[1]) &&
       (uVar3 = local_18[1] * iRam0207a4f4 +
                (*(uint *)(uRam0207a4f0 & 0xfffffffc) >> (uRam0207a4f0 & 3) * 8 |
                *(uint *)(uRam0207a4f0 & 0xfffffffc) << (uRam0207a4f0 & 3) * -8 + 0x20) + 0x590,
       uVar6 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
       uVar3 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x60, uVar6 = uVar3 & 3,
       uVar3 = *(uint *)(uVar3 & 0xfffffffc),
       uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0)) {
      local_18[1] = -1;
    }
    if ((uVar2 < *(byte *)((*(uint *)(uRam0207a4ec & 0xfffffffc) >> (uRam0207a4ec & 3) * 8 |
                           *(uint *)(uRam0207a4ec & 0xfffffffc) << (uRam0207a4ec & 3) * -8 + 0x20) +
                          0x3d0)) && (iVar4 = func_02085408(uVar2 + 1 & 0xffff), -1 < iVar4)) {
      iVar4 = iVar4 * iRam0207a4f4 +
              (*(uint *)(uRam0207a4f0 & 0xfffffffc) >> (uRam0207a4f0 & 3) * 8 |
              *(uint *)(uRam0207a4f0 & 0xfffffffc) << (uRam0207a4f0 & 3) * -8 + 0x20);
      uVar3 = iVar4 + 0x4c;
      uVar6 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(uint *)(iVar4 + 0x4c) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20 | 0x40000;
    }
  }
  uVar1 = uRam0207a4f8;
  iVar4 = iRam0207a4f4;
  uVar6 = uRam0207a4f0;
  uVar3 = 0;
  if (0 < (int)(*(uint *)(uRam0207a4f8 & 0xfffffffc) >> (uRam0207a4f8 & 3) * 8 |
               *(uint *)(uRam0207a4f8 & 0xfffffffc) << (uRam0207a4f8 & 3) * -8 + 0x20)) {
    do {
      if ((-1 < local_18[uVar3]) &&
         (uVar2 = uVar6 & 3, uVar5 = *(uint *)(uVar6 & 0xfffffffc),
         iVar7 = local_18[uVar3] * iVar4 + (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20),
         uVar2 = iVar7 + 0x4cU & 3, uVar5 = *(uint *)(iVar7 + 0x4cU & 0xfffffffc),
         ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x10000000) == 0)) {
        uVar2 = iVar7 + 0x4cU & 3;
        uVar5 = *(uint *)(iVar7 + 0x4cU & 0xfffffffc);
        *(uint *)(iVar7 + 0x4c) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 0x8000;
      }
      uVar2 = uVar1 & 3;
      uVar5 = *(uint *)(uVar1 & 0xfffffffc);
      uVar3 = uVar3 + 1 & 0xffff;
    } while ((int)uVar3 < (int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20));
    return;
  }
  return;
}

