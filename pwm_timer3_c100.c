// _dawnsea_
// unsigned int my_max;
static int setup_timer3(void)
{
        TCFG1_REG = (TCFG1_REG & ~((0xf) << 12)) | (0x1 << 12);

//      TCNTB3_REG = get_PCLK() / (2 * 16) * 1000 / 2;
        TCNTB3_REG = 2062500000L;  // 데이터 시트 보고 계산해봅시당~
//      my_max = TCNTB3_REG;

//      TCNTB3_REG = 0xffffffff;

        TCON_REG = (TCON_REG & ~((0xf) << 16));  // 스톱

        TCON_REG = (TCON_REG & ~((0xf) << 16)) | (4 << 16);  // 업데이트

        TCON_REG = (TCON_REG & ~((0xf) << 16)) | (0xa << 16);

        TCON_REG = (TCON_REG & ~((0xf) << 16)) | (0x9 << 16);

        return 0;
}


static int print_timer3(void)
{
        printf("\nCT = %dms\n", 1000000L - (unsigned long)TCNTO3_REG / 2063L);
        return 0;


}

