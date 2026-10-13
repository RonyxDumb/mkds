/* Decompiled C draft; module arm9; ROM address 0208adc8. No matching claim. */
#include "types.h"
#include "deps/0208adc8_LightInfo_SomeFn.h"

void LightInfo_SomeFn(ushort *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if ((param_2 & 1 << (uVar3 & 0xff)) != 0) break;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 4);
  uVar2 = (*(uint *)(uRam0208ae5c & 0xfffffffc) >> (uRam0208ae5c & 3) * 8 |
          *(uint *)(uRam0208ae5c & 0xfffffffc) << (uRam0208ae5c & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *param_1 = *(ushort *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + uVar3 * 2 + 0x18);
  param_1[7] = (ushort)(1 << (uVar3 & 0xff));
  param_1[1] = *param_1 & 0x1f;
  param_1[2] = (ushort)((int)(uint)*param_1 >> 5) & 0x1f;
  param_1[3] = (ushort)((int)(uint)*param_1 >> 10) & 0x1f;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0x1000;
  return;
}

