/* Decompiled C draft; module arm9; ROM address 020d4a20. No matching claim. */
#include "types.h"
#include "deps/020d4a20_func_020d4a20.h"

int func_020d4a20(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  
  piVar2 = piRam020d4bd4;
  *piRam020d4bd4 = param_5 << 4;
  piVar3 = piRam020d4bd8;
  *piRam020d4bd8 = param_5 << 4;
  piVar2[1] = param_6 << 4;
  piVar3[1] = param_6 << 4;
  piVar2[8] = param_5;
  piVar2[9] = 0;
  param_3 = -param_3;
  piVar2[10] = param_3;
  lVar7 = Multiply64(param_3,param_3 >> 0x1f,param_3,param_3 >> 0x1f);
  iVar4 = param_5 >> 0x1f;
  lVar8 = Multiply64(param_5,iVar4,param_5,iVar4);
  lVar9 = Multiply64(0,0,0,0);
  lVar7 = lVar7 + lVar8 + lVar9;
  if ((int)(uint)((uint)lVar7 < 0x10) <= (int)((ulonglong)lVar7 >> 0x20)) {
    Vector3_MaybeNormalize(uRam020d4bdc,uRam020d4bdc);
  }
  piVar2 = piRam020d4bd4;
  if (*(char *)(*piRam020d4be0 + 0x57) != '\0') {
    piRam020d4bd4[8] = -piRam020d4bd4[8];
    piVar2[9] = -piVar2[9];
    piVar2[10] = -piVar2[10];
  }
  piVar2 = piRam020d4bd4;
  iVar1 = -param_5;
  piRam020d4bd4[0xb] = iVar1;
  piVar2[0xc] = 0;
  piVar2[0xd] = param_4;
  lVar7 = Multiply64(param_4,param_4 >> 0x1f,param_4,param_4 >> 0x1f);
  iVar5 = iVar1 >> 0x1f;
  lVar8 = Multiply64(iVar1,iVar5,iVar1,iVar5);
  lVar9 = Multiply64(0,0,0,0);
  lVar7 = lVar7 + lVar8 + lVar9;
  if ((int)(uint)((uint)lVar7 < 0x10) <= (int)((ulonglong)lVar7 >> 0x20)) {
    Vector3_MaybeNormalize(uRam020d4be4,uRam020d4be4);
  }
  piVar2 = piRam020d4bd4;
  if (*(char *)(*piRam020d4be0 + 0x57) != '\0') {
    piRam020d4bd4[0xb] = -piRam020d4bd4[0xb];
    piVar2[0xc] = -piVar2[0xc];
    piVar2[0xd] = -piVar2[0xd];
  }
  piVar2 = piRam020d4bd4;
  piRam020d4bd4[0xe] = 0;
  piVar2[0xf] = iVar1;
  piVar2[0x10] = param_1;
  lVar7 = Multiply64(param_1,param_1 >> 0x1f,param_1,param_1 >> 0x1f);
  lVar8 = Multiply64(0,0,0,0);
  lVar9 = Multiply64(iVar1,iVar5,iVar1,iVar5);
  lVar7 = lVar7 + lVar8 + lVar9;
  if ((int)(uint)((uint)lVar7 < 0x10) <= (int)((ulonglong)lVar7 >> 0x20)) {
    Vector3_MaybeNormalize(uRam020d4be8,uRam020d4be8);
  }
  piVar2 = piRam020d4bd4;
  piRam020d4bd4[0x11] = 0;
  piVar2[0x12] = param_5;
  param_2 = -param_2;
  piVar2[0x13] = param_2;
  lVar7 = Multiply64(param_2,param_2 >> 0x1f,param_2,param_2 >> 0x1f);
  lVar8 = Multiply64(0,0,0,0);
  lVar9 = Multiply64(param_5,iVar4,param_5,iVar4);
  lVar7 = lVar7 + lVar8 + lVar9;
  uVar6 = (uint)lVar7;
  iVar4 = uVar6 - 0x10;
  if ((int)(uint)(uVar6 < 0x10) <= (int)((ulonglong)lVar7 >> 0x20)) {
    iVar4 = Vector3_MaybeNormalize(uRam020d4bec,uRam020d4bec);
  }
  return iVar4;
}

