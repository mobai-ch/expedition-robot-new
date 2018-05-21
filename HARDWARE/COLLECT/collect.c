#include "collect.h"

int normalization(float val, float max, float min)
{
	int res =  (val - min)/(max-min)*255;
	if(res > 255){
		return 255;
	}else if(res < 0){
		return 0;
	}
	return res;
}

