/* Decompiled C draft; module arm9; ROM address 020dadfc. No matching claim. */
#include "types.h"
#include "deps/020dadfc_func_020dadfc.h"

void func_020dadfc(int param_1)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_1 + 0xf0);
  if ((9 < uVar1) && ((uVar1 < 0x14 || (0x1d < uVar1)))) {
    func_020d8cc8(param_1 + 0xcc);
  }
  func_020d8c74(param_1 + 0xcc,param_1 + 4);
  uVar6 = param_1 + 0xc4U & 3;
  uVar5 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((uVar6 == 0x1000) &&
     (uVar5 = param_1 + 200U & 3, uVar4 = *(uint *)(param_1 + 200U & 0xfffffffc),
     uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0)) {
    return;
  }
  uVar6 = 0x1000 - uVar6;
  uVar5 = param_1 + 200U & 3;
  uVar4 = *(uint *)(param_1 + 200U & 0xfffffffc);
  *(uint *)(param_1 + 200) =
       (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) +
       (uVar6 * 0x200 >> 0xc | (((int)uVar6 >> 0x1f) << 9 | uVar6 >> 0x17) << 0x14);
  uVar6 = param_1 + 200U & 3;
  uVar5 = *(uint *)(param_1 + 200U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar2 = (ulonglong)uRam020daf00 * (ulonglong)uVar6;
  *(uint *)(param_1 + 200) =
       (uint)lVar2 >> 0xc |
       (((int)uVar6 >> 0x1f) * uRam020daf00 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
  iVar3 = iRam020daf04;
  uVar6 = param_1 + 0xc4U & 3;
  uVar7 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar5 = param_1 + 200U & 3;
  uVar4 = *(uint *)(param_1 + 200U & 0xfffffffc);
  *(uint *)(param_1 + 0xc4) =
       (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
       (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  uVar6 = param_1 + 0xc4U & 3;
  uVar5 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((int)uVar6 <= iVar3) {
    return;
  }
  if ((int)uVar6 < iRam020daf08) {
    uVar6 = param_1 + 200U & 3;
    uVar5 = *(uint *)(param_1 + 200U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if (-0x29 < (int)uVar6) {
      if ((int)uVar6 < 0x29) {
        *(undefined4 *)(param_1 + 0xc4) = 0x1000;
        *(undefined4 *)(param_1 + 200) = 0;
      }
      return;
    }
    return;
  }
  return;
}

