#pragma once

#include "BWAPI/Unit.h"

#include <list>

#include <Util/Types.h>

#include <BWAPITypes/Activity.h>
#include <BWAPITypes/TechType.h>
#include <BWAPITypes/UpgradeType.h>
#include <BWAPITypes/UnitType.h>

#include <BW/TilePosition.h>
#include <BW/ActivityID.h>
#include <BW/UnitType.h>

namespace Util  { class Logger; }
namespace BW    { class Position; };
namespace BW    { struct Unit; };
namespace BWAPI { class UnitPrototype;  };
namespace BWAPI { class AbilityPrototype;  };
namespace BWAPI { class Player;  };

namespace BWAPI
{
  /**
   * Interface for broodwar unit, can be used to obtain any information and
   * issue commands.
   */
  class UnitImpl : public Unit
  {
    public:

      virtual Player*  getPlayer() const;
      virtual UnitType  getType() const;
      virtual UnitType  getInitialType() const;
      virtual int  getHitPoints() const;
      virtual int  getInitialHitPoints() const;
      virtual int  getShields() const;
      virtual int  getEnergy() const;
      virtual int  getResources() const;
      virtual int  getInitialResources() const;
      virtual int  getKillCount() const;
      virtual int  getGroundWeaponCooldown() const;
      virtual int  getAirWeaponCooldown() const;
      virtual int  getSpellCooldown() const;
      virtual int  getDefenseMatrixPoints() const;

      virtual int  getDefenseMatrixTimer() const;
      virtual int  getEnsnareTimer() const;
      virtual int  getIrradiateTimer() const;
      virtual int  getLockdownTimer() const;
      virtual int  getMaelstromTimer() const;
      virtual int  getPlagueTimer() const;
      virtual int  getRemoveTimer() const;
      virtual int  getStasisTimer() const;
      virtual int  getStimTimer() const;

      virtual Position  getPosition() const;
      virtual Position  getInitialPosition() const;
      virtual TilePosition  getTilePosition() const;
      virtual TilePosition  getInitialTilePosition() const;
      virtual double getDistance(Unit* target) const;
      virtual double getDistance(Position target) const;
      virtual double getAngle() const;
      virtual double getVelocityX() const;
      virtual double getVelocityY() const;

      virtual Unit*  getTarget() const;
      virtual Position  getTargetPosition() const;
      virtual Activity  getActivity() const;
      virtual Unit*  getActivityTarget() const;
      virtual int  getActivityTimer() const;
      virtual Activity  getSecondaryActivity() const;
      virtual Unit*  getBuildUnit() const;
      virtual int  getRemainingBuildTime() const;
      virtual int  getRemainingTrainTime() const;
      virtual Unit*  getChild() const;
      virtual std::list<UnitType >  getTrainingQueue() const;
      virtual Unit*  getTransport() const;
      virtual std::list<Unit*>  getLoadedUnits() const;
      virtual int  getInterceptorCount() const;
      virtual int  getScarabCount() const;
      virtual int  getSpiderMineCount() const;
      virtual TechType  getTech() const;
      virtual UpgradeType  getUpgrade() const;
      virtual int  getRemainingResearchTime() const;
      virtual int  getRemainingUpgradeTime() const;
      virtual Position  getRallyPosition() const;
      virtual Unit*  getRallyUnit() const;
      virtual Unit*  getAddon() const;
      virtual int  getUpgradeLevel(UpgradeType upgrade) const;

      virtual bool  exists() const;
      virtual bool  isAccelerating() const;
      virtual bool  isBeingConstructed() const;
      virtual bool  isBeingHealed() const;
      virtual bool  isBlind() const;
      virtual bool  isBraking() const;
      virtual bool  isBurrowed() const;
      virtual bool  isCarryingGas() const;
      virtual bool  isCarryingMinerals() const;
      virtual bool  isCloaked() const;
      virtual bool  isCompleted() const;
      virtual bool  isConstructing() const;
      virtual bool  isDefenseMatrixed() const;
      virtual bool  isEnsnared() const;
      virtual bool  isFollowing() const;
      virtual bool  isGatheringGas() const;
      virtual bool  isGatheringMinerals() const;
      virtual bool  isHallucination() const;
      virtual bool  isIdle() const;
      virtual bool  isIrradiated() const;
      virtual bool  isLifted() const;
      virtual bool  isLoaded() const;
      virtual bool  isLockedDown() const;
      virtual bool  isMaelstrommed() const;
      virtual bool  isMorphing() const;
      virtual bool  isMoving() const;
      virtual bool  isParasited() const;
      virtual bool  isPatrolling() const;
      virtual bool  isPlagued() const;
      virtual bool  isRepairing() const;
      virtual bool  isResearching() const;
      virtual bool  isSelected() const;
      virtual bool  isSieged() const;
      virtual bool  isStartingAttack() const;
      virtual bool  isStasised() const;
      virtual bool  isStimmed() const;
      virtual bool  isTraining() const;
      virtual bool  isUnderStorm() const;
      virtual bool  isUnpowered() const;
      virtual bool  isUpgrading() const;
      virtual bool  isVisible() const;
      virtual bool  isBeingGathered() const;

      virtual bool  attackMove(Position position);
      virtual bool  attackUnit(Unit* target);
      /**
       * Activity this unit to right click on the specified location. Note that
       * right click on location will always result in move.
       */
      virtual bool  rightClick(Position position);
      /**
       * Activitys this unit to right click on the specified unit. Note that right
       * click on unit can result in lot of commands (attack, gather, follow,
       * set rally point)
       */
      virtual bool  rightClick(Unit* target);
      /** Activitys this unit to train (construct) the specified unit. */
      virtual bool  train(UnitType type);
      /** Activitys to build the specified building. */
      virtual bool  build(TilePosition position, UnitType type);
      virtual bool  buildAddon(UnitType type);
      /** Activitys to build the research the specified tech. */
      virtual bool  research(TechType tech);
      /** Activitys to build the upgrade the specified upgrade. */
      virtual bool  upgrade(UpgradeType upgrade);
      virtual bool  stop();
      virtual bool  holdPosition();
      virtual bool  patrol(Position position);
      virtual bool  follow(Unit* target);
      virtual bool  setRallyPosition(Position target);
      virtual bool  setRallyUnit(Unit* target);
      virtual bool  repair(Unit* target);
      virtual bool  morph(UnitType type);
      virtual bool  burrow();
      virtual bool  unburrow();
      virtual bool  siege();
      virtual bool  unsiege();
      virtual bool  cloak();
      virtual bool  decloak();
      virtual bool  lift();
      virtual bool  land(TilePosition position);
      virtual bool  load(Unit* target);
      virtual bool  unload(Unit* target);
      virtual bool  unloadAll();
      virtual bool  unloadAll(Position position);
      virtual bool  cancelConstruction();
      virtual bool  haltConstruction();
      virtual bool  cancelMorph();
      virtual bool  cancelTrain();
      virtual bool  cancelTrain(int slot);
      virtual bool  cancelAddon();
      virtual bool  cancelResearch();
      virtual bool  cancelUpgrade();
      virtual bool  useTech(TechType tech);
      virtual bool  useTech(TechType tech, Position position);
      virtual bool  useTech(TechType tech, Unit* target);


      //Internal BWAPI commands:
      UnitImpl(BW::Unit* originalUnit,
               BW::Unit* unitLocal,
               u16 index);
      ~UnitImpl();
      static UnitImpl* BWUnitToBWAPIUnit(BW::Unit* unit);
      void die();
      inline bool canAccess() const;
      inline bool canAccessSpecial() const;
      inline bool canAccessInside() const;
      inline bool attemptAccess() const;
      inline bool attemptAccessSpecial() const;
      inline bool attemptAccessInside() const;
      inline bool _exists() const;
      bool died() const;
      Player* _getPlayer() const;
      UnitType _getType() const;
      Position _getPosition() const;
      TilePosition _getTilePosition() const;
      int _getResources() const;
      int _getHitPoints() const;
      Unit* _getActivityTarget() const;
      bool _isCompleted() const;
      bool _isResearching() const;
      bool _isUpgrading() const;

      BW::UnitType getBWType() const;

      /**
       * Gets index of the unit in the unit array. Note that the index is same
       * for the original unit array, BWAPI::Unit array and BWAI::Unit array, so
       * it is good way to compare units of different types and for conversion.
       * @return 0-based index of the unit in the unit array.
       */
      u16 getIndex() const;
      u8  getBWActivity() const;
      void setSelected(bool selectedState);
      void setLoaded(bool loadedState);
      std::string getName() const;
      UnitImpl* getNext() const;
      /** Gets #bwOriginalUnit */
      BW::Unit* getOriginalRawData() const;
      /** Gets #bwUnitLocal */
      BW::Unit* getRawDataLocal() const;
      u8 getBuildQueueSlot() const;
      /** Gets #bwUnit->BW#Unit#buildQueue */
      BW::UnitType* getBuildQueue() const;
      /** Returns if the unit has empty building queue */
      bool hasEmptyBuildQueue() const;
      /** Returns if the unit has full building queue */
      bool hasFullBuildQueue() const;

      void saveInitialInformation();

      UnitImpl* buildUnit;
      bool alive;
      bool dead;
      bool userSelected;
      bool staticInformation;
      BWAPI::Player* savedPlayer;
      BWAPI::UnitType savedUnitType;
      bool lastVisible;
      bool makeVisible;
      UnitType lastType;
      Player* lastPlayer;
      bool nukeDetected;
      bool startingAttack;
      int lastAirWeaponCooldown;
      int lastGroundWeaponCooldown;
    private:

      /** Activitys to select this unit (previous selection will be lost. */
      void ActivitySelect();

      BW::Unit* bwUnitLocal; /**< Pointer to our local (precomputed) version of unit data table  @ref localData. */
      BW::Unit* bwOriginalUnit; /**< Pointer to broodwar unit data table. */
      u16 index; /**< Index of the unit in the array (can be computed, it's just optimisation) */
      UnitType staticType;
      BWAPI::Position staticPosition;
      BWAPI::TilePosition staticTilePosition;
      int staticResources;
      int staticHitPoints;
  };
  
  //------------------------------------------------- EXISTS -------------------------------------------------
  //returns true if the unit exists
  bool UnitImpl::_exists() const
  {
    return this->alive;
  }
};

