#pragma once

typedef struct
{
    u8 field0;
    u8 field1;
    u8 field2;
} ghost_time_t;

typedef struct
{
    u32 signature;

    u32 character : 4;
    u32 kart : 6;
    u32 course : 6;
    u32 : 16;

    u32 isValid : 1;
    u32 flagsBit1 : 1;
    u32 flagsBit2_3 : 2;
    u32 : 4;
    u32 minutes : 7;
    u32 seconds : 7;
    u32 milliseconds : 10;

    u16 nickname[10];
    ghost_time_t lapTimes[5];
    u8 field2F : 2;
} ghost_header_t;

typedef struct
{
    ghost_header_t header;
    u8 emblem[0x200];
} ghost_header_ex_t;