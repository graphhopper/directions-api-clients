part of openapi.api;

class Service {
  /* Unique identifier of service */
  String id = null;
  /* type of service */
  String type = null;
  //enum typeEnum {  service,  pickup,  delivery,  };{
  /* priority of service */
  int priority = null;
  /* name of service */
  String name = null;
  
  Address address = null;
  /* duration of service, i.e. time in seconds the corresponding activity takes */
  int duration = null;
  /* preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location */
  int preparationTime = null;
  /* array of time windows. currently, only a single time window is allowed */
  List<TimeWindow> timeWindows = [];
  /* array of capacity dimensions */
  List<int> size = [];
  /* array of required skills */
  List<String> requiredSkills = [];
  /* array of allowed vehicle ids */
  List<String> allowedVehicles = [];
  /* array of disallowed vehicle ids */
  List<String> disallowedVehicles = [];
  /* max time service can stay in vehicle */
  int maxTimeInVehicle = null;
  Service();

  @override
  String toString() {
    return 'Service[id=$id, type=$type, priority=$priority, name=$name, address=$address, duration=$duration, preparationTime=$preparationTime, timeWindows=$timeWindows, size=$size, requiredSkills=$requiredSkills, allowedVehicles=$allowedVehicles, disallowedVehicles=$disallowedVehicles, maxTimeInVehicle=$maxTimeInVehicle, ]';
  }

  Service.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    id = json['id'];
    type = json['type'];
    priority = json['priority'];
    name = json['name'];
    address = new Address.fromJson(json['address']);
    duration = json['duration'];
    preparationTime = json['preparationTime'];
    timeWindows = TimeWindow.listFromJson(json['timeWindows']);
    size = (json['size'] as List).map((item) => item as int).toList();
    requiredSkills = (json['requiredSkills'] as List).map((item) => item as String).toList();
    allowedVehicles = (json['allowedVehicles'] as List).map((item) => item as String).toList();
    disallowedVehicles = (json['disallowedVehicles'] as List).map((item) => item as String).toList();
    maxTimeInVehicle = json['maxTimeInVehicle'];
  }

  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'type': type,
      'priority': priority,
      'name': name,
      'address': address,
      'duration': duration,
      'preparationTime': preparationTime,
      'timeWindows': timeWindows,
      'size': size,
      'requiredSkills': requiredSkills,
      'allowedVehicles': allowedVehicles,
      'disallowedVehicles': disallowedVehicles,
      'maxTimeInVehicle': maxTimeInVehicle
    };
  }

  static List<Service> listFromJson(List<dynamic> json) {
    return json == null ? new List<Service>() : json.map((value) => new Service.fromJson(value)).toList();
  }

  static Map<String, Service> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Service>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Service.fromJson(value));
    }
    return map;
  }
}

