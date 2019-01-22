#pragma once
#include "hidapi.h"
#include <iostream>
#include <vector>

#define AXIS_VAL_MAX 0x80

struct JoyStickStatus {
	int     time;
	int		up;
	int		down;
	int		left;
	int		right;
	int     a;
	int     b;
	int     x;
	int     y;
	int     lbu;
	int     rbu;
	int     lbd;
	int     rbd;
	int     select;
	int     start;
	int     lo;
	int     ro;

	int     lx;
	int     ly;
	int     rx;
	int     ry;
};
 
class JoyStick
{
public:
	JoyStick();
	~JoyStick();

	int open();
	int read(JoyStickStatus * js);
	void close();

private:
	std::vector<hid_device*> hids;
	int process(unsigned char * raw, JoyStickStatus * js);

};

