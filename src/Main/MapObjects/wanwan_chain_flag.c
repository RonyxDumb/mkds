#include "Main/MapObjects/wanwan_chain_flag.h"
#include "Main/MapObjects/wanwan_chain_init.h"

void ClearWanwanChainFirstLinkFlag(WanwanChain *chain) {
    chain->mFirstLinkConstrained = 0x0u;
}
