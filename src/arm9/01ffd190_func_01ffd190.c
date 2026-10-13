/* Decompiled C draft; module arm9; ROM address 01ffd190. No matching claim. */
#include "types.h"
#include "deps/01ffd190_func_01ffd190.h"

void func_01ffd190(uint param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = iRam01ffd220;
  iVar1 = (int)((uint)(param_2 << 0xf) >> 0x10) >> 4;
  iVar5 = (int)*(short *)(iRam01ffd220 + iVar1 * 4);
  lVar3 = (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * (longlong)iVar5 +
          0x800;
  *param_3 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
  uVar2 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) * (longlong)iVar5 + 0x800
  ;
  param_3[1] = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
  uVar2 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) * (longlong)iVar5 + 0x800
  ;
  param_3[2] = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
  param_3[3] = (int)*(short *)(iVar4 + (iVar1 * 2 + 1) * 2);
  return;
}

