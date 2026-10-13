/* Decompiled C draft; module arm9; ROM address 0208f0f8. No matching claim. */
#include "types.h"
#include "deps/0208f0f8_func_0208f0f8.h"

void func_0208f0f8(uint param_1)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  
  uVar10 = (*(uint *)(uRam0208f390 & 0xfffffffc) >> (uRam0208f390 & 3) * 8 |
           *(uint *)(uRam0208f390 & 0xfffffffc) << (uRam0208f390 & 3) * -8 + 0x20) + 0xc;
  uVar18 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar12 = uRam0208f394;
  if ((uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20) != 5) {
    uVar12 = uRam0208f398;
  }
  uVar11 = FindFileBuffer_MAR_EFT_from_thumb(uVar12);
  puVar1 = puRam0208f39c;
  *puRam0208f39c = 8;
  puVar2 = puRam0208f3a0;
  uVar19 = uRam0208f390;
  *puRam0208f3a0 = 0x4d;
  puVar3 = puRam0208f3a4;
  *puRam0208f3a4 = 3;
  puVar4 = puRam0208f3a8;
  *puRam0208f3a8 = 0xc;
  puVar7 = puRam0208f3b8;
  uVar12 = uRam0208f3b4;
  puVar6 = puRam0208f3b0;
  puVar5 = puRam0208f3ac;
  uVar10 = 1;
  uVar18 = uVar19 & 3;
  uVar19 = *(uint *)(uVar19 & 0xfffffffc);
  uVar20 = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
  *puRam0208f3ac = 0xe;
  *puVar6 = 1;
  *puVar7 = uVar12;
  uVar12 = uRam0208f3bc;
  uVar18 = uVar20 + 8 & 3;
  uVar19 = *(uint *)(uVar20 + 8 & 0xfffffffc);
  if ((uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20) == 5) {
    uVar10 = 4;
  }
  else {
    uVar18 = uVar20 + 0xc & 3;
    uVar19 = *(uint *)(uVar20 + 0xc & 0xfffffffc);
    if ((uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20) == 5) {
      *puVar1 = 0xe;
      *puVar3 = 2;
      *puVar2 = 0;
      *puVar4 = 0x1e;
      *puVar7 = uVar12;
      *puVar5 = 4;
      *puVar6 = 0;
      uVar10 = 6;
    }
  }
  uVar19 = uVar20 + 8 & 3;
  uVar20 = *(uint *)(uVar20 + 8 & 0xfffffffc);
  uVar18 = *puRam0208f3a8 * uVar10 & 0xffff;
  if ((uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20) == 4) {
    uVar19 = (*(uint *)(uRam0208f3c0 & 0xfffffffc) >> (uRam0208f3c0 & 3) * 8 |
             *(uint *)(uRam0208f3c0 & 0xfffffffc) << (uRam0208f3c0 & 3) * -8 + 0x20) + 0xa4;
    uVar20 = uVar19 & 3;
    uVar19 = *(uint *)(uVar19 & 0xfffffffc);
    param_1 = uVar19 >> uVar20 * 8 | uVar19 << uVar20 * -8 + 0x20;
  }
  uVar12 = Mem_AllocateHeap(param_1,0x38);
  *puRam0208f3c4 = uVar12;
  iVar13 = Mem_AllocateHeap(param_1,uVar10 * 0x30);
  iVar14 = Mem_AllocateHeap(param_1,uVar18 * 0x1c);
  IntrusiveListWrapper_InitializeEmpty
            (*(uint *)((uint)puRam0208f3c4 & 0xfffffffc) >> ((uint)puRam0208f3c4 & 3) * 8 |
             *(uint *)((uint)puRam0208f3c4 & 0xfffffffc) << ((uint)puRam0208f3c4 & 3) * -8 + 0x20,0)
  ;
  IntrusiveListWrapper_InitializeEmpty
            ((*(uint *)((uint)puRam0208f3c4 & 0xfffffffc) >> ((uint)puRam0208f3c4 & 3) * 8 |
             *(uint *)((uint)puRam0208f3c4 & 0xfffffffc) << ((uint)puRam0208f3c4 & 3) * -8 + 0x20) +
             0xc,0);
  IntrusiveListWrapper_InitializeEmpty
            ((*(uint *)((uint)puRam0208f3c4 & 0xfffffffc) >> ((uint)puRam0208f3c4 & 3) * 8 |
             *(uint *)((uint)puRam0208f3c4 & 0xfffffffc) << ((uint)puRam0208f3c4 & 3) * -8 + 0x20) +
             0x18,0);
  uVar19 = 0;
  if (uVar10 != 0) {
    do {
      iVar16 = uVar19 * 0x30 + iVar13;
      IntrusiveListWrapper_InitializeEmpty(iVar16 + 8,0);
      IntrusiveListWrapper_InsertLast
                ((*(uint *)((uint)puRam0208f3c4 & 0xfffffffc) >> ((uint)puRam0208f3c4 & 3) * 8 |
                 *(uint *)((uint)puRam0208f3c4 & 0xfffffffc) <<
                 ((uint)puRam0208f3c4 & 3) * -8 + 0x20) + 0xc,iVar16);
      uVar19 = uVar19 + 1 & 0xffff;
    } while (uVar19 < uVar10);
  }
  puVar2 = puRam0208f3c4;
  uVar10 = 0;
  if (uVar18 != 0) {
    do {
      uVar19 = (uint)puVar2 & 3;
      uVar20 = *(uint *)((uint)puVar2 & 0xfffffffc);
      IntrusiveListWrapper_InsertLast
                ((uVar20 >> uVar19 * 8 | uVar20 << uVar19 * -8 + 0x20) + 0x18,uVar10 * 0x1c + iVar14
                );
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < uVar18);
  }
  LoadedModelTexture_SomeFn
            ((*(uint *)((uint)puRam0208f3c4 & 0xfffffffc) >> ((uint)puRam0208f3c4 & 3) * 8 |
             *(uint *)((uint)puRam0208f3c4 & 0xfffffffc) << ((uint)puRam0208f3c4 & 3) * -8 + 0x20) +
             0x24,uVar11,uVar11);
  uVar9 = uRam0208f3cc;
  puVar8 = puRam0208f3c8;
  uVar20 = uRam0208f390;
  uVar15 = *(uint *)((uint)puRam0208f3c4 & 0xfffffffc) >> ((uint)puRam0208f3c4 & 3) * 8 |
           *(uint *)((uint)puRam0208f3c4 & 0xfffffffc) << ((uint)puRam0208f3c4 & 3) * -8 + 0x20;
  uVar10 = uVar15 + 0x30;
  uVar18 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar18 = uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20;
  uVar10 = uVar18 + 8;
  uVar19 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar17 = (*(uint *)((uint)puRam0208f3c8 & 0xfffffffc) >> ((uint)puRam0208f3c8 & 3) * 8 |
           *(uint *)((uint)puRam0208f3c8 & 0xfffffffc) << ((uint)puRam0208f3c8 & 3) * -8 + 0x20) &
           0xffff0000;
  uVar10 = uRam0208f3cc &
           (uVar10 >> uVar19 * 8 | uVar10 << uVar19 * -8 + 0x20) & uRam0208f3cc & 0x1fffffff;
  *puRam0208f3c8 = uVar17;
  *puVar8 = uVar17 | uVar10;
  uVar18 = uVar18 + 0x2c;
  uVar10 = uVar18 & 3;
  uVar17 = *(uint *)(uVar18 & 0xfffffffc);
  uVar12 = 0x8000;
  uVar18 = uVar20 & 3;
  uVar19 = *(uint *)(uVar20 & 0xfffffffc);
  uVar18 = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
  puVar8[6] = ((uVar17 >> uVar10 * 8 | uVar17 << uVar10 * -8 + 0x20) & uVar9) << 3;
  puVar8[7] = 0x10000;
  puVar8[8] = 0x8000;
  uVar10 = uVar18 & 3;
  uVar18 = *(uint *)(uVar18 & 0xfffffffc);
  if ((uVar18 >> uVar10 * 8 | uVar18 << uVar10 * -8 + 0x20) == 0x1d) {
    uVar12 = 0;
  }
  *(undefined4 *)(uVar15 + 0x34) = uVar12;
  return;
}

