#.org    0x00
.global copy_1to1_ipuv_start
# set shift_in/x to 1 pixels
# set shift_out to 1 pixels
# input to line 0
# in to LSB
# out from LSB
# out0 : copied input value

copy_1to1_ipuv_start:
        //mov confalu,(0 /*unsigned*/ | (1<<1) /*saturate*/ | (14<<4) /*shr*/)
        done loop,i    // load first pixel

.local loop
copy_1to1_ipuv_loop:
//	mov loopcnt,8
//delay:	nop
//	loop delay
	dout in0,loop,ixo

        halt
.global copy_1to1_ipuv_end
copy_1to1_ipuv_end:
