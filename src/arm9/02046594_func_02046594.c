/* Decompiled C draft; module arm9; ROM address 02046594. No matching claim. */
#include "types.h"
#include "deps/02046594_func_02046594.h"

void func_02046594(void)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = DAT_02046644;
  cVar4 = '\x01';
  bVar2 = false;
  uVar5 = (*(uint *)(DAT_02046644 & 0xfffffffc) >> (DAT_02046644 & 3) * 8 |
          *(uint *)(DAT_02046644 & 0xfffffffc) << (DAT_02046644 & 3) * -8 + 0x20) + 0x1f0;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  switch(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    goto switchD_020465b4_default;
  case 3:
    goto switchD_020465b4_default;
  case 4:
    break;
  case 5:
    break;
  default:
    goto switchD_020465b4_default;
  }
  bVar2 = true;
switchD_020465b4_default:
  uVar5 = 0;
  do {
    if ((bVar2) ||
       (iVar6 = uVar5 * 0x30 +
                (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20), uVar7 = iVar6 + 600,
       uVar1 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
       (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) != 1)) {
      *(undefined1 *)
       (uVar5 * 0x30 +
        (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x26e) = 0xff;
    }
    else {
      *(char *)(iVar6 + 0x26e) = cVar4;
      cVar4 = cVar4 + '\x01';
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 8);
  *(char *)((*(uint *)(DAT_02046644 & 0xfffffffc) >> (DAT_02046644 & 3) * 8 |
            *(uint *)(DAT_02046644 & 0xfffffffc) << (DAT_02046644 & 3) * -8 + 0x20) + 0x3e1) = cVar4
  ;
  return;
}

