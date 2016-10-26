#include "DynamixelMessage.h"





DynamixelMessage::DynamixelMessage(uint8_t id, uint8_t length, bool write, bool syncwrite, uint8_t reg, uint8_t value)
{
    DynamixelMessage::_id=id;
    DynamixelMessage::_length=length;
    DynamixelMessage::_write=write;
    DynamixelMessage::_syncwrite=syncwrite;
    DynamixelMessage::_reg=reg;
    DynamixelMessage::_value=value;
}
void DynamixelMessage::assemblePacket()
{
    uint8_t pkt[255];
    uint8_t checksumResult;

    for (int t = 0; t < 255; t++)
    {
        pkt[t] = 0;
    }

    pkt[0] = 0XFF;
    pkt[1] = 0XFF;
    pkt[2] = DynamixelMessage::_id;
    pkt[3] = DynamixelMessage::_length+4;
    if(is_write())
    {
        pkt[4]=_WRITE_SERVO_DATA;

    }else if(is_syncwrite())
    {
        pkt[4] = _WRITE_SYNC_SERVO_DATA;

    }else
    {
        pkt[4] = _READ_SERVO_DATA;

    }
    pkt[5] =DynamixelMessage::_reg;
    pkt[6] =DynamixelMessage::_value;
    //checksum = ~(pkt[2] + pkt[3] + pkt[4] + pkt[5] + pkt[6] + pkt[7]);
    for(int p=2;p<pkt[3];p++)
    {
        checksumResult=checksumResult+pkt[p];
    }
    checksumResult=~checksumResult;
    pkt[pkt[3]]=checksumResult;


    for(int i=0;i<pkt[3];i++)
    {
        Serial.println(pkt[i]);
    }

}

uint8_t DynamixelMessage::get_id() const {
    return _id;
}

void DynamixelMessage::set_id(uint8_t _id) {
    DynamixelMessage::_id = _id;
}

uint8_t DynamixelMessage::get_length() const {
    return _length;
}

void DynamixelMessage::set_length(uint8_t _length) {
    DynamixelMessage::_length = _length;
}

bool DynamixelMessage::is_write() const {
    return _write;
}

void DynamixelMessage::set_write(bool _write) {
    DynamixelMessage::_write = _write;
}

bool DynamixelMessage::is_syncwrite() const {
    return _syncwrite;
}

void DynamixelMessage::set_syncwrite(bool _syncwrite) {
    DynamixelMessage::_syncwrite = _syncwrite;
}

uint8_t DynamixelMessage::get_reg() const {
    return _reg;
}

void DynamixelMessage::set_reg(uint8_t _reg) {
    DynamixelMessage::_reg = _reg;
}

uint8_t DynamixelMessage::get_value() const {
    return _value;
}

void DynamixelMessage::set_value(uint8_t _value) {
    DynamixelMessage::_value = _value;
}









