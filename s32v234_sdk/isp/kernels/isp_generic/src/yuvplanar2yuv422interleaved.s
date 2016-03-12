# for IPUS
#.org    0x00
.global yuvplanar2yuv422interleaved_start
# set shift_in/x to 1 pixels
# set shift_out to 1 pixels
# line0: y values
# line1: u values  / horizontally upscaled by stream DMA in case of yuv422
# line3: v values  / horizontally upscaled by stream DMA in case of yuv422
# out0 cycle 0 : Y
# out0 cycle 1 : U
# out0 cycle 2 : Y
# out0 cycle 3 : V

yuvplanar2yuv422interleaved_start:

        //mov loopcnt,(1280/2)/2
        //mov confalu,(0 /*unsigned*/ | (1<<1) /*saturate*/ | (14<<4) /*shr*/)

        mov maskv,0b011011000
        done yuvplanar2yuv422interleaved_in1,i  // load first 2 pixles yuyv
yuvplanar2yuv422interleaved_in1:
        done yuvplanar2yuv422interleaved_u,i  // load first 2 pixles yuyv

yuvplanar2yuv422interleaved_u:
        lsr  w,ina,1
        add  out0,w3,w4
        done yuvplanar2yuv422interleaved_y0,o

yuvplanar2yuv422interleaved_y0:
        dout ina1,yuvplanar2yuv422interleaved_v,o

yuvplanar2yuv422interleaved_v:
        add  out0,w6,w7
        done yuvplanar2yuv422interleaved_y1,ixo

yuvplanar2yuv422interleaved_y1:
        dout ina1,yuvplanar2yuv422interleaved_u,ixo

        halt
.global yuvplanar2yuv422interleaved_end
yuvplanar2yuv422interleaved_end:
