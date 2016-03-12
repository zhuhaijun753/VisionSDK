// kernel to convert Bayer pattern to gray level with 1:2 resolution
// reading two input lines with R, GR and next line GB, B and
// producing a single output value for the 2x2 input window
// Line INA0, even line  16bpp or 8bpp MSB aligned (buffertype = 0 or 1)
// Line INA1, odd line   16bpp or 8bpp MSB aligned (buffertype = 0 or 1)
// Line Out0, combined line       8bpp MSB aligned (buffertype = 1)
// expect that per output line the input lines progress by two lines
// additional hints:
// needs to cut lines from the top of the image (optical black) and
// frame from right (e.g., down from 1296 to 1280)



.org    0x00
.global debayer_g_start
debayer_g_start:
  done d0,i
d0:
  done d1,i
d1:
//  mov confalu, (0 /* unsigned*/ | (1<<1) /*saturate*/ | (15 << 4) /* SHR: q2.14*/)
  mov confaddt,(0/*w*/) | (0/*apply mask*/<<2) | (0 /* unsigned*/<<3) | (0/* shift right*/ <<5) | (64 /* factor*/ <<9)
  mov maskv,0b000011011

loop0:  // interpolate G from R+GR+GB+B
  lsr ina,2
//  sub w,0x0003

//  lsr hbinincl,ina0,8
//  lsr hbinincl,ina1,8
//  lsr hbinincl,ina3,8
//  lsr hbinincl,ina4,8
//  lsl out0,clipped,4
// done odd,ixo
   dout clipped,odd,ixo
odd:
  done loop0,i       # shift input by two

//        halt
.global debayer_g_end	
debayer_g_end:
