part of swagger.api;

@Entity()
class VehicleType {
  /* Unique identifier for the vehicle type */
  @Property(name: 'type_id')
  String typeId = null;
  
/* Profile of vehicle type */
  @Property(name: 'profile')
  String profile = null;
  //enum profileEnum {  car,  bike,  foot,  mtb,  racingbike,  truck,  small_truck,  };
/* array of capacity dimensions */
  @Property(name: 'capacity')
  List<int> capacity = [];
  
/* speed_factor of vehicle type */
  @Property(name: 'speed_factor')
  double speedFactor = null;
  
/* service time factor of vehicle type */
  @Property(name: 'service_time_factor')
  double serviceTimeFactor = null;
  
/* cost parameter per distance unit, here meter is used */
  @Property(name: 'cost_per_meter')
  double costPerMeter = null;
  
/* cost parameter per time unit, here second is used */
  @Property(name: 'cost_per_second')
  double costPerSecond = null;
  
/* cost parameter vehicle activation, i.e. fixed costs per vehicle */
  @Property(name: 'cost_per_activation')
  double costPerActivation = null;
  
  VehicleType();

  @override
  String toString()  {
    return 'VehicleType[typeId=$typeId, profile=$profile, capacity=$capacity, speedFactor=$speedFactor, serviceTimeFactor=$serviceTimeFactor, costPerMeter=$costPerMeter, costPerSecond=$costPerSecond, costPerActivation=$costPerActivation, ]';
  }
}

