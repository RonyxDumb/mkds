#pragma once

#include "types.h"


#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_02193000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_021906e4.h"

void GpiCloseConnection(GpConnection *connection, s32 tellServer);
u32 gpiDisconnectCleanupProfile(GpConnection *connection, GpiProfile *profile);
