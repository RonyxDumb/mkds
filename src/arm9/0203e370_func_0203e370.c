/* Decompiled C draft; module arm9; ROM address 0203e370. No matching claim. */
#include "types.h"
#include "deps/0203e370_func_0203e370.h"

void func_0203e370(int param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar3;
  
  uVar5 = (*(uint *)(uRam0203e4c0 & 0xfffffffc) >> (uRam0203e4c0 & 3) * 8 |
          *(uint *)(uRam0203e4c0 & 0xfffffffc) << (uRam0203e4c0 & 3) * -8 + 0x20) + 0x44;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  sVar1 = *(short *)((uint)*(ushort *)(param_1 + 0x32) * 0x24 +
                     (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x20);
  if ((sVar1 != -1) &&
     (*(short *)(param_1 + 0x36) = sVar1, (int)sVar1 <= *(short *)(param_1 + 0x34) + 1)) {
    *(short *)(param_1 + 0x34) = sVar1;
  }
  if ((param_2 == 0) &&
     ((int)(*(ushort *)
             ((*(uint *)(uRam0203e4c0 & 0xfffffffc) >> (uRam0203e4c0 & 3) * 8 |
              *(uint *)(uRam0203e4c0 & 0xfffffffc) << (uRam0203e4c0 & 3) * -8 + 0x20) + 0x98) - 1)
      <= (int)*(short *)(param_1 + 0x34))) {
    func_0203e550(param_1);
  }
  else if ((*(short *)(param_1 + 0x32) == 0) &&
          (param_2 ==
           *(ushort *)
            ((*(uint *)(uRam0203e4c0 & 0xfffffffc) >> (uRam0203e4c0 & 3) * 8 |
             *(uint *)(uRam0203e4c0 & 0xfffffffc) << (uRam0203e4c0 & 3) * -8 + 0x20) + 0x9a))) {
    uVar5 = param_1 + 0x24U & 3;
    uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if (-100 < (int)uVar5) {
      *(uint *)(param_1 + 0x24) = uVar5 - 1;
    }
    uVar4 = uRam0203e4c0;
    *(short *)(param_1 + 0x36) =
         *(short *)((*(uint *)(uRam0203e4c0 & 0xfffffffc) >> (uRam0203e4c0 & 3) * 8 |
                    *(uint *)(uRam0203e4c0 & 0xfffffffc) << (uRam0203e4c0 & 3) * -8 + 0x20) + 0x98)
         + -1;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(short *)(param_1 + 0x34) =
         *(short *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x98) + -1;
  }
  uVar4 = uRam0203e4c0;
  *(short *)(param_1 + 0x32) = (short)param_2;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = 0;
  if (*(short *)(uVar4 + 0x50) != 0) {
    uVar3 = uVar4 + 0x4c & 3;
    uVar2 = *(uint *)(uVar4 + 0x4c & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    do {
      uVar2 = (uint)*(ushort *)(uVar3 + uVar5 * 0xc);
      if ((uVar2 <= (param_2 & 0xffff)) &&
         ((param_2 & 0xffff) < (uVar2 + *(ushort *)(uVar3 + uVar5 * 0xc + 2) & 0xffff)))
      goto LAB_0203e4b4;
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < *(ushort *)(uVar4 + 0x50));
  }
  uVar5 = 0;
LAB_0203e4b4:
  *(short *)(param_1 + 0x38) = (short)uVar5;
  return;
}

