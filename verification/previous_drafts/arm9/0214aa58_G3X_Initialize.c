/* Decompiled C draft; module arm9; ROM address 0214aa58. No matching claim. */
#include "types.h"
#include "deps/0214aa58_G3X_Initialize.h"

void G3X_Initialize(void)

{
  ushort uVar1;
  uint *puVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  
  G3X_ClearFifo();
  *puRam0214ab70 = 0;
  puVar3 = puRam0214ab78;
  puVar2 = puRam0214ab74;
  do {
  } while (((*(uint *)((uint)puRam0214ab74 & 0xfffffffc) >> ((uint)puRam0214ab74 & 3) * 8 |
            *(uint *)((uint)puRam0214ab74 & 0xfffffffc) << ((uint)puRam0214ab74 & 3) * -8 + 0x20) &
           0x8000000) != 0);
  *puRam0214ab78 = 0;
  puVar4 = puRam0214ab7c;
  *puVar2 = 0;
  *puVar4 = 0;
  uVar5 = uRam0214ab84;
  uVar1 = (ushort)uRam0214ab80;
  *puVar3 = *puVar3 | 0x2000;
  *puVar3 = *puVar3 | 0x1000;
  *puVar3 = *puVar3 & uVar1;
  *puVar3 = *puVar3 & 0xcfff | 0x10;
  *puVar3 = (ushort)uVar5 & *puVar3;
  *puVar2 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20 | 0x8000;
  *puVar2 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0x3fffffff |
            0x80000000;
  G3X_InitializeMatrixStack();
  puVar6 = puRam0214ab90;
  uVar5 = uRam0214ab8c;
  *puRam0214ab88 = 0;
  puVar7 = puRam0214ab94;
  *puVar6 = (short)uVar5;
  puVar4 = puRam0214ab98;
  *puVar7 = 0;
  puVar6 = puRam0214ab9c;
  *puVar4 = 0;
  puVar3 = puRam0214aba0;
  *puVar6 = 0;
  *puVar3 = *puVar3 & 0xfffc;
  G3X_InitializeTable();
  puVar4 = puRam0214abac;
  *puRam0214aba8 = uRam0214aba4;
  puVar8 = puRam0214abb0;
  *puVar4 = 0;
  *puVar8 = 0;
  return;
}

