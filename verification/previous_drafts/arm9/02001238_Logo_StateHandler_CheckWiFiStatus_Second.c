/* Decompiled C draft; module arm9; ROM address 02001238. No matching claim. */
#include "types.h"
#include "deps/02001238_Logo_StateHandler_CheckWiFiStatus_Second.h"

void Logo_StateHandler_CheckWiFiStatus_Second(void)

{
  uint uVar1;
  
  if ((*(uint *)(uRam02001288 & 0xfffffffc) >> (uRam02001288 & 3) * 8 |
      *(uint *)(uRam02001288 & 0xfffffffc) << (uRam02001288 & 3) * -8 + 0x20) == 3) {
    uVar1 = *(uint *)(uRam0200128c & 0xfffffffc) >> (uRam0200128c & 3) * 8 |
            *(uint *)(uRam0200128c & 0xfffffffc) << (uRam0200128c & 3) * -8 + 0x20;
    *(undefined2 *)(uVar1 + 0x28) = 9;
    *(undefined2 *)(uVar1 + 0x2a) = 1;
    return;
  }
  uVar1 = *(uint *)(uRam0200128c & 0xfffffffc) >> (uRam0200128c & 3) * 8 |
          *(uint *)(uRam0200128c & 0xfffffffc) << (uRam0200128c & 3) * -8 + 0x20;
  *(undefined2 *)(uVar1 + 0x28) = 0xb;
  *(undefined2 *)(uVar1 + 0x2a) = 1;
  return;
}

