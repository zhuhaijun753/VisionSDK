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

#define	SCR_WIDTH	640
#define	SCR_HEIGHT	480
#define	BOX_TOP		100
#define	BOX_LEFT	100
#define	BOX_WIDTH	440
#define	BOX_HEIGHT	280
#define	REST_WIDTH	100
#define	NZ_REST_WIDTH	540

//.org    0x00
.global debayer_rgb_start
debayer_rgb_start:

  done d0,i
d0:
  done d1,i
d1:
  mov confalu, (0 /* unsigned*/ | (1<<1) /*saturate*/ | (8<< 4) /* SHR: 16.0*/)
//  mov confaddt,(0/*w*/) | (0/*apply mask*/<<2) | (0 /* unsigned*/<<3) | (0/* shift right*/ <<5) | (64 /* factor*/ <<9)
  //mov maskv,0b000011011
  mov gpr0,417 // gain r
  mov gpr1,256 // gain g
  mov gpr2,305 // gain b

  mov loopcnt,100
evenl0:  // first line rgrgrg
     mulh ina1,ina1,gpr0
     mulh ina0,ina0,gpr1
     mulh ina3,ina3,gpr2
eb0:  dout ina3,eg0,o // b
eg0:  dout ina0,er0,o // g
er0:  dout ina1,evenlodd0,ixo  // r
evenlodd0:
  ldon evenl0,i       # shift input by two

  mov gpr3,ypos 
  sub gpr3,100
  bge chkzoom
nozoom:
  mov loopcnt,540
  bal evenl2

chkzoom:
  sub gpr3,280	// 480-100-100
  bge nozoom
  
dozoom:
  mov loopcnt,220 //440/2

evenl1:  // first line rgrgrg
     asl gpr4,ina3,4 // b
     asl gpr5,ina0,4 // g
     asl gpr6,ina1,4 // r
  done d2,i
d2:
  done d3,i
d3:
     sub gpr4,gpr4,ina3 // b
     sub gpr5,gpr5,ina0 // g
     sub gpr6,gpr6,ina1 // r
     
bw0:  dout gpr4,bw1,o // b
bw1:  dout gpr5,bw2,o // g
bw2:  dout gpr6,bw3,o // r
bw3:  dout gpr4,bw4,o // b
bw4:  dout gpr5,bw5,o // g
bw5:  dout gpr6,evenlodd1,ixo  // r
evenlodd1:
  ldon evenl1,i       # shift input by two

  mov loopcnt,100
evenl2:  // first line rgrgrg
     mulh ina1,ina1,gpr0
     mulh ina0,ina0,gpr1
     mulh ina3,ina3,gpr2
eb2:  dout ina3,eg2,o // b
eg2:  dout ina0,er2,o // g
er2:  dout ina1,evenlodd2,ixo  // r
evenlodd2:
  ldon evenl2,i       # shift input by two

//     halt

.global debayer_rgb_end	
debayer_rgb_end:
