/* Decompiled C draft; module arm9; ROM address 020e7460. No matching claim. */
#include "types.h"
#include "deps/020e7460_func_020e7460.h"

void func_020e7460(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int extraout_r1;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  undefined4 unaff_r7;
  int local_34;
  int local_30;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  if (*(int *)(*piRam020e76e4 + 0xc) != 6) {
    uVar2 = find_buf_fn_from_thumb(uRam020e76e8);
    uVar3 = find_buf_fn_from_thumb(uRam020e76ec);
    BillboardModel_CreateFromNsbmdNsbtp_from_thumb(iRam020e76f0,uVar2,uVar3,0);
    BillboardModel_SomeFn(iRam020e76f0);
    *(uint *)(iRam020e76f0 + 0x14) = *(uint *)(iRam020e76f0 + 0x14) | 0xc0;
    uVar2 = find_buf_fn_from_thumb(uRam020e76f4);
    BillboardModel_CreateFromNsbmdNsbtp_from_thumb(iRam020e76f8,uVar2,0,0);
    BillboardModel_SomeFn(iRam020e76f8);
    *(uint *)(iRam020e76f8 + 0x14) = *(uint *)(iRam020e76f8 + 0x14) | 0xc0;
    iVar4 = Mem_AllocateHeap(uVar1,0x78);
    *piRam020e76fc = iVar4;
    iVar4 = Mem_AllocateHeap(uVar1,0x78);
    *piRam020e7700 = iVar4;
    iVar4 = Mem_AllocateHeap(uVar1,0x78);
    *piRam020e7704 = iVar4;
    iVar4 = Mem_AllocateHeap(uVar1,0x78);
    *piRam020e7708 = iVar4;
    iVar4 = Mem_AllocateHeap(uVar1,0x78);
    *piRam020e770c = iVar4;
    iVar4 = iRam020e7710;
    iVar9 = 0;
    local_30 = 0;
    iVar7 = 0;
    do {
      iVar5 = (int)*(short *)(iVar4 + (iVar9 >> 4) * 4);
      uVar6 = Multiply64(iVar5,iVar5 >> 0x1f,0x4c,0);
      *(short *)(*piRam020e76fc + iVar7) = (short)(uVar6 >> 0xc);
      iVar5 = (int)*(short *)(iVar4 + ((int)(iVar9 + iRam020e7714 & 0xffffU) >> 4) * 4);
      Multiply64(iVar5,iVar5 >> 0x1f,uRam020e7718,0xb6);
      iVar5 = (int)((uint)((extraout_r1 + iRam020e771c) * 0x10) >> 0x10) >> 4;
      *(undefined2 *)(*piRam020e7700 + iVar7) = *(undefined2 *)(iVar4 + iVar5 * 4);
      *(undefined2 *)(*piRam020e7704 + iVar7) = *(undefined2 *)(iVar4 + (iVar5 * 2 + 1) * 2);
      iVar5 = (int)*(short *)(iVar4 + ((int)(iVar9 + iRam020e7720 & 0xffffU) >> 4) * 4);
      uVar6 = Multiply64(iVar5,iVar5 >> 0x1f,uRam020e7724,0);
      *(short *)(*piRam020e7708 + iVar7) = (short)(uVar6 >> 0xc) + (short)uRam020e7728;
      iVar5 = (int)*(short *)(iVar4 + ((int)(iVar9 + iRam020e772c & 0xffffU) >> 4) * 4);
      uVar6 = Multiply64(iVar5,iVar5 >> 0x1f,uRam020e7724,0);
      *(short *)(*piRam020e770c + iVar7) = (short)(uVar6 >> 0xc) + (short)uRam020e7730;
      iVar9 = iVar9 + iRam020e7734;
      iVar7 = iVar7 + 2;
      local_30 = local_30 + 1;
    } while (local_30 < 0x3c);
    *puRam020e7738 = 0;
    local_34 = 2;
    puVar8 = puRam020e7740;
    piVar10 = piRam020e773c;
    do {
      if (*piVar10 == 0) {
        *puVar8 = 0;
      }
      else {
        uVar2 = Mem_AllocateHeap(uVar1,0x6c);
        *puVar8 = uVar2;
        unaff_r7 = find_buf_fn_from_thumb(*piVar10);
        Model_CreateFromNsbmd(*puVar8,unaff_r7);
        Model_SetPolygonIdLightFlagsEmi(*puVar8,0x3f,2,uRam020e7744);
        Model_SetCullMode(*puVar8,3);
      }
      if (piVar10[1] == 0) {
        puVar8[1] = 0;
      }
      else {
        uVar2 = Mem_AllocateHeap(uVar1,0x38);
        puVar8[1] = uVar2;
        uVar2 = find_buf_fn_from_thumb(piVar10[1]);
        SomeAnimationLoadWrapper_from_thumb(0,*puVar8,puVar8[1],unaff_r7,uVar2);
        Animation_SetLoop((undefined2 *)(uintptr_t)(puVar8[1]),0,1);
      }
      if (piVar10[2] == 0) {
        puVar8[2] = 0;
      }
      else {
        uVar2 = Mem_AllocateHeap(uVar1,0x38);
        puVar8[2] = uVar2;
        uVar2 = find_buf_fn_from_thumb(piVar10[2]);
        SomeAnimationLoadWrapper_from_thumb(4,*puVar8,puVar8[2],unaff_r7,uVar2);
        Animation_SetLoop((undefined2 *)(uintptr_t)(puVar8[2]),0,1);
      }
      piVar10 = piVar10 + 3;
      puVar8 = puVar8 + 4;
      local_34 = local_34 + 1;
    } while (local_34 < 4);
    uVar1 = find_buf_fn_from_thumb(uRam020e7748);
    uVar2 = find_buf_fn_from_thumb(uRam020e774c);
    BillboardModel_AllocateFromNsbmdNsbtp_from_thumb((undefined4 *)(uintptr_t)(uRam020e7750),uVar1,uVar2,0);
    BillboardModel_SomeFn(*(undefined4 *)(iRam020e7754 + 0xc));
    *(uint *)(*(int *)(iRam020e7754 + 0xc) + 0x14) =
         *(uint *)(*(int *)(iRam020e7754 + 0xc) + 0x14) | 0xc0;
    uVar1 = find_buf_fn_from_thumb(uRam020e7758);
    BillboardModel_AllocateFromNsbmdNsbtp_from_thumb((undefined4 *)(uintptr_t)(uRam020e775c),uVar1,0,0);
    BillboardModel_SomeFn(*(undefined4 *)(iRam020e7754 + 0x1c));
    *(uint *)(*(int *)(iRam020e7754 + 0x1c) + 0x14) =
         *(uint *)(*(int *)(iRam020e7754 + 0x1c) + 0x14) | 0xc0;
  }
  return;
}

