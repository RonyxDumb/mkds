/* Decompiled C draft; module arm9; ROM address 0204fb40. No matching claim. */
#include "types.h"
#include "deps/0204fb40_func_0204fb40.h"

void func_0204fb40(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_20;
  int local_1c;
  int local_18;
  uint *puVar8;
  
  uVar7 = (*(uint *)(uRam0204fcd0 & 0xfffffffc) >> (uRam0204fcd0 & 3) * 8 |
          *(uint *)(uRam0204fcd0 & 0xfffffffc) << (uRam0204fcd0 & 3) * -8 + 0x20) + 0x18;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  puVar8 = (uint *)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(uRam0204fcd4),puVar8,0x40);
  uVar3 = uRam0204fcd8;
  uVar2 = uRam0204fcd0;
  uVar7 = (*(uint *)(uRam0204fcd0 & 0xfffffffc) >> (uRam0204fcd0 & 3) * 8 |
          *(uint *)(uRam0204fcd0 & 0xfffffffc) << (uRam0204fcd0 & 3) * -8 + 0x20) + 0x7c;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  *(byte *)(uVar5 + 0x15) = *(byte *)(uVar5 + 0x15) & 0xfe;
  *(byte *)(uVar5 + 0x15) = *(byte *)(uVar5 + 0x15) & 0x81;
  uVar7 = uVar5 + 0x18 & 3;
  uVar6 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
  *(uint *)(uVar5 + 0x18) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xfffffff0;
  uVar7 = uVar5 + 0x18 & 3;
  uVar6 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
  *(uint *)(uVar5 + 0x18) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xfffffe0f;
  uVar7 = uVar5 + 0x18 & 3;
  uVar6 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
  *(uint *)(uVar5 + 0x18) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xffff01ff;
  uVar7 = uVar5 + 0x18 & 3;
  uVar6 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
  *(uint *)(uVar5 + 0x18) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xffc0ffff;
  uVar7 = uVar5 + 0x18 & 3;
  uVar6 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
  *(uint *)(uVar5 + 0x18) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & uVar3;
  *(byte *)(uVar5 + 0x14) = *(byte *)(uVar5 + 0x14) & 0xf0;
  uVar7 = uVar2 & 3;
  uVar5 = *(uint *)(uVar2 & 0xfffffffc);
  uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  if ((*(ushort *)(uVar7 + 0x454) & 0x40) == 0) {
    GetCurrentTime(&local_20);
    if (0x11 < local_20) {
      local_20 = local_20 - 0x12;
    }
    uVar7 = OS_GetTickLo();
    uVar7 = uVar7 | ((local_20 * 0x3c + local_1c) * 0x3c + local_18) * 0x10000;
    lVar1 = (ulonglong)uRam0204fce4 * (ulonglong)uVar7;
    *(ushort *)(puVar8 + 3) =
         (ushort)(uVar7 * iRam0204fce0 + (int)((ulonglong)lVar1 >> 0x20) +
                  (uint)CARRY4((uint)lVar1,uRam0204fce8) >> 0x10) | 0x8000;
  }
  else {
    *(ushort *)(puVar8 + 3) = (ushort)uRam0204fcdc & *(short *)(uVar7 + 0x1690) + 7U;
  }
  *(short *)((int)puVar8 + 0x32) =
       (short)*(char *)((*(uint *)(uRam0204fcd0 & 0xfffffffc) >> (uRam0204fcd0 & 3) * 8 |
                        *(uint *)(uRam0204fcd0 & 0xfffffffc) << (uRam0204fcd0 & 3) * -8 + 0x20) +
                       0x88);
  uVar4 = MaybeGeneratePseudoRandomValue();
  uVar5 = uRam0204fcd0;
  *(undefined2 *)(puVar8 + 6) = uVar4;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x7c;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *puVar8 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  *(undefined2 *)(puVar8 + 1) = 0x1c;
  *(undefined2 *)(puVar8 + 4) = 7;
  *(ushort *)((int)puVar8 + 0xe) = (ushort)(param_1 != 0);
  return;
}

