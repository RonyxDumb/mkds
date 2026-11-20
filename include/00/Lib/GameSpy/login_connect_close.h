#pragma once

#include "types.h"


#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/send_buffer.h"

void gpiDisconnect(GPConnection *connection, s32 tellServer);
s32 gpiDisconnectCleanupProfile(GPConnection *connection, GPIProfile *profile, void *data);
