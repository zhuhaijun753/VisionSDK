#.org    0x00
# set shift_in/x to 1 pixels
# set shift_out to 1 pixels
# input to line 0,line1,line2
# out0 : 3 pixels
# cylce 0 : line0
# cylce 1 : line1
# cylce 2 : line2
        
.global planar444_to_interleaved_start
planar444_to_interleaved_start:
  mov confalu,(0 /*unsigned*/ | (1<<1) /*saturate*/ | (14<<4) /*shr*/)
  mov maskv,0b001000001
  done planar444_to_interleaved_loop1,i    // load first pixel

planar444_to_interleaved_loop1:
  asl w,ina,1
  dout w0,planar444_to_interleaved_pixr,o
planar444_to_interleaved_pixr:
  dout ina3,planar444_to_interleaved_pixb,o
planar444_to_interleaved_pixb:
  dout w6,planar444_to_interleaved_loop1,ixo

        //halt
.global planar444_to_interleaved_end
planar444_to_interleaved_end:
