/* Decompiled C draft; module arm9_ov000; ROM address 021a9aa0. No matching claim. */
#include "types.h"
#include "deps/021a9aa0_FUN_021a9aa0.h"

undefined1 FUN_021a9aa0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  
  piVar7 = *(int **)(param_1 + 0xc);
  piVar1 = *(int **)((int)piVar7 + DAT_021a9c40);
  if (piVar1 == (int *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *piVar1;
  }
  uVar2 = FUN_021ab5bc();
  *(char *)(piVar7 + 10) = (char)((uint)uVar2 >> 0x18);
  *(char *)((int)piVar7 + 0x29) = (char)((uint)uVar2 >> 0x10);
  *(char *)((int)piVar7 + 0x2a) = (char)((uint)uVar2 >> 8);
  *(char *)((int)piVar7 + 0x2b) = (char)uVar2;
  FUN_021a9ca8(piVar7 + 0xb,0x1c);
  puVar3 = (undefined1 *)(*(code *)*DAT_021a9c44)(iVar8 + 0x9d);
  if (puVar3 == (undefined1 *)0x0) {
    *(undefined1 *)((int)piVar7 + DAT_021a9c48) = 9;
    return 1;
  }
  puVar3[5] = 2;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[8] = 0x46;
  puVar3[9] = 3;
  puVar3[10] = 0;
  func_0x0214d1fc(piVar7 + 10,puVar3 + 0xb,0x20);
  puVar3[0x2b] = 0x20;
  if (*piVar7 == 0) {
    FUN_021a9ca8(puVar3 + 0x2c,0x1c);
    iVar5 = *DAT_021a9c4c;
    puVar3[0x48] = (char)((uint)iVar5 >> 0x18);
    puVar3[0x49] = (char)((uint)iVar5 >> 0x10);
    puVar3[0x4a] = (char)((uint)iVar5 >> 8);
    puVar3[0x4b] = (char)iVar5;
    iVar5 = FUN_021ab5e4(puVar3 + 0x2c);
    *piVar7 = iVar5;
    *DAT_021a9c4c = *DAT_021a9c4c + 1;
    *(undefined1 *)(piVar7 + 1) = 0;
  }
  else {
    func_0x0214d1fc(*piVar7,puVar3 + 0x2c);
    *(undefined1 *)(piVar7 + 1) = 1;
  }
  puVar3[0x4c] = (char)((ushort)*(undefined2 *)((int)piVar7 + 6) >> 8);
  puVar3[0x4d] = (char)*(undefined2 *)((int)piVar7 + 6);
  puVar6 = puVar3 + 0x4f;
  puVar3[0x4e] = 0;
  if ((char)piVar7[1] == '\0') {
    if (iVar8 != 0) {
      *puVar6 = 0xb;
      iVar5 = iVar8 + 6;
      puVar3[0x50] = (char)((uint)iVar5 >> 0x10);
      puVar3[0x51] = (char)((uint)iVar5 >> 8);
      puVar3[0x52] = (char)iVar5;
      iVar5 = iVar8 + 3;
      puVar3[0x53] = (char)((uint)iVar5 >> 0x10);
      puVar3[0x54] = (char)((uint)iVar5 >> 8);
      puVar3[0x55] = (char)iVar5;
      puVar3[0x56] = (char)((uint)iVar8 >> 0x10);
      puVar3[0x57] = (char)((uint)iVar8 >> 8);
      puVar3[0x58] = (char)iVar8;
      func_0x0214d1fc(piVar1[1],puVar3 + 0x59,iVar8);
      puVar6 = puVar3 + 0x59 + iVar8;
    }
    *puVar6 = 0xe;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar4 = puVar6 + 3;
    puVar6 = puVar6 + 4;
    *puVar4 = 0;
  }
  iVar8 = ((int)puVar6 - (int)puVar3) + -5;
  *puVar3 = 0x16;
  puVar3[1] = 3;
  puVar3[2] = 0;
  puVar3[3] = (char)((uint)iVar8 >> 8);
  puVar3[4] = (char)iVar8;
  FUN_021abca0((int)piVar7 + DAT_021a9c50,puVar3 + 5,iVar8);
  FUN_021ab728((int)piVar7 + DAT_021a9c54,puVar3 + 5,iVar8);
  FUN_021adcec(puVar3,(int)puVar6 - (int)puVar3,0,0,param_1);
  (*(code *)*DAT_021a9c58)(puVar3);
  return (char)piVar7[1];
}

