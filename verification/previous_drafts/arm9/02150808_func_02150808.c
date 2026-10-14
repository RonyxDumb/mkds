/* Decompiled C draft; module arm9; ROM address 02150808. No matching claim. */
#include "types.h"
#include "deps/02150808_func_02150808.h"

void func_02150808(int param_1,int param_2,int param_3,byte *param_4,int param_5)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte abStack_118 [64];
  byte abStack_d8 [64];
  byte abStack_98 [20];
  undefined1 auStack_84 [104];
  
  pbVar2 = abStack_118;
  if (param_1 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  if (param_4 != (byte *)0x0) {
    if (param_5 != 0) {
      if (0x40 < param_5) {
        func_02150d78((undefined4 *)(void *)(auStack_84));
        func_02150c1c((int)(uintptr_t)(auStack_84),(uint)(uintptr_t)(param_4),param_5);
        func_02150a10(auStack_84,abStack_98);
        param_5 = 0x14;
        param_4 = abStack_98;
      }
      iVar1 = 0;
      if (0 < param_5) {
        pbVar3 = abStack_d8;
        do {
          iVar1 = iVar1 + 1;
          *pbVar2 = *param_4 ^ 0x36;
          pbVar2 = pbVar2 + 1;
          *pbVar3 = *param_4 ^ 0x5c;
          pbVar3 = pbVar3 + 1;
          param_4 = param_4 + 1;
        } while (iVar1 < param_5);
      }
      if (iVar1 < 0x40) {
        pbVar3 = abStack_118 + iVar1;
        pbVar2 = abStack_d8 + iVar1;
        do {
          *pbVar3 = 0x36;
          iVar1 = iVar1 + 1;
          *pbVar2 = 0x5c;
          pbVar3 = pbVar3 + 1;
          pbVar2 = pbVar2 + 1;
        } while (iVar1 < 0x40);
      }
      func_02150d78((undefined4 *)(void *)(auStack_84));
      func_02150c1c((int)(uintptr_t)(auStack_84),(uint)(uintptr_t)(abStack_118),0x40);
      func_02150c1c((int)(uintptr_t)(auStack_84),param_2,param_3);
      func_02150a10(auStack_84,abStack_98);
      func_02150d78((undefined4 *)(void *)(auStack_84));
      func_02150c1c((int)(uintptr_t)(auStack_84),(uint)(uintptr_t)(abStack_d8),0x40);
      func_02150c1c((int)(uintptr_t)(auStack_84),(uint)(uintptr_t)(abStack_98),0x14);
      func_02150a10(auStack_84,param_1);
      return;
    }
    return;
  }
  return;
}

