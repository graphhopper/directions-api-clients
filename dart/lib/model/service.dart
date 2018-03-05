part of swagger.api;

@Entity()
class Service {
  /* Unique identifier of service */
  @Property(name: 'id')
  String id = null;
  
/* type of service */
  @Property(name: 'type')
  String type = null;
  //enum typeEnum {  service,  pickup,  delivery,  };
/* priority of service */
  @Property(name: 'priority')
  int priority = null;
  
/* name of service */
  @Property(name: 'name')
  String name = null;
  

  @Property(name: 'address')
  Address address = null;
  
/* duration of service, i.e. time in seconds the corresponding activity takes */
  @Property(name: 'duration')
  int duration = null;
  
/* preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location */
  @Property(name: 'preparation_time')
  int preparationTime = null;
  
/* array of time windows. currently, only a single time window is allowed */
  @Property(name: 'time_windows')
  List<TimeWindow> timeWindows = [];
  
/* array of capacity dimensions */
  @Property(name: 'size')
  List<int> size = [];
  
/* array of required skills */
  @Property(name: 'required_skills')
  List<String> requiredSkills = [];
  
/* array of allowed vehicle ids */
  @Property(name: 'allowed_vehicles')
  List<String> allowedVehicles = [];
  
/* array of disallowed vehicle ids */
  @Property(name: 'disallowed_vehicles')
  List<String> disallowedVehicles = [];
  
/* max time service can stay in vehicle */
  @Property(name: 'max_time_in_vehicle')
  int maxTimeInVehicle = null;
  
  Service();

  @override
  String toString()  {
    return 'Service[id=$id, type=$type, priority=$priority, name=$name, address=$address, duration=$duration, preparationTime=$preparationTime, timeWindows=$timeWindows, size=$size, requiredSkills=$requiredSkills, allowedVehicles=$allowedVehicles, disallowedVehicles=$disallowedVehicles, maxTimeInVehicle=$maxTimeInVehicle, ]';
  }
}

