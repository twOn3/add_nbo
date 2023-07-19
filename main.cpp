#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

void func(uint8_t buf_1[], uint8_t buf_2[]) {
    uint32_t* p1 = reinterpret_cast<uint32_t*>(buf_1);
    uint32_t* p2 = reinterpret_cast<uint32_t*>(buf_2);

    uint32_t n1 = ntohl(*p1);
    uint32_t n2 = ntohl(*p2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);
}

int main(int argc, char *argv[]) {
    if(argc < 3){
        puts("syntax : add-nbo <file1> <file2>");
        puts("sample : add-nbo a.bin c.bin");
        return 0;
    }
    uint8_t buffer1[32], buffer2[32]; 
    FILE *f_1, *f_2;
    f_1 = fopen(argv[1], "rb");
    f_2 = fopen(argv[2], "rb");
    fread(buffer1, 1, 32, f_1); fread(buffer2, 1, 32, f_2);

    func(buffer1, buffer2);
    fclose(f_1); fclose(f_2);
}
