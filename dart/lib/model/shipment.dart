part of swagger.api;

@Entity()
class Shipment {
  /* Unique identifier of service */
  @Property(name: 'id')
  String id = null;
  
/* name of shipment */
  @Property(name: 'name')
  String name = null;
  
/* priority of service, i.e. 1 = high, 2 = normal, 3 = low. default is 2. */
  @Property(name: 'priority')
  int priority = null;
  

  @Property(name: 'pickup')
  Stop pickup = null;
  

  @Property(name: 'delivery')
  Stop delivery = null;
  
/* array of capacity dimensions */
  @Property(name: 'size')
  List<int> size = [];
  
/* array of required skills */
  @Property(name: 'required_skills')
  List<String> requiredSkills = [];
  
/* array of allowed vehicle ids */
  @Property(name: 'allowed_vehicles')
  List<String> allowedVehicles = [];
  
  Shipment();

  @override
  String toString()  {
    return 'Shipment[id=$id, name=$name, priority=$priority, pickup=$pickup, delivery=$delivery, size=$size, requiredSkills=$requiredSkills, allowedVehicles=$allowedVehicles, ]';
  }
}

