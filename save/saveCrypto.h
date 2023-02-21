#pragma once

void savc_encryptBlock(u8* data, u32 length);
BOOL savc_decryptBlock(u8* data, u32 length, u32 signature);