/* Decompiled C draft; module arm9; ROM address 0207564c. No matching claim. */
#include "types.h"
#include "deps/0207564c_SomeLookAtHD3.h"

int SomeLookAtHD3(void)

{
  uint uVar1;
  
  StructHD_SomeFn_0(*(uint *)(uRam0207568c & 0xfffffffc) >> (uRam0207568c & 3) * 8 |
                    *(uint *)(uRam0207568c & 0xfffffffc) << (uRam0207568c & 3) * -8 + 0x20);
  StructHD_SomeLookAt(*(uint *)(uRam0207568c & 0xfffffffc) >> (uRam0207568c & 3) * 8 |
                      *(uint *)(uRam0207568c & 0xfffffffc) << (uRam0207568c & 3) * -8 + 0x20);
  uVar1 = *(uint *)(uRam0207568c & 0xfffffffc) >> (uRam0207568c & 3) * 8 |
          *(uint *)(uRam0207568c & 0xfffffffc) << (uRam0207568c & 3) * -8 + 0x20;
  *puRam02075690 = uVar1;
  return uVar1 + 0x30;
}

