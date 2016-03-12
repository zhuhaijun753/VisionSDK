# For IPUS4/5
# simple BR debayer
# linea0: b1,1 b1,1 b3,1 b3,1 ...
# linea1: r2,2 r2,2 r4,2 r4,2 ...
# linea2: b1,3 b1,3 b3,3 b3,3 ...

# lineb1: g1,2 g2,2 g3,2 g4,2 ...

# out0 r 15 bit
# out1 b 15 bit 
# out2 g 16 bit
  
.global debayer_br_start
debayer_br_start:
        mov  confalu,(0 /* unsigned*/ | (1 << 1) /* saturate*/ | (16<<4) /* shr =0*/ ) 
        //mov confsgn,1            # signed
        //mov confsat,0            # saturation off
        mov confaddt,(0/*w*/) | (0/*apply mask*/<<2) | (0 /* unsigned*/<<3) | (1 /* keep higher*/<<4) | (4/* shift right -6*/ <<5) | (64 /* factor*/ <<9)
        //mov confthres,0          # kill values < 0
        //mov maskv,0b111111111
        //mov 1                  # to W
        //mov maskv,0b101000101  # 101 000 101
        //mov 2                  # to W
        //swp
        done debayer_br_d0,i
debayer_br_d0:
        done debayer_br_d1,i
debayer_br_d1:
        and ypos,1               # check for even lines (B first)
        done debayer_br_d2,i
debayer_br_d2:

        beq debayer_br_bluefirst   # lsb is 0
// 7 instructions

//loop:
//        dout ina4,loop,ixo

debayer_br_readfirst:      
debayer_br_loop10: // R2,2 first
        mov maskv,0b111111111    # 111 111 111
        lsr w,ina,2

        //mov maskv,0x028          # 000101000
        add out1,w3,w5           # B2,3 horizontal sum

        //mov maskv,0x082          # 010000010
        add out0,w1,w7           # R2,3 vertical sum

        mov out2,inb4            # G2,3
        done debayer_br_loop11,ixo
debayer_br_loop11:  // B1,1 First
        mov maskv,0b101000101
        lsr w,ina,3

        lsr out1,ina4,1          # B3,3
        mov out2,inb4            # G3,3
        dout sum,debayer_br_loop10,ixo      # R3,3

  //9 instruction

debayer_br_bluefirst:
debayer_br_loop00:  // B1,1 First
        mov maskv,0b101000101
        lsr w,ina,3
        lsr out0,ina4,1          # R2,2
        mov out1,sum             # B2,2
        mov out2,inb4            # G2,2

        done debayer_br_loop01,ixo
debayer_br_loop01:
        mov maskv,0x1ff
        lsr w,ina,2

        //mov maskv,0x028          # 000101000
        add out0,w3,w5             # R3,2 horizobtal sum

        //mov maskv,0x092          # 010010010
        add out1,w1,w7             # B3,2 vertical sum
        mov out2,inb4              # G3,2

        done debayer_br_loop00,ixo
//10 instructions
  
        //halt
.global debayer_br_end
debayer_br_end:
