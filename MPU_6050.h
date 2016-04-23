#ifndef MPU_6050_H
#define MPU_6050_H

#define   uint   unsigned int
#define   uchar  unsigned char 

#include"iom16v.h"
#include"delay.h"
#include"twi.h"
#include"sent.h"

#define		SMPRT_DIV		0X19		//陀螺仪采样频率输出,典型值0x07(125Hz)
#define		CONFIG			0x1A	    //低通滤波频率，典型值：0x06(5Hz)
#define		GYRO_CONFIG		0x1B		//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
#define		ACCEL_CONFIG	0x1C		//加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
#define     FIFO_EN         0x23
#define		ACCEL_XOUT_H	0x3B
#define		ACCEL_XOUT_L	0x3C
#define		ACCEL_YOUT_H	0x3D
#define		ACCEL_YOUT_L	0x3E
#define		ACCEL_ZOUT_H	0x3F
#define		ACCEL_ZOUT_L	0x40
#define		TEMP_OUT_H		0x41
#define		TEMP_OUT_L		0x42
#define		GYRO_XOUT_H		0x43
#define		GYRO_XOUT_L		0x44	
#define		GYRO_YOUT_H		0x45
#define		GYRO_YOUT_L		0x46
#define		GYRO_ZOUT_H		0x47
#define		GYRO_ZOUT_L		0x48
#define		PWR_MGMT_1		0x6B		//电源管理，典型值：0x00(正常启用)
#define		PWR_MGMT_2		0x6c
#define		WHO_AM_I		0x75		//IIC地址寄存器(默认数值0x68，只读)
#define		W_MPU6050_ADDR	0xD0		//IIC写入时的地址字节数据，+1为读取
#define		R_MPU6050_ADDR	0xD1

void MPU_6050_init(void);
int Get_data(uchar REG_Address);

#endif