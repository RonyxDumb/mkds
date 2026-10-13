/* Decompiled C draft; module arm9; ROM address 020e4184. No matching claim. */
#include "types.h"
#include "deps/020e4184_func_020e4184.h"

void func_020e4184(int *param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_28 [5];
  
  iVar5 = 0;
  piVar3 = local_28;
  iVar8 = 0;
  do {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  uVar1 = *(ushort *)(param_1 + 1);
  if (uVar1 != 0) {
    iVar5 = 0;
    do {
      iVar6 = *(int *)(*(int *)(*param_1 + iVar5) + DAT_020e42ec);
      if (local_28[iVar6] == 0) {
        switch(iVar6) {
        case 0:
          uVar4 = FormatFindMapObjFileBuffer_from_thumb(DAT_020e42f0);
          func_020ea588(DAT_020e42f4,uVar4,0);
          Model_SetPolygonIdLightFlagsEmi(*DAT_020e42f4,0x3f,2,DAT_020e42f8);
          break;
        case 1:
          uVar4 = FormatFindMapObjFileBuffer_from_thumb(DAT_020e42fc);
          func_020ea588(DAT_020e4300,uVar4,0);
          Model_SetPolygonIdLightFlagsEmi(*DAT_020e4300,0x3f,2,DAT_020e42f8);
          break;
        case 2:
          uVar4 = FormatFindMapObjFileBuffer_from_thumb(DAT_020e4304);
          func_020ea588(DAT_020e4308,uVar4,0);
          Model_SetPolygonIdLightFlagsEmi(*DAT_020e4308,0x3f,2,DAT_020e42f8);
          break;
        case 3:
          uVar4 = FormatFindMapObjFileBuffer_from_thumb(DAT_020e430c);
          func_020ea588(DAT_020e4310,uVar4,0);
          Model_SetPolygonIdLightFlagsEmi(*DAT_020e4310,0x3f,2,DAT_020e42f8);
          break;
        case 4:
          uVar4 = FormatFindMapObjFileBuffer_from_thumb(DAT_020e4314);
          func_020ea588(DAT_020e4318,uVar4,0);
          Model_SetPolygonIdLightFlagsEmi(*DAT_020e4318,0x3f,2,DAT_020e42f8);
        }
        local_28[iVar6] = 1;
      }
      iVar5 = iVar5 + 4;
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)uVar1);
  }
  iVar5 = DAT_020e431c;
  puVar2 = DAT_020e42f4;
  uVar1 = *(ushort *)(param_1 + 1);
  iVar8 = 0;
  if (uVar1 != 0) {
    iVar6 = 0;
    do {
      iVar7 = *(int *)(*param_1 + iVar6);
      switch(*(undefined4 *)(iVar7 + DAT_020e42ec)) {
      case 0:
        *(undefined4 *)(iVar7 + iVar5) = *puVar2;
        break;
      case 1:
        *(undefined4 *)(iVar7 + iVar5) = *DAT_020e4300;
        break;
      case 2:
        *(undefined4 *)(iVar7 + iVar5) = *DAT_020e4308;
        break;
      case 3:
        *(undefined4 *)(iVar7 + iVar5) = *DAT_020e4310;
        break;
      case 4:
        *(undefined4 *)(iVar7 + iVar5) = *DAT_020e4318;
      }
      iVar6 = iVar6 + 4;
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)uVar1);
  }
  return;
}

