/* Decompiled C draft; module arm9; ROM address 020e2fe4. No matching claim. */
#include "types.h"
#include "deps/020e2fe4_func_020e2fe4.h"

undefined1 func_020e2fe4(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_28 [2];
  int local_20;
  int local_1c [2];
  int local_14;
  
  if (*param_3 == '\x01') {
    if (param_2 == 0) {
      VecFx32_Subtract(param_1 + 4,param_1 + 4,local_1c);
      uVar1 = uRam020e3118 + 8 & 3;
      uVar5 = *(uint *)(uRam020e3118 + 8 & 0xfffffffc);
      lVar2 = (longlong)local_14 *
              (longlong)
              (int)(*(uint *)(uRam020e3118 & 0xfffffffc) >> (uRam020e3118 & 3) * 8 |
                   *(uint *)(uRam020e3118 & 0xfffffffc) << (uRam020e3118 & 3) * -8 + 0x20);
      lVar3 = (longlong)local_1c[0] *
              (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
      if ((int)((int)((ulonglong)lVar2 >> 0x20) -
               ((int)((ulonglong)lVar3 >> 0x20) + (uint)((uint)lVar2 < (uint)lVar3))) < 0) {
        *(undefined4 *)(param_1 + 0xb4) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0xb4) = 0;
      }
      *(undefined4 *)(param_1 + 0x14) = 0x4000;
      *(undefined2 *)(param_1 + 0x90) = 6;
      *(undefined2 *)(param_1 + 0x92) = 1;
      *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e3114;
    }
    else {
      VecFx32_Subtract(param_1 + 4,param_2 + 0x50,local_28);
      uVar1 = param_2 + 0x5cU & 3;
      uVar6 = *(uint *)(param_2 + 0x5cU & 0xfffffffc);
      uVar5 = param_2 + 100U & 3;
      uVar4 = *(uint *)(param_2 + 100U & 0xfffffffc);
      lVar2 = (longlong)local_20 * (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
      lVar3 = (longlong)local_28[0] *
              (longlong)(int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
      if ((int)((int)((ulonglong)lVar2 >> 0x20) -
               ((int)((ulonglong)lVar3 >> 0x20) + (uint)((uint)lVar2 < (uint)lVar3))) < 0) {
        *(undefined4 *)(param_1 + 0xb4) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0xb4) = 0;
      }
      *(undefined4 *)(param_1 + 0x14) = 0x4000;
      *(undefined2 *)(param_1 + 0x90) = 6;
      *(undefined2 *)(param_1 + 0x92) = 1;
      *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e3114;
      func_020f8ddc(param_2);
    }
  }
  return *param_4;
}

