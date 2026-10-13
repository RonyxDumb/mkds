/* Decompiled C draft; module arm9; ROM address 0208b934. No matching claim. */
#include "types.h"
#include "deps/0208b934_SomeEffectFileStuff.h"

void SomeEffectFileStuff(uint param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  *puRam0208bcc0 = uRam0208bcbc;
  uVar10 = 0x78;
  uVar9 = 0x28;
  iVar4 = GetCurrentSceneId();
  uVar8 = param_1;
  if (iVar4 == 2) {
    uVar7 = *(uint *)(uRam0208bcc4 & 0xfffffffc) >> (uRam0208bcc4 & 3) * 8 |
            *(uint *)(uRam0208bcc4 & 0xfffffffc) << (uRam0208bcc4 & 3) * -8 + 0x20;
    uVar6 = uVar7 + 8 & 3;
    uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 4) {
      uVar8 = uRam0208bcc8 & 3;
      uVar6 = *(uint *)(uRam0208bcc8 & 0xfffffffc);
      *puRam0208bcc0 = uRam0208bccc;
      uVar8 = (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 0xa4;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      uVar10 = 0x96;
    }
    if ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
        *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) == 0x34) {
      uVar10 = 300;
      uVar9 = 0x32;
    }
  }
  *puRam0208bcd0 = uVar8;
  func_02061768();
  uVar9 = func_02018d94(uRam0208bcd4,uVar9,uVar10,3);
  *puRam0208bcd8 = uVar9;
  iVar4 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208bcdc);
  func_02018a1c(*(uint *)((uint)puRam0208bcd8 & 0xfffffffc) >> ((uint)puRam0208bcd8 & 3) * 8 |
                *(uint *)((uint)puRam0208bcd8 & 0xfffffffc) << ((uint)puRam0208bcd8 & 3) * -8 + 0x20
                ,iVar4);
  func_02018888(*(uint *)((uint)puRam0208bcd8 & 0xfffffffc) >> ((uint)puRam0208bcd8 & 3) * 8 |
                *(uint *)((uint)puRam0208bcd8 & 0xfffffffc) << ((uint)puRam0208bcd8 & 3) * -8 + 0x20
               );
  func_02018874(*(uint *)((uint)puRam0208bcd8 & 0xfffffffc) >> ((uint)puRam0208bcd8 & 3) * 8 |
                *(uint *)((uint)puRam0208bcd8 & 0xfffffffc) << ((uint)puRam0208bcd8 & 3) * -8 + 0x20
               );
  uVar6 = iVar4 + 0x18U & 3;
  uVar5 = *(uint *)(iVar4 + 0x18U & 0xfffffffc);
  ResizeActiveExecutionContextHeapHandle_from_thumb
            (iVar4,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  uVar9 = func_02018d94(uRam0208bcd4,0x1e,100,3);
  *puRam0208bce0 = uVar9;
  uVar9 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208bce4);
  func_02018a1c(*(uint *)((uint)puRam0208bce0 & 0xfffffffc) >> ((uint)puRam0208bce0 & 3) * 8 |
                *(uint *)((uint)puRam0208bce0 & 0xfffffffc) << ((uint)puRam0208bce0 & 3) * -8 + 0x20
                ,uVar9);
  func_02018888(*(uint *)((uint)puRam0208bce0 & 0xfffffffc) >> ((uint)puRam0208bce0 & 3) * 8 |
                *(uint *)((uint)puRam0208bce0 & 0xfffffffc) << ((uint)puRam0208bce0 & 3) * -8 + 0x20
               );
  func_02018874(*(uint *)((uint)puRam0208bce0 & 0xfffffffc) >> ((uint)puRam0208bce0 & 3) * 8 |
                *(uint *)((uint)puRam0208bce0 & 0xfffffffc) << ((uint)puRam0208bce0 & 3) * -8 + 0x20
               );
  puVar2 = puRam0208bcec;
  *puRam0208bce8 = 0;
  puVar3 = puRam0208bcf0;
  *puVar2 = 0;
  *puVar3 = 0;
  iVar4 = GetCurrentSceneId();
  if (iVar4 == 2) {
    uVar6 = (*(uint *)(uRam0208bcc4 & 0xfffffffc) >> (uRam0208bcc4 & 3) * 8 |
            *(uint *)(uRam0208bcc4 & 0xfffffffc) << (uRam0208bcc4 & 3) * -8 + 0x20) + 8;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) == 4) {
      uStack_40 = 0;
      uVar9 = func_02018d94(uRam0208bcd4,0x32,200,3);
      *puRam0208bcec = uVar9;
      ReadFileFromMountManagerHandle_from_thumb(uRam0208bcf4,uVar8,&uStack_40);
      func_02018a1c(*(uint *)((uint)puRam0208bcec & 0xfffffffc) >> ((uint)puRam0208bcec & 3) * 8 |
                    *(uint *)((uint)puRam0208bcec & 0xfffffffc) <<
                    ((uint)puRam0208bcec & 3) * -8 + 0x20,uStack_40);
      func_02018888(*(uint *)((uint)puRam0208bcec & 0xfffffffc) >> ((uint)puRam0208bcec & 3) * 8 |
                    *(uint *)((uint)puRam0208bcec & 0xfffffffc) <<
                    ((uint)puRam0208bcec & 3) * -8 + 0x20);
      func_02018874(*(uint *)((uint)puRam0208bcec & 0xfffffffc) >> ((uint)puRam0208bcec & 3) * 8 |
                    *(uint *)((uint)puRam0208bcec & 0xfffffffc) <<
                    ((uint)puRam0208bcec & 3) * -8 + 0x20);
      *(undefined4 *)
       ((*(uint *)((uint)puRam0208bcec & 0xfffffffc) >> ((uint)puRam0208bcec & 3) * 8 |
        *(uint *)((uint)puRam0208bcec & 0xfffffffc) << ((uint)puRam0208bcec & 3) * -8 + 0x20) + 0x3c
       ) = 0x8000;
    }
    puVar3 = puRam0208bcec;
    puVar2 = puRam0208bce0;
    uVar7 = *(uint *)((uint)puRam0208bcd8 & 0xfffffffc) >> ((uint)puRam0208bcd8 & 3) * 8 |
            *(uint *)((uint)puRam0208bcd8 & 0xfffffffc) << ((uint)puRam0208bcd8 & 3) * -8 + 0x20;
    uVar6 = uVar7 + 0x38;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar7 + 0x38) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20 | 0x1000000;
    uVar6 = (uint)puVar2 & 3;
    uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc);
    uVar7 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = uVar7 + 0x38;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar7 + 0x38) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20 | 0x1000000;
    uVar6 = (uint)puVar3 & 3;
    uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if (uVar6 != 0) {
      uVar5 = uVar6 + 0x38 & 3;
      uVar7 = *(uint *)(uVar6 + 0x38 & 0xfffffffc);
      *(uint *)(uVar6 + 0x38) = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20 | 0x1000000;
    }
    AndAnotherAlloc(param_1);
    uVar5 = *(uint *)(uRam0208bcc4 & 0xfffffffc) >> (uRam0208bcc4 & 3) * 8 |
            *(uint *)(uRam0208bcc4 & 0xfffffffc) << (uRam0208bcc4 & 3) * -8 + 0x20;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 0x1d) {
      *(undefined4 *)
       ((*(uint *)((uint)puRam0208bcd8 & 0xfffffffc) >> ((uint)puRam0208bcd8 & 3) * 8 |
        *(uint *)((uint)puRam0208bcd8 & 0xfffffffc) << ((uint)puRam0208bcd8 & 3) * -8 + 0x20) + 0x3c
       ) = 0;
    }
    else {
      *(undefined4 *)
       ((*(uint *)((uint)puRam0208bcd8 & 0xfffffffc) >> ((uint)puRam0208bcd8 & 3) * 8 |
        *(uint *)((uint)puRam0208bcd8 & 0xfffffffc) << ((uint)puRam0208bcd8 & 3) * -8 + 0x20) + 0x3c
       ) = 0x8000;
    }
    func_02082aec();
    uVar5 = *(uint *)(uRam0208bcc4 & 0xfffffffc) >> (uRam0208bcc4 & 3) * 8 |
            *(uint *)(uRam0208bcc4 & 0xfffffffc) << (uRam0208bcc4 & 3) * -8 + 0x20;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if (uVar6 == 0x22) {
      uStack_3c = *puRam0208bcf8;
      uStack_38 = puRam0208bcf8[1];
      uStack_34 = puRam0208bcf8[2];
      uVar9 = Mem_AllocateHeap(uVar8,100);
      iVar4 = iRam0208bcfc;
      puVar2 = puRam0208bcf0;
      uVar8 = 0;
      *puRam0208bcf0 = uVar9;
      do {
        *(undefined4 *)
         ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar8 * 4 + 0x48
         ) = 0;
        VecFx32_Subtract(iVar4 + uVar8 * 0xc,&uStack_3c,&iStack_30);
        lVar1 = (longlong)iStack_28 * (longlong)iStack_28 +
                (longlong)iStack_30 * (longlong)iStack_30 +
                (longlong)iStack_2c * (longlong)iStack_2c;
        if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
          Vector3_MaybeNormalize
                    (&iStack_30,
                     (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                     *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) +
                     uVar8 * 0xc);
        }
        uVar9 = uRam0208bd00;
        puVar3 = puRam0208bce8;
        uVar8 = uVar8 + 1 & 0xff;
      } while (uVar8 < 6);
      *(undefined2 *)
       ((*(uint *)((uint)puRam0208bcf0 & 0xfffffffc) >> ((uint)puRam0208bcf0 & 3) * 8 |
        *(uint *)((uint)puRam0208bcf0 & 0xfffffffc) << ((uint)puRam0208bcf0 & 3) * -8 + 0x20) + 0x60
       ) = 1;
      *puVar3 = uVar9;
      return;
    }
    if (uVar6 == 0x34) {
      func_0208afe4();
      return;
    }
    return;
  }
  return;
}

