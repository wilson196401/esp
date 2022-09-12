#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace hs2xx3a {

class HS2XX3A : public uart::UARTDevice, public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;

  void publishTarget(std::string idx, float dist, float snr);
  static void clearTargets();
  void publishNumber(std::string sensor, float resp);
  void publishSwitch(std::string sensor, int state);
  void getmmwConf(std::string mmwparam);

 protected:
  int readline(int readch, char *buffer, int len);
};

}  // namespace hs2xx3a
}  // namespace esphome
