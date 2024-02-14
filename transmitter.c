#include <dlcd.h>

void serial_trans1(unsigned char);
void serial_line_trans1(unsigned char const*);
unsigned char serial_recev1(void);

unsigned char R, i, j;
unsigned char k0, k1, k2, k3;

void main() {
    TRISB = 0x00;
    TRISD = 0x00;
    TRISC = 0x85;
    
    lcd_init();
    delay(1000);
    print_line(" TRANSMITTER ", 0x80);

    while (1) {
        if (RC0 == 1) {
            while (RC0 == 1);
            j++;
            j = j % 4;
        }

        if (RC2 == 1) {
            while (RC2 == 1);
            j--;
            j = j % 4;
        }

        if (j == 0) {
            print_line("MODE 1 ", 0xC0);
            serial_line_trans1("MODE1");
        }

        if (j == 1) {
            print_line("MODE 2 ", 0xC0);
            serial_line_trans1("MODE2");
        }

        if (j == 2) {
            print_line("MODE 3 ", 0xC0);
            serial_line_trans1("MODE3");
        }
    }
}

void serial_line_trans1(unsigned char const* line_dat) {
    while (*line_dat) {
        serial_trans1(*line_dat);
        line_dat++;
        delay(200);
    }
}
