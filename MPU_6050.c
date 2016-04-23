#include"MPU_6050.h"

void MPU_6050_init(void)
{		
	//twi_write(PWR_MGMT_1, 0x80);	
	//delay_nms(20);
	twi_write(PWR_MGMT_1, 0x00);		//解除休眠
	//twi_write(0x23, 0xf8);	
	//delay_nms(100);
	//twi_write(PWR_MGMT_1, 0x08);	
	twi_write(SMPRT_DIV, 0x01);
	twi_write(CONFIG,0x06);
	twi_write(GYRO_CONFIG, 0x18);
	twi_write(ACCEL_CONFIG, 0x01);
	//twi_write(PWR_MGMT_1,0X01); //设置CLKSEL,PLL X轴为参考
	//twi_write(PWR_MGMT_2,0X00); //加速度与陀螺仪都工作
}

int Get_data(uchar REG_Address)
{
	int H_data;
	int L_data;
	H_data=twi_read(REG_Address);
	L_data=twi_read(REG_Address+1);
	return (H_data<<8)|L_data;
}


