/* Little example kernel for A2I
 * use it with entry.asm and with the switch -B 0x20000
 * email: placr@mygale.org
 */

static short* video = (short *) 0xB8000;

typedef unsigned char BYTE;

static __inline__ BYTE inportb(unsigned short _port)
{
	BYTE result;
	__asm__ __volatile__
	  ("inb %1,%0" : "=a" (result) : "d" (_port));
	return result;
}

static __inline__ void outportb(unsigned short _port, BYTE _data)
{
	__asm__ __volatile__
	  ("outb %1,%0"	: : "d" (_port), "a" (_data));
}

void prints(char *s)
{
        long scrofs;
        int c;
        outportb(0x3D4, 0x0E);
        scrofs = inportb(0x3D5);
        scrofs <<= 8;
        outportb(0x3D4, 0x0F);
        scrofs += inportb(0x3D5);

        while ((c=*s++)) {
        	switch (c) {
                	case '\n':
                        	scrofs += 80;
                                scrofs = (scrofs/80)*80;
                                break;
                        default:
                        	video[scrofs++] = c + (7 << 8);
                                break;
                }
                if (scrofs > 80*25) scrofs = 0;
        }

        outportb(0x3D4, 0x0F);
        outportb(0x3D5, scrofs & 0xFF);

        for (c= 0; c < 25; c++) ; /* little delay */

        outportb(0x3D4, 0x0E);
        outportb(0x3D5, scrofs >> 8);

}

char *string_ptr = "Hello World!\n";

int main(void)
{
	int i;
	/* clear the screen */
        for (i = 0; i < 80*25; i++) video[i] = ' ' + (7 << 8);
        /* set cursor to 0, 0 */
        outportb(0x3D4, 0x0F);
        outportb(0x3D5, 0);
        for (i = 0; i < 25; i++) ; /* delay */
        outportb(0x3D4, 0x0E);
        outportb(0x3D5, 0);

	prints(string_ptr);
        prints("This little program was made with Nasm and GCC by mixing 012345678901234567890\n");
        prints("16 and 32 bits code\n\n");

	return 0;
}

