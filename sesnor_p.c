#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

//一個funtion pointer指向一個裝有funtion的陣列，裡面的funtion都是吃一個int的參數，並沒有回傳值(OpenBMC常用，拿來做command table)
void (cmd_table[])(int) = {start_fun, stop_fun, reset_fun};
//互叫第第二個函式
cmd_table[1](10);


//memcopy的應用。把src的位置搬n個Bytes到dest指向的位置。
//用在記憶體沒對齊的時候（解決Aligment問題）
memcopy(void *dest, const void *src, size_t n);

