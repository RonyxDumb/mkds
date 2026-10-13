/* Decompiled C draft; module arm7; ROM address 03800f58. No matching claim. */
#include "types.h"
#include "deps/03800f58_FUN_03800f58.h"

void FUN_03800f58(void)

{
  int iVar1;
  uint uVar2;
  
  if ((*(uint *)((uint)DAT_0380101c & 0xfffffffc) >> ((uint)DAT_0380101c & 3) * 8 == 0 &&
       *(uint *)((uint)DAT_0380101c & 0xfffffffc) << ((uint)DAT_0380101c & 3) * -8 + 0x20 == 0) &&
     (*DAT_03801020 != 2)) {
    uVar2 = *(uint *)((uint)DAT_03801024 & 0xfffffffc) >> ((uint)DAT_03801024 & 3) * 8 |
            *(uint *)((uint)DAT_03801024 & 0xfffffffc) << ((uint)DAT_03801024 & 3) * -8 + 0x20;
    if (uVar2 == 0xffffffff) {
      *DAT_03801024 =
           (*(uint *)(DAT_03801028 & 0xfffffffc) >> (DAT_03801028 & 3) * 8 |
           *(uint *)(DAT_03801028 & 0xfffffffc) << (DAT_03801028 & 3) * -8 + 0x20) + 10;
    }
    else if (uVar2 <= (*(uint *)(DAT_03801028 & 0xfffffffc) >> (DAT_03801028 & 3) * 8 |
                      *(uint *)(DAT_03801028 & 0xfffffffc) << (DAT_03801028 & 3) * -8 + 0x20)) {
      *DAT_03801024 =
           (*(uint *)(DAT_03801028 & 0xfffffffc) >> (DAT_03801028 & 3) * 8 |
           *(uint *)(DAT_03801028 & 0xfffffffc) << (DAT_03801028 & 3) * -8 + 0x20) + 10;
      iVar1 = FUN_038010c4();
      if (((iVar1 == 0) ||
          (*DAT_0380101c = 1,
          *(uint *)((uint)DAT_0380102c & 0xfffffffc) >> ((uint)DAT_0380102c & 3) * 8 == 0 &&
          *(uint *)((uint)DAT_0380102c & 0xfffffffc) << ((uint)DAT_0380102c & 3) * -8 + 0x20 == 0))
         && (*DAT_0380102c = 0,
            *(uint *)((uint)DAT_0380101c & 0xfffffffc) >> ((uint)DAT_0380101c & 3) * 8 != 0 ||
            *(uint *)((uint)DAT_0380101c & 0xfffffffc) << ((uint)DAT_0380101c & 3) * -8 + 0x20 != 0)
         ) {
        FUN_03800ef0(0x11,100);
      }
    }
  }
  return;
}

