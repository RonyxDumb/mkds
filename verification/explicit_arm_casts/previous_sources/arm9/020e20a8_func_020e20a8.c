/* Decompiled C draft; module arm9; ROM address 020e20a8. No matching claim. */
#include "types.h"
#include "deps/020e20a8_func_020e20a8.h"

void func_020e20a8(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22a8);
  uVar3 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22ac);
  if (((*(int *)(*piRam020e22b0 + 8) == 4) || (iVar4 = func_0203c5e4(), iVar4 != 0)) ||
     (7 < *(byte *)(*piRam020e22b0 + 0x62))) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  *(undefined4 *)(param_1 + 0x38) = uVar5;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  func_020ea588(piRam020e22b4,uVar2);
  func_020ea588(piRam020e22b8,uVar3,0);
  uVar5 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22bc);
  func_020ea588(piRam020e22c0,uVar5,0);
  uVar5 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22c4);
  func_020ea588(piRam020e22c8,uVar5,0);
  uVar5 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22cc);
  func_020ea55c(uRam020e22d0,uVar5,7);
  uVar5 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22d4);
  func_020ea55c(uRam020e22d8,uVar5,7);
  uVar5 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22dc);
  func_020ea55c(uRam020e22e0,uVar5,7);
  uVar5 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22e4);
  func_020ea4bc(2,*piRam020e22b4,uRam020e22e8,uVar2,uVar5);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020e22ec);
  func_020ea4bc(2,*piRam020e22b8,uRam020e22f0,uVar3,uVar2);
  Model_SetPolygonIdLightFlagsEmi(*piRam020e22b4,0x3f,2,uRam020e22f4);
  uVar9 = 0;
  iVar4 = *(int *)(*piRam020e22b4 + 4);
  if (*(char *)(iVar4 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_3(iVar4,uVar9,7);
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(byte *)(iVar4 + 0x18));
  }
  Model_SetPolygonIdLightFlagsEmi(*piRam020e22b8,0x3f,2,uRam020e22f4);
  uVar9 = 0;
  iVar4 = *(int *)(*piRam020e22b8 + 4);
  if (*(char *)(iVar4 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_3(iVar4,uVar9,7);
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(byte *)(iVar4 + 0x18));
  }
  Model_SetPolygonIdLightFlagsEmi(*piRam020e22c0,0x3f,2,uRam020e22f4);
  uVar9 = 0;
  iVar4 = *(int *)(*piRam020e22c0 + 4);
  if (*(char *)(iVar4 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_3(iVar4,uVar9,7);
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(byte *)(iVar4 + 0x18));
  }
  Model_SetPolygonIdLightFlagsEmi(*piRam020e22c8,0x3f,2,uRam020e22f4);
  uVar9 = 0;
  iVar4 = *(int *)(*piRam020e22c8 + 4);
  if (*(char *)(iVar4 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_3(iVar4,uVar9,7);
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(byte *)(iVar4 + 0x18));
  }
  StructML_SomeFn_8(*piRam020e22c8,0);
  iVar4 = iRam020e22fc;
  uVar1 = *(ushort *)(*piRam020e22f8 + 4);
  iVar8 = 0;
  if (uVar1 != 0) {
    iVar6 = 0;
    do {
      iVar7 = *(int *)(*(int *)*piRam020e22f8 + iVar6);
      puVar10 = *(undefined4 **)(*(int *)(iVar7 + iVar4) + 0x20);
      if (puVar10 == (undefined4 *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *puVar10;
      }
      *(undefined4 *)(iVar7 + iRam020e2300) = uVar2;
      puVar10 = *(undefined4 **)(*(int *)(iVar7 + iVar4) + 0x24);
      if (puVar10 == (undefined4 *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *puVar10;
      }
      *(undefined4 *)(iVar7 + iRam020e2304) = uVar2;
      puVar10 = *(undefined4 **)(*(int *)(iVar7 + iVar4) + 0x28);
      if (puVar10 == (undefined4 *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *puVar10;
      }
      *(undefined4 *)(iVar7 + iRam020e2308) = uVar2;
      iVar6 = iVar6 + 4;
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)uVar1);
  }
  return;
}

