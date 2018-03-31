#include <stdio.h>
#include <string.h>

unsigned char to_write_1[8] = {0}, to_write_2[8] = {0}, to_write_3[8] = {0}, to_write_4[8] = {0};
unsigned char *to_write[4] = {to_write_1, to_write_2, to_write_3, to_write_4};
unsigned char Global_Key_[] =
    {
        0x4B, 0x47, 0x51, 0x40, 0x5C, 0x66, 0x19, 0x57, 0x7B, 0x43,
        0x4A, 0x13, 0x4F, 0x76, 0x7C, 0x48, 0x15, 0x49, 0x4C, 0x77,
        0x4A, 0x4E, 0x54, 0x7A, 0x56, 0x16, 0x52, 0x54};
unsigned char Global_Key[] =
    {
        0x4B, 0x47, 0x51, 0x40, 0x5C, 0x66, 0x19, 0x57, 0x7B, 0x43,
        0x4A, 0x13, 0x4F, 0x76, 0x7C, 0x48, 0x15, 0x49, 0x4C, 0x77,
        0x4A, 0x4E, 0x54, 0x7A, 0x56, 0x16, 0x52, 0x54};
unsigned char Correct_Key__[] =
    {
        0x68, 0x62, 0x76, 0x65, 0x7F, 0x48, 0x32, 0x7F, 0x56, 0x7C,
        0x63, 0x3F, 0x52, 0x65, 0x48, 0x6C, 0x4D, 0x74, 0x65, 0x20,
        0x72, 0x73, 0x4A, 0x60, 0x73, 0x7F, 0x7C, 0x65};

int __cdecl Encrypt_3(char *input, char *_to_write_, int step)
{
    int result;   // eax
    signed int i; // [esp+0h] [ebp-4h]

    for (i = 0; i < 7; ++i)
    {
        _to_write_[i] = step ^ (i + 7 * step) ^ input[7 * step + i];
        result = i + 1;
    }
    return result;
}

int __cdecl Encrypt_2(char *input, char *to_write__, char *Global_Key_, int step_)
{
    int result;   // eax
    signed int i; // [esp+0h] [ebp-4h]

    for (i = 0; i < 7; ++i)
    {
        Global_Key_[i] = Global_Key_[7 * step_ + i] ^ 0x34;
        result = i + 1;
    }
    if (step_ >= 0)
        result = Encrypt_3(input, to_write__, step_);
    return result;
}

int __cdecl Encrypt(char *input, char *Global_key_, char *to_write_, signed int step)
{
    int result;   // eax
    signed int i; // [esp+0h] [ebp-4h]

    for (i = 0; i < 7; ++i)
    {
        to_write_[i] = (i + 35) ^ Global_key_[7 * step + i];
        result = i + 1;
    }
    if (step < 35)
        result = Encrypt_2(input, to_write_, Global_Key, step);
    return result;
}

int main()
{
    unsigned char input[32] = {0};
    for (int i = 0; i < 28; i++)
    {

        int i_mod_4 = i / 7;
        //printf("%d", i_mod_4);
        for (int j = 33; j <= 128; j++)
        {
            input[i] = j;
            memcpy(Global_Key, Global_Key_, 28);
            /*Encrypt(input, Global_Key, to_write[0], 0);
            Encrypt(input, Global_Key, to_write[1], 1);
            Encrypt(input, Global_Key, to_write[2], 2);
            Encrypt(input, Global_Key, to_write[3], 3);*/
            if ((i_mod_4 ^ ((i % 7) + 7 * i_mod_4) ^ j) == (Correct_Key__ + i_mod_4 * 7)[i % 7])
            {
                printf("%c", j);
                break;
            }
        }
        //printf("%X ", (Correct_Key__ + i_mod_4 * 7)[i % 7]);
    }
    return 0;
}