/* Decompiled C draft; module arm9; ROM address 02032138. No matching claim. */
#include "types.h"
#include "deps/02032138_func_02032138.h"

void func_02032138(void)

{
  int *piVar1;
  uint *puVar2;
  ushort *puVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar2 = puRam020321f8;
  iVar5 = 0x18;
  uVar4 = 0;
  if (*(int *)(*piRam020321f4 + 0x54) != 10) {
    iVar5 = 0x1a;
    uVar4 = 3;
  }
  *puRam020321f8 = *puRam020321f8 & uRam020321fc | iVar5 << 8;
  *puRam02032200 = *puRam02032200 & 0xfffc | uVar4;
  piVar1 = piRam020321f4;
  *puRam02032208 = *(int *)(*piRam020321f4 + 0x60) * -0x10000 & uRam02032204;
  if (*(int *)(*piVar1 + 0x60) != 0) {
    *puVar2 = *puVar2 & uRam0203220c | uRam02032210;
    puVar3 = puRam02032214;
    *puRam02032214 = *puRam02032214 & 0xffc0 | 0x3f;
    *puVar3 = *puVar3 & (ushort)uRam02032218 | (ushort)uRam0203221c | (ushort)uRam02032220;
    *puRam02032224 = *puRam02032224 & 0xffc0 | 0x2d;
    uVar6 = *(undefined4 *)(*piVar1 + 0x60);
    *puRam02032228 = 0xff;
    *puRam0203222c = (short)uVar6 + 0xc0U & 0xff;
    uVar6 = *(undefined4 *)(*piVar1 + 0x60);
    *puRam02032234 = (short)uRam02032230;
    *puRam02032238 = (short)uVar6 + 0xc0U & 0xff;
    return;
  }
  *puVar2 = *puVar2 & uRam0203220c;
  return;
}

