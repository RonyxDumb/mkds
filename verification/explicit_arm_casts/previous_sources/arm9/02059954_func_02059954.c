/* Decompiled C draft; module arm9; ROM address 02059954. No matching claim. */
#include "types.h"
#include "deps/02059954_func_02059954.h"

void func_02059954(byte *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  
  iVar6 = DAT_02059b18;
  iVar3 = DAT_02059b10;
  iVar5 = DAT_02059b00 * (uint)*param_1;
  piVar4 = (int *)*DAT_02059b04;
  bVar1 = false;
  if (piVar4 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar4;
  }
  if (iVar2 == 1) {
    uVar8 = (uint)param_1[1];
    iVar2 = uVar8 << 5;
  }
  else {
    uVar8 = (uint)param_1[1];
    iVar2 = DAT_02059b0c * uVar8;
  }
  switch(uVar8) {
  case 0xfc:
    *(undefined1 *)((int)piVar4 + DAT_02059b1c + iVar5) = 0;
    bVar1 = true;
    break;
  case 0xfd:
    if (piVar4 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar4;
    }
    if (iVar3 == 1) {
      *(byte *)((int)piVar4 + DAT_02059b18) =
           *(byte *)((int)piVar4 + DAT_02059b18) | (byte)(1 << (uint)*param_1);
      iVar3 = *DAT_02059b04;
      if (*(byte *)(iVar3 + 0x87) == (*(byte *)(iVar3 + 0x87) & *(byte *)(iVar3 + iVar6))) {
        iVar3 = iVar3 + DAT_02059b10;
        *(undefined2 *)(iVar3 + 0x10) = 10;
        *(undefined2 *)(iVar3 + 0x12) = 1;
      }
    }
    break;
  case 0xfe:
    if (piVar4 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar4;
    }
    if (iVar3 == 2) {
      *(char *)((int)piVar4 + DAT_02059b14) = (char)*(undefined2 *)(param_1 + 2);
    }
    break;
  case 0xff:
    if (piVar4 == (int *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *piVar4;
    }
    if (iVar6 == 2) {
      *(undefined2 *)((int)piVar4 + DAT_02059b10 + 0x10) = 9;
      *(undefined2 *)((int)piVar4 + iVar3 + 0x12) = 1;
    }
    break;
  default:
    Mem_CpuCopy8(param_1 + 4,(int)piVar4 + iVar2 + iVar5 + DAT_02059b08,*(undefined2 *)(param_1 + 2)
                );
    *(undefined1 *)(*(int *)(*DAT_02059b04 + (uint)*param_1 * 4 + DAT_02059b20) + (uint)param_1[1])
         = 1;
    iVar3 = func_02059b28(*param_1);
    if (iVar3 != 0) {
      bVar1 = true;
    }
  }
  iVar3 = DAT_02059b18;
  if (bVar1) {
    piVar4 = (int *)*DAT_02059b04;
    if (piVar4 == (int *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *piVar4;
    }
    if (iVar6 == 1) {
      iVar3 = func_020586ac(0xff,0,0,0,1 << *param_1 & 0xff);
      if (iVar3 != 0) {
        *(byte *)(*DAT_02059b04 + DAT_02059b18) =
             *(byte *)(*DAT_02059b04 + DAT_02059b18) | (byte)(1 << *param_1);
        return;
      }
    }
    else {
      *(byte *)((int)piVar4 + DAT_02059b18) =
           *(byte *)((int)piVar4 + DAT_02059b18) | (byte)(1 << *param_1);
      piVar4 = (int *)*DAT_02059b04;
      if (*(byte *)((int)piVar4 + DAT_02059b14) ==
          (*(byte *)((int)piVar4 + DAT_02059b14) & *(byte *)((int)piVar4 + iVar3))) {
        if (*piVar4 == 2) {
          uVar7 = *(ushort *)((int)piVar4 + DAT_02059b24);
        }
        else {
          uVar7 = 0;
        }
        iVar3 = func_020586ac(0xfd,0,0,uVar7 & 0xff,1);
        if (iVar3 != 0) {
          iVar3 = *DAT_02059b04 + DAT_02059b10;
          *(undefined2 *)(iVar3 + 0x10) = 10;
          *(undefined2 *)(iVar3 + 0x12) = 1;
        }
      }
    }
  }
  return;
}

