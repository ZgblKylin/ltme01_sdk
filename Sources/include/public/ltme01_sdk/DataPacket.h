#ifndef DATA_PACKET_H
#define DATA_PACKET_H

#include "ltme01_sdk/Common.h"

#include <cstdint>

namespace ltme01_sdk {

class LTME01_SDK_API DataPacket
{
public:
  static const int MAX_DATA_PACKET_SIZE = 256;

  static const uint16_t DATA_PACKET_SIGNATURE = 0xFFFF;

  static const uint8_t DATA_PACKET_INDEX_MIN = 0;
  static const uint8_t DATA_PACKET_INDEX_MAX = 23;
  static const uint8_t DATA_PACKET_COUNT_MAX = 64;

  static const uint8_t FLAG_TIMESTAMP_VALID = 0x01;

  static const uint16_t RANGE_TIMEOUT = 0x544F;
  static const uint16_t RANGE_NO_DATA = 0x4E44;

public:
  DataPacket();
  DataPacket(uint8_t* buffer, int length);

  void fillIn(uint8_t* buffer, int length);

  bool isValid() const;

  uint8_t index() const;
  uint8_t count() const;
  uint8_t flags() const;
  uint32_t timestamp() const;
  uint16_t range(int i) const;

  uint8_t* data();

private:
#pragma pack(push, 1)
  typedef struct
  {
    uint16_t signature;
    uint8_t index;
    uint8_t count;
    uint8_t reserved;
    uint8_t flags;
    uint32_t timestamp;
    uint16_t checksum;
  } DataPacketHeader;
#pragma pack(pop)

  DataPacketHeader* header_;
  uint8_t data_[MAX_DATA_PACKET_SIZE] = {0};
};

}

#endif
