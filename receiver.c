#include <pic.h>
#include <dlcd.h>

unsigned char i, c, f, j, k1, k2, k3, k4, x;
unsigned char d[10];

void main() {
    TRISB = 0x00;
    TRISC = 0x80;
    TRISD = 0x00;
    PORTB = 0x00;
    RC5 = 0;
    
    lcd_init();
    delay(1000);
    print_line("Receiver", 0x80);
    delay(6500);
    delay(65000);
    RD4 = RD5 = RD6 = RD7 = 1;
    
    while (1) {
        CREN = 1;
        
        if ((d[0] == 'M' && d[1] == 'O' && d[2] == 'D' && d[3] == 'E' && d[4] == '1') && k1 < 1) {
            d[0] = d[1] = d[2] = d[3] = 0x00;
            k1++;
            k2 = k3 = k4 = 0;
            print_line("Mode 1", 0xc0);
            RD4 = 0;
            i = 20;
            while (i--) {
                delay(65000);
            }
            RD4 = 1;
        }
        
        if ((d[0] == 'M' && d[1] == 'O' && d[2] == 'D' && d[3] == 'E' && d[4] == '2') && k2 < 1) {
            d[0] = d[1] = d[2] = d[3] = 0x00;
            k2++;
            k4 = k3 = k1 = 0;
            print_line("Mode 2", 0xc0);
            RD5 = 0;
            i = 20;
            while (i--) {
                delay(65000);
            }
            RD5 = 1;
        }
        
        if ((d[0] == 'M' && d[1] == 'O' && d[2] == 'D' && d[3] == 'E' && d[4] == '3') && k3 < 1) {
            d[0] = d[1] = d[2] = d[3] = 0x00;
            k3++;
            k2 = k4 = k1 = 0;
            print_line("Mode 3", 0xc0);
            RD6 = 0;
            i = 20;
            while (i--) {
                delay(65000);
            }
            RD6 = 1;
        }
        
        if ((d[0] == 'M' && d[1] == 'O' && d[2] == 'D' && d[3] == 'E' && d[4] == '4') && k4 < 1) {
            d[0] = d[1] = d[2] = d[3] = 0x00;
            k4++;
            k2 = k3 = k1 = 0;
            print_line("Mode 4", 0xc0);
            RD7 = 0;
            i = 20;
            while (i--) {
                delay(65000);
            }
            RD7 = 1;
        }
    }
}

void interrupt isr(void) {
    if (RCIF == 1) {
        RCIF = 0;
        d[x] = RCREG;
        x++;
        x = x % 5;
        //CREN=0;
        RCREG = 0;
    }
}
