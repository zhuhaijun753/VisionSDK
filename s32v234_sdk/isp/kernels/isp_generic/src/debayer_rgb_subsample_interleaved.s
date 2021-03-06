.global debayer_rgb_subsample_interleaved_start
debayer_rgb_subsample_interleaved_start:
        done debayer_rgb_subsample_interleaved_d0,i
debayer_rgb_subsample_interleaved_d0:
        done debayer_rgb_subsample_interleaved_d1,i
debayer_rgb_subsample_interleaved_d1:

	mov confalu, (0 /* unsigned*/ | (1<<1) /*saturate*/ | (8<< 4) /* SHR: 16.0*/)   

	mov gpr0,400 // gain r
	mov gpr1,256 // gain g
	mov gpr2,490 // gain b
	
debayer_rgb_subsample_interleaved_loop0:
	mulh ina1,ina1,gpr0
	mulh ina0,ina0,gpr1
	mulh ina3,ina3,gpr2

debayer_rgb_subsample_interleaved_output:
	dout ina3,debayer_rgb_subsample_interleaved_eg,o // b
debayer_rgb_subsample_interleaved_eg:
	dout ina0,debayer_rgb_subsample_interleaved_er,o  // g
debayer_rgb_subsample_interleaved_er:
	dout ina1,debayer_rgb_subsample_interleaved_evenlodd,ixo  // r
debayer_rgb_subsample_interleaved_evenlodd:
	done debayer_rgb_subsample_interleaved_loop0,i
	
//	halt

.global debayer_rgb_subsample_interleaved_end
debayer_rgb_subsample_interleaved_end:
