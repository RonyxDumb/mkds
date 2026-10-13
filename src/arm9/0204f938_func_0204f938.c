/* Decompiled C draft; module arm9; ROM address 0204f938. No matching claim. */
#include "types.h"
#include "deps/0204f938_func_0204f938.h"

void func_0204f938(int param_1)

{
  longlong lVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_20;
  int local_1c;
  int local_18;
  uint *puVar8;
  
  uVar7 = (*(uint *)(uRam0204fb20 & 0xfffffffc) >> (uRam0204fb20 & 3) * 8 |
          *(uint *)(uRam0204fb20 & 0xfffffffc) << (uRam0204fb20 & 3) * -8 + 0x20) + 0x18;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  puVar8 = (uint *)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(uRam0204fb24),puVar8,0x40);
  uVar7 = (*(uint *)(uRam0204fb20 & 0xfffffffc) >> (uRam0204fb20 & 3) * 8 |
          *(uint *)(uRam0204fb20 & 0xfffffffc) << (uRam0204fb20 & 3) * -8 + 0x20) + 0x7c;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar6 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
  *(byte *)(uVar6 + 0x15) = *(byte *)(uVar6 + 0x15) & 0xfe | 1;
  Mem_CpuCopy8((ushort *)(uintptr_t)(param_1 + 0xc),(uint *)(uintptr_t)(uVar6),0x14);
  uVar7 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(byte *)(uVar6 + 0x15) =
       *(byte *)(uVar6 + 0x15) & 0x81 |
       (byte)((((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) << 0x16) >> 0x1a) << 1);
  uVar7 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar3 = uVar6 + 0x18 & 3;
  uVar5 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  *(uint *)(uVar6 + 0x18) =
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0xfffffff0 |
       (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & 0xf;
  uVar7 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar3 = GetCourseIdFromInternalId
                    (((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) << 0x10) >> 0x1a);
  uVar7 = uVar6 + 0x18 & 3;
  uVar4 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  *(uint *)(uVar6 + 0x18) =
       (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & 0xfffffe0f | (uVar3 & 0x1f) << 4;
  uVar7 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar6 + 0x18 & 3;
  uVar5 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  *(uint *)(uVar6 + 0x18) =
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0xffff01ff |
       (((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) << 0x11) >> 0x19) << 9;
  uVar7 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar6 + 0x18 & 3;
  uVar5 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  *(uint *)(uVar6 + 0x18) =
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0xffc0ffff |
       (((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) << 10) >> 0x19 & 0x3f) << 0x10;
  uVar7 = uVar6 + 0x18 & 3;
  uVar5 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  uVar3 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(uint *)(uVar6 + 0x18) =
       (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & uRam0204fb28 |
       (uRam0204fb2c & (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) >> 0x16) << 0x16;
  GetCurrentTime(&local_20);
  if (0x11 < local_20) {
    local_20 = local_20 - 0x12;
  }
  uVar7 = OS_GetTickLo();
  uVar3 = uRam0204fb20;
  uVar7 = uVar7 | ((local_20 * 0x3c + local_1c) * 0x3c + local_18) * 0x10000;
  lVar1 = (ulonglong)uRam0204fb34 * (ulonglong)uVar7;
  *(ushort *)(puVar8 + 3) =
       (ushort)(uVar7 * iRam0204fb30 + (int)((ulonglong)lVar1 >> 0x20) +
                (uint)CARRY4((uint)lVar1,uRam0204fb38) >> 0x10) | 0x8000;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(short *)((int)puVar8 + 0x32) =
       (short)*(char *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 0x88);
  uVar2 = MaybeGeneratePseudoRandomValue();
  *(undefined2 *)(puVar8 + 6) = uVar2;
  uVar7 = (*(uint *)(uRam0204fb20 & 0xfffffffc) >> (uRam0204fb20 & 3) * 8 |
          *(uint *)(uRam0204fb20 & 0xfffffffc) << (uRam0204fb20 & 3) * -8 + 0x20) + 0x7c;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *puVar8 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
  *(undefined2 *)(puVar8 + 1) = 0x1c;
  uVar2 = (undefined2)uRam0204fb3c;
  *(undefined2 *)(puVar8 + 4) = 1;
  *(undefined2 *)(puVar8 + 0xd) = uVar2;
  *(undefined2 *)((int)puVar8 + 0x36) = 0x2e;
  return;
}

