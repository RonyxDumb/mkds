/* Decompiled C draft; module arm9; ROM address 020e3ef4. No matching claim. */
#include "types.h"
#include "deps/020e3ef4_func_020e3ef4.h"

void func_020e3ef4(int param_1,int param_2,int *param_3)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  short *psVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined8 uVar9;
  
  StateDualHandler_Create(param_1 + 0x80,uRam020e40a8,4,param_1);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xc);
  puVar7 = (undefined4 *)(param_1 + 0x28);
  puVar5 = (undefined4 *)(param_1 + 0xa0);
  iVar8 = 4;
  do {
    uVar2 = *puVar7;
    uVar3 = puVar7[1];
    puVar7 = puVar7 + 2;
    *puVar5 = uVar2;
    puVar5[1] = uVar3;
    puVar5 = puVar5 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *puVar5 = *puVar7;
  puVar7 = (undefined4 *)(param_1 + 0x28);
  puVar5 = (undefined4 *)(param_1 + 0xc4);
  iVar8 = 4;
  do {
    uVar2 = *puVar7;
    uVar3 = puVar7[1];
    puVar7 = puVar7 + 2;
    *puVar5 = uVar2;
    puVar5[1] = uVar3;
    puVar5 = puVar5 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *puVar5 = *puVar7;
  *(undefined4 *)(param_1 + iRam020e40ac) = 0;
  *(undefined4 *)(param_1 + iRam020e40b0) = 0;
  *(undefined4 *)(param_1 + iRam020e40b4) = 0;
  *(uint *)(param_1 + iRam020e40b8) = (uint)(*param_3 == 0);
  *(undefined2 *)(param_1 + iRam020e40bc) = *(undefined2 *)(param_2 + 0x2c);
  *(undefined2 *)(param_1 + iRam020e40c0) = *(undefined2 *)(param_2 + 0x2a);
  *(undefined2 *)(param_1 + iRam020e40c4) = *(undefined2 *)(param_2 + 0x2e);
  sVar1 = _s32_div_f((int)*(short *)(param_2 + 0x28) << 7,100);
  iVar8 = iRam020e40c8;
  psVar6 = (short *)(param_1 + iRam020e40c8);
  *psVar6 = sVar1;
  if (*(short *)(param_2 + 0x30) != 0) {
    *psVar6 = -*(short *)(param_1 + iVar8);
  }
  *(undefined2 *)(param_1 + 0x7e) = 0;
  if (*(short *)(param_1 + iRam020e40bc) == 0) {
    *(undefined4 *)(param_1 + iRam020e40d0) = 0;
  }
  else {
    uVar2 = _s32_div_f(uRam020e40cc);
    *(undefined4 *)(param_1 + iRam020e40d0) = uVar2;
  }
  *(undefined4 *)(param_1 + iRam020e40d4) = 0;
  uVar9 = Multiply64(param_3[1],param_3[1] >> 0x1f,*(int *)(param_1 + 0x1c),
                     *(int *)(param_1 + 0x1c) >> 0x1f);
  *(uint *)(param_1 + iRam020e40d8) = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
  uVar9 = Multiply64(param_3[2],param_3[2] >> 0x1f,*(int *)(param_1 + 0x20),
                     *(int *)(param_1 + 0x20) >> 0x1f);
  *(int *)(param_1 + iRam020e40dc) =
       (int)((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14) >> 1;
  if (*param_3 == 0) {
    *(undefined4 *)(param_1 + iRam020e40e0) = 1;
    *(undefined4 *)(param_1 + iRam020e40e4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + iRam020e40e0) = 0;
    *(undefined4 *)(param_1 + iRam020e40e4) = 1;
  }
  *(undefined4 *)(param_1 + iRam020e40e8) = 0;
  *(int *)(param_1 + iRam020e40ec) = param_3[4];
  *(undefined4 *)(param_1 + iRam020e40f0) = 1;
  *(int *)(param_1 + iRam020e40f4) = param_3[5];
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e40f8;
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  piVar4 = (int *)(param_1 + iRam020e40fc);
  *piVar4 = param_3[3];
  if ((*piVar4 == 1) && (*(short *)(param_2 + 0x32) == 0)) {
    *piVar4 = 2;
  }
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  if (param_3[3] == 0) {
    uVar2 = uRam020e4104;
    if (0 < *(int *)(param_2 + 0xc)) {
      uVar2 = uRam020e4100;
    }
    *(undefined4 *)(param_1 + iRam020e4108) = uVar2;
  }
  else {
    *(int *)(param_1 + iRam020e4108) = param_3[6];
  }
  if (*(int *)(param_1 + iRam020e4108) != -1) {
    func_020d27fc(param_1);
  }
  return;
}

