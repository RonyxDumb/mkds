/* Decompiled C draft; module arm9; ROM address 0206331c. No matching claim. */
#include "types.h"
#include "deps/0206331c_LoadCourseModelsAnimations.h"

void LoadCourseModelsAnimations(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined6 uVar10;
  int local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar1 = FindFileBuffer_CRS_CST_from_thumb(uRam020636a0);
  uVar2 = FindFileBuffer_CRS_CST_from_thumb(uRam020636a4);
  uVar3 = Mem_AllocateHeap(param_1,0x6c);
  *puRam020636a8 = uVar3;
  iVar4 = Model_CreateFromNsbmdNsbtxMetaCopy(param_1,uVar3,uVar1,uVar2);
  uVar10 = FindFileBuffer_CRS_CST_from_thumb(uRam020636ac);
  uVar9 = (undefined2)((uint6)uVar10 >> 0x20);
  iVar6 = (int)uVar10;
  if (iVar6 == 0) {
    uVar9 = 0;
  }
  if (iVar6 == 0) {
    *(undefined2 *)(puRam020636a8 + 8) = uVar9;
  }
  else {
    Animation_CreateFrom
              (2,uRam020636b0,
               *(uint *)((uint)puRam020636a8 & 0xfffffffc) >> ((uint)puRam020636a8 & 3) * 8 |
               *(uint *)((uint)puRam020636a8 & 0xfffffffc) << ((uint)puRam020636a8 & 3) * -8 + 0x20,
               1,param_1,uVar1);
    Animation_RegisterAll(uRam020636b0,iVar6,param_1);
    Animation_SetLoop(uRam020636b0,0,1);
    Animation_SetAt(uRam020636b0,0);
  }
  iVar5 = FindFileBuffer_CRS_CST_from_thumb(uRam020636b4);
  iVar6 = iVar5;
  if (iVar5 == 0) {
    iVar6 = 0;
  }
  if (iVar5 == 0) {
    *(short *)(puRam020636a8 + 0x16) = (short)iVar6;
  }
  else {
    Animation_CreateFrom
              (1,uRam020636b8,
               *(uint *)((uint)puRam020636a8 & 0xfffffffc) >> ((uint)puRam020636a8 & 3) * 8 |
               *(uint *)((uint)puRam020636a8 & 0xfffffffc) << ((uint)puRam020636a8 & 3) * -8 + 0x20,
               1,param_1,uVar1);
    Animation_RegisterAll(uRam020636b8,iVar5,param_1);
    Animation_SetLoop(uRam020636b8,0,1);
    Animation_SetAt(uRam020636b8,0);
  }
  Model_Render(*(uint *)((uint)puRam020636a8 & 0xfffffffc) >> ((uint)puRam020636a8 & 3) * 8 |
               *(uint *)((uint)puRam020636a8 & 0xfffffffc) << ((uint)puRam020636a8 & 3) * -8 + 0x20,
               8);
  ModelBlock_SetSomethingToAllMaterials_MaybeTraslucent(iVar4,1);
  uVar7 = *(uint *)(uRam020636bc & 0xfffffffc) >> (uRam020636bc & 3) * 8 |
          *(uint *)(uRam020636bc & 0xfffffffc) << (uRam020636bc & 3) * -8 + 0x20;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if (uVar8 == 0xc) {
    uVar8 = iVar4 + 8U & 3;
    uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    iVar6 = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,uRam020636c0
                         );
    if (-1 < iVar6) {
      func_02013468(iVar4,iVar6,0x1e);
      ModelBlock_SomeTexPltFn(iVar4,iVar6,0);
    }
  }
  else if (uVar8 == 0x16) {
    uVar8 = iVar4 + 8U & 3;
    uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    iVar6 = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,uRam020636c4
                         );
    if (-1 < iVar6) {
      ModelBlock_SomeTexPltFn(iVar4,iVar6,0);
    }
    uVar8 = iVar4 + 8U & 3;
    uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    iVar6 = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,uRam020636c8
                         );
    if (-1 < iVar6) {
      ModelBlock_SomeTexPltFn(iVar4,iVar6,0);
    }
  }
  uVar1 = uRam020636cc;
  puRam020636a8[1] = 0;
  iVar6 = FindFileBuffer_CRS_CST_from_thumb(uVar1);
  uVar1 = FindFileBuffer_CRS_CST_from_thumb(uRam020636d0);
  if (iVar6 != 0) {
    uVar2 = Mem_AllocateHeap(param_1,0x6c);
    puRam020636a8[1] = uVar2;
    Model_CreateFromNsbmdNsbtxMetaCopy(param_1,uVar2,iVar6,uVar1);
    uVar8 = (uint)(puRam020636a8 + 1) & 3;
    uVar7 = *(uint *)((uint)(puRam020636a8 + 1) & 0xfffffffc);
    Model_Render(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,8);
    uVar10 = FindFileBuffer_CRS_CST_from_thumb(uRam020636d4);
    uVar9 = (undefined2)((uint6)uVar10 >> 0x20);
    iVar5 = (int)uVar10;
    if (iVar5 == 0) {
      uVar9 = 0;
    }
    uVar8 = (uint)(puRam020636a8 + 1) & 3;
    uVar7 = *(uint *)((uint)(puRam020636a8 + 1) & 0xfffffffc);
    if (iVar5 == 0) {
      *(undefined2 *)(puRam020636a8 + 0x24) = uVar9;
    }
    else {
      Animation_CreateFrom
                (1,uRam020636d8,uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,1,param_1,iVar6);
      Animation_RegisterAll(uRam020636d8,iVar5,param_1);
      Animation_SetLoop(uRam020636d8,0,1);
      Animation_SetAt(uRam020636d8,0);
    }
  }
  uVar8 = iVar4 + 8U & 3;
  uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  local_30[0] = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,
                              uRam020636dc);
  uVar8 = iVar4 + 8U & 3;
  uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  local_30[1] = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,
                              uRam020636e0);
  uVar8 = iVar4 + 8U & 3;
  uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  local_30[2] = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,
                              uRam020636e4);
  uVar8 = iVar4 + 8U & 3;
  uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  local_30[3] = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,
                              uRam020636e8);
  uVar8 = iVar4 + 8U & 3;
  uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  local_20 = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,
                           uRam020636ec);
  uVar8 = iVar4 + 8U & 3;
  uVar7 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  local_1c = Dict_SomeFn_0(iVar4 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4,
                           uRam020636f0);
  iVar6 = 0;
  do {
    if (-1 < local_30[iVar6]) {
      ModelBlock_SomeTexPltFn_3(iVar4,local_30[iVar6],7);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 6);
  Matrix4x3_Identity(uRam020636f4);
  func_0206302c();
  return;
}

