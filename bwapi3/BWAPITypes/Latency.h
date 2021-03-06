#pragma once
namespace BWAPI
{
  typedef int Latency;
  namespace Latencies
  {
    enum Enum
    {
      SinglePlayer    = 2,
      LanLow          = 5,
      LanMedium       = 7,
      LanHigh         = 9,
      BattlenetLow    = 14,
      BattlenetMedium = 19,
      BattlenetHigh   = 24
    };
  }
}
