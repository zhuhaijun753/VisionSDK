// IPUS kernel
// 2 input line: line 0, line 1
// starting with R
// no subsampling
// reducing by top/bottom lines & left/right column

.global debayer_rgb_simple_interleaved_start
debayer_rgb_simple_interleaved_start:
        done debayer_rgb_simple_interleaved_d0,i
debayer_rgb_simple_interleaved_d0:
//        done debayer_rgb_simple_interleaved_d1,i
//debayer_rgb_simple_interleaved_d1:
        done debayer_rgb_simple_interleaved_d2,i
debayer_rgb_simple_interleaved_d2:

	//mov confalu, (0 /* unsigned*/ | (1<<1) /*saturate*/ | (8<< 4) /* SHR: 16.0*/)   
        //
	////mov gpr1,256 // gain g
        ////mov gpr0,400 // gain r
	////mov gpr2,490 // gain b
	//mov gpr0,490 // gain r
	//mov gpr2,400 // gain b

        lsl zero,ypos,15
        bne debayer_rgb_simple_interleaved_loop_odd:

// *********************************
debayer_rgb_simple_interleaved_loop_even:
	//mulh ina3,ina3,gpr2  // B              X R G              R G X
	////mulh ina0,ina0,gpr1  // G   pixel 1  X X B     pixel 2  X B X
	//mulh ina1,ina1,gpr0  // R


	dout ina3,debayer_rgb_simple_interleaved_eg0,o          // b0
debayer_rgb_simple_interleaved_eg0:
	dout ina0,debayer_rgb_simple_interleaved_er0,o          // g0
debayer_rgb_simple_interleaved_er0:
	dout ina1,debayer_rgb_simple_interleaved_eb1,ixo        // r0
debayer_rgb_simple_interleaved_eb1:
        //done debayer_rgb_simple_interleaved_loop_even,ix             // skip

        dout ina4,debayer_rgb_simple_interleaved_eg1,o          // b1
debayer_rgb_simple_interleaved_eg1:
	dout ina1,debayer_rgb_simple_interleaved_er1,o          // g1
debayer_rgb_simple_interleaved_er1:
	dout ina2,debayer_rgb_simple_interleaved_loop_even,ixo  // r1



// *********************************
debayer_rgb_simple_interleaved_loop_odd:
	//mulh ina4,ina4,gpr0  // R              X G B              G B X
	////mulh ina1,ina1,gpr1  // G   pixel 1  X R X     pixel 2  R X X
	//mulh ina0,ina0,gpr2  // B


	dout ina0,debayer_rgb_simple_interleaved_og0,o          // b0
debayer_rgb_simple_interleaved_og0:
	dout ina1,debayer_rgb_simple_interleaved_or0,o          // g0
debayer_rgb_simple_interleaved_or0:
	dout ina4,debayer_rgb_simple_interleaved_ob1,ixo        // r0
debayer_rgb_simple_interleaved_ob1:
	//done debayer_rgb_simple_interleaved_loop_odd,ix         // skip

        dout ina1,debayer_rgb_simple_interleaved_og1,o          // b1
debayer_rgb_simple_interleaved_og1:
	dout ina2,debayer_rgb_simple_interleaved_or1,o          // g1
debayer_rgb_simple_interleaved_or1:
	dout ina5,debayer_rgb_simple_interleaved_loop_odd,ixo   // r1
	
//	halt

.global debayer_rgb_simple_interleaved_end
debayer_rgb_simple_interleaved_end:
