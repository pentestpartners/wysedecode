// Basic C code to decrypt Wyse password for decoding
// Reverse engineering and C mangulation by David Lodge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void NFuseDecode(unsigned char *src, int length, unsigned char *dst)
{
   unsigned char a;
   int i;

   length/=2;

   for (i=0; i<length; i++)
   {
      a=src[i*2];
      a-=1;
      a<<=4;
      a+=src[i*2+1];
      a-=0x41;
      dst[i]=a;
   }

   for (i=length; i>=0; i--)
   {
      a=dst[i-1];
      a^=dst[i];
      a^=0xA5;
      dst[i]=a;
   }
   dst[length]='\0';
}

void main(int argc, char **argv)
{
   unsigned char buffer[256];
   int i;

   NFuseDecode(argv[1], strlen(argv[1]), buffer);
   printf("%s\n", buffer);
}
