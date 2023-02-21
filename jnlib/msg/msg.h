#pragma once

#define JN_MSG_BMG_HEADER_MAGIC1	MKTAG('M','E','S','G')
#define JN_MSG_BMG_HEADER_MAGIC2	MKTAG('b','m','g','1')

typedef struct
{
    u32 magic1;
    u32 magic2;
    u32 fileSize;
    u32 nrSections;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1C;
} jn_msg_bmg_header_t;

typedef struct
{
    u32 magic;
    u32 size;
} jn_msg_bmg_section_header_t;

#define JN_MSG_BMG_INF1_MAGIC	MKTAG('I','N','F','1')

typedef struct
{
    jn_msg_bmg_section_header_t sectionHeader;
    u16 nrEntries;
    u16 fieldA;
    u32 fieldC;
    u32 offsets[0];
} jn_msg_bmg_inf1_t;

#define JN_MSG_BMG_DAT1_MAGIC	MKTAG('D','A','T','1')

typedef struct
{
    jn_msg_bmg_section_header_t sectionHeader;
    u16 stringData[0];
} jn_msg_bmg_dat1_t;

typedef struct
{
    jn_msg_bmg_header_t header;
    jn_msg_bmg_inf1_t inf1;
} jn_msg_bmg_t;

const u16* jn_msg_getMessage(const jn_msg_bmg_t* bmg, int idx);
