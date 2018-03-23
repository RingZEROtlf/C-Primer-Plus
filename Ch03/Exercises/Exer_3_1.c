#include <stdio.h>
#include <stdint.h>

int main()
{
    int8_t i8_num = INT8_MAX;
    printf("int8_t number %hhd is %hhd when overflowed.\n", i8_num, i8_num + 1);
    uint8_t ui8_num = UINT8_MAX;
    printf("uint8_t number %hhu is %hhu when overflowed.\n", ui8_num, ui8_num + 1);
    int16_t i16_num = INT16_MAX;
    printf("int16_t number %hd is %hd when overflowed.\n", i16_num, i16_num + 1);
    uint16_t ui16_num = UINT16_MAX;
    printf("uint16_t number %hu is %hu when overflowed.\n", ui16_num, ui16_num + 1);
    int32_t i32_num = INT32_MAX;
    printf("int32_t number %d is %d when overflowed.\n", i32_num, i32_num + 1);
    uint32_t ui32_num = UINT32_MAX;
    printf("uint32_t number %u is %u when overflowed.\n", ui32_num, ui32_num + 1);
    int64_t i64_num = INT64_MAX;
    printf("int64_t number %lld is %lld when overflowed.\n", i64_num, i64_num + 1);
    uint64_t ui64_num = UINT64_MAX;
    printf("uint64_t number %llu is %llu when overflowed.\n", ui64_num, ui64_num + 1);
    
    float single_max;
    int32_t *p_single_max = (int32_t *)&single_max;
    *p_single_max = 0x7f7fffff;
    printf("single precision number %e is %f when overflowed.\n", single_max, (float)(single_max * 2.0));

    float single_min;
    int32_t *p_single_min = (int32_t *)&single_min;
    *p_single_min = 0x00000001;
    printf("single precision number %e is %e when underflowed.\n", single_min, (float)(single_min / 2.0));

    double double_max;
    int64_t *p_double_max = (int64_t *)&double_max;
    *p_double_max = 0x7fefffffffffffff;
    printf("double precision number %e is %e when overflowed.\n", double_max, double_max * 2.0);
    
    double double_min;
    int64_t *p_double_min = (int64_t *)&double_min;
    *p_double_min = 0x0000000000000001;
    printf("single precision number %e is %e when underflowed.\n", double_min, double_min / 2.0);

    return 0;
}

