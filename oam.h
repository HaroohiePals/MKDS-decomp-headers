#pragma once

typedef struct
{
    GXOamAttr oam[128];
    u16 objCount;
    u16 affineCount;
} oam_buf_t;

typedef struct
{
    oam_buf_t mainOamBuf;
    oam_buf_t subOamBuf;
} oam_buffers_t;

void oam_clearResetBuffers(oam_buf_t* main, oam_buf_t* sub);
void oam_resetBuffers(oam_buf_t* main, oam_buf_t* sub);
void oam_prepareBuffers(oam_buf_t* main, oam_buf_t* sub);
void oam_applyBuffers(oam_buf_t* main, oam_buf_t* sub);
u16 oam_getAffineCount(oam_buf_t* oamBuf);
void oam_increaseAffineCount(oam_buf_t* oamBuf);
u16 oam_getAffineId(oam_buf_t* oamBuf);
