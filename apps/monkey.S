    .global MONKEY_SUZANNE_OFFSET;
    .global MONKEY_SUZANNE_SIZE;
    .global MONKEY_ALBEDO_S3TC_OFFSET;
    .global MONKEY_ALBEDO_S3TC_SIZE;
    .global MONKEY_ROUGHNESS_OFFSET;
    .global MONKEY_ROUGHNESS_SIZE;
    .global MONKEY_METALLIC_OFFSET;
    .global MONKEY_METALLIC_SIZE;
    .global MONKEY_AO_OFFSET;
    .global MONKEY_AO_SIZE;
    .global MONKEY_NORMAL_OFFSET;
    .global MONKEY_NORMAL_SIZE;

    .global MONKEY_PACKAGE
    .section .rodata
MONKEY_PACKAGE:
    .incbin "monkey.bin"
MONKEY_SUZANNE_OFFSET:
    .int 0
MONKEY_SUZANNE_SIZE:
    .int 272768
MONKEY_ALBEDO_S3TC_OFFSET:
    .int 272768
MONKEY_ALBEDO_S3TC_SIZE:
    .int 699172
MONKEY_ROUGHNESS_OFFSET:
    .int 971940
MONKEY_ROUGHNESS_SIZE:
    .int 1398209
MONKEY_METALLIC_OFFSET:
    .int 2370149
MONKEY_METALLIC_SIZE:
    .int 1398209
MONKEY_AO_OFFSET:
    .int 3768358
MONKEY_AO_SIZE:
    .int 1398209
MONKEY_NORMAL_OFFSET:
    .int 5166567
MONKEY_NORMAL_SIZE:
    .int 1065180

