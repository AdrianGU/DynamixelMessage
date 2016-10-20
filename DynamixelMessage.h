
#include <cstdint>



#define _READ_SERVO_DATA 0X02
#define _WRITE_SERVO_DATA 0X03
#define _WRITE_SYNC_SERVO_DATA 0X04

/* EEPROM */
#define  SERVO_REGISTER_MODEL_NUMBER             0x00
//SERVO_REGISTER_MODEL_NUMBER_L         0x00,
//SERVO_REGISTER_MODEL_NUMBER_H         0x01,
#define  SERVO_REGISTER_FIRMWARE_VERSION         0x02
#define  SERVO_REGISTER_ID                       0x03
#define  SERVO_REGISTER_BAUD_RATE                0x04
#define  SERVO_REGISTER_RETURN_DELAY_TIME        0x05
#define  SERVO_REGISTER_MIN_ANGLE                0x06
//SERVO_REGISTER_MIN_ANGLE_L            0x06,
//SERVO_REGISTER_MIN_ANGLE_H            0x07,
#define  SERVO_REGISTER_MAX_ANGLE                0x08
//SERVO_REGISTER_MAX_ANGLE_L            0x08,
//SERVO_REGISTER_MAX_ANGLE_H            0x09,
#define  SERVO_REGISTER_MAX_TEMPERATURE          0x0B
#define  SERVO_REGISTER_MIN_VOLTAGE              0x0C
#define  SERVO_REGISTER_MAX_VOLTAGE              0x0D
#define  SERVO_REGISTER_MAX_TORQUE               0x0E
//SERVO_REGISTER_MAX_TORQUE_L           0x0E,
//SERVO_REGISTER_MAX_TORQUE_H           0x0F,
#define  SERVO_REGISTER_RETURN_LEVEL             0x10
#define  SERVO_REGISTER_LED_ERROR                0x11
#define  SERVO_REGISTER_SHUTDOWN_ERROR           0x12

/* RAM */
#define  SERVO_REGISTER_TORQUE_ENABLE            0x18
#define  SERVO_REGISTER_LED_IS_ON                0x19
#define  SERVO_REGISTER_D_GAIN                   0x1A
#define  SERVO_REGISTER_I_GAIN                   0x1B
#define  SERVO_REGISTER_P_GAIN                   0x1C
#define  SERVO_REGISTER_GOAL_ANGLE               0x1E
//SERVO_REGISTER_GOAL_ANGLE_L           0x1E,
//SERVO_REGISTER_GOAL_ANGLE_H           0x1F,
#define  SERVO_REGISTER_MOVING_SPEED             0x20
//SERVO_REGISTER_MOVING_SPEED_L        0x20,
//SERVO_REGISTER_MOVING_SPEED_H        0x21,
#define  SERVO_REGISTER_TORQUE_LIMIT             0x22
//SERVO_REGISTER_TORQUE_LIMIT_L         0x22,
//SERVO_REGISTER_TORQUE_LIMIT_H         0x23,
#define  SERVO_REGISTER_PRESENT_ANGLE            0x24
//SERVO_REGISTER_PRESENT_ANGLE_L        0x24,
//SERVO_REGISTER_PRESENT_ANGLE_H        0x25,
#define  SERVO_REGISTER_PRESENT_SPEED            0x26
//SERVO_REGISTER_PRESENT_SPEED_L        0x26,
//SERVO_REGISTER_PRESENT_SPEED_H        0x27,
#define  SERVO_REGISTER_PRESENT_TORQUE           0x28
//SERVO_REGISTER_PRESENT_TORQUE_L       0x28,
//SERVO_REGISTER_PRESENT_TORQUE_H       0x29,
#define  SERVO_REGISTER_PRESENT_VOLTAGE          0x2A
#define  SERVO_REGISTER_PRESENT_TEMPERATURE      0x2B

#define  SERVO_REGISTER_PENDING_INSTRUCTION      0x2C
#define  SERVO_REGISTER_IS_MOVING                0x2E
#define  SERVO_REGISTER_LOCK_EEPROM              0x2F
#define  SERVO_REGISTER_PUNCH                    0x30
//SERVO_REGISTER_PUNCH_L                0x30,
//SERVO_REGISTER_PUNCH_H                0x31,
#define  SERVO_REGISTER_CURRENT_CONSUMPTION      0x44
//SERVO_REGISTER_CURRENT_CONSUMPTION_L  0x44,
//SERVO_REGISTER_CURRENT_CONSUMPTION_H  0x45,
#define  SERVO_REGISTER_TORQUE_CTRL_ENABLE       0x46
#define  SERVO_REGISTER_GOAL_TORQUE              0x47
//SERVO_REGISTER_GOAL_TORQUE_L          0x47,
//SERVO_REGISTER_GOAL_TORQUE_H          0x48,
#define  SERVO_REGISTER_GOAL_ACCELERATION        0x49


class DynamixelMessage
{

    public:
        DynamixelMessage(uint8_t id,uint8_t length, bool write, bool syncwrite, uint8_t reg, uint8_t value);
        void assemblePacket();


        uint8_t get_id() const;
        void set_id(uint8_t _id);
        uint8_t get_length() const;
        void set_length(uint8_t _length);
        bool is_write() const;
        void set_write(bool _write);
        bool is_syncwrite() const;
        void set_syncwrite(bool _syncwrite);
        uint8_t get_reg() const;
        void set_reg(uint8_t _reg);
        uint8_t get_value() const;
        void set_value(uint8_t _value);

private:
    uint8_t _id;
    uint8_t _length;
    bool _write;
    bool _syncwrite;
    uint8_t _reg;
    uint8_t _value;
};