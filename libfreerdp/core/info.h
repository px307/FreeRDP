/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * RDP Client Info
 *
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __INFO_H
#define __INFO_H

#include "rdp.h"

#include <freerdp/freerdp.h>
#include <freerdp/api.h>

#include <winpr/stream.h>

/* Client Address Family */
#define ADDRESS_FAMILY_INET		0x0002
#define ADDRESS_FAMILY_INET6		0x0017

/* Client Info Packet Flags */
#define INFO_MOUSE			0x00000001
#define INFO_DISABLECTRLALTDEL		0x00000002
#define INFO_AUTOLOGON			0x00000008
#define INFO_UNICODE			0x00000010
#define INFO_MAXIMIZESHELL		0x00000020
#define INFO_LOGONNOTIFY		0x00000040
#define INFO_COMPRESSION		0x00000080
#define INFO_ENABLEWINDOWSKEY		0x00000100
#define INFO_REMOTECONSOLEAUDIO		0x00002000
#define INFO_FORCE_ENCRYPTED_CS_PDU	0x00004000
#define INFO_RAIL			0x00008000
#define INFO_LOGONERRORS		0x00010000
#define INFO_MOUSE_HAS_WHEEL		0x00020000
#define INFO_PASSWORD_IS_SC_PIN		0x00040000
#define INFO_NOAUDIOPLAYBACK		0x00080000
#define INFO_USING_SAVED_CREDS		0x00100000
#define INFO_AUDIOCAPTURE		0x00200000
#define INFO_VIDEO_DISABLE		0x00400000
#define INFO_HIDEF_RAIL_SUPPORTED	0x02000000

/* Extended Logon Info */
#define LOGON_EX_AUTORECONNECTCOOKIE	0x00000001
#define LOGON_EX_LOGONERRORS		0x00000002

#define SAVE_SESSION_PDU_VERSION_ONE 0x0001

FREERDP_LOCAL void rdp_write_auto_reconnect_cookie(rdpRdp* rdp, wStream* s);
FREERDP_LOCAL BOOL rdp_recv_client_info(rdpRdp* rdp, wStream* s);
FREERDP_LOCAL BOOL rdp_send_client_info(rdpRdp* rdp);
FREERDP_LOCAL BOOL rdp_recv_save_session_info(rdpRdp* rdp, wStream* s);
FREERDP_LOCAL BOOL rdp_send_save_session_info(rdpContext* context, UINT32 type,
        void* data);

#endif /* __INFO_H */
