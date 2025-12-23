#include<stdio.h>
#include<stdlib.h>


typedef struct{
    uint8_t id;
    uint8_t i2c_bus;
    uint8_t i2c_address;
    int last_temp;
    int valid;
}Sensor;

typedef struct {
    uint8_t id;
    uint8_t sensor_od;
    int target_rpm;
}Fan;

//定期更新Sensor值
void SensorPollingTask(void) {
    while (1){
        for each sensor in sensor_list{
            lock_i2c_bus();

            int ret = i2c_read_tmp(sensor.i2c_bus, sensor.i2c_address, &sensor.last_temp);

            unlock_i2c_bus();

            if (ret < 0){
                sensor.valid = 0;
            }
            else{
                sensor.valid = 1;
            }
        }
        sleep(POLLING_INTERVAL_MS);
    }
}

//根據sensor值控制風扇

void FanControlTask(void){
    while (1){
        for each fan in fan_list{
            Sensor *s = find_sensor_by_id(fan.sensor_id);

            int temp;
            if (s == NULL || s->valid == 0){
                tmp = SAFE_TEMP;
            }
            else{
                temp = s->last_temp;
            }

            fan.target_rpm = compute_rpm_from_temp(temp);
            set_fan_pwm(fan.pwm_channel, fan.target_rpm);
        }
        sleep(CONTROL_INTERVAL_MS);
    }
}