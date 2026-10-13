/* Decompiled C draft; module arm9; ROM address 0205a92c. No matching claim. */
#include "types.h"
#include "deps/0205a92c_func_0205a92c.h"

void func_0205a92c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar6 = 0;
  local_2c = 0;
  local_30 = 0;
  do {
    uVar1 = func_0x0219bb50();
    if (((uVar6 != uVar1) &&
        (uVar1 = *(uint *)(uRam0205aa54 & 0xfffffffc) >> (uRam0205aa54 & 3) * 8 |
                 *(uint *)(uRam0205aa54 & 0xfffffffc) << (uRam0205aa54 & 3) * -8 + 0x20,
        ((uint)*(byte *)(uVar1 + 0x749) & 1 << uVar6) != 0)) &&
       ((int)((uint)*(byte *)(uVar6 * 0x88 + uVar1 + 0x18a) << 0x1f) < 0)) {
      uVar1 = local_30;
      do {
        uVar2 = *(uint *)(uRam0205aa54 & 0xfffffffc) >> (uRam0205aa54 & 3) * 8 |
                *(uint *)(uRam0205aa54 & 0xfffffffc) << (uRam0205aa54 & 3) * -8 + 0x20;
        iVar5 = uVar1 * 0x30 + uVar2 + 0x3e4 + uVar6 * 0xc;
        pcVar4 = (char *)(uVar2 + iRam0205aa58 + uVar1 * 4 + uVar6);
        if (*(char *)(iVar5 + 9) == '\x0f') {
          *pcVar4 = '\0';
        }
        else if (*pcVar4 == '\0') {
          func_0205b954(uVar6);
          uVar2 = local_2c;
          if (*(char *)(iVar5 + 0xb) != '\0') {
            uVar2 = iVar5 + 4U & 3;
            uVar3 = *(uint *)(iVar5 + 4U & 0xfffffffc);
            uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
          }
          if (*(byte *)(iVar5 + 10) < 2) {
            func_0205a630(uVar6);
          }
          func_020fe5b8(*(undefined1 *)(iVar5 + 9),*(undefined1 *)(iVar5 + 10),(byte *)(uintptr_t)(uVar2),
                        (int)*(char *)(uVar6 + (*(uint *)(uRam0205aa5c & 0xfffffffc) >>
                                                (uRam0205aa5c & 3) * 8 |
                                               *(uint *)(uRam0205aa5c & 0xfffffffc) <<
                                               (uRam0205aa5c & 3) * -8 + 0x20) + 6));
          *pcVar4 = '\x01';
        }
        uVar1 = uVar1 + 1 & 0xffff;
      } while (uVar1 < 0x10);
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 4);
  return;
}

