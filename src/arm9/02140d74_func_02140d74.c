/* Decompiled C draft; module arm9; ROM address 02140d74. No matching claim. */
#include "types.h"
#include "deps/02140d74_func_02140d74.h"

void func_02140d74(uint *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  undefined8 uVar6;
  int local_90;
  int local_8c;
  uint local_88;
  undefined8 local_7c;
  undefined1 auStack_74 [38];
  undefined1 auStack_4e [38];
  undefined4 local_c;
  undefined4 local_8;
  
  uVar6 = CONCAT44(param_3,param_2);
  uVar2 = (uint)((param_3 & 0x80000000) != 0);
  iVar1 = FUN_02131bfc(0,0,param_2,param_3);
  if (iVar1 != 0) {
    uVar2 = uVar2 | (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                    0xffffff00;
    uVar3 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
    *param_1 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
    *(undefined2 *)((int)param_1 + 2) = 0;
    puVar5 = param_1 + 1;
    uVar3 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffff00 | 1
    ;
    uVar2 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
    param_1 = (uint *)((int)param_1 + 5);
    *puVar5 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    uVar3 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
    uVar2 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
    *param_1 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    return;
  }
  if ((param_3 & uRam021410b4) == 0) {
    if (((param_3 & uRam021410b8) == 0) && (param_2 == 0)) {
      uVar3 = 3;
    }
    else {
      uVar3 = 5;
    }
  }
  else if ((param_3 & uRam021410b4) == uRam021410b4) {
    if (((param_3 & uRam021410b8) == 0) && (param_2 == 0)) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 4;
  }
  if (2 < uVar3) {
    local_8c = param_2;
    local_88 = param_3;
    if (uVar2 != 0) {
      uVar6 = func_02130ccc(0,0,param_2,param_3);
    }
    local_8 = (undefined4)((ulonglong)uVar6 >> 0x20);
    local_c = (undefined4)uVar6;
    local_7c = func_021400ec(local_c,local_8,&local_90);
    uVar3 = (uint)((ulonglong)local_7c >> 0x20);
    iVar1 = (int)local_7c;
    if (iVar1 == 0) {
      iVar4 = func_021422a0(uVar3 | 0x100000);
      iVar4 = iVar4 + 0x20;
    }
    else {
      iVar4 = func_021422a0();
    }
    func_0214177c((undefined2 *)(void *)(auStack_4e),local_90 - (0x35 - iVar4));
    func_021401ac(iVar1,uVar3,0x35 - iVar4);
    uVar6 = func_02130198();
    func_02141f14((uint *)(void *)(auStack_74),(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
    func_02141c98(param_1,(int)(uintptr_t)(auStack_74),(int)(uintptr_t)(auStack_4e));
    uVar2 = uVar2 | (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                    0xffffff00;
    uVar3 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
    *param_1 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
    return;
  }
  uVar2 = uVar2 | (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                  *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                  0xffffff00;
  uVar3 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
  *param_1 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
  *(undefined2 *)((int)param_1 + 2) = 0;
  puVar5 = param_1 + 1;
  uVar3 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
          *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffff00 | 1;
  uVar2 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
  *puVar5 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
  uVar2 = param_3 & uRam021410b4;
  if (uVar2 == 0) {
    if (((param_3 & uRam021410b8) == 0) && (param_2 == 0)) {
      iVar1 = 3;
    }
    else {
      iVar1 = 5;
    }
  }
  else if (uVar2 == uRam021410b4) {
    if (((param_3 & uRam021410b8) == 0) && (param_2 == 0)) {
      iVar1 = 2;
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 4;
  }
  param_1 = (uint *)((int)param_1 + 5);
  if (iVar1 == 1) {
    uVar2 = 0x4e;
  }
  if (iVar1 != 1) {
    uVar2 = 0x49;
  }
  uVar3 = uVar2 & 0xff |
          (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
  uVar2 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
  *param_1 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
  return;
}

