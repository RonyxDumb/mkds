/* Decompiled C draft; module arm9; ROM address 020e6df0. No matching claim. */
#include "types.h"
#include "deps/020e6df0_func_020e6df0.h"

void func_020e6df0(undefined4 *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  uVar3 = uRam020e6f3c;
  *(undefined4 *)
   (*(uint *)(uRam020e6f3c & 0xfffffffc) >> (uRam020e6f3c & 3) * 8 |
   *(uint *)(uRam020e6f3c & 0xfffffffc) << (uRam020e6f3c & 3) * -8 + 0x20) = 0x1000;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 4) = 0;
  uVar11 = uRam020e6f40;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 8) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0xc) = 0;
  uVar2 = (uint)(param_1 + 4) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  *(uint *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10) =
       uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(param_1 + 5) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  *(uint *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x14) =
       uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x18) = 0;
  uVar2 = (uint)(param_1 + 5) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  *(uint *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1c) =
       -(uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20);
  uVar2 = (uint)(param_1 + 4) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  *(uint *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x20) =
       uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  uVar2 = uVar11 & 3;
  uVar3 = *(uint *)(uVar11 & 0xfffffffc);
  func_02146d0c(param_1,(undefined4 *)(uintptr_t)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20));
  MTX_Concat33(*(uint *)(uRam020e6f3c & 0xfffffffc) >> (uRam020e6f3c & 3) * 8 |
               *(uint *)(uRam020e6f3c & 0xfffffffc) << (uRam020e6f3c & 3) * -8 + 0x20,
               (uint *)(uintptr_t)(*(uint *)(uRam020e6f40 & 0xfffffffc) >> (uRam020e6f40 & 3) * 8 |
               *(uint *)(uRam020e6f40 & 0xfffffffc) << (uRam020e6f40 & 3) * -8 + 0x20),
               (uint *)(uintptr_t)(*(uint *)(uRam020e6f44 & 0xfffffffc) >> (uRam020e6f44 & 3) * 8 |
               *(uint *)(uRam020e6f44 & 0xfffffffc) << (uRam020e6f44 & 3) * -8 + 0x20));
  uVar11 = uRam020e6f48;
  puVar7 = (uint *)(*(uint *)(uRam020e6f48 & 0xfffffffc) >> (uRam020e6f48 & 3) * 8 |
                   *(uint *)(uRam020e6f48 & 0xfffffffc) << (uRam020e6f48 & 3) * -8 + 0x20);
  uVar2 = *(uint *)(uRam020e6f40 & 0xfffffffc) >> (uRam020e6f40 & 3) * 8 |
          *(uint *)(uRam020e6f40 & 0xfffffffc) << (uRam020e6f40 & 3) * -8 + 0x20;
  uVar3 = *(uint *)(uVar2 + 0x1c);
  uVar9 = *(uint *)(uVar2 + 0x20);
  puVar7[6] = *(uint *)(uVar2 + 0x18);
  puVar7[7] = uVar3;
  puVar7[8] = uVar9;
  uVar2 = (uint)(puVar7 + 6) & 3;
  uVar9 = *(uint *)((uint)(puVar7 + 6) & 0xfffffffc);
  uVar3 = (uint)(puVar7 + 8) & 3;
  uVar4 = *(uint *)((uint)(puVar7 + 8) & 0xfffffffc);
  puVar7[2] = -(uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20);
  *puVar7 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  puVar7[1] = 0;
  uVar2 = uVar11 & 3;
  uVar3 = *(uint *)(uVar11 & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 + 4 & 3;
  uVar11 = *(uint *)(uVar3 + 4 & 0xfffffffc);
  uVar4 = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20;
  uVar11 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
           *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 8 & 3;
  uVar9 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  uVar2 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar2 * (longlong)(int)uVar2 +
          (longlong)(int)uVar11 * (longlong)(int)uVar11 +
          (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(uVar3,(int *)(uintptr_t)(uVar3));
  }
  uVar2 = *(uint *)(uRam020e6f48 & 0xfffffffc) >> (uRam020e6f48 & 3) * 8 |
          *(uint *)(uRam020e6f48 & 0xfffffffc) << (uRam020e6f48 & 3) * -8 + 0x20;
  Vector3_Cross(uVar2 + 0x18,uVar2,(uint *)(uintptr_t)(uVar2 + 0xc));
  uVar5 = param_1[1];
  uVar6 = param_1[2];
  uVar8 = param_1[3];
  puVar10 = (undefined4 *)
            (*(uint *)(uRam020e6f4c & 0xfffffffc) >> (uRam020e6f4c & 3) * 8 |
            *(uint *)(uRam020e6f4c & 0xfffffffc) << (uRam020e6f4c & 3) * -8 + 0x20);
  *puVar10 = *param_1;
  puVar10[1] = uVar5;
  puVar10[2] = uVar6;
  puVar10[3] = uVar8;
  uVar5 = param_1[5];
  uVar6 = param_1[6];
  uVar8 = param_1[7];
  puVar10[4] = param_1[4];
  puVar10[5] = uVar5;
  puVar10[6] = uVar6;
  puVar10[7] = uVar8;
  uVar5 = param_1[9];
  uVar6 = param_1[10];
  uVar8 = param_1[0xb];
  puVar10[8] = param_1[8];
  puVar10[9] = uVar5;
  puVar10[10] = uVar6;
  puVar10[0xb] = uVar8;
  return;
}

