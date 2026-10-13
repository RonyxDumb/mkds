/* Decompiled C draft; module arm9; ROM address 020ed2f8. No matching claim. */
#include "types.h"
#include "deps/020ed2f8_LoadItems_from_thumb.h"

void LoadItems_from_thumb(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  
  puVar1 = puRam020ed414;
  iVar5 = 0;
  do {
    puVar1[iVar5] = 0;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed418,0,uRam020ed41c);
  *puRam020ed414 = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed420,0,uRam020ed424);
  puRam020ed414[1] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed428,0,uRam020ed42c);
  puRam020ed414[2] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed430,0,uRam020ed434);
  puRam020ed414[3] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed438,0,uRam020ed43c);
  puRam020ed414[4] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed440,0,uRam020ed444);
  puRam020ed414[5] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed448,0,uRam020ed44c);
  puRam020ed414[6] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed450,0,uRam020ed454);
  puRam020ed414[7] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed458,uRam020ed45c,uRam020ed460);
  puRam020ed414[9] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed464,0,uRam020ed468);
  puRam020ed414[10] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed46c,0,uRam020ed470);
  puRam020ed414[0xb] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed474,0,uRam020ed478);
  puRam020ed414[0xc] = uVar3;
  uVar3 = CreateBillboardModel_from_thumb(uRam020ed47c,0,uRam020ed480);
  puVar1 = puRam020ed414;
  puRam020ed414[0xd] = uVar3;
  puVar1[8] = puVar1[7];
  piVar2 = piRam020ed488;
  puVar1 = puRam020ed414;
  iVar5 = *(int *)*puRam020ed484;
  iVar6 = 0;
  do {
    pcVar4 = *(code **)(*piVar2 + iVar6 * 0xa8 + 0x14);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)();
    }
    if (iVar5 == 0x1d) {
      *(uint *)(puVar1[iVar6] + 0x14) = *(uint *)(puVar1[iVar6] + 0x14) & uRam020ed48c;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xe);
  return;
}

