#include "stdafx.h"
#include "JoyStick.h"


JoyStick::JoyStick()
{
}


JoyStick::~JoyStick()
{
}


int JoyStick::open()
{
	int error = 0;

	error = hid_init();
	if (error == -1) {
		// HID库初始化错误
		return -2;
	}

	hid_device_info* hids_info = hid_enumerate(0x0079, 0x0006);
	if (hids_info == nullptr) {
		// 找不到指定HID设备
		return -3;
	}

	for (; hids_info != nullptr; hids_info = hids_info->next) {
		hid_device* hid = hid_open_path(hids_info->path);
		if (hid != nullptr) {
			hids.push_back(hid);
		}
	}

	if (hids.size() == 0) {
		// 无法打开指定HID设备
		return -4;
	}

	return 0;
}

int JoyStick::read(JoyStickStatus * js)
{
	bool is_press = false;
	unsigned char data[128] = {};
	for (hid_device* hid : hids) {
		hid_set_nonblocking(hid, 1);
		int len = hid_read(hid, data, 128);
		if (len == 0) continue;

		//for (int i = 0; i < len - 1; i++) {
		//	printf("%02x-", data[i]);
		//}
		//printf("%02x\r", data[len - 1]);
		return process(data, js);
	}
	return -1;
}

void JoyStick::close()
{
	for (hid_device* hid : hids) {
		hid_close(hid);
	}
	hid_exit();
}

int JoyStick::process(unsigned char * raw, JoyStickStatus * js)
{
	static int time = 0;
	js->time = time++;

	js->lx = raw[0];
	js->ly = raw[1];
	js->rx = raw[3];
	js->ry = raw[4];

#define TEMP(a,b,c,d) {\
	js->up = a;\
	js->right = b;\
	js->down = c;\
	js->left = d;\
}

	switch (raw[5] % 16)
	{
	case 0:
		TEMP(1, 0, 0, 0);
		break;
	case 1:
		TEMP(1, 1, 0, 0);
		break;
	case 2:
		TEMP(0, 1, 0, 0);
		break;
	case 3:
		TEMP(0, 1, 1, 0);
		break;
	case 4:
		TEMP(0, 0, 1, 0);
		break;
	case 5:
		TEMP(0, 0, 1, 1);
		break;
	case 6:
		TEMP(0, 0, 0, 1);
		break;
	case 7:
		TEMP(1, 0, 0, 1);
		break;
	case 15:
		TEMP(0, 0, 0, 0);
		break;
	default:
		break;
	}

	js->a = (raw[5] >> 6) % 2;
	js->b = (raw[5] >> 5) % 2;
	js->x = (raw[5] >> 7) % 2;
	js->y = (raw[5] >> 4) % 2;

	js->lbu = (raw[6] >> 0) % 2;
	js->lbd = (raw[6] >> 2) % 2;
	js->rbu = (raw[6] >> 1) % 2;
	js->rbd = (raw[6] >> 3) % 2;

	js->select = (raw[6] >> 4) % 2;
	js->start = (raw[6] >> 5) % 2;
	js->lo = (raw[6] >> 6) % 2;
	js->ro = (raw[6] >> 7) % 2;

	return 0;
}