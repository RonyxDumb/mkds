/* Decompiled C draft; module arm9; ROM address 020f850c. No matching claim. */
#include "types.h"
#include "deps/020f850c_func_020f850c.h"

undefined4 func_020f850c(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar2 = uRam020f86b0;
  uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar1 == 1) {
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[1] = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 1;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    if ((uVar2 == 5) &&
       (uVar1 = (uint)(param_1 + 8) & 3, uVar5 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc),
       uVar5 >> uVar1 * 8 != 0 || uVar5 << uVar1 * -8 + 0x20 != 0)) {
      uVar2 = *(ushort *)(param_2 + 0x1f8) & 0xff;
      iVar3 = func_0205a310(*(undefined1 *)
                             ((*(uint *)(uRam020f86b4 & 0xfffffffc) >> (uRam020f86b4 & 3) * 8 |
                              *(uint *)(uRam020f86b4 & 0xfffffffc) << (uRam020f86b4 & 3) * -8 + 0x20
                              ) + uVar2));
      if (iVar3 == 0) {
        iVar3 = func_0205a2ac(*(undefined1 *)
                               ((*(uint *)(uRam020f86b4 & 0xfffffffc) >> (uRam020f86b4 & 3) * 8 |
                                *(uint *)(uRam020f86b4 & 0xfffffffc) <<
                                (uRam020f86b4 & 3) * -8 + 0x20) + uVar2));
        iVar4 = func_020faca4();
        if (iVar4 != 0) {
          func_020faa78(iVar3);
        }
        iVar7 = iVar3 * 0x1c +
                (*(uint *)(uRam020f86b8 & 0xfffffffc) >> (uRam020f86b8 & 3) * 8 |
                *(uint *)(uRam020f86b8 & 0xfffffffc) << (uRam020f86b8 & 3) * -8 + 0x20);
        uVar2 = iVar7 + 8;
        uVar1 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        iVar4 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020f86bc & 0xfffffffc) >> (uRam020f86bc & 3) * 8 |
                *(uint *)(uRam020f86bc & 0xfffffffc) << (uRam020f86bc & 3) * -8 + 0x20);
        uVar2 = iVar4 + 0x1c;
        uVar1 = uVar2 & 3;
        uVar6 = *(uint *)(uVar2 & 0xfffffffc);
        uVar2 = iVar7 + 0xc;
        uVar5 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        *(uint *)(iVar4 + 0x1c) =
             (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) +
             (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
        param_1[4] = iVar3;
        param_1[8] = 0;
        uVar2 = (uint)(param_1 + 1) & 3;
        uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        uVar1 = (uint)(param_1 + 2) & 3;
        uVar6 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
        param_1[2] = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) +
                     ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) - 0x6f);
      }
      else {
        uVar2 = (uint)(param_1 + 1) & 3;
        uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        if (0x6e < (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) {
          param_1[1] = 0x67;
        }
      }
      return 0;
    }
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar1 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    if ((0x3c < uVar1) &&
       (((((uRam020f86c0 & *(ushort *)(param_2 + 0x1ec)) == uRam020f86c0 && (uVar2 != 5)) &&
         (uVar2 = (uint)(param_1 + 7) & 3, uVar5 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc),
         uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0)) ||
        (uVar2 = (uint)(param_1 + 2) & 3, uVar5 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
        (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) < uVar1)))) {
      param_1[1] = 0;
      *param_1 = 2;
    }
  }
  else if ((uVar1 == 2) &&
          (uVar2 = (uint)(param_1 + 1) & 3, uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc),
          param_1[1] = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 1,
          uVar2 = (uint)(param_1 + 1) & 3, uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc),
          uVar1 = (uint)(param_1 + 10) & 3, uVar5 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc),
          (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * 2 <
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20))) {
    return 1;
  }
  return 0;
}

