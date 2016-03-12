#ifndef _APEX_CV_BICUBIC_LUT_H
#define _APEX_CV_BICUBIC_LUT_H

const int incr = 50;

const int16_t BicubicLUT[4][incr + 1] = {
	{
		0,-2,-4,-6,-8,-10,-11,-13,-14,-15,-16,-17,-17,-18,-18,-18,-18,-18,-18,-18,-18,-18,-17,-17,-16,-16,-15,-14,-13,-13,-12,-11,-10,-9,-8,-8,-7,-6,-5,-4,-4,-3,-2,-2,-1,-1,0,0,0,0,0
	},
	{
		256,255,255,253,252,249,247,244,241,237,233,229,224,219,214,208,203,197,190,184,178,171,164,157,151,144,136,129,122,115,108,101,94,87,80,74,67,61,54,48,43,37,32,26,22,17,13,9,5,2,0
	},
	{
		0,2,5,9,13,17,22,26,32,37,43,48,54,61,67,74,80,87,94,101,108,115,122,129,136,144,151,157,164,171,178,184,190,197,203,208,214,219,224,229,233,237,241,244,247,249,252,253,255,255,256
	},
	{
		0,0,0,0,0,-1,-1,-2,-2,-3,-4,-4,-5,-6,-7,-8,-8,-9,-10,-11,-12,-13,-13,-14,-15,-16,-16,-17,-17,-18,-18,-18,-18,-18,-18,-18,-18,-18,-17,-17,-16,-15,-14,-13,-11,-10,-8,-6,-4,-2,0
	}
};

#endif /* _APEX_CV_BICUBIC_LUT_H */