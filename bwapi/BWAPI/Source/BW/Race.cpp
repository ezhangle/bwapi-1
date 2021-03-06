#include "Race.h"
namespace BW
{
  namespace Race
  {
    u8 stringToRace(const std::string& name)
    {
      if (name == "Zerg")
        return Zerg;
      if (name == "Terran")
        return Terran;
      if (name == "Protoss")
        return Protoss;
      return None;
    };
    std::string raceName(u8 race)
    {
      switch (race)
      {
        case Zerg    : return "Zerg";
        case Terran  : return "Terran";
        case Protoss : return "Protoss";
        case Other   : return "Other";
        case Select  : return "Select";
        case Random  : return "Random";
        case None    : return "None";
        default      : return "Unknown";
      }
    };
  }
};
