
#include "motion.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "dmpKey.h"
#include "dmpmap.h"
#include <stdio.h>
#include <math.h>
#include "uart.h"
#include "i2c_eeprom.h"
#define DEFAULT_MPU_HZ  (20)

 struct hal_s {
    unsigned char lp_accel_mode;
    unsigned char sensors;
    unsigned char dmp_on;
    unsigned char wait_for_tap;
    volatile unsigned char new_gyro;
    unsigned char motion_int_mode;
    unsigned long no_dmp_hz;
    unsigned long next_pedo_ms;
    unsigned long next_temp_ms;
    unsigned long next_compass_ms;
    unsigned int report;
    unsigned short dmp_features;
};
static struct hal_s hal = {0};
 
static signed char gyro_orientation[9] = { 1, 0, 0,
                                           0, 1, 0,
                                           0, 0, 1};

static  unsigned short inv_row_2_scale(const signed char *row)
{
    unsigned short b;

    if (row[0] > 0)
        b = 0;
    else if (row[0] < 0)
        b = 4;
    else if (row[1] > 0)
        b = 1;
    else if (row[1] < 0)
        b = 5;
    else if (row[2] > 0)
        b = 2;
    else if (row[2] < 0)
        b = 6;
    else
        b = 7;      // error
    return b;
}

static  unsigned short inv_orientation_matrix_to_scalar(
    const signed char *mtx)
{
    unsigned short scalar;

    /*
       XYZ  010_001_000 Identity Matrix
       XZY  001_010_000
       YXZ  010_000_001
       YZX  000_010_001
       ZXY  001_000_010
       ZYX  000_001_010
     */

    scalar = inv_row_2_scale(mtx);
    scalar |= inv_row_2_scale(mtx + 3) << 3;
    scalar |= inv_row_2_scale(mtx + 6) << 6;


    return scalar;
}



static void tap_cb(unsigned char direction, unsigned char count)
{
    switch (direction) {
    case TAP_X_UP:
        break;
    case TAP_X_DOWN:
        break;
    case TAP_Y_UP:
        break;
    case TAP_Y_DOWN:
        break;
    case TAP_Z_UP:
        break;
    case TAP_Z_DOWN:
        break;
    default:
        return;
    }
    return;
}

static void android_orient_cb(unsigned char orientation)
{
	switch (orientation) {
	case ANDROID_ORIENT_PORTRAIT:

        break;
	case ANDROID_ORIENT_LANDSCAPE:

        break;
	case ANDROID_ORIENT_REVERSE_PORTRAIT:

        break;
	case ANDROID_ORIENT_REVERSE_LANDSCAPE:

        break;
	default:
		return;
	}
}


static void run_self_test(void)
{
    int result;
//    char test_packet[4] = {0};
    long gyro[3], accel[3];
    do{
    result = mpu_run_self_test(gyro, accel);
    }while(result != 0x7);
        /* Test passed. We can trust the gyro data here, so let's push it down
         * to the DMP.
         */
        float sens;
        unsigned short accel_sens;
        mpu_get_gyro_sens(&sens);
        gyro[0] = (long)(gyro[0] * sens);
        gyro[1] = (long)(gyro[1] * sens);
        gyro[2] = (long)(gyro[2] * sens);
        dmp_set_gyro_bias(gyro);
        mpu_get_accel_sens(&accel_sens);
        accel[0] *= accel_sens;
        accel[1] *= accel_sens;
        accel[2] *= accel_sens;
        dmp_set_accel_bias(accel);
}

void motion_init(void)
{
	i2c_eeprom_init(0x69, 2, 0, I2C_1BYTE_ADDR);
  	mpu_init();
		mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
		mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
	  mpu_set_sample_rate(DEFAULT_MPU_HZ);
		while(dmp_load_motion_driver_firmware());
		dmp_set_orientation(inv_orientation_matrix_to_scalar(gyro_orientation));
		dmp_register_tap_cb(tap_cb);
//	 dmp_register_android_orient_cb(android_orient_cb);
		hal.dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP | DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_GYRO_CAL;
		dmp_enable_feature(hal.dmp_features);
		dmp_set_fifo_rate(DEFAULT_MPU_HZ);                        
		run_self_test();

		mpu_set_dmp_state(1);
//				dmp_set_interrupt_mode(DMP_INT_GESTURE);
		dmp_set_interrupt_mode(DMP_INT_CONTINUOUS);
	//	mpu_lp_motion_interrupt(500, 1, 5);
  while(mpu_set_int_latched(1));
}

void uart_dis(void)
{
			 unsigned long sensor_timestamp;
     short gyro[3], accel[3], sensors;
     unsigned char more;
     long quat[4];
	do{
			dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more);
	}while(!(sensors & INV_WXYZ_QUAT));
            __nop();
				float w = (float)quat[0]/1073741824.0f;
				float x = (float)quat[1]/1073741824.0f;
				float y = (float)quat[2]/1073741824.0f;
				float z = (float)quat[3]/1073741824.0f;
				float Roll=atan2f(2*w*y+2*x*z, 1-2*x*x-2*y*y)*57.3;
        float Pitch=asinf(2*w*x-2*z*y)*57.3;
        float Yaw=atan2f(2*w*z+2*x*y, 1-2*x*x-2*z*z)*57.3;
				__nop();
				
				
				unsigned char i=0;
        unsigned char _cnt=0,sum = 0;
        int _temp;
        unsigned char  uart_dis[50];
        
        _temp = (int)(Pitch*100);
				if(_temp > 0)
					uart_dis[0] = '+';
				else
				{
          uart_dis[0] = '-';
					_temp = -_temp;
        }
				uart_dis[1] = _temp/10000+0x30;
				uart_dis[2] = _temp%10000/1000+0x30;
				uart_dis[3] = _temp%1000/100 + 0x30;
				uart_dis[4] = '.';
				uart_dis[5] = _temp%100/10 + 0x30;
				printf_string("\n\r Pitch: ");
        print_nbytes(uart_dis, 6);
				
        _temp = 0-(int)(Roll*100);
        if(_temp > 0)
					uart_dis[0] = '+';
				else
				{
          uart_dis[0] = '-';
					_temp = -_temp;
        }
				uart_dis[1] = _temp/10000+0x30;
				uart_dis[2] = _temp%10000/1000+0x30;
				uart_dis[3] = _temp%1000/100 + 0x30;
				uart_dis[4] = '.';
				uart_dis[5] = _temp%100/10 + 0x30;
				printf_string("   Roll: ");
        print_nbytes(uart_dis, 6);
				
        _temp = 0-(int)(Yaw*100);
        if(_temp > 0)
					uart_dis[0] = '+';
				else
				{
          uart_dis[0] = '-';
					_temp = -_temp;
        }
				uart_dis[1] = _temp/10000+0x30;
				uart_dis[2] = _temp%10000/1000+0x30;
				uart_dis[3] = _temp%1000/100 + 0x30;
				uart_dis[4] = '.';
				uart_dis[5] = _temp%100/10 + 0x30;
				printf_string("   Yaw: ");
        print_nbytes(uart_dis, 6);
}




