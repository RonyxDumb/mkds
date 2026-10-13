/* Decompiled C draft; module arm9; ROM address 02086098. No matching claim. */
#include "types.h"
#include "deps/02086098_func_02086098.h"

void func_02086098(uint param_1,undefined4 *param_2,undefined4 param_3,int param_4,int param_5,
                  short param_6,int param_7,int param_8,int param_9,int param_10,code *param_11)

{
  uint uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_48 [5];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  *puRam02086230 =
       *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (*(short *)(param_1 + 8) != 0) {
    uVar1 = param_1 + 0x18 & 3;
    uVar4 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
    *puRam02086234 =
         (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >>
         (4 - (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) >> 0x1a & 7) == 2) &
         0xff);
  }
  Matrix4x3_Identity(local_48);
  local_24 = *param_2;
  local_20 = param_2[1];
  local_1c = param_2[2];
  MTX_Concat43(local_48,param_3,local_48);
  puVar3 = puRam0208623c;
  local_24 = param_7;
  uVar1 = (uint)(param_2 + 4) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 1) {
    lVar2 = (longlong)param_9 * (longlong)param_4 + 0x800;
    local_24 = param_7 + ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) + 0x1e000
    ;
  }
  lVar2 = (longlong)param_10 * (longlong)param_5 + 0x800;
  local_20 = param_8 + 0x5000 + ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000);
  local_1c = 0;
  uVar1 = param_1 + 0x1c & 3;
  uVar6 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  uVar4 = param_1 + 0x20 & 3;
  uVar5 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  local_48[4] = param_5;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_34 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  *puRam02086238 = (*(ushort *)(param_2 + 3) + 0xb) * 0x1000000 | 0xc0 | (int)param_6 << 0x10;
  *puVar3 = 2;
  local_48[0] = param_4;
  G3_LoadMtx43(local_48);
  *puRam02086240 = 1;
  *puRam02086248 = uRam02086244;
  (*param_11)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,
              uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,*(undefined2 *)((int)param_2 + 0x26));
  *puRam0208624c = 0;
  return;
}

